/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 *  �ץ��å���¸�⥸�塼���MIPS3�ѡ�
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  ����ߥϥ�ɥ顿����ߥޥ����ε����ơ��֥�
 */
INT_TABLE int_table[ TMAX_ALL_INTNO ];

/*
 *  �㳰�ϥ�ɥ�ε����ơ��֥�
 */
FP exc_table[ TMAX_CORE_EXCNO ];

/*
 *  �ץ��å���¸�ν����
 */
void cpu_initialize() {

	int i;

	/* ����ߥϥ�ɥ顿����ߥޥ����ε����ơ��֥����� */
	for( i = 0; i < TMAX_ALL_INTNO; i++ ) {
		define_inh( i, (FP) &cpu_experr );
	}

	/* �㳰�٥����ε����ơ��֥����� */
	for( i = 0; i < TMAX_CORE_EXCNO; i++ ) {
		define_exc( i, (FP) &cpu_experr );
	}

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

	/* $2 : v0, $3 : v1 */
	Asm("	move	$2, %0" :: "r"(dlytim) );
	Asm("	li	$3, %0" :: "g"(SIL_DLY_TIM1) );

	Asm("	sub	$2, $2, $3");	/* v0 -= v1 (dlytim -= SIL_DLY_TIM1) */
	Asm("	blez    $2, sil_dly_nse_2");	/* v0 <= 0 �ʤ�꥿���� */

	Asm("	li      $3, %0" :: "g"(SIL_DLY_TIM2) );

	Asm("sil_dly_nse_1:");
	Asm("	sub     $2, $2, $3");	/* v0 -= v1 (dlytim -= SIL_DLY_TIM2) */
	Asm("	bgtz    $2, sil_dly_nse_1");	/* v0 > 0 �ʤ�롼�� */

	Asm("sil_dly_nse_2:");
}

#ifdef SUPPORT_CHG_IPM

/*
 *  ����ߥޥ������ѹ�
 *
 *  ����ߥޥ����ϡ��������ǥ����ѥå��ˤ�äơ��������¹Ծ��֤ˤʤä���������
 *  �����Ѥ���롣���Τ��ᡢ���������¹���ˡ��̤Υ������ˤ�äƳ���ߥޥ�����
 *  �ѹ�������礬���롣JSP�����ͥ�Ǥϡ�����ߥޥ������ѹ��ϥ������㳰����
 *  �롼����ˤ�äƤⵯ���뤬������ˤ�äư������񤷤��ʤ�����Ͼ��ʤ��Ȼפ�
 *  ��롣����ߥޥ������ͤˤ�äƥ������ǥ����ѥå���ػߤ��������ˤϡ�
 *  dis_dsp ��ʻ�Ѥ���Ф褤��
 *  MIPS3�������åȤǤϡ�MIPS3�����γ���ߥޥ��������Ǥʤ�������ߥ���ȥ���
 *  �γ���ߥ���ȥ���ⰷ�äƤ���Τ���ա�
 */

SYSCALL ER chg_ipm(IPM ipm) {

	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_IPM(ipm);

	t_lock_cpu();
	cpu_set_ipm( ipm.core );	/* MIPS3�����γ���ߥޥ��������� */
	icu_set_ipm( &(ipm.icu) );	/* ��������ߥ���ȥ���γ���ߥޥ���
					   ������ */
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_CHG_IPM_LEAVE(ercd);
	return(ercd);
}

/*
 *  ����ߥޥ����λ���
 */
SYSCALL ER get_ipm(IPM *p_ipm) {

	ER	ercd;

	LOG_GET_IPM_ENTER(p_ipm);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	p_ipm->core = cpu_get_ipm();	/* MIPS3�����γ���ߥޥ������� */
	icu_get_ipm(&(p_ipm->icu));	/* ��������ߥ���ȥ���γ���ߥޥ���
					   �λ��� */
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
 * �ϥ�ɥ餬��Ͽ����Ƥ��ʤ�����ߡ��㳰��ȯ������ȸƤӽФ����
 */
void cpu_experr( EXCSTACK *sp, UW SR, UW CR) {

    syslog_0(LOG_EMERG, "Interrupt/Exception error occurs.");

    syslog_1(LOG_EMERG, "PC(EPC;CP0_r14) = 0x%08x",
    			sp->CP0_EPC);
    syslog_2(LOG_EMERG, "SR(Status;CP0_r12) = 0x%08x CR(Cause;CP0_r13) = 0x%08x",
    			SR, CR);	/* SR�Ǥ⡢sp->CP0_Status�Ǥ�� */
    syslog_3(LOG_EMERG, "at(r1 ) = %08x v0(r2 ) = %08x v1(r3 ) = %08x",
    			sp->at, sp->v0, sp->v1);
    syslog_4(LOG_EMERG, "a0(r4 ) = %08x a1(r5 ) = %08x a2(r6 ) = %08x a3(r7 ) = %08x",
    			sp->a0, sp->a1, sp->a2, sp->a3);
    syslog_4(LOG_EMERG, "t0(r8 ) = %08x t1(r9 ) = %08x t2(r10) = %08x t3(r11) = %08x",
    			sp->t0, sp->t1, sp->t2, sp->t3);
    syslog_4(LOG_EMERG, "t4(r12) = %08x t5(r13) = %08x t6(r14) = %08x t7(r15) = %08x",
    			sp->t4, sp->t5, sp->t6, sp->t7);
    syslog_2(LOG_EMERG, "t8(r24) = %08x t9(r25) = %08x",
    			sp->t8, sp->t9);
    syslog_2(LOG_EMERG, "HI = %08x LO = %08x",
    			sp->hi, sp->lo);
    syslog_4(LOG_EMERG, "gp(r28) = %08x sp(r29) = %08x fp(r30) = %08x ra(r31) = %08x",
    			sp->gp, sp->sp, sp->fp, sp->ra);
    while(1);
}

/*
 *  ����֥�å����饤�֥��ʥ�󥯥�����ץ���ǻ��ѡ�
 *	(ItIs�����ή��)
 *
 *  �ؿ��λ��ͤϡ�ANSI C �饤�֥��λ��ͤ�Ʊ����ɸ��饤�֥��Τ�Τ�
 *  �Ȥä�������Ψ���ɤ���ǽ�������롥
 */
VP _dummy_memcpy(VP dest, VP src, UINT len) {

	VB	*d = dest;
	VB	*s = src;

	while (len-- > 0) {
		*d++ = *s++;
	}

	return(dest);
}
