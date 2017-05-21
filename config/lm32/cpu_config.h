/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation 
 *  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
 *  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
 *  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: cpu_config.h,v 1.14 2007/07/27 11:28:44 honda Exp $
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

#include "cpu_defs.h"

#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif

#ifndef _MACRO_ONLY

extern UW exception_count;
extern UW exception_registers[40];

typedef struct task_context_block {
        VP	sp;             
        FP	pc;             
} CTXB;


Inline BOOL
sense_context()
{
    return(exception_count > 0);
}

Inline BOOL
sense_lock()
{
    return((current_sr() & 0x1) == 0);
}

#define t_sense_lock     sense_lock
#define i_sense_lock     sense_lock

Inline void
lock_cpu()
{
    disint();
}

Inline void
unlock_cpu()
{
    enaint();
}

#define EXC_ENTRY(exchdr)     exchdr
#define EXCHDR_ENTRY(exchdr)  extern void exchdr(VP sp)

Inline BOOL
exc_sense_context(VP p_excinf)
{
    return(exception_count > 1);
}

Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return((current_sr() & 0x2) == 0);
}


#define t_lock_cpu      lock_cpu
#define i_lock_cpu      lock_cpu
#define t_unlock_cpu    unlock_cpu
#define i_unlock_cpu    unlock_cpu

extern void dispatch(void);
extern void exit_and_dispatch(void);

extern FP int_table[TMAX_ALL_INTNO];
extern FP exc_table[TMAX_CORE_EXCNO];

Inline void define_inh(INTNO intno, FP inthdr)
{
    int_table[intno] = inthdr;
}

Inline void define_exc(EXCNO excno, FP exchdr)
{
    exc_table[excno] = exchdr;
}

extern void _start();
extern void Breakpoint_exception();
extern void InstructionBusError_exception();
extern void Watchpoint_exception();
extern void DataBusError_exception();
extern void DivideByZero_exception();
extern void Interrupt_exception();
extern void SystemCall_exception();

extern void cpu_initialize(void);
extern void cpu_terminate(void);

#endif /* _MACRO_ONLY */

#endif /* _CPU_CONFIG_H_ */

