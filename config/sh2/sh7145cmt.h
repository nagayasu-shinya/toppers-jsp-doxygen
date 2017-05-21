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
 *  @(#) $Id: sh7145cmt.h,v 1.5 2005/07/06 00:45:07 honda Exp $
 */

/*
 *	�����ޥɥ饤��
 *  CMT�����
 */

#ifndef _SH7145CMT_H_
#define _SH7145CMT_H_

/*
 *   �����ޤؤ����ϥ���å���ʬ��������
 *   	f/8�ǥ������
 */
#define TCR_CKS         0x0

/*
 *   �����ޤ˶��뤵��륯��å����ȿ�[kHz]
 *      12.288MHz*2/8 = 3,072kHz
 */
#define TIMER_CLOCK     3072


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
#define CMSTR	(VH *)0xffff83d0
#define CMCSR_0	(VH *)0xffff83d2
#define CMCNT_0	(VH *)0xffff83d4
#define CMCOR_0	(VH *)0xffff83d6


#ifndef _MACRO_ONLY
/*
 *  �����ޥ�������
 */
Inline void
sh2_timer_start ()
{
	sil_wrh_mem (CMSTR, sil_reh_mem (CMSTR) | 0x0001);
}

/*
 *  �����ް�����
 */
Inline void
sh2_timer_stop ()
{
    	/* �����ޤ���� 	  */
	sil_wrh_mem (CMSTR, sil_reh_mem (CMSTR) & ~0x0001);
}

/*
 *  �����޳�����׵�Υ��ꥢ
 *	TCR�쥸������IMFA�ӥåȤ�1���ɤ߽Ф�����ˣ���񤭹���
 */
Inline void
sh2_timer_int_clear ()
{
	/* �������׵�򥯥ꥢ     */
	sil_wrh_mem (CMCSR_0, sil_reh_mem (CMCSR_0) & ~0x0080);
				/* CMF����ڥ��ޥå��ե饰�Υ��ꥢ */
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


	sil_wrh_mem (MSTCR2, (sil_reh_mem(MSTCR2)& ~0x0100));
	/*
	 *  �����޴�Ϣ������
	 */
	sh2_timer_stop ();			/* ��������� */
	/* �����޾���ͤΥ����å� */
	assert (cyc <= MAX_CLOCK);

	/*  ʬ��������  clock 1/8  �������߶ػ� */
    sil_wrh_mem(CMCSR_0,0x0000);
	/*  CMCOR0�쥸��������ʥ�������ɸ�͡�      */
	sil_wrh_mem (CMCOR_0,(VH)CLOCK_PER_TICK);
	/* �����󥿤򥯥ꥢ             */
	sil_wrh_mem (CMCNT_0,0x0000);
	sil_wrh_mem (CMCSR_0, sil_reh_mem(CMCSR_0) | 0x0040);	/* �����ߵ��� */
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

	sil_wrh_mem (CMCSR_0, sil_reh_mem(CMCSR_0) & ~0x0040);	//�������Ե���
	sil_wrh_mem (CMCNT_0,0x0000);
	sil_wrh_mem (CMCOR_0,0x0000);
	sil_wrh_mem (MSTCR2, (sil_reh_mem(MSTCR2) | 0x0100));
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 *�����������ޤ�ư�����Ū����ߤ����������ͤ��ɤ߽Ф���
 */
Inline CLOCK
sh2_timer_get_current ()
{
	CLOCK	clk;
/* SH1��Ʊ�� */
	sh2_timer_stop ();			/*  ���������  */

	/*  ������Ԥ����֤������٤�  */

	clk = sil_reh_mem(CMCNT_0);
	sh2_timer_start();			/*  �����ޥ�������  */
	
	return(clk);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
sh2_timer_fetch_interrupt ()
{
	return (sil_reh_mem (CMCSR_0) & 0x0080);
}

#endif /* _MACRO_ONLY */
#endif /* _SH7145CMT_H_ */
