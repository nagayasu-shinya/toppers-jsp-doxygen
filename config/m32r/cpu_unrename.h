/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2003 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: cpu_unrename.h,v 1.6 2007/05/30 03:56:47 honda Exp $
 */

#ifdef _CPU_RENAME_H_
#undef _CPU_RENAME_H_

#ifndef OMIT_RENAME

#undef _reset
#undef vector_entry_SBI
#undef vector_entry_RIE
#undef vector_entry_AE
#undef vector_entry_trap
#undef _trap_handler_0
#undef _trap_handler_1
#undef _trap_handler_2
#undef _trap_handler_3
#undef _trap_handler_4
#undef _trap_handler_5
#undef _trap_handler_6
#undef _trap_handler_7
#undef _trap_handler_8
#undef _trap_handler_9
#undef _trap_handler_10
#undef _trap_handler_11
#undef _trap_handler_12
#undef _trap_handler_13
#undef _trap_handler_14
#undef _trap_handler_15
#undef interrupt_handler
#undef InterruptHandlerEntry
#undef interrupt_handler_r
#undef recover_task_r
#undef recover_task
#undef recover_int
#undef exit_interrupt_handler
#undef _exception_handler
#undef ExceptionHandlerEntry
#undef _unhandled_interrupt_handler
#undef exit_exception_handler
#undef exception_handler_r
#undef recover_exception_exc_task_r
#undef dispatch
#undef reqflg
#undef calltex
#undef runtsk
#undef dispatch_r
#undef exit_and_dispatch
#undef schedtsk
#undef activate_r

#ifdef LABEL_ASM

#undef __reset
#undef _vector_entry_SBI
#undef _vector_entry_RIE
#undef _vector_entry_AE
#undef _vector_entry_trap
#undef __trap_handler_0
#undef __trap_handler_1
#undef __trap_handler_2
#undef __trap_handler_3
#undef __trap_handler_4
#undef __trap_handler_5
#undef __trap_handler_6
#undef __trap_handler_7
#undef __trap_handler_8
#undef __trap_handler_9
#undef __trap_handler_10
#undef __trap_handler_11
#undef __trap_handler_12
#undef __trap_handler_13
#undef __trap_handler_14
#undef __trap_handler_15
#undef _interrupt_handler
#undef _InterruptHandlerEntry
#undef _interrupt_handler_r
#undef _recover_task_r
#undef _recover_task
#undef _recover_int
#undef _exit_interrupt_handler
#undef __exception_handler
#undef _ExceptionHandlerEntry
#undef __unhandled_interrupt_handler
#undef _exit_exception_handler
#undef _exception_handler_r
#undef _recover_exception_exc_task_r
#undef _dispatch
#undef _reqflg
#undef _calltex
#undef _runtsk
#undef _dispatch_r
#undef _exit_and_dispatch
#undef _schedtsk
#undef _activate_r

#endif /* LABEL_ASM */
#endif /* OMIT_RENAME */
#endif /* _CPU_RENAME_H_ */
