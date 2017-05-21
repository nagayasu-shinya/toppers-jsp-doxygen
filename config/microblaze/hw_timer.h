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
 *  @(#) $Id: hw_timer.h,v 1.7 2003/12/11 00:58:01 honda Exp $
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

/*
 * CPU��¸�����ޥ⥸�塼���MicroBlaze�ѡ�
 */ 
#include <s_services.h>
#include <microblaze.h>

/*
 * �����޳���ߥϥ�ɥ�γ�����ֹ�
 */
#define INHNO_TIMER TIMINTLVL

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

  sil_wrw_mem((VP)TIMER_TCSR0,TIMER_RESET); /* �ꥻ�å� */
  
  assert(cyc <= MAX_CLOCK);	                /* �����޾���ͤΥ����å� */
  sil_wrw_mem((VP)TIMER_TCCR0, cyc);        /* �����󥿡����å� */
  
  /*
   * �����ޡ�0���͡��֥롤�����ȥ���ɡ������󥫥���ȡ�����ߵ��ġ�
   */
  sil_wrw_mem((VP)TIMER_TCSR0,TIMER_ENABLE | TIMER_RELOAD | TIMER_DOWN_COUNT
                                | TIMER_ENABLE_INTR);

  /*
   *  INTC����ߵ���
   */
  intc_enable_interrupt((1 << (TIMINTLVL - 1)));
}



/*
 *   �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{
  sil_wrw_mem((VP)TIMER_TCSR0,sil_rew_mem((VP)TIMER_TCSR0));
  /*
   * ��٥����ߤΤ��ᡤ������װ��򲼤������ACK
   */
  intc_ack_interrupt(1 << (TIMINTLVL - 1));
}



/*
 *   �����ޤζػ߽���
 */
Inline void
hw_timer_terminate()
{
  int dummy;
  
  sil_wrw_mem((VP)TIMER_TCSR0, ~TIMER_ENABLE); /* ���������         */
  sil_wrw_mem((VP)TIMER_TCSR0, sil_rew_mem((VP)TIMER_TCSR0));  /* ������׵�Υ��ꥢ */
  
  /*
   * ���Ǥ˳���ߤ����äƤ����礬����Τǳ�����׵�򥯥ꥢ
   */
  dummy = 1 << (TIMINTLVL - 1);
  intc_ack_interrupt(dummy);
  intc_disable_interrupt(dummy);  /* INTC�μ����դ��ػ� */
}



/*
 *   �����ޤθ����ͤ��ɤ߽Ф�
 *
 *   ����߶ػ߶����ǸƤӽФ�����
 */
Inline CLOCK
hw_timer_get_current(void)
{
  return(TO_CLOCK(TIC_NUME, TIC_DENO) - sil_rew_mem((VP)TIMER_TCR0));
}



/*
 *   ����ߤ�ȯ�����Ƥ��뤫��Ƚ��
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
  return(sil_rew_mem((VP)TIMER_TCSR0) & TIMER_INTERRUPT);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
