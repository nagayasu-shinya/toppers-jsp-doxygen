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
 */

/*
 *   CQ-FRK-NXP-ARM UART�� �ʰ�SIO�ɥ饤��
 *
 *   ���Υե�����ϡ�TOPPERS/JSP 1.4.2�� pdic/simple_sio/st16c2550.h��
 *   ��͡��ष�������μ��̻Ҥ��ѹ�������ΤǤ��롣
 */
#ifndef _UART_H_
#define _UART_H_

#include <t_config.h>

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
typedef struct sio_port_initialization_block {
    UW reg_base;    	/* �쥸�����Υ١������ɥ쥹 */
    UB dlm_val;     	/* �ܡ��졼�Ⱦ�̤�������   */
    UB dll_val;  	  	/* �ܡ��졼�Ȳ��̤�������   */
	UB set_ucen:1;		/* 1�ΤȤ���GCTL��UCEN��1�ˤ���(ADSP-BF53x�Τ�) */
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å�
 */
typedef struct sio_port_control_block {
    const SIOPINIB  *siopinib; /* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
    VP_INT          exinf;     /* ��ĥ���� */
    BOOL    openflag;          /* �����ץ�Ѥߥե饰 */
    BOOL    sendflag;          /* ��������ߥ��͡��֥�ե饰 */
    BOOL    getready;          /* ʸ��������������� */
    BOOL    putready;          /* ʸ���������Ǥ������ */
}SIOPCB;


/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND    1u      /* ������ǽ������Хå� */
#define SIO_ERDY_RCV    2u      /* �������Υ�����Хå� */


/*
 * �����ͥ뵯ư���Ѥν����(sys_putc����Ѥ��뤿��)
 */
extern void uart_init(void);

/*
 *  ���ꥢ��I/O�ݡ��ȤؤΥݡ���󥰤Ǥν���
 */
extern void uart_pol_putc(char c, ID siopid);


/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void uart_initialize(void);


/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
extern BOOL uart_openflag(void);


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
extern BOOL uart_snd_chr(SIOPCB *siopcb, char c);


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
extern void uart0_tx_isr(void);
extern void uart0_rx_isr(void);


/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void uart_ierdy_snd(VP_INT exinf);


/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void uart_ierdy_rcv(VP_INT exinf);


#endif
