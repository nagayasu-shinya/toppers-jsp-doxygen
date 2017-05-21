/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id: oaks16.h,v 1.3 2005/11/24 12:41:23 honda Exp $
 */

#ifndef _OAKS16_H_
#define	_OAKS16_H_

/*
 *  ������ֹ�����
 */
#define	INT_BRK         0			/* BRK */
#define INT_INT3        4			/* INT3 */
#define INT_TB5	        5			/* ������B5 */
#define INT_TB4         6			/* ������B4 */
#define INT_TB3         7			/* ������B3 */
#define INT_SIO4INT5    8			/* SI/O4/INT5 */
#define INT_SIO3INT4    9			/* SI/O3/INT4 */
#define INT_BUS         10			/* �Х����͸��� */
#define INT_DMA0        11			/* DMA0 */
#define INT_DMA1        12			/* DMA1 */
#define INT_KEY         13			/* �������ϳ����� */
#define INT_AD          14			/* ��-���Ѵ��� */
#define INT_S2TNACK     15			/* UART2����,NACK2 */
#define INT_S2RACK      16			/* UART2����,ACK2 */
#define INT_S0T         17			/* UART0���� */
#define INT_S0R         18			/* UART0���� */
#define INT_S1T         19			/* UART1���� */
#define INT_S1R         20			/* UART1���� */
#define INT_TA0         21			/* ������A0 */
#define INT_TA1         22			/* ������A1 */
#define INT_TA2         23			/* ������A2 */
#define INT_TA3         24			/* ������A3 */
#define INT_TA4         25			/* ������A4 */
#define INT_TB0         26			/* ������B0 */
#define INT_TB1         27			/* ������B1 */
#define INT_TB2         28			/* ������B2 */
#define INT_INT0        29			/* INT0 */
#define INT_INT1        30			/* INT1 */
#define INT_INT2        31			/* INT2 */

/*
 *  OAKS16 SFR���ɥ쥹���
 *
 *  ����ߥ쥸����
 */
#define	TADR_SFR_INT_BASE       0x040			/* ����ߴ�Ϣ�Υ١������ɥ쥹 */
#define TADR_SFR_INT3IC_OFFSET  4				/* INT3 ���������쥸���� */
#define TADR_SFR_TB5IC_OFFSET   5				/* timerB5 ���������쥸���� */
#define TADR_SFR_TB4IC_OFFSET   6				/* timerB4 ���������쥸���� */
#define TADR_SFR_TB3IC_OFFSET   7				/* timerB3 ���������쥸���� */
#define TADR_SFR_SO4INT5_OFFSET 8				/* SI/O4/INT5 ���������쥸���� */
#define TADR_SFR_SO3INT4_OFFSET 9				/* SI/O3/INT4 ���������쥸���� */
#define TADR_SFR_BCNIC_OFFSET   10				/* �Х����͸��г��������쥸���� */
#define TADR_SFR_DMA0IC_OFFSET  11				/* DMA0���������쥸���� */
#define TADR_SFR_DMA1IC_OFFSET  12				/* DMA1���������쥸���� */
#define TADR_SFR_KUPIC_OFFSET   13				/* �������ϳ��������쥸���� */
#define TADR_SFR_ADIC_OFFSET    14				/* A-D�Ѵ����������쥸���� */
#define	TADR_SFR_S2TIC_OFFSET   15				/* uart2�������������쥸���� */
#define	TADR_SFR_S2RIC_OFFSET   16				/* uart2�������������쥸���� */
#define	TADR_SFR_S0TIC_OFFSET   17				/* uart0�������������쥸���� */
#define	TADR_SFR_S0RIC_OFFSET   18				/* uart0�������������쥸���� */
#define	TADR_SFR_S1TIC_OFFSET   19				/* uart1�������������쥸���� */
#define	TADR_SFR_S1RIC_OFFSET   20				/* uart1�������������쥸���� */
#define	TADR_SFR_TA0IC_OFFSET   21				/* timerA0 ���������쥸���� */
#define TADR_SFR_TA1IC_OFFSET   22				/* timerA1 ���������쥸���� */
#define TADR_SFR_TA2IC_OFFSET   23				/* timerA2 ���������쥸���� */
#define TADR_SFR_TA3IC_OFFSET   24				/* timerA3 ���������쥸���� */
#define TADR_SFR_TA4IC_OFFSET   25				/* timerA4 ���������쥸���� */
#define TADR_SFR_TB0IC_OFFSET   26				/* timerB0 ���������쥸���� */
#define TADR_SFR_TB1IC_OFFSET   27				/* timerB1 ���������쥸���� */
#define TADR_SFR_TB2IC_OFFSET   28				/* timerB2 ���������쥸���� */
#define TADR_SFR_INT0IC_OFFSET  29				/* INT0 ���������쥸���� */
#define TADR_SFR_INT1IC_OFFSET  30				/* INT1 ���������쥸���� */
#define TADR_SFR_INT12C_OFFSET  31				/* INT2 ���������쥸���� */

