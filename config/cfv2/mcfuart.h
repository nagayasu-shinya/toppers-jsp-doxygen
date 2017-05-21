/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
 *  Copyright (C) 2008 by Takahisa Yokota
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
 *  @(#) $Id: mcfuart.h,v 1.1 2005/07/06 00:45:07 honda Exp $
 */

/*
 *   COLDFIRE��¢UART�� �ʰץɥ饤��
 */

#ifndef _MCFUART_H_
#define _MCFUART_H_

#include <t_config.h>

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
typedef struct sio_port_initialization_block
{
	UW reg_base;				/* �쥸�����Υ١������ɥ쥹 */
	UH brr;					/* �ܡ��졼�Ȥ�������   */
	UB smr;					/* �⡼�ɥ쥸������������   */
	UB int_level;				/* �����ߥ�٥��������   */
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å�
 */
typedef struct sio_port_control_block
{
	const SIOPINIB *siopinib;	/* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
	VP_INT exinf;				/* ��ĥ���� */
	BOOL openflag;				/* �����ץ�Ѥߥե饰 */
	BOOL getready;				/* ʸ��������������� */
	BOOL putready;				/* ʸ���������Ǥ������ */
	VB   imr;				/* ����ߥޥ����ξ��� */
} SIOPCB;

/*
 *  ����ȥ���쥸�����Υ��ɥ쥹�Υ��ե��å� 
 */
#define MCF_UART_UMR1	0x00
#define MCF_UART_UMR2	0x00
#define MCF_UART_USR	0x04
#define MCF_UART_UCSR	0x04
#define MCF_UART_UCR	0x08
#define MCF_UART_URB	0x0c
#define MCF_UART_UTB	0x0c
#define MCF_UART_UIPCR	0x10
#define MCF_UART_UACR	0x10
#define MCF_UART_UISR	0x14
#define MCF_UART_UIMR	0x14
#define MCF_UART_UBG1	0x18
#define MCF_UART_UBG2	0x1c
#define MCF_UART_UIP	0x34
#define MCF_UART_UOP1	0x38
#define MCF_UART_UOP0	0x3c

/*
 *  ����ȥ���쥸������������
 */
/*  FIFO����ȥ���쥸����SCFCR�Υӥå�  */
#define MCF_UART_UCR_RC_MASK  0x03
#define MCF_UART_UCR_RC_EN   0x01
#define MCF_UART_UCR_RC_DIS  0x02
#define MCF_UART_UCR_TC_MASK  0x0C
#define MCF_UART_UCR_TC_EN   0x04
#define MCF_UART_UCR_TC_DIS  0x08
#define MCF_UART_UCR_MISC_MASK 0x70
#define MCF_UART_UCR_MISC_RRC  0x10
#define MCF_UART_UCR_MISC_RR   0x20
#define MCF_UART_UCR_MISC_RT   0x30
#define MCF_UART_UCR_MISC_RE   0x40
#define MCF_UART_UCR_MISC_RBK  0x50
#define MCF_UART_UCR_MISC_SBK  0x60
/*  ���ꥢ�륳��ȥ���쥸����UIMR�Υӥå�  */
#define MCF_UART_UIMR_TXRDY 0x01
#define MCF_UART_UIMR_RXRDY 0x02
#define MCF_UART_UIMR_DB    0x04
/*  ���ꥢ�륳��ȥ���쥸����UISR�Υӥå�  */
#define MCF_UART_UISR_TXRDY 0x01
#define MCF_UART_UISR_RXRDY 0x02
#define MCF_UART_UISR_DB    0x04
/*  ���ꥢ�륹�ơ������쥸����SC1SSR�Υӥå�  */
#define MCF_UART_USR_RXRDY (0x01)	/* ������ǥ� */
#define MCF_UART_USR_FULL  (0x02)	/* FIFO�ե�   */
#define MCF_UART_USR_TXRDY (0x04)	/* ������ǥ� */
#define MCF_UART_USR_TEMP  (0x08)	/* �ȥ�󥹥ߥå�����ץƥ� */
#define MCF_UART_USR_OE    (0x10)	/* �����С���󥨥顼 */
#define MCF_UART_USR_RE    (0x20)	/* �ѥ�ƥ����顼 */
#define MCF_UART_USR_FE    (0x40)	/* �ե졼�ߥ󥰥��顼 */
#define MCF_UART_USR_RB    (0x80)	/* �֥졼������ */

/*
 *  UBG������
 */
#define SMR_CKS 	0x0			/*  ʬ����          */
#define BRR9600 	195 			/*  9600 �ӥåȥ졼��    */
#define BRR19200	97			/*  19200 �ӥåȥ졼��    */
#define BRR38400	48			/*  38400 �ӥåȥ졼��    */
#define BRR57600 	32			/*  57600 �ӥåȥ졼�� 	*/
#define BRR115200 	16			/*  115200 �ӥåȥ졼�� */

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND	1u		/* ������ǽ������Хå� */
#define SIO_ERDY_RCV	2u		/* �������Υ�����Хå� */

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void mcfuart_initialize (void);

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
extern BOOL mcfuart_openflag (ID siopid);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB *mcfuart_opn_por (ID siopid, VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void mcfuart_cls_por (SIOPCB * siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern BOOL mcfuart_snd_chr (SIOPCB * siopcb, char c);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern INT mcfuart_rcv_chr (SIOPCB * siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void mcfuart_ena_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void mcfuart_dis_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
extern void mcfuart_isr (void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void mcfuart_ierdy_snd (VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void mcfuart_ierdy_rcv (VP_INT exinf);

#endif /* _MCFUART_H_ */
