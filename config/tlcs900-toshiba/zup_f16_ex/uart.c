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
 *  @(#) $Id: uart.c,v 1.1 2006/04/10 08:19:25 honda Exp $
 */

/*
 *  ��Ʊ���̿� (UART)���ꥢ������ͥ�ǥХ�����SIO�˥ɥ饤��
 *  ��Zup-F16��ĥ�ܡ����ѡ�
 */
#include <s_services.h>
#include <sil.h>
#include <tmp91cy22.h>
#include <uart.h>

/*
 *  ���ꥢ��I/O����쥸�����ؤΥ��ե��å����
 */
#define		TOFFSET_SC0BUF			0x0000
#define		TOFFSET_SC0CR			0x0001
#define		TOFFSET_SC0MOD0			0x0002
#define		TOFFSET_BR0CR			0x0003
#define		TOFFSET_BR0ADD			0x0004
#define		TOFFSET_SC0MOD1			0x0005
 
/*
 *  ���ꥢ��I/O�ݡ��Ⱦ��֥ե饰�����
 */
#define		TBIT_STS_DEF			0x00
#define		TBIT_TXB_EMPTY			0x01
#define		TBIT_ENE_TXCBR			0x02
#define		TBIT_ENE_RXCBR			0x04
#define		TBIT_LOG_PORT			0x80

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 *
 *  ID = 1 ��uart1��ID = 2 ��uart0���б������Ƥ��롥
 */
static const SIOPINIB siopinib_table[TNUM_PORT] = {
	{ TADR_SFR_SC1BUF, TADR_SFR_INTES1, 0x08, (TBIT_SIOSMU8 | TBIT_SIORXE | TBIT_SIOSCBRG),
	  0x00, BRCR_19200, BRADD_19200, TBIT_RX1_CLR }	/* ID1�� UART1 19200bps	*/
/*	{ TADR_SFR_SC1BUF, TADR_SFR_INTES1, 0x08, (TBIT_SIOSMU8 | TBIT_SIORXE | TBIT_SIOSCBRG),
	  0x00, BRCR_38400, BRADD_38400, TBIT_RX1_CLR }*/	/* ID1�� UART1 38400bps	*/
/*	{ TADR_SFR_SC0BUF, TADR_SFR_INTES0, 0x01, (TBIT_SIOSMU8 | TBIT_SIORXE | TBIT_SIOSCBRG),
	  0x00, BRCR_19200, BRADD_19200, TBIT_RX0_CLR }*/	/* ID2�� UART0 19200bps	*/
};

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
static SIOPCB siopcb_table[TNUM_PORT];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

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
	for (siopcb = siopcb_table, i = 0; i < TNUM_PORT; siopcb++, i++) {
		siopcb->siopinib = &(siopinib_table[i]);
		siopcb->sts_flag = TBIT_STS_DEF;
		siopcb->rxb = -1;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB		*siopcb;
	const SIOPINIB	*siopinib;
	int i;

	/* �ݡ���ID��������֥�å������	*/
	siopcb = get_siopcb(siopid);
	siopinib = siopcb->siopinib;

	/* �����֥�å��˾�������	*/
	siopcb->sts_flag |= TBIT_TXB_EMPTY;
	siopcb->exinf = exinf;
	if( siopid == LOGTASK_PORTID ){	/* �����ƥ���ѤΥݡ��Ȥξ��	*/
		siopcb->sts_flag |= TBIT_LOG_PORT;
		if( log_io_busy == TRUE ){
			/* ������ξ��ϴ�λ�ޤ��Ԥ�	*/
			while( (sil_reb_mem((VP)(siopinib->hint)) & TBIT_INTC_H) == 0 );
		}
		log_io_busy = FALSE;	/* ������ʤΤ�����Ū�˹ԤäƤ���   */
	}

	/* �������	*/
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0MOD0), 0x00 );
	/* �ݡ�������(TXD�Ȥ��ƻ���)	*/
	sil_wrb_mem((VP)(TADR_SFR_P9FC), siopinib->pcrfc_def );
	sil_wrb_mem((VP)(TADR_SFR_P9CR), siopinib->pcrfc_def );

	/* ư��⡼������	*/
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0MOD0), siopinib->scmod0_def );
	sil_reb_mem((VP)(siopinib->cntrl+TOFFSET_SC0CR));	/* �ɽФ��ˤ�ꥨ�顼�ե饰���ꥢ	*/
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0CR), siopinib->sccr_def );
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_BR0CR), siopinib->brcr_def);
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_BR0ADD), siopinib->bradd_def);
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0MOD1), TBIT_SIOI2S);

	/* ���ꥢ�����ߤ����ꤪ����׵�ե饰���ꥢ	 */
	sil_wrb_mem((VP)TADR_SFR_INTCLR, (siopinib->int_clr) );		/* �����׵᥯�ꥢ	*/
	sil_wrb_mem((VP)TADR_SFR_INTCLR, (VB)(siopinib->int_clr + 1) );	/* �����׵᥯�ꥢ	*/
	sil_wrb_mem((VP)(siopinib->hint), (VB)((INT_LEVEL_UART << 4) | INT_LEVEL_UART) );

	/*
	 * ���ߡ��ǡ�������
	 */
	sil_reb_mem((VP)(siopinib->cntrl+TOFFSET_SC0BUF));
	sil_reb_mem((VP)(siopinib->cntrl+TOFFSET_SC0BUF));

	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
