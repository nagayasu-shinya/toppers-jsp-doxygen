/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2010 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: hw_serial.c,v 1.12 2007/03/23 07:22:15 honda Exp $
 */

/*
 *  �������åȰ�¸���ꥢ��I/O�⥸�塼���H8�ѡ�
 *    ���ݡ��Ȥ� 1�ܤξ��� HWPORT1_ADDR�˻��ꤵ�줿�ݡ��Ȥ���Ѥ���
 *      2�ܤξ��ϡ�HWPORT1_ADDR��桼���ѡ�HWPORT2_ADDR�򥳥󥽡���
 *      ���ϤȤ��ƻ��Ѥ��롣
 *      HWPORTx_ADDR�� �������åȰ�¸�� sys_config.h��ǻ��ꤹ�롣
 *    ���������Υ⥸�塼��ˤ�äơ�XON/XOFF�ե����椬�Ԥ�
 *      ��Ƥ���Τǡ���������TxD��RxD��2�ܤǤ褤
 */

#include "jsp_kernel.h"
#include <hw_serial.h>
#include <h8_sil.h>

/*
 *  �ܡ��졼�Ȥ�1�ӥå�ʬ�λ���[nsec]���Ѵ�����ޥ���
 *  ���黻������ǥ����С��ե����ʤ��褦long��������Ѥ��Ƥ���
 */
#define BAUD_TO_NSEC(b)       (UINT)(((1000000ul / (b)) + 1ul) * 1000ul)

/*
 *  �ܡ��졼�Ȥ�BRR���ͤ��Ѵ�����ޥ���
 */
#define H8BRR_RATE(b)	(((b)>38400)?((UB)(((CPU_CLOCK+(16*(b)))/(32*(b)))-1))\
			          :((UB)((CPU_CLOCK/(32*(b)))-1)))

/*
 *  ���ꥢ��ݡ��Ȥν�����֥�å�
 */

static const SIOPINIB siopinib_table[TNUM_PORT] = {
	{
		SYSTEM_SCI,
		SYSTEM_BAUD_RATE,
                {
                        (UB*)SYSTEM_SCI_IPR,
                        SYSTEM_SCI_IP_BIT,
                        SYSTEM_SCI_IPM
                },
		SYSTEM_SCI_SMR
	}

#if TNUM_PORT >= 2
	,{
		USER_SCI,
		USER_BAUD_RATE,
                {
                        (UB*)USER_SCI_IPR,
                        USER_SCI_IP_BIT,
                        USER_SCI_IPM
                },
		USER_SCI_SMR
	}
#endif	/* of #if TNUM_PORT >= 2 */

#if TNUM_PORT >= 3
	,{
		USER2_SCI,
		USER2_BAUD_RATE,
                {
                        (UB*)USER2_SCI_IPR,
                        USER2_SCI_IP_BIT,
                        USER2_SCI_IPM
                },
		USER2_SCI_SMR
	}
#endif	/* of #if TNUM_PORT >= 3 */

};


/*
 *  ���ꥢ��ݡ��Ȥ�����֥�å�
 */

SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ��������֥�å��ؤ��Ѵ��ޥ���
 */

#define get_siopinib(sioid)	(&(siopinib_table[INDEX_SIO(sioid)]))

/*
 *  SCI �ν����
 */

