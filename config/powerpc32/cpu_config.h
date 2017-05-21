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
 *  @(#) $Id: cpu_config.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���PowerPC�ѡ�
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
 *  PowerPC�ץ��å��������쥸���������
 */
#include <powerpc.h>


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

/*
 *  �����å���ɬ�פʥޡ�����
 *  
 *  PowerPC EABI�ǵ��ꤵ��Ƥ��륳����󥰡�����٥󥷥��Ǥϴؿ��Ƥ�
 *  �Ф����Υե졼�ॹ���å��ݥ��󥿤��ؤ��Ƥ���8�Х�����(sp+4)��
 *  (sp+7)���Ϥ˸ƤФ줿¦�ξ������򤵤�롣���Τ��ᡢ������֥�롼
 *  ���󤫤�C����롼�����ƤӽФ��ս���ä˳���ߥ���ȥ����¸
 *  ���ˤǤ���դ�ɬ�פǤ��롣
 *  ����Ū�ˤϰʲ��βս꤬�������롣
 *   ��(1) �������ȥ��åץ롼����
 *   ��(2) ��������ư
 *   ��  (2-1) �������㳰�����롼����ư
 *   ��(3) ����ߥϥ�ɥ鵯ư
 *   ��(4) CPU�㳰�롼����ư
 *  
 *  �������������������������������å������Ӥ�����
 *  ������������������������������������
 *  �� �ؿ��ƤӽФ�����sp��  ---------------------- 
 *  �� ����������           |                      |
 *  ������������         +4  ----------------------��
 *  ������������            |                      |��C����롼����θƤӽФ�
 *  ������������         +8  ----------------------   �ˤ��񤭹��ޤ��
 *  ��
 *  ������
 *  ����64�ӥåȲ��κݤˤ���դ�ɬ�פǤ��롣
 *  ��
 */
#define STACK_MARGIN	8


#ifndef _MACRO_ONLY
/*
 *  ����������ƥ����ȥ֥�å������
 *����sp��4�Х��ȶ����Ǥ��뤳�Ȥ��������뤿�ᡢ
 *����UW*����������Ƥ��롣
 */

typedef struct task_context_block {
        UW	*sp;            /* �����å��ݥ��� */
        FP	pc;             /* �ץ���५���� */
} CTXB;

/*
 *  �����ƥ���ֻ���
 */

/*
 *  ����ƥ����Ȼ���
 *  
 *    �����
 *    ��TRUE ���󥿥�������ƥ�����
 *    ��FALSE������������ƥ�����
 *
 *��SPRG0�����ߥͥ��ȥ����󥿤��Ѥ��Ƥ���
 *  ����ߥͥ��ȥ����󥿤��ɤ߽Ф���ľ��˳���ߤ�ȯ�����Ƥ⡢
 *  ��ä��Ȥ��ˤϥ���ƥ����Ȥ⸵����äƤ���
 *
 */
Inline BOOL
sense_context()
{
    UW intnest;
    
    intnest = current_sprg0();    	/*  intnest �� SPRG0  */
    return(intnest > 0);
}

/*
 *  CPU��å����ֻ���
 *  
 *    �����
 *    ��TRUE ��CPU��å�����
 *    ��FALSE��CPU��å��������
 *
 *  MSR���ɤ߽Ф���ľ��˳���ߤ�ȯ�����Ƥ⡢��ä��Ȥ��ˤ�
 *  MSR�⸵����äƤ���
 *
 */
Inline BOOL
sense_lock()
{
    return(!(current_msr() & MSR_EE));
}

#define t_sense_lock    sense_lock
#define i_sense_lock    sense_lock



/*
 *  CPU��å��Ȥ��β��
 *
 *  ��MSR��EE�ӥåȤ�CPU��å���¸����Ƥ��롣
 *  ������ߥޥ����ϳ���ߥ���ȥ���ˤ��롣
 *  ����������ػߤȳ���ߥޥ�������Ω���Ƥ��뤿�ᡢ
 *  ��ñ��˼����Ǥ��롣
 */

/*  ����������ƥ�������  */
#define t_lock_cpu      disint      /*  cpu_insn.h  */
#define t_unlock_cpu    enaint      /*  cpu_insn.h  */

/*  �󥿥�������ƥ�������  */
#define i_lock_cpu      disint      /*  cpu_insn.h  */
#define i_unlock_cpu    enaint      /*  cpu_insn.h  */


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
 *  ����ߥϥ�ɥ�ε����ơ��֥�
 */
extern FP int_table[];

/*
 *  �㳰�٥����ε����ơ��֥�
 */
extern FP exc_table[];


Inline void
define_inh(INHNO intno, FP inthdr)
{
    int_table[intno] = inthdr;

#ifdef GDB_STUB     /*  ��α  */

#endif
}

/*
 *   CPU�㳰�ϥ�ɥ������
 */

Inline void
define_exc(EXCNO excno, FP exchdr)
{
    exc_table[excno] = exchdr;

#ifdef GDB_STUB     /*  ��α  */

#endif
}


/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 */

#define INTHDR_ENTRY(inthdr)  extern void inthdr(void)

#define INT_ENTRY(inthdr) inthdr

/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 *
 */
#define EXCHDR_ENTRY(exchdr)  extern void exchdr(VP sp)

#define EXC_ENTRY(exchdr)     exchdr

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */

/*
 *  CPU�㳰��ȯ���������Υ���ƥ�����Ƚ��
 *  
 *    �����
 *    ��TRUE ��CPU�㳰ȯ�������󥿥�������ƥ�����
 *    ��FALSE��CPU�㳰ȯ�����˥���������ƥ�����
 *
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
    UW  intnest;
    
    intnest = current_sprg0();    	/*  intnest �� SPRG0  */

    /*
     * ������Ӥ���Τϡ����߼¹����CPU�㳰��ʬ
     * ����ߥͥ��ȥ����󥿤����󥯥���Ȥ���Ƥ��뤿��
     */
    return(intnest > 1);
}


