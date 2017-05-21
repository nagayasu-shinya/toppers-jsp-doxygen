/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2003-2004 by CHUO ELECTRIC WORKS Co.,LTD. JAPAN
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
 *�������ꥢ��I/O�ǥХ�����SIO�˥ɥ饤��
 *����(��)������������ITRON���SH1CPU�ܡ�����
 *��������SH1��¢���ꥢ�륳�ߥ�˥�������󥤥󥿥ե�����SCI�����
 *
 *��������sh1sci.{c,h}��hw_serial.h��ʬ��δ��
 *��������������sh1sci.{c,h}�����ꥢ��ǥХ����˰�¸������ʬ�Τߵ���
 *��������������hw_serial.h�����ꥢ��ǥХ����ʳ��˵�����������
 *�������� ������������������hw_serial.h�˵��Ҥ���
 *��������������������������������ߥ���ȥ����¸�ʤ�
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#ifndef _MACRO_ONLY
#include "sh1sci2.h"
#endif /* _MACRO_ONLY */

/*
 *  SIO�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define INHNO_SERIAL_IN		RXI0
#define INHNO_SERIAL_OUT	TXI0
#define INHNO_SERIAL_ERROR  	ERI0

#define INHNO_SERIAL2_IN	RXI1
#define INHNO_SERIAL2_OUT	TXI1
#define INHNO_SERIAL2_ERROR	ERI1
#define INHNO_SERIAL2_TEI  	TEI1

#define LEVEL0		0	/*  ����߲�����Υ�٥�  */

#ifndef _MACRO_ONLY

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
#define	sio_initialize	sh1sci_initialize

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;
	BOOL	openflag;

	/*
	 *  �ݡ��ȥ����ץ󤷤����� openflag ���ɤ�Ǥ�����
	 */
	openflag = sh1sci_openflag(siopid);

	/*
	 *  �ǥХ�����¸�Υ����ץ������
	 */
	siopcb = sh1sci_opn_por(siopid, exinf);

	/*
	 *  ����ߥ���ȥ����¸
	 *  �����ꥢ��I/O����ߤγ���ߥ�٥�����ꤹ��
	 */
	 if (!openflag) {
		define_int_plevel(siopcb->inib->ipr, SCI_INTLVL, siopcb->inib->shift);
	 }
	 
	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
Inline void
sio_cls_por(SIOPCB *siopcb)
{
	/*
	 *  �ǥХ�����¸�Υ�����������
	 */
	sh1sci_cls_por(siopcb);

	/*
	 *  ���ꥢ��I/O����ߥ�٥������٥�ˤ���
	 */
	define_int_plevel(siopcb->inib->ipr, LEVEL0, siopcb->inib->shift);

}

/*
 *  SIO�γ���ߥϥ�ɥ�
 */
#define	sio_handler_in		sh1sci_isr_in		/*  ��������ߥϥ�ɥ�  */
#define	sio_handler_out		sh1sci_isr_out		/*  ��������ߥϥ�ɥ�  */
#define	sio_handler_error	sh1sci_isr_error	/*  �������顼����ߥϥ�ɥ� */

#define	sio2_handler_in		sh1sci2_isr_in		/*  ��������ߥϥ�ɥ�  */
#define	sio2_handler_out	sh1sci2_isr_out		/*  ��������ߥϥ�ɥ�  */
#define	sio2_handler_error	sh1sci2_isr_error	/*  �������顼����ߥϥ�ɥ� */
#define	sio2_handler_tend	sh1sci2_isr_tend	/*  ������λ����ߥϥ�ɥ�   */

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
#define	sio_snd_chr	sh1sci_snd_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
#define	sio_rcv_chr	sh1sci_rcv_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
#define	sio_ena_cbr	sh1sci_ena_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
#define	sio_dis_cbr	sh1sci_dis_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 *  ����jsp/systask/serial.c�ˤ�����Τ��͡��ष�Ƥ���
 *  �����ʰ����������ȡ�
 */
#define	sio_ierdy_snd	sh1sci_ierdy_snd

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 *  ����jsp/systask/serial.c�ˤ�����Τ��͡��ष�Ƥ���
 *  �����ʰ����������ȡ�
 */
#define	sio_ierdy_rcv	sh1sci_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
