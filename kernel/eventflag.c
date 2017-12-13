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
 *  @(#) $Id: eventflag.c,v 1.8 2003/06/04 01:46:16 hiro Exp $
 */

/**
 * @file
 * @brief イベントフラグ機能
 *
 * @copyright 2000 by Embedded and Real-Time Systems Laboratory Toyohashi Univ. of Technology, JAPAN
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "eventflag.h"

/*
 *  イベントフラグIDの最大値（kernel_cfg.c）
 */
extern const ID tmax_flgid;

/*
 *  イベントフラグ初期化ブロックのエリア（kernel_cfg.c）
 */
extern const FLGINIB flginib_table[];

/*
 *  イベントフラグ管理ブロックのエリア（kernel_cfg.c）
 */
extern FLGCB flgcb_table[];

/*
 *  イベントフラグの数
 */
#define TNUM_FLG ((UINT) (tmax_flgid - TMIN_FLGID + 1))

/*
 *  イベントフラグIDからイベントフラグ管理ブロックを取り出すためのマクロ
 */
#define INDEX_FLG(flgid)  ((UINT) ((flgid) - TMIN_FLGID))
#define get_flgcb(flgid)  (&(flgcb_table[INDEX_FLG(flgid)]))

/*
 *  イベントフラグ待ち情報ブロックの定義
 *
 *  flgptn は，waiptn および wfmode と同時に使うことはないため，union
 *  を使えばメモリを節約することが可能である．
 */
typedef struct eventflag_waiting_information {
    WINFO   winfo;         /* 標準の待ち情報ブロック */
    WOBJCB *wobjcb;        /* 待ちオブジェクトの管理ブロック */
    FLGPTN  waiptn;        /* 待ちパターン */
    MODE    wfmode;        /* 待ちモード */
    FLGPTN  flgptn;        /* 待ち解除時のパターン */
} WINFO_FLG;

/*
 *  イベントフラグ機能の初期化
 */
#ifdef __flgini

void eventflag_initialize(void)
{
    UINT  i;
    FLGCB *flgcb;

    for (flgcb = flgcb_table, i = 0; i < TNUM_FLG; flgcb++, i++) {
        queue_initialize(&(flgcb->wait_queue));
        flgcb->flginib = &(flginib_table[i]);
        flgcb->flgptn = flgcb->flginib->iflgptn;
    }
}

#endif /* __flgini */

/*
 *  イベントフラグ待ち解除条件のチェック
 */
#ifdef __flgcnd

BOOL eventflag_cond(FLGCB *flgcb, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn)
{
    if ((wfmode & TWF_ORW) != 0 ? (flgcb->flgptn & waiptn) != 0
                : (flgcb->flgptn & waiptn) == waiptn) {
        *p_flgptn = flgcb->flgptn;
        if ((flgcb->flginib->flgatr & TA_CLR) != 0) {
            flgcb->flgptn = 0;
        }
        return TRUE;
    }
    return FALSE;
}

#endif /* __flgcnd */

#ifdef __set_flg

/**
 * @イベントフラグのセット
 *
 * @par 機能
 * flgidで指定されるイベントフラグに対して，setptnで指定されるビットをセットする．
 * 具体的には，対象イベントフラグのビットパターンを，
 * サービスコール呼出し前のビットパターンと setptn の値のビット毎の論理和に更新する．
 * \n
 * 対象イベントフラグのビットパターンが更新された結果，
 * そのイベントフラグで待っているタスクの待ち解除条件を満たした場合には，
 * 該当するタスクを待ち解除する．具体的には，
 * イベントフラグの待ち行列の先頭のタスクから順に待ち解除条件を満たしているかを調べ，
 * 待ち解除条件を満たしているタスクが見つかれば，そのタスクを待ち解除する．
 * また，待ち解除されたタスクに対しては，待ち状態に入ったサービスコールの返値として E_OK を返し，
 * 待ち解除時のビットパターンとして，この時の(待ち解除条件を満たした)ビットパターンを返す．
 * またこの時，対象イベントフラグ属性に TA_CLR(= 0x04)が指定されている場合には，
 * イベントフラグのビットパターンのすべてのビットをクリアし，
 * サービスコールの処理を終了する．TA_CLR が指定されていない場合には，
 * 待ち行列のさらに後ろのタスクについても待ち解除の条件を満たしているかを調べ，
 * 待ち行列の最後のタスクまで調べた時点で終了する．
 * 待ち解除条件については，wai_flg の機能説明を参照すること．
 * \n
 * イベントフラグ属性に TA_WMUL(= 0x02)が指定されており，TA_CLR が指定されていない場合，
 * set_flg の一回の呼出しで複数のタスクが待ち解除される可能性がある．
 * この場合，待ち解除されるタスクが複数ある場合には，
 * イベントフラグの待ち行列につながれていた順序で待ち解除される．
 * そのため，実行可能状態に移行したタスクで同じ優先度を持つものの間では，
 * 待ち行列の中で前につながれていたタスクの方が高い優先順位を持つことになる．
 *
 * @par 補足説明
 * setptn の全ビットが 0 の場合には，何もしない．
 *
 * @par μITRON3.0 仕様との相違
 * setptn のデータ型を UINT から FLGPTN に変更した．
 */
SYSCALL ER set_flg(ID flgid, FLGPTN setptn)
{
    FLGCB  *flgcb;
    TCB    *tcb;
    WINFO_FLG *winfo;
    ER ercd;

    LOG_SET_FLG_ENTER(flgid, setptn);
    CHECK_TSKCTX_UNL();
    CHECK_FLGID(flgid);
    flgcb = get_flgcb(flgid);

    t_lock_cpu();
    flgcb->flgptn |= setptn;
    if (!(queue_empty(&(flgcb->wait_queue)))) {
        tcb = (TCB *)(flgcb->wait_queue.next);
        winfo = (WINFO_FLG *)(tcb->winfo);
        if (eventflag_cond(flgcb, winfo->waiptn,
                    winfo->wfmode, &(winfo->flgptn))) {
            queue_delete(&(tcb->task_queue));
            if (wait_complete(tcb)) {
                dispatch();
            }
        }
    }
    ercd = E_OK;
    t_unlock_cpu();

exit:
    LOG_SET_FLG_LEAVE(ercd);
    return ercd;
}

#endif /* __set_flg */

#ifdef __iset_flg

/**
 * @brief イベントフラグのセット（非タスクコンテキスト用）
 *
 * @par 機能
 * flgidで指定されるイベントフラグに対して，setptnで指定されるビットをセットする．
 * 具体的には，対象イベントフラグのビットパターンを，
 * サービスコール呼出し前のビットパターンと setptn の値のビット毎の論理和に更新する．
 * \n
 * 対象イベントフラグのビットパターンが更新された結果，
 * そのイベントフラグで待っているタスクの待ち解除条件を満たした場合には，
 * 該当するタスクを待ち解除する．具体的には，
 * イベントフラグの待ち行列の先頭のタスクから順に待ち解除条件を満たしているかを調べ，
 * 待ち解除条件を満たしているタスクが見つかれば，そのタスクを待ち解除する．
 * また，待ち解除されたタスクに対しては，待ち状態に入ったサービスコールの返値として E_OK を返し，
 * 待ち解除時のビットパターンとして，この時の(待ち解除条件を満たした)ビットパターンを返す．
 * またこの時，対象イベントフラグ属性に TA_CLR(= 0x04)が指定されている場合には，
 * イベントフラグのビットパターンのすべてのビットをクリアし，
 * サービスコールの処理を終了する．TA_CLR が指定されていない場合には，
 * 待ち行列のさらに後ろのタスクについても待ち解除の条件を満たしているかを調べ，
 * 待ち行列の最後のタスクまで調べた時点で終了する．
 * 待ち解除条件については，wai_flg の機能説明を参照すること．
 * \n
 * イベントフラグ属性に TA_WMUL(= 0x02)が指定されており，TA_CLR が指定されていない場合，
 * set_flg の一回の呼出しで複数のタスクが待ち解除される可能性がある．
 * この場合，待ち解除されるタスクが複数ある場合には，
 * イベントフラグの待ち行列につながれていた順序で待ち解除される．
 * そのため，実行可能状態に移行したタスクで同じ優先度を持つものの間では，
 * 待ち行列の中で前につながれていたタスクの方が高い優先順位を持つことになる．
 *
 * @par 補足説明
 * setptn の全ビットが 0 の場合には，何もしない．
 *
 * @par μITRON3.0 仕様との相違
 * setptn のデータ型を UINT から FLGPTN に変更した．
 */
SYSCALL ER iset_flg(ID flgid, FLGPTN setptn)
{
    FLGCB *flgcb;
    TCB   *tcb;
    WINFO_FLG *winfo;
    ER ercd;

    LOG_ISET_FLG_ENTER(flgid, setptn);
    CHECK_INTCTX_UNL();
    CHECK_FLGID(flgid);
    flgcb = get_flgcb(flgid);

    i_lock_cpu();
    flgcb->flgptn |= setptn;
    if (!(queue_empty(&(flgcb->wait_queue)))) {
        tcb = (TCB *)(flgcb->wait_queue.next);
        winfo = (WINFO_FLG *)(tcb->winfo);
        if (eventflag_cond(flgcb, winfo->waiptn,
                    winfo->wfmode, &(winfo->flgptn))) {
            queue_delete(&(tcb->task_queue));
            if (wait_complete(tcb)) {
                reqflg = TRUE;
            }
        }
    }
    ercd = E_OK;
    i_unlock_cpu();

exit:
    LOG_ISET_FLG_LEAVE(ercd);
    return ercd;
}

#endif /* __iset_flg */

#ifdef __clr_flg

/**
 * @brief イベントフラグのクリア
 *
 * @par 機能
 * flgidで指定されるイベントフラグに対して，
 * clrptnの対応するビットが0になっているビットをクリアする．
 * 具体的には，対象イベントフラグのビットパターンを，
 * サービスコール呼出し前のビットパターンと clrptn の値のビット毎の論理積に更新する．
 *
 * @par 補足説明
 * clrptnの全ビットが1の場合には，何もしない．
 *
 * @par μITRON3.0仕様との相違
 * clrptnのデータ型をUINTからFLGPTNに変更した．
 *
 * @param[in] flgid セット対象のイベントフラグのID番号
 * @param[in] clrptn クリアするビットパターン（ビット毎の反転値）
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（flgidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象イベントフラグが未登録）
 * @retval E_PAR   パラメータエラー（clrptnが不正）
 */
SYSCALL ER clr_flg(ID flgid, FLGPTN clrptn)
{
    FLGCB *flgcb;
    ER ercd;

    LOG_CLR_FLG_ENTER(flgid, clrptn);
    CHECK_TSKCTX_UNL();
    CHECK_FLGID(flgid);
    flgcb = get_flgcb(flgid);

    t_lock_cpu();
    flgcb->flgptn &= clrptn;
    ercd = E_OK;
    t_unlock_cpu();

exit:
    LOG_CLR_FLG_LEAVE(ercd);
    return ercd;
}

#endif /* __clr_flg */

#ifdef __wai_flg

/**
 * @brief イベントフラグ待ち
 *
 * @par 機能
 * flgidで指定されるイベントフラグのビットパターンが，
 * waiptnとwfmodeで指定される待ち解除条件を満たすのを待つ．
 * flgptn には，待ち解除される時のイベントフラグのビットパターンを返す．
 * 具体的な処理内容は次の通りである．
 * \n
 * 対象イベントフラグのビットパターンがwaiptn とwfmode で指定される待ち解除条件を満たしている場合には，
 * 自タスクを待ち状態とせずにサービスコールの処理を終了する．
 * flgptn には，この時の（待ち解除条件を満たした）ビットパターンを返す．
 * またこの時，対象イベントフラグ属性にTA_CLR（＝ 0x04）が指定されている場合には，
 * イベントフラグのビットパターンのすべてのビットをクリアする．
 * \n
 * 対象イベントフラグのビットパターンがwaiptn とwfmode で指定される待ち解除条件を満たしていない場合には，
 * 自タスクを待ち行列につなぎ，イベントフラグ待ち状態に移行させる．
 * \n
 * 対象イベントフラグ属性にTA_WSGL（＝0x00）が指定されており，
 * イベントフラグの待ち行列に他のタスクがつながれている場合には，
 * 待ち解除条件を満たしているかどうかにかかわらず，E_ILUSEエラーとなる．
 * \n
 * wfmodeには，（TWF_ANDW | TWF_ORW）の指定ができる．
 * waiptnとwfmodeで指定される待ち解除条件とは，
 * wfmode にTWF_ANDW（＝ 0x00）が指定された場合には，
 * 対象イベントフラグのビットパターンのwaiptn で指定されるビットのすべてがセットされるという条件である．
 * TWF_ORW（＝0x01）が指定された場合には，
 * 対象イベントフラグのビットパターンのwaiptnで指定されるビットのいずれかがセットされるという条件である．
 * \n
 * 他のタスクがすでに待ち行列につながっている場合，自タスクを待ち行列につなぐ処理は次のように行う．
 * イベントフラグ属性にTA_TFIFO（＝0x00）が指定されている場合には，
 * 自タスクを待ち行列の末尾につなぐ．TA_TPRI（＝0x01）が指定されている場合には，
 * 自タスクを優先度順で待ち行列につなぐ．同じ優先度のタスクの中では，自タスクを最後につなぐ．
 * \n
 * waiptnに0が指定された場合には，E_PARエラーを返す．
 *
 * @par μITRON3.0仕様との相違
 * パラメータとリターンパラメータの順序を変更した．
 * また，waitpn とflgptn のデータ型をUINTからFLGPTNに，
 * wfmodeのデータ型をUINTからMODEにそれぞれ変更した．
 * \n
 * 待ちモードのクリア指定（TWF_CLR）を廃止した．同等の機能として，
 * TA_CLR属性のイベントフラグを用意している．また，TWF_ORWの値を変更した．
 *
 * @par 仕様決定の理由
 * waiptnに0が指定された場合をE_PARエラーとしたのは，この指定をした場合に，
 * イベントフラグのビットパターンがどのような値になっても待ち解除状態を満たさないため，
 * イベントフラグ待ち状態から抜けることができなくなるためである．
 *
 * @pram[in] flgid  待ち対象のイベントフラグのID番号
 * @pram[in] waiptn 待ちビットパターン
 * @pram[in] wfmode 待ちモード
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（flgidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象イベントフラグが未登録）
 * @retval E_PAR   パラメータエラー（waiptn，wfmode，p_flgptn，tmoutが不正）
 * @retval E_ILUSE サービスコール不正使用（TA_WSGL 属性が指定されたイベントフラグで待ちタスクあり）
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_wai を受付）
 * @retval E_DLT   待ちオブジェクトの削除（待ち状態の間に対象イベントフラグが削除）
 */
SYSCALL ER wai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn)
{
    FLGCB    *flgcb;
    WINFO_FLG winfo;
    ER    ercd;

    LOG_WAI_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn);
    CHECK_DISPATCH();
    CHECK_FLGID(flgid);
    CHECK_PAR(waiptn != 0);
    CHECK_PAR((wfmode & ~TWF_ORW) == 0);
    flgcb = get_flgcb(flgid);

    t_lock_cpu();
    if (!(queue_empty(&(flgcb->wait_queue)))) {
        ercd = E_ILUSE;
    } else if (eventflag_cond(flgcb, waiptn, wfmode, p_flgptn)) {
        ercd = E_OK;
    } else {
        winfo.waiptn = waiptn;
        winfo.wfmode = wfmode;
        wobj_make_wait((WOBJCB *) flgcb, (WINFO_WOBJ *) &winfo);
        dispatch();
        ercd = winfo.winfo.wercd;
        if (ercd == E_OK) {
            *p_flgptn = winfo.flgptn;
        }
    }
    t_unlock_cpu();

