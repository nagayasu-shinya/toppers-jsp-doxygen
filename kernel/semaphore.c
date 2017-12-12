/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: semaphore.c,v 1.6 2003/06/04 01:46:16 hiro Exp $
 */

/**
 * @file
 * @brief セマフォ機能
 *
 * @copyright 2000 by Embedded and Real-Time Systems Laboratory Toyohashi Univ. of Technology, JAPAN
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "semaphore.h"

/*
 *  セマフォIDの最大値（kernel_cfg.c）
 */
extern const ID tmax_semid;

/*
 *  セマフォ初期化ブロックのエリア（kernel_cfg.c）
 */
extern const SEMINIB seminib_table[];

/*
 *  セマフォ管理ブロックのエリア（kernel_cfg.c）
 */
extern SEMCB semcb_table[];

/**
 * @brief セマフォの数
 */
#define TNUM_SEM ((UINT) (tmax_semid - TMIN_SEMID + 1))

/*
 *  セマフォIDからセマフォ管理ブロックを取り出すためのマクロ
 */
#define INDEX_SEM(semid) ((UINT) ((semid) - TMIN_SEMID))
#define get_semcb(semid) (&(semcb_table[INDEX_SEM(semid)]))

/*
 *  セマフォ機能の初期化
 */
#ifdef __semini

void
semaphore_initialize()
{
    UINT  i;
    SEMCB *semcb;

    for (semcb = semcb_table, i = 0; i < TNUM_SEM; semcb++, i++) {
        queue_initialize(&(semcb->wait_queue));
        semcb->seminib = &(seminib_table[i]);
        semcb->semcnt = semcb->seminib->isemcnt;
    }
}

#endif /* __semini */

#ifdef __sig_sem

/**
 * @brief セマフォ資源の返却
 *
 * @par 機能
 * semidで指定されるセマフォに対して，資源を1つ返却する．具体的には，
 * 対象セマフォに対して資源の獲得を待っているタスクがある場合には，
 * 待ち行列の先頭のタスクを待ち解除する．この時，対象セマフォの資源数は変化しない．
 * また，待ち解除されたタスクに対しては，待ち状態に入ったサービスコールの返値としてE_OKを返す．
 * 資源の獲得を待っているタスクがない場合には，対象セマフォの資源数に1を加える．
 * \n
 * セマフォの資源数に1 を加えるとセマフォの最大資源数を越える場合には，
 * E_QOVRエラーを返す．
 *
 * @param[in] semid 資源返却対象のセマフォのID番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（semidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象セマフォが未登録）
 * @retval E_QOVR  キューイングオーバフロー（最大資源数を越える返却）
 */
SYSCALL ER sig_sem(ID semid)
{
    SEMCB *semcb;
    TCB   *tcb;
    ER    ercd;

    LOG_SIG_SEM_ENTER(semid);
    CHECK_TSKCTX_UNL();
    CHECK_SEMID(semid);
    semcb = get_semcb(semid);

    t_lock_cpu();
    if (!(queue_empty(&(semcb->wait_queue)))) {
        tcb = (TCB *) queue_delete_next(&(semcb->wait_queue));
        if (wait_complete(tcb)) {
            dispatch();
        }
        ercd = E_OK;
    } else if (semcb->semcnt < semcb->seminib->maxsem) {
        semcb->semcnt += 1;
        ercd = E_OK;
    } else {
        ercd = E_QOVR;
    }
    t_unlock_cpu();

exit:
    LOG_SIG_SEM_LEAVE(ercd);
    return ercd;
}

#endif /* __sig_sem */

#ifdef __isig_sem

/**
 * @brief セマフォ資源の返却（非タスクコンテキスト用）
 *
 * @par 機能
 * semidで指定されるセマフォに対して，資源を1つ返却する．具体的には，
 * 対象セマフォに対して資源の獲得を待っているタスクがある場合には，
 * 待ち行列の先頭のタスクを待ち解除する．この時，対象セマフォの資源数は変化しない．
 * また，待ち解除されたタスクに対しては，待ち状態に入ったサービスコールの返値としてE_OKを返す．
 * 資源の獲得を待っているタスクがない場合には，対象セマフォの資源数に1を加える．
 * \n
 * セマフォの資源数に1 を加えるとセマフォの最大資源数を越える場合には，E_QOVRエラーを返す．
 * 非タスクコンテキストから呼び出された場合で，
 * サービスコールを遅延実行する場合には，E_QOVRエラーを返すことを，実装定義で省略することができる．
 *
 * @param[in] semid 資源返却対象のセマフォのID番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（semidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象セマフォが未登録）
 * @retval E_QOVR  キューイングオーバフロー（最大資源数を越える返却）
 */