void
SCI_initialize (ID sioid)
{
	const SIOPINIB	*inib;

	inib = get_siopinib(sioid);
	SCI_cls_por(inib->base);
			/*
			 *���⡼������
			 *������Ĵ��Ʊ����
			 *����������饯��Ĺ
			 *�������ѥ�ƥ�
			 *���������ȥåץӥå�Ĺ
			 *����������å�����
			 */
	sil_wrb_mem((VP)(inib->base + H8SMR), inib->smr_init);

					/*  �ܡ��졼������  	*/
	sil_wrb_mem((VP)(inib->base + H8BRR), H8BRR_RATE(inib->baudrate));

			/* ����߶ػߤȥ���å�������������	*/
	h8_anb_reg((UB *)(inib->base + H8SCR),
            	    (UB)~(H8SCR_TIE  | H8SCR_RIE  | H8SCR_MPIE |
            	          H8SCR_TEIE | H8SCR_CKE1 | H8SCR_CKE0 ));

	/* �ܡ��졼�Ȥ�����塢1�ӥå�ʬ�Ԥ��ʤ���Фʤ�ʤ���*/
	sil_dly_nse(BAUD_TO_NSEC(inib->baudrate));

					/* ���顼�ե饰�򥯥ꥢ		*/
	h8_anb_reg((UB *)(inib->base + H8SSR),
	            ~(H8SSR_ORER | H8SSR_FER | H8SSR_PER));

        /*
         *  �ץ饤����ƥ���٥������
         *      �����ϳ���ߥ���ȥ����¸��ʬ��ʬΥ���٤�
         */
	define_int_plevel(&(inib->irc));

	/* ���������ߤ���������ߤε��Ĥϥ��ꥢ�� I/O �ǹԤ� */
	/* ���������� */
	h8_orb_reg((VP)(inib->base + H8SCR), (H8SCR_TE | H8SCR_RE));
}

/*
 *  SCI �Υ�����
 */

void
SCI_cls_por (UW base)
{
#ifndef HEW_SIMULATOR
	/* TDRE �� 1 �ˤʤ�ޤ��Ԥ� */
	while ((sil_reb_mem((VP)(base + H8SSR)) & H8SSR_TDRE) == 0)
		;

	/* 11�ӥå�����ʬ�Ԥġ�*/
	sil_dly_nse(11*BAUD_TO_NSEC(H8_MIN_BAUD_RATE));
#endif	/* HEW_SIMULATOR */
					/* ���������		*/
	h8_anb_reg((UB *)(base + H8SCR),
	           (UB)~(H8SCR_TIE | H8SCR_RIE | H8SCR_TE | H8SCR_RE));
}

/*
 *  SCI_in_handler -- SCI ���ϳ���ߥϥ�ɥ�
 */

void
SCI_in_handler(ID sioid)
{
	SIOPCB	*pcb;
	VP	p_ssr;
	UB	status;
	
	pcb = get_siopcb(sioid);
	p_ssr = (VP)(pcb->inib->base + H8SSR);
	status = sil_reb_mem(p_ssr);
	
#if 0	/*  �����ȥ�����  */
	/*
	 *  SIO���顼����ߥ����ӥ��롼��������Ǥʤ�
	 *  �����Ǥ⥨�顼�����å���ԤäƤ�����ͳ��
	 *  �ʲ��Υ������󥹤����ꤷ�Ƥ��뤿�ᡣ
	 *  �ʥ쥢�������Τ��ᡢ�����ȥ����Ȥ��Ƥ��롣��
	 *  
	 *  �������ꥢ���������ߡ�����ˤ�ȯ����������ߥϥ�ɥ餬��ư����롣
	 *  ��������߽������¿�ų���ߤ����ꡢ���ꥢ�������������α����롣
	 *  �������㡧�����޳����
	 *  ��������˥ǡ�������������㤨�С������Х�󥨥顼��ȯ��
	 *  �������γ���߽�������λ�������γ���߽�������롣
	 *  �������κݡ����ꥢ��Υ��顼�ե饰��Ω�ä����֤ǡ�
	 *  �������辰�����μ�������ߤγ���ߥϥ�ɥ餬�¹Ԥ���롣
	 */
	if (status & (H8SSR_ORER | H8SSR_FER | H8SSR_PER)) {

		/* ���顼����		*/

	    	/* ���顼�ե饰�򥯥ꥢ	*/
		sil_wrb_mem(p_ssr,
		            status & ~(H8SSR_ORER | H8SSR_FER | H8SSR_PER));
	}
#endif

	if (status & H8SSR_RDRF) {
		if (pcb->openflag) {
			/* ������ǽ������Хå��롼�����ƽФ���*/
			SCI_ierdy_rcv(pcb->exinf);
		} else {
			sil_wrb_mem(p_ssr, status & ~H8SSR_RDRF);
		}
	}
}

