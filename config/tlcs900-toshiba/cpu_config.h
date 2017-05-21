/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2010 by Witz Corporation, JAPAN
 * 
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 * 
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 * 
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 * 
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 * 
 *    (a) The above copyright notice, this use conditions, and the
 *           disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 * 
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 * 
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�
 *  �����ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭�����
 *      ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ�����
 *      ��������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ����Ѽԥ�
 *      �˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ�����̵��
 *      �ڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ���
 *        �𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»��
 *      ����⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ��ޤ���
 *      �ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���ͳ�˴��
 *      �����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ���
 *  ��TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū���Ф�
 *  ��Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ�����������
 *  �ˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ����
 *  ��ʤ���
 * 
 *  @(#) $Id: cpu_config.h,v 1.1 2006/04/10 08:19:25 honda Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���TLCS-900L1�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include <cpu_rename.h>

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif /* _MACRO_ONLY */

/*
 *  chg_ipm/get_ipm �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define	SUPPORT_CHG_IPM

/*
 *  TCB ��Υե�����ɤΥӥå��������
 *
 *  cpu_context.h ��������������쥬��Ȥ��������Ȥΰ�¸���δط��ǡ�
 *  cpu_context.h �ˤ�������ʤ���
 */
#define	TBIT_TCB_TSTAT		8	/* tstat �ե�����ɤΥӥå��� */
#define	TBIT_TCB_PRIORITY	4	/* priority �ե�����ɤΥӥå��� */

#ifndef _MACRO_ONLY
/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	VP	xsp;		/* �����å��ݥ��� */
	FP	pc;		/* �ץ���५���� */
} CTXB;

/* 
 *  �����/CPU�㳰�ͥ��ȥ�����
 */
extern UINT	intcnt;

/*
 *  ����ߥޥ������饤�֥��
 *
 *  ����ߥޥ�����intmask�ˤϡ�IPM��Interrupt Priority Mask�ˤ�12�ӥå�
 *  ���˥��եȤ�����ΤǤ��롥
 */

/*
 *  ���ߤγ���ߥޥ������ɽФ�
 */
#pragma inline current_intmask
UH
current_intmask()
{
	return(current_sr() & 0x7000);
}

/*
 *  ����ߥޥ���������
 */
#pragma inline set_intmask
void
set_intmask(UH intmask)
{
	set_sr((current_sr() & ~0x7000) | intmask);
}

/*
 *  �����ƥ���ֻ���
 */

#pragma inline sense_context
BOOL
sense_context()
{
	Asm("	ldc	hl, intnest");
	return __HL;
}