SYSCALL ER isig_sem(ID semid)
{
    SEMCB *semcb;
    TCB   *tcb;
    ER    ercd;

    LOG_ISIG_SEM_ENTER(semid);
    CHECK_INTCTX_UNL();
    CHECK_SEMID(semid);
    semcb = get_semcb(semid);

    i_lock_cpu();
    if (!queue_empty(&(semcb->wait_queue))) {
        tcb = (TCB *) queue_delete_next(&(semcb->wait_queue));
        if (wait_complete(tcb)) {
            reqflg = TRUE;
        }
        ercd = E_OK;
    } else if (semcb->semcnt < semcb->seminib->maxsem) {
        semcb->semcnt += 1;
        ercd = E_OK;
    } else {
        ercd = E_QOVR;
    }
    i_unlock_cpu();

exit:
    LOG_ISIG_SEM_LEAVE(ercd);
    return ercd;
}

#endif /* __isig_sem */

#ifdef __wai_sem

/**
 * @brief セマフォ資源の獲得
 *
 * @par 機能
 * semidで指定されるセマフォから，資源を1つ獲得する．
 * 具体的には，対象セマフォの資源数が1 以上の場合には，セマフォの資源数から1 を減じ，
 * 自タスクを待ち状態とせずにサービスコールの処理を終了する．
 * 対象セマフォの資源数が0の場合には，自タスクを待ち行列につなぎ，セマフォ資源の獲得待ち状態に移行させる．
 * この時，対象セマフォの資源数は0のまま変化しない．
 * \n
 * 他のタスクがすでに待ち行列につながっている場合，自タスクを待ち行列につなぐ処理は次のように行う．
 * セマフォ属性にTA_TFIFO（＝0x00）が指定されている場合には，自タスクを待ち行列の末尾につなぐ．
 * TA_TPRI（＝0x01）が指定されている場合には，自タスクを優先度順で待ち行列につなぐ．
 * 同じ優先度のタスクの中では，自タスクを最後につなぐ．
 *
 * @param[in] semid 資源獲得対象のセマフォのID番号
 * @retval E_OK 正常終了
 * @retval E_ID 不正ID番号（semidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象セマフォが未登録）
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_wai を受付）
 * @retval E_DLT 待ちオブジェクトの削除（待ち状態の間に対象セマフォが削除）
 */
SYSCALL ER wai_sem(ID semid)
{
    SEMCB    *semcb;
    WINFO_WOBJ winfo;
    ER    ercd;

    LOG_WAI_SEM_ENTER(semid);
    CHECK_DISPATCH();
    CHECK_SEMID(semid);
    semcb = get_semcb(semid);

    t_lock_cpu();
    if (semcb->semcnt >= 1) {
        semcb->semcnt -= 1;
        ercd = E_OK;
    } else {
        wobj_make_wait((WOBJCB *) semcb, &winfo);
        dispatch();
        ercd = winfo.winfo.wercd;
    }
    t_unlock_cpu();

exit:
    LOG_WAI_SEM_LEAVE(ercd);
    return ercd;
}

#endif /* __wai_sem */

#ifdef __pol_sem

/**
 * @brief セマフォ資源の獲得（ポーリング）
 *
 * @par 機能
 * semidで指定されるセマフォから，資源を1つ獲得する．
 * 具体的には，対象セマフォの資源数が1 以上の場合には，セマフォの資源数から1 を減じ，
 * 自タスクを待ち状態とせずにサービスコールの処理を終了する．
 * 対象セマフォの資源数が0の場合には，自タスクを待ち行列につなぎ，セマフォ資源の獲得待ち状態に移行させる．
 * この時，対象セマフォの資源数は0のまま変化しない．
 * \n
 * 他のタスクがすでに待ち行列につながっている場合，自タスクを待ち行列につなぐ処理は次のように行う．
 * セマフォ属性にTA_TFIFO（＝0x00）が指定されている場合には，自タスクを待ち行列の末尾につなぐ．
 * TA_TPRI（＝0x01）が指定されている場合には，自タスクを優先度順で待ち行列につなぐ．
 * 同じ優先度のタスクの中では，自タスクを最後につなぐ．
 * \n
 * pol_sem は，wai_sem の処理をポーリングで行うサービスコール，
 * twai_sem は，wai_sem にタイムアウトの機能を付け加えたサービスコールである．
 * tmout には，正の値のタイムアウト時間に加えて，TMO_POL（＝0）とTMO_FEVR（＝-1）を指定することができる．
 *
 * @par 補足説明
 * twai_semは，tmoutにTMO_POLが指定された場合，E_CTXエラーにならない限りはpol_sem と全く同じ動作をする．
 * また，tmout にTMO_FEVRが指定された場合は，wai_semと全く同じ動作をする
 *
 * @par μITRON3.0仕様との相違
 * サービスコールの名称を，preq_semからpol_semに変更した．
 *
 * @param[in] semid 資源獲得対象のセマフォのID番号
 * @param[in] tmout タイムアウト指定
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（semidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象セマフォが未登録）
 * @retval E_PAR   パラメータエラー（tmoutが不正）
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_wai を受付）
 * @retval E_TMOUT ポーリング失敗またはタイムアウト
 * @retval E_DLT   待ちオブジェクトの削除（待ち状態の間に対象セマフォが削除）
 */

