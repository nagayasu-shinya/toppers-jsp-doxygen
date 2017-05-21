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
 *  @(#) $Id: hw_timer.h,v 1.6 2003/12/04 08:25:44 honda Exp $
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include "c54x.h"

#define INHNO_TIMER TINT0_VEC

#ifndef _MACRO_ONLY

#define TO_CLOCK(nume,deno) (TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)       ((clock) * 1000 / TIMER_CLOCK)

#define MAX_CLOCK ((CLOCK) 0xffff)

#define GET_TOLERANCE 100

#define BEFORE_IREQ(clock) \
  ((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


typedef UH CLOCK;

Inline void
hw_timer_initialize()
{
	CLOCK	c = TO_CLOCK(TIC_NUME,TIC_DENO);

	/* 0.25 ��sec�ǥ�����Ȥ��� */
	sil_wrh_mem((VP) TMU0_TCR, TCR_TSS | 0x0009);
//	sil_wrh_mem((VP) TMU0_TCR, TCR_TSS | 0x0001);
	/* �����󥿤����� */
	sil_wrh_mem((VP) TMU0_PRD, c - 1);
	/* �����󥫥��󥿤ν�������� */
	sil_wrh_mem((VP) TMU0_TCR, (sil_reh_mem((VP) TMU0_TCR) | TCR_TRB));
	/* �����ޤε�ư */
	sil_wrh_mem((VP) TMU0_TCR, (sil_reh_mem((VP) TMU0_TCR) & ~TCR_TSS));

	sil_wrh_mem((VP) IFR, (sil_reh_mem((VP) IFR) | (0x1 << TINT0)));
	sil_wrh_mem((VP) IMR, (sil_reh_mem((VP) IMR) | (0x1 << TINT0)));
}

Inline void
hw_timer_int_clear()
{
}

Inline void
hw_timer_terminate()
{
	sil_wrh_mem((VP) TMU0_TCR, (sil_reh_mem((VP) TMU0_TCR) | TCR_TSS));
	sil_wrh_mem((VP) IMR, (sil_reh_mem((VP) IMR) & ~(0x1 << TINT0)));
	sil_wrh_mem((VP) IFR, (sil_reh_mem((VP) IFR) | (0x1 << TINT0)));
}

Inline CLOCK
hw_timer_get_current(void)
{
	return(TO_CLOCK(TIC_NUME,TIC_DENO) - sil_reh_mem((VP) TMU0_TIM));
}

Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return(sil_reh_mem((VP) IFR) & (0x1 << TINT0));
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
