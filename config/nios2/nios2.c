/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2005 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: nios2.c,v 1.6 2005/07/17 14:24:04 honda Exp $
 */

/*
 * Nios2 ɸ��ڥ�ե�����ѥɥ饤��
 */
#include <s_services.h>
#include <nios2.h>


/*
 * UART �� �ʰץɥ饤��
 */

/*                                                                       
 * ���ꥢ��I/O�ݡ��Ƚ�����֥�å�                                         
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {{}};

/*                                                                      
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ                                
 */
SIOPCB  siopcb_table[TNUM_SIOP];

/*                                                                          
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���                  
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))

#ifdef USE_JTAG_UART
/*
 *  JTAG_UART �ϥ��ơ������ȥǡ�����Ʊ���˼������뤿�ᡤ���ơ�������
 *  �����å�����ȥǡ������ɤ߹���Ǥ��ޤ������Τ��ᡤuart_getready()
 *  ��¹Ԥ�����Υǡ���������롥  
 */ 
UB jtag_uart_buf = -1;
#endif /* USE_JTAG_UART */

/*
 * ʸ�������������?                                                       
 */
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	return((sil_rew_mem((VP)UART_STATUS) &
			UART_STATUS_RRDY) != 0);
#else
	UW tmp = sil_rew_mem((VP)JTAG_UART_DATA);
	jtag_uart_buf = (UB)tmp;	
	return ((tmp & JTAG_UART_DATA_RVALID) != 0);
#endif /* USE_JTAG_UART	*/	
}

/*                                                                             
 * ʸ���������Ǥ��뤫?                                                         
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART		
	return((sil_rew_mem((VP)UART_STATUS) & UART_STATUS_TRDY) != 0);
#else
	return((sil_rew_mem(
		(VP)JTAG_UART_CONTROL) & JTAG_UART_CONTROL_WSAPCE) > 0);
#endif /* USE_JTAG_UART	*/
}

/*                                                                             
 *  ��������ʸ���μ��Ф�                                                     
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	return((UB)(sil_rew_mem((VP)UART_RXDATA)));
#else
	return((UB)(sil_rew_mem((VP)JTAG_UART_DATA)));
#endif /* USE_JTAG_UART	*/
}

/*                                                                            
 *  ��������ʸ���ν񤭹���                                                    
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
#ifndef USE_JTAG_UART
	sil_wrw_mem((VP)UART_TXDATA, c);
#else
	sil_wrw_mem((VP)JTAG_UART_DATA,c);
#endif /* USE_JTAG_UART	*/
}

/*
 * ��������ؿ�
 */
/*                                                                             
 *  ��������ߵ���                                                             
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	sil_wrw_mem((VP)UART_CONTROL,
				sil_rew_mem((VP)UART_CONTROL)|UART_CONTROL_ITRD);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,
				sil_rew_mem((VP)JTAG_UART_CONTROL)|JTAG_UART_CONTROL_WIE);
#endif /* USE_JTAG_UART	*/	
}

/*                                                                             
 *  ��������߶ػ�                                                             
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	sil_wrw_mem((VP)UART_CONTROL,
				sil_rew_mem((VP)UART_CONTROL)&~UART_CONTROL_ITRD);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,
				sil_rew_mem((VP)JTAG_UART_CONTROL)&~JTAG_UART_CONTROL_WIE);
#endif /* USE_JTAG_UART	*/
}

/*
 * ��������ؿ�
 */
/*                                                                             
 *  ��������ߵ���                                                             
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	sil_wrw_mem((VP)UART_CONTROL,
				sil_rew_mem((VP)UART_CONTROL)|UART_STATUS_RRDY);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,
				sil_rew_mem((VP)JTAG_UART_CONTROL)|JTAG_UART_CONTROL_RIE);
#endif /* USE_JTAG_UART	*/
}

/*                                                                             
 *  ��������߶ػ�                                                             
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART	
	sil_wrw_mem((VP)UART_CONTROL,
				sil_rew_mem((VP)UART_CONTROL)&~UART_STATUS_RRDY);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,
				sil_rew_mem((VP)JTAG_UART_CONTROL)&~JTAG_UART_CONTROL_RIE);
#endif /* USE_JTAG_UART	*/	
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


SIOPCB   *
uart_opn_por(ID siopid, VP_INT exinf){

    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

#ifndef USE_JTAG_UART		
//    sil_wrw_mem(UART_DIVISOR, UART_DIVISOR_VAL);
    sil_wrw_mem((VP)UART_STATUS, 0x00);
    
    /*
     *  ���������ߵ���
     */
    sil_wrw_mem((VP)UART_CONTROL, UART_STATUS_RRDY);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,JTAG_UART_CONTROL_RIE);
#endif /* USE_JTAG_UART	*/
	
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);
}


void
uart_cls_por(SIOPCB *siopcb){
#ifndef USE_JTAG_UART	
    /* ����߶ػ� */
    sil_wrw_mem((VP)UART_CONTROL, 0x00);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,0x00);
#endif /* USE_JTAG_UART	*/		
    siopcb->openflag = FALSE;
    siopcb->sendflag = FALSE;
}



/*                                                                             
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������                                            
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, INT chr)
{
    if(uart_putready(siopcb)){
        uart_putchar(siopcb, (UB) chr);
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
#ifndef USE_JTAG_UART
	if (uart_getready(siopcb)) {
		return((INT)(UB) uart_getchar(siopcb));
	}
	return(-1);
#else
	UB tmp;
	
	if (jtag_uart_buf != -1) {
		tmp = jtag_uart_buf;
		jtag_uart_buf = -1;
		return tmp;
	}
	return(-1);
#endif /* USE_JTAG_UART	*/	
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