/*
 *  DMA�쥸����
 */
#define TADR_SFR_SAR0           0x020			/* DMA0�������ݥ��� */
#define TADR_SFR_DAR0           0x024			/* DMA0�ǥ��ƥ��͡������ݥ��� */
#define TADR_SFR_TCR0			0x028			/* DMA0ž�������� */
#define TADR_SFR_DM0CON         0x02c			/* DMA0����쥸���� */
#define TADR_SFR_SAR1           0x030			/* DMA1�������ݥ��� */
#define TADR_SFR_DAR1           0x034			/* DMA1�ǥ��ƥ��͡������ݥ��� */
#define TADR_SFR_TCR1			0x038			/* DMA1ž�������� */
#define TADR_SFR_DM1CON         0x03c			/* DMA1����쥸���� */

/*
 *  �����ޡ��Ȥ���¾�ΥǥХ����쥸����
 */
#define TADR_SFR_TBSR           0x340			/* timerB3,4,5������ȳ��ϥե饰 */
#define TADR_SFR_TA11           0x342			/* timerA1-1�쥸���� */
#define TADR_SFR_TA21           0x344			/* timerA2-1�쥸���� */
#define TADR_SFR_TA41           0x346			/* timerA4-1�쥸���� */
#define TADR_SFR_INVC0          0x348			/* ����PWM����쥸������ */
#define TADR_SFR_INVC1          0x349			/* ����PWM����쥸������ */
#define TADR_SFR_IDB0           0x34a			/* ������ϥХåե��쥸������ */
#define TADR_SFR_IDB1           0x34b			/* ������ϥХåե��쥸������ */
#define TADR_SFR_DTT            0x34c			/* û���ɻߥ����� */
#define TADR_SFR_ICTB2          0x34d			/* timerB2�����ȯ���������ꥫ���� */
#define TADR_SFR_TB3            0x350			/* timerB3�쥸���� */
#define TADR_SFR_TB4            0x352			/* timerB4�쥸���� */
#define TADR_SFR_TB5            0x354			/* timerB5�쥸���� */
#define	TADR_SFR_TB3MR          0x35b			/* timerB3�⡼�ɥ쥸���� */
#define	TADR_SFR_TB4MR          0x35c			/* timerB4�⡼�ɥ쥸���� */
#define	TADR_SFR_TB5MR          0x35d			/* timerB5�⡼�ɥ쥸���� */
#define TADR_SFR_IFSR           0x35f			/* ������װ�����쥸���� */

#define TADR_SFR_S3TRR          0x360			/* SI/O3�������쥸���� */
#define TADR_SFR_S3C            0x362			/* SI/O3����쥸���� */
#define TADR_SFR_S3BRG          0x363			/* SI/O3ž��®�٥쥸���� */
#define TADR_SFR_S4TRR          0x364			/* SI/O4�������쥸���� */
#define TADR_SFR_S4C            0x366			/* SI/O4����쥸���� */
#define TADR_SFR_S4BRG          0x367			/* SI/O4ž��®�٥쥸���� */

