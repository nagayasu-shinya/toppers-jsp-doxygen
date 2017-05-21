/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005 by Freelines CO.,Ltd 
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
 *  @(#) $Id: hw_timer.h,v 1.2 2007/01/05 02:10:17 honda Exp $
 */

/*
 *	�������åȰ�¸�����ޥ⥸�塼���V850ES/SG2��¢������P-ch0(TMP0)�ѡ�
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>

#ifndef _MACRO_ONLY

/* �����ƥॿ���ޡ���TMP0����� */
#define	TIMER_INT_PRIORITY		0		/* ������ͥ����(0���ǹ��7������) */
#define TIMER_CLKDIV			1		/* fx/2=10MHz */
#define	TIMER_COMPAREVALUE		(10000-1)	/* fx/2��1msec���� */

/*
 *  �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define	INHNO_TIMER	       (0x17)

/*
 *  �������ͤ�����ɽ���η�
 */
typedef UW	CLOCK;

#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)      ((clock) * 1000 / TIMER_CLOCK)

/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize(void)
{
	/* �����޽���� */
	sil_wrb_mem((VP)TP0CTL0, 1);		/* fx/2 (count stop) */
	sil_wrb_mem((VP)TP0CTL1, 0);		/* interval mode */
	sil_wrb_mem((VP)TP0IOC0, 1);		/* TOP00 clock out */
	sil_wrh_mem((VP)TP0CCR0, TIMER_COMPAREVALUE);
	sil_wrb_mem((VP)TP0CTL0, 0x81);		/* Count Start */

	/* ������׵�������Ĥġ�����ߵ��Ĥˤ��ơ�ͥ���٤����ꤹ�� */
	sil_wrb_mem((VP)TP0CCIC0, TIMER_INT_PRIORITY);
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
	/* ����ߤ�ޥ������� */
	sil_wrb_mem((VP)TP0CCIC0, sil_reb_mem((VP)TP0CCIC0) | 0x47);
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return sil_rew_mem((VP)TP0CNT);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return (sil_reb_mem((VP)TP0CCIC0) & 0x80) != 0;
}

#endif /* _MACRO_ONLY */

#endif /* _HW_TIMER_H_ */