uart_cls_por(SIOPCB *siopcb)
{
	const SIOPINIB	*siopinib;

	siopinib = siopcb->siopinib;

	/* �������	*/
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0MOD0), 0x00 );

	/* �����ƥ���ѥݡ��Ȥν���	*/
	if( (siopcb->sts_flag & TBIT_LOG_PORT) == TBIT_LOG_PORT ){
		if( log_io_busy == TRUE ){
			/* ������ξ��ϴ�λ�ޤ��Ԥ�	*/
			while( (sil_reb_mem((VP)(TADR_SFR_INTES0)) & TBIT_INTC_H) == 0 );
		}
		log_io_busy = FALSE;
	}

	/* ���ꥢ�����ߤζػߤ�����׵�ե饰���ꥢ	 */
	sil_wrb_mem((VP)(siopinib->hint), 0x00 );
	sil_wrb_mem((VP)TADR_SFR_INTCLR, (siopinib->int_clr) );		/* �����׵᥯�ꥢ	*/
	sil_wrb_mem((VP)TADR_SFR_INTCLR, (VB)(siopinib->int_clr + 1) );	/* �����׵᥯�ꥢ	*/
	/* �ݡ�������(�ݡ��ȤȤ��ƻ���)	*/
	sil_wrb_mem((VP)(TADR_SFR_P9FC), 0x00 );
	sil_wrb_mem((VP)(TADR_SFR_P9CR), 0x00 );

	siopcb->sts_flag = TBIT_STS_DEF;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char c)
{
	if( (siopcb->sts_flag & TBIT_TXB_EMPTY) == TBIT_TXB_EMPTY ){
		siopcb->sts_flag &= (UB)~TBIT_TXB_EMPTY;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0BUF), c);

	/* �����ƥ���ѥݡ��Ȥν���	*/
		if( (siopcb->sts_flag & TBIT_LOG_PORT) == TBIT_LOG_PORT ){
			log_io_busy = TRUE;	/* ������	*/
		}
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
	return(siopcb->rxb);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case UART_ERDY_SND:
		siopcb->sts_flag |= TBIT_ENE_TXCBR;
		break;
	case UART_ERDY_RCV:
		siopcb->sts_flag |= TBIT_ENE_RXCBR;
		break;
	default:
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
	case UART_ERDY_SND:
		siopcb->sts_flag &= (UB)~TBIT_ENE_TXCBR;
		break;
	case UART_ERDY_RCV:
		siopcb->sts_flag &= (UB)~TBIT_ENE_RXCBR;
		break;
	default:
		break;
	}
}

