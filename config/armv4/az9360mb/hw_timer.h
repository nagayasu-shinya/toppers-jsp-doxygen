/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005-2007 by Y.D.K.Co.,LTD Technologies company
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
 *  @(#) $Id: hw_timer.h,v 1.1 2007/05/11 06:06:35 honda Exp $
 */

/*
 *  �����ޥ⥸�塼��
 *  TIMER0�����
 */

#ifndef	_HW_TIMER_H_
#define	_HW_TIMER_H_

#include	<s_services.h>
#ifndef	_NS9360_H_
#include	<ns9360.h>
#endif

/*
 *  �����޳���ߤγ�����ֹ�(�����ޡ��˥��åȤ���ͥ����)
 */
#define		INHNO_TIMER		INTLV_TIM0

#ifndef	_MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef	UW		CLOCK;

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *  TIMER_CLOCK �ϥ������åȥܡ����������
 */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)			((clock) * 1000 / TIMER_CLOCK)

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define	MAX_CLOCK	((CLOCK) 0xffffffff)

/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define	GET_TOLERANCE	100
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize()
{
	CLOCK    cyc = TO_CLOCK(TIC_NUME, TIC_DENO);
	    
	sil_wrw_mem((VP)TIMER0_CR,0x00);  			/* ���������,����ߥ��ꥢ,����߶ػ� */
	assert(cyc <= MAX_CLOCK);					/* �����޾���ͤΥ����å� */
	sil_wrw_mem((VP)TIMER0_CR,0x00000007);		/* ���������,����ߥ��ꥢ,����߶ػ� */
	sil_wrw_mem((VP)TIMER0_RLC_REG,cyc);		/* ��������ͥ��å�       */
	/*
	 *  ����ߴ�Ϣ������
	 */
	/* ����ߥޥ������ꥢ����ߵ��� */
	sil_wrw_mem((VP)INT_CFG4_7_REG,sil_rew_mem((VP)INT_CFG4_7_REG)|0x80000000);	/* IRQ4 IntEnable */

	/* ����ߵ���,�����ޥ������� */
	sil_wrw_mem((VP)TIMER0_CR,0x0000800f); 
}



/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{
	UW	n;

	n = (sil_rew_mem((VP)TIMER0_CR));
	sil_wrw_mem((VP)TIMER0_CR, n | 0x200);
	sil_wrw_mem((VP)TIMER0_CR, n & ~0x200);
}


/*
 *  �����ޤ���߽���
 */
Inline void
hw_timer_terminate()
{
	/* ���������,����ߥ��ꥢ,����߶ػ� */
	sil_wrw_mem((VP)TIMER0_CR,0x00000107);
	/* ����ߥޥ������åȳ���߶ػ� */
	sil_wrw_mem((VP)INT_CFG4_7_REG,sil_rew_mem((VP)INT_CFG4_7_REG)&~(0x80000000));	/* IRQ4 IntDisable */
}


/*
 *  �����ޤθ����ͤ��ɤߤ���
 *
 *  ����߶ػ߶����ǸƤӽФ����ȡ�
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return(TO_CLOCK(TIC_NUME, TIC_DENO) -
		sil_rew_mem((VP)TIMER0_RR));
}


Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return(sil_rew_mem((VP)TIS_REG) & 1);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
