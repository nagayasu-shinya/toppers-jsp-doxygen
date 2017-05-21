/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 * 
 *  @(#) $Id: cpu_config.c,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���PowerPC�ѡ�
 *���������������ͥ������ǻ��Ѥ������
 *������������C����ؿ��μ���
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <sil.h>


/*
 *  ����ߥϥ�ɥ顿����ߥޥ����ε����ơ��֥�
 */
FP int_table[TMAX_INTNO];


/*
 *  �㳰�٥����ε����ơ��֥�
 */
FP exc_table[TMAX_EXCNO];

/*
 *  ���顼��å������Υǡ����ơ��֥�
 *
 *  ����ץ���ơ�������ͭ���㳰0x1000�ϥ����ͥ뤬�Ѱդ����
 *  �����������ͳ���ʤ��Τǡ����Υơ��֥��0x10���ܤ����Ѥ����
 *  ���ȤϤʤ���
 */
static const char *(exe_list[]) = {
	"",				/*  0x0  */
	"System Reset",			/*  0x1  */
	"Machine Check",		/*  0x2  */
	"DSI",				/*  0x3  */
	"ISI",				/*  0x4  */
	"External Interrupt",		/*  0x5  */
	"Alignment",			/*  0x6  */
	"Program",			/*  0x7  */
	"Floating Point Unavailable",	/*  0x8  */
	"Decrementer",			/*  0x9  */
	"Implement Exception 0xa00",	/*  0xa  */
	"",				/*  0xb  */
	"System Call",			/*  0xc  */
	"Trace",			/*  0xd  */
	"Floating Point Assist",	/*  0xe  */
};


/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize()
{
    	INHNO i;
    	EXCNO j;

    	/* 
    	 * ����ߵ����٥����ơ��֥�����
    	 *
    	 *����0�ǽ��������̤��Ͽ�����ˤ��Ƥ���Τǡ�
    	 *��������߽�����ICU��¸��ʬPROC_ICU�Ǥϡ�
    	 *����̤��Ͽ�ξ��ν���������Ƥ�������
         */
    	for( i = 0; i < TMAX_INTNO; i++ ) {
        	define_inh( i, (FP)0 );
    	}

    	/* CPU�㳰�����٥����ơ��֥����� */
    	for( j = 0; j < TMAX_EXCNO; j++ ) {
        	define_exc( j, (FP)&no_reg_exception );
    	}
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate()
{
}

#ifdef SUPPORT_CHG_IPM

/*
 *  ����ߥޥ������ѹ�
 *
 *  PowerPC�����ˤ�IPM���ʤ�������ߥ���ȥ����IPM�Τ߰��ä�
 *  �����������
 *
 *  chg_ipm ��Ȥä� NMI�ʳ��Τ��٤Ƥγ���ߤ�ػߤǤ��뤫�ɤ���
 *  �ϳ���ߥ���ȥ���˰�¸���롣
 *  NMI�ʳ��Τ��٤Ƥγ���ߤ�ػߤ��������ˤϡ�loc_cpu�ˤ��CPU
 *  ��å����֤ˤ���Ф褤��
 *  IPM�ˤ�äư����γ���ߤ��ޥ�������Ƥ�����ˤ⡤�������ǥ���
 *  �ѥå�����α����ʤ���IPM�ϡ��������ǥ����ѥå��ˤ�äơ�����
 *  ���¹Ծ��֤ˤʤä��������ذ����Ѥ���롥���Τ��ᡤ����������
 *  ����ˡ��̤Υ������ˤ�ä� IPM���ѹ�������礬���롥JSP����
 *  �ͥ�Ǥϡ�IPM���ѹ��ϥ������㳰�����롼����ˤ�äƤⵯ���뤬��
 *  ����ˤ�äư������񤷤��ʤ�����Ͼ��ʤ��Ȼפ��롥IPM ����
 *  �ˤ�äƥ������ǥ����ѥå���ػߤ��������ˤϡ�dis_dsp��ʻ��
 *  ����Ф褤��
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);	/*  ICU��¸  */
	CHECK_TSKCTX_UNL();
	CHECK_IPM(ipm);		/*  ICU��¸  */

	t_lock_cpu();
	CHG_IPM(ipm);		/*  ICU��¸  */
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

	LOG_GET_IPM_ENTER(p_ipm);		/*  ICU��¸  */
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	GET_IPM(p_ipm);				/*  ICU��¸  */
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_GET_IPM_LEAVE(ercd, *p_ipm);	/*  ICU��¸  */
	return(ercd);
}

#endif /* SUPPORT_CHG_IPM */


/*  CPU�㳰�������ȯ�����Υ����å���Υǡ���ɽ��  */
void syslog_data_on_stack(EXCSTACK *sp)
{
    syslog(LOG_EMERG, "PC = 0x%08x SR = 0x%08x",
    			sp->srr0, sp->srr1);

    syslog(LOG_EMERG, "r0 = 0x%08x ", sp->r0);
    syslog(LOG_EMERG, "r3 = 0x%08x r4 = 0x%08x r5 = 0x%08x",
    			sp->r3, sp->r4, sp->r5);
    syslog(LOG_EMERG, "r6 = 0x%08x r7 = 0x%08x r8 = 0x%08x",
    			sp->r6, sp->r7, sp->r8);
    syslog(LOG_EMERG, "r9 = 0x%08x r10 = 0x%08x r11 = 0x%08x",
    			sp->r9, sp->r10, sp->r11);
    syslog(LOG_EMERG, "r12 = 0x%08x ", sp->r12);


    syslog(LOG_EMERG, "LR = 0x%08x CTR = 0x%08x",
    			sp->lr, sp->ctr );
    syslog(LOG_EMERG, "CR = 0x%08x XER = 0x%08x",
    			sp->cr, sp->xer );
}


/*
 * ��Ͽ����Ƥ��ʤ��㳰��ȯ������ȸƤӽФ����
 */

void no_reg_exception(EXCSTACK *sp)
{
    syslog(LOG_EMERG, "Exception error occurs.");
    syslog(LOG_EMERG, " [0x%02x]: %s", 
    	   sp->exc_no, exe_list[sp->exc_no]);

    /*  �����å���Υǡ�����ɽ��  */
    syslog_data_on_stack(sp);

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
VP
_dummy_memcpy(VP dest, VP src, UINT len)
{
	VB *d = (VB *)dest;
	VB *s = (VB *)src;

	while (len-- > 0) {
		*d++ = *s++;
	}
	return(dest);
}

/*  end of file  */
