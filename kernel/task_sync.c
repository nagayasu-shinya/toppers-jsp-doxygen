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
 *  @(#) $Id: task_sync.c,v 1.7 2003/12/20 08:12:24 hiro Exp $
 */

/**
 * @file
 * @brief タスク付属同期機能
 *
 * @copyright 2000-2003 by Embedded and Real-Time Systems Laboratory Toyohashi Univ. of Technology, JAPAN
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"

#ifdef __slp_tsk

/**
 * @brief 起床待ち
 *
 * @par 機能
 * 自タスクを起床待ち状態に移行させる．
 * ただし，自タスクに対する起床要求がキューイングされている場合，
 * 具体的には，自タスクの起床要求キューイング数が1 以上の場合には，
 * 起床要求キューイング数から1 を減じ，自タスクを待ち状態に移行させず，
 * そのまま実行を継続する．
 *
 * @param なし
 * @retval E_OK    正常終了
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_waiを受付）
 */
SYSCALL ER slp_tsk()
{
    WINFO winfo;
    ER    ercd;

    LOG_SLP_TSK_ENTER();
    CHECK_DISPATCH();

    t_lock_cpu();
    if (runtsk->wupcnt) {
        runtsk->wupcnt = FALSE;
        ercd = E_OK;
    } else {
        runtsk->tstat = (TS_WAITING | TS_WAIT_SLEEP);
        make_wait(&winfo);
        LOG_TSKSTAT(runtsk);
        dispatch();
        ercd = winfo.wercd;
    }
    t_unlock_cpu();

exit:
    LOG_SLP_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __slp_tsk */

#ifdef __tslp_tsk

/**
 * @brief 起床待ち（タイムアウトあり）
 *
 * @par 機能
 * 自タスクを起床待ち状態に移行させる．
 * ただし，自タスクに対する起床要求がキューイングされている場合，
 * 具体的には，自タスクの起床要求キューイング数が1 以上の場合には，
 * 起床要求キューイング数から1 を減じ，自タスクを待ち状態に移行させず，
 * そのまま実行を継続する．
 * \n
 * tslp_tsk は，slp_tsk にタイムアウトの機能を付け加えたサービスコールである．
 * tmoutには，正の値のタイムアウト時間に加えて，TMO_POL（＝0）と
 * TMO_FEVR（＝–1）を指定することができる．
 *
 * @param[in] tmout タイムアウト指定
 * @retval E_OK    正常終了
 * @retval E_PAR   パラメータエラー（tmoutが不正）
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_waiを受付）
 * @retval E_TMOUT ポーリング失敗またはタイムアウト
 */
SYSCALL ER tslp_tsk(TMO tmout)
{
    WINFO  winfo;
    TMEVTB tmevtb;
    ER     ercd;

    LOG_TSLP_TSK_ENTER(tmout);
    CHECK_DISPATCH();
    CHECK_TMOUT(tmout);

    t_lock_cpu();
    if (runtsk->wupcnt) {
        runtsk->wupcnt = FALSE;
        ercd = E_OK;
    } else if (tmout == TMO_POL) {
        ercd = E_TMOUT;
    } else {
        runtsk->tstat = (TS_WAITING | TS_WAIT_SLEEP);
        make_wait_tmout(&winfo, &tmevtb, tmout);
        LOG_TSKSTAT(runtsk);
        dispatch();
        ercd = winfo.wercd;
    }
    t_unlock_cpu();

exit:
    LOG_TSLP_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __tslp_tsk */

#ifdef __wup_tsk

/**
 * @brief タスクの起床
 *
 * @par 機能
 * tskidで指定されるタスクを，起床待ち状態から待ち解除する．
 * 待ち解除されたタスクに対しては， 待ち状態に入ったサービスコールの返値としてE_OKを返す．
 * \n
 * 対象タスクが起床待ち状態でない場合には， タスクに対する起床要求をキューイングする
 * （ただし，対象タスクが未登録状態の時はE_NOEXSエラー，休止状態の時はE_OBJ エラーとなる）．
 * 具体的には，タスクの起床要求キューイング数に1 を加える．
 * タスクの起床要求キューイング数に1 を加えると起床要求キューイング数の最大値を越える場合には，
 * E_QOVRエラーを返す．
 * \n
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 *
 * @par 補足説明
 * スタンダードプロファイルでは，タスクの起床要求キューイング数の最大値は，
 * 1以上であればいくつであってもよい．したがって，スタンダードプロファイルに準拠したカーネルで，
 * 起床要求がキューイングされているタスクを指定してこのサービスコールを呼び出しても，
 * E_QOVR エラーが返るとは限らない．
 *
 * @par μITRON3.0仕様との相違
 * 対象タスクに自タスクを指定できることとした．これは，act_tskとの整合性を考慮したためである．
*
 * @param[in] tskid 起床対象のタスクのID番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（tskidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_OBJ   オブジェクト状態エラ（対象タスクが休止状態）
 * @retval E_QOVR  キューイングオーバフロ（起床要求キューイング数のオーバフロー）
 */
SYSCALL ER wup_tsk(ID tskid)
{
    TCB  *tcb;
    UINT  tstat;
    ER    ercd;

    LOG_WUP_TSK_ENTER(tskid);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID_SELF(tskid);
    tcb = get_tcb_self(tskid);

    t_lock_cpu();
    if (TSTAT_DORMANT(tstat = tcb->tstat)) {
        ercd = E_OBJ;
    }
    else if ((tstat & TS_WAIT_SLEEP) != 0) {
        if (wait_complete(tcb)) {
            dispatch();
        }
        ercd = E_OK;
    } else if (!(tcb->wupcnt)) {
        tcb->wupcnt = TRUE;
        ercd = E_OK;
    } else {
        ercd = E_QOVR;
    }
    t_unlock_cpu();

exit:
    LOG_WUP_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __wup_tsk */

#ifdef __iwup_tsk

/**
 * @brief タスクの起床（非タスクコンテキスト用）
 *
 * @par 機能
 * tskidで指定されるタスクを，起床待ち状態から待ち解除する．
 * 待ち解除されたタスクに対しては， 待ち状態に入ったサービスコールの返値としてE_OKを返す．
 * \n
 * 対象タスクが起床待ち状態でない場合には，
 * タスクに対する起床要求をキューイングする
 * （ただし，対象タスクが未登録状態の時はE_NOEXSエラー，休止状態の時はE_OBJ エラーとなる）．
 * 具体的には，タスクの起床要求キューイング数に1 を加える．
 * タスクの起床要求キューイング数に1 を加えると起床要求キューイング数の最大値を越える場合には，
 * E_QOVRエラーを返す．
 * \n
 * 非タスクコンテキストから呼び出された場合で，
 * サービスコールを遅延実行する場合には，E_OBJエラーとE_QOVRエラーを返すことを，
 * 実装定義で省略することができる．
 * \n
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 * ただし，非タスクコンテキストからの呼出しでこの指定が行われた場合には，
 * E_IDエラーを返す．
 *
 * @par 補足説明
 * スタンダードプロファイルでは，タスクの起床要求キューイング数の最大値は，
 * 1以上であればいくつであってもよい．したがって，スタンダードプロファイルに準拠したカーネルで，
 * 起床要求がキューイングされているタスクを指定してこのサービスコールを呼び出しても，
 * E_QOVR エラーが返るとは限らない．
 *
 * @par μITRON3.0仕様との相違
 * 対象タスクに自タスクを指定できることとした．これは，act_tskとの整合性を考慮したためである．
 *
 * @param[in] tskid 起床対象のタスクのID番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（tskidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_OBJ   オブジェクト状態エラ（対象タスクが休止状態）
 * @retval E_QOVR  キューイングオーバフロ（起床要求キューイング数のオーバフロー）
 *
 */
SYSCALL ER iwup_tsk(ID tskid)
{
    TCB *tcb;
    UINT tstat;
    ER   ercd;

    LOG_IWUP_TSK_ENTER(tskid);
    CHECK_INTCTX_UNL();
    CHECK_TSKID(tskid);
    tcb = get_tcb(tskid);

    i_lock_cpu();
    if (TSTAT_DORMANT(tstat = tcb->tstat)) {
        ercd = E_OBJ;
    } else if ((tstat & TS_WAIT_SLEEP) != 0) {
        if (wait_complete(tcb)) {
            reqflg = TRUE;
        }
        ercd = E_OK;
    } else if (!(tcb->wupcnt)) {
        tcb->wupcnt = TRUE;
        ercd = E_OK;
    } else {
        ercd = E_QOVR;
    }
    i_unlock_cpu();

exit:
    LOG_IWUP_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __iwup_tsk */

#ifdef __can_wup

/**
 * @brief タスク起床要求のキャンセル
 *
 * @par 機能
 * tskid で指定されるタスクに対してキューイングされている起床要求をキャンセルし，
 * キューイングされていた起床要求の回数を返す．
 * 具体的には，タスクの起床要求キューイング数を0にクリアし，クリアする前の起床要求キューイング数を返す．
 * \n
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 *
 * @par 補足説明
 * このサービスコールは，タスクを周期的に起床して処理を行う場合に，
 * 周期内に処理が終わっているかどうかを判定するために用いることができる．
 * 具体的には，前の起床要求に対する処理が終了した時点でcan_wupを呼び出し，
 * その返値が1以上の値であった場合，前の起床要求に対する処理が周期内に終了せず，
 * 次の起床要求が行われたことがわかる．したがって，処理の遅れに対する処置をとることができる．
 *
 * @par μITRON3.0仕様との相違
 * キューイングされていた起床要求の回数（wupcnt）を，サービスコールの返値として返すこととした．
 *
 * @param[in] tskid 起床要求のキャンセル対象のタスクのID番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（tskidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが休止状態）
 */
SYSCALL ER_UINT can_wup(ID tskid)
{
    TCB    *tcb;
    ER_UINT ercd;

    LOG_CAN_WUP_ENTER(tskid);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID_SELF(tskid);
    tcb = get_tcb_self(tskid);

    t_lock_cpu();
    if (TSTAT_DORMANT(tcb->tstat)) {
        ercd = E_OBJ;
    } else {
        ercd = tcb->wupcnt ? 1 : 0;
        tcb->wupcnt = FALSE;
    }
    t_unlock_cpu();

exit:
    LOG_CAN_WUP_LEAVE(ercd);
    return ercd;
}

#endif /* __can_wup */

#ifdef __rel_wai

/**
 * @brief 待ち状態の強制解除
 *
 * @par 機能
 * tskid で指定されるタスクが待ち状態にある場合に，強制的に待ち解除を行う．
 * すなわち，対象タスクが待ち状態の時は実行可能状態に，
 * 二重待ち状態の時は強制待ち状態に移行させる．
 * このサービスコールにより待ち解除されたタスクに対しては，
 * 待ち状態に入ったサービスコールの返値としてE_RLWAI エラーを返す．
 * \n
 * 対象タスクが待ち状態（二重待ち状態を含む）でない場合には，
 * E_OBJエラーを返す（ただし，対象タスクが未登録状態の時はE_NOEXSエラーとなる）．
 *
 * @par 補足説明
 * 対象タスクに自タスクを指定することはできない．
 * 自タスクが指定された場合には，待ち状態でないためにE_OBJエラーを返す．
 * \n
 * このサービスコールでは，強制待ちからの再開は行わない．
 * 強制待ちからの再開を行う必要がある場合には，frsm_tsk（またはrsm_tsk）を用いる．
 * \n
 * 対象タスクが何らかの待ち行列につながれていた場合には，
 * 対象タスクを待ち行列から外す．その際に，
 * その待ち行列で待っている他のタスクの待ち解除が必要になる場合がある
 * （snd_mbfの機能説明とget_mplの機能説明を参照）．
 * \n
 * rel_waiとwup_tskには次のような違いがある．
 * \n
 * \li wup_tsk は起床待ち状態からのみ待ち解除するが，
 * rel_wai は任意の要因による待ち状態から待ち解除する．
 * \n
 * \li 起床待ち状態になっていたタスクから見ると，
 * wup_tsk による待ち解除は正常終了（E_OK）であるのに対して，
 * rel_waiによる強制的な待ち解除はエラー（E_RLWAI）である．
 * \n
 * \li wup_tskの場合は，対象タスクが起床待ち状態でない場合には，
 * 要求がキューイングされる．
 * それに対してrel_wai の場合は，対象タスクが待ち状態でない場合にはE_OBJエラーとなる．
 *
 * @param[in] tskid 待ち状態の強制解除対象のタスクのID番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（tskidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが待ち状態でない）
 */
SYSCALL ER rel_wai(ID tskid)
{
    TCB *tcb;
    ER   ercd;

    LOG_REL_WAI_ENTER(tskid);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID(tskid);
    tcb = get_tcb(tskid);

    t_lock_cpu();
    if (!(TSTAT_WAITING(tcb->tstat))) {
        ercd = E_OBJ;
    } else {
        if (wait_release(tcb)) {
            dispatch();
        }
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_REL_WAI_LEAVE(ercd);
    return ercd;
}

#endif /* __rel_wai */

#ifdef __irel_wai
/**
 * @brief 待ち状態の強制解除（非タスクコンテキスト用）
 *
 * @par 機能
 * tskid で指定されるタスクが待ち状態にある場合に，強制的に待ち解除を行う．
 * すなわち，対象タスクが待ち状態の時は実行可能状態に，
 * 二重待ち状態の時は強制待ち状態に移行させる．
 * このサービスコールにより待ち解除されたタスクに対しては，
 * 待ち状態に入ったサービスコールの返値としてE_RLWAI エラーを返す．
 * \n
 * 対象タスクが待ち状態（二重待ち状態を含む）でない場合には，
 * E_OBJエラーを返す（ただし，対象タスクが未登録状態の時はE_NOEXSエラーとなる）．
 * 非タスクコンテキストから呼び出された場合で，サービスコールを遅延実行する場合には，
 * E_OBJエラーを返すことを，実装定義で省略することができる．
 *
 * @par 補足説明
 * 対象タスクに自タスクを指定することはできない．
 * 自タスクが指定された場合には，待ち状態でないためにE_OBJエラーを返す．
 * \n
 * このサービスコールでは，強制待ちからの再開は行わない．
 * 強制待ちからの再開を行う必要がある場合には，frsm_tsk（またはrsm_tsk）を用いる．
 * \n
 * 対象タスクが何らかの待ち行列につながれていた場合には，
 * 対象タスクを待ち行列から外す．その際に，
 * その待ち行列で待っている他のタスクの待ち解除が必要になる場合がある
 * （snd_mbfの機能説明とget_mplの機能説明を参照）．
 * \n
 * rel_waiとwup_tskには次のような違いがある．
 * \n
 * \li wup_tsk は起床待ち状態からのみ待ち解除するが，
 * rel_wai は任意の要因による待ち状態から待ち解除する．
 * \n
 * \li 起床待ち状態になっていたタスクから見ると，
 * wup_tsk による待ち解除は正常終了（E_OK）であるのに対して，
 * rel_waiによる強制的な待ち解除はエラー（E_RLWAI）である．
 * \n
 * \li wup_tskの場合は，対象タスクが起床待ち状態でない場合には，
 * 要求がキューイングされる．
 * それに対してrel_wai の場合は，対象タスクが待ち状態でない場合にはE_OBJエラーとなる．
 *
 * @param[in] tskid 待ち状態の強制解除対象のタスクのID番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（tskidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが待ち状態でない）
 */
SYSCALL ER irel_wai(ID tskid)
{
    TCB    *tcb;
    ER    ercd;

    LOG_IREL_WAI_ENTER(tskid);
    CHECK_INTCTX_UNL();
    CHECK_TSKID(tskid);
    tcb = get_tcb(tskid);

    i_lock_cpu();
    if (!(TSTAT_WAITING(tcb->tstat))) {
        ercd = E_OBJ;
    } else {
        if (wait_release(tcb)) {
            reqflg = TRUE;
        }
        ercd = E_OK;
    }
    i_unlock_cpu();

exit:
    LOG_IREL_WAI_LEAVE(ercd);
    return ercd;
}

#endif /* __irel_wai */

#ifdef __sus_tsk

/**
 * @brief 強制待ち状態への移行
 *
 * @par 機能
 * tskid で指定されるタスクを強制待ち状態にして，タスクの実行を中断させる．
 * 具体的には，対象タスクが実行できる状態の時は強制待ち状態に，
 * 待ち状態の時は二重待ち状態に移行させる．
 * また，対象タスクの強制待ち要求ネスト数に1 を加える．
 * タスクの強制待ち要求ネスト数に1 を加えると強制待ち要求ネスト数の最大値を越える場合には，
 * E_QOVRエラーを返す．
 * \n
 * このサービスコールは，ディスパッチ禁止状態でも呼び出すことができるが，
 * ディスパッチ禁止状態で自タスクを対象タスクとして呼び出された場合には，
 * E_CTXエラーを返す．
 * \n
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 *
 * @par 補足説明
 * このサービスコールは，パラメータによっては自タスクを強制待ち状態にする可能性があるにもかかわらず，
 * ディスパッチ禁止状態でも呼び出すことができる．
 * したがって，
 * 「ディスパッチ禁止状態から自タスクを広義の待ち状態にする可能性のあるサービスコールが呼び出された場合に実装定義でE_CTX エラーとする仕様は，
 * サービスコール単位に適用される」という原則の例外となっている．
 * \n
 * スタンダードプロファイルでは，タスクの強制待ち要求ネスト数の最大値は，
 * 1 以上であればいくつであってもよい．
 * したがって，スタンダードプロファイルに準拠したカーネルで，
 * 強制待ち状態のタスクを指定してこのサービスコールを呼び出しても，E_QOVRエラーが返るとは限らない．
 *
 * @par μITRON3.0仕様との相違
 * 対象タスクに自タスクを指定できることとした．
 *
 * @param[in] tskid 移行対象のタスクのID番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正ID番号（tskidが不正あるいは使用できない）
 * @retval E_CTX   コンテキストエラー（ディスパッチ禁止状態で対象タスクに自タスクを指定，その他のコンテキストエラー）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが休止状態）
 * @retval E_QOVR  キューイングオーバフロー（強制待ち要求ネスト数のオーバフロー）
 */
SYSCALL ER sus_tsk(ID tskid)
{
    TCB  *tcb;
    UINT  tstat;
    ER    ercd;

    LOG_SUS_TSK_ENTER(tskid);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID_SELF(tskid);
    tcb = get_tcb_self(tskid);

    t_lock_cpu();
    if (tcb == runtsk && !(enadsp)) {
        ercd = E_CTX;
    } else if (TSTAT_DORMANT(tstat = tcb->tstat)) {
        ercd = E_OBJ;
    } else if (TSTAT_RUNNABLE(tstat)) {
        /*
         *  実行できる状態から強制待ち状態への遷移
         */
        tcb->tstat = TS_SUSPENDED;
        LOG_TSKSTAT(tcb);
        if (make_non_runnable(tcb)) {
            dispatch();
        }
        ercd = E_OK;
    } else if (TSTAT_SUSPENDED(tstat)) {
        ercd = E_QOVR;
    } else {
        /*
         *  待ち状態から二重待ち状態への遷移
         */
        tcb->tstat |= TS_SUSPENDED;
        LOG_TSKSTAT(tcb);
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_SUS_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __sus_tsk */

#ifdef __rsm_tsk

/**
 * @brief 強制待ち状態からの再開
 *
 * @par 機能
 * tskidで指定されるタスクの強制待ちを解除し，タスクの実行を再開させる．
 * 具体的な処理内容は次の通りである．
 * \n
 * rsm_tskは，対象タスクの強制待ち要求ネスト数から1を減じ，
 * 減じた後の強制待ち要求ネスト数が0の場合には，対象タスクが強制待ち状態の時は実行可能状態に，
 * 二重待ち状態の時は待ち状態に移行させる．減じた後の強制待ち要求ネスト数が1以上の場合には，対象タスクの状態を変化させない．
 *
 * @par 補足説明
 * 対象タスクに自タスクを指定することはできない．
 *
 * @par μITRON3.0仕様との相違
 * タスクを強制待ち状態から実行可能状態に移行させる時に，
 * 同じ優先度内で最低の優先順位とするものとした．
 *
 * @note
 * JSPカーネルでは，frsm_tsk と rsm_tsk は同一の処理となる．
 * frsm_tskが呼ばれると，frsm_tsk と rsm_tskの両方のサービスコールのトレース ログが出力される．
 * ログ取得後に rsm_tsk のトレースログを削除することが必要である．
 * rsm_tsk のトレースログを正しく削除するためには，
 * タスクディスパッチのログと，タスク例外処理のログも取得することが必要となるので，注意が必要である．
 *
 * @param[in] tskid 再開対象のタスクのID番号
 * @retval E_OK    正常終了
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが強制待ち状態でない）
 */
SYSCALL ER rsm_tsk(ID tskid)
{
    TCB  *tcb;
    UINT  tstat;
    ER    ercd;

    LOG_RSM_TSK_ENTER(tskid);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID(tskid);
    tcb = get_tcb(tskid);

    t_lock_cpu();
    if (!(TSTAT_SUSPENDED(tstat = tcb->tstat))) {
        ercd = E_OBJ;
    } else if (!(TSTAT_WAITING(tstat))) {
        /*
         *  強制待ち状態から実行できる状態への遷移
         */
        if (make_runnable(tcb)) {
            dispatch();
        }
        ercd = E_OK;
    } else {
        /*
         *  二重待ち状態から待ち状態への遷移
         */
        tcb->tstat &= ~TS_SUSPENDED;
        LOG_TSKSTAT(tcb);
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_RSM_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __rsm_tsk */

#ifdef __frsm_tsk

/**
 * @brief 強制待ち状態からの強制再開
 *
 * @par 機能
 * tskidで指定されるタスクの強制待ちを解除し，タスクの実行を再開させる．
 * 具体的な処理内容は次の通りである．
 * \n
 * frsm_tskは，対象タスクの強制待ち要求ネスト数を0とし，
 * 対象タスクが強制待ち状態の時は実行可能状態に，二重待ち状態の時は待ち状態に移行させる．
 * 対象タスクが強制待ち状態（二重待ち状態を含む）でない場合には，E_OBJエラーを返す
 * （ただし，対象タスクが未登録状態の時はE_NOEXSエラーとなる）．
 *
 * @par 補足説明
 * 対象タスクに自タスクを指定することはできない．
 *
 * @par μITRON3.0仕様との相違
 * タスクを強制待ち状態から実行可能状態に移行させる時に，
 * 同じ優先度内で最低の優先順位とするものとした．
 *
 * @note
 * JSPカーネルでは，frsm_tsk と rsm_tsk は同一の処理となる．
 * frsm_tskが呼ばれると，frsm_tsk と rsm_tskの両方のサービスコールのトレース ログが出力される．
 * ログ取得後に rsm_tsk のトレースログを削除することが必要である．
 * rsm_tsk のトレースログを正しく削除するためには，
 * タスクディスパッチのログと，タスク例外処理のログも取得することが必要となるので，注意が必要である．
 *
 * @param[in] tskid 再開対象のタスクのID番号
 * @retval E_OK    正常終了
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが強制待ち状態でない）
 */

SYSCALL ER frsm_tsk(ID tskid)
{
    ER ercd;

    LOG_FRSM_TSK_ENTER(tskid);
    ercd = rsm_tsk(tskid);
    LOG_FRSM_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __frsm_tsk */

#ifdef __dly_tsk

/**
 * @brief 自タスクの遅延
 *
 * @par 機能
 * 自タスクを時間経過待ち状態に移行させ，dlytimで指定される時間の間，
 * 実行を一時的に停止する．
 * 具体的には，サービスコールが呼び出された時刻から
 * dlytimで指定された相対時間後に待ち解除されるよう設定し，
 * 自タスクを時間経過待ち状態に移行させる．
 * 指定された相対時間後に待ち解除された場合，このサービスコールは正常終了し，E_OKを返す．
 * \n
 * dlytimは，サービスコールが呼び出された時刻を基準に，
 * 時間経過待ち状態から待ち解除される時刻を指定する相対時間と解釈する．
 *
 * @par 補足説明
 * 時間経過待ち状態からの解除は，システム時刻に依存して行われる処理である．
 * そのため，時間経過待ち状態からの解除は，待ち解除すべき時刻以降の最初のタイムティックで行う．
 * また，時間経過待ち状態からの解除は，このサービスコールが呼び出されてから，
 * dlytimで指定された以上の時間が経過した後に行うことを保証しなければならない．
 * このサービスコールは，dlytimに0が指定された場合にも，自タスクを待ち状態に移行させる．
 * \n
 * 時間経過待ち状態は待ち状態の一種であり，rel_waiにより強制的に待ち解除することができる．
 * タスクの遅延時間には，タスクが二重待ち状態になっている時間も含まれる．
 * \n
 * このサービスコールは，tslp_tskと異なり，dlytimで指定された時間が経過して待ち解除された場合に正常終了となる．
 * 時間経過待ち状態にあるタスクを指定してwup_tsk が呼び出されても，
 * 時間経過待ち状態からの解除は行わない．dlytim で指定された時間が経過する前にdly_tsk が終了するのは，
 * ter_tsk かrel_waiが呼び出された場合に限られる．
 *
 * @par μITRON3.0仕様との相違
 * dlytimのデータ型をDLYTIMEからRELTIMに変更した
 *
 * @param[in] dlytim 自タスクの遅延時間（相対時間）
 * @retval E_PAR   パラメータエラー（dlytimが不正）
 * @retval E_RLWAI 待ち状態の強制解除（待ち状態の間にrel_waiを受付）
 */
SYSCALL ER dly_tsk(RELTIM dlytim)
{
    WINFO  winfo;
    TMEVTB tmevtb;
    ER     ercd;

    LOG_DLY_TSK_ENTER(dlytim);
    CHECK_DISPATCH();
    CHECK_PAR(dlytim <= TMAX_RELTIM);

    t_lock_cpu();
    runtsk->tstat = TS_WAITING;
    make_non_runnable(runtsk);
    runtsk->winfo = &winfo;
    winfo.tmevtb = &tmevtb;
    tmevtb_enqueue(&tmevtb, dlytim, (CBACK) wait_tmout_ok, (VP) runtsk);
    LOG_TSKSTAT(runtsk);
    dispatch();
    ercd = winfo.wercd;
    t_unlock_cpu();

exit:
    LOG_DLY_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __dly_tsk */
