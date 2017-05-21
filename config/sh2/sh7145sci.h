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
 *  @(#) $Id: sh7145sci.h,v 1.1 2005/07/06 00:45:07 honda Exp $
 */

/*
 *   SH2��¢���ꥢ�륳�ߥ�˥�������󥤥󥿥ե�����SCI�� �ʰץɥ饤��
 */

#ifndef _sh7145sci_H_
#define _sh7145sci_H_

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
#define SCI_SCR	0x2
#define SCI_SSR	0x4
#define SCI_BRR	0x1
#define SCI_SMR	0x0
#define SCI_TDR	0x3
#define SCI_RDR	0x5
#define SCI_SDCR 0x6


/*
 *  ����ȥ���쥸������������
 */
#define SCI_TIE		0x80		/* �ȥ�󥹥ߥåȥ��󥿥�ץȥ��͡��֥� */
#define SCI_RIE		0x40		/* �쥷���֥��󥿥�ץȥ��͡��֥�   */
#define SCI_TE		0x20		/* �ȥ�󥹥ߥåȥ��͡��֥�         */
#define SCI_RE		0x10		/* �쥷���֥��͡��֥�           */
#define SSR_ORER	0x20		/* �����С���󥨥顼           */
#define SSR_FER		0x10		/* �ե졼�ߥ󥰥��顼           */
#define SSR_PER		0x08		/* �ѥ�ƥ����顼           */
#define SSR_TDRE	0x80		/* �ȥ�󥹥ߥåȥǡ����쥸��������ץƥ� */
#define SSR_RDRF	0x40		/* �쥷���֥ǡ����쥸�����ե�       */

#define sh2sci_DELAY 	105000

#define PFC_TXD0	0x0004
#define PFC_RXD0	0x0001
#define PFC_TXD1	0x0100
#define PFC_RXD1	0x0040
#define PFC_TXD2	0x0020
#define PFC_RXD2	0x8000

/*
 *  SCI������
 */
#define SMR_CKS 	0x0			/*  ʬ����          */
#define BRR9600 	79			/*  9600 �ӥåȥ졼��    */
#define BRR19200	39			/*  19200 �ӥåȥ졼��    */
#define BRR38400	19			/*  38400 �ӥåȥ졼��    */

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND	1u		/* ������ǽ������Хå� */
#define SIO_ERDY_RCV	2u		/* �������Υ�����Хå� */

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void sh2sci_initialize (void);

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
extern BOOL sh2sci_openflag (ID siopid);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB *sh2sci_opn_por (ID siopid, VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void sh2sci_cls_por (SIOPCB * siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern BOOL sh2sci_snd_chr (SIOPCB * siopcb, char c);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern INT sh2sci_rcv_chr (SIOPCB * siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void sh2sci_ena_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void sh2sci_dis_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
extern void sh2sci_isr (void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void sh2sci_ierdy_snd (VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void sh2sci_ierdy_rcv (VP_INT exinf);

#endif /* _sh7145sci_H_ */
