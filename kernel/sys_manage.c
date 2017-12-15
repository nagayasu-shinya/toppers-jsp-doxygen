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
 *  @(#) $Id: sys_manage.c,v 1.8 2003/07/01 13:30:35 hiro Exp $
 */

/**
 * @file
 * @brief システム状態管理機能
 *
 * @copyright 2000 by Embedded and Real-Time Systems Laboratory Toyohashi Univ. of Technology, JAPAN
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

#ifdef __rot_rdq

/**
 * @brief タスクの優先順位の回転
 *
 * @par 機能
 * tskpri で指定される優先度のタスクの優先順位を回転する．
 * すなわち，対象優先度を持った実行できる状態のタスクの中で，
 * 最も高い優先順位を持つタスクを，同じ優先度を持つタスクの中で最低の優先順位とする．
 * \n
 * tskpriにTPRI_SELF（＝0）が指定されると，自タスクのベース優先度を対象優先度とする．
 * ただし，非タスクコンテキストからの呼出しでこの指定が行われた場合には，E_PARエラーを返す．
 *
 * @par 補足説明
 * このサービスコールを周期的に呼び出すことにより，ラウンドロビン方式を実現することができる．
 * 対象優先度を持った実行できる状態のタスクがない場合や，
 * 一つしかない場合には，何もしない（エラーとはしない）．
 * \n
 * ディスパッチ許可状態で，
 * 対象優先度に自タスクの現在優先度を指定してこのサービスコールが呼び出されると，
 * 自タスクの実行順位は同じ優先度を持つタスクの中で最低となる．
 * そのため，このサービスコールを用いて，実行権の放棄を行うことができる．
 * ディスパッチ禁止状態では，同じ優先度を持つタスクの中で最高の優先順位を持ったタスクが実行されているとは限らないため，
 * この方法で自タスクの実行順位が同じ優先度を持つタスクの中で最低となるとは限らない．
 * 自タスクの現在優先度がベース優先度に一致している場合
 * （ミューテックス機能を使わない場合には，この条件は常に成り立つ）には，
 * tskpriにTPRI_SELFを指定しても同じ結果となる．
 *
 * @par μITRON3.0仕様との相違
 * 非タスクコンテキストから呼び出された場合に，
 * 実行状態のタスクの優先度を対象優先度とする指定は規定しないこととした．
 * これに伴って，TPRI_RUNをTPRI_SELFに名称変更した．また，ミューテックスの導入に伴って，
 * TPRI_SELFは自タスクのベース優先度を指定するものとした．
 *
 * @param[in]  tskpri 優先順位を回転する対象の優先度
 * @retval E_OK 正常終了
 * @retval E_PAR パラメータエラー（tskpriが不正）
 */
SYSCALL ER rot_rdq(PRI tskpri)
{
    UINT pri;
    ER   ercd;

    LOG_ROT_RDQ_ENTER(tskpri);
    CHECK_TSKCTX_UNL();
    CHECK_TPRI_SELF(tskpri);

    t_lock_cpu();
    pri = (tskpri == TPRI_SELF) ? runtsk->priority : INT_PRIORITY(tskpri);
    if (rotate_ready_queue(pri)) {
        dispatch();
    }
    ercd = E_OK;
    t_unlock_cpu();

exit:
    LOG_ROT_RDQ_LEAVE(ercd);
    return ercd;
}

#endif /* __rot_rdq */

/*
 *  タスクの優先順位の回転（非タスクコンテキスト用）
 */
#ifdef __irot_rdq

/**
 * @brief タスクの優先順位の回転
 *
 * @par 機能
 * tskpri で指定される優先度のタスクの優先順位を回転する．
 * すなわち，対象優先度を持った実行できる状態のタスクの中で，
 * 最も高い優先順位を持つタスクを，同じ優先度を持つタスクの中で最低の優先順位とする．
 * \n
 * tskpriにTPRI_SELF（＝0）が指定されると，自タスクのベース優先度を対象優先度とする．
 * ただし，非タスクコンテキストからの呼出しでこの指定が行われた場合には，E_PARエラーを返す．
 *
 * @par 補足説明
 * このサービスコールを周期的に呼び出すことにより，ラウンドロビン方式を実現することができる．
 * 対象優先度を持った実行できる状態のタスクがない場合や，
 * 一つしかない場合には，何もしない（エラーとはしない）．
 * \n
 * ディスパッチ許可状態で，
 * 対象優先度に自タスクの現在優先度を指定してこのサービスコールが呼び出されると，
 * 自タスクの実行順位は同じ優先度を持つタスクの中で最低となる．
 * そのため，このサービスコールを用いて，実行権の放棄を行うことができる．
 * ディスパッチ禁止状態では，同じ優先度を持つタスクの中で最高の優先順位を持ったタスクが実行されているとは限らないため，
 * この方法で自タスクの実行順位が同じ優先度を持つタスクの中で最低となるとは限らない．
 * 自タスクの現在優先度がベース優先度に一致している場合
 * （ミューテックス機能を使わない場合には，この条件は常に成り立つ）には，
 * tskpriにTPRI_SELFを指定しても同じ結果となる．
 *
 * @par μITRON3.0仕様との相違
 * 非タスクコンテキストから呼び出された場合に，
 * 実行状態のタスクの優先度を対象優先度とする指定は規定しないこととした．
 * これに伴って，TPRI_RUNをTPRI_SELFに名称変更した．また，ミューテックスの導入に伴って，
 * TPRI_SELFは自タスクのベース優先度を指定するものとした．
 *
 * @param[in]  tskpri 優先順位を回転する対象の優先度
 * @retval E_OK 正常終了
 * @retval E_PAR パラメータエラー（tskpriが不正）
 */
SYSCALL ERirot_rdq(PRI tskpri)
{
    ER ercd;

    LOG_IROT_RDQ_ENTER(tskpri);
    CHECK_INTCTX_UNL();
    CHECK_TPRI(tskpri);

    i_lock_cpu();
    if (rotate_ready_queue(INT_PRIORITY(tskpri))) {
        reqflg = TRUE;
    }
    ercd = E_OK;
    i_unlock_cpu();

exit:
    LOG_IROT_RDQ_LEAVE(ercd);
    return ercd;
}

#endif /* __irot_rdq */

#ifdef __get_tid

/**
 * @brief 実行状態のタスクIDの参照
 *
 * @par 機能
 * 実行状態のタスク（タスクコンテキストから呼び出された場合は，
 * 自タスクに一致する）のID 番号を参照し，tskid に返す．
 * 非タスクコンテキストから呼び出された場合で，
 * 実行状態のタスクがない時には，tskid にTSK_NONE（＝ 0）を返す．
 *
 * @par 補足説明
 * アプリケーションが用意したタスクがどれも実行できる状態にない場合に，
 * カーネルが用意したタスク（一般的にはアイドルタスクと呼ばれる）を実行するような実装では，
 * アイドルタスクが実行状態の時にこのサービスコールが呼び出された場合，
 * アイドルタスクのID番号ではなく，TSK_NONEを返す．
 *
 * @par μITRON3.0仕様との相違
 * 自タスクのID 番号を返すサービスコールから，
 * 実行状態のタスクのID 番号を返すものに変更した．
 * 具体的には，非タスクコンテキストから呼び出した場合の振舞いが変更になった．
 *
 * @par 仕様決定の理由
 * tskidをサービスコールの返値としなかったのは，
 * タスクのID番号が負の値になる場合に対応するためである．
 *
 * @param[out] p_tskid 実行状態のタスクのID番号
 * @retval E_OK  正常終了
 * @retval E_PAR パラメータエラー（p_tskidが不正）
 */
SYSCALL ER get_tid(ID *p_tskid)
{
    ER ercd;

    LOG_GET_TID_ENTER(p_tskid);
    CHECK_TSKCTX_UNL();

    t_lock_cpu();
    *p_tskid = TSKID(runtsk);
    ercd = E_OK;
    t_unlock_cpu();

exit:
    LOG_GET_TID_LEAVE(ercd, *p_tskid);
    return ercd;
}

#endif /* __get_tid */

#ifdef __iget_tid

/**
 * @brief 実行状態のタスクIDの参照（非タスクコンテキスト用）
 *
 * @par 機能
 * 実行状態のタスク（タスクコンテキストから呼び出された場合は，
 * 自タスクに一致する）のID 番号を参照し，tskid に返す．
 * 非タスクコンテキストから呼び出された場合で，
 * 実行状態のタスクがない時には，tskid にTSK_NONE（＝ 0）を返す．
 *
 * @par 補足説明
 * アプリケーションが用意したタスクがどれも実行できる状態にない場合に，
 * カーネルが用意したタスク（一般的にはアイドルタスクと呼ばれる）を実行するような実装では，
 * アイドルタスクが実行状態の時にこのサービスコールが呼び出された場合，
 * アイドルタスクのID番号ではなく，TSK_NONEを返す．
 *
 * @par μITRON3.0仕様との相違
 * 自タスクのID 番号を返すサービスコールから，
 * 実行状態のタスクのID 番号を返すものに変更した．
 * 具体的には，非タスクコンテキストから呼び出した場合の振舞いが変更になった．
 *
 * @par 仕様決定の理由
 * tskidをサービスコールの返値としなかったのは，
 * タスクのID番号が負の値になる場合に対応するためである．
 *
 * @param[out] p_tskid 実行状態のタスクのID番号
 * @retval E_OK  正常終了
 * @retval E_PAR パラメータエラー（p_tskidが不正）
 */
SYSCALL ER iget_tid(ID *p_tskid)
{
    ER ercd;

    LOG_IGET_TID_ENTER(p_tskid);
    CHECK_INTCTX_UNL();

    i_lock_cpu();
    *p_tskid = (runtsk == NULL) ? TSK_NONE : TSKID(runtsk);
    ercd = E_OK;
    i_unlock_cpu();

exit:
    LOG_IGET_TID_LEAVE(ercd, *p_tskid);
    return ercd;
}

#endif /* __iget_tid */

#ifdef __loc_cpu

/**
 * @brief CPUロック状態への移行
 *
 * @par 機能
 * CPUロック状態に移行する．CPUロック状態で呼び出された場合には何もしない．
 *
 * @par 補足説明
 * loc_cpu（またはiloc_cpu）が複数回呼び出されても，unl_cpu（またはiunl_cpu）が一回呼び出されると
 * CPU ロック解除状態となる．
 * したがって，loc_cpu（またはiloc_cpu）とunl_cpu（またはiunl_cpu）の対をネストさせたい場合には，
 * 次のような方法で対処することが必要である．
 * @code
 * {
 *     BOOL cpu_locked = sns_loc() ;
 *     if (!cpu_locked)
 *         loc_cpu () ;
 *     CPUロック状態で行うべき処理
 *
 *     if (!cpu_locked)
 *         unl_cpu() ;
 * }
 * @endcode
 *
 * @par μITRON3.0仕様との相違
 * CPUロック状態の意味を変更した．
 * また，非タスクコンテキストからも呼び出せるものとした．
 *
 * @retval E_OK 正常終了
 */
SYSCALL ER loc_cpu(void)
{
    ER ercd;

    LOG_LOC_CPU_ENTER();
    CHECK_TSKCTX();

    if (!(t_sense_lock())) {
        t_lock_cpu();
    }
    ercd = E_OK;

exit:
    LOG_LOC_CPU_LEAVE(ercd);
    return ercd;
}

#endif /* __loc_cpu */

#ifdef __iloc_cpu

/**
 * @brief CPUロック状態への移行（非タスクコンテキスト用）
 *
 * @par 機能
 * CPUロック状態に移行する．CPUロック状態で呼び出された場合には何もしない．
 *
 * @par 補足説明
 * loc_cpu（またはiloc_cpu）が複数回呼び出されても，unl_cpu（またはiunl_cpu）が一回呼び出されると
 * CPU ロック解除状態となる．
 * したがって，loc_cpu（またはiloc_cpu）とunl_cpu（またはiunl_cpu）の対をネストさせたい場合には，
 * 次のような方法で対処することが必要である．
 * @code
 * {
 *     BOOL cpu_locked = sns_loc() ;
 *     if (!cpu_locked)
 *         loc_cpu () ;
 *     CPUロック状態で行うべき処理
 *
 *     if (!cpu_locked)
 *         unl_cpu() ;
 * }
 * @endcode
 *
 * @par μITRON3.0仕様との相違
 * CPUロック状態の意味を変更した．
 * また，非タスクコンテキストからも呼び出せるものとした．
 *
 * @retval E_OK 正常終了
 */
SYSCALL ER iloc_cpu(void)
{
    ER ercd;

    LOG_ILOC_CPU_ENTER();
    CHECK_INTCTX();

    if (!(i_sense_lock())) {
        i_lock_cpu();
    }
    ercd = E_OK;

exit:
    LOG_ILOC_CPU_LEAVE(ercd);
    return ercd;
}

#endif /* __iloc_cpu */

#ifdef __unl_cpu

/**
 * @brief CPUロック状態の解除
 *
 * @par 機能
 * CPUロック解除状態に移行する．CPUロック解除状態で呼び出された場合には何もしない．
 *
 * @par μITRON3.0仕様との相違
 * CPUロック状態の意味を変更した．これにより，このサービスコールを呼び出しても，
 * ディスパッチ許可状態になるとは限らないこととなった．
 * また，非タスクコンテキストからも呼び出せるものとした．
 *
 * @note
 * CPUロック中は，ディスパッチが必要となるサービスコールを呼び出すことはできないため，
 * CPUロック状態の解除時にディスパッチャを起動する必要はない．
 *
 * @retval E_OK 正常終了
 */
SYSCALL ER unl_cpu(void)
{
    ER ercd;

    LOG_UNL_CPU_ENTER();
    CHECK_TSKCTX();

    if (t_sense_lock()) {
        t_unlock_cpu();
    }
    ercd = E_OK;

exit:
    LOG_UNL_CPU_LEAVE(ercd);
    return ercd;
}

#endif /* __unl_cpu */

#ifdef __iunl_cpu

/**
 * @brief CPUロック状態の解除（非タスクコンテキスト用）
 *
 * @par 機能
 * CPUロック解除状態に移行する．CPUロック解除状態で呼び出された場合には何もしない．
 *
 * @par μITRON3.0仕様との相違
 * CPUロック状態の意味を変更した．これにより，このサービスコールを呼び出しても，
 * ディスパッチ許可状態になるとは限らないこととなった．
 * また，非タスクコンテキストからも呼び出せるものとした．
 *
 * @note
 * CPUロック中は，ディスパッチが必要となるサービスコールを呼び出すことはできないため，
 * CPUロック状態の解除時にディスパッチャを起動する必要はない．
 *
 * @retval E_OK 正常終了
 */
SYSCALL ER iunl_cpu(void)
{
    ER ercd;

    LOG_IUNL_CPU_ENTER();
    CHECK_INTCTX();

    if (i_sense_lock()) {
        i_unlock_cpu();
    }
    ercd = E_OK;

exit:
    LOG_IUNL_CPU_LEAVE(ercd);
    return ercd;
}

#endif /* __iunl_cpu */

#ifdef __dis_dsp

/**
 * @brief ディスパッチの禁止
 *
 * @par 機能
 * ディスパッチ禁止状態に移行する．
 * ディスパッチ禁止状態で呼び出された場合には何もしない．
 *
 * @par 補足説明
 * dis_dsp が複数回呼び出されても，ena_dsp が一回呼び出されるとディスパッチ許可状態となる．
 * したがって，dis_dsp とena_dsp の対をネストさせたい場合には，
 * 次のような方法で対処することが必要である．
 * @code
 * {
 *     BOOL dispatch_disabled = sns_dsp();
 *     if (!dispatch_disabled)
 *         dis_dsp();
 *     ディスパッチ禁止状態で行うべき処理
 *     if (!dispatch_disabled)
 *         ena_dsp();
 * }
 * @endocode
 *
 * @par μITRON3.0仕様との相違
 * ディスパッチ禁止状態の意味を変更した．
 *
 * @retval E_OK 正常終了
 */
SYSCALL ER dis_dsp(void)
{
    ER ercd;

    LOG_DIS_DSP_ENTER();
    CHECK_TSKCTX_UNL();

    t_lock_cpu();
    enadsp = FALSE;
    ercd = E_OK;
    t_unlock_cpu();

exit:
    LOG_DIS_DSP_LEAVE(ercd);
    return ercd;
}

#endif /* __dis_dsp */

#ifdef __ena_dsp

/**
 * @brief ディスパッチの許可
 *
 * @par 機能
 * ディスパッチ許可状態に移行する．
 * ディスパッチ許可状態で呼び出された場合には何もしない．
 *
 * @par μITRON3.0仕様との相違
 * ディスパッチ禁止状態の意味を変更した．
 *
 * @retval E_OK 正常終了
 */
SYSCALL ER ena_dsp(void)
{
    ER ercd;

    LOG_ENA_DSP_ENTER();
    CHECK_TSKCTX_UNL();

    t_lock_cpu();
    enadsp = TRUE;
    if (runtsk != schedtsk) {
        dispatch();
    }
    ercd = E_OK;
    t_unlock_cpu();

exit:
    LOG_ENA_DSP_LEAVE(ercd);
    return ercd;
}

#endif /* __ena_dsp */

#ifdef __sns_ctx

/**
 * @brief コンテキストの参照
 *
 * @par 機能
 * 非タスクコンテキストから呼び出された場合にTRUE，
 * タスクコンテキストから呼び出された場合にFALSEを返す．
 *
 * @par μITRON3.0仕様との相違
 * 新設のサービスコールである．
 *
 * @retval TRUE  非タスクコンテキスト
 * @retval FALSE タスクコンテキスト
 */
SYSCALL BOOL sns_ctx(void)
{
    BOOL state;

    LOG_SNS_CTX_ENTER();
    state = sense_context() ? TRUE : FALSE;
    LOG_SNS_CTX_LEAVE(state);
    return state;
}

#endif /* __sns_ctx */

#ifdef __sns_loc

/**
 * @brief CPUロック状態の参照
 *
 * @par 機能
 * システムが，CPU ロック状態の場合にTRUE，
 * CPU ロック解除状態の場合にFALSEを返す．
 *
 * @par μITRON3.0仕様との相違
 * 新設のサービスコールである．
 *
 * @retval TRUE  CPUロック状態
 * @retval FALSE CPUロック解除状態
 */
SYSCALL BOOL sns_loc(void)
{
    BOOL state;

    LOG_SNS_LOC_ENTER();
    state = sense_lock() ? TRUE : FALSE;
    LOG_SNS_LOC_LEAVE(state);
    return state;
}

#endif /* __sns_loc */

#ifdef __sns_dsp

/**
 * @brief ディスパッチ禁止状態の参照
 *
 * @par 機能
 * システムが，ディスパッチ禁止状態の場合にTRUE，
 * ディスパッチ許可状態の場合にFALSEを返す．
 *
 * @par μITRON3.0仕様との相違
 * 新設のサービスコールである．
 *
 * @retval TRUE  ディスパッチ禁止状態
 * @retval FALSE ディスパッチ許可状態
 */
SYSCALL BOOL sns_dsp(void)
{
    BOOL state;

    LOG_SNS_DSP_ENTER();
    state = !(enadsp) ? TRUE : FALSE;
    LOG_SNS_DSP_LEAVE(state);
    return state;
}

#endif /* __sns_dsp */

#ifdef __sns_dpn

/**
 * @brief ディスパッチ保留状態の参照
 *
 * @par 機能
 * システムが，ディスパッチ保留状態の場合にTRUE，
 * そうでない場合にFALSEを返す．すなわち，
 * ディスパッチャよりも優先順位の高い処理が実行されているか，
 * CPUロック状態であるか，ディスパッチ禁止状態であるかのいずれかの場合に，TRUEを返す．
 *
 * @par 補足説明
 * このサービスコールがFALSE を返す状態では，
 * 自タスクを広義の待ち状態にする可能性のあるサービスコールを呼び出すことができる．
 *
 * @par μITRON3.0仕様との相違
 * 新設のサービスコールである．
 *
 * @retval TRUE  ディスパッチ保留状態
 * @retval FALSE ディスパッチ保留状態以外
 */
SYSCALL BOOL sns_dpn(void)
{
    BOOL state;

    LOG_SNS_DPN_ENTER();
    state = (sense_context() || sense_lock() || !(enadsp)) ? TRUE : FALSE;
    LOG_SNS_DPN_LEAVE(state);
    return state;
}

#endif /* __sns_dpn */

/*
 *  カーネル動作状態の参照
 */
#ifdef __vsns_ini

SYSCALL BOOL
vsns_ini(void)
{
    BOOL state;

    LOG_VSNS_INI_ENTER();
    state = !(iniflg) ? TRUE : FALSE;
    LOG_VSNS_INI_LEAVE(state);
    return state;
}

#endif /* __vsns_ini */
