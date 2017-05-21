/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005-2007 by Y.D.K.Co.,LTD Technologies company
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
 *  @(#) $Id: ns9360.c,v 1.2 2007/05/21 01:33:50 honda Exp $
 */

/*
 *    ������ǽ�ѥɥ饤��
 */
#include <s_services.h>
#include <ns9360.h>

/*
 * ����UART�� �ʰ�SIO�ɥ饤��
 */

/*
 * ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{
		/* UART Channel A */
		 (VP)SC1SRA_REG , (VP)SC1FIFO_REG , (VP)SC1CRA_REG , (VP)SC1CRB_REG
		,(VP)SC1RCT_REG , (VP)SC1RBT_REG , (VP)SC1BRG_REG
		,(SCCRA_CE | SCCRA_WLS | SCCRA_DTR | SCCRA_RTS)
		,0x08000000
		,0x80000008
		,0x80000008
		,(0xC0140000 | 7)			/* 29.4912MHz /2/8 = 115200*16 */
		,BBBI_S1TX , BBBI_S1RX
	 }
#if TNUM_SIOP >= 2
    ,
    {
		/* UART Channel C */
		 (VP)SC3SRA_REG , (VP)SC3FIFO_REG , (VP)SC3CRA_REG , (VP)SC3CRB_REG
		,(VP)SC3RCT_REG ,(VP)SC3RBT_REG ,  (VP)SC3BRG_REG
		,(SCCRA_CE | SCCRA_WLS | SCCRA_DTR | SCCRA_RTS)
		,0x08000000
		,0x80000008
		,0x80000008
		,(0xC0140000 | 7)			/* 29.4912MHz /2/8 = 115200*16 */
		,BBBI_S3TX , BBBI_S3RX
	}
#endif
 };

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
SIOPCB  siopcb_table[TNUM_SIOP];

/*
 * �����ƥ�����ѥ��ꥢ��ݡ��Ⱦ���
 */
SIOPCB      *sys_siopcb;


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
	VW	dt;
	
	if(0 != siopcb->rxfdb)
		return TRUE;
	
	dt = sil_rew_mem((VP)siopcb->siopinib->pSraReg);
	return(dt &(SCSRA_RFS | SCSRA_RRDY));
}

/*
 * ʸ���������Ǥ��뤫?
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
	return(sil_rew_mem((VP)siopcb->siopinib->pSraReg)&(SCSRA_TRDY | SCSRA_THALF | SCSRA_TEMPTY));
}

/*
 *  ��������ʸ���μ��Ф�
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
	UW	dt;
	
	if(0 == siopcb->rxfdb)
	{
		siopcb->rxfdb = (sil_rew_mem((VP)siopcb->siopinib->pSraReg) >> 20) & 0x03;
		if(0 == siopcb->rxfdb)
			siopcb->rxfdb = 4;
		
		siopcb->rxbuf = sil_rew_mem((VP)siopcb->siopinib->pFifoReg);
	}
	--(siopcb->rxfdb);
	dt = (siopcb->rxbuf >> 24) & 0xff;
	siopcb->rxbuf <<= 8;
	
	return (UB)dt;

}

/*
 *  ��������ʸ���ν񤭹���
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
    sil_wrb_mem((VP)siopcb->siopinib->pFifoReg, (VB)c);
}

/*
 *  ��������ߵ���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
		sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) | siopcb->siopinib->BbbiTx);
}

/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
	sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) & ~siopcb->siopinib->BbbiTx);
}

/*
 *  ��������ߵ���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
	sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) | siopcb->siopinib->BbbiRx);
}

/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
	sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) & ~siopcb->siopinib->BbbiRx);
}



/*
 * �����ͥ뵯ư���Υ������Ѥν����
 */
void
uart_init(ID siopid){
    SIOPCB      *siopcb;

	uart_initialize();

    siopcb = get_siopcb(siopid);

	sys_siopcb = siopcb;

    /* UART Initialize */
    sil_wrw_mem((VP)siopcb->siopinib->pCraReg,(VW)siopcb->siopinib->CraData);
	sil_wrw_mem((VP)siopcb->siopinib->pCrbReg,(VW)siopcb->siopinib->CrbData);
	sil_wrw_mem((VP)siopcb->siopinib->pRctReg,(VW)0);
	
    /* Set bound rate */
	sil_wrw_mem((VP)siopcb->siopinib->pBrgReg,siopcb->siopinib->BrgData);
}


/*
 *  ������åפ�UART����Υݡ���󥰽���
 */
void
uart_putc(char c)
{
    UW buf_level;
    
    do{
        buf_level = sil_rew_mem((VP)sys_siopcb->siopinib->pSraReg) & SCSRA_TRDY;
    }while(buf_level == 0);
    
    sil_wrb_mem((VP)sys_siopcb->siopinib->pFifoReg,(VW)c);
}