#define	TADR_SFR_TABSR          0x380			/* ������ȳ��ϥե饰 */
#define TADR_SFR_CPSRF          0x381			/* �ꥻ�å� �ץꥹ������ �ꥻ�åȥե饰 */
#define TADR_SFR_ONSF           0x382			/* ��󥷥�� �������ȥե饰 */
#define TADR_SFR_TRGSR          0x383			/* �ȥꥬ�����쥯�� �쥸���� */
#define	TADR_SFR_UDF            0x384			/* ���åץ�����ե饰 */
#define	TADR_SFR_TA0            0x386			/* timerA0�쥸���� */
#define TADR_SFR_TA1            0x388			/* timerA1�쥸���� */
#define TADR_SFR_TA2            0x38a			/* timerA2�쥸���� */
#define TADR_SFR_TA3            0x38c			/* timerA3�쥸���� */
#define TADR_SFR_TA4            0x38e			/* timerA4�쥸���� */
#define TADR_SFR_TB0            0x390			/* timerB0�쥸���� */
#define TADR_SFR_TB1            0x392			/* timerB1�쥸���� */
#define TADR_SFR_TB2            0x394			/* timerB2�쥸���� */
#define	TADR_SFR_TA0MR          0x396			/* timerA0�⡼�ɥ쥸���� */
#define	TADR_SFR_TA1MR          0x397			/* timerA1�⡼�ɥ쥸���� */
#define	TADR_SFR_TA2MR          0x398			/* timerA2�⡼�ɥ쥸���� */
#define	TADR_SFR_TA3MR          0x399			/* timerA3�⡼�ɥ쥸���� */
#define	TADR_SFR_TA4MR          0x39a			/* timerA4�⡼�ɥ쥸���� */
#define	TADR_SFR_TB0MR          0x39b			/* timerB0�⡼�ɥ쥸���� */
#define	TADR_SFR_TB1MR			0x39c			/* timerB1�⡼�ɥ쥸���� */
#define	TADR_SFR_TB2MR          0x39d			/* timerB2�⡼�ɥ쥸���� */
#define	TADR_SFR_TB2SR          0x39e			/* timerB2���ڥ����⡼�ɥ쥸���� */

/*
 *  ���ꥢ��쥸����
 */
#define	TADR_SFR_UART0_BASE     0x3a0			/* uart0�쥸�����١������ɥ쥹 */
#define	TADR_SFR_UART1_BASE     0x3a8			/* uart1�쥸�����١������ɥ쥹 */
#define	TADR_SFR_UART2_BASE     0x378			/* uart2�쥸�����١������ɥ쥹 */
#define	TADR_SFR_U2SMR          0x377			/* uart2�ü�⡼�ɥ쥸���� */
#define	TADR_SFR_U2SMR2         0x376			/* uart2�ü�⡼�ɥ쥸������ */
#define	TADR_SFR_U2SMR3         0x375			/* uart2�ü�⡼�ɥ쥸������ */

#define	TADR_SFR_UMR_OFFSET     0				/* uart�������⡼�ɥ쥸���� */
#define	TADR_SFR_UBRG_OFFSET    1				/* uart�ܡ��졼�ȥ����ͥ졼�� */
#define	TADR_SFR_UTB_OFFSET     2				/* uart�����Хåե��쥸���� */
#define	TADR_SFR_UC0_OFFSET     4				/* uart����������쥸����#0 */
#define	TADR_SFR_UC1_OFFSET     5				/* uart����������쥸����#1 */
#define	TADR_SFR_URB_OFFSET     6				/* uart�����Хåե��쥸���� */
#define	TADR_SFR_UC2_OFFSET     16				/* uart����������쥸����#2 */

/*
 *  A-D/D-A�쥸����
 */
#define TADR_SFR_AD0            0x3c0			/* A-D�쥸������ */
#define TADR_SFR_AD1            0x3c2			/* A-D�쥸������ */
#define TADR_SFR_AD2            0x3c4			/* A-D�쥸������ */
#define TADR_SFR_AD3            0x3c6			/* A-D�쥸������ */
#define TADR_SFR_AD4            0x3c8			/* A-D�쥸������ */
#define TADR_SFR_AD5            0x3ca			/* A-D�쥸������ */
#define TADR_SFR_AD6            0x3cc			/* A-D�쥸������ */
#define TADR_SFR_AD7            0x3ce			/* A-D�쥸������ */
#define TADR_SFR_ADCON2         0x3d4			/* A-D����쥸������ */
#define TADR_SFR_ADCON0         0x3d6			/* A-D����쥸������ */
#define TADR_SFR_ADCON1         0x3d7			/* A-D����쥸������ */
#define TADR_SFR_DA0            0x3d8			/* D-A�쥸������ */
#define TADR_SFR_DA1            0x3da			/* D-A�쥸������ */
#define TADR_SFR_DACON          0x3dc			/* D-A����쥸���� */

