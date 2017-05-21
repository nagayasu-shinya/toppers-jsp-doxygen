/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2003-2004 by CHUO ELECTRIC WORKS Co.,LTD. JAPAN
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
#ifndef _SYS_SUPPORT_H_
#define _SYS_SUPPORT_H_

/*
 *  �ݡ��ȣ�����ĥ�ɡ��Ϥس���ü�Ҥ����
 *  ���٤ƥץ륢�åפ���
 */
/*
 *  PA15 ���򤹤뵡ǽ�� 1 �˥��åȤ��Ƥ�������
 */
#define	PA15_PORT_IN	1	/* �������ϥݡ���		PI15	*/
#define	PA15_PORT_OUT	0	/* ���ѽ��ϥݡ���		PO15	*/
#define	PA15_IRQ3	0	/* �������׵�����		IRQ3	*/
#define	PA15_DREQ1	0	/* �ģͣ�ž���׵�����		DREQ1	*/

/*
 *  PA14 ���򤹤뵡ǽ�� 1 �˥��åȤ��Ƥ�������
 */
#define	PA14_PORT_IN	1	/* �������ϥݡ���		PI14	*/
#define	PA14_PORT_OUT	0	/* ���ѽ��ϥݡ���		PO14	*/
#define	PA14_IRQ2	0	/* �������׵����� 		IRQ2	*/
#define	PA14_DACK1	0	/* �ģͣ�ž���׵���ս���	DACK1	*/

/*
 *  PA13 ���򤹤뵡ǽ�� 1 �˥��åȤ��Ƥ�������
 */
#define	PA13_PORT_IN	1	/* �������ϥݡ���		PI13	*/
#define	PA13_PORT_OUT	0	/* ���ѽ��ϥݡ���		PO13	*/
#define	PA13_IRQ1	0	/* �������׵����� 		IRQ1	*/
#define	PA13_TCLKB	0	/* �ɣԣե����ޥ���å�����	TCLKB	*/
#define	PA13_DREQ0	0	/* �ģͣ�ž���׵�����		DREQ0	*/

/*
 *  PA12 ���򤹤뵡ǽ�� 1 �˥��åȤ��Ƥ�������
 */
#define	PA12_PORT_IN	1	/* �������ϥݡ���		PI12	*/
#define	PA12_PORT_OUT	0	/* ���ѽ��ϥݡ���		PO12	*/
#define	PA12_IRQ0	0	/* �������׵����� 		IRQ0	*/
#define	PA13_TCLKA	0	/* �ɣԣե����ޥ���å�����	TCLKA	*/
#define	PA13_DACK0	0	/* �ģͣ�ž���׵���ս���	DACK0	*/

/*
 *  PA03 ���򤹤뵡ǽ�� 1 �˥��åȤ��Ƥ�������
 */
#define	PA03_PORT_IN	1	/* �������ϥݡ���		PI03	*/
#define	PA03_PORT_OUT	0	/* ���ѽ��ϥݡ���		PO03	*/
#define	PA03_CS7	0	/* ���åץ��쥯�ȣ�����		CS7	*/
#define	PA03_WAIT	0	/* �������ȥ��ơ�������		WAIT	*/

/*
 *  PA01 ���򤹤뵡ǽ�� 1 �˥��åȤ��Ƥ�������
 */
#define	PA01_PORT_IN	1	/* �������ϥݡ���		PI01	*/
#define	PA01_PORT_OUT	0	/* ���ѽ��ϥݡ���		PO01	*/
#define	PA01_CS5	0	/* ���åץ��쥯�ȣ�����		CS5	*/
#define	PA01_RAS	0	/* �����ɥ쥹���ȥ��ֽ���	RAS	*/

/*####################################################
 *
 *  �ʲ��Խ����ʤ�����
 *
 *####################################################*/
/*
 *  �У����У½��ϥХåե������
 *  ���Υԥ�ե��󥯥��������򻲾Ȥ��Ƥ�������
 */
