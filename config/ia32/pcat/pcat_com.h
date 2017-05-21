/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2002 by Monami software, Limited Partners.
 *  Copyright (C) 2002 by MURANAKA Masaki
 *  Copyright (C) 2008-     by Monami Software Limited Partnership, JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
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
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id$
 */

/*
 *	COM�ɥ饤�С�PC/AT�ѡ�
 */

#ifndef _PCAT_COM_H_
#define _PCAT_COM_H_

#include <s_services.h>

#define SIO_ERDY_RCV (1u)
#define SIO_ERDY_SND (2u)

#ifndef _MACRO_ONLY

/*
 *  ���ꥢ��ݡ��ȤΥϡ��ɥ�������¸��������
 */
typedef struct {
  short base_address;
  short com_irq;
	UH divisor_latch;
} SIOPINIB;
typedef struct pcat_hardware_serial_port_descripter {
	const SIOPINIB *siopinib;
  INT	    initflag;	   /* ������ѥե饰�ؤΥݥ���   */
  VP_INT spcb;
} SIOPCB;

/*
 *  ���ꥢ��I/O�ݡ��Ȥν����
 */
extern void pcat_com_initialize();

extern void pcat_com1_handler();
#if TNUM_PORT >= 2
extern void pcat_com2_handler();
#endif

extern SIOPCB *pcat_com_opn_por(ID portid, VP_INT spcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥν�λ
 */
extern void pcat_com_cls_por(SIOPCB *p);

extern void pcat_com_ierdy_rcv(VP_INT exinf);

extern void pcat_com_ierdy_snd(VP_INT exinf);

/*
 *  ��������ʸ���μ��Ф�
 */
extern INT pcat_com_rcv_chr(SIOPCB *p);

/*
 *  ��������ʸ���ν񤭹���
 */
extern BOOL pcat_com_snd_chr(SIOPCB *p, char c);

extern void pcat_com_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

extern void pcat_com_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

extern void pcat_com_init(ID siopid);

extern void pcat_com_putc(ID siopid, char c);

#endif /* _MACRO_ONLY */

#endif /* _PCAT_COM_H_ */
