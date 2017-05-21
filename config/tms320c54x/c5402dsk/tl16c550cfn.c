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
 *  @(#) $Id: tl16c550cfn.c,v 1.4 2003/12/19 10:03:31 honda Exp $
 */

/*
 * TL16c550cfn �ѥɥ饤��
 */

#include <s_services.h>
#include "tl16c550cfn.h"

/*
 * �����ͥ뵯ư���Ѥν����(sys_putc����Ѥ��뤿��)
 */
void
uart_init(void)
{
	/*  FIFO��ͭ���ˤ�����������FIFO�򥯥ꥢ��
	 *  �ȥꥬ��٥�ᣱ(�����������̡�
	 *  8�ǡ�����1���ȥåץӥåȡ�no parity 
	 */ 
	UART_FCR = (FCR_FIFO | FCR_RFRST | FCR_TFRST | FIFO_TRIG);
	UART_LCR = 0x03;
	 /*  �ܡ��졼�ȥ쥸�����˥������� */
	UART_LCR |= LCR_DLAB;
	UART_DLL = UART_BAUD_RATE;
	UART_DLM = UART_BAUD_RATE >> 8;
	/*  BAUD RATE���꽪λ  */
	UART_LCR &= ~LCR_DLAB;
	UART_SCR = UART_LSR;
}

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {0};

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ʸ���������������
 */
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
	return((UART_LSR & LSR_DR) != 0);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
	return((UART_LSR & LSR_THRE) != 0);
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
uart_getchar(SIOPCB *siopcb)
{
	return((char) UART_RBR);
}

/*
 *  ��������ʸ���ν����
 */
Inline void
uart_putchar(SIOPCB *siopcb, char c)
{
	UART_THR = (UB) c;
}

/*
 *  ��������ߵ���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
	UART_IER |= IER_TIE;
}

/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
	UART_IER &= ~IER_TIE;
}

/*
 *  ��������ߵ���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
	UART_IER = IER_RIE;
}

/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
	UART_IER &= ~IER_RIE;
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
uart_initialize()
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->siopinib = &(siopinib_table[i]);
		siopcb->openflag = FALSE;
	}
}

/*
 * �����ץ󤷤Ƥ���ݡ��Ȥ����뤫
 */
BOOL
uart_openflag(void)
{
	return(siopcb_table[0].openflag);
}



/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;

	siopcb = get_siopcb(siopid);
	
	/*  FIFO��ͭ���ˤ�����������FIFO�򥯥ꥢ��
	 *  �ȥꥬ��٥�ᣱ(�����������̡�
	 *  8�ǡ�����1���ȥåץӥåȡ�no parity 
	 */
	UART_FCR = (FCR_FIFO | FCR_RFRST | FCR_TFRST | FIFO_TRIG);
	UART_LCR = 0x03;
	/*  �ܡ��졼�ȥ쥸�����˥������� */
	UART_LCR |= LCR_DLAB;
	UART_DLL = UART_BAUD_RATE;
	UART_DLM = UART_BAUD_RATE >> 8;
	/*  BAUD RATE���꽪λ  */
	UART_LCR &= ~LCR_DLAB;
	/*  ���顼�ե饰�򥯥ꥢ  */
	UART_SCR = UART_LSR;
	UART_IER = IER_RIE;       /*  ���������ߵ���  */
	
	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	siopcb->getready = siopcb->putready = FALSE;

	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
uart_cls_por(SIOPCB *siopcb)
{
	/* ���������������׵�ػ� */
	UART_IER = 0;
	
	siopcb->openflag = FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char chr)
{
	if (uart_putready(siopcb)) {
		uart_putchar(siopcb, chr);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
uart_rcv_chr(SIOPCB *siopcb)
{
	if (uart_getready(siopcb)) {
		return((INT)(UB) uart_getchar(siopcb));
	}
	return(-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	    case SIO_ERDY_SND:
		uart_enable_send(siopcb);
		break;
	    case SIO_ERDY_RCV:
		uart_enable_rcv(siopcb);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	    case SIO_ERDY_SND:
		uart_disable_send(siopcb);
		break;
	    case SIO_ERDY_RCV:
		uart_disable_rcv(siopcb);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф������߽���
 */
static void
uart_isr_siop(SIOPCB *siopcb)
{
	if (uart_getready(siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		uart_ierdy_rcv(siopcb->exinf);
	}
	if (uart_putready(siopcb)) {
		/*
		 *  ������ǽ������Хå��롼�����ƤӽФ���
		 */
		uart_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
void
uart_isr()
{
	if (siopcb_table[0].openflag) {
		uart_isr_siop(&(siopcb_table[0]));
	}
}