#pragma inline sense_lock
BOOL
sense_lock()
{
	return(current_intmask() == 0x7000);
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU��å��Ȥ��β���ʥ���������ƥ������ѡ�
 *
 *  task_intmask �ϡ�chg_ipm �򥵥ݡ��Ȥ��뤿����ѿ���chg_ipm �򥵥ݡ�
 *  �Ȥ��ʤ����ˤϡ�task_intmask ����� 0 �ˤʤäƤ���ȹͤ���Ф褤��
 */

#ifdef SUPPORT_CHG_IPM
extern UH	task_intmask;	/* ����������ƥ����ȤǤγ���ߥޥ��� */
#endif /* SUPPORT_CHG_IPM */

#pragma inline t_lock_cpu
void
t_lock_cpu()
{
	disint();
}

#pragma inline t_unlock_cpu
void
t_unlock_cpu()
{
#ifdef SUPPORT_CHG_IPM
	/*
	 *  t_unlock_cpu ���ƤӽФ����Τ� CPU��å����֤ΤߤǤ��뤿
	 *  �ᡤ����������� task_intmask ���񤭴���뤳�ȤϤʤ���
	 */
	set_intmask(task_intmask);
#else /* SUPPORT_CHG_IPM */
	enaint();
#endif /* SUPPORT_CHG_IPM */
}

/*
 *  CPU��å��Ȥ��β�����󥿥�������ƥ������ѡ�
 */

extern UH	int_intmask;	/* �󥿥�������ƥ����ȤǤγ���ߥޥ��� */

#pragma inline i_lock_cpu
void
i_lock_cpu()
{
	UH	intmask;

	/*
	 *  ����ѿ� intmask ��ȤäƤ���Τϡ�current_intmask() ���
	 *  ���ľ��˳���ߤ�ȯ��������ư���줿����ߥϥ�ɥ����
	 *  int_intmask ���ѹ�������ǽ�������뤿��Ǥ��롥
	 */
	intmask = current_intmask();
	disint();
	int_intmask = intmask;
}

#pragma inline i_unlock_cpu
void
i_unlock_cpu()
{
	set_intmask(int_intmask);
}

/*
 *  �������ǥ����ѥå���
 */

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���cpu_support.asm��
 *
 *  dispatch �ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ����������
 *  ��ǡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	dispatch(void);

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���cpu_support.asm��
 *
 *  exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	exit_and_dispatch(void);

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ������
 */

/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 *  ����ߥϥ�ɥ����Ͽ����٥����ơ��֥��ROM��˼��,
 *  �����˽񤭹���. ���Τ��ᤳ���Ǥϲ��⤷�ʤ���
 */

#pragma inline define_inh
void
define_inh(INHNO inhno, FP inthdr)
{
}

/*
 *  CPU�㳰�ϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� excno ��CPU�㳰�ϥ�ɥ�ε�ư���Ϥ� exchdr �����ꤹ�롥
 *  ����ߥϥ�ɥ����Ͽ����٥����ơ��֥��ROM��˼��,
 *  �����˽񤭹���. ���Τ��ᤳ���Ǥϲ��⤷�ʤ���
 */
#pragma inline define_exc
void
define_exc(EXCNO excno, FP exchdr)
{
}


/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ�ν���������
 */

/*
 *  ����ߥϥ�ɥ�����������������ޥ���
 *
 *  �����ȯ�����Υ����å����ڤ��ؤ��򥽥եȥ������Ǽ¸����롥���Τ��ᡤ
 *  ����ߥϥ�ɥ�������ˤƳ���߶ػ߽�����Ԥ����ʤ��������ȯ������
 *  ����߶ػߤ�Ԥ��ޤǤδ֤�¿�ų���ߤ�ȯ������ȡ�¿�ų���ߤǤ���
 *  ���Ȥ򥽥եȥ������Ǹ��ΤǤ��ʤ����ᡤ�ǽ��ȯ����������߽������
 *  �Ԥ��ʤ��ޤޥ������ǥ����ѥå������ǽ�������롥����¿�ų���ߤ�
 *  �Τ��뤿��˥ϡ��ɥ����� INTNEST �쥸���������Ѥ��롥
 *
 *  TLCS-900 Family C Compiler �Ǥ� XIZ �쥸�����ʳ������ƥ�����å���
 *  �������Ǥ��롥�ʤ�������������ǻ��Ѥ��륹����å��쥸�����Τߤ�
 *  �����ݻ������Ĥ�ϳ���߶��̽������ݻ����롥
 *
 *  ��������������ϡ�����CPU�㳰�ϥ�ɥ��������������ޥ����Ʊ�ͤ�
 *  �������뤳�ȡ�
 */
#define	INTHDR_ENTRY(inthdr) \
extern void _kernel_interrupt(void); \
extern void inthdr##(void); \
void inthdr##_entry(void) \
{ \
Asm("	push	xwa	");	/* ���Ѥ��륹����å��쥸��������¸ */ \
Asm("	push	sr");	/* �����ȯ������IFF�����	*/ \
Asm("	pop		wa"); \
Asm("	ei		7");	/* ����߶ػ�	*/ \
Asm("	push	xhl	");	/* ���Ѥ��륹����å��쥸��������¸ */ \
Asm("	ld		xhl, _" #inthdr );	/* �桼���ϥ�ɥ�ݥ��󥿤����	*/ \
Asm("	jp	__kernel_interrupt"	);	/* ����߶��̽�����	*/ \
}
/*
 *  �嵭����������ϡ�����CPU�㳰�ϥ�ɥ��������������ޥ����Ʊ�ͤ�
 *  �������뤳�ȡ�
 */


#define	INT_ENTRY(inthdr)	inthdr##_entry

/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 *
 *  CPU�㳰�ϥ�ɥ�ϡ��󥿥�������ƥ����ȤǼ¹Ԥ��롥
 *  CPU�㳰�ϥ�ɥ�ϡ�����ߥϥ�ɥ��Ʊ�������Ȥ��롥
 *  �ʤ����㳰�ϥ�ɥ�ΰ��������ۤʤ뤿�ᡤƱ�������Υޥ��������
 *  �������롥
 *
 *  ��������������ϡ���γ���ߥϥ�ɥ��������������ޥ����Ʊ�ͤ�
 *  �������뤳�ȡ�
 */

#define	EXCHDR_ENTRY(exchdr) \
extern void _kernel_interrupt(void); \
extern void exchdr##(VP p_excinf); \
void exchdr##_entry(void) \
{ \
Asm("	push	xwa	");	/* ���Ѥ��륹����å��쥸��������¸ */ \
Asm("	push	sr");	/* �����ȯ������IFF�����	*/ \
Asm("	pop		wa"); \
Asm("	ei		7");	/* ����߶ػ�	*/ \
Asm("	push	xhl	");	/* ���Ѥ��륹����å��쥸��������¸ */ \
Asm("	ld		xhl, _" #exchdr );	/* �桼���ϥ�ɥ�ݥ��󥿤����	*/ \
Asm("	jp	__kernel_interrupt"	);	/* ����߶��̽�����	*/ \
}
/*
 *  ��������������ϡ���γ���ߥϥ�ɥ��������������ޥ����Ʊ�ͤ�
 *  �������뤳�ȡ�
 */

#define	EXC_ENTRY(exchdr)	exchdr##_entry


/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥλ���
 */
#pragma inline exc_sense_context
BOOL
exc_sense_context(VP p_excinf)
{
	Asm("	ldc	hl, intnest");
	return ( __HL > 1 );
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
#pragma inline exc_sense_lock
BOOL
exc_sense_lock(VP p_excinf)
{
	return ((*((UH *) p_excinf) & 0x7000) == 0x7000);
}

/*
 *  �ץ��å���¸�ν����
 */
extern void	cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void	cpu_terminate(void);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
