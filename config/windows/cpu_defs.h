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
 *  @(#) $Id: cpu_defs.h,v 1.11 2003/12/15 07:19:22 takayuki Exp $
 */


/*
 *	�ץ��å��˰�¸���������Windows�ѡ�
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define OMIT_SIL_ACCESS

#define WINDOWS

#define INT_NUMINTERRUPTS	7	/* ������ܿ� */

#ifndef _MACRO_ONLY

#include <itron.h>
#include <vwindows.h>

typedef	UINT		INHNO;		/* ����ߥϥ�ɥ��ֹ� */
typedef	UINT		EXCNO;		/* CPU�㳰�ϥ�ɥ��ֹ� */

/*
 * ����ߥ��ߥ�졼������Ϣ
 */

#define INT_STAT_MASK		0x0000ffffu
#define INT_STAT_PENDING	0x00000001u
#define INT_STAT_RUNNING	0x00000002u
#define INT_STAT_ENABLED	0x00000004u

#define INT_MOD_MASK		0xff000000u
#define INT_MOD_LOGMASK		0x01000000u

struct tagInterruptLevel
{
	HANDLE			ThreadHandle;
	DWORD			ThreadID;
	void *			Routine;
	unsigned int	Flags;
};

extern struct tagInterruptLevel InterruptLevel[INT_NUMINTERRUPTS];
extern unsigned int             CurrentInterruptLevel;

/*  �㳰��Ϣ����� */

#define EXC_MAXITEMS 32

struct tagExceptionLevel
{
	DWORD ExceptionCode;
	void * Routine;
};

extern struct tagExceptionLevel ExceptionLevel[EXC_MAXITEMS];

/*
 * ����ߥ��ߥ�졼����������ؿ�
 */

extern BOOL			def_int( unsigned int ims, void * rtn);	/* �ϥ�ɥ���� */
extern BOOL			ini_int( void );				/* ����� */
extern void			fin_int( void );
extern BOOL			ras_int(unsigned int ims);		/* ������׵� */
extern unsigned int sns_int( void );				/* Sense the highest pending request */
extern HANDLE		sch_int( void );				/* �����ߤΥ������塼�� */

extern BOOL			set_intlogmask( unsigned int ims, BOOL mask );

 /* ���Ĥȶػߤϰ����˴ط��ʤ�������&���ػߤȤʤ� */
extern ER	ena_int(unsigned int ims);			/* ���� */
extern ER	dis_int(unsigned int ims);			/* �ػ� */

extern ER	chg_ims(unsigned int ims);			/* ����ߥ�٥������ */
extern ER	get_ims(unsigned int *p_ims);		/* ����ߥ�٥�μ��� */
extern ER	vget_ims(unsigned int *p_ims);		/* ����ߥ�٥�μ��� */

extern BOOL def_exc(DWORD exc, void * routine);
extern BOOL ini_exc(void);
extern void fin_exc(void);

	/*
	 * �����ƥ९��ƥ����륻�������
	 *   ���¾��CPU��å��ǡ����������äƤ���֥ǥ����ѥå���ȯ�����ʤ�
	 */
extern void enter_system_critical_section(BOOL *);
extern void leave_system_critiacl_section(BOOL *);

	/* ���ꤵ�줿�������򥷥��ƥ९��ƥ����륻������󳰤���ߤ����� */
extern ER   wait_for_thread_suspension_completion(HANDLE thread);

    /* ���ߥ�졼����󥿥������� */
extern unsigned int current_timer_clock_unit;

    /* ���ߥ�졼��������Υƥ��å���������
     *   clk : ���Υ����޳������˲ä��륷�ߥ�졼��������
     *     (clk = 0 : �������� (TIMER_CLOCK_WINDOWS))
     */
extern ER set_clk(unsigned int clk);

#endif /* _MACRO_ONLY */

/*
 * �����ޡ���Ϣ
 */

#include <hw_timer.h>

/*
 *  ������ƥ��å������
 */
#define	TIC_NUME	current_timer_clock_unit	/* ������ƥ��å��μ�����ʬ�� */
#define	TIC_DENO	1						    /* ������ƥ��å��μ�����ʬ�� */

#ifndef _MACRO_ONLY

/*
 * ��ĥ�����ޡ� (Pentium Timer)
 */

typedef UD SYSUTIM;

Inline ER
vxget_tim(SYSUTIM * pk_sysutim)
{
	QueryPerformanceCounter((LARGE_INTEGER *)pk_sysutim);
	return E_OK;
}

#endif /* _MACRO_ONLY */

#endif /* _CPU_DEFS_H_ */
