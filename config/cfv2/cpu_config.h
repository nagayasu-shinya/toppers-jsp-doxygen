/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.14 2003/07/08 14:57:12 hiro Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���CFV2�ѡ�
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
 *  ���ͥǡ���ʸ�����ѥޥ�������
 */
#include <util.h>

/*
 *  �桼�����������
 */
#include <user_config.h>

/*
 *  �����ǽ�ʺǹ�ͥ����
 */
#ifdef GDB_STUB
#define MAX_IPM  0x6	/* �����֤���ξ���ͥ����6��CPU��å�   */
#else
#define MAX_IPM  0x7	/* �����֤ʤ��ξ��Ϻǹ�ͥ���٤�CPU��å� */
#endif /*  GDB_STUB  */

#define str_MAX_IPM  		TO_STRING(MAX_IPM)

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif /* _MACRO_ONLY */

/*
 *  chg_ipm/get_ipm �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define	SUPPORT_CHG_IPM

/*
 *  TCB ��Υե�����ɤΥӥå��������
 *
 *  cpu_context.h ��������������쥬��Ȥ��������Ȥΰ�¸���δط��ǡ�
 *  cpu_context.h �ˤ�������ʤ���
 */
#define	TBIT_TCB_TSTAT		8	/* tstat �ե�����ɤΥӥå��� */
#define	TBIT_TCB_PRIORITY	8	/* priority �ե�����ɤΥӥå��� */

#ifndef _MACRO_ONLY
/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	VP	msp;		/* �����å��ݥ��� */
	FP	pc;		/* �ץ���५���� */
} CTXB;

/*
 *  ����ߥޥ������饤�֥��
 *
 *  ����ߥޥ�����intmask�ˤϡ�IPM��Interrupt Priority Mask�ˤ�8�ӥå�
 *  ���˥��եȤ�����ΤǤ��롥
 */

/*
 *  ���ߤγ���ߥޥ������ɽФ�
 */
Inline UH
current_intmask()
{
	return(current_sr() & 0x0700);
}

/*
 *  ����ߥޥ���������
 */
Inline void
set_intmask(UH intmask)
{
	set_sr((current_sr() & ~0x0700) | intmask);
}

/*
 *  ����ߡ�CPU�㳰�ͥ��ȥ�����
 */
extern UW	intnest;

/*
 *  �����ƥ���ֻ���
 */

Inline BOOL
sense_context()
{
	return(intnest > 0);
}