exit:
    LOG_WAI_FLG_LEAVE(ercd, *p_flgptn);
    return ercd;
}

#endif /* __wai_flg */

#ifdef __pol_flg

/**
 * @brief イベントフラグ待ち（ポーリング）
 *
 * @par 機能
 * flgidで指定されるイベントフラグのビットパターンが，
 * waiptnとwfmodeで指定される待ち解除条件を満たすのを待つ．
 * flgptn には，待ち解除される時のイベントフラグのビットパターンを返す．
 * 具体的な処理内容は次の通りである．
 * \n
 * 対象イベントフラグのビットパターンがwaiptn とwfmode で指定される待ち解除条件を満たしている場合には，
 * 自タスクを待ち状態とせずにサービスコールの処理を終了する．
 * flgptn には，この時の（待ち解除条件を満たした）ビットパターンを返す．
 * またこの時，対象イベントフラグ属性にTA_CLR（＝ 0x04）が指定されている場合には，
 * イベントフラグのビットパターンのすべてのビットをクリアする．
 * \n
 * 対象イベントフラグのビットパターンがwaiptn とwfmode で指定される待ち解除条件を満たしていない場合には，
 * 自タスクを待ち行列につなぎ，イベントフラグ待ち状態に移行させる．
 * \n
 * 対象イベントフラグ属性にTA_WSGL（＝0x00）が指定されており，
 * イベントフラグの待ち行列に他のタスクがつながれている場合には，
 * 待ち解除条件を満たしているかどうかにかかわらず，E_ILUSEエラーとなる．
 * \n
 * wfmodeには，（TWF_ANDW‖TWF_ORW）の指定ができる．
 * waiptnとwfmodeで指定される待ち解除条件とは，
 * wfmode にTWF_ANDW（＝ 0x00）が指定された場合には，
 * 対象イベントフラグのビットパターンのwaiptn で指定されるビットのすべてがセットされるという条件である．
 * TWF_ORW（＝0x01）が指定された場合には，
 * 対象イベントフラグのビットパターンのwaiptnで指定されるビットのいずれかがセットされるという条件である．
 * \n
 * 他のタスクがすでに待ち行列につながっている場合，自タスクを待ち行列につなぐ処理は次のように行う．
 * イベントフラグ属性にTA_TFIFO（＝0x00）が指定されている場合には，
 * 自タスクを待ち行列の末尾につなぐ．TA_TPRI（＝0x01）が指定されている場合には，
 * 自タスクを優先度順で待ち行列につなぐ．同じ優先度のタスクの中では，自タスクを最後につなぐ．
 * \n
 * pol_flg は，wai_flg の処理をポーリングで行うサービスコール，twai_flg は，
 * wai_flgにタイムアウトの機能を付け加えたサービスコールである．tmoutには，
 * 正の値のタイムアウト時間に加えて，TMO_POL（＝0）とTMO_FEVR（＝-1）を指定することができる．
 * \n
 * waiptnに0が指定された場合には，E_PARエラーを返す．
 *
 * @par 補足説明
 * twai_flgは，tmoutにTMO_POLが指定された場合，
 * E_CTXエラーにならない限りはpol_flgと全く同じ動作をする．
 * また，tmoutにTMO_FEVRが指定された場合は，wai_flgと全く同じ動作をする．
 *
 * @par μITRON3.0仕様との相違
 * パラメータとリターンパラメータの順序を変更した．
 * また，waitpn とflgptn のデータ型をUINTからFLGPTNに，
 * wfmodeのデータ型をUINTからMODEにそれぞれ変更した．
 * \n
 * 待ちモードのクリア指定（TWF_CLR）を廃止した．同等の機能として，
 * TA_CLR属性のイベントフラグを用意している．また，TWF_ORWの値を変更した．
 *
 * @par 仕様決定の理由
 * waiptnに0が指定された場合をE_PARエラーとしたのは，この指定をした場合に，
 * イベントフラグのビットパターンがどのような値になっても待ち解除状態を満たさないため，
 * イベントフラグ待ち状態から抜けることができなくなるためである．
 *
 * @pram[in] flgid  待ち対象のイベントフラグのID番号
 * @pram[in] waiptn 待ちビットパターン
 * @pram[in] wfmode 待ちモード
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（flgidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象イベントフラグが未登録）
 * @retval E_PAR   パラメータエラー（waiptn，wfmode，p_flgptn，tmoutが不正）
 * @retval E_ILUSE サービスコール不正使用（TA_WSGL 属性が指定されたイベントフラグで待ちタスクあり）
 * @retval E_TMOUT ポーリング失敗またはタイムアウト
 */
