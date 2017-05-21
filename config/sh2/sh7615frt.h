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
 *  @(#) $Id: sh7615frt.h,v 1.5 2005/07/06 00:45:07 honda Exp $
 */

/*
 *	�����ޥɥ饤��
 *  FRT�����
 */

#ifndef _SH7615FRT_H_
#define _SH7615FRT_H_

/*
 *   �����ޤؤ����ϥ���å���ʬ��������
 *   	f/8�ǥ������
 */
#define TCR_CKS         0x0

/*
 *   �����ޤ˶��뤵��륯��å����ȿ�[kHz]
 *   	14.7456MHz/8 =1.8432MHz =1843.2kHz
 */
#define TIMER_CLOCK	1843


/*
 *  �������ͤ�����ɽ���η�
 */
typedef UH CLOCK;

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *
 */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)
#define CLOCK_PER_TICK	((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define	MAX_CLOCK	((CLOCK) 0xffff)

/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define	GET_TOLERANCE	100		/* �����٤�θ��Ѥ��͡�ñ�̤�����ɽ���� */
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  ����ȥ���쥸�����Υ��ɥ쥹
 */

#define FRT_FTCSR	(VB *)0xfffffe11
#define FRT_TOCR	(VB *)0xfffffe17
#define FRT_TCR		(VB *)0xfffffe16
#define FRT_OCRH	(VB *)0xfffffe14
#define FRT_OCRL	(VB *)0xfffffe15
#define FRT_TIER	(VB *)0xfffffe10
#define FRT_FRCH	(VB *)0xfffffe12
#define FRT_FRCL	(VB *)0xfffffe13


#ifndef _MACRO_ONLY

/*
 *  �����ޥ�������
 */
Inline void
sh2_timer_start ()
{
	/* OCRA���פˤ����ȯ������ */
	sil_wrb_mem (FRT_TIER, sil_reb_mem(FRT_TIER) | 0x08);
}

/*
 *  �����ް�����
 */
Inline void
sh2_timer_stop ()
{
	/* OCRA���פˤ����ȯ���Ե��� */
	sil_wrb_mem (FRT_TIER, sil_reb_mem(FRT_TIER) & ~0x08);
}
/*
 *  �����޳�����׵�Υ��ꥢ
 *	TCR�쥸������IMFA�ӥåȤ�1���ɤ߽Ф�����ˣ���񤭹���
 */
Inline void
sh2_timer_int_clear ()
{
	/* �������׵�򥯥ꥢ     */
	/*  ��GRA����ڥ��ޥå��ե饰�� */
	sil_wrb_mem (FRT_FTCSR, sil_reb_mem (FRT_FTCSR) & 0xf7);
	/* OCRA����ڥ��ޥå��ե饰�Υ��ꥢ */

}


/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
sh2_timer_initialize ()
{
	CLOCK cyc = TO_CLOCK (TIC_NUME, TIC_DENO);


	/*
	 *  �����޴�Ϣ������
	 */
	sh2_timer_stop ();			/* ��������� */
	/* �����޾���ͤΥ����å� */
	assert (cyc <= MAX_CLOCK);

	/* OCRA���� */
	sil_wrb_mem (FRT_TOCR, 0x00);
	/*  ʬ��������  clock 1/8   */
	sil_wrb_mem (FRT_TCR, 0x00);
	/* OCRA���פˤ��FRC�Υ��ꥢ */
	sil_wrb_mem (FRT_FTCSR, sil_reb_mem (FRT_FTCSR) | 0x01);
	/* ����ڥ��ޥå��ե饰�Υ��ꥢ */
	sil_wrb_mem (FRT_FTCSR, sil_reb_mem (FRT_FTCSR) & 0xf7);
	/*  OCRA�쥸��������ʥ�������ɸ�͡�      */
	sil_wrb_mem (FRT_OCRH, (CLOCK_PER_TICK >> 8) & 0x00ff);
	sil_wrb_mem (FRT_OCRL, (CLOCK_PER_TICK) & 0x00ff);
	/* OCRA���פˤ����ȯ������ */
	sil_wrb_mem (FRT_TIER, 0x09);
	/* �����󥿤򥯥ꥢ             */
	sil_wrb_mem (FRT_FRCH, 0);
	sil_wrb_mem (FRT_FRCL, 0);
}

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
Inline void
sh2_timer_terminate ()
{
	sh2_timer_stop ();			/* �����ޤ����     */
	sh2_timer_int_clear ();		/* �������׵�򥯥ꥢ */

	sil_wrb_mem (FRT_TIER, 0x01);	//�������Ե���
	sil_wrb_mem (FRT_FRCH, 0);
	sil_wrb_mem (FRT_FRCL, 0);
	sil_wrb_mem (FRT_OCRH, 0);
	sil_wrb_mem (FRT_OCRL, 0);
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 *�������������ͤ��ɤ߽Ф���
 */
Inline CLOCK
sh2_timer_get_current ()
{
	CLOCK	clk;
	CLOCK up, low;


	up = sil_reb_mem (FRT_FRCH);
	low = sil_reb_mem (FRT_FRCL);
	clk = (up << 8) | low;
	return (clk);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
sh2_timer_fetch_interrupt ()
{
	return (sil_reb_mem (FRT_FTCSR) & 0x08);
}

#endif /* _MACRO_ONLY */
#endif /* _SH7615FRT_H_ */
