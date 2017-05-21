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

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include <cpu_rename.h>

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#include <cpu_insn.h>

/*
 *  chg_ipm/get_ipm �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define	SUPPORT_CHG_IPM

/*
 *  TCB ��Ϣ�����
 *
 *  cpu_context.h ��������������쥬��Ȥ��������Ȥΰ�¸���δط��ǡ�
 *  cpu_context.h �ˤ�������ʤ���
 */
#ifndef _MACRO_ONLY

/*  ����������ƥ����ȥ֥�å������  */
typedef struct task_context_block {
        VP	sp;             /* �����å��ݥ��� */
        FP	pc;             /* �ץ���५���� */
} CTXB;

#endif /* _MACRO_ONLY */

/*  TCB ��Υե�����ɤΥӥå��������  */
#define	TBIT_TCB_TSTAT		8	/* tstat �ե�����ɤΥӥå��� */
#define	TBIT_TCB_PRIORITY	8	/* priority �ե�����ɤΥӥå��� */

/*
 *  �����ƥ���ֻ���
 */

#ifndef _MACRO_ONLY

/*
 *  ����ƥ����Ȼ���
 *    ����ߥͥ��ȥ����󥿤��ɤ߽Ф���ľ��˳���ߤ�ȯ�����Ƥ⡢��ä��Ȥ��ˤ�
 *    ����ƥ����Ȥ⸵����äƤ��롣
 */
Inline BOOL sense_context() {

	UW intnest;

	Asm("move %0, "str_k0 :"=r"(intnest));

	return(intnest > 0);
}

Inline BOOL sense_lock() {

	return(!(current_sr() & SR_IE));
}

#endif /* _MACRO_ONLY */

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU��å��Ȥ��β���ʥ���������ƥ������ѡ�
 *    CPU��å����֤�Ƚ�Ǥϡ����ơ������쥸������IE�ӥåȤ��Ѥ���Ƚ�Ǥ��Ƥ��롣
 */

#ifndef _MACRO_ONLY

Inline void t_lock_cpu() {

	disint();		/* cpu_insn.h */
}

Inline void t_unlock_cpu() {

	enaint();		/* cpu_insn.h */
}

#endif /* _MACRO_ONLY */

/*
 *  CPU��å��Ȥ��β�����󥿥�������ƥ������ѡ�
 */

#define i_lock_cpu	t_lock_cpu
#define i_unlock_cpu	t_unlock_cpu

/*
 *  �������ǥ����ѥå���
 */

#ifndef _MACRO_ONLY

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���cpu_support.S��
 *    dispatch �ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ������������ǡ�
 *    CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	dispatch(void);

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���cpu_support.S��
 *    exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	exit_and_dispatch(void);

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ������
 */

/*  ����ߥϥ�ɥ顿����ߥޥ��������ơ��֥�  */
extern INT_TABLE int_table[ TMAX_ALL_INTNO ];

/*  �㳰�ϥ�ɥ鵼���ơ��֥�  */
extern FP	 exc_table[ TMAX_CORE_EXCNO ];

/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ�(������װ��ֹ�)intno �γ���ߥϥ�ɥ�ε�ư���Ϥ�inthdr�����ꡣ
 */

Inline void define_inh(INTNO intno, FP inthdr) {

	int_table[intno].inthdr = inthdr;
}

/*
 *   CPU�㳰�ϥ�ɥ������
 */

Inline void define_exc(EXCNO excno, FP exchdr) {

	exc_table[excno] = exchdr;
}

#endif /* _MACRO_ONLY */

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 */

#define	INTHDR_ENTRY(inthdr)  extern void inthdr(void)
#define INT_ENTRY(inthdr) inthdr

/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 *
 */
#define	EXCHDR_ENTRY(exchdr)  extern void exchdr(VP sp)
#define	EXC_ENTRY(exchdr)     exchdr

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */

#ifndef _MACRO_ONLY

/*
 *  CPU�㳰��ȯ���������Υ���ƥ�����Ƚ��
 */
Inline BOOL exc_sense_context(VP p_excinf) {

	UW  nest;

	Asm( "move %0, "str_k0 : "=r"(nest) );

	return( nest > 1 );
		/* 1����Ӥ���Τϡ����߼¹����CPU�㳰��ʬ��������ߥͥ���
		   �����󥿤����󥯥���Ȥ���Ƥ��뤿�� */
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
Inline BOOL exc_sense_lock(VP p_excinf) {

	/* Status�쥸�����ϡ������å���22���ܤ��Ѥޤ�Ƥ��롣
	   exc_stack(mips3.h), cpu_support.S ���� */
	return( !( *((UW *)p_excinf + 21) & SR_IE) );
}

/*
 *  �ץ��å���¸�ν����
 */
extern void	cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void	cpu_terminate(void);

#endif /* _MACRO_ONLY */

/*============================================================================*/
/*  ���̥ɥ�����ȤˤϤʤ����ȼ�����ʬ  */

/*  �ץ��å������ܳ���ߥ���ȥ�������ꤹ�����ߥޥ����Υ����å�  */
#define CHECK_IPM(ipm)	     CHECK_CORE_IPM( (ipm.core >> 8) & 0xff );	\
			     CHECK_ICU_IPM( ipm.icu )

#ifndef _MACRO_ONLY

/*
 *  �����ߥ�٥������ʶ���������ϸƤӽФ���ʤ���
 */

Inline void all_set_ilv(INTNO intno, IPM *ipm) {

	/*  MIPS������ intmask �ơ��֥������  */
	int_table[intno].intmask = SR_BEV | (ipm->core) | SR_IE;
			/* ����ߥ٥�����kseg1�˻��äƤ��뤿�ᡢBEV=1 */

	/*  ����ߥ���ȥ���γ���ߥޥ����ơ��֥������  */
	/*  �ʳ���ߥ�٥�������  */
	icu_set_ilv( intno, &(ipm->icu) );
}

#endif /* _MACRO_ONLY */

/*
 *  �������Ѥδؿ�
 */

#ifndef _MACRO_ONLY

/* ��Ͽ����Ƥ��ʤ�����ߡ��㳰ȯ�����Υ����� (cpu_config.c, cpu_support.S) */
extern void     cpu_experr( EXCSTACK *sp, UW SR, UW CR );

#endif /* _MACRO_ONLY */

#endif /* _CPU_CONFIG_H_ */