#define	VAL_PA_DR 	(1<<10 | 1<<9 | 1<<8)	/* RTC-4553-CS=1,RTC-4553-WR=1,LEDCTL1=1(off) */
#define	VAL_PB_DR 	(1<<11 | 1<<9 | 1<<6)	/* TXD1=1,TXD0=1,LEDCTL2=1(off) */

/*
 *  PA ���굡ǽ��PA15,14,13,12,03,01�������
 *
 *  PNO  I/O PAIOR  PACR1/2
 *  PA15 IN   [0]    [00] �� ��ĥ�ɡ��Ϥ˳���
 *  PA14 IN   [0]    [00] �� ��ĥ�ɡ��Ϥ˳���
 *  PA13 IN   [0]    [00] �� ��ĥ�ɡ��Ϥ˳���
 *  PA12 IN   [0]    [00] �� ��ĥ�ɡ��Ϥ˳���
 *  PA11 IN   [0]    [00] �� RTC-4553-SOUT
 *  PA10 OUT  [1]    [00] �� RTC-4553-CS[active-low]
 *  PA09 OUT  [1]    [00] �� RTC-4553-WR[active-low]
 *  PA08 OUT  [1]    [10] �� LEDCTL1 LED1����[active-low]
 *  PA07 IN   [0]    [10] �� ̤����
 *  PA06 ��   [0]    [11] �� RD �˳�����ơ�
 *  PA05 OUT  [1]    [10] �� WD-PULSE �����å��ɥå��ꥻ�åȥѥ륹�������ˤ�
 *  PA04 ��   [0]    [11] �� WR �˳������
 *  PA03 ��   [0]    [00] �� ��ĥ�ɡ��Ϥ˳���
 *  PA02 ��   [0]    [01] �� CS6 �˳�����ơʣ̣��Υ���ȥ����ѡ�
 *  PA01 ��   [0]    [00] �� ��ĥ�ɡ��Ϥ˳���
 *  PA00 ��   [0]    [01] �� CS4 �˳�����ơ�ROMICE �ѡ�
 */
#define	PAIOR_BASE	0x0720
#define	PACR1_BASE	0x0002
#define	PACR2_BASE	0xbb11

#if PA15_PORT_IN == 1
#define	PA15MD			0	/* �������ϥݡ���		PI15	*/
#define	PA15IOR			0
#endif
#if PA15_PORT_OUT == 1
#ifdef PA15MD
#error : 'PA15MD' redefined.
#endif
#define	PA15MD			0	/* ���ѽ��ϥݡ���		PO15	*/
#define	PA15IOR			1
#endif
#if PA15_IRQ3 == 1
#ifdef PA15MD
#error : 'PA15MD' redefined.
#endif
#define	PA15MD			1	/* �������׵�����		IRQ3	*/
#define	PA15IOR			0
#endif
#if PA15_DREQ1 == 1
#ifdef PA15MD
#error : 'PA15MD' redefined.
#endif
#define	PA15MD			3	/* �ģͣ�ž���׵�����		DREQ1	*/
#define	PA15IOR			0
#endif
#ifndef	PA15MD
#error : 'PA15MD' is not set up.
#endif

#if PA14_PORT_IN == 1
#define	PA14MD			0	/* �������ϥݡ���		PI14	*/
#define	PA14IOR			0
#endif
#if PA14_PORT_OUT == 1
#ifdef PA14MD
#error : 'PA14MD' redefined.
#endif
#define	PA14MD			0	/* ���ѽ��ϥݡ���		PO14	*/
#define	PA14IOR			1
#endif
#if PA14_IRQ2 == 1
#ifdef PA14MD
#error : 'PA14MD' redefined.
#endif
#define	PA14MD			1	/* �������׵�����		IRQ2	*/
#define	PA14IOR			0
#endif
#if PA14_DACK1 == 1
#ifdef PA14MD
#error : 'PA14MD' redefined.
#endif
#define	PA14MD			3	/* �ģͣ�ž���׵���ս���	DACK1	*/
#define	PA14IOR			0
#endif
#ifndef PA14MD
#error : 'PA14MD' is not set up.
#endif

