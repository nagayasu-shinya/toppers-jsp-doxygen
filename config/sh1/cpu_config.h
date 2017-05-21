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
 *  @(#) $Id: cpu_config.h,v 1.18 2005/11/14 08:00:44 honda Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���SH1�ѡ�
 *���������������ͥ������ǻ��Ѥ������
 *�������������ǡ��������ޥ����ؿ��Υץ�ȥ��������
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
 *  SH1�ץ��å��������쥸���������
 */
#include <sh1.h>

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
#define MAX_IPM  0xe	/* �����֤���ξ���ͥ����14��CPU��å�   */
#else
#define MAX_IPM  0xf	/* �����֤ʤ��ξ��Ϻǹ�ͥ���٤�CPU��å� */
#endif /*  GDB_STUB  */

#define str_MAX_IPM  		TO_STRING(MAX_IPM)

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif /* _MACRO_ONLY */

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
 *  
 *  ��sp��UW *���Ȥ��Ƥ���Τ�4�Х��ȶ�����ռ����Ƥ��뤿��
 *  
 */
typedef struct task_context_block {
        UW 	*sp;            /* �����å��ݥ��� */
        FP	pc;             /* �ץ���५���� */
} CTXB;

/*
 *  ����ߥޥ������饤�֥��
 *
 *  ����ߥޥ�����intmask�ˤϡ�IPM��Interrupt Priority Mask�ˤ�4�ӥå�
 *  ���˥��եȤ�����ΤǤ��롥
 */

/*
 *  ���ߤγ���ߥޥ������ɽФ�
 */
Inline UW
current_intmask(void)
{
	return(current_sr() & 0x000000f0u);
}

/*
 *  ����ߥޥ���������
 */
Inline void
set_intmask(UW intmask)
{
	set_sr((current_sr() & ~0x000000f0u) | intmask);
}


/*
 *  ����ߡ�CPU�㳰�ͥ��ȥ�����
 */
extern UW	intnest;

/*
 *  �����ƥ���ֻ���
 */


/*
 *  ����ƥ����Ȼ���
 *
 *  ����ߥͥ��ȥ����󥿤��ɤ߽Ф���ľ��˳���ߤ�ȯ�����Ƥ⡢
 *  ��ä��Ȥ��ˤϥ���ƥ����Ȥ⸵����äƤ���
 */
Inline BOOL
sense_context(void)
{
	return(intnest > 0);
}

Inline BOOL
sense_lock(void)
{
	return(current_intmask() == (MAX_IPM << 4));
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
extern UW	task_intmask;	/* ����������ƥ����ȤǤγ���ߥޥ��� */
#endif /* SUPPORT_CHG_IPM */

Inline void
t_lock_cpu(viod)
{
	disint();		/*  cpu_insn.h  */
}

Inline void
t_unlock_cpu(void)
{
#ifdef SUPPORT_CHG_IPM
	/*
	 *  t_unlock_cpu ���ƤӽФ����Τ� CPU��å����֤ΤߤǤ��뤿
	 *  �ᡤ����������� task_intmask ���񤭴���뤳�ȤϤʤ���
	 */
	set_intmask(task_intmask);
#else /* SUPPORT_CHG_IPM */
	enaint();		/*  cpu_insn.h  */
#endif /* SUPPORT_CHG_IPM */
}

/*
 *  CPU��å��Ȥ��β�����󥿥�������ƥ������ѡ�
 */

extern UW	int_intmask;	/* �󥿥�������ƥ����ȤǤγ���ߥޥ��� */

Inline void
i_lock_cpu(void)
{
	UW	intmask;

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
i_unlock_cpu(void)
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

#endif /* _MACRO_ONLY */

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


/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{
#ifdef GDB_STUB
	/*  �����ָƤӽФ�  */
	Asm("mov   #0x08,r0;	\
	     mov   %0,r4;	\
	     mov   %1,r5;	\
	     trapa #0x21"
               : /* no output */
               : "r"(inhno),"r"(inthdr)
               : "r0","r4","r5");

#else	/*  GDB_STUB  */

#ifdef KERNEL_HAS_A_VECTOR_TABLE

#ifdef SIO_RESERVED	/*  ���ꥢ������ߤ��򤱤�  */
	if ((inhno != RXI0) && (inhno != TXI0))
#endif /* SIO_RESERVED */
		vector_table[inhno] = inthdr;

#endif /* KERNEL_HAS_A_VECTOR_TABLE */

#endif	/*  GDB_STUB  */
}

/*
 *  CPU�㳰�ϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� excno ��CPU�㳰�ϥ�ɥ�ε�ư���Ϥ� exchdr �����ꤹ�롥
 */
extern void define_exc(EXCNO excno, FP exchdr)  throw();


/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ����������
 */

/*  C����롼����δؿ�̾�������������Υ�٥������  
 *     kernel_cfg.c�ǻ���
 */
#define	INT_ENTRY(inthdr)	_kernel_##inthdr##_entry
#define	EXC_ENTRY(exchdr)	_kernel_##exchdr##_entry

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ�����������ζ�����ʬ
 *
 *	SH1�Ǥϡ�����ߤ�CPU�㳰�ΰ������ۤȤ��Ʊ���ʤΤǡ�
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
 *��������r1������߼���ľ���SR�Υ��ԡ�
 *��������r0��interrupt_entry
 *��������r2��C����롼�������Ƭ���ɥ쥹
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
asm(".text;								  "\
"	.align 2;							  "\
"	.global _"#label";						  "\
"_"#label":;								  "\
			/*  ɬ�׺Ǿ��¤Υ쥸�����򥹥��å�������  */	   \
"	mov.l	r0,@-r15;						  "\
"	mov.l	r1,@-r15;						  "\
				/*  ����߶ػߤ�SR�����ν���  		*/ \
"	stc	sr,r1;							  "\
	/*  ����߶ػ�  						*/ \
	/*     ����ߤ�ػߤ��������̤γ���ߤ����ä������������ 	*/ \
	/*     cpu_suppourt.S��ret_int�򻲾� 				*/ \
"	mov.l	_mask_ipm_"#handler",r0;				  "\
"	ldc	r0,sr;							  "\
"	mov.l	r2,@-r15;						  "\
"	mov.l	_common_routine_"#handler",r0;				  "\
"	mov.l	_c_routine_"#handler",r2;" /* C����롼�������Ƭ���ɥ쥹*/\
"	jmp	@r0;		"/*  interrupt_entry�إ����� 		*/ \
"	nop;				"	/*  �ٱ䥹��å�  	*/ \
	/* ���� 							*/ \
	/* ���ٱ䥹��åȤ�PC���Х��ɥ�å��󥰤Υ���̿��� 		*/ \
	/* �������ȸ�ư��롣 					*/ \
	/*  ���ʥ���å�����̿���㳰��ȯ�����ʤ��Τ�ȯ�����񤷤����� 	*/ \
									   \
"	.align 2;							  "\
"_mask_ipm_"#handler":;	    "	/*  ����߶ػ��ѥޥ���  		*/ \
"	.long  "str_MAX_IPM" << 4; "	/*  ipm�ʳ��ΥӥåȤϥ�����ɤ�	*/ \
"_c_routine_"#handler":;	    					  "\
"	.long  _"#handler";   "	/* C����롼�������Ƭ���ɥ쥹  	*/ \
"_common_routine_"#handler":; "	/* cpu_support.S���ʬ���襢�ɥ쥹	*/ \
"	.long  __kernel_"#common_routine"; "		  		   \
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
	return(intnest > 1);
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	UW sr = *(UW *)p_excinf; 
	return((sr& 0x00000f0u) == (MAX_IPM << 4));
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
	VW	r0;
	VW	r1;
	VW	r2;
	VW	r3;
	VW	r4;
	VW	r5;
	VW	r6;
	VW	r7;
	VW	r8;
	VW	r9;
	VW	r10;
	VW	r11;
	VW	r12;
	VW	r13;
	VW	r14;
	VW	r15;
	VW	pr;	/*  �ץ������㡦�쥸����  	*/
	VW	pc;	/*  �ץ���ࡦ������  	*/
	VW	sr;	/*  ���ơ��������쥸����  	*/
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

#ifndef GII_VECTOR	/*  ��������̿��  */
#define GII_VECTOR	RESET_VECTOR
#endif /* GII_VECTOR */

#ifndef SII_VECTOR	/*  ����å�����̿��  */
#define SII_VECTOR	RESET_VECTOR
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
