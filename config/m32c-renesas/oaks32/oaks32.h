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
 *  @(#) $Id: oaks32.h,v 1.3 2005/11/24 12:41:23 honda Exp $
 */

#ifndef _OAKS32_H_
#define	_OAKS32_H_

/*
 *  ������ֹ�����
 */
#define	INT_BRK		0		/* BRK */
#define INT_AD1		7		/* ��-���Ѵ���1 */
#define INT_DMA0	8		/* DMA0 */
#define INT_DMA1	9		/* DMA1 */
#define INT_DMA2	10		/* DMA2 */
#define INT_DMA3	11		/* DMA3 */
#define INT_TA0		12		/* ������A0 */
#define INT_TA1		13		/* ������A1 */
#define INT_TA2		14		/* ������A2 */
#define INT_TA3		15		/* ������A3 */
#define INT_TA4		16		/* ������A4 */
#define INT_S0TNACK	17		/* UART0����,NACK */
#define INT_S0RACK	18		/* UART0����,ACK */
#define INT_S1TNACK	19		/* UART1����,NACK */
#define INT_S1RACK	20		/* UART1����,ACK */
#define INT_TB0		21		/* ������B0 */
#define INT_TB1		22		/* ������B1 */
#define INT_TB2		23		/* ������B2 */
#define INT_TB3		24		/* ������B3 */
#define INT_TB4		25		/* ������B4 */
#define INT_INT5	26		/* INT5 */
#define INT_INT4	27		/* INT4 */
#define INT_INT3	28		/* INT3 */
#define INT_INT2	29		/* INT2 */
#define INT_INT1	30		/* INT1 */
#define INT_INT0	31		/* INT0 */
#define INT_TB5		32		/* ������B5 */
#define INT_S2TNACK 	33		/* UART2����,NACK */
#define INT_S2RACK 	34		/* UART2����,ACK */
#define INT_S3TNACK 	35		/* UART3����,NACK */
#define INT_S3RACK 	36		/* UART3����,ACK */
#define INT_S4TNACK 	37		/* UART4����,NACK */
#define INT_S4RACK 	38		/* UART4����,ACK */

#define INT_AD0		42		/* ��-���Ѵ���0 */
#define INT_KEY		43		/* �������ϳ����� */
#define INT_IIO0	44		/* ����ƥꥸ�����I/O�����0 */
#define INT_IIO1	45		/* ����ƥꥸ�����I/O�����1 */
#define INT_IIO2	46		/* ����ƥꥸ�����I/O�����2 */
#define INT_IIO3	47		/* ����ƥꥸ�����I/O�����3 */
#define INT_IIO4	48		/* ����ƥꥸ�����I/O�����4 */
#define INT_IIO5	49		/* ����ƥꥸ�����I/O�����5 */
#define INT_IIO6	50		/* ����ƥꥸ�����I/O�����6 */
#define INT_IIO7	51		/* ����ƥꥸ�����I/O�����7 */
#define INT_IIO8	52		/* ����ƥꥸ�����I/O�����8 */
#define INT_IIO9CAN0	53		/* ����ƥꥸ�����I/O�����9,CAN0 */
#define INT_IIO10CAN1	54		/* ����ƥꥸ�����I/O�����10,CAN1 */
#define INT_IIO11CAN2	57		/* ����ƥꥸ�����I/O�����11,CAN2 */

/*
 *  OAKS32 SFR���ɥ쥹���
 *
 *  ����ߥ쥸����
 */
#define	TADR_SFR_INT_BASE       0x60			/* ����ߴ�Ϣ�Υ١������ɥ쥹 */
#define TADR_SFR_DM0IC_OFFSET  8				/* DMA0���������쥸���� */
#define TADR_SFR_TB5IC_OFFSET   9				/* timerB5 ���������쥸���� */
#define TADR_SFR_DMA2IC_OFFSET  10				/* DMA2���������쥸���� */
#define	TADR_SFR_S2RIC_OFFSET   11				/* uart2�������������쥸���� */
#define	TADR_SFR_TA0IC_OFFSET   12				/* timerA0 ���������쥸���� */
#define	TADR_SFR_S3RIC_OFFSET   13				/* uart3�������������쥸���� */
#define TADR_SFR_TA2IC_OFFSET   14				/* timerA2 ���������쥸���� */
#define	TADR_SFR_S4RIC_OFFSET   15				/* uart4�������������쥸���� */
#define TADR_SFR_TA4IC_OFFSET   16				/* timerA4 ���������쥸���� */
#define TADR_SFR_BCN0IC_OFFSET  17				/* UART0�Х����͸��г��������쥸���� */
#define TADR_SFR_BCN3IC_OFFSET  17				/* UART3�Х����͸��г��������쥸���� */
#define	TADR_SFR_S0RIC_OFFSET   18				/* uart0�������������쥸���� */
#define TADR_SFR_AD0IC_OFFSET   19				/* A-D0�Ѵ����������쥸���� */
#define	TADR_SFR_S1RIC_OFFSET   20				/* uart1�������������쥸���� */
#define TADR_SFR_IIO0IC_OFFSET  21				/* ����ƥꥸ�����I/O���������쥸����0 */
#define TADR_SFR_TB1IC_OFFSET   22				/* timerB1 ���������쥸���� */
#define TADR_SFR_IIO2IC_OFFSET  23				/* ����ƥꥸ�����I/O���������쥸����2 */
#define TADR_SFR_TB3IC_OFFSET   24				/* timerB3 ���������쥸���� */
#define TADR_SFR_IIO4IC_OFFSET  25				/* ����ƥꥸ�����I/O���������쥸����4 */
#define TADR_SFR_INT5IC_OFFSET  26				/* SI/O4/INT5 ���������쥸���� */
#define TADR_SFR_IIO6IC_OFFSET  27				/* ����ƥꥸ�����I/O���������쥸����6 */
#define TADR_SFR_INT3IC_OFFSET  28				/* INT3 ���������쥸���� */
#define TADR_SFR_IIO8IC_OFFSET  29				/* ����ƥꥸ�����I/O���������쥸����8 */
#define TADR_SFR_INT1IC_OFFSET  30				/* INT1 ���������쥸���� */
#define TADR_SFR_IIO10IC_OFFSET 31				/* ����ƥꥸ�����I/O���������쥸����10 */
#define TADR_SFR_CAN1IC_OFFSET  31				/* CAN�����1����쥸���� */
#define TADR_SFR_IIO11IC_OFFSET 33				/* ����ƥꥸ�����I/O���������쥸����11 */
#define TADR_SFR_CAN2IC_OFFSET  33				/* CAN�����2����쥸���� */
#define TADR_SFR_AD1IC_OFFSET   38				/* A-D1�Ѵ����������쥸���� */
#define TADR_SFR_DM1IC_OFFSET   40				/* DMA1���������쥸���� */
#define	TADR_SFR_S2TIC_OFFSET   41				/* uart2�������������쥸���� */
#define TADR_SFR_DM3IC_OFFSET   42				/* DMA3���������쥸���� */
#define	TADR_SFR_S3TIC_OFFSET   43				/* uart3�������������쥸���� */
#define TADR_SFR_TA1IC_OFFSET   44				/* timerA1 ���������쥸���� */
#define	TADR_SFR_S4TIC_OFFSET   45				/* uart4�������������쥸���� */
#define TADR_SFR_TA3IC_OFFSET   46				/* timerA3 ���������쥸���� */
#define TADR_SFR_BCN2IC_OFFSET  47				/* UART2�Х����͸��г��������쥸���� */
#define	TADR_SFR_S0TIC_OFFSET   48				/* uart0�������������쥸���� */
#define TADR_SFR_BCN1IC_OFFSET  49				/* UART1�Х����͸��г��������쥸���� */
#define TADR_SFR_BCN4IC_OFFSET  49				/* UART4�Х����͸��г��������쥸���� */
#define	TADR_SFR_S1TIC_OFFSET   50				/* uart1�������������쥸���� */
#define TADR_SFR_KUPIC_OFFSET   51				/* �������ϳ��������쥸���� */
#define TADR_SFR_TB0IC_OFFSET   52				/* timerB0 ���������쥸���� */
#define TADR_SFR_IIO1IC_OFFSET  53				/* ����ƥꥸ�����I/O���������쥸����1 */
#define TADR_SFR_TB2IC_OFFSET   54				/* timerB2 ���������쥸���� */
#define TADR_SFR_IIO3IC_OFFSET  55				/* ����ƥꥸ�����I/O���������쥸����3 */
#define TADR_SFR_TB4IC_OFFSET   56				/* timerB4 ���������쥸���� */
#define TADR_SFR_IIO5IC_OFFSET  57				/* ����ƥꥸ�����I/O���������쥸����5 */
#define TADR_SFR_INT4IC_OFFSET  58				/* INT4 ���������쥸���� */
#define TADR_SFR_IIO7IC_OFFSET  59				/* ����ƥꥸ�����I/O���������쥸����7 */
#define TADR_SFR_INT2IC_OFFSET  60				/* INT2 ���������쥸���� */
#define TADR_SFR_IIO9IC_OFFSET  61				/* ����ƥꥸ�����I/O���������쥸����9 */
#define TADR_SFR_CAN0IC_OFFSET  61				/* CAN�����0����쥸���� */
#define TADR_SFR_INT0IC_OFFSET  62				/* INT0 ���������쥸���� */

/*
 *  �����ޡ��쥸����
 */
#define TADR_SFR_TBSR           0x300			/* timerB3,4,5������ȳ��ϥե饰 */
#define TADR_SFR_TA11           0x302			/* timerA1-1�쥸���� */
#define TADR_SFR_TA21           0x304			/* timerA2-1�쥸���� */
#define TADR_SFR_TA41           0x306			/* timerA4-1�쥸���� */
#define TADR_SFR_INVC0          0x308			/* ����PWM����쥸������ */
#define TADR_SFR_INVC1          0x309			/* ����PWM����쥸������ */
#define TADR_SFR_IDB0           0x30a			/* ������ϥХåե��쥸������ */
#define TADR_SFR_IDB1           0x30b			/* ������ϥХåե��쥸������ */
#define TADR_SFR_DTT            0x30c			/* û���ɻߥ����� */
#define TADR_SFR_ICTB2          0x30d			/* timerB2�����ȯ���������ꥫ���� */
#define TADR_SFR_TB3            0x310			/* timerB3�쥸���� */
#define TADR_SFR_TB4            0x312			/* timerB4�쥸���� */
#define TADR_SFR_TB5            0x314			/* timerB5�쥸���� */
#define	TADR_SFR_TB3MR          0x31b			/* timerB3�⡼�ɥ쥸���� */
#define	TADR_SFR_TB4MR          0x31c			/* timerB4�⡼�ɥ쥸���� */
#define	TADR_SFR_TB5MR          0x31d			/* timerB5�⡼�ɥ쥸���� */
#define TADR_SFR_IFSR           0x31f			/* ������װ�����쥸���� */

#define	TADR_SFR_TABSR          0x340			/* ������ȳ��ϥե饰 */
#define TADR_SFR_CPSRF          0x341			/* �ꥻ�å� �ץꥹ������ �ꥻ�åȥե饰 */
#define TADR_SFR_ONSF           0x342			/* ��󥷥�� �������ȥե饰 */
#define TADR_SFR_TRGSR          0x343			/* �ȥꥬ�����쥯�� �쥸���� */
#define	TADR_SFR_UDF            0x344			/* ���åץ�����ե饰 */
#define	TADR_SFR_TA0            0x346			/* timerA0�쥸���� */
#define TADR_SFR_TA1            0x348			/* timerA1�쥸���� */
#define TADR_SFR_TA2            0x34a			/* timerA2�쥸���� */
#define TADR_SFR_TA3            0x34c			/* timerA3�쥸���� */
#define TADR_SFR_TA4            0x34e			/* timerA4�쥸���� */
#define TADR_SFR_TB0            0x350			/* timerB0�쥸���� */
#define TADR_SFR_TB1            0x352			/* timerB1�쥸���� */
#define TADR_SFR_TB2            0x354			/* timerB2�쥸���� */
#define	TADR_SFR_TA0MR          0x356			/* timerA0�⡼�ɥ쥸���� */
#define	TADR_SFR_TA1MR          0x357			/* timerA1�⡼�ɥ쥸���� */
#define	TADR_SFR_TA2MR          0x358			/* timerA2�⡼�ɥ쥸���� */
#define	TADR_SFR_TA3MR          0x359			/* timerA3�⡼�ɥ쥸���� */
#define	TADR_SFR_TA4MR          0x35a			/* timerA4�⡼�ɥ쥸���� */
#define	TADR_SFR_TB0MR          0x35b			/* timerB0�⡼�ɥ쥸���� */
#define	TADR_SFR_TB1MR		0x35c			/* timerB1�⡼�ɥ쥸���� */
#define	TADR_SFR_TB2MR          0x35d			/* timerB2�⡼�ɥ쥸���� */
#define	TADR_SFR_TB2SC          0x35e			/* timerB2���ڥ����⡼�ɥ쥸���� */
#define TADR_SFR_TCSPR          0x35f			/* ������ȥ������ץꥹ������쥸���� */

/*
 *  ���ꥢ��쥸����
 */
#define	TADR_SFR_UART0_BASE     0x360			/* uart0�쥸�����١������ɥ쥹 */
#define	TADR_SFR_UART1_BASE     0x2e0			/* uart1�쥸�����١������ɥ쥹 */
#define	TADR_SFR_UART2_BASE     0x330			/* uart2�쥸�����١������ɥ쥹 */
#define	TADR_SFR_UART3_BASE     0x320			/* uart3�쥸�����١������ɥ쥹 */
#define	TADR_SFR_UART4_BASE     0x2f0			/* uart4�쥸�����١������ɥ쥹 */

#define	TADR_SFR_USMR_OFFSET    7			/* �ü�⡼�ɥ쥸���� */
#define	TADR_SFR_USMR2_OFFSET   6			/* �ü�⡼�ɥ쥸����2 */
#define	TADR_SFR_USMR3_OFFSET   5			/* �ü�⡼�ɥ쥸����3 */
#define	TADR_SFR_USMR4_OFFSET   4			/* �ü�⡼�ɥ쥸����4 */

#define	TADR_SFR_UMR_OFFSET     8			/* uart�������⡼�ɥ쥸���� */
#define	TADR_SFR_UBRG_OFFSET    9			/* uart�ܡ��졼�ȥ����ͥ졼�� */
#define	TADR_SFR_UTB_OFFSET     10			/* uart�����Хåե��쥸���� */
#define	TADR_SFR_UC0_OFFSET     12			/* uart����������쥸����#0 */
#define	TADR_SFR_UC1_OFFSET     13			/* uart����������쥸����#1 */
#define	TADR_SFR_URB_OFFSET     14			/* uart�����Хåե��쥸���� */

/*
 *  A-D/D-A�쥸����
 */
#define TADR_SFR_AD00            0x380			/* A-D�쥸������ */
#define TADR_SFR_AD01            0x382			/* A-D�쥸������ */
#define TADR_SFR_AD02            0x384			/* A-D�쥸������ */
#define TADR_SFR_AD03            0x386			/* A-D�쥸������ */
#define TADR_SFR_AD04            0x388			/* A-D�쥸������ */
#define TADR_SFR_AD05            0x38a			/* A-D�쥸������ */
#define TADR_SFR_AD06            0x38c			/* A-D�쥸������ */
#define TADR_SFR_AD07            0x38e			/* A-D�쥸������ */
#define TADR_SFR_AD0CON2         0x394			/* A-D����쥸������ */
#define TADR_SFR_AD0CON0         0x396			/* A-D����쥸������ */
#define TADR_SFR_AD0CON1         0x397			/* A-D����쥸������ */

#define TADR_SFR_AD10            0x1c0			/* A-D�쥸������ */
#define TADR_SFR_AD11            0x1c2			/* A-D�쥸������ */
#define TADR_SFR_AD12            0x1c4			/* A-D�쥸������ */
#define TADR_SFR_AD13            0x1c6			/* A-D�쥸������ */
#define TADR_SFR_AD14            0x1c8			/* A-D�쥸������ */
#define TADR_SFR_AD15            0x1ca			/* A-D�쥸������ */
#define TADR_SFR_AD16            0x1cc			/* A-D�쥸������ */
#define TADR_SFR_AD17            0x1ce			/* A-D�쥸������ */
#define TADR_SFR_AD1CON2         0x1d4			/* A-D����쥸������ */
#define TADR_SFR_AD1CON0         0x1d6			/* A-D����쥸������ */
#define TADR_SFR_AD1CON1         0x1d7			/* A-D����쥸������ */

#define TADR_SFR_DA0            0x398			/* D-A�쥸������ */
#define TADR_SFR_DA1            0x39a			/* D-A�쥸������ */
#define TADR_SFR_DACON          0x39c			/* D-A����쥸���� */

/*
 *  ���ѥݡ��ȥ쥸����(������144�ԥ��ǤΤ�)
 */
#define TADR_SFR_P0             0x3e0           /* �ݡ���P0�쥸���� */
#define TADR_SFR_P1             0x3e1           /* �ݡ���P1�쥸���� */
#define TADR_SFR_PD0            0x3e2		/* �ݡ���P0�����쥸���� */
#define TADR_SFR_PD1            0x3e3		/* �ݡ���P1�����쥸���� */
#define TADR_SFR_P2             0x3e4		/* �ݡ���P2�쥸���� */
#define TADR_SFR_P3             0x3e5		/* �ݡ���P3�쥸���� */
#define	TADR_SFR_PD2            0x3e6		/* �ݡ���P2�����쥸���� */
#define	TADR_SFR_PD3            0x3e7		/* �ݡ���P3�����쥸���� */
#define TADR_SFR_P4             0x3e8		/* �ݡ���P4�쥸���� */
#define	TADR_SFR_P5             0x3e9		/* �ݡ���P5�쥸���� */
#define	TADR_SFR_PD4            0x3ea		/* �ݡ���P4�����쥸���� */
#define	TADR_SFR_PD5            0x3eb		/* �ݡ���P5�����쥸���� */
#define TADR_SFR_P6             0x3c0		/* �ݡ���P6�쥸���� */
#define	TADR_SFR_P7             0x3c1		/* �ݡ���P7�쥸���� */
#define	TADR_SFR_PD6            0x3c2		/* �ݡ���P6�����쥸���� */
#define	TADR_SFR_PD7            0x3c3		/* �ݡ���P7�����쥸���� */
#define	TADR_SFR_P8             0x3c4		/* �ݡ���P8�쥸���� */
#define TADR_SFR_P9             0x3c5		/* �ݡ���P9�쥸���� */
#define	TADR_SFR_PD8            0x3c6		/* �ݡ���P8�����쥸���� */
#define TADR_SFR_PD9            0x3c7		/* �ݡ���P9�����쥸���� */
#define TADR_SFR_P10            0x3c8		/* �ݡ���P10�쥸���� */
#define TADR_SFR_P11            0x3c9		/* �ݡ���P11�쥸����(144�ԥ��ǤΤ�) */
#define TADR_SFR_PD10           0x3ca		/* �ݡ���P10�����쥸���� */
#define TADR_SFR_PD11           0x3cb		/* �ݡ���P11�����쥸����(144�ԥ��ǤΤ�) */
#define TADR_SFR_P12            0x3cc		/* �ݡ���P12�쥸����(144�ԥ��ǤΤ�) */
#define TADR_SFR_P13            0x3cd		/* �ݡ���P13�쥸����(144�ԥ��ǤΤ�) */
#define TADR_SFR_PD12           0x3ce		/* �ݡ���P12�����쥸����(144�ԥ��ǤΤ�) */
#define TADR_SFR_PD13           0x3cf		/* �ݡ���P13�����쥸����(144�ԥ��ǤΤ�) */
#define TADR_SFR_P14            0x3d0		/* �ݡ���P14�쥸����(144�ԥ��ǤΤ�) */
#define TADR_SFR_P15            0x3d1		/* �ݡ���P15�쥸����(144�ԥ��ǤΤ�) */
#define TADR_SFR_PD14           0x3d2		/* �ݡ���P14�����쥸����(144�ԥ��ǤΤ�) */
#define TADR_SFR_PD15           0x3d3		/* �ݡ���P15�����쥸����(144�ԥ��ǤΤ�) */

#define	TADR_SFR_PUR0           0x3f0		/* �ץ륢�å�����쥸������ */
#define	TADR_SFR_PUR1           0x3f1		/* �ץ륢�å�����쥸������ */
#define	TADR_SFR_PUR2           0x3da		/* �ץ륢�å�����쥸������ */
#define	TADR_SFR_PUR3           0x3db		/* �ץ륢�å�����쥸������ */
#define	TADR_SFR_PUR4           0x3dc		/* �ץ륢�å�����쥸������(144�ԥ��ǤΤ�) */

#define	TADR_SFR_PCR            0x3ff		/* �ݡ�������쥸���� */

#define TADR_SFR_PS0            0x3b0		/* ��ǽ����쥸����A0 */
#define TADR_SFR_PS1            0x3b1		/* ��ǽ����쥸����A1 */
#define TADR_SFR_PS2            0x3b4		/* ��ǽ����쥸����A2 */
#define TADR_SFR_PS3            0x3b5		/* ��ǽ����쥸����A3 */
#define TADR_SFR_PS5            0x3b9		/* ��ǽ����쥸����A5(144�ԥ��ǤΤ�) */
#define TADR_SFR_PS6            0x3bc		/* ��ǽ����쥸����A6(144�ԥ��ǤΤ�) */
#define TADR_SFR_PS7            0x3bd		/* ��ǽ����쥸����A7(144�ԥ��ǤΤ�) */
#define TADR_SFR_PS8            0x3a0		/* ��ǽ����쥸����A8(144�ԥ��ǤΤ�) */
#define TADR_SFR_PS9            0x3a1		/* ��ǽ����쥸����A9(144�ԥ��ǤΤ�) */

#define TADR_SFR_PSL0           0x3b2		/* ��ǽ����쥸����B0 */
#define TADR_SFR_PSL1           0x3b3		/* ��ǽ����쥸����B1 */
#define TADR_SFR_PSL2           0x3b6		/* ��ǽ����쥸����B2 */
#define TADR_SFR_PSL3           0x3b7		/* ��ǽ����쥸����B3 */

#define TADR_SFR_PSC            0x3af		/* ��ǽ����쥸����C */


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
//#define	P7_LED1					0x10			/* LED1�ӥå���� */
//#define	P7_LED2					0x20			/* LED2�ӥå���� */

#ifndef _MACRO_ONLY

#include "cpu_defs.h"

/*
 *  �������åȥ����ƥ��ʸ������
 */

Inline void
oaks32_putc(char c)
{
	char enabled;
	volatile char * p = (volatile char *)TADR_SFR_UART0_BASE;

	/* �������Ĥ���Ƥ��ʤ���е��Ĥ��� */
	enabled = p[TADR_SFR_UC1_OFFSET] & TBIT_UiC1_TE;
	if(!enabled) {
		p[TADR_SFR_UC1_OFFSET] |= TBIT_UiC1_TE;
	}

	/* �����Хåե������ˤʤ�ޤ��Ԥ�(ͭ�»�����ξ����Ω����) */
	while((p[TADR_SFR_UC1_OFFSET] & TBIT_UiC1_TI) == 0);

	/* 1ʸ������ */
	p[TADR_SFR_UTB_OFFSET] = c;

	if(!enabled) {
		p[TADR_SFR_UC1_OFFSET] &= ~TBIT_UiC1_TE;
	}
}

#endif /* _MACRO_ONLY */
#endif /* _OAKS32_H_ */

