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
 *  @(#) $Id: cpu_rename.h,v 1.3 2003/07/01 13:49:51 takayuki Exp $
 */

/* This file is generated from cpu_rename.def by genrename. */

#ifndef _CPU_RENAME_H_
#define _CPU_RENAME_H_

#ifndef OMIT_RENAME

#define activate_r		_kernel_activate_r
#define ret_int			_kernel_ret_int
#define ret_exc			_kernel_ret_exc
#define NotifyDialogProc	_kernel_NotifyDialogProc
#define InitializeComSupportModule	_kernel_InitializeComSupportModule
#define FinalizeComSupportModule	_kernel_FinalizeComSupportModule
#define idispatch		_kernel_idispatch
#define FatalAssertion		_kernel_FatalAssertion
#define CurrentInterruptLevel	_kernel_CurrentInterruptLevel
#define InterruptLevel		_kernel_InterruptLevel
#define ExceptionLevel		_kernel_ExceptionLevel
#define AnotherExceptionFilter	_kernel_AnotherExceptionFilter
#define SystemMutex		_kernel_SystemMutex
#define SystemMutexOwnerThreadID	_kernel_SystemMutexOwnerThreadID
#define SystemMutexLastOwnerThreadID	_kernel_SystemMutexLastOwnerThreadID
#define enter_system_critical_section	_kernel_enter_system_critical_section
#define leave_system_critiacl_section	_kernel_leave_system_critiacl_section
#define wait_for_thread_suspension_completion	_kernel_wait_for_thread_suspension_completion
#define isns_int		_kernel_isns_int
#define InterruptHandlerWrapper	_kernel_InterruptHandlerWrapper
#define def_int			_kernel_def_int
#define ini_int			_kernel_ini_int
#define fin_int			_kernel_fin_int
#define ras_int			_kernel_ras_int
#define sns_int			_kernel_sns_int
#define sch_int			_kernel_sch_int
#define LockerThreadID		_kernel_LockerThreadID
#define HALExceptionHandler	_kernel_HALExceptionHandler
#define ini_exc			_kernel_ini_exc
#define fin_exc			_kernel_fin_exc
#define DebugOutDialogProc	_kernel_DebugOutDialogProc
#define InitializeDebugServices	_kernel_InitializeDebugServices
#define FinalizeDebugServices	_kernel_FinalizeDebugServices
#define decode_waitstatus	_kernel_decode_waitstatus
#define decode_taskstatus	_kernel_decode_taskstatus
#define ProcessInstance		_kernel_ProcessInstance
#define PrimaryThreadHandle	_kernel_PrimaryThreadHandle
#define PrimaryDialogHandle	_kernel_PrimaryDialogHandle
#define CurrentRunningThreadHandle	_kernel_CurrentRunningThreadHandle
#define ShutdownPostponementRequest	_kernel_ShutdownPostponementRequest
#define WorkerThreadHandle	_kernel_WorkerThreadHandle
#define DestructionProcedureQueue	_kernel_DestructionProcedureQueue
#define KernelStarter		_kernel_KernelStarter
#define TaskExceptionPerformer	_kernel_TaskExceptionPerformer
#define ForceShutdownHandler	_kernel_ForceShutdownHandler
#define PrimaryDialogCommandHandler	_kernel_PrimaryDialogCommandHandler
#define HALMessageHandler	_kernel_HALMessageHandler
#define PrimaryDialogProc	_kernel_PrimaryDialogProc

#ifdef LABEL_ASM

#define _activate_r		__kernel_activate_r
#define _ret_int		__kernel_ret_int
#define _ret_exc		__kernel_ret_exc
#define _NotifyDialogProc	__kernel_NotifyDialogProc
#define _InitializeComSupportModule	__kernel_InitializeComSupportModule
#define _FinalizeComSupportModule	__kernel_FinalizeComSupportModule
#define _idispatch		__kernel_idispatch
#define _FatalAssertion		__kernel_FatalAssertion
#define _CurrentInterruptLevel	__kernel_CurrentInterruptLevel
#define _InterruptLevel		__kernel_InterruptLevel
#define _ExceptionLevel		__kernel_ExceptionLevel
#define _AnotherExceptionFilter	__kernel_AnotherExceptionFilter
#define _SystemMutex		__kernel_SystemMutex
#define _SystemMutexOwnerThreadID	__kernel_SystemMutexOwnerThreadID
#define _SystemMutexLastOwnerThreadID	__kernel_SystemMutexLastOwnerThreadID
#define _enter_system_critical_section	__kernel_enter_system_critical_section
#define _leave_system_critiacl_section	__kernel_leave_system_critiacl_section
#define _wait_for_thread_suspension_completion	__kernel_wait_for_thread_suspension_completion
#define _isns_int		__kernel_isns_int
#define _InterruptHandlerWrapper	__kernel_InterruptHandlerWrapper
#define _def_int		__kernel_def_int
#define _ini_int		__kernel_ini_int
#define _fin_int		__kernel_fin_int
#define _ras_int		__kernel_ras_int
#define _sns_int		__kernel_sns_int
#define _sch_int		__kernel_sch_int
#define _LockerThreadID		__kernel_LockerThreadID
#define _HALExceptionHandler	__kernel_HALExceptionHandler
#define _ini_exc		__kernel_ini_exc
#define _fin_exc		__kernel_fin_exc
#define _DebugOutDialogProc	__kernel_DebugOutDialogProc
#define _InitializeDebugServices	__kernel_InitializeDebugServices
#define _FinalizeDebugServices	__kernel_FinalizeDebugServices
#define _decode_waitstatus	__kernel_decode_waitstatus
#define _decode_taskstatus	__kernel_decode_taskstatus
#define _ProcessInstance	__kernel_ProcessInstance
#define _PrimaryThreadHandle	__kernel_PrimaryThreadHandle
#define _PrimaryDialogHandle	__kernel_PrimaryDialogHandle
#define _CurrentRunningThreadHandle	__kernel_CurrentRunningThreadHandle
#define _ShutdownPostponementRequest	__kernel_ShutdownPostponementRequest
#define _WorkerThreadHandle	__kernel_WorkerThreadHandle
#define _DestructionProcedureQueue	__kernel_DestructionProcedureQueue
#define _KernelStarter		__kernel_KernelStarter
#define _TaskExceptionPerformer	__kernel_TaskExceptionPerformer
#define _ForceShutdownHandler	__kernel_ForceShutdownHandler
#define _PrimaryDialogCommandHandler	__kernel_PrimaryDialogCommandHandler
#define _HALMessageHandler	__kernel_HALMessageHandler
#define _PrimaryDialogProc	__kernel_PrimaryDialogProc

#endif /* LABEL_ASM */
#endif /* OMIT_RENAME */
#endif /* _CPU_RENAME_H_ */