/*
 *  SIO�ɥ饤�Фν�����롼����
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
        siopcb->rxfdb = 0;
        siopcb->rxbuf = 0;
        siopcb->siopid = i;
    }
}

/*
 * �����ץ󤷤Ƥ���ݡ��Ȥ����뤫
 */
BOOL
uart_openflag(ID siopid)
{
    return(siopcb_table[siopid].openflag);
}


/*
 * ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;
	UW		n;
	
    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

    /* UART Initialize */
    sil_wrw_mem((VP)siopinib->pCraReg,(VW)siopinib->CraData);
	sil_wrw_mem((VP)siopinib->pCrbReg,(VW)siopinib->CrbData);
	sil_wrw_mem((VP)siopinib->pRctReg,(VW)siopinib->RctData);
	sil_wrw_mem((VP)siopinib->pRbtReg,(VW)siopinib->RbtData);
	
    /* Set bound rate */
	sil_wrw_mem((VP)siopinib->pBrgReg,siopinib->BrgData);

    /* ����RcvRdy,FIFO=Half������TxEmpty,FIFO-Half����ߵ��� */
	n = sil_rew_mem((VP)siopinib->pCraReg);
	n &=  (~(SCCRA_RIE | SCCRA_TIC));
	n |= (0xe00 | 0x0c);
    sil_wrw_mem((VP)siopinib->pCraReg,(VW)n);
	
    /* BBUS����ߵ��� */
	sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) | siopinib->BbbiRx);
	sil_wrw_mem((VP)INT_CFG8_11_REG,sil_rew_mem((VP)INT_CFG8_11_REG)|0x80000000);
	
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;
    siopcb->rxfdb = 0;
    siopcb->rxbuf = 0;

    return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
uart_cls_por(SIOPCB *siopcb)
{
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
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф�����������߽���
 */
static void
uart_Txisr_siop(SIOPCB *siopcb)
{
    /*
     *  ������ǽ������Хå��롼�����ƤӽФ���
     */
    uart_ierdy_snd(siopcb->exinf);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф����������߽���
 */
static void
uart_Rxisr_siop(SIOPCB *siopcb)
{
    /*
     *  �������Υ�����Хå��롼�����ƤӽФ���
     *  ����4ʸ��(32bit)�������Ƥ���ΤǤ�����������ʸ�����������
     */
    while(1)
    {
        uart_ierdy_rcv(siopcb->exinf);
        if(0 == siopcb->rxfdb)
            break;                           /* �����Ѥߥ���饯���ʤ� */
	}
}


/*
 *  SIO��Tx����ߥ����ӥ��롼����
 */
void
uart_Tx_isr()
{
	uart_Txisr_siop(&(siopcb_table[0]));
}

/*
 *  SIO��Rx����ߥ����ӥ��롼����
 */
void
uart_Rx_isr()
{
	uart_Rxisr_siop(&(siopcb_table[0]));
	sil_wrw_mem((VP)siopcb_table[0].siopinib->pSraReg , 
					sil_rew_mem((VP)siopcb_table[0].siopinib->pSraReg) );
}

/*
 *  SIO2��Tx����ߥ����ӥ��롼����
 */
void
uart2_Tx_isr()
{
	uart_Txisr_siop(&(siopcb_table[1]));
}

/*
 *  SIO2��Rx����ߥ����ӥ��롼����
 */
void
uart2_Rx_isr()
{
	uart_Rxisr_siop(&(siopcb_table[1]));
	sil_wrw_mem((VP)siopcb_table[1].siopinib->pSraReg , 
					sil_rew_mem((VP)siopcb_table[1].siopinib->pSraReg) );
}


/*
 *  SIO�γ���ߵ��ĥ롼����
 */
void
uart_TxRx_Enable(ID siopid)
{
	sil_wrw_mem((VP)BBBIE_REG,
				sil_rew_mem((VP)BBBIE_REG) | siopcb_table[siopid].siopinib->BbbiTx 
		                                   | siopcb_table[siopid].siopinib->BbbiRx);
}

/*
 *  SIO�γ���߶ػߥ롼����
 */
void
uart_TxRx_Disable(ID siopid)
{
		sil_wrw_mem((VP)BBBIE_REG,
				sil_rew_mem((VP)BBBIE_REG) & ~(siopcb_table[siopid].siopinib->BbbiTx
												 | siopcb_table[siopid].siopinib->BbbiRx) );
}

/*
 * ���ߤΥ��ꥢ��ݡ��Ȥμ���
 */
ID
uart_get_id(SIOPCB *siopcb)
{
	return(siopcb->siopid);
}

