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
 *  @(#) $Id: task_except.c,v 1.8 2003/06/04 01:46:16 hiro Exp $
 */

/**
 * @file
 * @brief タスク例外処理機能
 *
 * @copyright 2000-2003 by Embedded and Real-Time Systems Laboratory Toyohashi Univ. of Technology, JAPAN
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

#ifdef __ras_tex

/**
 * @brief タスク例外処理の要求
 *
 * @par 機能
 * tskid で指定されるタスクに対して，rasptn で指定されるタスク例外要因によって，
 * タスク例外処理を要求する．すなわち，対象タスクの保留例外要因を，
 * サービスコール呼出し前の保留例外要因とrasptn の値のビット毎の論理和に更新する．
 * \n
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 * \n
 * 対象タスクが休止状態の時はE_OBJエラーを返す．また，
 * 対象タスクにタスク例外処理ルーチンが定義されていない場合にも，E_OBJエラーを返す．
 * \n
 * rasptnに0が指定された場合には，E_PARエラーを返す．
 *
 * @par 補足説明
 * このサービスコールにより，タスク例外処理ルーチンを起動する条件が揃った場合には，
 * タスク例外処理ルーチンを起動する処理を行う．
 * このサービスコールでは，対象タスクが広義の待ち状態である場合に，
 * 保留例外要因の更新のみを行い，待ち解除や強制待ちからの再開は行わない．
 * 待ち解除や強制待ちからの再開を行う必要がある場合には，
 * それぞれrel_wai やfrsm_tsk（またはrsm_tsk）を用いる．
 *
 * @param[in] tskid  要求対象のタスクのID番号
 * @param[in] rasptn 要求するタスク例外処理のタスク例外要因
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（tskidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_PAR   パラメータエラー（rasptnが不正）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが休止状態，対象タスクにタスク例外処理ルーチンが定義されていない）
 */
SYSCALL ER ras_tex(ID tskid, TEXPTN rasptn)
{
    TCB *tcb;
    ER   ercd;

    LOG_RAS_TEX_ENTER(tskid, rasptn);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID_SELF(tskid);
    CHECK_PAR(rasptn != 0);
    tcb = get_tcb_self(tskid);

    t_lock_cpu();
    if (TSTAT_DORMANT(tcb->tstat) || tcb->tinib->texrtn == NULL) {
        ercd = E_OBJ;
    } else {
        tcb->texptn |= rasptn;
        if (tcb == runtsk && runtsk->enatex) {
            call_texrtn();
        }
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_RAS_TEX_LEAVE(ercd);
    return ercd;
}

#endif /* __ras_tex */

#ifdef __iras_tex

/**
 * @brief タスク例外処理の要求（非タスクコンテキスト用）
 *
 * @par 機能
 * tskid で指定されるタスクに対して，rasptn で指定されるタスク例外要因によって，
 * タスク例外処理を要求する．すなわち，対象タスクの保留例外要因を，
 * サービスコール呼出し前の保留例外要因とrasptn の値のビット毎の論理和に更新する．
 * \n
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 * ただし，非タスクコンテキストからの呼出しでこの指定が行われた場合には，
 * E_IDエラーを返す．
 * \n
 * 対象タスクが休止状態の時はE_OBJエラーを返す．また，
 * 対象タスクにタスク例外処理ルーチンが定義されていない場合にも，E_OBJエラーを返す．
 * 非タスクコンテキストから呼び出された場合で，サービスコールを遅延実行する場合には，
 * E_OBJエラーを返すことを，実装定義で省略することができる．
 * \n
 * rasptnに0が指定された場合には，E_PARエラーを返す．
 *
 * @par 補足説明
 * このサービスコールにより，タスク例外処理ルーチンを起動する条件が揃った場合には，
 * タスク例外処理ルーチンを起動する処理を行う．
 * このサービスコールでは，対象タスクが広義の待ち状態である場合に，
 * 保留例外要因の更新のみを行い，待ち解除や強制待ちからの再開は行わない．
 * 待ち解除や強制待ちからの再開を行う必要がある場合には，
 * それぞれrel_wai やfrsm_tsk（またはrsm_tsk）を用いる．
 * \n
 * 非タスクコンテキストから呼び出されたサービスコールを遅延実行する場合に，
 * ディスパッチが起こる状態となるまで実行を遅延できるサービスコールが多いが，
 * このサービスコールはディスパッチ禁止状態でも実行しなければならない．
 * 具体的な例として，ディスパッチ禁止状態で起動された割込みハンドラで，
 * 実行状態のタスクを対象タスクとしてタスク例外処理が要求された場合には，
 * 割込みハンドラからのリターン直後にタスク例外処理ルーチンを起動しなければならない．
 * これを使うと，ディスパッチ禁止状態で暴走するタスクに対して，
 * 割込みハンドラからタスク例外処理を要求することによって，暴走を止めることができる．
 * ただし，CPUロック状態で暴走するタスクや，ディスパッチに加えてタスク例外処理も禁止した状態で暴走するタスクは，
 * この方法で止めることはできない．
 *
 * @param[in] tskid  要求対象のタスクのID番号
 * @param[in] rasptn 要求するタスク例外処理のタスク例外要因
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（tskidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_PAR   パラメータエラー（rasptnが不正）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが休止状態，対象タスクにタスク例外処理ルーチンが定義されていない）
 */
SYSCALL ER iras_tex(ID tskid, TEXPTN rasptn)
{
    TCB *tcb;
    ER   ercd;

    LOG_IRAS_TEX_ENTER(tskid, rasptn);
    CHECK_INTCTX_UNL();
    CHECK_TSKID(tskid);
    CHECK_PAR(rasptn != 0);
    tcb = get_tcb(tskid);

    i_lock_cpu();
    if (TSTAT_DORMANT(tcb->tstat) || tcb->tinib->texrtn == NULL) {
        ercd = E_OBJ;
    } else {
        tcb->texptn |= rasptn;
        if (tcb == runtsk && runtsk->enatex) {
            reqflg = TRUE;
        }
        ercd = E_OK;
    }
    i_unlock_cpu();

exit:
    LOG_IRAS_TEX_LEAVE(ercd);
    return ercd;
}

#endif /* __iras_tex */

#ifdef __dis_tex

/**
 * @brief タスク例外処理の禁止
 *
 * @par 機能
 * 自タスクを，タスク例外処理禁止状態に移行させる．
 * 自タスクにタスク例外処理ルーチンが定義されていない場合には，E_OBJエラーを返す．
 *
 * @retval E_OK  正常終了
 * @retval E_OBJ オブジェクト状態エラー（自タスクにタスク例外処理ルーチンが定義されていない）
 */
SYSCALL ER dis_tex()
{
    ER ercd;

    LOG_DIS_TEX_ENTER();
    CHECK_TSKCTX_UNL();

    t_lock_cpu();
    if (runtsk->tinib->texrtn == NULL) {
        ercd = E_OBJ;
    } else {
        runtsk->enatex = FALSE;
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_DIS_TEX_LEAVE(ercd);
    return ercd;
}

#endif /* __dis_tex */

#ifdef __ena_tex

/**
 * @brief タスク例外処理の許可
 *
 * @par 機能
 * 自タスクを，タスク例外処理許可状態に移行させる．
 * 自タスクにタスク例外処理ルーチンが定義されていない場合には，E_OBJエラーを返す．
 * \n
 * 拡張サービスコールルーチン内でタスク例外処理を許可してはならない実装で，
 * このサービスコールが拡張サービスコールルーチンから呼び出された場合には，
 * E_CTXエラーを返す．
 *
 * @par 補足説明
 * このサービスコールにより，タスク例外処理ルーチンを起動する条件が揃った場合には，
 * タスク例外処理ルーチンを起動する処理を行う．
 *
 * @retval E_OK  正常終了
 * @retval E_OBJ オブジェクト状態エラー（自タスクにタスク例外処理ルーチンが定義されていない）
 * @retval E_CTX コンテキストエラー（タスク例外処理を許可してはならないコンテキストからの呼出し，その他のコンテキストエラー）
 */
SYSCALL ER ena_tex()
{
    ER ercd;

    LOG_ENA_TEX_ENTER();
    CHECK_TSKCTX_UNL();

    t_lock_cpu();
    if (runtsk->tinib->texrtn == NULL) {
        ercd = E_OBJ;
    } else {
        runtsk->enatex = TRUE;
        if (runtsk->texptn != 0) {
            call_texrtn();
        }
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_ENA_TEX_LEAVE(ercd);
    return ercd;
}

#endif /* __ena_tex */

#ifdef __sns_tex

/**
 * @brief タスク例外処理禁止状態の参照
 *
 * @par 機能
 * 実行状態のタスク（タスクコンテキストから呼び出された場合は，自タスクに一致する）が，
 * タスク例外処理禁止状態の場合にTRUE，タスク例外処理許可状態の場合にFALSEを返す．
 * 非タスクコンテキストから呼び出された場合で，実行状態のタスクがない時には，TRUEを返す．
 *
 * @par 補足説明
 * タスク例外処理ルーチンが定義されていないタスクは，
 * タスク例外処理禁止状態に保たれているため，
 * 実行状態のタスクにタスク例外処理ルーチンが定義されていない場合には，
 * このサービスコールはTRUEを返す．
 *
 * @retval TRUE  実行状態のタスクが例外処理禁止状態
 * @retval FALSE TRUE 以外
 */
SYSCALL BOOL sns_tex()
{
    BOOL state;

    LOG_SNS_TEX_ENTER();
    state = (runtsk != NULL && runtsk->enatex) ? FALSE : TRUE;
    LOG_SNS_TEX_LEAVE(state);
    return state;
}

#endif /* __sns_tex */
