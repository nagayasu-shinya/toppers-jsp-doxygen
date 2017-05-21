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
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
 *  Copyright (C) 2008 by Takahisa Yokota
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

#ifndef _MCFPIT_H_
#define _MCFPIT_H_

/*
 *   �����ޤؤ����ϥ���å���ʬ��������
 *   	f/8�ǥ������
 */
#define TCR_CKS         0x0

/*
 *   �����ޤ˶��뤵��륯��å����ȿ�[kHz]
 *      60MHz/2 = 30MHz
 */
#define	TIMER_CLOCK		(25000)

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
 *  �쥸������������
 */
#define MCF_PIT_PCSR_EN   (0x0001u)
#define MCF_PIT_PCSR_RLD  (0x0002u)
#define MCF_PIT_PCSR_PIF  (0x0004u)
#define MCF_PIT_PCSR_PIE  (0x0008u)
#define MCF_PIT_PCSR_OVW  (0x0010u)
#define MCF_PIT_PCSR_DBG  (0x0020u)
#define MCF_PIT_PCSR_DOZE (0x0040u)

/*
 *  ����ȥ���쥸�����Υ��ɥ쥹
 */
#define MCF_PIT0_PCSR   (VH*)(IPSBAR + 0x00150000)
#define MCF_PIT0_PMR    (VH*)(IPSBAR + 0x00150002)
#define MCF_PIT0_PCNTR  (VH*)(IPSBAR + 0x00150004)


#ifndef _MACRO_ONLY

/*
 *  �����ޥ�������
 */
Inline void
mcf_timer_start ()
{
     sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem (MCF_PIT0_PCSR) | MCF_PIT_PCSR_EN);
}

/*
 *  �����ް�����
 */
Inline void
mcf_timer_stop ()
{
    	/* �����ޤ���� 	  */
	sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem (MCF_PIT0_PCSR) & ~MCF_PIT_PCSR_EN);
}
/*
 *  �����޳�����׵�Υ��ꥢ
 *	TCR�쥸������IMFA�ӥåȤ�1���ɤ߽Ф�����ˣ���񤭹���
 */
Inline void
mcf_timer_int_clear ()
{
	/* �������׵�򥯥ꥢ     */
	sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem (MCF_PIT0_PCSR));
}


/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
mcf_timer_initialize ()
{
	CLOCK cyc = TO_CLOCK (TIC_NUME, TIC_DENO);

	/*
	 *  �����޴�Ϣ������
	 */
	mcf_timer_stop ();			/* ��������� */
	/* �����޾���ͤΥ����å� */
	assert (cyc <= MAX_CLOCK);
       /*
         *  �����޳���ߤγ���ߥ�٥�����ꤷ���׵�򥯥ꥢ�����塤
         *  �ޥ����������롥
         */
        sil_wrh_mem (MCF_PIT0_PCSR, (VH)(MCF_PIT_PCSR_OVW | MCF_PIT_PCSR_PIF | MCF_PIT_PCSR_RLD));
        sil_wrh_mem (MCF_PIT0_PMR, (VH)CLOCK_PER_TICK);
        sil_wrh_mem (MCF_PIT0_PCNTR,0x0000);
        sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem(MCF_PIT0_PCSR) | MCF_PIT_PCSR_PIE);	//�����ߵ���
}

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
Inline void
mcf_timer_terminate ()
{
	/*
	 *  �����ޤ�ư�����ߤ��롥
	 */
	mcf_timer_stop();
        mcf_timer_int_clear ();
	/*
	 *  �����޳���ߤ�ޥ��������׵�򥯥ꥢ���롥
	 */
	sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem(MCF_PIT0_PCSR) & ~MCF_PIT_PCSR_PIE);	//�������Ե���
	sil_wrh_mem (MCF_PIT0_PCNTR,0x0000);
	sil_wrh_mem (MCF_PIT0_PMR,0x0000); 
        sil_wrw_mem (MCF_INTC_IMRH(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRH(MCF_INTC0)) | (1 << (TBIT_TT0)));
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK
mcf_timer_get_current ()
{
	CLOCK	clk;
        
	clk = TO_CLOCK(TIC_NUME, TIC_DENO) - sil_reh_mem(MCF_PIT0_PCNTR);
	return (clk);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
mcf_timer_fetch_interrupt ()
{
        return (sil_reh_mem (MCF_PIT0_PCSR) & MCF_PIT_PCSR_PIF);
}

#endif /* _MACRO_ONLY */
#endif /* _MCFPIT_H_ */
