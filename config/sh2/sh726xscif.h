/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2010 by Cronus Computer Works, JAPAN
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
 *  @(#) $Id: sh7615scif.h,v 1.1 2005/07/06 00:45:07 honda Exp $
 */

/*
 *   SH2��¢���ꥢ�륳�ߥ�˥�������󥤥󥿥ե�����SCI�� �ʰץɥ饤��
 */

#ifndef _SH726xSCI_H_
#define _SH726xSCI_H_

#include <t_config.h>

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
typedef struct sio_port_initialization_block
{
	UW reg_base;				/* �쥸�����Υ١������ɥ쥹 */
	UB brr;						/* �ܡ��졼�Ȥ�������   */
	UB smr;						/* �⡼�ɥ쥸������������   */
	UB int_level;				/* �����ߥ�٥��������   */
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å�
 */
typedef struct sio_port_control_block
{
	const SIOPINIB *siopinib;	/* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
	VP_INT exinf;				/* ��ĥ���� */
	BOOL openflag;				/* �����ץ�Ѥߥե饰 */
	BOOL sendflag;				/* ��������ߥ��͡��֥�ե饰 */
	BOOL getready;				/* ʸ��������������� */
	BOOL putready;				/* ʸ���������Ǥ������ */
} SIOPCB;

/*
 *  ����ȥ���쥸�����Υ��ɥ쥹�Υ��ե��å� 
 */
#define SCIF_SCFSR	0x10
#define SCIF_SCLSR	0x24
#define SCIF_SCFRDR	0x14
#define SCIF_SCFTDR	0x0c
#define SCIF_SCSCR	0x08
#define SCIF_SCFCR	0x18
#define SCIF_SCSMR	0x00
#define SCIF_SCBRR	0x04

/*
 *  ����ȥ���쥸������������
 */
/*  FIFO����ȥ���쥸����SCFCR�Υӥå�  */
#define SCFCR_TFRST	0x0004		/* �ȥ�󥹥ߥå�FIFO�ǡ����쥸�����ꥻ�å� */
#define SCFCR_RFRST	0x0002		/* �쥷����FIFO�ǡ����쥸�����ꥻ�å� */
/*  ���ꥢ�륳��ȥ���쥸����SCSCR�Υӥå�  */
#define SCSCR_TIE	0x0080		/* �ȥ�󥹥ߥåȥ��󥿥�ץȥ��͡��֥� */
#define SCSCR_RIE	0x0040		/* �쥷���֥��󥿥�ץȥ��͡��֥�   */
#define SCSCR_TE	0x0020		/* �ȥ�󥹥ߥåȥ��͡��֥�         */
#define SCSCR_RE	0x0010		/* �쥷���֥��͡��֥�           */
/*  ���ꥢ�륹�ơ������쥸����SC1SSR�Υӥå�  */
#define SCFSR_TEND	0x0040
#define SCFSR_TDFE	0x0020		/* �ȥ�󥹥ߥå�FIFO�ǡ����쥸��������ץƥ� */
#define SCFSR_ER	0x0080		/* �쥷���֥��顼       */
#define SCFSR_FER	0x0008		/* �ե졼�ߥ󥰥��顼       */
#define SCFSR_PER	0x0004		/* �ѥ�ƥ����顼       */
#define SCFSR_RDRF	0x0002		/* �쥷���֥ǡ����쥸�����ե�       */
#define SCFSR_BRK	0x0010		/* �֥졼������ */
/*  ���ꥢ�륹�ơ������쥸����SC2SSR�Υӥå�  */
#define SCLSR_ORER	0x01		/* �����С���󥨥顼 */

#define sh2scif_DELAY 	1000000


/*
 *  SCIF������
 */
#define SMR_CKS 	0x0			/*  ʬ���� P������å�/1 [�ѹ��Բ�] */
/* BRR�����ͤη׻� */
#define BRR_VALUE(bps)	(((PCLOCK / 32) / (bps)) - 1)

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND	1u		/* ������ǽ������Хå� */
#define SIO_ERDY_RCV	2u		/* �������Υ�����Хå� */

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void sh2scif_initialize (void);

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
extern BOOL sh2scif_openflag (ID siopid);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB *sh2scif_opn_por (ID siopid, VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void sh2scif_cls_por (SIOPCB * siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern BOOL sh2scif_snd_chr (SIOPCB * siopcb, char c);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern INT sh2scif_rcv_chr (SIOPCB * siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void sh2scif_ena_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void sh2scif_dis_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
extern void sh2scif_isr (void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void sh2scif_ierdy_snd (VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void sh2scif_ierdy_rcv (VP_INT exinf);

#endif /* _SH726xSCI_H_ */
