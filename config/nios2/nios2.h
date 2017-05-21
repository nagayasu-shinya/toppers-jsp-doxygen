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
 *  @(#) $Id: nios2.h,v 1.5 2005/03/11 07:37:57 honda Exp $
 */

#ifndef _NIOSII_H_
#define _NIOSII_H_

#ifndef _MACRO_ONLY
#include <itron.h>
#endif /* _MACRO_ONLY */

/*
 *  ����ߥӥå�
 */
#define STATUS_U   0x02
#define STATUS_PIE 0x01

/*
 * ����ߤο�
 */
#define MAX_INT_NUM 32

/*
 * �㳰�θĿ�
 */
#define MAX_EXC_NUM 32


/*
 *  Timer
 *  Full-featured���ݡ��� 
 */

/*
 * ���ե��å���
 */
#define TIM_STATUS_OFFSET  0x00
#define TIM_CONTROL_OFFSET 0x04
#define TIM_PERIODL_OFFSET 0x08
#define TIM_PERIODH_OFFSET 0x0C
#define TIM_SNAPL_OFFSET 0x10
#define TIM_SNAPH_OFFSET 0x14

#define TIM_STATUS_RUN 0x02
#define TIM_STATUS_TO  0x01

#define TIM_CONTROL_STOP  0x08
#define TIM_CONTROL_START 0x04
#define TIM_CONTROL_COUNT 0x02
#define TIM_CONTROL_ITO   0x01

/*
 *
 */
#define TIM_STATUS  (TIM_BASE + TIM_STATUS_OFFSET)
#define TIM_CONTROL (TIM_BASE + TIM_CONTROL_OFFSET)
#define TIM_PERIODL (TIM_BASE + TIM_PERIODL_OFFSET)
#define TIM_PERIODH (TIM_BASE + TIM_PERIODH_OFFSET)
#define TIM_SNAPL   (TIM_BASE + TIM_SNAPL_OFFSET)
#define TIM_SNAPH   (TIM_BASE + TIM_SNAPH_OFFSET)


/*
 * UART
 */
#define UART_RXDATA_OFFSET  0x00
#define UART_TXDATA_OFFSET  0x04
#define UART_STATUS_OFFSET  0x08
#define UART_CONTROL_OFFSET 0x0C
#define UART_DIVISOR_OFFSET 0x10
#define UART_ENDOFPACKET_OFFSET 0x1C

#define UART_STATUS_EOP   0x1000
#define UART_STATUS_CTS   0x0800
#define UART_STATUS_DCTS  0x0400
#define UART_STATUS_E     0x0100
#define UART_STATUS_RRDY  0x0080
#define UART_STATUS_TRDY  0x0040
#define UART_STATUS_TMT   0x0020
#define UART_STATUS_TOE   0x0010
#define UART_STATUS_ROE   0x0008
#define UART_STATUS_BRK   0x0004
#define UART_STATUS_FE    0x0002
#define UART_STATUS_PE    0x0001

#define UART_CONTROL_IEOP  0x1000
#define UART_CONTROL_RTS   0x0800
#define UART_CONTROL_IDCTS 0x0400
#define UART_CONTROL_TRDK  0x0200
#define UART_CONTROL_IE    0x0100
#define UART_CONTROL_IRRDY 0x0080
#define UART_CONTROL_ITRD  0x0040
#define UART_CONTROL_ITMT  0x0020
#define UART_CONTROL_ITOE  0x0010
#define UART_CONTROL_IROE  0x0008
#define UART_CONTROL_IBRK  0x0004
#define UART_CONTROL_IFE   0x0002
#define UART_CONTROL_IPE   0x0001

#define UART_RXDATA  (UART_BASE + UART_RXDATA_OFFSET)
#define UART_TXDATA  (UART_BASE + UART_TXDATA_OFFSET)
#define UART_STATUS  (UART_BASE + UART_STATUS_OFFSET)
#define UART_CONTROL (UART_BASE + UART_CONTROL_OFFSET)
#define UART_DIVISOR (UART_BASE + UART_DIVISOR_OFFSET)
#define UART_ENDOFPACKET (UART_BASE + UART_ENDOFPACKET_OFFSET)


/*
 * JTAG UART��Ϣ
 */ 
#define JTAG_UART_DATA_OFFSET    0x00
#define JTAG_UART_CONTROL_OFFSET 0x04

#define JTAG_UART_DATA_RVALID 0x8000

#define JTAG_UART_CONTROL_RIE 0x01
#define JTAG_UART_CONTROL_WIE 0x02
#define JTAG_UART_CONTROL_RIP 0x04
#define JTAG_UART_CONTROL_WIP 0x08
#define JTAG_UART_CONTROL_WSAPCE 0x0ffff0000

#define JTAG_UART_DATA    (UART_BASE + JTAG_UART_DATA_OFFSET)
#define JTAG_UART_CONTROL (UART_BASE + JTAG_UART_CONTROL_OFFSET)


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
#ifndef USE_JTAG_UART	
	while(!(sil_rew_mem((VP)UART_STATUS) & UART_STATUS_TRDY));
	sil_wrw_mem((VP)UART_TXDATA, c);
#else
	while(!((sil_rew_mem((VP)JTAG_UART_CONTROL) & JTAG_UART_CONTROL_WSAPCE) > 0));
	sil_wrw_mem((VP)JTAG_UART_DATA, c);	
#endif /* USE_JTAG_UART	*/	
}

Inline unsigned char
uart_getc(void){
#ifndef USE_JTAG_UART	
	while(!(sil_rew_mem((VP)UART_STATUS) & UART_STATUS_RRDY));
	return (char)(sil_rew_mem((VP)UART_RXDATA));
#else
	int tmp;
	do{
		tmp = sil_rew_mem((VP)JTAG_UART_DATA);
	}while((tmp &JTAG_UART_DATA_RVALID) == 0);

	return (char)tmp;
#endif /* USE_JTAG_UART	*/			
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

#endif /* _NIOSII_H_ */

