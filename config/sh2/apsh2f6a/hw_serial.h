/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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
 *  @(#) $Id: hw_serial.h,v 1.5 2005/07/06 00:45:07 honda Exp $
 */

/*
 *�������ꥢ��I/O�ǥХ�����SIO/SCIF�˥ɥ饤�С�apsh02f6a�ѡ�
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#ifndef _MACRO_ONLY
#include "sh7145sci.h"
#endif /* _MACRO_ONLY */

/*
 *  SIO�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
#ifndef GDB_STUB

#define INHNO_SERIAL_IN	 RXI1
#define INHNO_SERIAL_OUT TXI1
#define INHNO_SERIAL_ERROR ERI1
#if TNUM_PORT >= 2
#define INHNO_SERIAL2_IN	 RXI0
#define INHNO_SERIAL2_OUT TXI0
#define INHNO_SERIAL2_ERROR ERI0
#endif /* TNUM_PORT >= 2 */

#else /* GDB_STUB */

#define INHNO_SERIAL_IN	 RXI0
#define INHNO_SERIAL_OUT TXI0
#define INHNO_SERIAL_ERROR ERI0

#endif /* GDB_STUB */

/*
 * SCI�γ����ߥ�٥�
 * ������ߥϥ�ɥ���������̡�����Ͽ�Ǥ��뤬������ߥ�٥��
 * �������������Ʊ����٥�ˤ�������Ǥ��ʤ���
 */
#define LEVEL0		0			/*  ����߲�����Υ�٥�  */

#ifndef _MACRO_ONLY

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
#define	sio_initialize	sh2sci_initialize

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
Inline SIOPCB *
sio_opn_por (ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb;
	BOOL openflag;

	/*
	 *  �����ץ󤷤��ݡ��Ȥ����뤫�� openflag ���ɤ�Ǥ�����
	 */
	openflag = sh2sci_openflag (siopid);

	/*
	 *  �ǥХ�����¸�Υ����ץ������
	 */
	siopcb = sh2sci_opn_por (siopid, exinf);

	/*
	 *  ����ߥ���ȥ����¸
	 *  �����ꥢ��I/O����ߤγ���ߥ�٥�����ꤹ��
	 */
	if (!openflag) {
		if ((siopcb->siopinib->reg_base) == 0xffff81c0)
			define_int_plevel (IPRI, siopcb->siopinib->int_level, 12);
		if ((siopcb->siopinib->reg_base) == 0xffff81a0)
			define_int_plevel (IPRF, siopcb->siopinib->int_level, 4);
		if ((siopcb->siopinib->reg_base) == 0xffff81b0)
			define_int_plevel (IPRF, siopcb->siopinib->int_level, 0);
	}
	return (siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
Inline void
sio_cls_por (SIOPCB * siopcb)
{
	/*
	 *  �ǥХ�����¸�Υ�����������
	 */
	sh2sci_cls_por (siopcb);

	/*
	 *  ���ꥢ��I/O����ߥ�٥������٥�ˤ���
	 */
	if ((siopcb->siopinib->reg_base) == 0xffff81c0)
		define_int_plevel (IPRI, LEVEL0, 12);
	if ((siopcb->siopinib->reg_base) == 0xffff81a0)
		define_int_plevel (IPRF, LEVEL0, 4);
	if ((siopcb->siopinib->reg_base) == 0xffff81b0)
		define_int_plevel (IPRF, LEVEL0, 0);
}

/*
 *  SIO�γ���ߥϥ�ɥ�
 */
#define	sio_handler_in	sh2sci_isr_in	/*  ��������ߥϥ�ɥ�  */
#define	sio_handler_out	sh2sci_isr_out	/*  ��������ߥϥ�ɥ�  */
#define	sio_handler_error sh2sci_isr_error	/*  �������顼����ߥϥ�ɥ�  */
#if TNUM_PORT >= 2
#define	sio_handler2_in		sh2sci_isr2_in	/*  ��������ߥϥ�ɥ�  */
#define	sio_handler2_out	sh2sci_isr2_out	/*  ��������ߥϥ�ɥ�  */
#define	sio_handler2_error	sh2sci_isr2_error	/*  �������顼����ߥϥ�ɥ�  */
#endif /* TNUM_PORT >= 2 */

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
#define	sio_snd_chr	sh2sci_snd_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
#define	sio_rcv_chr	sh2sci_rcv_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
#define	sio_ena_cbr	sh2sci_ena_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
#define	sio_dis_cbr	sh2sci_dis_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 *  ����jsp/systask/serial.c�ˤ�����Τ��͡��ष�Ƥ���
 *  �����ʰ����������ȡ�
 */
#define	sio_ierdy_snd	sh2sci_ierdy_snd

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 *  ����jsp/systask/serial.c�ˤ�����Τ��͡��ष�Ƥ���
 *  �����ʰ����������ȡ�
 */
#define	sio_ierdy_rcv	sh2sci_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
