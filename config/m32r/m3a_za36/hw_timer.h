/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 * 32 (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
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
 *  @(#) $Id: hw_timer.h,v 1.2 2007/05/28 02:03:55 honda Exp $
 */

/*
 *  �������åȰ�¸�����ޥ⥸�塼���M32R ��¢������(MFT0)�ѡ�
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <sys_config.h>

#define WAIT __asm("nop;nop;nop;nop");

/*
 *  �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */

#define	INHNO_TIMER 20 //INT_MFT0(16) + TIMER_PORT(4) 

#ifndef _MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef UW	CLOCK;

/*                                                                             
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�                               
 */
#define TO_CLOCK(nume, deno)  	(TIMER_CLKCNT * (nume) / (deno))
#define TO_USEC(clock)      	((TO_CLOCK(TIC_NUME, TIC_DENO) - (clock)) * 1000 / TIMER_CLKCNT)

/*
 *  ��ǽɾ���ѥ����ƥ�������Ф��ݤν������֤θ��Ѥ��͡�ñ�̤�����ɽ����
 */
#define GET_TOLERANCE			100
#define BEFORE_IREQ(clock)    	((clock) <= GET_TOLERANCE)

/*
 *  �����ޤν����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize()
{
	/* �����޽���� */
	*(volatile unsigned short *)(ICUCR(MFT,TIMER_PORT)+2) = 0x1000;
	*(volatile unsigned short *)(MFTMOD(TIMER_PORT)+2) = 0x8001;
	*(volatile unsigned short *)(MFTCUT(TIMER_PORT)+2) = TIMER_CLKCNT;
	*(volatile unsigned short *)(MFTCR+2) = 0x8080 >> TIMER_PORT;
}

/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{	
	*(volatile unsigned char *)(ICUCR(MFT,TIMER_PORT)+2) = 0x10;	
}

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ��롥
 */
Inline void
hw_timer_terminate()
{	
	*(volatile unsigned char *)(ICUCR(MFT,TIMER_PORT)+2) = 0x0;	
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return *(volatile unsigned short *)(MFTCUT(TIMER_PORT)+2); 
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return *(volatile unsigned char *)(ICUCR(MFT,TIMER_PORT)+2) & 0x1;
}

#endif /* _MACRO_ONLY */

#endif /* _HW_TIMER_H_ */
