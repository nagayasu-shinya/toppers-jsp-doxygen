/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by  Advanced Data Controls, Corp
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
 *  @(#) $Id: hw_timer.h,v 1.3 2003/12/19 11:24:18 honda Exp $
 */

/*
 *  CPU��¸�����ޥ⥸�塼���Integrator�ѡ�
 *  TMU0�����
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include <integrator.h>

/*
 *  �����޳���ߤγ�����ֹ�
 */
#define	INHNO_TIMER	IRQ_TM1_BIT

#ifndef _MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef UW	CLOCK;

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *  TIMER_CLOCK �ϥ������åȥܡ����������
 */
#define TO_CLOCK(nume, deno) (TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)       ((clock) * 1000 / TIMER_CLOCK)

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define MAX_CLOCK	((CLOCK) 0xffffffff)
/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define GET_TOLERANCE	100
#define BEFORE_IREQ(clock) \
        ((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize()
{
	CLOCK	cyc = TO_CLOCK(TIC_NUME, TIC_DENO);
        
	/*
	 *  �����޴�Ϣ������
	 */
	/* ��������� */
	sil_wrw_mem((VP)TM1_CTRL,TCTRL_STOP);
	/* �����޾���ͤΥ����å� */
	assert(cyc <= MAX_CLOCK);       
	/* ����ߤΥ��ꥢ  */
	sil_wrw_mem((VP)TM1_CTRL,0x01);
	sil_wrw_mem((VP)TM1_LOAD,cyc);
	/* ��������ͤ򥻥å� */
	sil_wrw_mem((VP)TM1_VAL,cyc);
	/* ������ȥ�������   */
        sil_wrw_mem((VP)TM1_CTRL,TCTRL_START);
	/* ����ߵ��� */    	
	sil_wrw_mem((VP)IRQ0_ENABLESET,IRQ_TM1);
}

/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{
  sil_wrw_mem((VP)TM1_CLR,0x01);    /* �ڥ�ǥ��󥰥ӥåȤ򥯥ꥢ */
}

/*
 *  �����ޤ���߽���
 */
Inline void
hw_timer_terminate()
{
    /* �ڥ�ǥ��󥰥ӥåȤ򥯥ꥢ */
    sil_wrw_mem((VP)TM1_CLR,0x01);    
    /* ��������� */
    sil_wrw_mem((VP)TM1_CTRL,TCTRL_STOP);
    /* ������Ե���*/
    sil_wrw_mem((VP)IRQ0_ENABLECLR,
	    sil_rew_mem((VP)IRQ0_ENABLECLR)&~IRQ_TM1);
}

/*
 *  �����ޤθ����ͤ��ɤߤ���
 *
 *  ����߶ػ߶����ǸƤӽФ����ȡ�
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return(TO_CLOCK(TIC_NUME, TIC_DENO) - sil_rew_mem((VP)TM1_VAL));
}

Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return(sil_rew_mem((VP)IRQ0_STATUS) & IRQ_TM1);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */



