/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RICOH COMPANY,LTD. JAPAN
 * 
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ��� 
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ����(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ�������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: hw_timer.h,v 1.5 2007/01/05 02:33:59 honda Exp $
 */

/*
 *	�����ޥɥ饤�С�OAKS16 MINI�ѡ�
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include <sil.h>
#include <oaks16mini.h>

/*
 *  �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define	INHNO_TIMER	       INT_TA0

/*
 *  �����ޡ��γ����ߥ�٥�
 */

#define INT_LEVEL_TIMER	0x05

#ifndef _MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef UH	CLOCK;

/*
 *  �������ͤ�����ɽ���ȥߥ���ñ�̤Ȥ��Ѵ�
 *
 *  1ms�Υ����ޡ������ߤ���Ѥ���ΤǤ��Υ���å���������롥
 */
#define TIMER_CLOCK		625
#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define	MAX_CLOCK	((CLOCK) 0xffff)

/*
 *  ��ǽɾ���ѥ����ƥ�������Ф��ݤν������֤θ��Ѥ��͡�ñ�̤�����ɽ����
 */
#define	GET_TOLERANCE	100	/* �����٤�θ��Ѥ��͡�ñ�̤�����ɽ����*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize(void)
{
		/* �����޽���� */
	sil_wrb_mem((VP)TADR_SFR_UDF, 0x00);		/* �����󥫥��������				*/
	sil_wrb_mem((VP)TADR_SFR_TA0MR, 0x80);		/* �����ޥ⡼��	����å���1/32		*/
	sil_wrh_mem((VP)TADR_SFR_TA0, TIMER_CLOCK-1);/* �������ͤν����				*/
												/* �����ߥ�٥������				*/
	set_ic_ilvl((VP)(TADR_SFR_INT_BASE+TADR_SFR_TA0IC_OFFSET), INT_LEVEL_TIMER);
												/* ������ȳ���						*/
	sil_wrb_mem((VP)TADR_SFR_TABSR, TBIT_TABSR_TA0S);
}

/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear(void)
{
}

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
Inline void
hw_timer_terminate(void)
{
	VB  c;

	c = sil_reb_mem((VP)TADR_SFR_TABSR);
	c &= ~TBIT_TABSR_TA0S;						/* ������Ƚ�λ						*/
	sil_wrb_mem((VP)TADR_SFR_TABSR, c);
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return (TIMER_CLOCK-1)-sil_reh_mem((VP)TADR_SFR_TA0);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return (sil_reb_mem((VP)(TADR_SFR_INT_BASE+TADR_SFR_TA0IC_OFFSET)) & TBIT_TAiIC_IR) != 0;
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