/*
 *  ���ѥݡ��ȥ쥸����
 */
#define TADR_SFR_P0             0x3e0           /* �ݡ���P0�쥸���� */
#define TADR_SFR_P1             0x3e1           /* �ݡ���P1�쥸���� */
#define TADR_SFR_PD0            0x3e2			/* �ݡ���P0�����쥸���� */
#define TADR_SFR_PD1            0x3e3			/* �ݡ���P1�����쥸���� */
#define TADR_SFR_P2             0x3e4			/* �ݡ���P2�쥸���� */
#define TADR_SFR_P3             0x3e5			/* �ݡ���P3�쥸���� */
#define	TADR_SFR_PD2            0x3e6			/* �ݡ���P2�����쥸���� */
#define	TADR_SFR_PD3            0x3e7			/* �ݡ���P3�����쥸���� */
#define TADR_SFR_P4             0x3e8			/* �ݡ���P4�쥸���� */
#define	TADR_SFR_P5             0x3e9			/* �ݡ���P5�쥸���� */
#define	TADR_SFR_PD4            0x3ea			/* �ݡ���P4�����쥸���� */
#define	TADR_SFR_PD5            0x3eb			/* �ݡ���P5�����쥸���� */
#define TADR_SFR_P6             0x3ec			/* �ݡ���P6�쥸���� */
#define	TADR_SFR_P7             0x3ed			/* �ݡ���P7�쥸���� */
#define	TADR_SFR_PD6            0x3ee			/* �ݡ���P6�����쥸���� */
#define	TADR_SFR_PD7            0x3ef			/* �ݡ���P7�����쥸���� */
#define	TADR_SFR_P8             0x3f0			/* �ݡ���P8�쥸���� */
#define TADR_SFR_P9             0x3f1			/* �ݡ���P9�쥸���� */
#define	TADR_SFR_PD8            0x3f2			/* �ݡ���P8�����쥸���� */
#define TADR_SFR_PD9            0x3f3			/* �ݡ���P9�����쥸���� */
#define TADR_SFR_P10            0x3f4			/* �ݡ���P10�쥸���� */
#define TADR_SFR_PD10           0x3f6			/* �ݡ���P10�����쥸���� */
#define	TADR_SFR_PUR0           0x3fc			/* �ץ륢�å�����쥸������ */
#define	TADR_SFR_PUR1           0x3fd			/* �ץ륢�å�����쥸������ */
#define	TADR_SFR_PUR2           0x3fe			/* �ץ륢�å�����쥸������ */
#define	TADR_SFR_PCR            0x3ff			/* �ݡ�������쥸���� */

/*
 *  ����������쥸����1 (UART0,UART1)
 */
#define	TBIT_UiC1_RI	0x08	/* ������λ�ե饰 */
#define	TBIT_UiC1_RE	0x04	/* �������ĥӥå� */
#define	TBIT_UiC1_TI	0x02	/* �����Хåե����ե饰 */
#define	TBIT_UiC1_TE	0x01	/* �������ĥӥå� */

#define TBIT_UiC0_TXEPT	0x08	/* �����쥸�������ե饰 */

/*
 *  ���������쥸����
 */
#define	TBIT_TAiIC_IR	0x08

/*
 *  ������ȳ��ϥե饰 (TABSR)
 */
#define TBIT_TABSR_TA0S	0x01

/*
 *  ���åץ�����ե饰(UDF)
 */
#define TBIT_UDF_TA0UD	0x01


/*
 *  �ݡ��ȣ�����
 */
#define	P7_LED1					0x10			/* LED1�ӥå���� */
#define	P7_LED2					0x20			/* LED2�ӥå���� */

#ifndef _MACRO_ONLY

#include "cpu_defs.h"

/*
 *  �������åȥ����ƥ��ʸ������
 */

Inline void
oaks16_putc(char c)
{
	volatile char * p = (volatile char *)TADR_SFR_UART1_BASE;

	while((p[TADR_SFR_UC1_OFFSET] & TBIT_UiC1_TI) == 0);
	p[TADR_SFR_UTB_OFFSET] = c;
}

#endif /* _MACRO_ONLY */
#endif /* _OAKS16_H_ */