#if PA13_PORT_IN == 1
#define	PA13MD			0	/* �������ϥݡ���		PI13	*/
#define	PA13IOR			0
#endif
#if PA13_PORT_OUT == 1
#ifdef PA13MD
#error : 'PA13MD' redefined.
#endif
#define	PA13MD			0	/* ���ѽ��ϥݡ���		PO13	*/
#define	PA13IOR			1
#endif
#if PA13_IRQ1 == 1
#ifdef PA13MD
#error : 'PA13MD' redefined.
#endif
#define	PA13MD			1	/* �������׵�����		IRQ1	*/
#define	PA13IOR			0
#endif
#if PA13_TCLKB == 1
#ifdef PA13MD
#error : 'PA13MD' redefined.
#endif
#define	PA13MD			2	/* �ɣԣե����ޥ���å�����	TCLKB	*/
#define	PA13IOR			0
#endif
#if PA13_DREQ0 == 1
#ifdef PA13MD
#error : 'PA13MD' redefined.
#endif
#define	PA13MD			3	/* �ģͣ�ž���׵�����		DREQ0	*/
#define	PA13IOR			0
#endif
#ifndef PA13MD
#error : 'PA13MD' is not set up.
#endif

#if PA12_PORT_IN == 1
#define	PA12MD			0	/* �������ϥݡ���		PI12	*/
#define	PA12IOR			0
#endif
#if PA12_PORT_OUT == 1
#ifdef PA12MD
#error : 'PA12MD' redefined.
#endif
#define	PA12MD			0	/* ���ѽ��ϥݡ���		PO12	*/
#define	PA12IOR			1
#endif
#if PA12_IRQ0 == 1
#ifdef PA12MD
#error : 'PA12MD' redefined.
#endif
#define	PA12MD			1	/* �������׵�����		IRQ0	*/
#define	PA12IOR			0
#endif
#if PA13_TCLKA == 1
#ifdef PA12MD
#error : 'PA12MD' redefined.
#endif
#define	PA12MD			2	/* �ɣԣե����ޥ���å�����	TCLKA	*/
#define	PA12IOR			0
#endif
#if PA13_DACK0 == 1
#ifdef PA12MD
#error : 'PA12MD' redefined.
#endif
#define	PA12MD			3	/* �ģͣ�ž���׵���ս���	DACK0	*/
#define	PA12IOR			0
#endif
#ifndef PA12MD
#error : 'PA12MD' is not set up.
#endif

#if PA03_PORT_IN == 1
#define	PA03MD			0	/* �������ϥݡ���		PI03	*/
#define	PA03IOR			0
#endif
#if PA03_PORT_OUT == 1
#ifdef PA03MD
#error : 'PA03MD' redefined.
#endif
#define	PA03MD			0	/* ���ѽ��ϥݡ���		PO03	*/
#define	PA03IOR			1
#endif
#if PA03_CS7 == 1
#ifdef PA03MD
#error : 'PA03MD' redefined.
#endif
#define	PA03MD			1	/* ���åץ��쥯�ȣ�����		CS7	*/
#define	PA03IOR			0
#endif
#if PA03_WAIT == 1
#ifdef PA03MD
#error : 'PA03MD' redefined.
#endif
#define	PA03MD			2	/* �������ȥ��ơ�������		WAIT	*/
#define	PA03IOR			0
#endif
#ifndef PA03MD
#error : 'PA03MD' is not set up.
#endif

