/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by Advanced Data Controls, Corp
 *  Copyright (C) 2009 by Suikan
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
 *  �������åȥ��åװ�¸�⥸�塼���LPC2388�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�sys_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */


#ifndef _CHIP_CONFIG_H_
#define _CHIP_CONFIG_H_


/*
 * ����ߥϥ�ɥ�κ����
 */
#define MAX_INT_NUM 31

/*
 *  vxget_tim �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define  SUPPORT_VXGET_TIM



/*
 *  ������Ԥ����֤Ǥμ¹ԥ롼����
 */
#ifdef ARM920T_CORE
#define WAIT_INTERRUPT  mcr p15, 0, r3, c7, c0, 4
#else
#define WAIT_INTERRUPT  nop
#endif

/*
 *  �ץ��å��Υ���ǥ�����
 */
#define SIL_ENDIAN  SIL_ENDIAN_LITTLE  /* ��ȥ륨��ǥ����� */


/*
 * ----------------------- �����ߥ٥��ȥ���� --------------------
 * INTNO_UART0 �ǤϤʤ� INTO_U0 ��Ȥ��Τϡ�UART��TOPPERS/JSP�����ΥǥХ���̾�Ȥ���
 * �ȤäƤ��ꡢUART���ֹ��LPC2388����Ʊ���̿��ǥХ������ֹ椬���פ��ʤ�����Ǥ��롣
 *
 */
#define	INTNO_WDT		0
/*reserverved interrupt 1*/
#define	INTNO_ARM0		2
#define	INTNO_ARM1		3
#define	INTNO_TIMER0	4
#define	INTNO_TIMER1	5
#define	INTNO_U0		6
#define	INTNO_U1		7
#define	INTNO_PWM1		8
#define	INTNO_I2C0		9
#define	INTNO_SSP0		10
#define	INTNO_SSP1		11
#define	INTNO_PLL		12
#define	INTNO_RTC		13
#define	INTNO_EINT0		14
#define	INTNO_EINT1		15
#define	INTNO_EINT2		16
#define	INTNO_EINT3		17
#define	INTNO_ADC0		18
#define	INTNO_I2C1		19
#define	INTNO_BOD		20
#define	INTNO_ETHERNET	21
#define	INTNO_USB		22
#define	INTNO_CAN		23
#define	INTNO_SD		24
#define	INTNO_GPDMA		25
#define	INTNO_TIMER2	26
#define	INTNO_TIMER3	27
#define	INTNO_U2		28
#define	INTNO_U3		29
#define	INTNO_I2C2		30
#define	INTNO_I2S		31

#define	INHNO_WDT		0
/*reserverved interrupt 1*/
#define	INHNO_ARM0		2
#define	INHNO_ARM1		3
#define	INHNO_TIMER0	4
#define	INHNO_TIMER1	5
#define	INHNO_U0		6
#define	INHNO_U1		7
#define	INHNO_PWM1		8
#define	INHNO_I2C0		9
#define	INHNO_SSP0		10
#define	INHNO_SSP1		11
#define	INHNO_PLL		12
#define	INHNO_RTC		13
#define	INHNO_EINT0		14
#define	INHNO_EINT1		15
#define	INHNO_EINT2		16
#define	INHNO_EINT3		17
#define	INHNO_ADC0		18
#define	INHNO_I2C1		19
#define	INHNO_BOD		20
#define	INHNO_ETHERNET	21
#define	INHNO_USB		22
#define	INHNO_CAN		23
#define	INHNO_SD		24
#define	INHNO_GPDMA		25
#define	INHNO_TIMER2	26
#define	INHNO_TIMER3	27
#define	INHNO_U2		28
#define	INHNO_U3		29
#define	INHNO_I2C2		30
#define	INHNO_I2S		31

/*
 * SIO1,2,3�ˤ�U0,U2,U3�������Ƥ�
 */
#define INHNO_SIO		INHNO_U0
#define INHNO_SIO2		INHNO_U2
#define INHNO_SIO3		INHNO_U3

/*
 * ----------------------- UART ���� ---------------------------
 */

