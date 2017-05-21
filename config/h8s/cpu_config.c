/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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
IPM	task_intmask;		/* IPM -> UB�����̵��8�ӥå� */
#endif /* SUPPORT_CHG_IPM */

/*
 *  �󥿥�������ƥ����ȤǤγ���ߥޥ���
 */
IPM	int_intmask;

/*
 *  ����ߥͥ��ȥ�����
 */
UW	intnest;

/*
 *  �ץ��å���¸�ν����
 */
void cpu_initialize() {

#ifdef SUPPORT_CHG_IPM
	/* ����������ƥ����ȤǤγ���ߥޥ����ν���� */
	task_intmask = 0x00;
#endif /* SUPPORT_CHG_IPM */

	/* ����ߡ�CPU�㳰�ͥ��ȥ����󥿤ν���� */
	intnest = 1;

	/* ����ߥ�٥�ν���� */
	icu_set_ilv( (VP) IPRA, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRA, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRB, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRB, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRC, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRC, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRD, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRD, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRE, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRE, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRF, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRF, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRG, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRG, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRH, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRH, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRI, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRI, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRJ, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRJ, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRK, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRK, IPR_LOW, 0 );
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void cpu_terminate() {
}

/*
 *  ���������Ԥ�
 */
void sil_dly_nse(UINT dlytim) {
	/* er0 = dlytim */
	Asm("		sub.l	%0, er0" :: "g"(SIL_DLY_TIM1) );
	Asm("		ble	sil_dly_nse_2");
				/* dlytim < SIL_DLY_TIM1 �ʤ�롼�׽�λ */
	Asm("	sil_dly_nse_1:");
	Asm("		sub.l	%0, er0" :: "g"(SIL_DLY_TIM2) );
	Asm("		bgt	sil_dly_nse_1");
				/* dlytim > SIL_DLY_TIM2 �ʤ�롼��³�� */
	Asm("	sil_dly_nse_2:");
}

#ifdef SUPPORT_CHG_IPM

/*
 *  ����ߥޥ������ѹ�
 *
 *  ��chg_ipm ��Ȥäơ�����ߥޥ����� MAX_IPM ��NMI �����֥�⡼�ȥ֥졼�� �ʳ�
 *    �Τ��٤Ƥγ���ߤ�ػߡ˰ʾ���ѹ����뤳�ȤϤǤ��ޤ���NMI �����֥�⡼��
 *    �֥졼���ʳ��Τ��٤Ƥγ���ߤ�ػߤ��������ˤϡ�loc_cpu�ˤ��CPU��å�
 *    ���֤ˤ��Ƥ���������
 *  ������ߥޥ����� 0 �ʳ��λ��Ǥ��äƤ⡢�������ǥ����ѥå�����α����ޤ���
 *    ���ΤȤ�������ߥޥ����ξ��֤ϡ��������ǥ����ѥå��ˤ�äƿ������¹Ծ��֤�
 *    �ʤä��������ء��������١������Ѥ���ޤ���
 *    ���Τ��ᡢ���������¹���ˡ�����ߤ�ȯ�������ǥ����ѥå���������̤Υ�����
 *    �ˤ�äƳ���ߥޥ������ѹ�������礬����ޤ���
 *    TOPPERS/JSP �����ͥ�Ǥϡ�����ߥޥ������ѹ��ϥ������㳰�����롼����ˤ��
 *    �Ƥⵯ����Τǡ�����ˤ�äư������񤷤��ʤ�����Ͼ��ʤ��Ȼפ��ޤ���
 *  ������ߥޥ������ͤˤ�äƥ������ǥ����ѥå���ػߤ��������ˤϡ�dis_dsp ��
 *    ʻ�Ѥ��Ƥ���������
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_PAR( /*(0 <= ipm) &&*/ (ipm <= MAX_IPM) );
	/* IPM�� �ϡ�unsigned ��������Ƥ���Τǡ������ȥ����Ȥ���
	   ����Ȥ���ϡ������Ω���Ƥ��뤿�ᡢWarnning ��ȯ�����롣
	   �������������������꤫�顢����Ū�˵��Ҥ��Ƥ����� */

	t_lock_cpu();
	task_intmask = ipm;
	ercd = E_OK;
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
	ER	ercd;

	LOG_GET_IPM_ENTER(p_ipm);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_ipm = task_intmask;
	ercd = E_OK;
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
void cpu_experr(EXCSTACK *sp)
{
	syslog( LOG_EMERG, "Unexpected interrupt." );
	syslog( LOG_EMERG, "SP  = %08x PC  = %08x CCR = %08x",
				sp - 34, sp->pc,  sp->ccr );
	syslog( LOG_EMERG, "ER0 = %08x ER1 = %08x ER2 = %08x ER3 = %08x",
				sp->er0, sp->er1, sp->er2, sp->er3 );
	syslog( LOG_EMERG, "ER4 = %08x ER5 = %08x ER6 = %08x ",
				sp->er4, sp->er5, sp->er6 );

	while(1);
}

/*
 *  ����֥�å����饤�֥��
 *	(ItIs�����ή��)
 *
 *  �ؿ��λ��ͤϡ�ANSI C �饤�֥��λ��ͤ�Ʊ����ɸ��饤�֥��Τ�Τ�
 *  �Ȥä�������Ψ���ɤ���ǽ�������롥
 *
 */
VP _dummy_memcpy(VP dest, VP src, UINT len)
{
	VB	*d = (VB *)dest;
	VB	*s = (VB *)src;

	while (len-- > 0) {
		*d++ = *s++;
	}

	return(dest);
}