#if PA01_PORT_IN == 1
#define	PA01MD			0	/* �������ϥݡ���		PI01	*/
#define	PA01IOR			0
#endif
#if PA01_PORT_OUT == 1
#ifdef PA01MD
#error : 'PA01MD' redefined.
#endif
#define	PA01MD			0	/* ���ѽ��ϥݡ���		PO01	*/
#define	PA01IOR			1
#endif
#if PA01_CS5 == 1
#ifdef PA01MD
#error : 'PA01MD' redefined.
#endif
#define	PA01MD			1	/* ���åץ��쥯�ȣ�����		CS5	*/
#define	PA01IOR			0
#endif
#if PA01_RAS == 1
#ifdef PA01MD
#error : 'PA01MD' redefined.
#endif
#define	PA01MD			2	/* �����ɥ쥹���ȥ��ֽ���	RAS	*/
#define	PA01IOR			0
#endif
#ifndef PA01MD
#error : 'PA01MD' is not set up.
#endif

/*
 *  �ݡ��ȣ��ԥ�ե��󥯥�������
 */
#define VAL_PFC_PAIOR   (PAIOR_BASE | PA15IOR<<15 | PA14IOR<<14 | PA13IOR<<13 | PA12IOR<<12 | PA03IOR<<3 | PA01IOR<<1)
#define VAL_PFC_PACR1   (PACR1_BASE | PA15MD<<14  | PA14MD<<12  | PA13MD<<10  | PA12MD<<8)
#define VAL_PFC_PACR2   (PACR2_BASE | PA03MD<<6   | PA01MD<<2)

/*
 *  �ݡ��ȣ¥ԥ�ե��󥯥�������
 */
#define VAL_PFC_PBIOR   0x107b
#define VAL_PFC_PBCR1   0x14aa
#define VAL_PFC_PBCR2   0x0000
 /*
 *  PNO  I/O PBIOR  PBCR1/2
 *  PB15 IN   [0]    [00] �� ̤���� IRQ7 �˳�����ơʣңԣ��ѡ�
 *  PB14 ��   [0]    [01] �� IRQ6 �˳�����ơʣգӣ¥���ȥ����ѡ�
 *  PB13 ��   [0]    [01] �� IRQ5 �˳�����ơʣ̣��Υ���ȥ����ѡ�
 *  PB12 OUT  [1]    [00] �� LEDCTL3 LED3 ����[active-low]
 *  PB11 ��   [0]    [10] �� TDX1 �˳�����ơ�RS485 �ǡ������ϡ�
 *  PB10 ��   [0]    [10] �� RDX1 �˳�����ơ�RS485 �ǡ������ϡ�
 *  PB09 ��   [0]    [10] �� TDX0 �˳�����ơ�RS-232C �ǡ������ϡ�
 *  PB08 ��   [0]    [10] �� RDX0 �˳�����ơ�RS-232C �ǡ������ϡ�
 *  PB07 IN   [0]    [00] �� ���ꥢ��EEPROM-DO
 *  PB06 OUT  [1]    [00] �� LEDCTL2 LED2 ����[active-low]
 *  PB05 OUT  [1]    [00] �� TXE0 RS485 �������͡��֥�����������
 *  PB04 OUT  [1]    [00] �� ���ꥢ��EEPROM-CS[active-high]
 *  PB03 OUT  [1]    [00] �� CTS0 RS232C ��CTS �����̤������
 *  PB02 IN   [0]    [00] �� RTS0 RS232C ��RTS �����̤������
 *  PB01 OUT  [1]    [00] �� ���ꥢ��EEPROM-SK��RTC-4553-SCK
 *  PB00 OUT  [1]    [00] �� ���ꥢ��EEPROM-DI��RTC-4553-SIN
 *
 *  PBIOR=0x107b
 *  PBCR1=0x14aa
 *  PBCR2=0x0000
 *
 */

/*
 *  ����ॢ�ɥ쥹���ȥ��֥ԥ󥳥�ȥ������
 */
#define VAL_PFC_CASCR   0x5fff

#ifndef _MACRO_ONLY
/*
 * �ؿ����
 */
void	software_init_hook(void);
void	hardware_init_hook(void);

#endif /* _MACRO_ONLY */
#endif	/* _SYS_SUPPORT_H_ */


