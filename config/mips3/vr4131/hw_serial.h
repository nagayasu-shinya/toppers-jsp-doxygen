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

/*
 *	���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�VR4131��¢DSIU�ѡ�
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <vr4131_dsiu.h>		/* siopcb, vr4131_dsiu_openflag */

/*
 *  SIO�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define INHNO_SIO		INTNO_DSIU

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
#define	sio_initialize		vr4131_dsiu_initialize

/*
 *  �����ͥ뵯ư���Ѥν���� (sys_putc������)
 */
#define sio_init		vr4131_dsiu_init

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
	openflag = vr4131_dsiu_openflag();

	/*
	 * DSIU�ؤΥ���å����볫��
	 */
	vr4131_orh( (VP) CMUCLKMSK, (MSKDSIU | MSKSSIU | MSKSIU) );

	/*
	 *  �ǥХ�����¸�Υ����ץ������
	 */
	siopcb = vr4131_dsiu_opn_por(siopid, exinf);

	/*
	 *  ���ꥢ��I/O����ߤγ���ߥ�٥�����ꤷ���ޥ����������롥
	 */
	if (!openflag) {
		/* ����ߥ�٥����� */
		all_set_ilv( (UINT) INTNO_DSIU, &((IPM) IPM_DSIU) );

		/* �ޥ����������(��٥룱) */
		vr4131_orh( (VP) MSYSINT2REG, DSIUINTR );

		/* �ޥ����������(��٥룲) */
		vr4131_orh( (VP) MDSIUINTREG, INTDSIU );
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
	 *  ���ꥢ��I/O����ߤ�ޥ������롥
	 */
	if (!vr4131_dsiu_openflag) {
		/* �ޥ����������(��٥룱) */
		vr4131_andh( (VP) MSYSINT2REG, ~DSIUINTR );

		/* �ޥ����������(��٥룲) */
		vr4131_andh( (VP) MDSIUINTREG, ~INTDSIU );
	}

	/*
	 *  �ǥХ�����¸�Υ�����������
	 */
	vr4131_dsiu_cls_por(siopcb);

	/*
	 *  DSIU�ؤΥ���å��������
	 */
	vr4131_andh( (VP) CMUCLKMSK, ~(MSKDSIU | MSKSSIU | MSKSIU) );

}

#endif /* _MACRO_ONLY */

/*
 *  SIO�γ���ߥϥ�ɥ�
 */
#define	sio_handler		vr4131_dsiu_isr

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
#define	sio_snd_chr		vr4131_dsiu_snd_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ�������ʥݡ���󥰡�
 */
#define	sio_snd_chr_pol		vr4131_dsiu_putchar_pol

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
#define	sio_rcv_chr		vr4131_dsiu_rcv_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
#define	sio_ena_cbr		vr4131_dsiu_ena_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
#define	sio_dis_cbr		vr4131_dsiu_dis_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
#define	sio_ierdy_snd		vr4131_dsiu_ierdy_snd

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
#define	sio_ierdy_rcv		vr4131_dsiu_ierdy_rcv

#endif /* _HW_SERIAL_H_ */
