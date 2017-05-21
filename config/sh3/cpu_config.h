/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.26 2006/04/10 09:58:15 honda Exp $
 */


/*
 *  �ץ��å���¸�⥸�塼���SH3/4�ѡ�
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_


/*
 *  �����ͥ���������̾�Υ�͡���
 */
#include <cpu_rename.h>


#ifdef SH4
#include <sh4.h>        
#else  /* SH3 */
#include <sh3.h>        
#endif /* SH4 */


/*
 *  �����ǽ�ʺǹ�ͥ����
 */
#ifdef GDB_STUB
#define MAX_IPM  0xe
#else
#define MAX_IPM  0xf
#endif 


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
 *  TCB ��Ϣ�����
 *
 *  cpu_context.h ��������������쥬��Ȥ��������Ȥΰ�¸���δط��ǡ�
 *  cpu_context.h �ˤ�������ʤ���
 */

/*
 *  TCB ��Υե�����ɤΥӥå��������
 */
#define	TBIT_TCB_PRIORITY	8	/* priority �ե�����ɤΥӥå��� */
#define	TBIT_TCB_TSTAT		8	/* tstat �ե�����ɤΥӥå��� */

#ifndef _MACRO_ONLY
/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
        VP	sp;             /* �����å��ݥ��� */
        FP  pc;             /* �ץ���५���� */
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
current_intmask()
{
	return(current_sr() & 0x000000f0);
}


/*
 *  ����ߥޥ���������
 */
Inline void
set_intmask(UW intmask)
{
	set_sr((current_sr() & ~0x000000f0) | intmask);
}


/*
 *  �����ƥ���ֻ���
 */

Inline BOOL
sense_context()
{
    UW  nest;
    Asm("stc r7_bank,%0":"=r"(nest));
        
	return(nest > 0);    
}


Inline BOOL
sense_lock()
{
	return(current_intmask() == MAX_IPM << 4);
}


#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock


/*
 *  CPU��å��Ȥ��β���ʥ���������ƥ������ѡ�
 *
 *  task_intmask �ϡ�chg_ipm �򥵥ݡ��Ȥ��뤿����ѿ���chg_ipm �򥵥ݡ�
 *  �Ȥ��ʤ����ˤϡ�t_unlock_cpu ��� task_intmask �� 0 ���֤�������
 *  �褤��
 */

#ifdef SUPPORT_CHG_IPM
extern UW	task_intmask;	/* ����������ƥ����ȤǤγ���ߥޥ��� */
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

extern UW	int_intmask;	/* �󥿥�������ƥ����ȤǤγ���ߥޥ��� */

Inline void
i_lock_cpu()
{
	UW	intmask;

	/*
	 *  ����ѿ� intmask ��ȤäƤ���Τϡ�current_intmask()��Ƥ�
	 *  ��ľ��˳���ߤ�ȯ��������ư���줿����ߥϥ�ɥ����
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


/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ������
 */

/*
 *  �٥����١��������
 */
extern void   BASE_VBR(void);


/*
 *  �㳰�٥����ơ��֥�ι�¤�����
 */
typedef struct exc_vector_entry {
	FP	exchdr;			/* �㳰�ϥ�ɥ�ε�ư���� */
} EXCVE;



/*
 *  �����ߥϥ�ɥ�ε����ơ��֥�
 *  SH3�ʹߤϥ٥����ơ��֥������ʤ���������߽������㳰�װ���
 *  ���ե��åȤˤ���鵿���ơ��֥���ϥ�ɥ�μ¹����ϵڤ�
 *  �����ߥޥ������ͤ��������
 */
extern FP	int_table[];
extern VW   int_plevel_table[];


/*
 *  CPU�㳰�ϥ�ɥ�ε����ơ��֥�
 */
extern FP	exc_table[(0x1E0 >> 5) + 1];


/*
 *
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 *  �����ơ��֥����Ͽ����
 *  stub��Ȥ�����stub�ƤӽФ��ˤ��stub����Ͽ����
 *  
 */

extern FP general_exception();
extern FP interrupt();


Inline void
define_inh(INHNO inhno, FP inthdr)
{
        int_table[inhno >> 5] = inthdr;
#ifdef GDB_STUB
        Asm("mov #0x8,r0;  mov %0,r4; mov %1,r5; trapa #0x3f"
	    : /* no output */
	    : "r"(inhno),"r"(interrupt)
	    : "r0", "r4", "r5");
#endif /* GDB_STUB */
}


/*
 *   CPU�㳰�ϥ�ɥ������
 *   �����٥������ơ��֥����Ͽ
 */   
Inline void
define_exc(EXCNO excno, FP exchdr)
{
        exc_table[excno >> 5] = exchdr;
#ifdef  GDB_STUB 
        Asm("mov #0x8,r0;  mov %0,r4; mov %1,r5;  trapa #0x3f"
	    : /* no output */
	    : "r"(excno),"r"(general_exception)
	    : "r0", "r4", "r5");
#endif /* GDB_STUB */
}


/*
 *  �����ߥ�٥������
 */
Inline void
define_int_plevel(UINT dintno, UW plevel)
{
    int_plevel_table[dintno >> 5] = (plevel << 4) | 0x40000000;
}


/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ�ν���������
 *  
 */

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

/*
 *  CPU�㳰��ȯ���������Υ���ƥ�����Ƚ��
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
    UW  nest;
    Asm("stc r7_bank,%0":"=r"(nest));
        
	return(nest > 1);
}


/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return((*((UW *)p_excinf + 11) & 0x00000f0) == MAX_IPM << 4);
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
 * ̤��Ͽ�γ����/�㳰ȯ�����Υ�����
 */
extern void     cpu_expevt(VW,VW,VW,VW);
extern void     cpu_interrupt(VW,VW,VW,VW);
extern void     no_reg_interrupt(void);


/*
 *  ���ꥢ�륳��ȥ���Υܡ��졼����������Ԥ����֤�����
 *  �Х����ơ��ȥ���ȥ���Υ�ե�å��奫���󥿤�Ȥ�
 */
#define WAIT_RFCR_FOR_SCI    200

/*
 *  gdb stub�ˤ�����
 */
Inline int
stub_putc(int c)
{
  Asm("mov #0x00,r0; mov %0,r4; trapa #0x3f"
               : /* no output */
               : "r"(c)
               : "r0","r4");
  return(c);
}


#endif /* _MACRO_ONLY_ */
#endif /* _CPU_CONFIG_H_ */
