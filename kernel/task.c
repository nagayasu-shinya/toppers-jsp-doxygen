/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: task.c,v 1.12 2006/02/12 05:29:32 hiro Exp $
 */

/**
 * @file タスク管理モジュール
 *
 * @copyright 2000-2003 by Embedded and Real-Time Systems Laboratory Toyohashi Univ. of Technology, JAPAN
 * @copyright 2005,2006 by Embedded and Real-Time Systems Laboratory Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include "jsp_kernel.h"
#include "task.h"
#include <cpu_context.h>

#ifdef __tskini

/*
 * @brief 実行状態のタスク
 */
TCB *runtsk;

/*
 * @brief 最高優先順位のタスク
 */
TCB *schedtsk;

/*
 * @brief タスクディスパッチ／タスク例外処理ルーチン起動要求フラグ
 */
BOOL reqflg;

/*
 * @brief  タスクディスパッチ許可状態
 */
BOOL enadsp;

/*
 * @brief レディキュー
 */
QUEUE ready_queue[TNUM_TPRI];

/*
 * @brief レディキューサーチのためのビットマップ
 *
 * ビットマップを UINT で定義しているが，ビットマップサーチ関数で優先
 * 度が16段階以下であることを仮定している．
 */
UINT ready_primap;

/*
 * @brief タスク管理モジュールの初期化
 */
void task_initialize(void)
{
    UINT i, j;
    TCB  *tcb;

    runtsk = schedtsk = NULL;
    reqflg = FALSE;
    enadsp = TRUE;

    for (i = 0; i < TNUM_TPRI; i++) {
        queue_initialize(&(ready_queue[i]));
    }
    ready_primap = 0;

    for (i = 0; i < TNUM_TSK; i++) {
        j = INDEX_TSK(torder_table[i]);
        tcb = &(tcb_table[j]);
        tcb->tinib = &(tinib_table[j]);
        tcb->actcnt = FALSE;
        make_dormant(tcb);
        if ((tcb->tinib->tskatr & TA_ACT) != 0) {
            make_active(tcb);
        }
    }
}

#endif /* __tskini */

#ifndef PRIMAP_BIT
#define    PRIMAP_BIT(pri)        (1u << (pri))
#endif /* PRIMAP_BIT */

#ifndef CPU_BITMAP_SEARCH

/*
 * @brief ビットマップサーチ関数
 *
 * bitmap 内の 1 のビットの内，最も下位（右）のものをサーチし，
 * そのビット番号を返す．ビット番号は，最下位ビットを 0 とする．
 * bitmap に 0を指定してはならない．
 * この関数では，優先度が16段階以下であることを仮定し，bitmap の下位16ビットのみをサーチする．
 * ビットサーチ命令を持つプロセッサでは，
 * ビットサーチ命令を使うように書き直した方が効率が良いだろう．
 * このような場合には，cpu_insn.h でビットサーチ命令を使った bitmap_search を定義し，
 * CPU_BITMAP_SEARCH をマクロ定義すればよい．
 * また，ビットサーチ命令のサーチ方向が逆などの理由で優先度とビットとの対応を変更したい場合には，
 * PRIMAP_BIT をマクロ定義すればよい．
 * また，標準ライブラリに ffs があるなら，次のように定義して標準ライブラリを使った方が効率が良い可能性もある．
 *    #define    bitmap_search(bitmap) (ffs(bitmap) - 1)
 *
 * @param[in] bitmap ビットサーチする変数
 * @return LSB から数えた先行ゼロの数
 */
Inline UINT bitmap_search(UINT bitmap)
{
    static const unsigned char search_table[] =
        { 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0 };
    UINT n = 0;

    assert((bitmap & 0xffff) != 0);
    if ((bitmap & 0x00ff) == 0) {
        bitmap >>= 8;
        n += 8;
    }
    if ((bitmap & 0x0f) == 0) {
        bitmap >>= 4;
        n += 4;
    }
    return n + search_table[(bitmap & 0x0f) - 1];
}

#endif /* CPU_BITMAP_SEARCH */

#ifdef __tsksched

/*
 * @brief 最高優先順位タスクのサーチ
 * @return 最高優先順位タスクのTCBへのポインタ
 */
TCB *search_schedtsk(void)
{
    UINT schedpri;

    schedpri = bitmap_search(ready_primap);
    return (TCB *) (ready_queue[schedpri].next);
}

#endif /* __tsksched */

#ifdef __tskrun

/*
 * @brief 実行できる状態への移行
 *
 * 最高優先順位のタスクを更新するのは，実行できるタスクがなかった場合と，
 * tcb の優先度が最高優先順位のタスクの優先度よりも高い場合である．
 */
BOOL make_runnable(TCB *tcb)
{
    UINT pri = tcb->priority;

    tcb->tstat = TS_RUNNABLE;
    LOG_TSKSTAT(tcb);
    queue_insert_prev(&(ready_queue[pri]), &(tcb->task_queue));
    ready_primap |= PRIMAP_BIT(pri);

    if (schedtsk == (TCB *) NULL || pri < schedtsk->priority) {
        schedtsk = tcb;
        return enadsp;
    }
    return FALSE;
}

#endif /* __tskrun */

#ifdef __tsknrun