Inline BOOL
sense_lock()
{
	return(current_intmask() == (MAX_IPM << 8));
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU��å��Ȥ��β���ʥ���������ƥ������ѡ�
 *
 *  task_intmask �ϡ�chg_ipm �򥵥ݡ��Ȥ��뤿����ѿ���chg_ipm �򥵥ݡ�
 *  �Ȥ��ʤ����ˤϡ�task_intmask ����� 0 �ˤʤäƤ���ȹͤ���Ф褤��
 */

#ifdef SUPPORT_CHG_IPM
extern UH	task_intmask;	/* ����������ƥ����ȤǤγ���ߥޥ��� */
#endif /* SUPPORT_CHG_IPM */

Inline void
t_lock_cpu()
{
	disint();
}

Inline void
t_unlock_cpu()
{
#ifdef SUPPORT_CHG_IPM
	/*
	 *  t_unlock_cpu ���ƤӽФ����Τ� CPU��å����֤ΤߤǤ��뤿
	 *  �ᡤ����������� task_intmask ���񤭴���뤳�ȤϤʤ���
	 */
	set_intmask(task_intmask);
#else /* SUPPORT_CHG_IPM */
	enaint();
#endif /* SUPPORT_CHG_IPM */
}

/*
 *  CPU��å��Ȥ��β�����󥿥�������ƥ������ѡ�
 */

extern UH	int_intmask;	/* �󥿥�������ƥ����ȤǤγ���ߥޥ��� */

Inline void
i_lock_cpu()
{
	UH	intmask;

	/*
	 *  ����ѿ� intmask ��ȤäƤ���Τϡ�current_intmask() ���
	 *  ���ľ��˳���ߤ�ȯ��������ư���줿����ߥϥ�ɥ����
	 *  int_intmask ���ѹ�������ǽ�������뤿��Ǥ��롥
	 */
	intmask = current_intmask();
	disint();
	int_intmask = intmask;
}

Inline void
i_unlock_cpu()
{
	set_intmask(int_intmask);
}

/*
 *  �������ǥ����ѥå���
 */

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���cpu_support.S��
 *
 *  dispatch �ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ����������
 *  ��ǡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	dispatch(void);

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���cpu_support.S��
 *
 *  exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	exit_and_dispatch(void);

#endif  /* _MACRO_ONLY */

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ������
 */

/*
 *  �㳰�٥����ơ��֥�����
 *  �����ޥ��������
 *  ������KERNEL_HAS_A_VECTOR_TABLE
 *  �������������ͥ뤬�㳰�٥����ơ��֥�����
 *  ������SIO_RESERVED
 *  �����������ꥢ��ǥХ������ǥХå��ˤ�äƻ��Ѥ���Ƥ���
 */
#ifndef _MACRO_ONLY

#ifdef KERNEL_HAS_A_VECTOR_TABLE
extern FP vector_table[];	/*  �㳰�٥����ơ��֥�  */
#endif /* KERNEL_HAS_A_VECTOR_TABLE */

typedef struct exc_vector_entry {
	FP	exchdr;			/* �㳰�ϥ�ɥ�ε�ư���� */
} EXCVE;

/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{
#ifdef GDB_STUB
        Asm("moveq.l #0x8,%%d0;  move.l %0,%%d2; move.l %1,%%d3; trap #0xf"
	    : /* no output */
	    : "r"(inhno), "r"(inthdr)
	    : "%%d0", "%%d2", "%%d3");
#else	/*  GDB_STUB  */

#ifdef KERNEL_HAS_A_VECTOR_TABLE

/* SIO_RESERVED�ϻ��Ѥ��ʤ���sys_config.h�ǥ����Ȥˤ��Ƥ��� */
/*#ifdef SIO_RESERVED	*//*  ���ꥢ������ߤ��򤱤�  */
/*	if ((inhno != RXI0) && (inhno != TXI0))*/
/*#endif *//* SIO_RESERVED */ 
	vector_table[inhno] = inthdr;

#endif /* KERNEL_HAS_A_VECTOR_TABLE */

#endif	/*  GDB_STUB  */
}

/*
 *  CPU�㳰�ϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� excno ��CPU�㳰�ϥ�ɥ�ε�ư���Ϥ� exchdr �����ꤹ�롥
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
	define_inh(excno, exchdr);
}

/*  C����롼����δؿ�̾�������������Υ�٥������  
 *     kernel_cfg.c�ǻ���
 */
#define	INT_ENTRY(inthdr)	_kernel_##inthdr##_entry
#define	EXC_ENTRY(exchdr)	_kernel_##exchdr##_entry


/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ�����������ζ�����ʬ
 *
 *	ColdFire�Ǥϡ�����ߤ�CPU�㳰�ΰ������ۤȤ��Ʊ���ʤΤǡ�
 *	���������Υޥ���ⶦ�̤�������Ƥ���
 *
 *��������
 *	label�����������Υ�٥�
 *	inthdr��C����롼�������Ƭ���ɥ쥹
 *	common_routine��cpu_support.S���ʬ���襢�ɥ쥹
 *			interrupt_entry������ߤξ��
 *			cpu_exception_entry��CPU�㳰�ξ��
 *
 *�����쥸��������
 *��������d1������߼���ľ���SR�Υ��ԡ�
 *��������a0��C����롼�������Ƭ���ɥ쥹
 *
 *	����ߤ�CPU�㳰�������
 *	������CPU�㳰�ϥ�ɥ�˰�����Ϳ����
 *	������CPU�㳰�Ǥϡ��㳰ȯ������IPM��Ʊ���ͤǳ���ߤ���Ĥ���
 *		��CPU�㳰�ˤ�ꡢIPM���Ѳ������ʤ���
 *
 *	����������ߥϥ�ɥ�ξ��				
 *	����  	����߼��ջ��˥ϡ��ɥ�������IPM�����ꤹ��	
 *	����  	����ߵ��ĤˤϤ���IPM���ͤ��Ѥ���		
 *	������CPU�㳰�ϥ�ɥ�ξ��				
 *	����  	CPU�㳰���ջ���IPM���ͤ��Ѳ����ʤ�		
 *	����  	����ߵ��Ĥˤ�CPU�㳰ȯ������IPM���ͤ��Ѥ���	
 */
#define	HANDLER_ENTRY_PROC(label, handler, common_routine)		   \
asm(".text								\n"\
"	.align 2							\n"\
"	.global "#label"						\n"\
#label":								\n"\
"	lea.l   -16(%sp), %sp		\n"                                \
"	movem.l %d0-%d1/%a0-%a1, (%sp)	\n" /* ������å��쥸��������¸ */ \
				/*  ����߶ػߤ�SR�����ν���  		*/ \
"	move.w	%sr,%d1							\n"\
	/*  ����߶ػ�  						*/ \
	/*     ����ߤ�ػߤ��������̤γ���ߤ����ä������������ 	*/ \
	/*     cpu_suppourt.S��ret_int�򻲾� 				*/ \
"	move.l	#("str_MAX_IPM" << 8),%d0	                        \n"\
"	ori.l	#0x00002000,%d0	                                        \n"\
"	move.w	%d0,%sr	                                                \n"\
"	move.l	#"#handler", %a0				                \n"\
"	jbra	_kernel_"#common_routine"        \n" /* C����롼�������Ƭ���ɥ쥹*/\
)

/*
 *  ����ߥϥ�ɥ�����������������ޥ���
 *
 */
#define INTHDR_ENTRY(inthdr)	INTHDR_ENTRY2(INT_ENTRY(inthdr), inthdr)

#define INTHDR_ENTRY2(entry, inthdr)					\
	extern void entry(void);					\
	HANDLER_ENTRY_PROC(entry, inthdr, interrupt_entry)


/*
 *  CPU�㳰�ϥ�ɥ�����������������ޥ���
 */
#define	EXCHDR_ENTRY(exchdr)	EXCHDR_ENTRY2(EXC_ENTRY(exchdr), exchdr)

#define EXCHDR_ENTRY2(entry, exchdr)					\
	extern void entry(void);					\
	HANDLER_ENTRY_PROC(entry, exchdr, cpu_exception_entry)
	/*
	 *  void entry()��ñ�ʤ륨��ȥ�Υ�٥�ʤΤǡ�
	 *  �������դ��ʤ�
	 */

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥλ���
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	/* 
	 *  ������Ӥ���Τϡ����߼¹����CPU�㳰��ʬ
	 *  ����ߥͥ��ȥ����󥿤����󥯥���Ȥ���Ƥ��뤿�� 	
	 *  
	 *  CPU�㳰��������������̤�CPU�㳰��ȯ�����ʤ��Ȳ���
	 *  ���Ƥ���
	 */
	return(intnest > 0);
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return((*((UH *) p_excinf) & 0x0700) == 0x0700);
}

