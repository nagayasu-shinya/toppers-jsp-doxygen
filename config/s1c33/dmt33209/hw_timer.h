/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include "s_services.h"

/*
 *  �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define INHNO_TIMER		S1C33_INHNO_P16TIMER1B

#define S1C33_P16TIMER_CLOCK	40000000

#ifndef _MACRO_ONLY
/*
 *  �����ؿ��λ���
 */
extern	ER	ena_int(INHNO);
extern	ER	dis_int(INHNO);

/*
 *  16�ӥåȥ�����1�ν����
 */
Inline void
hw_timer_initialize(void)
{
	/*
	 *  16�ӥåȥ�����1B ����߶ػ�
	 */
	dis_int(INHNO_TIMER);

	/*
	 *  16�ӥåȥ�����1B ������װ����ꥢ
	 */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntFactor[2] |= 0x40;

	/*
	 *  16bit������1����
	 *
	 *  �����ޥ���å�ON  16ʬ��  16�ӥåȥ�����1B ���� 1ms
	 */
	(*(s1c33TimerControl_t *) S1C33_TIMER_CONTROL_BASE).bP16ClkCtrl[1]
		= 0x0b;
	(*(s1c33P16Timer_t *) S1C33_P16TIMER_BASE).stChannel[1].uwComp[1]
		= ((S1C33_P16TIMER_CLOCK * 1) / (16 * 1000));

	/*
	 *  16�ӥåȥ����ޥꥻ�å�
	 */
	(*(s1c33P16Timer_t *) S1C33_P16TIMER_BASE).stChannel[1].bControl = 0x02;

	/*
	 *  16�ӥåȥ�����1B ����ߵ���
	 */
	ena_int(INHNO_TIMER);


	/*
	 *  16�ӥåȥ�����1 ư���
	 */
	(*(s1c33P16Timer_t *) S1C33_P16TIMER_BASE).stChannel[1].bControl = 0x01;

	return;
}

/*
 *  16�ӥåȥ�����1������װ��Υ��ꥢ
 */
Inline void
hw_timer_int_clear(void)
{
	/*
	 *  16�ӥåȥ�����1B ������װ����ꥢ
	 */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntFactor[2] |= 0x40;

	return;
}

/*
 *  16�ӥåȥ�����1�����
 */
Inline void
hw_timer_terminate(void)
{
	/*
	 *  16�ӥåȥ�����1B ����߶ػ�
	 */
	dis_int(INHNO_TIMER);

	/*
	 *  16�ӥåȥ�����1���
	 */
	(*(s1c33P16Timer_t *) S1C33_P16TIMER_BASE).stChannel[1].bControl = 0x00;

	return;
}

#endif /* _MACRO_ONLY  */
#endif /* _HW_TIMER_H_ */
