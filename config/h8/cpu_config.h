/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2010 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.18 2007/03/23 07:22:15 honda Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���H8�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

#include <h8.h>

/*
 *  �����ͥ����������̾�Υ�͡���
 */

#include <cpu_rename.h>

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */

#ifndef _MACRO_ONLY
#include <cpu_insn.h>

/*
 *  ����������ƥ����ȥ֥�å������
 */

typedef struct task_context_block {
	VP	sp;		/* �����å��ݥ��� */
	FP	pc;		/* �ץ���५���� */
} CTXB;

/*
 *  ����ߥޥ������饤�֥��
 */

/*
 *  ���ߤγ���ߥޥ������ɽФ�
 */

Inline UB
current_intmask(void)
{
	return(current_ccr() & H8INT_MASK_ALL);
}

/*
 *  ����ߥޥ���������
 */

Inline void
set_intmask(UB intmask)
{
	set_ccr((current_ccr() & ~H8INT_MASK_ALL) | intmask);
}

/*
 *  ����ߥͥ��ȥ�����
 */

extern volatile UB intnest;

/*
 *  ����ƥ����Ȼ���
 *
 *  ����ߥͥ��ȥ����󥿤��ɤ߽Ф���ľ��˳���ߤ�ȯ�����Ƥ⡢��ä���
 *  ���ˤϥ���ƥ����Ȥ⸵����äƤ���
 */

Inline BOOL
sense_context(void)
{
	BOOL ret;
	
	ret = (intnest != 0) ? TRUE : FALSE;
	return(ret);
}

/*
 *  CPU��å����֤λ���
 */

/*
 *  CPU��å����֤�ɽ���ե饰
 */
extern volatile BOOL    iscpulocked;

#define sense_lock()    iscpulocked
#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU��å��Ȥ��β���ʥ���������ƥ������ѡ�
 *
 *  task_intmask �ϡ�chg_ipm �򥵥ݡ��Ȥ��뤿����ѿ���chg_ipm �򥵥ݡ���
 *  ���ʤ����ˤϡ�t_unlock_cpu ��� task_intmask �� 0 ���֤������Ƥ褤��
 */

#ifdef SUPPORT_CHG_IPM
extern volatile UB       task_intmask;   /* ����������ƥ����ȤǤγ���ߥޥ��� */
#endif /* SUPPORT_CHG_IPM */

Inline void
t_lock_cpu(void)
{
        disint();
    	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
    	Asm("":::"memory");
        iscpulocked = TRUE;
}

Inline void
t_unlock_cpu(void)
{
        iscpulocked = FALSE;
    	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
    	Asm("":::"memory");
#ifdef SUPPORT_CHG_IPM
        /*
         *  t_unlock_cpu ���ƤӽФ����Τ� CPU��å����֤ΤߤǤ��뤿�ᡢ
         *  ����������� task_intmask ���񤭴���뤳�ȤϤʤ���
         */
        set_intmask(task_intmask);
#else /* SUPPORT_CHG_IPM */
        enaint();               /* cpu_insn.h */
#endif /* SUPPORT_CHG_IPM */
}

/*
 *  CPU��å��Ȥ��β�����󥿥�������ƥ������ѡ�
 */

extern volatile UB int_intmask;    /* �󥿥�������ƥ����ȤǤγ���ߥޥ��� */

Inline void
i_lock_cpu(void)
{
        UB      intmask = current_intmask();
        /*
         *  ����ѿ� intmask ��ȤäƤ���Τϡ�current_intmask()��Ƥ�
         *  ��ľ��˳���ߤ�ȯ��������ư���줿����ߥϥ�ɥ����
         *  int_intmask ���ѹ�������ǽ�������뤿��Ǥ��롥
         */

        disint();
    	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
    	Asm("":::"memory");
        int_intmask = intmask;
        iscpulocked = TRUE;
}

