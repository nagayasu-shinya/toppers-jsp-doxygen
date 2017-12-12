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
 *  @(#) $Id: task_manage.c,v 1.9 2007/04/22 18:04:06 hiro Exp $
 */

/**
 * @file
 * @brief タスク管理機能
 *
 * @copyright 2000-2003 by Embedded and Real-Time Systems Laboratory Toyohashi Univ. of Technology, JAPAN
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"

#ifdef __act_tsk
/**
 * @brief タスクの起動
 *
 * @par 機能
 * tskidで指定されるタスクを起動する．
 * 具体的には，対象タスクを休止状態から実行可能状態に移行させ，
 * タスクの起動時に行うべき処理を行う．タスクを起動する際のパラメータとして，
 * タスクの拡張情報を渡す．
 * \n
 * 対象タスクが休止状態でない場合には，タスクに対する起動要求をキューイングする
 * （ただし，対象タスクが未登録状態の時はE_NOEXSエラーとなる）． 具体的には，
 * タスクの起動要求キューイング数に1を加える．
 * タスクの起動要求キューイング数に1を加えると起動要求キューイング数の最大値を越える場合には，
 * E_QOVRエラーを返す．
 * \n
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 *
 * @par 補足説明
 * スタンダードプロファイルでは，タスクの起動要求キューイング数の最大値は，
 * 1以上であればいくつであってもよい．
 * したがって，スタンダードプロファイルに準拠したカーネルで，
 * 起動要求がキューイングされているタスクを指定してこのサービスコールを呼び出しても，
 * E_QOVR エラーが返るとは限らない．
 *
 * @par μITRON3.0仕様との相違
 * 新設のサービスコールである．
 *
 * @param[in] tskid 起動対象のタスクの ID 番号
 * @retval E_OK 正常終了
 * @retval E_ID 不正 ID 番号（tskid が不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_QOVR  キューイングオーバーフロー（起動要求キューイング数のオーバーフロー）
 */
SYSCALL ER act_tsk(ID tskid)
{
    TCB *tcb;
    ER   ercd;

    LOG_ACT_TSK_ENTER(tskid);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID_SELF(tskid);
    tcb = get_tcb_self(tskid);

    t_lock_cpu();
    if (TSTAT_DORMANT(tcb->tstat)) {
        if (make_active(tcb)) {
            dispatch();
        }
        ercd = E_OK;
    } else if (!(tcb->actcnt)) {
        tcb->actcnt = TRUE;
        ercd = E_OK;
    } else {
        ercd = E_QOVR;
    }
    t_unlock_cpu();

exit:
    LOG_ACT_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __act_tsk */

#ifdef __iact_tsk

/**
 * @brief タスクの起動（非タスクコンテキスト用）
 *
 * @par 機能
 * tskidで指定されるタスクを起動する．
 * 具体的には，対象タスクを休止状態から実行可能状態に移行させ，
 * タスクの起動時に行うべき処理を行う．タスクを起動する際のパラメータとして，
 * タスクの拡張情報を渡す．
 * \n
 * 対象タスクが休止状態でない場合には，タスクに対する起動要求をキューイングする
 * （ただし，対象タスクが未登録状態の時はE_NOEXSエラーとなる）． 具体的には，
 * タスクの起動要求キューイング数に1を加える．
 * タスクの起動要求キューイング数に1を加えると起動要求キューイング数の最大値を越える場合には，
 * E_QOVRエラーを返す．
 * \n
 * 非タスクコンテキストから呼び出された場合で，サービスコールを遅延実行する場合には，
 * E_QOVRエラーを返すことを，実装定義で省略することができる．
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 * ただし，非タスクコンテキストからの呼出しでこの指定が行われた場合には，E_IDエラーを返す．
 *
 * @par 補足説明
 * スタンダードプロファイルでは，タスクの起動要求キューイング数の最大値は，
 * 1以上であればいくつであってもよい．
 * したがって，スタンダードプロファイルに準拠したカーネルで，
 * 起動要求がキューイングされているタスクを指定してこのサービスコールを呼び出しても，
 * E_QOVR エラーが返るとは限らない．
 *
 * @par μITRON3.0仕様との相違
 * 新設のサービスコールである．
 *
 * @param[in] tskid 起動対象のタスクの ID 番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正 ID 番号（tskid が不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_QOVR  キューイングオーバーフロー（起動要求キューイング数のオーバーフロー）
 */
SYSCALL ER iact_tsk(ID tskid)
{
    TCB *tcb;
    ER  ercd;

    LOG_IACT_TSK_ENTER(tskid);
    CHECK_INTCTX_UNL();
    CHECK_TSKID(tskid);
    tcb = get_tcb(tskid);

    i_lock_cpu();
    if (TSTAT_DORMANT(tcb->tstat)) {
        if (make_active(tcb)) {
            reqflg = TRUE;
        }
        ercd = E_OK;
    } else if (!(tcb->actcnt)) {
        tcb->actcnt = TRUE;
        ercd = E_OK;
    } else {
        ercd = E_QOVR;
    }
    i_unlock_cpu();

exit:
    LOG_IACT_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __iact_tsk */

#ifdef __can_act
/**
 * @brief タスク起動要求のキャンセル
 *
 * @par 機能
 * tskid で指定されるタスクに対してキューイングされている起動要求をキャンセルし，
 * キューイングされていた起動要求の回数を返す．
 * 具体的には，タスクの起動要求キューイング数を0にクリアし，
 * クリアする前の起動要求キューイング数を返す．
 * \n
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 *
 * @par 補足説明
 * 休止状態のタスクを対象タスクとして呼び出すこともできる．
 * この場合，休止状態のタスクには起動要求がキューイングされていないために，
 * サービスコールの返値は0となる．
 * \n
 * このサービスコールは，タスクを周期的に起動して処理を行う場合に，
 * 周期内に処理が終わっているかどうかを判定するために用いることができる．
 * 具体的には，前の起動要求に対する処理が終了した時点でcan_act を呼び出し，
 * その返値が1以上の値であった場合，前の起動要求に対する処理が周期内に終了せず，
 * 次の起動要求が行われたことがわかる．したがって，処理の遅れに対する処置をとることができる．
 *
 * @par μITRON3.0仕様との相違
 * 新設のサービスコールである．
 *
 * @param[in] tskid 起動対象要求のキャンセル対象のタスクの ID 番号
 * @retval actcnt  キューイングされていた起動要求の回数（正の値または0）
 * @retval E_ID    不正 ID 番号（tskid が不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 */
SYSCALL ER_UINT can_act(ID tskid)
{
    TCB    *tcb;
    ER_UINT ercd;

    LOG_CAN_ACT_ENTER(tskid);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID_SELF(tskid);
    tcb = get_tcb_self(tskid);

    t_lock_cpu();
    ercd = tcb->actcnt ? 1 : 0;
    tcb->actcnt = FALSE;
    t_unlock_cpu();

exit:
    LOG_CAN_ACT_LEAVE(ercd);
    return ercd;
}

#endif /* __can_act */

#ifdef __ext_tsk

/**
 * @brief 自タスクの終了
 *
 * @par 機能
 * 自タスクを終了させる．具体的には，自タスクを実行状態から休止状態に移行させ，
 * タスクの終了時に行うべき処理を行う．
 * \n
 * 自タスクに対する起動要求がキューイングされている場合，具体的には，
 * 自タスクの起動要求キューイング数が1以上の場合には，
 * 起動要求キューイング数から1を減じ，自タスクを実行可能状態に移行させる．
 * この時，タスク起動時に行うべき処理を行う．
 * タスクを起動する際のパラメータとしては，タスクの拡張情報を渡す．
 * \n
 * このサービスコールは，リターンすることがないサービスコールである．
 * したがって，サービスコール内で何らかのエラーを検出した場合でも，
 * エラーコードを返すことはできない．サービスコール内のエラーを検出するか否かと，
 * もし検出した場合の振る舞いは実装定義とする．
 *
 * @par 補足説明
 * このサービスコールは，自タスクに対する起動要求がキューイングされている場合，
 * 自タスクをいったん終了させた後に再起動する．そのため，
 * 自タスクがロックしているミューテックスをロック解除し，
 * 上限プロセッサ時間の設定を解除する．また，タスクのベース優先度（および現在優先度），
 * 起床要求キューイング数，強制待ち要求ネスト数，保留例外要因，
 * タスク例外処理禁止／許可状態を，タスクの起動直後の状態に初期化する．
 * 再起動されたタスクの優先順位は，同じ優先度を持つタスクの中で最低の優先順位となる．
 * \n
 * サービスコール内でエラーを検出した場合，検出したエラーに関する情報を，
 * エラーログに残すなどの方法が考えられる．
 * \n
 * タスクのメインルーチンからリターンした場合も，ext_tskを呼び出した場合と同じ振舞いをする．
 *
 * @par μITRON3.0仕様との相違
 * 起動要求をキューイングする機能を追加したため，このサービスコールは，
 * 自タスクを終了させた後に再起動する場合がある．
 *
 * @return なし
 * @attention このサービスコールからはリターンしない
 */
SYSCALL void ext_tsk(void)
{
    LOG_EXT_TSK_ENTER();

#ifdef oACTIVATED_STACK_SIZE
    /*
     *  create_context と activate_context で，使用中のスタック領
     *  域を破壊しないように，スタック上にダミー領域を確保する．
     */
    (void) alloca(ACTIVATED_STACK_SIZE);
#endif /* ACTIVATED_STACK_SIZE */

    if (sense_context()) {
        /*
         *  非タスクコンテキストから ext_tsk が呼ばれた場合，
         *  システムログにエラーを記録し，そのまま実行を続ける
         *  が, 動作は保証されない．
         */
        syslog_0(LOG_EMERG,
            "ext_tsk is called from non-task contexts.");
    }
    if (sense_lock()) {
        /*
         *  CPUロック状態で ext_tsk が呼ばれた場合は，CPUロック
         *  を解除してからタスクを終了する．実装上は，サービス
         *  コール内でのCPUロックを省略すればよいだけ．
         */
        syslog_0(LOG_WARNING,
            "ext_tsk is called from CPU locked state.");
    } else {
        if (sense_context()) {
            i_lock_cpu();
        } else  {
            t_lock_cpu();
        }
    }
    if (!(enadsp)) {
        /*
         *  ディスパッチ禁止状態で ext_tsk が呼ばれた場合は，
         *  ディスパッチ許可状態にしてからタスクを終了する．
         */
        syslog_0(LOG_WARNING,
            "ext_tsk is called from dispatch disabled state.");
        enadsp = TRUE;
    }
    exit_task();
}

#endif /* __ext_tsk */

#ifdef __ter_tsk

/**
 * @brief タスクの強制終了
 *
 * @par 機能
 * tskidで指定されるタスクを強制的に終了させる．具体的には，
 * 対象タスクを休止状態に移行させ，タスクの終了時に行うべき処理を行う．
 * \n
 * 対象タスクに対する起動要求がキューイングされている場合，具体的には，
 * 対象タスクの起動要求キューイング数が1以上の場合には，
 * 起動要求キューイング数から1を減じ，対象タスクを実行可能状態に移行させる．
 * この時，タスクの起動時に行うべき処理を行う．
 * タスクを起動する際のパラメータとしては，タスクの拡張情報を渡す．
 * \n
 * 対象タスクが休止状態の時はE_OBJエラーを返す．
 * また，このサービスコールで自タスクを終了させることはできない．
 * 対象タスクが自タスクの場合には，E_ILUSEエラーを返す．
 *
 * @par 補足説明
 * このサービスコールは，対象タスクが広義の待ち状態にある場合にも，
 * 対象タスクを強制的に終了させる．
 * 対象タスクが何らかの待ち行列につながれていた場合には，
 * 対象タスクを待ち行列から外す．その際に，
 * その待ち行列で待っている他のタスクの待ち解除が必要になる場合がある
 * （snd_mbf の機能説明とget_mplの機能説明を参照）．
 * \n
 * このサービスコールは，対象タスクに対する起動要求がキューイングされている場合，
 * 対象タスクをいったん終了させた後に再起動する．
 * そのため，対象タスクがロックしているミューテックスをロック解除し，
 * 上限プロセッサ時間の設定を解除する．
 * また，タスクのベース優先度（および現在優先度），起床要求キューイング数，
 * 強制待ち要求ネスト数，保留例外要因，タスク例外処理禁止／許可状態を，
 * タスクの起動直後の状態に初期化する．再起動されたタスクの優先順位は，
 * 同じ優先度を持つタスクの中で最低の優先順位となる．
 *
 * @par μITRON3.0仕様との相違
 * 対象タスクに自タスクが指定された場合のエラーを，E_OBJからE_ILUSEに変更した．
 * \n
 * 起動要求をキューイングする機能を追加したため，このサービスコールは，
 * 対象タスクを終了させた後に再起動する場合がある．
 *
 * @param[in] tskid 強制終了対象のタスクの ID 番号
 * @retval E_OK    正常終了
 * @retval E_ID    不正 ID 番号（tskid が不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_ILUSE サービスコールの不正使用（対象タスクが自タスク）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが休止状態）
 */
SYSCALL ER ter_tsk(ID tskid)
{
    TCB  *tcb;
    UINT  tstat;
    ER    ercd;

    LOG_TER_TSK_ENTER(tskid);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID(tskid);
    tcb = get_tcb(tskid);
    CHECK_NONSELF(tcb);

    t_lock_cpu();
    if (TSTAT_DORMANT(tstat = tcb->tstat)) {
        ercd = E_OBJ;
    } else {
        if (TSTAT_RUNNABLE(tstat)) {
            make_non_runnable(tcb);
        } else if (TSTAT_WAITING(tstat)) {
            wait_cancel(tcb);
        }
        make_dormant(tcb);
        if (tcb->actcnt) {
            tcb->actcnt = FALSE;
            if (make_active(tcb)) {
                dispatch();
            }
        }
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_TER_TSK_LEAVE(ercd);
    return ercd;
}

#endif /* __ter_tsk */

#ifdef __chg_pri

/**
 * @brief タスク優先度の変更
 *
 * @par 機能
 * tskidで指定されるタスクのベース優先度を，tskpriで指定される値に変更する．
 * それに伴って，タスクの現在優先度も変更する．
 * \n
 * tskid にTSK_SELF（＝ 0）が指定されると，自タスクを対象タスクとする．
 * また，tskpri にTPRI_INI（＝ 0）が指定されると，対象タスクのベース優先度を，
 * タスクの起動時優先度に変更する．
 * \n
 * このサービスコールを実行した結果，対象タスクの現在優先度が変化した場合
 * および現在優先度がベース優先度に一致している場合
 * （ミューテックス機能を使わない場合には，この条件は常に成り立つ）には，次の処理を行う．
 * 対象タスクが実行できる状態である場合，タスクの優先順位を，
 * 変更後の優先度にしたがって変化させる．変更後の優先度と同じ優先度を持つタスクの間では，
 * 対象タスクの優先順位を最低とする．
 * 対象タスクが何らかのタスク優先度順の待ち行列につながれている場合にも，
 * その待ち行列の中での順序を，変更後の優先度にしたがって変化させる．
 * 変更後の優先度と同じ優先度を持つタスクの間では，対象タスクを最後につなぐ．
 * \n
 * 対象タスクがTA_CEILING属性のミューテックスをロックしているか，
 * ロックを待っている場合で，tskpriで指定されたベース優先度が，
 * それらのミューテックスのいずれかの上限優先度よりも高い場合には，E_ILUSEエラーを返す．
 *
 * @par 補足説明
 * このサービスコールを呼び出した結果，対象タスクのタスク優先度順の待ち行列の中での順序が変化した場合，
 * 対象タスクないしはその待ち行列で待っている他のタスクの待ち解除が必要になる場合がある
 * （snd_mbf の機能説明と get_mplの機能説明を参照）．
 * \n
 * 対象タスクが，TA_INHERIT属性のミューテックスのロック待ち状態である場合，
 * このサービスコールでベース優先度を変更したことにより，推移的な優先度継承の処理が必要になる場合がある．
 * \n
 * ミューテックス機能を使わない場合には，対象タスクに自タスク，
 * 変更後の優先度に自タスクのベース優先度を指定してこのサービスコールが呼び出されると，
 * 自タスクの実行順位は同じ優先度を持つタスクの中で最低となる．
 * そのため，このサービスコールを用いて，実行権の放棄を行うことができる．
 *
 * @par μITRON3.0仕様との相違
 * ミューテックスの導入に伴って，chg_priはタスクのベース優先度を変更するものとした．
 * tskpriにTPRI_INIを指定できる機能を，標準的な機能とした．
 *
 * @param[in] tskid  変更象のタスクの ID 番号
 * @param[in] tskpri 変更語のベース優先度
 * @retval E_OK    正常終了
 * @retval E_ID    不正 ID 番号（tskid が不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_PAR   パラメータエラー（tskpri が不正）
 * @retval E_ILUSE サービスコールの不正使用（上限優先度の違反）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが休止状態）
 */
SYSCALL ER chg_pri(ID tskid, PRI tskpri)
{
    TCB  *tcb;
    UINT  newpri;
    UINT  tstat;
    ER    ercd;

    LOG_CHG_PRI_ENTER(tskid, tskpri);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID_SELF(tskid);
    CHECK_TPRI_INI(tskpri);
    tcb = get_tcb_self(tskid);
    newpri = (tskpri == TPRI_INI) ? tcb->tinib->ipriority
                    : INT_PRIORITY(tskpri);

    t_lock_cpu();
    if (TSTAT_DORMANT(tstat = tcb->tstat)) {
        ercd = E_OBJ;
    } else if (TSTAT_RUNNABLE(tstat)) {
        if (change_priority(tcb, newpri)) {
            dispatch();
        }
        ercd = E_OK;
    } else {
        tcb->priority = newpri;
        if ((tstat & TS_WAIT_WOBJCB) != 0) {
            wobj_change_priority(((WINFO_WOBJ *)(tcb->winfo))
                            ->wobjcb, tcb);
        }
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_CHG_PRI_LEAVE(ercd);
    return ercd;
}

#endif /* __chg_pri */

#ifdef __get_pri

/**
 * @brief タスク優先度の参照
 *
 * @par 機能
 * tskidで指定されるタスクの現在優先度を参照し，tskpriに返す．
 * \n
 * tskidにTSK_SELF（＝0）が指定されると，自タスクを対象タスクとする．
 *
 * @par 補足説明
 * chg_priがタスクのベース優先度を変更するのに対して，
 * get_priはタスクの現在優先度を参照する．
 *
 * @par μITRON3.0仕様との相違
 * 新設のサービスコールである．このサービスコールを新設したのは，
 * 送信するメッセージの優先度に自タスクの優先度を設定する場合などに，
 * 自タスクの優先度を小さいオーバヘッドで取り出す方法が必要となるためである．

 * @par 仕様決定の理由
 * tskpri をサービスコールの返値としなかったのは，他の類似のサービスコール（get_yyy）との整合性と，
 * 実装独自に優先度に負の値を使う場合を考慮したためである．
 *
 * @param[in] ercd 正常終了（E_OK）またはエラーコード
 * @param[out] tskpri 対象タスクの現在優先度
 * @retval E_ID    不正ID番号（tskidが不正あるいは使用できない）
 * @retval E_NOEXS オブジェクト未生成（対象タスクが未登録）
 * @retval E_PAR   パラメータエラー（p_tskpriが不正）
 * @retval E_OBJ   オブジェクト状態エラー（対象タスクが休止状態）
 */
SYSCALL ER get_pri(ID tskid, PRI *p_tskpri)
{
    TCB *tcb;
    ER   ercd;

    LOG_GET_PRI_ENTER(tskid, p_tskpri);
    CHECK_TSKCTX_UNL();
    CHECK_TSKID_SELF(tskid);
    tcb = get_tcb_self(tskid);

    t_lock_cpu();
    if (TSTAT_DORMANT(tcb->tstat)) {
        ercd = E_OBJ;
    } else {
        *p_tskpri = EXT_TSKPRI(tcb->priority);
        ercd = E_OK;
    }
    t_unlock_cpu();

exit:
    LOG_GET_PRI_LEAVE(ercd, *p_tskpri);
    return ercd;
}

#endif /* __get_pri */
