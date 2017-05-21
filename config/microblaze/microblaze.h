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
 *  @(#) $Id: microblaze.h,v 1.6 2004/02/05 09:16:25 honda Exp $
 */

#ifndef _MICROBLAZE_H_
#define _MICROBLAZE_H_



#ifndef _MACRO_ONLY
#include <itron.h>
#include <sil.h>
#endif /* _MACRO_ONLY */


/*
 *  MSR�Υӥå�
 */
#define MSR_CC  0x80000000
#define MSR_DCE 0x80
#define MSR_DZ  0x40
#define MSR_ICE 0x20
#define MSR_FSL 0x10
#define MSR_BIP 0x08
#define MSR_C   0x04
#define MSR_IE  0x02
#define MSR_BE  0x01


/*
 * INTC Registers
 */
#define INTC_INT_STATUS_REG    0x00
#define INTC_INT_PENDING_REG   0x04
#define INTC_INT_ENABLE_REG    0x08
#define INTC_INT_ACK_REG       0x0c
#define INTC_SET_INT_ENABLE    0x10
#define INTC_CLEAR_INT_ENABLE  0x14
#define INTC_INT_VECTOR_REG    0x18
#define INTC_MASTER_ENABLE_REG 0x1c

/* 
 * Masks for the INTC Registers
 */
#define INTC_HIE_MASK 0x2
#define INTC_ME_MASK  0x1



#define INTC_ISR (INTC_BASE + INTC_INT_STATUS_REG)
#define INTC_IPR (INTC_BASE + INTC_INT_PENDING_REG)
#define INTC_IER (INTC_BASE + INTC_INT_ENABLE_REG)
#define INTC_IAR (INTC_BASE + INTC_INT_ACK_REG)
#define INTC_SIE (INTC_BASE + INTC_SET_INT_ENABLE)
#define INTC_CIE (INTC_BASE + INTC_CLEAR_INT_ENABLE)
#define INTC_IVR (INTC_BASE + INTC_INT_VECTOR_REG)
#define INTC_MER (INTC_BASE + INTC_MASTER_ENABLE_REG)

#ifndef _MACRO_ONLY
/*
 *  INTC���ؿ�
 */
Inline void
intc_start(void){
  sil_wrw_mem((VP)INTC_MER, INTC_HIE_MASK | INTC_ME_MASK);
}

Inline void
intc_disable_allinterrupt(){
  sil_wrw_mem((VP)INTC_MER, 0);
}

Inline void
intc_enable_interrupt(UW mask)
{
  sil_wrw_mem((VP)INTC_SIE, mask);
}

Inline void
intc_disable_interrupt(UW mask)
{
  sil_wrw_mem((VP)INTC_CIE, mask);
}

Inline void
intc_ack_interrupt(UW mask)
{
  sil_wrw_mem((VP)INTC_IAR, mask);
}

#endif /* _MACRO_ONLY */



/*
 * �����ޥɥ饤���ѤΥޥ������
 */


/*
 * Masks for the control/status register
 */
#define TIMER_ENABLE_ALL    0x400
#define TIMER_PWM           0x200
#define TIMER_INTERRUPT     0x100
#define TIMER_ENABLE        0x080
#define TIMER_ENABLE_INTR   0x040
#define TIMER_RESET         0x020
#define TIMER_RELOAD        0x010
#define TIMER_EXT_CAPTURE   0x008
#define TIMER_EXT_COMPARE   0x004
#define TIMER_DOWN_COUNT    0x002
#define TIMER_CAPTURE_MODE  0x001

#define TIMER_CONTROL_STATUS_0  0x0
#define TIMER_COMPARE_CAPTURE_0 0x4
#define TIMER_COUNTER_0         0x8
#define TIMER_CONTROL_STATUS_1  0x10
#define TIMER_COMPARE_CAPTURE_1 0x14
#define TIMER_COUNTER_1         0x18


#define TIMER_TCSR0 (TIMER_BASE + TIMER_CONTROL_STATUS_0)
#define TIMER_TCCR0 (TIMER_BASE + TIMER_COMPARE_CAPTURE_0)
#define TIMER_TCR0  (TIMER_BASE + TIMER_COUNTER_0)
#define TIMER_TCSR1 (TIMER_BASE + TIMER_CONTROL_STATUS_1)
#define TIMER_TCCR1 (TIMER_BASE + TIMER_COMPARE_CAPTURE_1)
#define TIMER_TCR1  (TIMER_BASE + TIMER_COUNTER_1)


/*
 *  UART�ɥ饤���ѤΥޥ������
 */

/*
 * Error condition masks 
 */
#define UARTLITE_PAR_ERROR     0x80
#define UARTLITE_FRAME_ERROR   0x40
#define UARTLITE_OVERRUN_ERROR 0x20


/*
 * Other status bit masks
 */
#define UARTLITE_INTR_ENABLED       0x10
#define UARTLITE_TX_FIFO_FULL       0x08
#define UARTLITE_TX_FIFO_EMPTY      0x04
#define UARTLITE_RX_FIFO_FULL       0x02
#define UARTLITE_RX_FIFO_VALID_DATA 0x01

/*
 * Control bit masks 
 */
#define UARTLITE_ENABLE_INTR  0x10
#define UARTLITE_RST_RX_FIFO  0x02
#define UARTLITE_RST_TX_FIFO  0x01

/*
 * UARTLITE Registers
 */
#define UARTLITE_RECEIVE_REG  0x0
#define UARTLITE_TRANSMIT_REG 0x4
#define UARTLITE_STATUS_REG   0x8
#define UARTLITE_CONTROL_REG  0xc


#define UARTLITE_RXREG (UART_BASE + UARTLITE_RECEIVE_REG)
#define UARTLITE_TXREG (UART_BASE + UARTLITE_TRANSMIT_REG)
#define UARTLITE_SRREG (UART_BASE + UARTLITE_STATUS_REG)
#define UARTLITE_CTREG (UART_BASE + UARTLITE_CONTROL_REG)



#ifndef _MACRO_ONLY
/*                                                                          
 * ��¢UART�� �ʰ�SIO�ɥ饤��                                                 
 */

/*                                                                            
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�                                         
 */
typedef struct sio_port_initialization_block {

} SIOPINIB;

/*                                                                            
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å�                                            
 */
typedef struct sio_port_control_block {
    const SIOPINIB  *siopinib;  /* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
    VP_INT          exinf;      /* ��ĥ���� */
    BOOL    openflag;           /* �����ץ�Ѥߥե饰 */
    BOOL    sendflag;           /* ��������ߥ��͡��֥�ե饰 */
    BOOL    getready;           /* ʸ��������������� */
    BOOL    putready;           /* ʸ���������Ǥ������ */
} SIOPCB;

extern SIOPCB   siopcb_table[];

#define uart_openflag   (siopcb_table[0].openflag)

Inline void
uart_putc(unsigned char c){
  while(sil_rew_mem((VP)UARTLITE_SRREG) & UARTLITE_TX_FIFO_FULL);
  sil_wrw_mem((VP)UARTLITE_TXREG, c);
}

Inline unsigned char
uart_getc(void){
  while(!(sil_rew_mem((VP)UARTLITE_SRREG) & UARTLITE_RX_FIFO_VALID_DATA));
  return (char)(sil_rew_mem((VP)UARTLITE_RXREG));
}

/*
 *  ������Хå��롼����μ����ֹ�
 *  OPB_UARTLITE �ϡ�����������ߤ�ʬ����Ƥ��ʤ����ᡤ��̣�Ϥʤ���
 */
#define SIO_ERDY_SND    1u              /* ������ǽ������Хå� */
#define SIO_ERDY_RCV    2u              /* �������Υ�����Хå� */


/*                                                                           
 *  SIO�ɥ饤�Фν�����롼����                                                
 */
extern void uart_initialize(void);


/*                                                                           
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�                                              
 */
extern SIOPCB   *uart_opn_por(ID siopid, VP_INT exinf);

/*                                                                         
 *  ���ꥢ��I/O�ݡ��ȤΥ�����                                             
 */
extern void uart_cls_por(SIOPCB *siopcb);

/*                                                                            
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������                                            
 */
extern BOOL uart_snd_chr(SIOPCB *siopcb, INT chr);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern INT  uart_rcv_chr(SIOPCB *siopcb);


/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);


/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);


/*                                                                            
 *  SIO�γ���ߥ����ӥ��롼����                                              
 */
extern void uart_isr(void);


/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void uart_ierdy_snd(VP_INT exinf);


/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void uart_ierdy_rcv(VP_INT exinf);




#endif  /* _MACRO_ONLY */

#endif /* _MICROBLAZE_H_*/

