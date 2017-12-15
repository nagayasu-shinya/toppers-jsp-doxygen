/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 *
 *  @(#) $Id: mempfix.c,v 1.12 2005/11/12 14:55:23 hiro Exp $
 */

/**
 * @file
 * @brief 固定長メモリプール機能
 *
 * @copyright 2000 by Embedded and Real-Time Systems Laboratory Toyohashi Univ. of Technology, JAPAN
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "mempfix.h"

/*
 * 固定長メモリプールIDの最大値（kernel_cfg.c）
 */
extern const ID tmax_mpfid;

/*
 *  固定長メモリプール初期化ブロックのエリア（kernel_cfg.c）
 */
extern const MPFINIB mpfinib_table[];

/*
 *  固定長メモリプール管理ブロックのエリア（kernel_cfg.c）
 */
extern MPFCB mpfcb_table[];

/*
 * 固定長メモリプールの数
 */
#define TNUM_MPF ((UINT) (tmax_mpfid - TMIN_MPFID + 1))

/*
 *  固定長メモリプールIDから固定長メモリプール管理ブロックを取り出すた
 *  めのマクロ
 */
#define INDEX_MPF(mpfid) ((UINT) ((mpfid) - TMIN_MPFID))
#define get_mpfcb(mpfid) (&(mpfcb_table[INDEX_MPF(mpfid)]))

/*
 *  固定長メモリプール待ち情報ブロックの定義
 */
typedef struct fixed_memorypool_waiting_information {
    WINFO   winfo;     /* 標準の待ち情報ブロック */
    WOBJCB *wobjcb;    /* 待ちオブジェクトの管理ブロック */
    VP      blk;       /* 獲得したメモリブロック */
} WINFO_MPF;

/*
 *  固定長メモリプール機能の初期化
 */
#ifdef __mpfini

void
mempfix_initialize()
{
    UINT i;
    MPFCB *mpfcb;

    for (mpfcb = mpfcb_table, i = 0; i < TNUM_MPF; mpfcb++, i++) {
        queue_initialize(&(mpfcb->wait_queue));
        mpfcb->mpfinib = &(mpfinib_table[i]);
        mpfcb->unused = mpfcb->mpfinib->mpf;
        mpfcb->freelist = NULL;
    }
}

#endif /* __mpfini */

/*
 *  固定長メモリプールからブロックを獲得
 */
#ifdef __mpfget

BOOL
mempfix_get_block(MPFCB *mpfcb, VP *p_blk)
{
    FREEL    *free;

    if (mpfcb->freelist != NULL) {
        free = mpfcb->freelist;
        mpfcb->freelist = free->next;
        *p_blk = (VP) free;
        return TRUE;
    } else if (mpfcb->unused < mpfcb->mpfinib->limit) {
        *p_blk = mpfcb->unused;
        mpfcb->unused = (VP) ((char *) (mpfcb->unused)
                        + mpfcb->mpfinib->blksz);
        return TRUE;
    }
    return FALSE;
}

#endif /* __mpfget */

#ifdef __get_mpf

/**
 * @brief 固定長メモリブロックの獲得
 *
 * @par 機能
 * mpfid で指定される固定長メモリプールから，
 * 固定長メモリプール生成時に指定されたサイズのメモリブロックを獲得し，
 * その先頭番地をblk に返す．具体的には，
 * 対象固定長メモリプール領域に空きメモリブロックがある場合には，
 * その内のいずれかを選んで獲得された状態とし，その先頭番地をblk に返す．
 * 空きメモリブロックがない場合には，自タスクを待ち行列につなぎ，
 * 固定長メモリブロックの獲得待ち状態に移行させる．
 * \n
 * 他のタスクがすでに待ち行列につながっている場合，
 * 自タスクを待ち行列につなぐ処理は次のように行う．
 * 固定長メモリプール属性にTA_TFIFO（＝ 0x00）が指定されている場合には，
 * 自タスクを待ち行列の末尾につなぐ．TA_TPRI（＝ 0x01）が指定されている場合には，
 * 自タスクを優先度順で待ち行列につなぐ．同じ優先度のタスクの中では，自タスクを最後につなぐ．
 *
 * @par 補足説明
 * 獲得するメモリブロックのサイズは，
 * 固定長メモリプール生成時に指定されたメモリブロックのサイズ以上であれば，
 * それよりも大きくてもよい．またこれらのサービスコールは，
 * 獲得したメモリブロックのクリアは行わないため，その内容は不定となる．
 * \n
 * tget_mpfは，tmoutにTMO_POLが指定された場合，
 * E_CTXエラーにならない限りはpget_mpfと全く同じ動作をする．
 * また，tmoutにTMO_FEVRが指定された場合は，get_mpfと全く同じ動作をする．
 *
 * @par μITRON3.0仕様との相違
 * サービスコールの名称を，get_blf，pget_blf，tget_blf から，それぞれget_mpf，
 * pget_mpf，tget_mpfに変更した．リターンパラメータの名称をblfからblkに変更した．
 * また，パラメータとリターンパラメータの順序を変更した．
 *
 * @param[in]  mpfid メモリブロック獲得対象の固定長メモリプールのID番号
 * @param[out] blk   獲得したメモリブロックの先頭番地
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（mpfidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象固定長メモリプールが未登録）
 * @retval E_PAR   パラメータエラー（p_blk）
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_wai を受付）
 * @retval E_DLT   待ちオブジェクトの削除（待ち状態の間に対象固定長メモリプールが削除）
 */
SYSCALL ER get_mpf(ID mpfid, VP *p_blk)
{
    MPFCB    *mpfcb;
    WINFO_MPF winfo;
    ER    ercd;

    LOG_GET_MPF_ENTER(mpfid, p_blk);
    CHECK_DISPATCH();
    CHECK_MPFID(mpfid);
    mpfcb = get_mpfcb(mpfid);

    t_lock_cpu();
    if (mempfix_get_block(mpfcb, p_blk)) {
        ercd = E_OK;
    } else {
        wobj_make_wait((WOBJCB *) mpfcb, (WINFO_WOBJ *) &winfo);
        dispatch();
        ercd = winfo.winfo.wercd;
        if (ercd == E_OK) {
            *p_blk = winfo.blk;
        }
    }
    t_unlock_cpu();

exit:
    LOG_GET_MPF_LEAVE(ercd, *p_blk);
    return ercd;
}

#endif /* __get_mpf */

#ifdef __pget_mpf

/**
 * @brief 固定長メモリブロックの獲得（ポーリング）
 *
 * @par 機能
 * mpfid で指定される固定長メモリプールから，
 * 固定長メモリプール生成時に指定されたサイズのメモリブロックを獲得し，
 * その先頭番地をblk に返す．具体的には，
 * 対象固定長メモリプール領域に空きメモリブロックがある場合には，
 * その内のいずれかを選んで獲得された状態とし，その先頭番地をblk に返す．
 * 空きメモリブロックがない場合には，自タスクを待ち行列につなぎ，
 * 固定長メモリブロックの獲得待ち状態に移行させる．
 * \n
 * 他のタスクがすでに待ち行列につながっている場合，
 * 自タスクを待ち行列につなぐ処理は次のように行う．
 * 固定長メモリプール属性にTA_TFIFO（＝ 0x00）が指定されている場合には，
 * 自タスクを待ち行列の末尾につなぐ．TA_TPRI（＝ 0x01）が指定されている場合には，
 * 自タスクを優先度順で待ち行列につなぐ．同じ優先度のタスクの中では，自タスクを最後につなぐ．
 * \n
 * pget_mpf は，get_mpf の処理をポーリングで行うサービスコール，tget_mpf は，
 * get_mpfにタイムアウトの機能を付け加えたサービスコールである．tmoutには，
 * 正の値のタイムアウト時間に加えて，TMO_POL（＝0）とTMO_FEVR（＝-1）を指定することができる．
 *
 * @par 補足説明
 * 獲得するメモリブロックのサイズは，
 * 固定長メモリプール生成時に指定されたメモリブロックのサイズ以上であれば，
 * それよりも大きくてもよい．またこれらのサービスコールは，
 * 獲得したメモリブロックのクリアは行わないため，その内容は不定となる．
 * \n
 * tget_mpfは，tmoutにTMO_POLが指定された場合，
 * E_CTXエラーにならない限りはpget_mpfと全く同じ動作をする．
 * また，tmoutにTMO_FEVRが指定された場合は，get_mpfと全く同じ動作をする．
 *
 * @par μITRON3.0仕様との相違
 * サービスコールの名称を，get_blf，pget_blf，tget_blf から，それぞれget_mpf，
 * pget_mpf，tget_mpfに変更した．リターンパラメータの名称をblfからblkに変更した．
 * また，パラメータとリターンパラメータの順序を変更した．
 *
 * @param[in]  mpfid メモリブロック獲得対象の固定長メモリプールのID番号
 * @param[out] blk   獲得したメモリブロックの先頭番地
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（mpfidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象固定長メモリプールが未登録）
 * @retval E_PAR   パラメータエラー（p_blk，tmoutが不正）
 * @retval E_TMOUT ポーリング失敗またはタイムアウト
 */
SYSCALL ER pget_mpf(ID mpfid, VP *p_blk)
{
    MPFCB *mpfcb;
    ER    ercd;

    LOG_PGET_MPF_ENTER(mpfid, p_blk);
    CHECK_TSKCTX_UNL();
    CHECK_MPFID(mpfid);
    mpfcb = get_mpfcb(mpfid);

    t_lock_cpu();
    if (mempfix_get_block(mpfcb, p_blk)) {
        ercd = E_OK;
    } else {
        ercd = E_TMOUT;
    }
    t_unlock_cpu();

exit:
    LOG_PGET_MPF_LEAVE(ercd, *p_blk);
    return ercd;
}

#endif /* __pget_mpf */

#ifdef __tget_mpf

/**
 * @brief 固定長メモリブロックの獲得（タイムアウトあり）
 *
 * @par 機能
 * mpfid で指定される固定長メモリプールから，
 * 固定長メモリプール生成時に指定されたサイズのメモリブロックを獲得し，
 * その先頭番地をblk に返す．具体的には，
 * 対象固定長メモリプール領域に空きメモリブロックがある場合には，
 * その内のいずれかを選んで獲得された状態とし，その先頭番地をblk に返す．
 * 空きメモリブロックがない場合には，自タスクを待ち行列につなぎ，
 * 固定長メモリブロックの獲得待ち状態に移行させる．
 * \n
 * 他のタスクがすでに待ち行列につながっている場合，
 * 自タスクを待ち行列につなぐ処理は次のように行う．
 * 固定長メモリプール属性にTA_TFIFO（＝ 0x00）が指定されている場合には，
 * 自タスクを待ち行列の末尾につなぐ．TA_TPRI（＝ 0x01）が指定されている場合には，
 * 自タスクを優先度順で待ち行列につなぐ．同じ優先度のタスクの中では，自タスクを最後につなぐ．
 * \n
 * pget_mpf は，get_mpf の処理をポーリングで行うサービスコール，tget_mpf は，
 * get_mpfにタイムアウトの機能を付け加えたサービスコールである．tmoutには，
 * 正の値のタイムアウト時間に加えて，TMO_POL（＝0）とTMO_FEVR（＝-1）を指定することができる．
 *
 * @par 補足説明
 * 獲得するメモリブロックのサイズは，
 * 固定長メモリプール生成時に指定されたメモリブロックのサイズ以上であれば，
 * それよりも大きくてもよい．またこれらのサービスコールは，
 * 獲得したメモリブロックのクリアは行わないため，その内容は不定となる．
 * \n
 * tget_mpfは，tmoutにTMO_POLが指定された場合，
 * E_CTXエラーにならない限りはpget_mpfと全く同じ動作をする．
 * また，tmoutにTMO_FEVRが指定された場合は，get_mpfと全く同じ動作をする．
 *
 * @par μITRON3.0仕様との相違
 * サービスコールの名称を，get_blf，pget_blf，tget_blf から，それぞれget_mpf，
 * pget_mpf，tget_mpfに変更した．リターンパラメータの名称をblfからblkに変更した．
 * また，パラメータとリターンパラメータの順序を変更した．
 *
 * @param[in]  mpfid メモリブロック獲得対象の固定長メモリプールのID番号
 * @param[out] blk   獲得したメモリブロックの先頭番地
 * @param[in]  tmout タイムアウト指定
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（mpfidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象固定長メモリプールが未登録）
 * @retval E_PAR   パラメータエラー（p_blk，tmoutが不正）
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_wai を受付）
 * @retval E_TMOUT ポーリング失敗またはタイムアウト
 * @retval E_DLT   待ちオブジェクトの削除（待ち状態の間に対象固定長メモリプールが削除）
 */

SYSCALL ER tget_mpf(ID mpfid, VP *p_blk, TMO tmout)
{
    MPFCB    *mpfcb;
    WINFO_MPF winfo;
    TMEVTB    tmevtb;
    ER    ercd;

    LOG_TGET_MPF_ENTER(mpfid, p_blk, tmout);
    CHECK_DISPATCH();
    CHECK_MPFID(mpfid);
    CHECK_TMOUT(tmout);
    mpfcb = get_mpfcb(mpfid);

    t_lock_cpu();
    if (mempfix_get_block(mpfcb, p_blk)) {
        ercd = E_OK;
    } else if (tmout == TMO_POL) {
        ercd = E_TMOUT;
    } else {
        wobj_make_wait_tmout((WOBJCB *) mpfcb, (WINFO_WOBJ *) &winfo,
                        &tmevtb, tmout);
        dispatch();
        ercd = winfo.winfo.wercd;
        if (ercd == E_OK) {
            *p_blk = winfo.blk;
        }
    }
    t_unlock_cpu();

exit:
    LOG_TGET_MPF_LEAVE(ercd, *p_blk);
    return ercd;
}

#endif /* __tget_mpf */

#ifdef __rel_mpf

/**
 * @brief 固定長メモリブロックの返却
 *
 * @par 機能
 * mpfidで指定される固定長メモリプールに対して，
 * blkを先頭番地とするメモリブロックを返却する．
 * \n
 * 対象固定長メモリプールでメモリブロックの獲得を待っているタスクがある場合には，
 * 返却したメモリブロックを待ち行列の先頭のタスクに獲得させ，そのタスクを待ち解除する．
 * この時，待ち解除されたタスクに対しては，待ち状態に入ったサービスコールの返値としてE_OKを返し，
 * 固定長メモリブロックから獲得したメモリブロックの先頭番地としてblkの値を返す．
 * \n
 * メモリブロックを返却する対象の固定長メモリプールは，
 * メモリブロックの獲得を行った固定長メモリプールと同じものでなければならない．
 * メモリブロックを返却する対象の固定長メモリプールが，
 * メモリブロックの獲得を行った固定長メモリプールと異なっている場合には，E_PARエラーを返す．
 * \n
 * また，返却するメモリブロックの先頭番地は，
 * get_mpf，pget_mpf，tget_mpfのいずれかのサービスコールが，
 * 獲得したメモリブロックの先頭番地として返したもので，
 * まだ返却されていないものでなければならない．
 * blk にそれ以外の番地が指定された場合の振舞いは未定義である．
 * エラーを報告する場合には，E_PARエラーを返す．
 *
 * @par μITRON3.0仕様との相違
 * サービスコールの名称を，rel_blfからrel_mpfに変更した．
 * パラメータの名称をblfからblkに変更した．
 *
 * @param[in] mpfid メモリブロック返却対象の固定長メモリプールのID番号
 * @param[in] blk   返却するメモリブロックの先頭番地
 * @retval E_ID     不正ID番号（mpfidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象固定長メモリプールが未登録）
 * @retval E_PAR   パラメータエラー（blk が不正，異なるメモリプールへの返却，獲得したメモリブロックの先頭番地以外の返却）
 */
SYSCALL ER rel_mpf(ID mpfid, VP blk)
{
    MPFCB *mpfcb;
    TCB   *tcb;
    FREEL *free;
    ER     ercd;

    LOG_REL_MPF_ENTER(mpfid, blk);
    CHECK_TSKCTX_UNL();
    CHECK_MPFID(mpfid);
    mpfcb = get_mpfcb(mpfid);
    CHECK_PAR(mpfcb->mpfinib->mpf <= blk
            && blk < mpfcb->mpfinib->limit
            && ((char *) (blk) - (char *) (mpfcb->mpfinib->mpf))
                    % mpfcb->mpfinib->blksz == 0);

    t_lock_cpu();
    if (!(queue_empty(&(mpfcb->wait_queue)))) {
        tcb = (TCB *) queue_delete_next(&(mpfcb->wait_queue));
        ((WINFO_MPF *)(tcb->winfo))->blk = blk;
        if (wait_complete(tcb)) {
            dispatch();
        }
        ercd = E_OK;
    } else {
        free = (FREEL *) blk;
        free->next = mpfcb->freelist;
        mpfcb->freelist = free;
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_REL_MPF_LEAVE(ercd);
    return ercd;
}

#endif /* __rel_mpf */
