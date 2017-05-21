/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  @(#) $Id: cpu_config.c,v 1.10 2005/11/12 14:57:17 hiro Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���COLDFIRE�ѡ�
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  ����������ƥ����ȤǤγ���ߥޥ���
 */
#ifdef SUPPORT_CHG_IPM
UH	task_intmask;
#endif /* SUPPORT_CHG_IPM */

/*
 *  �󥿥�������ƥ����ȤǤγ���ߥޥ���
 */
UH	int_intmask;

/*
 *  ����ߡ�CPU�㳰�ͥ��ȥ�����
 */
UW      intnest;

extern void board_leds_display (unsigned char number);
/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize()
{
	/*
	 *  ����������ƥ����ȤǤγ���ߥޥ����ν����
	 */
#ifdef SUPPORT_CHG_IPM
	task_intmask = 0x0000;
#endif /* SUPPORT_CHG_IPM */

	/*
	 *  ����ߡ�CPU�㳰�ͥ��ȥ����󥿤ν����
	 */
	intnest = 1u;
        
	/*
	 *  �㳰�٥����ơ��֥�ν����
	 */
#ifdef KERNEL_HAS_A_VECTOR_TABLE
        if ((UW)&vector_table != current_vbr()) {
	     set_vbr(vector_table);
        }
#endif /* KERNEL_HAS_A_VECTOR_TABLE */
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate()
{
#ifdef KERNEL_HAS_A_VECTOR_TABLE
  if ((UW)&vector_table != EXCVT_ORIG) {  
	set_vbr(EXCVT_ORIG);
  }
#endif /* EXCVT_KERNEL */
}

#ifdef SUPPORT_CHG_IPM

/*
 *  ����ߥޥ������ѹ�
 *
 *  chg_ipm ��Ȥä� IPM �� 7��NMI �ʳ��Τ��٤Ƥγ���ߤ�ػߡˤ��ѹ�
 *  ���뤳�ȤϤǤ��ʤ���NMI �ʳ��Τ��٤Ƥγ���ߤ�ػߤ��������ˤϡ�
 *  loc_cpu �ˤ��CPU��å����֤ˤ���Ф褤��
 *  IPM �� 0 �ʳ��λ��ˤ⡤�������ǥ����ѥå�����α����ʤ���IPM �ϡ�
 *  �������ǥ����ѥå��ˤ�äơ��������¹Ծ��֤ˤʤä��������ذ����Ѥ�
 *  ��롥���Τ��ᡤ���������¹���ˡ��̤Υ������ˤ�ä� IPM ���ѹ���
 *  ����礬���롥JSP�����ͥ�Ǥϡ�IPM ���ѹ��ϥ������㳰�����롼��
 *  ��ˤ�äƤⵯ����Τǡ��̤Υ������ˤ�ä� IPM ���ѹ�����뤳�Ȥ�
 *  ��äơ��������񤷤��ʤ�����Ͼ��ʤ��Ȼפ��롥IPM ���ͤˤ�äƥ�
 *  �����ǥ����ѥå���ػߤ��������ˤϡ�dis_dsp ��ʻ�Ѥ���Ф褤��
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_PAR(0 <= ipm && ipm <= 6);

	t_lock_cpu();
	task_intmask = (ipm << 8);
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_CHG_IPM_LEAVE(ercd);
	return(ercd);
}

/*
 *  ����ߥޥ����λ���
 */
SYSCALL ER
get_ipm(IPM *p_ipm)
{
	ER	ercd;

	LOG_GET_IPM_ENTER(p_ipm);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_ipm = (task_intmask >> 8);
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_GET_IPM_LEAVE(ercd, *p_ipm);
	return(ercd);
}

#endif /* SUPPORT_CHG_IPM */

/*
 * ��Ͽ����Ƥ��ʤ��㳰��ȯ������ȸƤӽФ����
 */
void cpu_experr(EXCSTACK *sp)
{
    syslog(LOG_EMERG, "Exception error occurs.");
    
    syslog(LOG_EMERG, "PC = 0x%08x SR = 0x%08x",
    			sp->pc, sp->sr);
    
    syslog(LOG_EMERG, "d0 = 0x%08x d1 = 0x%08x d2 = 0x%08x",
    			sp->d0, sp->d1, sp->d2);
    syslog(LOG_EMERG, "d3 = 0x%08x d4 = 0x%08x d5 = 0x%08x",
    			sp->d3, sp->d4, sp->d5);
    syslog(LOG_EMERG, "d6 = 0x%08x d7 = 0x%08x a0 = 0x%08x",
    			sp->d6, sp->d7, sp->a0);
    syslog(LOG_EMERG, "a2 = 0x%08x a3 = 0x%08x a3 = 0x%08x",
    			sp->a1, sp->a2, sp->a3);
    syslog(LOG_EMERG, "a4 = 0x%08x a5 = 0x%08x a6 = 0x%08x",
    			sp->a4, sp->a5, sp->a6);
    			/*  �㳰ȯ��ľ���Υ����å��ݥ��󥿤���  */
    syslog(LOG_EMERG, "a7 = 0x%08x", (sp->a7)+2*4);

    while(1);
}