/*
 * @brief 実行できる状態から他の状態への移行
 *
 * 最高優先順位のタスクを更新するのは，tcb が最高優先順位のタスクであった場合である．
 * tcb と同じ優先度のタスクが他にある場合は，tcb の次のタスクが最高優先順位になる．
 * そうでない場合は，レディキューをサーチする必要がある．
 */
BOOL make_non_runnable(TCB *tcb)
{
    UINT   pri = tcb->priority;
    QUEUE *queue = &(ready_queue[pri]);

    queue_delete(&(tcb->task_queue));
    if (queue_empty(queue)) {
        ready_primap &= ~PRIMAP_BIT(pri);
        if (schedtsk == tcb) {
            schedtsk = (ready_primap == 0) ? (TCB * ) NULL : search_schedtsk();
            return enadsp;
        }
    } else {
        if (schedtsk == tcb) {
            schedtsk = (TCB *) (queue->next);
            return enadsp;
        }
    }
    return FALSE;
}

#endif /* __tsknrun */

#ifdef __tskdmt

/*
 * @brief 休止状態への移行
 */
void make_dormant(TCB *tcb)
{
    tcb->priority = tcb->tinib->ipriority;
    tcb->tstat = TS_DORMANT;
    tcb->wupcnt = FALSE;
    tcb->enatex = FALSE;
    tcb->texptn = 0;
    create_context(tcb);
    LOG_TSKSTAT(tcb);
}

#endif /* __tskdmt */

#ifdef __tskact

/*
 * @brief 休止状態から実行できる状態への移行
 */
BOOL make_active(TCB *tcb)
{
    activate_context(tcb);
    return make_runnable(tcb);
}

#endif /* __tskact */

#ifdef __tskext

/*
 * @brief 実行状態のタスクの終了
 */
void exit_task(void)
{
    make_non_runnable(runtsk);
    make_dormant(runtsk);
    if (runtsk->actcnt) {
        runtsk->actcnt = FALSE;
        make_active(runtsk);
    }
    exit_and_dispatch();
}

#endif /* __tskext */

#ifdef __tskpri

/*
 * @brief レディキュー中のタスクの優先度の変更
 *
 * 最高優先順位のタスクを更新するのは，(1) tcb が最高優先順位のタスク
 * であって，その優先度を下げた場合，(2) tcb が最高優先順位のタスクで
 * はなく，変更後の優先度が最高優先順位のタスクの優先度よりも高い場合
 * である．(1) の場合には，レディキューをサーチする必要がある．
 */
BOOL change_priority(TCB *tcb, UINT newpri)
{
    UINT oldpri = tcb->priority;

    tcb->priority = newpri;
    queue_delete(&(tcb->task_queue));
    if (queue_empty(&(ready_queue[oldpri]))) {
        ready_primap &= ~PRIMAP_BIT(oldpri);
    }
    queue_insert_prev(&(ready_queue[newpri]), &(tcb->task_queue));
    ready_primap |= PRIMAP_BIT(newpri);

    if (schedtsk == tcb) {
        if (newpri >= oldpri) {
            schedtsk = search_schedtsk();
            return schedtsk != tcb && enadsp;
        }
    } else {
        if (newpri < schedtsk->priority) {
            schedtsk = tcb;
            return enadsp;
        }
    }
    return FALSE;
}

#endif /* __tskpri */

#ifdef __tskrot

/*
 * @brief レディキューの回転
 *
 * 最高優先順位のタスクを更新するのは，
 * 最高優先順位のタスクがタスクキューの末尾に移動した場合である．
 */
BOOL rotate_ready_queue(UINT pri)
{
    QUEUE *queue = &(ready_queue[pri]);
    QUEUE *entry;

    if (!(queue_empty(queue)) && queue->next->next != queue) {
        entry = queue_delete_next(queue);
        queue_insert_prev(queue, entry);
        if (schedtsk == (TCB *) entry) {
            schedtsk = (TCB *) (queue->next);
            return enadsp;
        }
    }
    return FALSE;
}

#endif /* __tskrot */

/**
 * @brief 引数まで定義したタスク例外処理ルーチンの型
 */
typedef void (*TEXRTN) (TEXPTN texptn, VP_INT exinf);

#ifdef __tsktex

/**
 * @brrief タスク例外処理ルーチンの呼出し
 * @return なし
 */
void call_texrtn(void)
{
    TEXPTN texptn;

    do {
        texptn = runtsk->texptn;
        runtsk->enatex = FALSE;
        runtsk->texptn = 0;
        t_unlock_cpu();
        LOG_TEX_ENTER(texptn);
        (*((TEXRTN) (runtsk->tinib->texrtn)))(texptn, runtsk->tinib->exinf);
        LOG_TEX_LEAVE(texptn);
        if (!t_sense_lock()) {
            t_lock_cpu();
        }
    } while (runtsk->texptn != 0);
    runtsk->enatex = TRUE;
}

#ifndef OMIT_CALLTEX

/*
 * @brief タスク例外処理ルーチンの起動
 * @return なし
 */
void calltex(void)
{
    if (runtsk->enatex && runtsk->texptn != 0) {
        call_texrtn();
    }
}

#endif /* OMIT_CALLTEX */
#endif /* __tsktex */