SYSCALL ER pol_sem(ID semid)
{
    SEMCB *semcb;
    ER    ercd;

    LOG_POL_SEM_ENTER(semid);
    CHECK_TSKCTX_UNL();
    CHECK_SEMID(semid);
    semcb = get_semcb(semid);

    t_lock_cpu();
    if (semcb->semcnt >= 1) {
        semcb->semcnt -= 1;
        ercd = E_OK;
    } else {
        ercd = E_TMOUT;
    }
    t_unlock_cpu();

exit:
    LOG_POL_SEM_LEAVE(ercd);
    return ercd;
}

#endif /* __pol_sem */

#ifdef __twai_sem

/**
 * @brief セマフォ資源の獲得（タイムアウトあり）
 *
 * @par 機能
 * semidで指定されるセマフォから，資源を1つ獲得する．
 * 具体的には，対象セマフォの資源数が1 以上の場合には，セマフォの資源数から1 を減じ，
 * 自タスクを待ち状態とせずにサービスコールの処理を終了する．
 * 対象セマフォの資源数が0の場合には，自タスクを待ち行列につなぎ，セマフォ資源の獲得待ち状態に移行させる．
 * この時，対象セマフォの資源数は0のまま変化しない．
 * \n
 * 他のタスクがすでに待ち行列につながっている場合，自タスクを待ち行列につなぐ処理は次のように行う．
 * セマフォ属性にTA_TFIFO（＝0x00）が指定されている場合には，自タスクを待ち行列の末尾につなぐ．
 * TA_TPRI（＝0x01）が指定されている場合には，自タスクを優先度順で待ち行列につなぐ．
 * 同じ優先度のタスクの中では，自タスクを最後につなぐ．
 * \n
 * twai_sem は，wai_sem にタイムアウトの機能を付け加えたサービスコールである．
 * tmout には，正の値のタイムアウト時間に加えて，TMO_POL（＝0）とTMO_FEVR（＝-1）を指定することができる．
 *
 * @par 補足説明
 * twai_semは，tmoutにTMO_POLが指定された場合，E_CTXエラーにならない限りはpol_sem と全く同じ動作をする．
 * また，tmout にTMO_FEVRが指定された場合は，wai_semと全く同じ動作をする
 *
 * @param[in] semid 資源獲得対象のセマフォのID番号
 * @param[in] tmout タイムアウト指定
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（semidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象セマフォが未登録）
 * @retval E_PAR   パラメータエラー（tmoutが不正）
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_wai を受付）
 * @retval E_TMOUT ポーリング失敗またはタイムアウト
 * @retval E_DLT   待ちオブジェクトの削除（待ち状態の間に対象セマフォが削除）
 */
SYSCALL ER twai_sem(ID semid, TMO tmout)
{
    SEMCB    * semcb;
    WINFO_WOBJ winfo;
    TMEVTB     tmevtb;
    ER    ercd;

    LOG_TWAI_SEM_ENTER(semid, tmout);
    CHECK_DISPATCH();
    CHECK_SEMID(semid);
    CHECK_TMOUT(tmout);
    semcb = get_semcb(semid);

    t_lock_cpu();
    if (semcb->semcnt >= 1) {
        semcb->semcnt -= 1;
        ercd = E_OK;
    } else if (tmout == TMO_POL) {
        ercd = E_TMOUT;
    } else {
        wobj_make_wait_tmout((WOBJCB *) semcb, &winfo, &tmevtb, tmout);
        dispatch();
        ercd = winfo.winfo.wercd;
    }
    t_unlock_cpu();

exit:
    LOG_TWAI_SEM_LEAVE(ercd);
    return ercd;
}

#endif /* __twai_sem */