Inline void
i_unlock_cpu(void)
{
        iscpulocked = FALSE;
    	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
    	Asm("":::"memory");
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

/*
 *
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 *
 */

#define JMP_OPECODE		0x5a000000u

Inline void
define_inh(INHNO inhno, FP inthdr)
{
#ifdef REDBOOT
   UW *addr = (UW *)VECTOR_TABLE_ADDR;
   addr[inhno] = JMP_OPECODE | (UW)inthdr;
#endif	/*  #ifdef REDBOOT  */
}

/*
 *   CPU�㳰�ϥ�ɥ������
 */

Inline void
define_exc(EXCNO excno, FP exchdr)
{
}

#endif	/*  _MACRO_ONLY  */

/*
 *  ����ߥϥ�ɥ�ν���������
 *
 */

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *		�ʼ������������
 */

/*  
 * C����롼����δؿ�̾�������������Υ�٥������ ����ޥ���
 */

/*  C�����ѤΥ�٥�����  */
#define	INT_ENTRY(inthdr)	_kernel_##inthdr##_entry
#define	EXC_ENTRY(exchdr)	INT_ENTRY(exchdr)

/*  ������֥��ѤΥ�٥�����  */
#define	INT_ENTRY_ASM(inthdr)	__kernel_##inthdr##_entry



/*
 *��������ߤ�������������������ޥ�������
 *�������ʳ�����װ���˰ۤʤ���ʬ��
 *
 *�������ѥ�᡼��
 *	����entry�����������Υ�٥�
 *����������inthdr��C����롼����δؿ�̾����Ƭ��'_'���դ��ʤ���
 *����������intmask��������ߵ��Ļ��˳���ߥޥ��������ꤹ����
 *����������������������IPM_LEVEL1��IPM_LEVEL2�Τ����줫�ˤ��뤳��
 *
 *������H8�Ǥϳ���߼���ľ��ϥϡ��ɥ�����Ū�˳���߶ػߤˤʤäƤ���
 *
 *���������쥸�����������
 *������������er0��er3������
 *������������er2��C����롼�������Ƭ���ɥ쥹
 *������������r3l������ߵ��Ļ��˳���ߥޥ��������ꤹ����
 *
 */
#define	INTHDR_ENTRY2(entry, inthdr, intmask)	 \
	_INTHDR_ENTRY2(entry, inthdr, intmask)

#define	_INTHDR_ENTRY2(entry, inthdr, intmask)	 \
asm(".text					\n"\
"	.align 2				\n"\
"	.global "#entry"			\n"\
#entry":					\n"\
	/*  ɬ�׺Ǿ��¤Υ쥸�����򥹥��å�������  */\
"	push.l	er0				\n"\
"	push.l	er1				\n"\
"	push.l	er2				\n"\
"	push.l	er3				\n"\
	/*  C����롼�������Ƭ���ɥ쥹  */	 \
"	mov.l   #_"#inthdr", er2		\n"\
	/*  ����ߵ��Ļ������ꤹ�����ߥޥ�������  */\
"	mov.b   #"#intmask", r3l		\n"\
"	jmp	@__kernel_common_interrupt_process"\
)

/*  _INTHDR_ENTRY()�ޥ��������ޤ�  */

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *
 */

#define INTHDR_ENTRY(inthdr)				\
	extern void INT_ENTRY(inthdr)(void) throw();	\
	INTHDR_ENTRY2(INT_ENTRY_ASM(inthdr), inthdr, inthdr##_intmask)

/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 */

#define	EXCHDR_ENTRY(exchdr)	INTHDR_ENTRY(exchdr)


#ifndef _MACRO_ONLY

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */

/*
 *  CPU�㳰��ȯ���������Υ���ƥ�����Ƚ��
 */

Inline BOOL
exc_sense_context(VP p_excinf)
{
        /* H8�ǤǤϸƤФ�ʤ��� */
        return(TRUE);
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */

Inline BOOL
exc_sense_lock(VP p_excinf)
{
        /* H8�ǤǤϸƤФ�ʤ��� */
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

/*
 *  ̤��������ȯ�����Υ��顼���ϻ��Υ����å���¤�����
 */

typedef struct exc_stack {
	UW	er0;
	UW	er1;
	UW	er2;
	UW	er3;
	UW	er4;
	UW	er5;
	UW	er6;
	UW	pc;	/*  �ץ���ࡦ������  	*/
} EXCSTACK;

/*
 * ̤��������ȯ�����Υ��顼���� (cpu_config.c, cpu_support.S)
 */

extern void     cpu_experr(EXCSTACK *sp) throw();

/*
 *  �������åȥ����ƥ��ʸ������
 *
 *  �����ƥ�����٥��ʸ�����ϥ롼����
 */

extern void cpu_putc(char c);

#endif /* _MACRO_ONLY_ */

#endif /* _CPU_CONFIG_H_ */
