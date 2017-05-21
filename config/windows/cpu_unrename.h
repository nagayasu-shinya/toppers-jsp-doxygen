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
 *  @(#) $Id: cpu_unrename.h,v 1.4 2005/07/06 03:10:29 honda Exp $
 */

/* This file is generated from cpu_rename.def by genrename. */

#ifdef _CPU_UNRENAME_H_
#undef _CPU_UNRENAME_H_

#ifndef OMIT_RENAME

#undef activate_r
#undef ret_int
#undef ret_exc
#undef NotifyDialogProc
#undef InitializeComSupportModule
#undef FinalizeComSupportModule
#undef idispatch
#undef FatalAssertion
#undef CurrentInterruptLevel
#undef InterruptLevel
#undef ExceptionLevel
#undef AnotherExceptionFilter
#undef SystemMutex
#undef SystemMutexOwnerThreadID
#undef SystemMutexLastOwnerThreadID
#undef enter_system_critical_section
#undef leave_system_critiacl_section
#undef wait_for_thread_suspension_completion
#undef isns_int
#undef InterruptHandlerWrapper
#undef def_int
#undef ini_int
#undef fin_int
#undef ras_int
#undef sns_int
#undef sch_int
#undef LockerThreadID
#undef HALExceptionHandler
#undef ini_exc
#undef fin_exc
#undef DebugOutDialogProc
#undef InitializeDebugServices
#undef FinalizeDebugServices
#undef decode_waitstatus
#undef decode_taskstatus
#undef ProcessInstance
#undef PrimaryThreadHandle
#undef PrimaryDialogHandle
#undef CurrentRunningThreadHandle
#undef ShutdownPostponementRequest
#undef WorkerThreadHandle
#undef DestructionProcedureQueue
#undef KernelStarter
#undef TaskExceptionPerformer
#undef ForceShutdownHandler
#undef PrimaryDialogCommandHandler
#undef HALMessageHandler
#undef PrimaryDialogProc

#ifdef LABEL_ASM

#undef _activate_r
#undef _ret_int
#undef _ret_exc
#undef _NotifyDialogProc
#undef _InitializeComSupportModule
#undef _FinalizeComSupportModule
#undef _idispatch
#undef _FatalAssertion
#undef _CurrentInterruptLevel
#undef _InterruptLevel
#undef _ExceptionLevel
#undef _AnotherExceptionFilter
#undef _SystemMutex
#undef _SystemMutexOwnerThreadID
#undef _SystemMutexLastOwnerThreadID
#undef _enter_system_critical_section
#undef _leave_system_critiacl_section
#undef _wait_for_thread_suspension_completion
#undef _isns_int
#undef _InterruptHandlerWrapper
#undef _def_int
#undef _ini_int
#undef _fin_int
#undef _ras_int
#undef _sns_int
#undef _sch_int
#undef _LockerThreadID
#undef _HALExceptionHandler
#undef _ini_exc
#undef _fin_exc
#undef _DebugOutDialogProc
#undef _InitializeDebugServices
#undef _FinalizeDebugServices
#undef _decode_waitstatus
#undef _decode_taskstatus
#undef _ProcessInstance
#undef _PrimaryThreadHandle
#undef _PrimaryDialogHandle
#undef _CurrentRunningThreadHandle
#undef _ShutdownPostponementRequest
#undef _WorkerThreadHandle
#undef _DestructionProcedureQueue
#undef _KernelStarter
#undef _TaskExceptionPerformer
#undef _ForceShutdownHandler
#undef _PrimaryDialogCommandHandler
#undef _HALMessageHandler
#undef _PrimaryDialogProc

#endif /* LABEL_ASM */
#endif /* OMIT_RENAME */
#endif /* _CPU_UNRENAME_H_ */
