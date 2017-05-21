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
 *  @(#) $Id: cpu_config.h,v 1.15 2003/12/15 07:19:22 takayuki Exp $
 */


/*
 *	�ץ��å���¸�⥸�塼���Windows�ѡ�
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  Windows-HAL�ȼ��Υ��󥯥롼�ɥե�����
 */


/*
 *  Windows-HAL�ȼ������
 */

#define FPU_CONTEXTSIZE 108     /* ��ư��������˥åȤ����򤹤륳��ƥ����Ȥ��礭�� */

/*
 *  chg_ims/ref_ims �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define	SUPPORT_CHG_IMS

/*
 *  TCB ��Ϣ�����
 *
 *  cpu_context.h ��������������쥬��Ȥ��������Ȥΰ�¸���δط��ǡ�
 *  cpu_context.h �ˤ�������ʤ���
 */

/*
 *  TCB ��Υե�����ɤΥӥå��������
 */
#define	TBIT_TCB_PRIORITY	8	/* priority �ե�����ɤΥӥå��� */
#define	TBIT_TCB_TSTAT		8	/* tstat �ե�����ɤΥӥå��� */


#ifndef _MACRO_ONLY

#include <s_services.h>

/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	HANDLE	        ThreadHandle;		//�������˳�����Ƥ�줿����åɤΥϥ�ɥ�
	DWORD		    ThreadID;			//�������˳�����Ƥ�줿����åɤ�ID
	unsigned int    InterruptLevel;		//���Υ�������ư���Ƥ���Ȥ��γ���ߥޥ�����٥�
} CTXB;

/*
 * CPU���֥ե饰
 */
#define CPU_STAT_LOCK			0x01		//CPU��å����֤Ǥ�
#define CPU_STAT_EXC			0x02		//�㳰������Ǥ�
#define CPU_STAT_DOUBLEFAULT	0x04		//���֥�ե���Ȥ������äƤޤ�

extern volatile char CPUStatus;

/*
 *   CPU�㳰�ϥ�ɥ�
 */

/*#define EXCHNO_ZDIV  EXCEPTION_INT_DIVIDE_BY_ZERO */

/*
 *  �����ƥ���ֻ���
 */

Inline BOOL
sense_context()
{
		/* ����������ĤǤʤ�����󥿥�������ƥ����ȤǤ� */
	return (CurrentInterruptLevel != 0) ? TRUE : FALSE;
}

Inline BOOL
sense_lock()
{
		/* �㳰������ or ��å����֥ե饰��Ω�äƤ���� CPU��å����֤Ǥ� */
	return (CPUStatus & (CPU_STAT_LOCK|CPU_STAT_EXC)) != 0 ? TRUE : FALSE;
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU��å��Ȥ��β���ʥ���������ƥ������ѡ�
 *
 *  task_intmask �ϡ�chg_ipm �򥵥ݡ��Ȥ��뤿����ѿ���chg_ipm �򥵥ݡ�
 *  �Ȥ��ʤ����ˤϡ�task_intmask ����� 0 �ˤʤäƤ���ȹͤ���Ф褤��
 */

#include "debugout.h"
#include "device.h"

unsigned long task_intmask;

Inline void
i_lock_cpu()
{   dis_int(0);   }

Inline void
i_unlock_cpu()
{	ena_int(0);   }

#define t_lock_cpu	i_lock_cpu
#define t_unlock_cpu	i_unlock_cpu

/*
 *  �������ǥ����ѥå���
 */

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå�
 *
 *  dispatch �ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ����������
 *  ��ǡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	dispatch();
extern void idispatch();

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå�
 *
 *  exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */

extern void    exit_and_dispatch(void);

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ������
 */


/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 */

Inline void
define_inh(INHNO inhno, FP inthdr)
{	def_int((unsigned int)inhno,(void *)inthdr);   }

/*
 *  CPU�㳰�ϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� excno ��CPU�㳰�ϥ�ɥ�ε�ư���Ϥ� exchdr �����ꤹ�롥
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{	def_exc( (DWORD)excno, (void *)exchdr);   }

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ�ν���������
 */

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *
 *  ���Ƥγ����ߥϥ�ɥ�ϥǥ����ѥå����ư����SIGUSR1��ޥ�������
 *  ư��롣
 *  reqflg ������å��������˳���ߤ�ػߤ��ʤ��ȡ�reqflg ������å���
 *  �˵�ư���줿����ߥϥ�ɥ���ǥǥ����ѥå����׵ᤵ�줿���ˡ��ǥ�
 *  ���ѥå�����ʤ���
 */

	/* Windows-HAL�ˤ����Ƥ��ν����ϳ���ߥ��ߥ�졼���˰�Ǥ���Ƥ��� */

#define INT_ENTRY(hdr) hdr
#define INTHDR_ENTRY(inthdr) extern void inthdr(void)

/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 *
 *  CPU�㳰�ϥ�ɥ�ϡ��󥿥�������ƥ����ȤǼ¹Ԥ��롥���Τ��ᡤCPU��
 *  ���ϥ�ɥ��ƤӽФ����˳���ߥ⡼�ɤ˰ܹԤ����꥿���󤷤Ƥ������
 *  ���Υ⡼�ɤ��᤹�����Υ⡼�ɤ��᤹����ˡ�����ߥ⡼�ɤ˰ܹԤ�����
 *  �� SR �����ߥ����å������¸���롥CPU�㳰������������ƥ����Ȥ�
 *  ȯ������reqflg �� TRUE �ˤʤä����ˡ�ret_exc ��ʬ�����롥
 *  reqflg ������å��������˳���ߤ�ػߤ��ʤ��ȡ�reqflg ������å���
 *  �˵�ư���줿����ߥϥ�ɥ���ǥǥ����ѥå����׵ᤵ�줿���ˡ��ǥ�
 *  ���ѥå�����ʤ���
 */

#define EXC_ENTRY(hdr) hdr
#define EXCHDR_ENTRY(inthdr) extern void inthdr(void)

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */

/*
 *  CPU�㳰��ȯ���������Υǥ����ѥå�
 *
 *   WindowsHAL�����ѥե饰����äƤ����ǡ���������ξ���Ϥ��Τޤ�
 *   ��Ǽ����Ƥ��롣
 */
#define exc_sense_context sense_context

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
#define exc_sense_lock sense_lock

/*
 *  �ץ��å���¸�ν����
 */
extern void	cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void	cpu_terminate(void);

/*
 *  atexit����Ͽ���줿�ؿ����ɽФ� (Windows�ϲ��⤷�ʤ� -> CRT��Ǥ����)
 */
extern void	call_atexit(void);

/*
 *   Windows Dedicated Routines 
 */
extern LONG WINAPI HALExceptionHandler( EXCEPTION_POINTERS * exc );

/*
 *   ��̿Ū�ʼ��Ԥ��Ф����н�롼����
 */
extern void FatalAssertion(int exp, LPCSTR format, ... );


/*
 *   ���ν�������롼����
 */
extern void set_logcontrol(BOOL enable);

/*
 *   �����ͥ�ǥХå���printf
 */

#ifdef KERNEL_DEBUG_MODE
#  define kprintf(x) _kernel_debugprintf x
#else
#  define kprintf(x)
#endif

extern void _kernel_debugprintf(const char * format, ... );

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
