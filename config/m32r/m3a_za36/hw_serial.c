/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  @(#) $Id: hw_serial.c,v 1.2 2007/05/28 02:03:55 honda Exp $
 */

/*
 *	���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�M32102��¢��Ʊ�����ꥢ���ѡ�
 */

#include <sil.h>
#include <hw_serial.h>

#include <cpu_rename.h>
#include <sys_rename.h>

SIOPCB siopcb_table[TNUM_PORT];

extern FP InterruptHandlerEntry[];

/* 
 *  ����Ѵؿ� 
 */
#define ID_PORT(x)		((x) + 1)
#define INDEX_PORT(x)	((x) - 1)
#define GET_SIOPCB(x)	(&siopcb_table[INDEX_PORT(x)])

/*
 *  ���ꥢ��ݡ��Ȥν����
 */
void
sio_initialize(void)
{
	int i;

	for(i=0;i<TNUM_PORT;i++)
	{
		siopcb_table[i].flags = SIO_TYP_M32RUART;
		siopcb_table[i].port  = i;
		siopcb_table[i].exinf = 0;

		InterruptHandlerEntry[INT_SIO0RCV + (siopcb_table[i].port * 2) - 1] = sio_handler_in;
		InterruptHandlerEntry[INT_SIO0XMT + (siopcb_table[i].port * 2) - 1] = sio_handler_out;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB * siopcb = GET_SIOPCB(siopid);

	siopcb->exinf = exinf;

	switch(SIO_TYP(siopcb->flags))
	{
	case SIO_TYP_M32RUART:
		/* UART����� */
		sil_wrb_mem((void *)(SIOCR(siopcb->port)+3), 0);

		/* �ݡ��Ȥ򳫤�(UART0) */
		sil_wrb_mem((void *)PDATA(5), 0);
		sil_wrb_mem((void *)PDIR(5),  0x80);

		/* UART, Non-parity, 1 stop-bit */
		sil_wrb_mem((void *)(SIOMOD0(siopcb->port)+3), 0);

		/* 8bit, internal clock */
		sil_wrh_mem((void *)(SIOMOD1(siopcb->port)+2), 0x0800);

		/* m3a_za36 10MHz��57600bps */
		sil_wrh_mem((void *)(SIOBAUR(siopcb->port)+2),SERIAL_CLKDIV);
		sil_wrb_mem((void *)(SIORBAUR(siopcb->port)+3), SERIAL_CLKCMP);

		/* �����������ȯ������ */
		sil_wrh_mem((void *)(SIOTRCR(siopcb->port)+2), 0x0006);

		/* ���ơ��������ꥢ, ������ư��� */
		sil_wrb_mem((void *)(SIOCR(siopcb->port)+2), 0x3);
		sil_wrb_mem((void *)(SIOCR(siopcb->port)+3), 0x3);

		/* ������������׵���յ��� */
		sil_wrh_mem((void *)(ICUCR(SIO,siopcb->port)+2), 0x1000); /* ����������׵���� */
		sil_wrh_mem((void *)(ICUCR(SIO,siopcb->port)+6), 0x1000); /* ����������׵���� */

		/* TxD,RxD�ԥ�ͭ��(UART0) */
		sil_wrh_mem((void *)PMOD(5), 0x5500);

		break;
	}
	return siopcb;
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sio_cls_por(SIOPCB *siopcb)
{
	switch(SIO_TYP(siopcb->flags))
	{
	case SIO_TYP_M32RUART:
		/* ������ư���ػߤ��� */
		sil_wrb_mem((void *)(SIOCR(siopcb->port)+3), 0);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT sio_rcv_chr(SIOPCB * siopcb)
{
	switch(SIO_TYP(siopcb->flags))
	{
	case SIO_TYP_M32RUART:
		return sil_reb_mem((void *)(SIORXB(siopcb->port)+3));
	}
	return -1;
}


/*
 *  ʸ���������������
 */

inline BOOL
hw_port_getready(SIOPCB *p)
{
	switch(SIO_TYP(p->flags))
	{
	case SIO_TYP_M32RUART:
		return (sil_reb_mem((void *)(SIOSTS(p->port)+3)) & 0x4) != 0 ? TRUE : FALSE;
	}
	return FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå�����
 */
void sio_ena_cbr(SIOPCB * siopcb, UINT cbrtn)
{}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ػ�
 */
void sio_dis_cbr(SIOPCB * siopcb, UINT cbrtn)
{}

/*
 * ���ꥢ��ݡ��Ȥμ�������ߥϥ�ɥ�
 */
void sio_handler_in(void)
{
	int port;

	for(port = 0; port < TNUM_PORT; ++ port){
		if( hw_port_getready(&siopcb_table[port]) == TRUE )
			{
				sio_ierdy_rcv(GET_SIOPCB(ID_PORT(port))->exinf);
			}	
	}
}

/*
 * ���ꥢ��ݡ��Ȥ���������ߥϥ�ɥ�
 */
void sio_handler_out(void)
{
	int port;
	
	for(port = 0; port < TNUM_PORT; ++ port) {
		if((siopcb_table[port].flags & SIO_STS_SENDING) != 0) {		
			//�������ơ����������
			sil_wrb_mem((void *)(SIOCR(port)+2), 0x1);
			siopcb_table[port].flags &= ~SIO_STS_SENDING;

			sio_ierdy_snd(GET_SIOPCB(ID_PORT(port))->exinf);
		}
	}
}		
