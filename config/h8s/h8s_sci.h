/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

#ifndef _H8S_SCI_H_
#define _H8S_SCI_H_

#include <s_services.h>		/* �ǥХ����ɥ饤����ɸ�।�󥯥롼�ɥե����� */
#include <h8s_sil.h>

/*
 *  H8S ��¢���ꥢ�륳�ߥ�˥�������󥤥󥿥ե�����(SCI)��Ϣ�����
 */

/* SCI�쥸�����Υ��ɥ쥹 */
/* �١������ɥ쥹 */
#define SCI0_BASE_ADDR	0xff78	/* ����ͥ룰 */
#define SCI1_BASE_ADDR	0xff80	/* ����ͥ룱 */
/* �쥸�������ե��å� */
#define SMR		0	/* ���ꥢ��⡼�ɥ쥸������ */
#define BRR		1	/* �ӥåȥ졼�ȥ쥸���� */
#define SCR		2	/* ���ꥢ�륳��ȥ���쥸���� */
#define TDR		3	/* �ȥ�󥹥ߥåȥǡ����쥸���� */
#define SSR		4	/* ���ꥢ�륹�ơ������쥸���� */
#define RDR		5	/* �쥷���֥ǡ����쥸���� */
#define SCMR		6	/* ���ޡ��ȥ����ɥ⡼�ɥ쥸���� */

/* �ƥ쥸�����Υӥåȥѥ����� */

/* RSR, RDR, TSR, TDR */
/* ������٤���Τϡ��ä�̵�� */

/* SMR */
#define CA	BIT7
#define	CHR	BIT6	/* 8bit = 0 / 7bit = 1 */
#define	PE	BIT5	/* Parity OFF = 0 / Parity ON = 1 */
#define	OE	BIT4	/* EVEN Parity = 0 / ODD Parity = 1 */
#define	STOP	BIT3	/* 1 STOP BIT = 0 / 2 STOP BIT = 1 */
#define MP	BIT2
#define	CSK1	BIT1
#define	CSK0	BIT0

/* SCR */
#define TIE	BIT7
#define	RIE	BIT6
#define	TE	BIT5
#define	RE	BIT4
#define	MPIE	BIT3
#define TEIE	BIT2
#define	CKE1	BIT1
#define	CKE0	BIT0

/* SSR */
#define TDRE	BIT7
#define	RDRF	BIT6
#define	ORER	BIT5
#define	FER	BIT4
#define	PER	BIT3
#define TEND	BIT2
#define	MPB	BIT1
#define	MPBT	BIT0

/*
 *  �ܡ��졼�ȴط������
 *    ư����ȿ���20 [MHz] �ʤΤǡ��ޥ˥奢��p567����ޤ롣
 */
#if BAUD_RATE == 9600		/* �ӥåȥ졼�ȡ� 9600 [bit/s] */
	#define BRR_RATE	64	/* N = 64 */
#elif BAUD_RATE == 38400	/* �ӥåȥ졼�ȡ�38400 [bit/s] */
	#define BRR_RATE	15	/* N = 15 */
#elif BAUD_RATE == 57600	/* �ӥåȥ졼�ȡ�57600 [bit/s] */
	#define BRR_RATE	10	/* N = 10 */
#endif

#ifndef _MACRO_ONLY

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
typedef struct sio_port_control_block	SIOPCB;

#endif /* _MACRO_ONLY */

/*
 *  SCI�ѥ����ƥ।�󥿥ե������쥤�䡼
 */
/* x : �ݡ��ȤΥ١������ɥ쥹(UW ��)
   y : �쥸�������ե��å�(UW ��)
   z : �쥸������ */
#define h8s_sci_wrb( x, y, z )	h8s_wrb_mem( (VP)(x + y), z )
#define h8s_sci_reb( x, y )	h8s_reb_mem( (VP)(x + y) )

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND	1u		/* ������ǽ������Хå� */
#define SIO_ERDY_RCV	2u		/* �������Υ�����Хå� */

#ifndef _MACRO_ONLY

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void	h8s_sci_initialize(void);

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
extern BOOL	h8s_sci_openflag(void);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB	*h8s_sci_opn_por(ID siopid, VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void	h8s_sci_cls_por(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern BOOL	h8s_sci_snd_chr(SIOPCB *siopcb, char c);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern INT	h8s_sci_rcv_chr(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void	h8s_sci_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void	h8s_sci_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
extern void	h8s_sci_isr_in(void);
extern void	h8s_sci_isr_out(void);

/*
 *  SIO�μ������顼����ߥ����ӥ��롼����
 */
extern void	h8s_sci_isr_error(void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void	h8s_sci_ierdy_snd(VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void	h8s_sci_ierdy_rcv(VP_INT exinf);

/*
 *  �����ͥ뵯ư���Ѥν���� (sys_putc������)
 */
extern void	h8s_sci_init(void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ�������ʥݡ���󥰡�
 */
extern void	h8s_sci_putchar_pol(char c);

#endif /* _MACRO_ONLY */

#endif /* _H8S_sci_H_ */