/*
 *  �ץ��å���¸�ν����
 */
extern void	cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void	cpu_terminate(void);
/*
 *  �����Υ����ϻ��Υ����å���¤�����
 */
typedef struct exc_stack {
	VW	d0;
	VW	d1;
	VW	d2;
	VW	d3;
	VW	d4;
	VW	d5;
	VW	d6;
	VW	d7;
	VW	a0;
	VW	a1;
	VW	a2;
	VW	a3;
	VW	a4;
	VW	a5;
	VW	a6;
	VW	a7;
	VW	sr;	/*  ���ơ��������쥸����  	*/
	VW	pc;	/*  �ץ���ࡦ������  	*/
} EXCSTACK;


/*
 * �㳰ȯ�����Υ����� (cpu_config.c, cpu_support.S)
 */
extern void     cpu_experr(EXCSTACK *);

#endif /* _MACRO_ONLY */


/*
 *  �㳰�٥��������ꤹ��ǥե���Ȥ���
 *  	�ʲ����㳰�װ��ǥǥե���ȤȤϰۤʤ��㳰�٥��������
 *	������ϡ�sys_config.h�ǳ�������ޥ����������롣
 */
#define RESET_VECTOR 	start		/*  �ꥻ�åȥ٥���  */
#define INIT_STACK  	STACKTOP	/*  �����å��ݥ��󥿤ν����  */

#define RESERVED_VECTOR	RESET_VECTOR	/*  �����ƥ�ͽ��Υꥻ�åȥ٥���  */
					/*  �ºݤˤϻ��Ѥ���ʤ�  */

#ifndef ACC_VECTOR	/*  �����������顼  */
#define ACC_VECTOR	RESET_VECTOR
#endif /* ACC_VECTOR */

#ifndef ADD_VECTOR	/*  �����������顼  */
#define ADD_VECTOR	RESET_VECTOR
#endif /* ACC_VECTOR */

#ifndef II_VECTOR	/*  ����̿��  */
#define II_VECTOR	RESET_VECTOR
#endif /* II_VECTOR */

#ifndef PV_VECTOR	/*  ����å�����̿��  */
#define PV_VECTOR	RESET_VECTOR
#endif /* SII_VECTOR */

#ifndef CAE_VECTOR	/*  CPU���ɥ쥹���顼  */
#define CAE_VECTOR	RESET_VECTOR
#endif /* CAE_VECTOR */

#ifndef DAE_VECTOR	/*  DMA���ɥ쥹���顼  */
#define DAE_VECTOR	RESET_VECTOR
#endif /* DAE_VECTOR */

#ifndef NMI_VECTOR	/*  NMI  */
#define NMI_VECTOR	RESET_VECTOR
#endif /* NMI_VECTOR */

#endif /* _CPU_CONFIG_H_ */
