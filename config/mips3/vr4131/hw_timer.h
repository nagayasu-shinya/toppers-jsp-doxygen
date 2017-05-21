/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

/*
 *   �����ޥɥ饤�С�VR4131��¢RTC��TClock�������ѡ�
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <vr4131_rtc.h>

/*
 *  �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define	INHNO_TIMER	INTNO_TCLK

#ifndef _MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef UH		CLOCK;

#endif /* _MACRO_ONLY */

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *  TIMER_CLOCK�ϡ��ܡ��ɴط��Υإå��ե�����˵��ܤ��Ƥ��롣
 */
/* 1�ߥ��ü���(isig_tim ��ƤӽФ�����;1kHz)��ȯ�������뤿��Υ�����ȿ� */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
/* clock �� usec ñ�̤��Ѵ�����ޥ��� */
#define	TO_USEC(clock)		((clock) * 1000u / TIMER_CLOCK)

/*
 *  �����޼�����ñ�̤�����ɽ�����Ѵ�
 *  (���Ѥ��륿���ޤ������󥫥��󥿤ʤΤǡ����Υޥ������������)
 */
#define CLOCK_PER_TICK		((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define MAX_CLOCK		((CLOCK) 0x1ffffff)	/*  25�ӥå�  */

/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define	GET_TOLERANCE		100u	/* �����٤�θ��Ѥ��͡�ñ�̤�����ɽ����*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  ��������ߤޤǤλ��֡�nsecñ�̡�
 *  �ͤ˺���Ϥʤ���
 */
#define	TIMER_STOP_DELAY	200u

#ifndef _MACRO_ONLY
/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void hw_timer_int_clear() {

	vr4131_wrh_mem( (VP) RTCINTREG, RTCINTR3 );
}

/*
 *  �����ޤε�ư����
 *    �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void hw_timer_initialize() {

	/*
	 *  �����޼��������ꤷ�������ޤ�ư��򳫻Ϥ��롥
	 */
	assert( CLOCK_PER_TICK <= MAX_CLOCK );

	vr4131_wrh_mem( (VP) TCLKLREG, (UH) LO16(CLOCK_PER_TICK) );
	vr4131_wrh_mem( (VP) TCLKHREG, (UH) HI16(CLOCK_PER_TICK) );

	/*
	 *  �����޳���ߤγ���ߥ�٥�����ꤷ���׵�򥯥ꥢ�����塤
	 *  �ޥ����������롥
	 */
	all_set_ilv( INHNO_TIMER, &((IPM) IPM_TIMER) );	/* ����ߥ�٥������ */

	hw_timer_int_clear();				/* ������׵�򥯥ꥢ */

	/* �ޥ����������(��٥룱����٥룲����������쥸������̵��) */
	vr4131_orh( (VP) MSYSINT2REG, TCLKINTR );
}

/*
 *  �����ޤ���߽���
 *  �����ޤ�ư�����ߤ����롥
 */
Inline void hw_timer_terminate() {

	/*  �����ޤ�ư�����ߤ���  */
	vr4131_wrh_mem( (VP) TCLKLREG, 0 );
	vr4131_wrh_mem( (VP) TCLKHREG, 0 );

	/*
	 *  �����޳���ߤ�ޥ��������׵�򥯥ꥢ���롥
	 */
	/* �ޥ����������(��٥룱����٥룲����������쥸������̵��) */
	vr4131_andh( (VP) MSYSINT2REG, ~TCLKINTR );

	hw_timer_int_clear();				/* ������׵�򥯥ꥢ */
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK hw_timer_get_current() {

	UH 	count;
	UH	hi1, lo1, hi2, lo2;

	/* �������ͤ��ɤ߽Ф� */
	/* 2���ɤ߽Ф��Ƥ�����ͳ�ϡ��ϡ��ɥ�������p261���� */
	lo1 = vr4131_reh_mem( (VP) TCLKCNTLREG );
	hi1 = vr4131_reh_mem( (VP) TCLKCNTHREG );

	lo2 = vr4131_reh_mem( (VP) TCLKCNTLREG );
	hi2 = vr4131_reh_mem( (VP) TCLKCNTHREG );

	if( hi2 == hi1 )
		count = JOIN16( hi1, lo1 );
	else
		count = JOIN16( hi2, lo2 );

	return (CLOCK_PER_TICK - count);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL hw_timer_fetch_interrupt() {

	return( ( vr4131_reh_mem( (VP) RTCINTREG ) & RTCINTR3 ) != 0);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
