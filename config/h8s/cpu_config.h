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
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include <cpu_rename.h>

/*
 *  �ץ��å���Ϣ�����
 */
#include <h8s.h>
#include <h8s_sil.h>

/*
 *  �����ǽ�ʥ����ͥ�������κǹ���ĳ���ߥӥåȥѥ�����
 *  (�������ƥ�ɥ쥸����������;cpu_insn.h ������Ѥ���Τǡ����������롣)
 */
#ifndef GDB_STUB
#define  MAX_IPM	7	/* = EXR_I2|EXR_I1|EXR_I0 (�ǹ��٥�) */
#else  /* GDB_STUB */
#define  MAX_IPM	6	/* ��٥룷�γ����ߤϡ�GDB_STUB �����Ѥ��� */
#endif /* GDB_STUB */

#define  str_MAX_IPM	TO_STRING(MAX_IPM)
			/* �������������INTHDR_ENTRY�ޥ����� (cpu_config.h) */

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 *    �����ǡ�MAX_IPM�����Ѥ��Ƥ���Τǡ��������ɤ߹���
 */
#include <cpu_insn.h>

/*
 *  chg_ipm/get_ipm �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define	SUPPORT_CHG_IPM

/*
 *  ����������ƥ����ȥ֥�å������
 */
#ifndef _MACRO_ONLY

typedef struct task_context_block {
	VP	sp;		/* �����å��ݥ��� */
	FP	pc;		/* �ץ���५���� */
} CTXB;

#endif /* _MACRO_ONLY */

/*
 *  �����ƥ���ֻ���
 */
#ifndef _MACRO_ONLY

/*
 *  ����ߥͥ��ȥ�����
 *    �ͥ��ȥ����󥿤��ͤǥ���ƥ����Ȥ�Ƚ�Ǥ�Ԥ��Τǡ�����ƥ����Ȼ��Ȼ���
 *    ���Ѥ��롣
 */

extern UW	intnest;

/*
 *  ����ƥ����Ȼ���
 *    ����ߥͥ��ȥ����󥿤��ɤ߽Ф���ľ��˳���ߤ�ȯ�����Ƥ⡢��ä��Ȥ��ˤ�
 *    ����ƥ����Ȥ⸵����äƤ���
 */

Inline BOOL
sense_context(void)
{
	return( intnest > 0 );
}

Inline BOOL
sense_lock(void)
{
	return( current_intmask() == MAX_IPM );
}

#endif /* _MACRO_ONLY */

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

#ifndef _MACRO_ONLY

/*
 *  CPU��å��Ȥ��β���ʥ���������ƥ������ѡ�
 *
 *  task_intmask �ϡ�chg_ipm �򥵥ݡ��Ȥ��뤿����ѿ���chg_ipm �򥵥ݡ���
 *  ���ʤ����ˤϡ�t_unlock_cpu ��� task_intmask �� 0 ���֤������Ƥ褤��
 */

#ifdef SUPPORT_CHG_IPM
extern IPM	task_intmask;	/* ����������ƥ����ȤǤγ���ߥޥ��� */
#endif /* SUPPORT_CHG_IPM */

Inline void
t_lock_cpu(void)
{
	disint();		/* cpu_insn.h */
}

Inline void
t_unlock_cpu(void)
{
#ifdef SUPPORT_CHG_IPM
	/*
	 *  t_unlock_cpu ���ƤӽФ����Τ� CPU��å����֤ΤߤǤ��뤿�ᡣ
	 *  ����������� task_intmask ���񤭴���뤳�ȤϤʤ���
	 */
	set_intmask(task_intmask);
#else /* SUPPORT_CHG_IPM */
	enaint();		/* cpu_insn.h */
#endif /* SUPPORT_CHG_IPM */
}

/*
 *  CPU��å��Ȥ��β�����󥿥�������ƥ������ѡ�
 */

extern IPM	int_intmask;	/* �󥿥�������ƥ����ȤǤγ���ߥޥ��� */

Inline void
i_lock_cpu(void)
{
	IPM	intmask;

	/*
	 *  ����ѿ� intmask ��ȤäƤ���Τϡ�current_intmask()��Ƥ��ľ���
	 *  ����ߤ�ȯ��������ư���줿����ߥϥ�ɥ���� int_intmask ���ѹ�
	 *  ������ǽ�������뤿��Ǥ��롣
	 */
	intmask = current_intmask();
	disint();		/* cpu_insn.h */
	int_intmask = intmask;
}

Inline void
i_unlock_cpu(void)
{
	set_intmask(int_intmask);
}

/*
 *  �������ǥ����ѥå���
 */

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
 *  ����ߥϥ�ɥ������
 *    H8S�Ǥϡ�����ߥϥ�ɥ�ơ��֥�������ROM��ľ�ܹԤ�������Ѥ��ʤ���
 */

Inline void define_inh(INHNO inhno, FP inthdr) {
}

