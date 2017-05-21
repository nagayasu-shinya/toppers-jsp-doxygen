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
 *  @(#) $Id: cpu_config.c,v 1.24 2006/04/10 09:58:15 honda Exp $
 */

/*
 *  �ץ��å���¸�⥸�塼���SH3/4�ѡ�
 */
#include <s_services.h>
#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  ����������ƥ����ȤǤγ���ߥޥ���
 */
#ifdef SUPPORT_CHG_IPM
UW	task_intmask;
#endif /* SUPPORT_CHG_IPM */


/*
 *  �󥿥�������ƥ����ȤǤγ���ߥޥ���
 */
UW	int_intmask;


/*
 * �����ߥϥ�ɥ�/ͥ���٤ε����ơ��֥�
 */
FP  int_table[(MAX_INTIVT>>5) + 1];
VW  int_plevel_table[(MAX_INTIVT>>5) + 1];


/*
 * CPU�㳰�ϥ�ɥ�ε����ơ��֥�
 */
FP	exc_table[(0x1E0 >> 5) + 1];


/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize()
{
    int i;
    
    /*
     *  ����������ƥ����ȤǤγ���ߥޥ����ν����
     */
#ifdef SUPPORT_CHG_IPM
    task_intmask = 0x0000;    
#endif /* SUPPORT_CHG_IPM */
    
    /*
     * int_table[],int_plevel_table[]�ν����
     * ̤��Ͽ�γ����ȯ������cpu_interrup()���ƤӽФ����褦��
     * no_reg_interrup()����Ͽ����
     * �ǥ��ե���Ȥ�int_plevel_table[]�γ����ͥ���٤�MAX_IPM - 1
     * �Ȥ��롥
     */
    for(i = 0; i < ((MAX_INTIVT>>5) + 1); i++){
        int_table[i] = no_reg_interrupt;
        int_plevel_table[i] = 0x40000000 | (MAX_IPM - 1) << 4;
    }
    
#ifndef GDB_STUB
    /*
     * �����ߥ���ȥ���ν���� 
     */
#if defined(SH7750)
    sil_wrh_mem((VP)ICR, 0x0000);
    sil_wrh_mem((VP)IPRA, 0x0000);
    sil_wrh_mem((VP)IPRB, 0x0000);
    sil_wrh_mem((VP)IPRC, 0x0000);
#else /* SH7708 || SH7709 || SH7709A || SH7729R || SH7727 */   
    sil_wrh_mem((VP)ICR0, 0x0000);
    sil_wrh_mem((VP)IPRA, 0x0000);     
    sil_wrh_mem((VP)IPRB, 0x0000);
#if defined(SH7709) || defined(SH7709A) || defined(SH7729R) || defined(SH7727) 
    sil_wrh_mem((VP)ICR1, 0x4000);
    sil_wrh_mem((VP)ICR2, 0x0000);     
    sil_wrh_mem((VP)PINTER, 0x0000);
    sil_wrh_mem((VP)IPRC, 0x0000);
    sil_wrh_mem((VP)IPRD, 0x0000);
    sil_wrh_mem((VP)IPRE, 0x0000);
    sil_wrb_mem((VP)IRR0, 0x0000);   
    sil_wrb_mem((VP)IRR1, 0x0000);
    sil_wrb_mem((VP)IRR2, 0x0000);
#endif /* SH7709 || SH7709A  */   
#endif /* SH7750 */
    
    /*
     *  �٥����١����쥸�������ν����
     */
    set_vbr(BASE_VBR);
    
#endif /* GDB_STUB */
}


/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate()
{
}


/*
 * Trapa�ʳ����㳰����Ͽ����Ƥ��ʤ��㳰��ȯ������ȸƤӽФ����
 */
void
cpu_expevt(VW expevt,VW spc,VW ssr,VW pr)
{
    syslog(LOG_EMERG, "Unregistered Expevt error occurs.");
    syslog(LOG_EMERG, "Expevt = %08x SPC = %08x SR = %08x PR=%08X",
           expevt,spc,ssr,pr);
    while(1);
}

/*
 * ̤��Ͽ�γ���ߤ�ȯ���������˸ƤӽФ����
 */
void
cpu_interrupt(VW intevt, VW intevt2,VW spc,VW ssr)
{
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
#if defined(SH7709) || defined(SH7709A) || defined(SH7729R) || defined(SH7727) 
    syslog(LOG_EMERG, "INTEVT = %08x INTEVT2 = %08x SPC = %08x SR = %08x ",
           intevt,intevt2,spc,ssr);
#else /* SH7708 || SH7750 */   
    syslog(LOG_EMERG, "INTEVT = %08x  SPC = %08x SR = %08x ",intevt,spc,ssr);
#endif    
    while(1);
}



#ifdef SUPPORT_CHG_IPM

/*
 *  ����ߥޥ������ѹ�
 *
 *  chg_ipm ��Ȥä� IPM �� MAX_IPM ��NMI �����֥�⡼�ȥ֥졼�� �ʳ�
 *  �Τ��٤Ƥγ���ߤ�ػߡ˰ʾ���ѹ����뤳�ȤϤǤ��ʤ���NMI �����֥�
 *  �⡼�ȥ֥졼���ʳ��Τ��٤Ƥγ���ߤ�ػߤ��������ˤϡ�loc_cpu ��
 *  ���CPU��å����֤ˤ���Ф褤��IPM �� 0 �ʳ��λ��ˤ⡤�������ǥ���
 *  �ѥå�����α����ʤ���IPM �ϡ��������ǥ����ѥå��ˤ�äơ���������
 *  �Ծ��֤ˤʤä��������ذ����Ѥ���롥���Τ��ᡤ���������¹���ˡ���
 *  �Υ������ˤ�ä� IPM ���ѹ�������礬���롥JSP�����ͥ�Ǥϡ�IPM
 *  ���ѹ��ϥ������㳰�����롼����ˤ�äƤⵯ����Τǡ�����ˤ�äư�
 *  �����񤷤��ʤ�����Ͼ��ʤ��Ȼפ��롥IPM ���ͤˤ�äƥ������ǥ���
 *  �ѥå���ػߤ��������ˤϡ�dis_dsp ��ʻ�Ѥ���Ф褤��
 */

SYSCALL ER
chg_ipm(IPM ipm)
{
    ER  ercd;
    
    LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_PAR(0 <= ipm && ipm <= MAX_IPM - 1);

	t_lock_cpu();
	task_intmask = (ipm << 4);
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
    ER  ercd;

    LOG_GET_IPM_ENTER(p_ipm);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_ipm = (task_intmask >> 4);
    ercd = E_OK;
	t_unlock_cpu();

  exit:
    LOG_GET_IPM_LEAVE(ercd, *p_ipm);
    return(ercd);
}

#endif /* SUPPORT_CHG_IPM */
