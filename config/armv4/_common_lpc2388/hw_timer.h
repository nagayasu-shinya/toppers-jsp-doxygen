/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by  Advanced Data Controls, Corp
 *                2009 by Suikan
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
 */

/*
 *  CPU��¸�����ޥ⥸�塼���CQ-FRK-NXP-ARM�ѡ�
 *  TIMER3�����
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include "lpc2388.h"




/*
 *  �����޳���ߤγ�����ֹ�
 */
#define    INHNO_TIMER    INHNO_TIMER3

#ifndef _MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef UW    CLOCK;

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *  TIMER_CLOCK �ϥ������åȥܡ����������
 */
#define TO_CLOCK(nume, deno) (LP2388_SYSTEM_TIMER3_CLOCK/1000 * (nume) / (deno))
#define TO_USEC(clock)       ((clock) * 1000 / TIMER_CLOCK)

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define MAX_CLOCK    ((CLOCK) 0xffffffff)
/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define GET_TOLERANCE    100
#define BEFORE_IREQ(clock) \
        ((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �����ޤε�ư����
 *
 * �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥�����ޡ�3�ȥޥå��쥸����0��Ȥ���
 * ��������������PCLK (Hz)�򥯥�å����ϤȤ��ƻȤ���
 */
Inline void
hw_timer_initialize()
{

    /*
     *  �����޴�Ϣ������
     */
    		/* ��������ߤ���ӥꥻ�å� */
    T3TCR = 0x0002;
    		/* ����ߤΥ��ꥢ  */
    T3IR =  0x0001;				/* MR0�����ߤΥ��ꥢ */

	T3CTCR = 0;			/* PCLK�Υ��å�������롣����ץ������Ϥ�̵�� */
	T3PR = 0;			/* PCLK�Υ��å��򤹤٤ƿ����롣�ץꥹ������ʤ� */
    T3MR3 = (LP2388_SYSTEM_TIMER3_CLOCK/1000) -1;		/* 1mS���Ȥ˥ޥå������� */
	T3MCR = 0x3 << 9;	/* MR3S:R:I = 0:1:1���ޥå������饫���󥿤�ꥻ�åȤ��������ߤ򤫤��� */

	T3TCR = 1;			/* TIMER3�򥫥���ȳ��Ϥˤ��� */

		/* �����ޡ������ߤ�ͭ���ˤ��� */
	VICIntEnable = 1<< INHNO_TIMER;
}

/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{
    		/* ����ߤΥ��ꥢ  */
	T3IR = 1<<3;			/* MR3�ޥå��γ����ߤ򥯥ꥢ���� */
}

/*
 *  �����ޤ���߽���
 */
Inline void
hw_timer_terminate()
{
    		/* ��������ߤ���ӥꥻ�å� */
    T3TCR = 0x0002;
    		/* ����ߤΥ��ꥢ  */
    T3IR =  0x0001;				/* MR0�����ߤΥ��ꥢ */
}

/*
 *  �����ޤθ����ͤ��ɤߤ���
 *
 *  ����߶ػ߶����ǸƤӽФ����ȡ�
 */
Inline CLOCK
hw_timer_get_current(void)
{
    return(T3TC);
}

Inline BOOL
hw_timer_fetch_interrupt(void)
{
    return(T3IR & (1<<3));		/* MR3 ���ޥå����Ƥ����鿿 */
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */



