/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 *  �������åȰ�¸���ꥢ��I/O�⥸�塼��
 */

#include "jsp_kernel.h"
#include "hw_serial.h"

/*
 *  ���ꥢ��ݡ��Ȥν�����֥�å�
 */

const SIOPINIB siopinib_table[TNUM_PORT] = {

	{
		0,
		S1C33_INHNO_SERIAL0ERR,
		S1C33_INHNO_SERIAL0RX,
		S1C33_INHNO_SERIAL0TX,
	},
#if TNUM_PORT == 2
	{
		1,
		S1C33_INHN1_SERIAL0ERR,
		S1C33_INHN1_SERIAL0RX,
		S1C33_INHN1_SERIAL0TX,
	},
#endif	/* of #if TNUM_PORT == 2 */
};


/*
 *  ���ꥢ��ݡ��Ȥ�����֥�å�
 */

SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ��������֥�å��ؤ��Ѵ��ޥ���
 */
#define get_siopinib(sioid)	(&(siopinib_table[INDEX_SIO(sioid)]))
#define get_siopcb(sioid)	(&(siopcb_table[INDEX_SIO(sioid)]))

/*
 *  ���������ߥ����ӥ��롼����.
 */

void
sio_in_service(ID sioid)
{
	SIOPCB	*pcb;

	sio_clr_errflag(INDEX_SIO(sioid));
	pcb = get_siopcb(sioid);
	if (pcb->rx_cbrflag){
		/* ������ǽ������Хå��롼�����ƽФ���*/
		sio_ierdy_rcv(pcb->exinf);
	}
}

/*
 *  ������λ�����ߥ����ӥ��롼����
 */

void
sio_out_service(ID sioid)
{
	SIOPCB	*pcb;

	pcb = get_siopcb(sioid);
	if (pcb->tx_cbrflag){
		/* ������ǽ������Хå��롼�����ƽФ���*/
		sio_ierdy_snd(pcb->exinf);
	}
}

#ifdef SIO_ERR_HANDLER

/*
 *  �������顼�����ߥ����ӥ��롼����
 */

void
sio_err_service(ID sioid)
{
	SIOPCB	*pcb;
	UB	status;

	/* ���顼�ե饰�򥯥ꥢ */
	sio_clr_errflag(INDEX_SIO(sioid));

	/* �ݡ��Ȥ���ٽ�������� */
	sio_opn_por(sioid, (VP_INT)NULL);
}

#endif	/* of #ifdef SIO_ERR_HANDLER */

/*
 *  ���ꥢ��ݡ�������ơ��֥�����
 */

void
sio_initialize (void)
{
	int iLoop;

	/*
	 *  SIO ����֥�å��ν����
	 */
	for (iLoop = 0 ; iLoop < TNUM_PORT ; iLoop++ ) {
		siopcb_table[iLoop].inib     = &siopinib_table[iLoop];
		siopcb_table[iLoop].exinf    = (VP_INT)NULL;
		siopcb_table[iLoop].openflag = FALSE;
		siopcb_table[iLoop].tx_cbrflag  = FALSE;
		siopcb_table[iLoop].rx_cbrflag  = FALSE;
	}
}

/*
 *  ������Хå�����Ĥ���
 */
void
sio_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ch_no, sio_ctl;

	ch_no  = siopcb->inib->ch_no;
	sio_ctl = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bControl;
	switch (cbrtn){
	case	SIO_ERDY_SND:
		siopcb->tx_cbrflag = TRUE;
		break;
	case	SIO_ERDY_RCV:
		siopcb->rx_cbrflag = TRUE;
		break;
	}

	return;
}

/*
 *  ������Хå���ػߤ���
 */
void
sio_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ch_no, sio_ctl;

	ch_no  = siopcb->inib->ch_no;
	sio_ctl = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bControl;
	switch (cbrtn){
	case	SIO_ERDY_SND:
		siopcb->tx_cbrflag = FALSE;
		break;
	case	SIO_ERDY_RCV:
		siopcb->rx_cbrflag = FALSE;
		break;
	}

	/*
	 *  ������ǽͭ���ӥåȤ����ꤹ��
	 */
	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bControl = sio_ctl;

	return;
}

/*
 *  SIO ������
 */

void
sio_in_handler (void)
{
	sio_clr_factor(SIO_INT_RCV);
	sio_in_service(1);
}

void
sio_out_handler (void)
{
	sio_clr_factor(SIO_INT_SND);
	sio_out_service(1);
	}

#ifdef SIO_ERR_HANDLER

void
sio_err_handler (void)
{
	sio_clr_factor(SIO_INT_ERR);
	sio_err_service(1);
	}

#endif	/* of #ifdef SIO_ERR_HANDLER */

#if TNUM_PORT >= 2

void
sio_in2_handler (void)
{
	sio_clr_factor(SIO_INT_RCV << 3);
	sio_in_handler(2);
	}

void
sio_out2_handler (void)
{
	sio_clr_factor(SIO_INT_SND << 3);
	sio_out_handler(2);
	}

#ifdef SIO_ERR_HANDLER

void
sio_err2_handler (void)
{
	sio_clr_factor(SIO_INT_ERR << 3)
	sio_err_handler(2);
	}

#endif	/* of #ifdef SIO_ERR_HANDLER */

#endif	/* of #if TNUM_PORT >= 2 */