/*
 *  CPU�㳰�ϥ�ɥ������
 *    H8S�Ǥϡ�����ߥϥ�ɥ�ơ��֥�������ROM��ľ�ܹԤ�������Ѥ��ʤ���
 */

Inline void define_exc(EXCNO excno, FP exchdr) {
}

#endif /* _MACRO_ONLY */

/*
 *  ����ߥϥ�ɥ�ν���������
 */

/*
 *  ����ߥϥ�ɥ����������
 *    ���ν��������ޤǤˡ��ϡ��ɥ������ˤơ���������ߥ�٥�ޤǤγ���ߤ�
 *    �ػߤ���������Ԥ��Ƥ��롣
 *    entry�����������Υ�٥�
 *    inthdr��C����롼�������Ƭ���ɥ쥹
 */
#define	_INTHDR_ENTRY(entry, inthdr)		    \
asm("	.text					\n" \
"	.align 2				\n" \
"	.global _"#entry"			\n" \
"						\n" \
"_"#entry":					\n" \
"	push.l	er0				\n" \
			/* CPU��å���ɬ�פʥ쥸�����򥿥��������å������� */ \
"	stc.b	exr, r0l			\n" \
			/* exr �� r0l (er0) �˥��ԡ� \
"			  (_kernel_ret_main ��ǡ�����߶ػߵ�������˻Ȥ�) */ \
"						\n" \
"	ldc.b	#"str_MAX_IPM", exr		\n" \
			/* lock_cpu ���� (����߶ػ�) */ \
"						\n" \
"	push.l	er1				\n" \
			/* er1 �򥿥��������å������� */ \
"	mov.l	#_"#inthdr", er1		\n" \
			/* er1 = ����ߥϥ�ɥ�Υ��ɥ쥹 */ \
"	jmp	_kernel_ret_main		\n" \
			/* ��������������إ����� */ \
)

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 */
#define INTHDR_ENTRY(inthdr)			\
	extern void inthdr##_entry(void);	\
	_INTHDR_ENTRY(inthdr##_entry, inthdr)	/* ���ν����Ͼ嵭�ޥ������� */
#define	INT_ENTRY(inthdr)	inthdr##_entry

/* �٥����ơ��֥�(sys_support.S)�����ѥ�٥�����ޥ��� */
#define	__INT_ENTRY(inthdr)	_##inthdr##_entry
#define	_INT_ENTRY(inthdr)	__INT_ENTRY(inthdr)

/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 */
#define	EXCHDR_ENTRY(exchdr)	INTHDR_ENTRY(exchdr)
#define	EXC_ENTRY(exchdr)	exchdr##_entry

/* �٥����ơ��֥�(sys_support.S)�����ѥ�٥�����ޥ��� */
#define	__EXC_ENTRY(exchdr)	_##exchdr##_entry
#define	_EXC_ENTRY(exchdr)	__EXC_ENTRY(exchdr)

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */
#ifndef _MACRO_ONLY

/*
 *  CPU�㳰��ȯ���������Υ���ƥ�����Ƚ��
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return(intnest > 1);
		/* 1����Ӥ���Τϡ����߼¹����CPU�㳰��ʬ����ߥͥ���
		   �����󥿤����󥯥���Ȥ���Ƥ��뤿�� */
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 *    H8S�ǤǤϡ��ƤФ�뤳�Ȥ�̵����������������Ӥ�������������ꤹ�롣
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return(TRUE);
}

/*
 *  �ץ��å���¸�ν����
 */
extern void	cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void	cpu_terminate(void);

#endif /* _MACRO_ONLY_ */

/*============================================================================*/
/*  ���̥ɥ�����ȤˤϤʤ����ȼ�����ʬ  */

/*
 *  ����ߥ�٥������ѥޥ���ʤ⤷���ϡ�����饤��ؿ���
 *  ��x : ���󥿥�ץȥץ饤����ƥ��쥸����	( IPRA - IPRK )
 *  ��y : IPR�����ѥޥ����ʾ�̤����̤������	( IPR_UPR, IPR_LOW )
 *  ��z : ����ߥ�٥�				( 0 - 7 )
 */
#ifndef _MACRO_ONLY

Inline void icu_set_ilv( VP ipr, BOOL mask, INT level ) {

	if( mask == IPR_UPR ) {
		h8s_wrb_mem( ipr, ( h8s_reb_mem( ipr ) & ~IPR_UPR_MASK ) | TO_HI4((UB) level) );
	} else if( mask == IPR_LOW ) {
		h8s_wrb_mem( ipr, ( h8s_reb_mem( ipr ) & ~IPR_LOW_MASK ) | TO_LO4((UB) level) );
	}
}

#endif /* _MACRO_ONLY_ */

#ifndef _MACRO_ONLY
/*
 *  ̤��������ȯ�����Υ��顼���� (cpu_config.c, cpu_support.S)
 *    ��¤�� EXCSTACK �ϡ�h8s.h �����
 */
extern void	cpu_experr(EXCSTACK *sp);

#endif /* _MACRO_ONLY_ */

#endif /* _CPU_CONFIG_H_ */
