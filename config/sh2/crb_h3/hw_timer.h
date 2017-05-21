/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id$
 */

/*
 *  CPU��¸�����ޥ⥸�塼���SH7047�ѡ�
 *  CMT0�����
 *
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include "crb_h3.h"

/*
 *  ����ڥ��ޥå������ޥ������ȥ쥸����CMSTR�Υӥå�����
 */
#define CMSTR_STR1	0x0002	/* ������ȥ�������1 */
#define CMSTR_STR0  0x0001	/* ������ȥ�������0 */

/*
 *  ����ڥ��ޥå������ޥ���ȥ��롿���ơ������쥸����CMCSR�Υӥå�����
 */
#define CMCSR_CMF   0x0080	/* ����ڥ��ޥå��ե饰 */
#define CMCSR_CMIE  0x0040	/* ����ڥ��ޥå�����ߥ��͡��֥� */
#define CMCSR_CKS8  0x0000	/* 8ʬ������å����쥯�� */

/*
 *  �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define	INHNO_TIMER	CMI0

/*
 *   �����ޤ˶��뤵��륯��å����ȿ�[kHz]
 *   	40.000MHz/8 =5.0000MHz =5000.0kHz
 */
#define TIMER_CLOCK     (CLOCK_RATE/8000L)

#ifndef _MACRO_ONLY
/*
 *  �������ͤ�����ɽ���η�
 */
typedef UH CLOCK;

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *
 */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)
#define CLOCK_PER_TICK	((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define	MAX_CLOCK	((CLOCK) 0xffff)

/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define	GET_TOLERANCE	100		/* �����٤�θ��Ѥ��͡�ñ�̤�����ɽ���� */
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


/*  ����ߥ�٥������쥸��������������Ȥ��Υ��եȿ�  */
#define FRT_BIT_SHIFT	4

/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize()
{
	/* �����ޥǥХ������Τν���� */
	sil_wrh_mem((VP)IOREG_CMSTR_BASE, 0x0000);	/* �����ޥ��ȥå� */
												/* ������������ */
	sil_wrh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCOR_OFFSET), TO_CLOCK(TIC_NUME, TIC_DENO));

	/* �����ߥ�٥�����   */
	define_int_plevel ((VH*)(IOREG_INTC_BASE+IOREG_IPRG_OFFSET), TIMER_INTLVL, FRT_BIT_SHIFT);

	/*  �����������׵�򥯥ꥢ�ȥ���å����å� */
	sil_wrh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET), (CMCSR_CMIE|CMCSR_CKS8));
	sil_wrh_mem((VP)IOREG_CMSTR_BASE, CMSTR_STR0);	/* �����ޥ������� */
}

/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{
	sil_wrh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET),
		(sil_reh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET)) & ~CMCSR_CMF));
}

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
Inline void
hw_timer_terminate()
{
	sil_wrh_mem((VP)IOREG_CMSTR_BASE,			/* �����ޤ���� */
		(sil_reh_mem((VP)IOREG_CMSTR_BASE) & ~CMSTR_STR0));
	sil_wrh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET), CMCSR_CKS8);/* �������ߤ��װ��Υ��ꥢ */
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 *�����������ޤ�ư�����Ū����ߤ����������ͤ��ɤ߽Ф���
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return sil_reh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCNT_OFFSET));
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return ((sil_reh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET)) & CMCSR_CMIE) != 0);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
