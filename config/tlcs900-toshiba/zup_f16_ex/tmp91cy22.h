/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2010 by Witz Corporation, JAPAN
 * 
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 * 
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 * 
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 * 
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 * 
 *    (a) The above copyright notice, this use conditions, and the
 *           disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 * 
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 * 
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�
 *  �����ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭�����
 *      ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ�����
 *      ��������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ����Ѽԥ�
 *      �˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ�����̵��
 *      �ڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ���
 *        �𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»��
 *      ����⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ��ޤ���
 *      �ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���ͳ�˴��
 *      �����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ���
 *  ��TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū���Ф�
 *  ��Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ�����������
 *  �ˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ����
 *  ��ʤ���
 * 
 *  @(#) $Id: tmp91cy22.h,v 1.1 2006/04/10 08:19:25 honda Exp $
 */

/*
 *  �ü쵡ǽ�쥸������Ϣ�������TMP91CY22�ѡ�
 */

#ifndef _TMP91CY22_H_
#define _TMP91CY22_H_

/*
 *  ������ֹ�����
 */
#define		INT_NO_RST_SW0		1	/* �ꥻ�å�/SWI 0 ̿��				*/
#define		INT_NO_SW1			2	/* SWI 1 ̿��						*/
#define		INT_NO_UNDEF_SW2	3	/* ̤���̿��¹԰�ȿ/SWI 2 ̿��	*/
#define		INT_NO_SW3			4	/* SWI 3 ̿��						*/
#define		INT_NO_SW4			5	/* SWI 4 ̿��						*/
#define		INT_NO_SW5			6	/* SWI 5 ̿��						*/
#define		INT_NO_SW6			7	/* SWI 6 ̿��						*/
#define		INT_NO_SW7			8	/* SWI 7 ̿��						*/
#define		INT_NO_NMI			9	/* NMI								*/
#define		INT_NO_WD			10	/* �����å��ɥå�������				*/
#define		INT_NO_0			11	/* INT0								*/
#define		INT_NO_1			12	/* INT1								*/
#define		INT_NO_2			13	/* INT2								*/
#define		INT_NO_3			14	/* INT3								*/
#define		INT_NO_4			15	/* INT4								*/
#define		INT_NO_5			16	/* INT5								*/
#define		INT_NO_6			17	/* INT6								*/
#define		INT_NO_7			18	/* INT7								*/
#define		INT_NO_8			19	/* INT8								*/
#define		INT_NO_TA0			20	/* 8�ӥåȥ�����0					*/
#define		INT_NO_TA1			21	/* 8�ӥåȥ�����1					*/
#define		INT_NO_TA2			22	/* 8�ӥåȥ�����2					*/
#define		INT_NO_TA3			23	/* 8�ӥåȥ�����3					*/
#define		INT_NO_TA4			24	/* 8�ӥåȥ�����4					*/
#define		INT_NO_TA5			25	/* 8�ӥåȥ�����5					*/
#define		INT_NO_TA6			26	/* 8�ӥåȥ�����6					*/
#define		INT_NO_TA7			27	/* 8�ӥåȥ�����7					*/
#define		INT_NO_TB00			28	/* 16�ӥåȥ�����00					*/
#define		INT_NO_TB01			29	/* 16�ӥåȥ�����01					*/
#define		INT_NO_TB10			30	/* 16�ӥåȥ�����10					*/
#define		INT_NO_TB11			31	/* 16�ӥåȥ�����11					*/
#define		INT_NO_TBOF0		32	/* 16�ӥåȥ�����0�����С��ե�	*/
#define		INT_NO_TBOF1		33	/* 16�ӥåȥ�����1�����С��ե�	*/
#define		INT_NO_RX0			34	/* ���ꥢ�����0					*/
#define		INT_NO_TX0			35	/* ���ꥢ������0					*/
#define		INT_NO_RX1			36	/* ���ꥢ�����1					*/
#define		INT_NO_TX1			37	/* ���ꥢ������1					*/
#define		INT_NO_SBI			38	/* ���ꥢ��Х����󥿥ե�����		*/
#define		INT_NO_RTC			39	/* �����ѥ�����						*/
#define		INT_NO_AD			40	/* AD�Ѵ���λ						*/
#define		INT_NO_TC0			41	/* �ޥ�����DMA��λ0					*/
#define		INT_NO_TC1			42	/* �ޥ�����DMA��λ1					*/
#define		INT_NO_TC2			43	/* �ޥ�����DMA��λ2					*/
#define		INT_NO_TC3			44	/* �ޥ�����DMA��λ3					*/

/*
 *  SFR���ɥ쥹���
 */
/*
 *  �ݡ��ȥ쥸����
 */
#define		TADR_SFR_P0				0x0000
#define		TADR_SFR_P1				0x0001
#define		TADR_SFR_P0CR			0x0002
#define		TADR_SFR_P1CR			0x0004
#define		TADR_SFR_P1FC			0x0005
#define		TADR_SFR_P2				0x0006
#define		TADR_SFR_P3				0x0007
#define		TADR_SFR_P2CR			0x0008
#define		TADR_SFR_P2FC			0x0009
#define		TADR_SFR_P3CR			0x000a
#define		TADR_SFR_P3FC			0x000b
#define		TADR_SFR_P4				0x000c
#define		TADR_SFR_P5				0x000d
#define		TADR_SFR_P4CR			0x000e
#define		TADR_SFR_P4FC			0x000f
#define		TADR_SFR_P6				0x0012
#define		TADR_SFR_P7				0x0013
#define		TADR_SFR_P6CR			0x0014
#define		TADR_SFR_P6FC			0x0015
#define		TADR_SFR_P7CR			0x0016
#define		TADR_SFR_P7FC			0x0017
#define		TADR_SFR_P8				0x0018
#define		TADR_SFR_P9				0x0019
#define		TADR_SFR_P8CR			0x001a
#define		TADR_SFR_P8FC			0x001b
#define		TADR_SFR_P9CR			0x001c
#define		TADR_SFR_P9FC			0x001d
#define		TADR_SFR_PA				0x001e
#define		TADR_SFR_PACR			0x0020
#define		TADR_SFR_PAFC			0x0021
#define		TADR_SFR_ODE			0x002f

/*
 *  ����ߥ쥸����
 */
#define		TADR_SFR_DMA0V			0x0080
#define		TADR_SFR_DMA1V			0x0081
#define		TADR_SFR_DMA2V			0x0082
#define		TADR_SFR_DMA3V			0x0083
#define		TADR_SFR_INTCLR			0x0088
#define		TADR_SFR_DMAR			0x0089
#define		TADR_SFR_DMAB			0x008a
#define		TADR_SFR_IIMC			0x008c
#define		TADR_SFR_INTE0AD		0x0090
#define		TADR_SFR_INTE12			0x0091
#define		TADR_SFR_INTE34			0x0092
#define		TADR_SFR_INTE56			0x0093
#define		TADR_SFR_INTE78			0x0094
#define		TADR_SFR_INTETA01		0x0095
#define		TADR_SFR_INTETA23		0x0096
#define		TADR_SFR_INTETA45		0x0097
#define		TADR_SFR_INTETA67		0x0098
#define		TADR_SFR_INTETB0		0x0099
#define		TADR_SFR_INTETB1		0x009a
#define		TADR_SFR_INTETB01V		0x009b
#define		TADR_SFR_INTES0			0x009c
#define		TADR_SFR_INTES1			0x009d
#define		TADR_SFR_INTSBIRTC		0x009e
#define		TADR_SFR_INTETC01		0x00a0
#define		TADR_SFR_INTETC23		0x00a1

/*
 *  ���åץ��쥯��/�������ȥ���ȥ���쥸����
 */
#define		TADR_SFR_B0CS			0x00c0
#define		TADR_SFR_B1CS			0x00c1
#define		TADR_SFR_B2CS			0x00c2
#define		TADR_SFR_B3CS			0x00c3
#define		TADR_SFR_BEXCS			0x00c7
#define		TADR_SFR_MSAR0			0x00c8
#define		TADR_SFR_MAMR0			0x00c9
#define		TADR_SFR_MSAR1			0x00ca
#define		TADR_SFR_MAMR1			0x00cb
#define		TADR_SFR_MSAR2			0x00cc
#define		TADR_SFR_MAMR2			0x00cd
#define		TADR_SFR_MSAR3			0x00ce
#define		TADR_SFR_MAMR3			0x00cf

/*
 *  ����å�����/����å����ܲ�ϩ�쥸����
 */
#define		TADR_SFR_SYSCR0			0x00e0
#define		TADR_SFR_SYSCR1			0x00e1
#define		TADR_SFR_SYSCR2			0x00e2
#define		TADR_SFR_EMCCR0			0x00e3
#define		TADR_SFR_EMCCR1			0x00e4
#define		TADR_SFR_DFMCR0			0x00e8
#define		TADR_SFR_DFMCR1			0x00e9

/*
 *  8bit������A�쥸����
 */
#define		TADR_SFR_TA01RUN		0x0100
#define		TADR_SFR_TA0REG			0x0102
#define		TADR_SFR_TA1REG			0x0103
#define		TADR_SFR_TA01MOD		0x0104
#define		TADR_SFR_TA1FFCR		0x0105
#define		TADR_SFR_TA23RUN		0x0108
#define		TADR_SFR_TA2REG			0x010a
#define		TADR_SFR_TA3REG			0x010b
#define		TADR_SFR_TA23MOD		0x010c
#define		TADR_SFR_TA3FFCR		0x010d
#define		TADR_SFR_TA45RUN		0x0110
#define		TADR_SFR_TA4REG			0x0112
#define		TADR_SFR_TA5REG			0x0113
#define		TADR_SFR_TA45MOD		0x0114
#define		TADR_SFR_TA5FFCR		0x0115
#define		TADR_SFR_TA67RUN		0x0118
#define		TADR_SFR_TA6REG			0x011a
#define		TADR_SFR_TA7REG			0x011b
#define		TADR_SFR_TA67MOD		0x011c
#define		TADR_SFR_TA7FFCR		0x011d

/*
 *  16bit������B�쥸����
 */
#define		TADR_SFR_TB0RUN			0x0180
#define		TADR_SFR_TB0MOD			0x0182
#define		TADR_SFR_TB0FFCR		0x0183
#define		TADR_SFR_TB0RG0L		0x0188
#define		TADR_SFR_TB0RG0H		0x0189
#define		TADR_SFR_TB0RG1L		0x018a
#define		TADR_SFR_TB0RG1H		0x018b
#define		TADR_SFR_TB0CP0L		0x018c
#define		TADR_SFR_TB0CP0H		0x018d
#define		TADR_SFR_TB0CP1L		0x018e
#define		TADR_SFR_TB0CP1H		0x018f
#define		TADR_SFR_TB1RUN			0x0190
#define		TADR_SFR_TB1MOD			0x0192
#define		TADR_SFR_TB1FFCR		0x0193
#define		TADR_SFR_TB1RG0L		0x0198
#define		TADR_SFR_TB1RG0H		0x0199
#define		TADR_SFR_TB1RG1L		0x019a
#define		TADR_SFR_TB1RG1H		0x019b
#define		TADR_SFR_TB1CP0L		0x019c
#define		TADR_SFR_TB1CP0H		0x019d
#define		TADR_SFR_TB1CP1L		0x019e
#define		TADR_SFR_TB1CP1H		0x019f

/*
 *  ���ꥢ��I/O(UART/I2C�Х�/SIO)�쥸����
 */
#define		TADR_SFR_SC0BUF			0x0200
#define		TADR_SFR_SC0CR			0x0201
#define		TADR_SFR_SC0MOD0		0x0202
#define		TADR_SFR_BR0CR			0x0203
#define		TADR_SFR_BR0ADD			0x0204
#define		TADR_SFR_SC0MOD1		0x0205
#define		TADR_SFR_SIRCR			0x0207
#define		TADR_SFR_SC1BUF			0x0208
#define		TADR_SFR_SC1CR			0x0209
#define		TADR_SFR_SC1MOD0		0x020a
#define		TADR_SFR_BR1CR			0x020b
#define		TADR_SFR_BR1ADD			0x020c
#define		TADR_SFR_SC1MOD1		0x020d
#define		TADR_SFR_SBI0CR1		0x0240
#define		TADR_SFR_SBI0DBR		0x0241
#define		TADR_SFR_I2C0AR			0x0242
#define		TADR_SFR_SBI0CR2		0x0243
#define		TADR_SFR_SBI0BR0		0x0244
#define		TADR_SFR_SBI0BR1		0x0245

/*
 *  10�ӥå�ADC�쥸����
 */
#define		TADR_SFR_ADREG04L		0x02a0
#define		TADR_SFR_ADREG04H		0x02a1
#define		TADR_SFR_ADREG15L		0x02a2
#define		TADR_SFR_ADREG15H		0x02a3
#define		TADR_SFR_ADREG26L		0x02a4
#define		TADR_SFR_ADREG26H		0x02a5
#define		TADR_SFR_ADREG37L		0x02a6
#define		TADR_SFR_ADREG37H		0x02a7
#define		TADR_SFR_ADMOD0			0x02b0
#define		TADR_SFR_ADMOD1			0x02b1

/*
 *  �����å��ɥå������ޥ쥸����
 */
#define		TADR_SFR_WDMOD			0x0300
#define		TADR_SFR_WDCR			0x0301

/*
 *  �����ѥ����ޥ쥸����
 */
#define		TADR_SFR_RTCCR			0x0310

/*
 *  SFRbit�ޥ������
 */
/*
 *  ����ߥ쥸����
 */
/* ͥ��������쥸����	*/
#define		TBIT_INTM_L			0x07
#define		TBIT_INTC_L			0x08
#define		TBIT_INTM_H			0x70
#define		TBIT_INTC_H			0x80
/* ����ߥ��ꥢ����쥸����	*/
/* ���ꥢ�٥���(�ޥ�����DMA��ư�٥���)	*/
#define		TBIT_INT0_CLR		0x0a	/* INT0								*/
#define		TBIT_INT1_CLR		0x0b	/* INT1								*/
#define		TBIT_INT2_CLR		0x0c	/* INT2								*/
#define		TBIT_INT3_CLR		0x0d	/* INT3								*/
#define		TBIT_INT4_CLR		0x0e	/* INT4								*/
#define		TBIT_INT5_CLR		0x0f	/* INT5								*/
#define		TBIT_INT6_CLR		0x10	/* INT6								*/
#define		TBIT_INT7_CLR		0x11	/* INT7								*/
#define		TBIT_INT8_CLR		0x12	/* INT8								*/
#define		TBIT_TA0_CLR		0x13	/* 8�ӥåȥ�����0					*/
#define		TBIT_TA1_CLR		0x14	/* 8�ӥåȥ�����1					*/
#define		TBIT_TA2_CLR		0x15	/* 8�ӥåȥ�����2					*/
#define		TBIT_TA3_CLR		0x16	/* 8�ӥåȥ�����3					*/
#define		TBIT_TA4_CLR		0x17	/* 8�ӥåȥ�����4					*/
#define		TBIT_TA5_CLR		0x18	/* 8�ӥåȥ�����5					*/
#define		TBIT_TA6_CLR		0x19	/* 8�ӥåȥ�����6					*/
#define		TBIT_TA7_CLR		0x1a	/* 8�ӥåȥ�����7					*/
#define		TBIT_TB00_CLR		0x1b	/* 16�ӥåȥ�����00					*/
#define		TBIT_TB01_CLR		0x1c	/* 16�ӥåȥ�����01					*/
#define		TBIT_TB10_CLR		0x1d	/* 16�ӥåȥ�����10					*/
#define		TBIT_TB11_CLR		0x1e	/* 16�ӥåȥ�����11					*/
#define		TBIT_TBOF0_CLR		0x1f	/* 16�ӥåȥ�����0�����С��ե�	*/
#define		TBIT_TBOF1_CLR		0x20	/* 16�ӥåȥ�����1�����С��ե�	*/
#define		TBIT_RX0_CLR		0x21	/* ���ꥢ�����0					*/
#define		TBIT_TX0_CLR		0x22	/* ���ꥢ������0					*/
#define		TBIT_RX1_CLR		0x23	/* ���ꥢ�����1					*/
#define		TBIT_TX1_CLR		0x24	/* ���ꥢ������1					*/
#define		TBIT_SBI_CLR		0x25	/* ���ꥢ��Х����󥿥ե�����		*/
#define		TBIT_RTC_CLR		0x26	/* �����ѥ�����						*/
#define		TBIT_AD_CLR			0x27	/* AD�Ѵ���λ						*/

/*
 *  8bit�����ޥ쥸����
 */
/* RUN�쥸����	*/
#define		TBIT_TA0RUN			0x01
#define		TBIT_TA1RUN			0x02
#define		TBIT_TA01PRUN		0x04
#define		TBIT_I2TA01			0x08
#define		TBIT_TA0RDE			0x80
/* �⡼�ɥ쥸����	*/
#define		TBIT_TA0CLK			0x03
#define		TBIT_TA0CLK0		0x00
#define		TBIT_TA0CLK1		0x01
#define		TBIT_TA0CLK4		0x02
#define		TBIT_TA0CLK16		0x03
#define		TBIT_TA1CLK			0x0c
#define		TBIT_TA1CLK0		0x00
#define		TBIT_TA1CLK1		0x04
#define		TBIT_TA1CLK16		0x08
#define		TBIT_TA1CLK256		0x0c
#define		TBIT_PWM			0x30
#define		TBIT_PWM26			0x10
#define		TBIT_PWM27			0x20
#define		TBIT_PWM28			0x30
#define		TBIT_TA01M			0xc0
#define		TBIT_TA01M8			0x00
#define		TBIT_TA01M16		0x40
#define		TBIT_TA01MPPG		0x80
#define		TBIT_TA01MPWM		0xc0

/*
 *  ���ꥢ��I/O�쥸����
 */
/* �⡼�ɥ쥸����0	*/
#define		TBIT_SIOSC			0x03
#define		TBIT_SIOSCT			0x00
#define		TBIT_SIOSCBRG		0x01
#define		TBIT_SIOSCFSYS		0x02
#define		TBIT_SIOSCSCLK		0x03
#define		TBIT_SIOSM			0x0c
#define		TBIT_SIOSMIO		0x00
#define		TBIT_SIOSMU7		0x04
#define		TBIT_SIOSMU8		0x08
#define		TBIT_SIOSMU9		0x0c
#define		TBIT_SIOWU			0x10
#define		TBIT_SIORXE			0x20
#define		TBIT_SIOCTSE		0x40
#define		TBIT_SIOTB8			0x80
/* ����쥸����	*/
#define		TBIT_SIOIOC			0x01
#define		TBIT_SIOSCLKS		0x02
#define		TBIT_SIOFERR		0x04
#define		TBIT_SIOPERR		0x08
#define		TBIT_SIOOERR		0x10
#define		TBIT_SIOPE			0x20
#define		TBIT_SIOEVEN		0x40
#define		TBIT_SIORB8			0x80
/* �ܡ��졼�ȥ���ȥ���	*/
#define		TBIT_SIOBRS			0x0f
#define		TBIT_SIOBRCK		0x30
#define		TBIT_SIOBRCK0		0x00
#define		TBIT_SIOBRCK2		0x10
#define		TBIT_SIOBRCK8		0x20
#define		TBIT_SIOBRCK32		0x30
#define		TBIT_SIOBRADD		0x40
#define		TBIT_SIOBRK			0x0f
/* �⡼�ɥ쥸����1	*/
#define		TBIT_SIOFDPX		0x40
#define		TBIT_SIOI2S			0x80

#endif	/* _TMP91CY22_H_	*/