SYSCALL ER pol_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn)
{
    FLGCB *flgcb;
    ER ercd;

    LOG_POL_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn);
    CHECK_TSKCTX_UNL();
    CHECK_FLGID(flgid);
    CHECK_PAR(waiptn != 0);
    CHECK_PAR((wfmode & ~TWF_ORW) == 0);
    flgcb = get_flgcb(flgid);

    t_lock_cpu();
    if (!(queue_empty(&(flgcb->wait_queue)))) {
        ercd = E_ILUSE;
    } else if (eventflag_cond(flgcb, waiptn, wfmode, p_flgptn)) {
        ercd = E_OK;
    } else {
        ercd = E_TMOUT;
    }
    t_unlock_cpu();

exit:
    LOG_POL_FLG_LEAVE(ercd, *p_flgptn);
    return ercd;
}

#endif /* __pol_flg */

#ifdef __twai_flg

/**
 * @brief イベントフラグ待ち（タイムアウトあり）
 *
 * @par 機能
 * flgidで指定されるイベントフラグのビットパターンが，
 * waiptnとwfmodeで指定される待ち解除条件を満たすのを待つ．
 * flgptn には，待ち解除される時のイベントフラグのビットパターンを返す．
 * 具体的な処理内容は次の通りである．
 * \n
 * 対象イベントフラグのビットパターンがwaiptn とwfmode で指定される待ち解除条件を満たしている場合には，
 * 自タスクを待ち状態とせずにサービスコールの処理を終了する．
 * flgptn には，この時の（待ち解除条件を満たした）ビットパターンを返す．
 * またこの時，対象イベントフラグ属性にTA_CLR（＝ 0x04）が指定されている場合には，
 * イベントフラグのビットパターンのすべてのビットをクリアする．
 * \n
 * 対象イベントフラグのビットパターンがwaiptn とwfmode で指定される待ち解除条件を満たしていない場合には，
 * 自タスクを待ち行列につなぎ，イベントフラグ待ち状態に移行させる．
 * \n
 * 対象イベントフラグ属性にTA_WSGL（＝0x00）が指定されており，
 * イベントフラグの待ち行列に他のタスクがつながれている場合には，
 * 待ち解除条件を満たしているかどうかにかかわらず，E_ILUSEエラーとなる．
 * \n
 * wfmodeには，（TWF_ANDW‖TWF_ORW）の指定ができる．
 * waiptnとwfmodeで指定される待ち解除条件とは，
 * wfmode にTWF_ANDW（＝ 0x00）が指定された場合には，
 * 対象イベントフラグのビットパターンのwaiptn で指定されるビットのすべてがセットされるという条件である．
 * TWF_ORW（＝0x01）が指定された場合には，
 * 対象イベントフラグのビットパターンのwaiptnで指定されるビットのいずれかがセットされるという条件である．
 * \n
 * 他のタスクがすでに待ち行列につながっている場合，自タスクを待ち行列につなぐ処理は次のように行う．
 * イベントフラグ属性にTA_TFIFO（＝0x00）が指定されている場合には，
 * 自タスクを待ち行列の末尾につなぐ．TA_TPRI（＝0x01）が指定されている場合には，
 * 自タスクを優先度順で待ち行列につなぐ．同じ優先度のタスクの中では，自タスクを最後につなぐ．
 * \n
 * pol_flg は，wai_flg の処理をポーリングで行うサービスコール，twai_flg は，
 * wai_flgにタイムアウトの機能を付け加えたサービスコールである．tmoutには，
 * 正の値のタイムアウト時間に加えて，TMO_POL（＝0）とTMO_FEVR（＝-1）を指定することができる．
 * \n
 * waiptnに0が指定された場合には，E_PARエラーを返す．
 *
 * @par 補足説明
 * twai_flgは，tmoutにTMO_POLが指定された場合，
 * E_CTXエラーにならない限りはpol_flgと全く同じ動作をする．
 * また，tmoutにTMO_FEVRが指定された場合は，wai_flgと全く同じ動作をする．
 *  
 * @par μITRON3.0仕様との相違
 * パラメータとリターンパラメータの順序を変更した．
 * また，waitpn とflgptn のデータ型をUINTからFLGPTNに，
 * wfmodeのデータ型をUINTからMODEにそれぞれ変更した．
 * \n
 * 待ちモードのクリア指定（TWF_CLR）を廃止した．同等の機能として，
 * TA_CLR属性のイベントフラグを用意している．また，TWF_ORWの値を変更した．
 *
 * @par 仕様決定の理由
 * waiptnに0が指定された場合をE_PARエラーとしたのは，この指定をした場合に，
 * イベントフラグのビットパターンがどのような値になっても待ち解除状態を満たさないため，
 * イベントフラグ待ち状態から抜けることができなくなるためである．
 *
 * @pram[in] flgid  待ち対象のイベントフラグのID番号
 * @pram[in] waiptn 待ちビットパターン
 * @pram[in] wfmode 待ちモード
 * @pram[in] tmout  タイムアウト指定
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（flgidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象イベントフラグが未登録）
 * @retval E_PAR   パラメータエラー（waiptn，wfmode，p_flgptn，tmoutが不正）
 * @retval E_ILUSE サービスコール不正使用（TA_WSGL 属性が指定されたイベントフラグで待ちタスクあり）
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_wai を受付）
 * @retval E_TMOUT ポーリング失敗またはタイムアウト
 * @retval E_DLT   待ちオブジェクトの削除（待ち状態の間に対象イベントフラグが削除）
 */
