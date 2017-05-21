/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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
 *  @(#) $Id: hw_serial.c,v 1.7 2007/03/23 07:58:33 honda Exp $
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

/*
 *  ���ꥢ��ݡ��Ȥν�����֥�å�
 */
static const SIOPINIB siopinib_table[TNUM_PORT] = {
        {
                (UB*)SCI_PORT1_BASE,
                SCI_PORT1_BAUD_RATE,
                {
                        (UB*)SCI_PORT1_IPR,
                        SCI_PORT1_IPR_BIT,
                        SCI_PORT1_IPM
                },
                SCI_PORT1_SMR
        }

#if TNUM_PORT == 2u
        ,{
                (UB*)SCI_PORT2_BASE,
                SCI_PORT2_BAUD_RATE,
                {
                        (UB*)SCI_PORT2_IPR,
                        SCI_PORT2_IPR_BIT,
                        SCI_PORT2_IPM
                },
                SCI_PORT2_SMR
        }
#endif  /* of #if TNUM_PORT == 2u */

};


/*
 *  ���ꥢ��ݡ��Ȥ�����֥�å�
 */
SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ��������֥�å��ؤ��Ѵ�
 */
Inline SIOPINIB*
get_siopinib(ID sioid)
{
	UINT index = INDEX_SIO(sioid);
	
	assert(index < TNUM_PORT);
	
    return(&(siopinib_table[index]));
}

/*
 *  �ܡ��졼�Ȥ���BRR�쥸�����������ͤؤ��Ѵ�
 *  ���黻������ǥ����С��ե����ʤ��褦UW�����Ѥ��Ƥ���
 */
Inline UB 
baud_to_brr(UW baud)
{
	UB brr;
	
	if (baud > 38400ul) {
		brr = (UB)(((CPU_CLOCK+(16ul*baud)) / (32ul*baud))-1ul);
	} else {
		brr = (UB)((CPU_CLOCK / (32ul*baud))-1ul);
	}
	return brr;
}

/*
 *  �ܡ��졼���������Ԥ�����[nsec]�����ޥ���
 *  ���黻������ǥ����С��ե����ʤ��褦UW���˥��㥹�Ȥ��Ƥ���
 */
#define SCI_SETUP_TIME(b)       (((1000000ul / (b)) + 1ul) * 1000ul)

/*
 *  SCI �ν����
 */
void
SCI_initialize (ID sioid)
{
        const SIOPINIB  *inib = get_siopinib(sioid);
        
        assert(inib != (SIOPINIB*)NULL);
        SCI_cls_por(inib->base);

        sil_wrb_mem((VP)(inib->base + H8SMR), (VB)(inib->smr_init));

                                        /*  �ܡ��졼������      */
        sil_wrb_mem((VP)(inib->base + H8BRR), (VB)baud_to_brr(inib->baudrate));

                        /* ����߶ػߤȥ���å�������������     */
        h8_anb_reg(inib->base + H8SCR,
                     (UB)~(H8SCR_TIE  | H8SCR_RIE  | H8SCR_MPIE | H8SCR_TEIE |
                                                              H8SCR_CKE1 | H8SCR_CKE0 ));

        /* �ܡ��졼�Ȥ�����塢1�ӥå�ʬ�Ԥ��ʤ���Фʤ�ʤ���*/
        sil_dly_nse_long(SCI_SETUP_TIME(inib->baudrate));

                                        /* ���顼�ե饰�򥯥ꥢ         */
        h8_anb_reg(inib->base + H8SSR, (UB)~(H8SSR_ORER | H8SSR_FER | H8SSR_PER));

        /*
         *  �ץ饤����ƥ���٥������
         *      �����ϳ���ߥ���ȥ����¸��ʬ��ʬΥ���٤�
         */
        define_int_plevel(&(inib->irc));

        /* ���������ߤ���������ߤε��Ĥϥ��ꥢ�� I/O �ǹԤ� */
        /* ���������� */

        h8_orb_reg(inib->base + H8SCR, (UB)(H8SCR_TE | H8SCR_RE));
}

/*
 *  SCI �Υ�����
 */
void
SCI_cls_por (UB *base)
{
	    UB ssr;
	    
        /* TDRE �� 1 �ˤʤ�ޤ��Ԥ� */
        do {
			ssr = sil_reb_mem((VP)(base + H8SSR));
			ssr &= H8SSR_TDRE;
        } while(ssr == 0u);

        /* 11�ӥå�����ʬ�Ԥġ�*/
        /*
         * �׸�Ƥ����1.2msec����ꤹ��Τǡ�¾�ν�����CPU��
         * �����������ä����������������󥿥�������ƥ����Ȥ�
         * ���������ƤФ���ǽ��������Τǡ����Τޤޤˤ��Ƥ��롣
         */
        sil_dly_nse_long(SCI_SETUP_TIME(H8_MIN_BAUD_RATE)*11ul);

                                        /* ���������           */
        h8_anb_reg(base + H8SCR,
                    (UB)(~(H8SCR_TIE | H8SCR_RIE | H8SCR_TE | H8SCR_RE)));
}

/*
 *  SCI_in_handler -- SCI ���ϳ���ߥϥ�ɥ�
 */
void
SCI_in_handler(ID sioid)
{
        SIOPCB  *pcb = get_siopcb(sioid);
        UB      status = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
		UB      flag = (UB)(status & (H8SSR_ORER | H8SSR_FER | H8SSR_PER));

        if (flag != 0) {

                /* ���顼����           */

                /* ���顼�ե饰�򥯥ꥢ */
                sil_wrb_mem((VP)(pcb->inib->base + H8SSR),
                            (VB)(status & ~(H8SSR_ORER | H8SSR_FER | H8SSR_PER)));
        }

		flag = (UB)(status & H8SSR_RDRF);
        if (flag != 0) {
                if (pcb->openflag == TRUE) {
                        /* ������ǽ������Хå��롼�����ƽФ���*/
                        SCI_ierdy_rcv(pcb->exinf);
                } else {
                        sil_wrb_mem((VP)(pcb->inib->base + H8SSR), (VB)(status & ~H8SSR_RDRF));
                }
        }
}

/*
 *  SCI_out_handler -- SCI ���ϳ���ߥϥ�ɥ�
 */
void
SCI_out_handler(ID sioid)
{
        SIOPCB  *pcb;

        pcb = get_siopcb(sioid);
        if (pcb->openflag == TRUE) {
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
        SIOPCB  *pcb;
        UB      status;

        pcb = get_siopcb(sioid);
        status = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
        if (status & (H8SSR_ORER | H8SSR_FER | H8SSR_PER)) {

                /* ���顼����           */

                /* ���顼�ե饰�򥯥ꥢ */
                sil_wrb_mem((VP)(pcb->inib->base + H8SSR),
                            status & ~(H8SSR_ORER | H8SSR_FER | H8SSR_PER));
        }
}

#endif  /* of #ifdef H8_CFG_SCI_ERR_HANDLER */

/*
 *  sio_initialize -- ���ꥢ��ݡ��ȥɥ饤�Фν����
 */
void
sio_initialize(void)
{
        INT ix;

        /* SIO �����֥�å��ν���� */
        for (ix = 0; ix < TNUM_PORT; ix++) {
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
        default:
                assert(FALSE);
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
        default:
                assert(FALSE);
        }
}

/*
 *  SCI ������
 */
void
sio_in_handler (void)
{
        SCI_in_handler(SCI_PORTID1);
}

void
sio_out_handler (void)
{
        SCI_out_handler(SCI_PORTID1);
}

#ifdef H8_CFG_SCI_ERR_HANDLER

void
sio_err_handler (void)
{
        SCI_err_handler(SCI_PORTID1);
}

#endif  /* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#if TNUM_PORT >= 2u

void
sio_in2_handler (void)
{
        SCI_in_handler(SCI_PORTID2);
}

void
sio_out2_handler (void)
{
        SCI_out_handler(SCI_PORTID2);
}

#ifdef H8_CFG_SCI_ERR_HANDLER

void
sio_err2_handler (void)
{
        SCI_err_handler(SCI_PORTID2);
}

#endif  /* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#endif  /* of #if TNUM_PORT >= 2u */
