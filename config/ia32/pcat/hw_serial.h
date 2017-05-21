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
 *  @(#) $Id: hw_serial.h,v 1.1 2004/07/21 02:49:36 monaka Exp $
 */

/*
 *	�������åȰ�¸���ꥢ��I/O�⥸�塼���PC/AT�ѡ�
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#include <irc.h>
#include <pcat_com.h>

/*
 *  ���ꥢ��I/O�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define INHNO_SIO1	 PCAT_COM1_INHNO
#if TNUM_PORT >= 2
#define INHNO_SIO2	 PCAT_COM2_INHNO
#endif

#ifndef _MACRO_ONLY

/*
 *  ���ꥢ��I/O�ݡ��Ȥν����
 */
#define sio_initialize pcat_com_initialize

#define sio1_handler pcat_com1_handler
#if TNUM_PORT >= 2
#define sio2_handler pcat_com2_handler
#endif

Inline SIOPCB *
sio_opn_por(ID portid, VP_INT spcb)
{
  SIOPCB *p;

  p = pcat_com_opn_por(portid, spcb);

  irc_ena_irq(p->siopinib->com_irq);

  return p;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥν�λ
 */
Inline void
sio_cls_por(SIOPCB *p)
{
	pcat_com_cls_por(p);
  irc_dis_irq(p->siopinib->com_irq);
}

#define sio_ierdy_rcv pcat_com_ierdy_rcv

#define sio_ierdy_snd pcat_com_ierdy_snd

/*
 *  ��������ʸ���μ��Ф�
 */
#define sio_rcv_chr pcat_com_rcv_chr

/*
 *  ��������ʸ���ν񤭹���
 */
#define sio_snd_chr pcat_com_snd_chr

#define sio_ena_cbr pcat_com_ena_cbr

#define sio_dis_cbr pcat_com_dis_cbr

#endif /* _MACRO_ONLY */

#endif /* _HW_SERIAL_H_ */
