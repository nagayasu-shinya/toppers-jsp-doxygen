/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2006 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2006 by Logic Research Co., Ltd.
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
 * FRK_ADuC ������ǽ�ѥɥ饤��
 */

#include <s_services.h>
#include "frk_aduc.h"


/*
 * ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{(VP)COMRX, (VP)COMDIV0, (VP)COMDIV1,
	 (VP)COMIEN0, (VP)COMIID0, (VP)COMCON0,
	 (VP)COMSTA0, IRQ_UART}
};


/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
SIOPCB  siopcb_table[TNUM_SIOP];



/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))



/*
 * ʸ�������������?
 */ 
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
	return(((sil_rew_mem((VP)(siopcb->siopinib->line_status)) & COMSTA0_DR)!=0));
}


/*
 * ʸ���������Ǥ��뤫?
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
	return((sil_rew_mem((VP)(siopcb->siopinib->line_status)) & COMSTA0_TEMT)!=0);
}


/*
 *  ��������ʸ���μ��Ф�
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
	return(sil_rew_mem((VP)(siopcb->siopinib->uart_data)));
}


/*
 *  ��������ʸ���ν񤭹���
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_data), c);
}


/*
 *  ��������ߵ���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->int_enable),
            (sil_rew_mem((VP)(siopcb->siopinib->int_enable)) | COMIEN0_ETBEI));
}


/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->int_enable),
        (sil_rew_mem((VP)(siopcb->siopinib->int_enable)) & ~COMIEN0_ETBEI));
}


/*
 *  ��������ߵ���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->int_enable),
        (sil_rew_mem((VP)(siopcb->siopinib->int_enable)) | COMIEN0_ERBFI));
}

/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->int_enable),
        (sil_rew_mem((VP)(siopcb->siopinib->int_enable)) & ~COMIEN0_ERBFI));
}



/*
 * �����ͥ뵯ư���Υ������Ѥν����
 */
void
init_uart(void){
    /* Disable Interrupt */
    sil_wrw_mem((VP)COMIEN0, 0);
    /* 9600bps */
    sil_wrw_mem((VP)COMCON0, COMCON0_DLAB);
    sil_wrw_mem((VP)COMDIV0, COMDIV0_BR9600); 
    sil_wrw_mem((VP)COMDIV1, COMDIV1_BR9600);
    /* 8Data, 1Stop, No Parity */
    sil_wrw_mem((VP)COMCON0, (COMCON0_STOP|COMCON0_WLS_8b));
    /* Enabel Receive Interrupt */
    sil_wrw_mem((VP)COMIEN0, (COMIEN0_ERBFI|COMIEN0_ETBEI));      
}


/*
 *  ������åפ�UART����Υݡ���󥰽���
 */
void
uart_putc(char c)
{
    int i;

    while((sil_rew_mem((VP)COMSTA0) & COMSTA0_TEMT)!=COMSTA0_TEMT);
  
    sil_wrw_mem((VP)COMTX, (VW)c);
}


/*
 *  SIO�ɥ饤�Фν�����롼����
 *  1�ݡ��Ȥ����ʤ����ᡤ���ޤ��̣�Ϥʤ�
 */
void
uart_initialize()
{
    SIOPCB  *siopcb;
    UINT    i;

    /*
     *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
     */
    for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
        siopcb->siopinib = &(siopinib_table[i]);
        siopcb->openflag = FALSE;
        siopcb->sendflag = FALSE;
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
 * ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
    int i;
    
    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

    /* Disable Interrupt */
    sil_wrw_mem((VP)siopinib->int_enable, 0);
    /* 9600bps */
    sil_wrw_mem((VP)siopinib->line_control, COMCON0_DLAB);
    sil_wrw_mem((VP)siopinib->divisor_lo, COMDIV0_BR9600); 
    sil_wrw_mem((VP)siopinib->divisor_hi, COMDIV1_BR9600);
    
    /* 8Data, 1Stop, No Parity */
    sil_wrw_mem((VP)siopinib->line_control, (COMCON0_STOP|COMCON0_WLS_8b));

    /*
     * ����ߴ�Ϣ������
     */
    sil_wrw_mem((VP)siopinib->int_enable, (COMIEN0_ERBFI|COMIEN0_ETBEI));	/* Enable Interrupt */
    sil_wrw_mem((VP)IRQEN, siopinib->irq_bit);	/*Enable interrupt register*/
    
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);    
}


/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
uart_cls_por(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->line_control),
        (sil_rew_mem((VP)(siopcb->siopinib->line_control))|COMCON0_BRK)); /* Disable Interrupt */
    
    siopcb->openflag = FALSE;
}


/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char c)
{
    if (uart_putready(siopcb)){
        uart_putchar(siopcb, c);
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
	volatile UW	iid;

    if (uart_getready(siopcb)) {
        /*
         *  �������Υ�����Хå��롼�����ƤӽФ���
         */
        uart_ierdy_rcv(siopcb->exinf);
    }
    if (uart_putready(siopcb)) {
		iid = sil_rew_mem((VP)COMIID0);
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
    uart_isr_siop(&(siopcb_table[0]));
}

