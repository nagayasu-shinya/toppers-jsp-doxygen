/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: hw_timer.h,v 1.4 2004/09/10 14:38:21 honda Exp $
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

/*
 * CPU��¸�����ޥ⥸�塼���Nios2�ѡ�
 */ 
#include <s_services.h>
#include <nios2.h>

/*
 * �����޳���ߥϥ�ɥ�γ�����ֹ�
 */
#define INHNO_TIMER TIM_INTLVL

#ifndef _MACRO_ONLY

/*
 * �������ͤ�����ɽ���η�
 */
typedef UW CLOCK;

/*                                                                             
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�                               
 *  TIMER_CLOCK �ϥ������åȥܡ����������                                     
 */
#define TO_CLOCK(nume, deno)  (TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)      ((clock) * 1000 / TIMER_CLOCK)

/*
 *  ����Ǥ�����祿���޼�����ñ�̤�����ɽ����
 */
#define MAX_CLOCK ((CLOCK) 0xffffffff)

/*
 *  ��ǽɾ���ѥ����ƥ�������Ф��ݤν������֤θ��Ѥ��͡�ñ�̤�����ɽ����
 */
#define GET_TOLERANCE	100
#define BEFORE_IREQ(clock) \
        ((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


/*
 * �����ޤε�ư����
 *
 * �����ޤ�������������Ū�ʥ����޳���ߤ�ȯ��������
 */ 
Inline void
hw_timer_initialize(void)
{
  
    CLOCK cyc = TO_CLOCK(TIC_NUME, TIC_DENO);

    /* �����ޡ����ȥå� */
    sil_wrw_mem((VP)TIM_CONTROL,TIM_CONTROL_STOP);
    /* �����ॢ���ȥ��ơ��������ꥢ */
    sil_wrw_mem((VP)TIM_STATUS, 0x00);
    
      
    assert(cyc <= MAX_CLOCK);                          /* �����޾���ͤΥ����å� */
    sil_wrw_mem((VP)TIM_PERIODL, (cyc & 0xffff)); /* �����󥿡����å� ����16bit */
    sil_wrw_mem((VP)TIM_PERIODH, (cyc >> 16));    /* �����󥿡����å� ���16bit */
  
    /*
     * �����ޡ��������ȡ������ȥ���ɡ�����ߵ���
     */
    sil_wrw_mem((VP)TIM_CONTROL, TIM_CONTROL_START
                                 |TIM_CONTROL_COUNT|TIM_CONTROL_ITO);

    /*
     * ����ߥ���ȥ���ε���
     */
    ena_int(TIM_INTLVL);
}


/*
 *   �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{
    /* TO�ӥåȤΥ��ꥢ */
    sil_wrw_mem((VP)TIM_STATUS,0x00);
}


/*
 *   �����ޤζػ߽���
 */
Inline void
hw_timer_terminate()
{
    /* ��������� */
    sil_wrw_mem((VP)TIM_CONTROL, TIM_CONTROL_STOP);

    /* ������׵�Υ��ꥢ */
    sil_wrw_mem((VP)TIM_STATUS, 0x00);
}


/*
 *   �����ޤθ����ͤ��ɤ߽Ф�
 *
 *   ����߶ػ߶����ǸƤӽФ�����
 */
Inline CLOCK
hw_timer_get_current(void)
{
    CLOCK count;

    /* ���ʥåץ쥸�����˽񤭹�����ͤ�ۡ���ɤ��� */
    sil_wrw_mem((VP)TIM_SNAPL, 0x00);

    /* ��������ͤ��ɤ߹��� */
    count = sil_rew_mem((VP)TIM_SNAPL);
    count |= sil_rew_mem((VP)TIM_SNAPH) << 16; 
    
    return(TIMER_CLOCK - count);
}


/*
 *   ����ߤ�ȯ�����Ƥ��뤫��Ƚ��
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
    return(sil_rew_mem((VP)TIM_STATUS) & TIM_STATUS_TO);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
