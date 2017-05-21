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
 *  @(#) $Id: microblaze.c,v 1.8 2003/12/11 04:52:44 honda Exp $
 */

/*                                                                              * Microblaze ɸ��ڥ�ե�����ѥɥ饤��
 */
#include <s_services.h>
#include <microblaze.h>


/*
 * UART Lite�� �ʰץɥ饤��
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

Inline void
uart_ena_int(void){
  sil_wrw_mem((VP)UARTLITE_CTREG,
              sil_rew_mem((VP)UARTLITE_CTREG) | UARTLITE_ENABLE_INTR);
}

Inline void
uart_dis_int(void){
  sil_wrw_mem((VP)UARTLITE_CTREG,
              sil_rew_mem((VP)UARTLITE_CTREG) & ~UARTLITE_ENABLE_INTR);
}

/*
 * ʸ�������������?                                                       
 */
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
    return((sil_rew_mem((VP)UARTLITE_SRREG) &
            UARTLITE_RX_FIFO_VALID_DATA) != 0);

}

/*                                                                             
 * ʸ���������Ǥ��뤫?                                                         
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
  return((sil_rew_mem((VP)UARTLITE_SRREG) & UARTLITE_TX_FIFO_FULL) == 0);
}

/*                                                                             
 *  ��������ʸ���μ��Ф�                                                     
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
    return((UB)sil_rew_mem((VP)UARTLITE_RXREG));
}

/*                                                                            
 *  ��������ʸ���ν񤭹���                                                    
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
  sil_wrw_mem((VP)UARTLITE_TXREG, c);
}

/*
 * ��������ؿ�
 * UART Lite �ˤ���������ߤ���̤˶ػߵ��Ĥ��뵡ǽ�Ϥʤ�
 * ���Τ��ᡤ������λ���ˤ�ɬ��1�����ߤ�����  
 */
/*                                                                             
 *  ��������ߵ���                                                             
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
  
}

/*                                                                             
 *  ��������߶ػ�                                                             
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{

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

    /*
     *  �������Хåե����ꥢ
     */
    sil_wrw_mem((VP)UARTLITE_CTREG, UARTLITE_RST_RX_FIFO
                | UARTLITE_RST_TX_FIFO | UARTLITE_ENABLE_INTR);
    
//    sil_wrw_mem((VP)UARTLITE_CTREG, UARTLITE_RST_RX_FIFO
//                | UARTLITE_RST_TX_FIFO );
    
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);
}


void
uart_cls_por(SIOPCB *siopcb){
  sil_wrw_mem((VP)UARTLITE_CTREG, ~UARTLITE_ENABLE_INTR);   /* ����߶ػ�    */
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
    if (uart_getready(siopcb)) {
        return((INT)(UB) uart_getchar(siopcb));
    }
    return(-1);
}

/*
 *  OPB_UARTLITE �������ȼ�������ߤ���̤˵���/�ػߤ��뵡ǽ�ϻ����ʤ�
 */

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{

}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{

}


/*                                                                            
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф������߽���                                       
 */
static void
uart_isr_siop(SIOPCB *siopcb)
{
    /*
     * ���å�����ߤΤ������߽�������ACK
     */
    intc_ack_interrupt(1 << (UARTINTLVL - 1));
    
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