/*
 *     UART�Τ��������ĤΥݡ��Ȥ�PDIC�Ȥ��ƻ��Ѥ��뤫������롣
 *     LPC2388�ǤǤϺ���3
 */
#define TNUM_SIOP_UART	TNUM_SIOP

/*
 *    UART�Υ쥸���������Х��ȶ��������֤���Ƥ��뤫����ꤹ�롣����Ǥ����ͤ�1,2,4�Τ����줫��
 */
#define UART_BOUNDARY	4

/*
 * UART �쥸�����ؤΥ���������sil_xxb_iop()�Ȥ����ˤϤ��Υޥ����������롣
 * �ͤ����ס�������ʤ���硢sil_xxb_mem()�ˤ�äƥ����������롣LPC2388����
 * �Ǥ�mem������������Ѥ��롣
 */
/* #define UART_IOP_ACCESS */

/*
 *     UART�Υ١��������ɥ쥹����ꤹ�롣�١������ɥ쥹�Ȥ�THR�Υ��ɥ쥹�Τ��ȡ�
 *     U0,2,3��Ȥ��Τϡ�LPC2388�ˤ�����U1�����̰����Τ���
 */
#define UART0_ADDRESS 0xE000C000
#define UART1_ADDRESS 0xE0078000	/*U2*/
#define UART2_ADDRESS 0xE007C000	/*U3*/

/*
 * UART������ʬ����ϩ�������ͤ���ꤹ�롣16�ӥåȤ��͡�lpc2388uart.c������
 * ��̤Ȳ��̤�ʬ�䤷��DLM/DLL�쥸���������ꤵ��롣
 *
 * UART�ΥǥХ����ν��ϤϽ�˾����ܡ��졼�Ȥ�16�ܤǤʤ���Фʤ�ʤ���
 * U0,2,3��Ȥ��Τϡ�LPC2388�ˤ�����U1�����̰����Τ���
 */
#define UART0_DIVISOR (LP2388_SYSTEM_UART0_CLOCK/16/UART0_BAUD_RATE)
#define UART1_DIVISOR (LP2388_SYSTEM_UART1_CLOCK/16/UART2_BAUD_RATE) /*U2*/
#define UART2_DIVISOR (LP2388_SYSTEM_UART1_CLOCK/16/UART3_BAUD_RATE) /*U3*/


/*
 * ----------------------- UART ���ꤪ��� ---------------------------
 */


#ifndef _MACRO_ONLY

/*
 *  �������åȥ����ƥ��¸�ν����
 */
extern void    sys_initialize(void);

/*
 *  �������åȥ����ƥ�ν�λ
 *
 *  �����ƥ��λ������˻Ȥ���ROM��˥��ƽФ��Ǽ¸����뤳�Ȥ����ꤷ
 *  �Ƥ��롥
 */
extern void    sys_exit(void);

/*
 *  �������åȥ����ƥ��ʸ������
 *
 *  �����ƥ�����٥��ʸ�����ϥ롼����ROM��˥��ƽФ��Ǽ¸����뤳
 *  �Ȥ����ꤷ�Ƥ��롥
 */
extern void    sys_putc(char c);



/*
 *  IRQ�ϥ�ɥ�(sys_support.S)
 */
extern void IRQ_Handler(void);

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *
 */
#define INTHDR_ENTRY(inthdr)  extern void inthdr(void)

#define INT_ENTRY(inthdr) inthdr

/*
 *  ����ߥϥ�ɥ������
 *
 *  ������ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 */
extern void define_inh(INHNO inhno, FP inthdr);

extern void undef_interrupt();

extern void init_IRQ();
extern void init_vector();
extern void init_uart0();

/*
 * �����ߤΥ��͡��֥롢�ǥ������֥�
 */

extern ER dis_int(INTNO intno);
extern ER ena_int(INTNO intno);
extern ER chg_ims(unsigned int enableMask);
extern ER get_ims(unsigned int *p_enableMask);

#endif /* _MACRO_ONLY */
#endif /* _SYS_CONFIG_H_ */