/*
 * �㳰�ϥ�ɥ�ΰ���p_excinf���ؤ��������Ϥ���
 * ������������������������SSR1�쥸�����ޤǤΥ��ե��å�
 * 
 * ����MSR�Υ��ԡ�SSR1�쥸�����ϡ������å���(OFFSET_SSR1+1)���ܤ�
 * �����Ѥޤ�Ƥ��롣
 * ����support.S��SAVE_GPR0_12_SPRG�򻲾� 
 */
#define OFFSET_SSR1	12

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 *  
 *    �����
 *    ��TRUE ��CPU�㳰ȯ������CPU��å�����
 *    ��FALSE��CPU�㳰ȯ������CPU��å��������
 *  
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
    UW  ssr1;

    ssr1 = *((volatile UW *)p_excinf + OFFSET_SSR1);
    return( !(ssr1 & MSR_EE) );
}

/*
 *  �ץ��å���¸�ν����
 */
extern void cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void cpu_terminate(void);

/*
 *  �����Υ����ϻ��Υ����å���¤�����
 */
typedef struct exc_stack {
	UW	r0;
	UW	r3;
	UW	r4;
	UW	r5;
	UW	r6;
	UW	r7;
	UW	r8;
	UW	r9;
	UW	r10;
	UW	r11;
	UW	r12;
	UW	srr0;	/*   ���������쥸����0��*/
	UW	srr1;	/*   ���������쥸����1��*/
	UW	lr;	/*   ��󥯡��쥸���� 	*/
	UW	ctr;	/*   ������ȡ��쥸����	*/
	UW	cr;	/*   ����ǥ�����󡦥쥸���� 	*/
	UW	xer;	/*   �������ڥ졼�����ξ�Ｑ�̥쥸������*/
			/*  ���ʥ���꡼�䥪���Хե��ʤɡ�  */
	UW	exc_no;	/*   �㳰�ֹ� 	*/
} EXCSTACK;

/*  �����å���Υǡ�����ɽ��  */
void syslog_data_on_stack(EXCSTACK *sp);

/*
 * ��Ͽ����Ƥ��ʤ��㳰ȯ�����Υ����� (cpu_config.c)
 */
extern void no_reg_exception(EXCSTACK *);



#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */

/*  end of file  */
