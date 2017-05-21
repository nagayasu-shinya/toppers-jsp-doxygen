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
 *  @(#) $Id: cpu_config.c,v 1.16 2005/11/14 08:00:44 honda Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���SH1�ѡ�
 *���������������ͥ������ǻ��Ѥ������
 *������������C����ؿ��μ���
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <sil.h>

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
 *  ����ߡ�CPU�㳰�ͥ��ȥ�����
 */
UW	intnest;

/*
 *  ���ꥸ�ʥ�Υ٥����١����쥸��������¸�ΰ�
 */
#ifdef KERNEL_HAS_A_VECTOR_TABLE
static VP org_vbr;
#endif /* KERNEL_HAS_A_VECTOR_TABLE */

#ifdef SUPPORT_CPU_EXC_ENTRY_CHECK

/*
 *  CPU�㳰���װ���
 */
#ifndef NUM_EXC
#define NUM_EXC	(6 + 2)
#endif	/*  NUM_EXC  */

/*
 *  ��Ͽ���줿CPU�㳰���װ���
 */
static UW num_exc;

/*
 *  CPU�㳰��������������Ƭ���ɥ쥹
 */
static FP exc_entries[NUM_EXC];

#endif /* SUPPORT_CPU_EXC_ENTRY_CHECK */

/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize(void)
{
	/*
	 *  ����������ƥ����ȤǤγ���ߥޥ����ν����
	 */
#ifdef SUPPORT_CHG_IPM
	task_intmask = 0x0000u;
#endif /* SUPPORT_CHG_IPM */

	/*
	 *  ����ߡ�CPU�㳰�ͥ��ȥ����󥿤ν����
	 */
	intnest = 1u;

#ifndef GDB_STUB

	/*
	 * �����ߥ���ȥ���ν����
	 */
	sil_wrh_mem(IPRA, 0x0000);
	sil_wrh_mem(IPRB, 0x0000);
	sil_wrh_mem(IPRC, 0x0000);
	sil_wrh_mem(IPRD, 0x0000);
	sil_wrh_mem(IPRE, 0x0000);

#endif	/*  GDB_STUB  */

#ifdef KERNEL_HAS_A_VECTOR_TABLE
	/*
	 *  �٥����ơ��֥�Ͻ�����դ��ѿ�������ˤˤ����Τǡ�
	 *  �������ȥ��åץ롼�����data���������򥳥ԡ�����ݤ�
	 *  ���������롣
	 *  �ʤ����ǽ��������ɬ�פϤʤ�����
	 */
	
	/*
	 *  �٥����١����쥸�����ν����
	 */
	org_vbr = current_vbr();
	set_vbr((VP)vector_table);
#endif /* KERNEL_HAS_A_VECTOR_TABLE */

#ifdef SUPPORT_CPU_EXC_ENTRY_CHECK
	num_exc = 0;
#endif /* SUPPORT_CPU_EXC_ENTRY_CHECK */

}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate(void)
{
#ifdef KERNEL_HAS_A_VECTOR_TABLE
	set_vbr(org_vbr);
#endif /* KERNEL_HAS_A_VECTOR_TABLE */
}

/*
 *  CPU�㳰�ϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� excno ��CPU�㳰�ϥ�ɥ�ε�ư���Ϥ� exchdr �����ꤹ�롥
 */
void
define_exc(EXCNO excno, FP exchdr)
{
	/*  SH1�ϳ���ߤ�CPU�㳰��Ʊ������  */
	define_inh((INHNO)excno, exchdr);

#ifdef SUPPORT_CPU_EXC_ENTRY_CHECK
#if 0
	CHECK_PAR(num_exc < NUM_EXC);
#endif
	exc_entries[num_exc++] = exchdr;
#endif /* SUPPORT_CPU_EXC_ENTRY_CHECK */
}

#ifdef SUPPORT_CPU_EXC_ENTRY_CHECK
/*
 *  CPU�㳰�����������ǳ���߶ػߤ���ޤǤ�̿���
 */
#define NUM_INST_DIS_INT	5


/*
 *  ����ߤ���������Υ����å�
 *
 *  ������
 *  ����VP pc�������å�����Ѥޤ줿�������
 *  �������
 *  ����TRUE������褬CPU�㳰�����������ʳ���߶ػߤ�������
 *  ����FALSE������褬�嵭�ʳ�
 *  ������
 *  ��������ߤνи������ǳ���߶ػߤǸƤФ�롣
 */

/* cpu_support.S��ret_int��������ƤФ��Τ� 	*/
/* �إå����ե�����ˤϴޤ�ʤ��� 		*/
BOOL check_cpu_exc_entry(VP pc)   throw();

BOOL check_cpu_exc_entry(VP pc)
{
	UW i;
	UH *entry;	/* 2�Х���Ĺ̿��ؤΥݥ��� */
	
	for(i = 0; i < num_exc; i++) {
		entry = (UH *)exc_entries[i];
		if (((UW)entry <= (UW)pc) &&
		     ((UW)pc <= (UW)(entry + NUM_INST_DIS_INT)) ) {
			return TRUE;
		}
	}
	return FALSE;
}


#endif /* SUPPORT_CPU_EXC_ENTRY_CHECK */



#ifdef SUPPORT_CHG_IPM

/*
 *  ����ߥޥ������ѹ�
 *
 *  chg_ipm ��Ȥä� IPM ��0xf��NMI �ʳ��Τ��٤Ƥγ���ߤ�ػߡˤ��ѹ�
 *  ���뤳�ȤϤǤ��ʤ���NMI �ʳ��Τ��٤Ƥγ���ߤ�ػߤ��������ˤϡ�
 *  loc_cpu �ˤ��CPU��å����֤ˤ���Ф褤��
 *  IPM �� 0 �ʳ��λ��ˤ⡤�������ǥ����ѥå�����α����ʤ���IPM �ϡ�
 *  �������ǥ����ѥå��ˤ�äơ��������¹Ծ��֤ˤʤä��������ذ����Ѥ�
 *  ��롥���Τ��ᡤ���������¹���ˡ��̤Υ������ˤ�ä� IPM ���ѹ���
 *  ����礬���롥JSP�����ͥ�Ǥϡ�IPM ���ѹ��ϥ������㳰�����롼��
 *  ��ˤ�äƤⵯ���뤬������ˤ�äư������񤷤��ʤ�����Ͼ��ʤ���
 *  �פ��롥IPM ���ͤˤ�äƥ������ǥ����ѥå���ػߤ��������ˤϡ�
 *  dis_dsp ��ʻ�Ѥ���Ф褤��
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_PAR(0 <= ipm && ipm <= (MAX_IPM - 1) );

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
	ER	ercd;

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

/*
 * ��Ͽ����Ƥ��ʤ��㳰��ȯ������ȸƤӽФ����
 */
void cpu_experr(EXCSTACK *sp)
{
    syslog(LOG_EMERG, "Exception error occurs.");

    syslog(LOG_EMERG, "PC = 0x%08x SR = 0x%08x PR = 0x%08x",
    			sp->pc, sp->sr, sp->pr);

    syslog(LOG_EMERG, "r0 = 0x%08x r1 = 0x%08x r2 = 0x%08x",
    			sp->r0, sp->r1, sp->r2);
    syslog(LOG_EMERG, "r3 = 0x%08x r4 = 0x%08x r5 = 0x%08x",
    			sp->r3, sp->r4, sp->r5);
    syslog(LOG_EMERG, "r6 = 0x%08x r7 = 0x%08x r8 = 0x%08x",
    			sp->r6, sp->r7, sp->r8);
    syslog(LOG_EMERG, "r9 = 0x%08x r10 = 0x%08x r11 = 0x%08x",
    			sp->r9, sp->r10, sp->r11);
    syslog(LOG_EMERG, "r12 = 0x%08x r13 = 0x%08x r14 = 0x%08x",
    			sp->r12, sp->r13, sp->r14);
    			/*  �㳰ȯ��ľ���Υ����å��ݥ��󥿤���  */
    syslog(LOG_EMERG, "r15 = 0x%08x", (sp->r15)+19*4);

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
void *
_dummy_memcpy(void *dest, const void *src, size_t len)
{
	VB	*d = (VB *)dest;
	VB	*s = (VB *)src;

	while (len-- > 0) {
		*d++ = *s++;
	}
	return(dest);
}

