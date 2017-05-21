/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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

#ifndef _VR4131_DSIU_H_
#define _VR4131_DSIU_H_

#include <s_services.h>		/* �ǥХ����ɥ饤����ɸ�।�󥯥롼�ɥե����� */

/*
 *  VR4131��¢�ǥХå����ꥢ�륤�󥿥ե�������˥å�(DSIU)��Ϣ�����
 *  (�ʰ�NS16550)
 */

/* DSIU�쥸�����Υ��ɥ쥹 */
#define DSIURB		0x0f000820	/* �����Хåե��쥸����(�꡼�ɻ�) */
#define DSIUTH		0x0f000820	/* �����ݻ��쥸����(�饤�Ȼ�) */
#define DSIUDLL		0x0f000820	/* ʬ���沼�̥쥸���� */
#define DSIUIE		0x0f000821	/* ����ߵ��ĥ쥸���� */
#define DSIUDLM		0x0f000821	/* ʬ�����̥쥸���� */
#define DSIUIID		0x0f000822	/* �����ɽ���쥸����(�꡼�ɻ�) */
#define DSIUFC		0x0f000822	/* FIFO ����쥸����(�饤�Ȼ�) */
#define DSIULC		0x0f000823	/* �饤������쥸���� */
#define DSIUMC		0x0f000824	/* ��ǥ�����쥸���� */
#define DSIULS		0x0f000825	/* �饤����֥쥸���� */
#define DSIUMS		0x0f000826	/* ��ǥ���֥쥸���� */
#define DSIUSC		0x0f000827	/* ������å��쥸���� */

/* for DSIULC */
#define	WORD_LENGTH_8		(BIT1 | BIT0)
#define	STOP_BITS_1		0u		/* BIT2 */
#define	PARITY_NON		0u		/* BIT3, 4 */
/* BIT5,6 ��ά */
#define	DIVISOR_LATCH_ACC	BIT7

/* for DSIUIE */
#define	DIS_INT			0u
#define	RECEIVE_DATA_AVAILABLE	BIT0
#define	TRANS_REG_EMPTY		BIT1
#define RECEIVE_LINE_STATUS	BIT2
#define MODEM_STATUS		BIT3

/* for DSIUMC */
#define	DTR			BIT0
#define	RTS			BIT1

/* for DSIUFC */
#define	FIFO_ENABLE		BIT0
#define	RECEIVE_FIFO_RESET	BIT1
#define	TRANS_FIFO_RESET	BIT2
#define RECEIVE_TRIG_1_BYTE	0u	/* BIT6, 7 */
#define RECEIVE_TRIG_4_BYTE	BIT6
#define	RECEIVE_TRIG_8_BYTE	BIT7
#define	RECEIVE_TRIG_14_BYTE	(BIT6 | BIT7)

/* for DSIUIID */
#define	INT_MASK		0x0eu
#define	INT_RECEIVE_DATA	BIT2
#define INT_CHAR_TIME_OUT	(BIT3 | BIT2)
#define	INT_TRANS_EMPTY		BIT1

/* for DSIULS */
#define	THRE			BIT5
#define TEMT			BIT6

/* �ܡ��졼������ط� */
#define	DIVISOR			XIN_CLOCK / (16u * DEVIDE_RATIO)

#ifndef _MACRO_ONLY

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
typedef struct sio_port_control_block	SIOPCB;

#endif /* _MACRO_ONLY */

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND	1u		/* ������ǽ������Хå� */
#define SIO_ERDY_RCV	2u		/* �������Υ�����Хå� */

#ifndef _MACRO_ONLY

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void	vr4131_dsiu_initialize(void);

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
extern BOOL	vr4131_dsiu_openflag(void);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB	*vr4131_dsiu_opn_por(ID siopid, VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void	vr4131_dsiu_cls_por(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern BOOL	vr4131_dsiu_snd_chr(SIOPCB *siopcb, char c);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern INT	vr4131_dsiu_rcv_chr(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void	vr4131_dsiu_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void	vr4131_dsiu_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
extern void	vr4131_dsiu_dsiu_isr(void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void	vr4131_dsiu_ierdy_snd(VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void	vr4131_dsiu_ierdy_rcv(VP_INT exinf);

/*
 *  �����ͥ뵯ư���Ѥν���� (sys_putc������)
 */
extern void	vr4131_dsiu_init(void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ�������ʥݡ���󥰡�
 */
extern void	vr4131_dsiu_putchar_pol(char c);

#endif /* _MACRO_ONLY */

#endif /* _VR4131_DSIU_H_ */
