/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

/*
 *  �ץ��å���¸�⥸�塼��(H8S��)
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  ����������ƥ����ȤǤγ���ߥޥ���
 */
#ifdef SUPPORT_CHG_IPM
volatile IPM	task_intmask = 0;		/* IPM -> UB�����̵��8�ӥå� */
#endif /* SUPPORT_CHG_IPM */

/*
 *  �󥿥�������ƥ����ȤǤγ���ߥޥ���
 */
volatile IPM	int_intmask = 0;

/*
 *  ����ߥͥ��ȥ�����
 */
volatile UB	intnest = 1;

/*
 *  CPU��å����֤�ɽ���ե饰
 *  ��������߶ػߡʥ����ͥ�������γ���ߤΤߡ�
 *  ����������
 *  ����iscpulocked == TRUE
 *  �������ΤȤ�CPU��å����֤Ȥ��롣
 */
volatile BOOL     iscpulocked = TRUE;

/*
 *  �ץ��å���¸�ν����
 */
void cpu_initialize(void) {

        /*
         *  �ʲ���4�Ĥϥ������ȥ��åץ롼����ǽ�������Ѥ�Ǥ��롣
         *  ����������ߥͥ��ȥ����� intnest = 1;
         *  �������󥿥�������ƥ����Ȥγ���ߥޥ��� int_intmask = 0;
         *  ����������������ƥ����Ȥγ���ߥޥ��� task_intmask = 0;
         *  ����������chg_ipm�򥵥ݡ��Ȥ������
         *  ������CPU��å��ե饰 iscpulocked = TRUE;
         */

	/* ���������⡼�ɤ����� */
	h8s_wrb_reg(SYSCR, SYS_SYSCR);

	/* ����ߥ�٥�ν���� */
	h8s_wrb_reg(IPRA, 0);
	h8s_wrb_reg(IPRB, 0);
	h8s_wrb_reg(IPRC, 0);
	h8s_wrb_reg(IPRD, 0);
	h8s_wrb_reg(IPRE, 0);
	h8s_wrb_reg(IPRF, 0);
	h8s_wrb_reg(IPRG, 0);
	h8s_wrb_reg(IPRH, 0);
	h8s_wrb_reg(IPRI, 0);
	h8s_wrb_reg(IPRJ, 0);
	h8s_wrb_reg(IPRK, 0);
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void cpu_terminate(void) {
}

/*
 * ���������Ԥ�
 * ������ջ��ࡧ
 * ������ɸ��Ǥ�dlytim��UINT������16�ӥåȤ����ʤ��Τǡ�
 * ������UW�����ѹ����Ƥ��롣
 * ������sil_dly_nse()��������sil_dly_nse_long()��ƤӽФ���
 */
void sil_dly_nse(UINT dlytim) {
	sil_dly_nse_long((UW)dlytim);
}

#ifdef SUPPORT_CHG_IPM

/*
 *  ����ߥޥ������ѹ�
 *
 *��IPM������Ǥ����ͤ�0��MAX_IPM�Ǥ��롣
 *������ߥץ饤����ƥ���٥뤬(MAX_IPM+1)�ʾ�γ���ߤϥ����ͥ������
 *�������Ǥ��롣
 *
 *  IPM �� 0 �ʳ��λ��ˤ⡤�������ǥ����ѥå�����α����ʤ���
 *  �ǥ����ѥå���ػߤ��������ˤϡ�loc_cpu �ˤ��CPU��å����֤�
 *  ����Ф褤��IPM �ϡ�
 *  �������ǥ����ѥå��ˤ�äơ��������¹Ծ��֤ˤʤä��������ذ����Ѥ�
 *  ��롥���Τ��ᡤ���������¹���ˡ��̤Υ������ˤ�ä� IPM ���ѹ���
 *  ����礬���롥JSP�����ͥ�Ǥϡ�IPM ���ѹ��ϥ������㳰�����롼��
 *  ��ˤ�äƤⵯ����Τ�������ˤ�äư������񤷤��ʤ�����Ͼ��ʤ���
 *  �פ��롥
 *��IPM ���ͤˤ�äƥ������ǥ����ѥå���ػߤ��������ˤϡ�dis_dsp��
 *  ʻ�Ѥ���Ф褤��
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
        ER      ercd = E_OK;

        LOG_CHG_IPM_ENTER(ipm);
        CHECK_TSKCTX_UNL();
        CHECK_PAR(ipm <= MAX_IPM);

        t_lock_cpu();
        task_intmask = ipm;
        t_unlock_cpu();

    exit:
        LOG_CHG_IPM_LEAVE(ercd)
        return(ercd);
}

/*
 *  ����ߥޥ����λ���
 */
SYSCALL ER
get_ipm(IPM *p_ipm)
{
        ER      ercd = E_OK;

        LOG_GET_IPM_ENTER(p_ipm);
        CHECK_TSKCTX_UNL();

        t_lock_cpu();
        *p_ipm = task_intmask;
        t_unlock_cpu();

    exit:
        LOG_GET_IPM_LEAVE(ercd, *p_ipm);
        return(ercd);
}


#endif /* SUPPORT_CHG_IPM */

/*============================================================================*/
/*  ���̥ɥ�����ȤˤϤʤ����ȼ�����ʬ  */

/*
 * ��Ͽ����Ƥ��ʤ������ߤ�ȯ������ȸƤӽФ����
 */
void 
cpu_experr(EXCSTACK *sp)
{
    UW sp2, pc, ccr, tmp;
    
    sp2 = (UW)sp + OFFSET_SP;
    tmp = sp->pc;
    ccr = (tmp >> 24U) & 0xff;	/*  ���1�Х���  */
    pc = tmp & 0x00ffffffUL;	/*  ����3�Х���  */
    
    syslog(LOG_EMERG, "Unexpected interrupt.");
    syslog(LOG_EMERG, "PC  = 0x%08lx SP  = 0x%08lx CCR  = 0x%02x",
                       (VP)pc, (VP)sp2, (INT)ccr);
    syslog(LOG_EMERG, "EXR  = 0x%02x", (INT)(sp->exr));
    syslog(LOG_EMERG, "ER0 = 0x%08lx ER1 = 0x%08lx ER2 = 0x%08lx ER3 = 0x%08lx",
           (VP)(sp->er0), (VP)(sp->er1), (VP)(sp->er2), (VP)(sp->er3));
    syslog(LOG_EMERG, "ER4 = 0x%08lx ER5 = 0x%08lx ER6 = 0x%08lx",
                       (VP)(sp->er4), (VP)(sp->er5), (VP)(sp->er6));
    while(1)
    	;
}


/*============================================================================*/
/*  �ǥХå��ѥ�����  */

#ifdef TEST_CPU_INSN

volatile UB ccr, exr;
volatile IPM intmask;

void test_cpu_insn(void)
{
	ccr = current_ccr();
	set_ccr(0xf);
	ccr = current_ccr();

	exr = current_exr();
	set_exr(0x7);
	exr = current_exr();

	intmask = current_intmask();
	set_intmask(0x3);
	intmask = current_intmask();
	
	disint();
	enaint();
	
	_disint_();
}

#endif /* TEST_CPU_INSN */


#ifdef TEST_CPU_CONFIG

volatile BOOL b;
volatile ER err;
volatile IPM ipm;

void dummy(void)
{
}

void test_cpu_config(void)
{
	b = sense_context();
	dummy();
	intnest = 1;
	dummy();
	b = sense_context();
	dummy();
	intnest = 0;
	dummy();
	b = sense_context();
	dummy();

	b = t_sense_lock();
	dummy();
	t_lock_cpu();
	dummy();
	b = t_sense_lock();
	dummy();
	t_unlock_cpu();
	dummy();
	b = t_sense_lock();
	dummy();

	i_lock_cpu();
	dummy();
	b = i_sense_lock();
	dummy();
	i_unlock_cpu();
	dummy();
	b = i_sense_lock();
	dummy();
	
	err = chg_ipm(6);
	dummy();
	err = get_ipm(&ipm);
	dummy();
	err = chg_ipm(3);
	dummy();
	err = get_ipm(&ipm);
	dummy();
	err = chg_ipm(8);
	dummy();
}

#endif /* TEST_CPU_CONFIG */

#ifdef TEST_H8S_SIL

volatile UB ddr;

void test_h8s_sil(void)
{
	ddr = sil_reb_ddr(IO_PORT7);
	sil_wrb_ddr(IO_PORT7, 0xff);
	ddr = sil_reb_ddr(IO_PORT7);
	sil_anb_ddr(IO_PORT7, 0xf);
	ddr = sil_reb_ddr(IO_PORT7);
	sil_orb_ddr(IO_PORT7, 0x80);
	ddr = sil_reb_ddr(IO_PORT7);
}

#endif /* TEST_H8S_SIL */



