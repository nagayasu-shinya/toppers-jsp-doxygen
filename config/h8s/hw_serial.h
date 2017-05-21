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

/*
 *	���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�H8S�ե��ߥ꡼�ѡ�
 */
#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <h8s_sci.h>

/*
 *  SIO�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
/* �ݡ��ȣ� */
#define INHNO_SERIAL1_ERROR	IRQ_ERI0
#define INHNO_SERIAL1_IN	IRQ_RXI0
#define INHNO_SERIAL1_OUT	IRQ_TXI0
#if TNUM_PORT >= 2
/* �ݡ��ȣ� */
#define INHNO_SERIAL2_ERROR	IRQ_ERI1
#define INHNO_SERIAL2_IN	IRQ_RXI1
#define INHNO_SERIAL2_OUT	IRQ_TXI1
#endif /* TNUM_PORT */

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
#define	sio_initialize		h8s_sci_initialize

/*
 *  �����ͥ뵯ư���Ѥν���� (sys_putc������)
 */
#define sio_init		h8s_sci_init

#ifndef _MACRO_ONLY

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;
	BOOL	openflag;

	/*
	 *  �����ץ󤷤��ݡ��Ȥ����뤫�� openflag ���ɤ�Ǥ�����
	 */
	openflag = h8s_sci_openflag();

	/*
	 * �⥸�塼�륹�ȥåץ⡼�ɲ��
	 */
#if TNUM_SIOP < 2
	h8s_andh( (VP) MSTPCR, ~( BIT5 ) );
#else /* TNUM_SIOP < 2 */
	h8s_andh( (VP) MSTPCR, ~( BIT6 | BIT5 ) );
#endif /* TNUM_SIOP < 2 */

	/*
	 *  �ǥХ�����¸�Υ����ץ����
	 */
	siopcb = h8s_sci_opn_por(siopid, exinf);

	/*
	 *  ���ꥢ��I/O����ߤγ���ߥ�٥�����ꤹ�롣
	 */
	if (!openflag) {
		/* ����ߥ�٥����� */
#ifndef GDB_STUB	/* SCI0 �� GDB_STUB �����Ѥ��롣 */
		icu_set_ilv( (VP) IPRJ, IPR_LOW, SCI0_INT_LVL );
#endif /* GDB_STUB */
#if TNUM_SIOP >= 2
		icu_set_ilv( (VP) IPRK, IPR_UPR, SCI1_INT_LVL );
#endif /* TNUM_SIOP >= 2 */
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
	 *  �ǥХ�����¸�Υ���������
	 */
	h8s_sci_cls_por(siopcb);

	/*
	 *  �⥸�塼�륹�ȥåץ⡼�ɥ��å�
	 */
#if TNUM_SIOP < 2
	h8s_orh( (VP) MSTPCR,   BIT5 );
#else /* TNUM_SIOP < 2 */
	h8s_orh( (VP) MSTPCR, ( BIT6 | BIT5 ) );
#endif /* TNUM_SIOP < 2 */

	/*
	 *  ���ꥢ��I/O����ߤ�ޥ������롣
	 */
	if (!h8s_sci_openflag()) {
		/* ����ߥޥ������� */
#ifndef GDB_STUB	/* SCI0 �� GDB_STUB �����Ѥ��롣 */
		icu_set_ilv( (VP) IPRJ, IPR_LOW, 0 );
#endif /* GDB_STUB */
#if TNUM_SIOP >= 2
		icu_set_ilv( (VP) IPRK, IPR_UPR, 0 );
#endif /* TNUM_SIOP >= 2 */
	}
}

#endif /* _MACRO_ONLY */

/*
 *  SIO�γ���ߥϥ�ɥ�
 *    sio1_handler_in    : ��������ߥϥ�ɥ�
 *    sio1_handler_out   : ��������ߥϥ�ɥ�
 *    sio1_handler_error : �������顼����ߥϥ�ɥ�
 */
/* �ݡ��ȣ� */
#define	sio1_handler_in		h8s_sci0_isr_in
#define	sio1_handler_out	h8s_sci0_isr_out
#define	sio1_handler_error	h8s_sci0_isr_error
#if TNUM_SIOP >= 2
/* �ݡ��ȣ� */
#define	sio2_handler_in		h8s_sci1_isr_in
#define	sio2_handler_out	h8s_sci1_isr_out
#define	sio2_handler_error	h8s_sci1_isr_error
#endif /* TNUM_SIOP >= 2 */

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
#define	sio_snd_chr		h8s_sci_snd_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ�������ʥݡ���󥰡�
 */
#define	sio_snd_chr_pol		h8s_sci0_putchar_pol

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
#define	sio_rcv_chr		h8s_sci_rcv_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
#define	sio_ena_cbr		h8s_sci_ena_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
#define	sio_dis_cbr		h8s_sci_dis_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
#define	sio_ierdy_snd		h8s_sci_ierdy_snd

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
#define	sio_ierdy_rcv		h8s_sci_ierdy_rcv

#endif /* _HW_SERIAL_H_ */