/*
 *  SCI_out_handler -- SCI ���ϳ���ߥϥ�ɥ�
 */

void
SCI_out_handler(ID sioid)
{
	SIOPCB	*pcb;

	pcb = get_siopcb(sioid);
	if (pcb->openflag) {
		/* ������ǽ������Хå��롼�����ƽФ���*/
		SCI_ierdy_snd(pcb->exinf);
	}
}

#ifdef H8_CFG_SCI_ERR_HANDLER

/*
 *  SCI_err_handler -- SCI ���顼���ϳ���ߥϥ�ɥ�
 */

void
SCI_err_handler(ID sioid)
{
	SIOPCB	*pcb;
	VP	p_ssr;
	UB	status;

	pcb = get_siopcb(sioid);
	p_ssr = (VP)(pcb->inib->base + H8SSR);
	status = sil_reb_mem(p_ssr);
	if (status & (H8SSR_ORER | H8SSR_FER | H8SSR_PER)) {

		/* ���顼����		*/

	    	/* ���顼�ե饰�򥯥ꥢ	*/
		sil_wrb_mem(p_ssr,
		            status & ~(H8SSR_ORER | H8SSR_FER | H8SSR_PER));
	}
}

#endif	/* of #ifdef H8_CFG_SCI_ERR_HANDLER */

/*
 *  sio_initialize -- ���ꥢ��ݡ��ȥɥ饤�Фν����
 */

void
sio_initialize (void)
{
	int ix;

	/* SIO �����֥�å��ν���� */
	for (ix = TNUM_PORT; ix -- > 0; ) {
		siopcb_table[ix].inib     = &siopinib_table[ix];
		siopcb_table[ix].openflag = FALSE;
	}
}

/*
 *  sio_ena_cbr -- ���ꥢ�� I/O ����Υ�����Хå��ε���
 */

void
sio_ena_cbr(SIOPCB *pcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		SCI_enable_send(pcb);
		break;
	case SIO_ERDY_RCV:
		SCI_enable_recv(pcb);
		break;
	}
}

/*
 *  sio_dis_cbr -- ���ꥢ�� I/O ����Υ�����Хå��ζػ�
 */

void
sio_dis_cbr(SIOPCB *pcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		SCI_disable_send(pcb);
		break;
	case SIO_ERDY_RCV:
		SCI_disable_recv(pcb);
		break;
	}
}

/*
 *  SCI ������
 */

void
sio_in_handler (void)
{
	SCI_in_handler(1);
}

void
sio_out_handler (void)
{
	SCI_out_handler(1);
}

#ifdef H8_CFG_SCI_ERR_HANDLER

void
sio_err_handler (void)
{
	SCI_err_handler(1);
}

#endif	/* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#if TNUM_PORT >= 2

void
sio_in2_handler (void)
{
	SCI_in_handler(2);
}

void
sio_out2_handler (void)
{
	SCI_out_handler(2);
}

#ifdef H8_CFG_SCI_ERR_HANDLER

void
sio_err2_handler (void)
{
	SCI_err_handler(2);
}

#endif	/* of #ifdef H8_CFG_SCI_ERR_HANDLER */
#endif	/* of #if TNUM_PORT >= 2 */

#if TNUM_PORT >= 3

void
sio_in3_handler (void)
{
	SCI_in_handler(3);
}

void
sio_out3_handler (void)
{
	SCI_out_handler(3);
}

#ifdef H8_CFG_SCI_ERR_HANDLER

void
sio_err3_handler (void)
{
	SCI_err_handler(3);
}

#endif	/* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#endif	/* of #if TNUM_PORT >= 3 */