/*
 *  �ݡ���ID=1�˻��ꤵ��Ƥ���SIO�����ͥ�(uart1)����μ��������
 */
void serial_in_handler1()
{
	SIOPCB *siopcb = &siopcb_table[0];

	/* ���顼�ξ��������ʤ�   */
	if( ( sil_reb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0CR)) & 0x1c ) == 0 ){

		/* �ǡ�������	*/
		siopcb->rxb = (INT)sil_reb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0BUF));

		/* ������Хå������Ĥ���Ƥ�����	*/
		if( (siopcb->sts_flag & TBIT_ENE_RXCBR) == TBIT_ENE_RXCBR ){
			/*
			 *  �������Υ�����Хå��롼�����ƤӽФ���
			 */
			uart_ierdy_rcv(siopcb->exinf);
		}
	}
}

/*
 *  �ݡ���ID=1�˻��ꤵ��Ƥ���SIO�����ͥ�(uart1)��������������
 */
void serial_out_handler1()
{
	SIOPCB *siopcb = &siopcb_table[0];

	/* �ǡ���������λ�ե饰ON	*/
	siopcb->sts_flag |= TBIT_TXB_EMPTY;

	/* �����ƥ���ѥݡ��Ȥν���	*/
	if( (siopcb->sts_flag & TBIT_LOG_PORT) == TBIT_LOG_PORT ){
		log_io_busy = FALSE;	/* ������λ	*/
	}

	/* ������Хå������Ĥ���Ƥ�����	*/
	if( (siopcb->sts_flag & TBIT_ENE_TXCBR) == TBIT_ENE_TXCBR ){
		/*
		 *  ������ǽ������Хå��롼�����ƤӽФ���
		 */
		uart_ierdy_snd(siopcb->exinf);
	}
}

#if TNUM_PORT >= 2
/*
 *  �ݡ���ID=2�˻��ꤵ��Ƥ���SIO�����ͥ�(uart0)����μ��������
 */
void serial_in_handler2()
{
	SIOPCB *siopcb = &siopcb_table[1];

	/* ���顼�ξ��������ʤ�   */
	if( ( sil_reb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0CR)) & 0x1c ) == 0 ){

		/* �ǡ�������	*/
		siopcb->rxb = (INT)sil_reb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0BUF));

		/* ������Хå������Ĥ���Ƥ�����	*/
		if( (siopcb->sts_flag & TBIT_ENE_RXCBR) == TBIT_ENE_RXCBR ){
			/*
			 *  �������Υ�����Хå��롼�����ƤӽФ���
			 */
			uart_ierdy_rcv(siopcb->exinf);
		}
	}
}

/*
 *  �ݡ���ID=2�˻��ꤵ��Ƥ���SIO�����ͥ�(uart0)��������������
 */
void serial_out_handler2()
{
	SIOPCB *siopcb = &siopcb_table[1];

	/* �ǡ���������λ�ե饰ON	*/
	siopcb->sts_flag |= TBIT_TXB_EMPTY;

	/* �����ƥ���ѥݡ��Ȥν���	*/
	if( (siopcb->sts_flag & TBIT_LOG_PORT) == TBIT_LOG_PORT ){
		log_io_busy = FALSE;	/* ������λ	*/
	}

	/* ������Хå������Ĥ���Ƥ�����	*/
	if( (siopcb->sts_flag & TBIT_ENE_TXCBR) == TBIT_ENE_TXCBR ){
		/*
		 *  ������ǽ������Хå��롼�����ƤӽФ���
		 */
		uart_ierdy_snd(siopcb->exinf);
	}
}

#endif

