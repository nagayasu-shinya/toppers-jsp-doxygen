/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003      by Advanced Data Controls, Corp
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *    �������åȥ����ƥ��¸�⥸�塼���CQ-FRK-NXP-ARM��
 */

#include "jsp_kernel.h"
#include <lpc2388.h>



/*
 * OSC�ν����(�����ƥ��ͭ). 4MHz �����������졼����Ȥ�
 */
static void
init_clock()
{
	/* 1. �⤷PLL����Ѥ��Ƥ���ʤ顢�ǥ������ͥ��Ȥ����ե����ɡ��������󥹤�Ƨ�� */
	PLLCON &= 0xFFFFFFFD;	/* Clear bit 1, PLL bypassed */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;

	/* 2. PLL��ǥ������֥뤷���ե����ɡ��������󥹤�Ƨ�ࡣ */
	PLLCON = 0;		/* Disable PLL */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;

	/* 3. CPU����å����ǥ��Х����������PLL�ʤ��Ǥ��٤��ʤꤹ���ʤ��褦�����ꤹ�롣 */
	CCLKCFG = 0;	/* CCLK = PCLK / 1 */

	/* 4. PLL�Υ���å����������ѹ����롣 */
	CLKSRCSEL = 0;	/* Select 4MHz internal oscillator*/
//	CLKSRCSEL = 1;	/* Select 12MHz main oscillator*/

	/* 5. PLLCFG�ؤν񤭹��ߤ�Ԥ����ե����ɡ��������󥹤�Ƨ���ͭ�������롣
	 * PLLCFG�ϡ�PLL���ǥ������֥�ΤȤ��ˤ����ѹ��Ǥ��롣 */
	PLLCFG = 35;	/* Divide by 1, Multiply by 72, PCLK = 4*72 = 288MHz */
//	PLLCFG = 11;	/* Divide by 1, Multiply by 24, PCLK = 12*24 = 288MHz */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;

	/* 6. PLL�򥤥͡��֥�ˤ����ե����ɡ��������󥹤�Ƨ��. */
	PLLCON = 1;		/* Enable PLL */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;

	/* 7. CPU����å����ǥ��Х������ͤ�PLLư���Ѥ��ѹ����롣
	 * �����ɬ����PLL�򥯥�å����Ȥ�����³�������˹Ԥ��� */
	CCLKCFG = 3;	/* CCLK = PCLK/4 = 288/4 = 72MHz */

	/* 8. PLLSTAT�쥸������PLOCK bit��Ĵ�٤ơ�PLL����å�����ޤ��Ԥġ�
	 * ���뤤��PLOCK�����ߤ���Ѥ��Ƥ⤤�������뤤�ϡ�PLL�����ϥ���å���������(32kHz�ʤ�)�ʤ顢
	 * ñ��˥������ȡ��롼�פ�󤷤Ƥ⤤����*/
	while ( !(PLLSTAT & (1<<26)))
		;

	/* 9. PLL�򥷥��ƥ����³�����ե����ɥ������󥹤�¹Ԥ��� */
	PLLCON = 3;		/* Select PLL as CPU clock source */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;
}




/*
 *  �������åȥ����ƥ��¸�ν����
 */
void
sys_initialize()
{
    int i;

    init_vector();			/* SRAM�Υ�ޥåס�LPC2388���� */

    init_clock();			/* PLL�����ꡣ�����ƥ��ͭ */

    init_uart0();			/* UART0�ν�����������ƥ��ͭ */

    init_IRQ();				/* VIC���������롣LPC2388���� */

    		/* ɬ�פʥڥ�ե������Ÿ��������(�����ƥ��ͭ) */
			/* �ʤ���UART0��TIMER3��LPC2388���̤�ɬ�� */
	PCONP |= 0x00800008;	/* bit3:UART0, bit23:TIMER3 */

			/* UART0�Υԥ������ (LPC2388����) */
	PINSEL0 &= ~0xF0;			/* bit 4-7�����򥯥ꥢ */
	PINSEL0 |= 0x50;			/* UART�����Ϥ������� */

    /*
     *  ARM�Υ٥����ơ��֥�س���ߥϥ�ɥ����Ͽ�ʤɤ�ARMv4�����ƥ�Ǥ��׵ᤵ����
     */
    arm_install_handler(IRQ_Number,IRQ_Handler);

}