SYSCALL ER twai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn, TMO tmout)
{
    FLGCB    *flgcb;
    WINFO_FLG winfo;
    TMEVTB    tmevtb;
    ER    ercd;

    LOG_TWAI_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn, tmout);
    CHECK_DISPATCH();
    CHECK_FLGID(flgid);
    CHECK_PAR(waiptn != 0);
    CHECK_PAR((wfmode & ~TWF_ORW) == 0);
    CHECK_TMOUT(tmout);
    flgcb = get_flgcb(flgid);

    t_lock_cpu();
    if (!(queue_empty(&(flgcb->wait_queue)))) {
        ercd = E_ILUSE;
    } else if (eventflag_cond(flgcb, waiptn, wfmode, p_flgptn)) {
        ercd = E_OK;
    } else if (tmout == TMO_POL) {
        ercd = E_TMOUT;
    } else {
        winfo.waiptn = waiptn;
        winfo.wfmode = wfmode;
        wobj_make_wait_tmout((WOBJCB *) flgcb, (WINFO_WOBJ *) &winfo, &tmevtb, tmout);
        dispatch();
        ercd = winfo.winfo.wercd;
        if (ercd == E_OK) {
            *p_flgptn = winfo.flgptn;
        }
    }
    t_unlock_cpu();

exit:
    LOG_TWAI_FLG_LEAVE(ercd, *p_flgptn);
    return ercd;
}

#endif /* __twai_flg */
