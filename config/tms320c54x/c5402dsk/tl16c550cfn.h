/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: tl16c550cfn.h,v 1.3 2003/12/04 08:25:44 honda Exp $
 */

/*
 * TL16C550CFN�� �ʰ�SIO�ɥ饤��
 */
#ifndef _TL16C550CFN_H_
#define _TL16C550CFN_H_

#include <t_config.h>

/***********************************************
 *  I/O  ���ꡦ�ޥåץɡ��쥸����            *
***********************************************/
/*
 *  complex Programmable Logic Device (CPLD)   *
 *  I/O ���ꡦ�ޥåץɡ��쥸����                 *
 */

/*  �쥸���������ɥ쥹��*/
#ifndef _MACRO_ONLY
volatile ioport UH	port0;
volatile ioport UH	port1;
volatile ioport UH	port2;
volatile ioport UH	port3;
volatile ioport UH	port4;
volatile ioport UH	port5;
volatile ioport UH	port6;
#endif /* _MACRO_ONLY */

/*  CPLD���쥸���� */
#define CPLD_CTRL1	port0
#define CPLD_STAT	port1
#define CPLD_DMCTRL	port2
#define CPLD_DBIO	port3
#define CPLD_CTRL2	port4
#define CPLD_SEM0	port5
#define CPLD_SEM1	port6

/*
 *  UART I/O ���ꡦ�ޥåץɡ��쥸���� *
 */
/*  �쥸���� ���ɥ쥹 */
#ifndef _MACRO_ONLY
volatile ioport UH	port4000;
volatile ioport UH	port4001;
volatile ioport UH	port4002;
volatile ioport UH	port4003;
volatile ioport UH	port4004;
volatile ioport UH	port4005;
volatile ioport UH	port4006;
volatile ioport UH	port4007;
#endif /* _MACRO_ONLY */

/*  UART �쥸����  */
#define UART_RBR	port4000
#define UART_THR	port4000
#define UART_IER	port4001
#define UART_IIR	port4002
#define UART_FCR	port4002
#define UART_LCR	port4003
#define UART_MCR	port4004
#define UART_LSR	port4005
#define UART_MSR	port4006
#define UART_SCR	port4007
/*
 *  �ʲ��Υ쥸�����˥��������������ˡ�
 *  DLAB=1 (b7 of LCR) �򥻥åȤ���ɬ�פ�����
 */
#define UART_DLL	port4000
#define UART_DLM	port4001

/*
 *  �ӥåȥե�����ɤ����
 */
#define FCR_FIFO	0x01
#define FCR_RFRST	0x02
#define FCR_TFRST	0x04
#define FIFO_TRIG	0x00

#define LCR_DLAB	0x80

/* �������������ߤ���� */
#define IER_ERBI	0x01  /* ���������� */
#define IER_RIE		IER_ERBI 
#define IER_ETBEI	0x02  /* ���������� */
#define IER_TIE		IER_ETBEI

#define LSR_DR		0x01
#define LSR_THRE	0x20
#define LSR_TEMT	0x40

#define IIR_RXINT	0x04
#define IIR_TXINT	0x02

/*
 *  UART�Υܡ��졼�Ȥ�����
 */
/*
 * BAUD RATE 2 : 115200 bps
 * BAUD RATE 4 : 57600  bps
 */
#define UART_BAUD_RATE    2



#ifndef _MACRO_ONLY

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
typedef struct sio_port_initialization_block {
	VP	dummy;
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å�
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*siopinib;  /* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
	VP_INT	exinf;			/* ��ĥ���� */
	BOOL	openflag;		/* �����ץ�Ѥߥե饰 */
	BOOL	getready;		/* ʸ��������������� */
	BOOL	putready;		/* ʸ��������Ǥ������ */
} SIOPCB;

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND    1u              /* ������ǽ������Хå� */
#define SIO_ERDY_RCV    2u              /* �������Υ�����Хå� */

/*
 * �����ͥ뵯ư���Ѥν����(sys_putc����Ѥ��뤿��)
 */
extern void	uart_init(void);

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void	uart_initialize(void);

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
extern BOOL	uart_openflag(void);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB	*uart_opn_por(ID siopid, VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void	uart_cls_por(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern BOOL	uart_snd_chr(SIOPCB *siopcb, char chr);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern INT	uart_rcv_chr(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void	uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void	uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
extern void	uart_isr(void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void	uart_ierdy_snd(VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void	uart_ierdy_rcv(VP_INT exinf);

/* �ݡ���󥰤ǥ��ꥢ������� */
Inline char
uart_putc(char c)
{
	while ((UART_LSR & LSR_THRE) == 0);      /*  �����쥸�����������ɤ���  */
	UART_THR = c;
	return(c);
}

#endif /* _MACRO_ONLY */

#endif /* _TL16C550CFN_H_ */
