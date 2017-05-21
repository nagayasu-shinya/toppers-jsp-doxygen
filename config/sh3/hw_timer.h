/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: hw_timer.h,v 1.8 2003/06/20 11:44:42 honda Exp $
 */

/*
 *  CPU��¸�����ޥ⥸�塼���SH3/4�ѡ�
 *  TMU0�����
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>

/*
 *  �����޳���ߥϥ�ɥ��INTEVT�ֹ�
 */
#define	INHNO_TIMER	TMU0_INTEVT

#ifndef _MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef UW	CLOCK;

#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)      ((clock) * 1000 / TIMER_CLOCK)

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
    sil_wrb_mem((VP)TMU_TSTR,
                (sil_reb_mem((VP)TMU_TSTR) & ~TMU_STR0));  /* ��������� */
    assert(cyc <= MAX_CLOCK);		     /* �����޾���ͤΥ����å� */

    /* ʬ�������ꡢ�����ߵ��� */
    sil_wrh_mem((VP)TMU_TCR0,(0x020 | TCR0_TPSC));
    
    sil_wrw_mem((VP)TMU_TCOR0, cyc); /* timer constant�쥸�����򥻥å� */
    sil_wrw_mem((VP)TMU_TCNT0, cyc); /* �����󥿡��򥻥å� */
    /* ������0�������� */
    sil_wrb_mem((VP)TMU_TSTR,
                (sil_reb_mem((VP)TMU_TSTR) | TMU_STR0));

    
    /*
	 *  ����ߴ�Ϣ������
	 */
    define_int_plevel(TMU0_INTEVT,KTIM_INT_LV); /* �����ߥ�٥�����(SF) */
    /* �����ߥ�٥�����(HW) */
    sil_wrh_mem((VP)IPRA,
                ((sil_reh_mem((VP)IPRA) & 0x0fff) | (KTIM_INT_LV<<12)));
    /* �������׵�򥯥ꥢ */
    sil_wrh_mem((VP)TMU_TCR0,
                (sil_reh_mem((VP)TMU_TCR0) & ~TCR_UNF));
}


/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{
    /* �������׵�򥯥ꥢ */
    sil_wrh_mem((VP)TMU_TCR0,
                (sil_reh_mem((VP)TMU_TCR0) & ~TCR_UNF));    
}

/*
 *  �����ޤ���߽���
 */
Inline void
hw_timer_terminate()
{
    /* �����ޤ���� */
    sil_wrb_mem((VP)TMU_TSTR,
                (sil_reb_mem((VP)TMU_TSTR) & ~TMU_STR0));
    /* �������׵�򥯥ꥢ */
    sil_wrh_mem((VP)TMU_TCR0,0);
}

/*
 *  �����ޤθ����ͤ��ɤߤ���
 *
 *  ����߶ػ߶����ǸƤӽФ����ȡ�
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return(TO_CLOCK(TIC_NUME, TIC_DENO) - sil_rew_mem((VP)TMU_TCNT0));
}

Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return(sil_reh_mem((VP)TMU_TCR0) & TCR_UNF);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */



