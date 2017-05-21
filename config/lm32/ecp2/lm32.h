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
 *  @(#) $Id: lm32.h,v 1.14 2007/07/27 11:28:44 honda Exp $
 */

#ifndef _LM32_H_
#define _LM32_H_

#define MICO32_CPU_CLOCK_HZ     (25000000)
//#define MICO32_CPU_CLOCK_HZ   (100000000)

#define DEFAULT_UART_BAUDRATE  (115200)

#define TIMER_BASE_REG          (0x80000100)
#define UART1_BASE_REG          (0x80000180)

/*
 * Timer Registers
 */
#define TIMER_STATUS            (TIMER_BASE_REG)
#define TIMER_CONTROL           (TIMER_BASE_REG + 0x04)
#define TIMER_PERIOD            (TIMER_BASE_REG + 0x08)
#define TIMER_SNAPSHOT          (TIMER_BASE_REG + 0x0C)

#define TIMER_STATUS_TO         (0x01)
#define TIMER_CONTROL_ITO       (0x01)
#define TIMER_CONTROL_CONT      (0x02)
#define TIMER_CONTROL_START     (0x04)
#define TIMER_CONTROL_STOP      (0x08)

/*
 * UART0 Registers
 */
#define UART1_RX_TX    (UART1_BASE_REG)
#define UART1_IER      (UART1_BASE_REG + 0x04)
#define UART1_IIR      (UART1_BASE_REG + 0x08)
#define UART1_LCR      (UART1_BASE_REG + 0x0C)
#define UART1_MCR      (UART1_BASE_REG + 0x10)
#define UART1_LSR      (UART1_BASE_REG + 0x14)
#define UART1_MSR      (UART1_BASE_REG + 0x18)
#define UART1_DIV      (UART1_BASE_REG + 0x1C)

/*
 * UART1 Registers
 */
#define UART2_RX_TX    (UART2_BASE_REG)
#define UART2_IER      (UART2_BASE_REG + 0x04)
#define UART2_IIR      (UART2_BASE_REG + 0x08)
#define UART2_LCR      (UART2_BASE_REG + 0x0C)
#define UART2_MCR      (UART2_BASE_REG + 0x10)
#define UART2_LSR      (UART2_BASE_REG + 0x14)
#define UART2_MSR      (UART2_BASE_REG + 0x18)
#define UART2_DIV      (UART2_BASE_REG + 0x1C)

#define UART_IER_RX_INT_MASK    (0x01)
#define UART_IER_TX_INT_MASK    (0x02)
#define UART_LSR_RX_RDY_MASK    (0x01)
#define UART_LSR_TX_RDY_MASK    (0x20)
#define UART_IIR_RXRDY          (0x04)
#define UART_IIR_TXRDY          (0x02)

#define MAX_INT_NUM     32

#define INHNO_TIMER     0
#define INHNO_SIO1		1

#define TNUM_PORT   1
#define TNUM_SIOP   1

#ifndef _MACRO_ONLY

extern void uart1_isr(void);
extern void uart2_isr(void);

typedef struct sio_port_initialization_block 
{
    volatile VP rxtx;
    volatile VP ier;
    volatile VP iir;
    volatile VP lcr;
    volatile VP mcr;
    volatile VP lsr;
    volatile VP msr;
    volatile VP div;
}
SIOPINIB;

typedef struct sio_port_control_block 
{
    const SIOPINIB  *siopinib;
    VP_INT          exinf;
    BOOL            openflag;
    BOOL            sendflag;
    BOOL            getready;
    BOOL            putready;
    UW              ier_snapshot;
}SIOPCB;

#define SIO_ERDY_SND    1u
#define SIO_ERDY_RCV    2u

extern void      uart_putc(char c);
extern void      uart_initialize(void);
extern BOOL      uart_openflag(void);
extern SIOPCB   *uart_opn_por(ID siopid, VP_INT exinf);
extern void      uart_cls_por(SIOPCB *siopcb);
extern BOOL      uart_snd_chr(SIOPCB *siopcb, char c);
extern INT       uart_rcv_chr(SIOPCB *siopcb);
extern void      uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);
extern void      uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);
extern void      uart_in_isr(void);
extern void      uart_out_isr(void);
extern void      uart_ierdy_snd(VP_INT exinf);
extern void      uart_ierdy_rcv(VP_INT exinf);

#endif /* _MACRO_ONLY */
#endif /* _LM32_H_ */
