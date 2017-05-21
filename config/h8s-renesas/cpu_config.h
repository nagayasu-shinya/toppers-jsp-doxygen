/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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
 *      �ץ��å���¸�⥸�塼���H8S�ѡ�
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
 *  �ץ��å���Ϣ�����
 */
#include <h8s.h>
#include <h8s_sil.h>


/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 *    �����ǡ�MAX_IPM�����Ѥ��Ƥ���Τǡ��������ɤ߹���
 */
#include <cpu_insn.h>

/*
 *  TCB ��Υե�����ɤΥӥå��������
 *
 *  cpu_context.h ��������������쥬��Ȥ��������Ȥΰ�¸���δط��ǡ�
 *  cpu_context.h �ˤ�������ʤ���
 */
#define TBIT_TCB_TSTAT          8       /* tstat �ե�����ɤΥӥå��� */
#define TBIT_TCB_PRIORITY       8       /* priority �ե�����ɤΥӥå��� */

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

extern volatile UB	intnest;

/*
 *  ����ƥ����Ȼ���
 *    ����ߥͥ��ȥ����󥿤��ɤ߽Ф���ľ��˳���ߤ�ȯ�����Ƥ⡢��ä��Ȥ��ˤ�
 *    ����ƥ����Ȥ⸵����äƤ���
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
 *  ��������߶ػߡʥ����ͥ�������γ���ߤΤߡ�
 *  ����������
 *  ����iscpulocked == TRUE
 *  �������ΤȤ�CPU��å����֤Ȥ��롣
 */
extern volatile BOOL     iscpulocked;

#define sense_lock()    iscpulocked

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
extern volatile IPM	task_intmask;	/* ����������ƥ����ȤǤγ���ߥޥ��� */
#endif /* SUPPORT_CHG_IPM */

Inline void
t_lock_cpu(void)
{
	disint();		/* cpu_insn.h */
        iscpulocked = TRUE;
}

Inline void
t_unlock_cpu(void)
{
        iscpulocked = FALSE;
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

extern volatile IPM	int_intmask;	/* �󥿥�������ƥ����ȤǤγ���ߥޥ��� */

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
        iscpulocked = TRUE;
}

Inline void
i_unlock_cpu(void)
{
        iscpulocked = FALSE;
	set_intmask(int_intmask);
}

/*
 *  �������ǥ����ѥå���
 */

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���cpu_support.src��
 *    dispatch �ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ������������ǡ�
 *    CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	dispatch(void);

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���cpu_support.src��
 *    exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	exit_and_dispatch(void);

/*
 *  ����ߥϥ�ɥ������
 *    H8S�Ǥϡ�����ߥ٥����ơ��֥��ROM���ľ�ܤ����֤��뤿�ᡢ
 *��������������ʤ���
 *���ʥ٥����ơ��֥��perl������ץȤ����������
 */

Inline void define_inh(INHNO inhno, FP inthdr) {
}

/*
 *  CPU�㳰�ϥ�ɥ������
 *    H8S�Ǥϡ�CPU�㳰�ε������ʤ����ᡢ����������ʤ���
 */

Inline void define_exc(EXCNO excno, FP exchdr) {
}

#endif /* _MACRO_ONLY */

/*
 *  ����ߥϥ�ɥ�ν���������
 *����H8C��H8S��¸���Ǥϳ���ߤν����������򥢥���֥饽�������
 *�����������뤿�ᡢ�����C��������������ɬ�פ��ʤ���
 *���������Ǥ϶������ȤΥ��󥿡��ե��������碌�뤿�ᡢ
 *����ɬ�פʥޥ�������Τߤ��Ƥ��롣
 */

/*
 *  C����롼����δؿ�̾�������������Υ�٥������
 *����H8C��H8��¸���Ǥ�����������vector.src��Υ����롦����ܥ��
 *�����Ǥ���Τǡ������Х�˸�������ɬ�פ��ʤ���
 *���������Ǥ϶������ȤΥ��󥿡��ե��������碌�뤿�ᡢ
 *�������ߡ��Υ�٥��Ϳ���Ƥ��롣
 */
#define INT_ENTRY(inthdr) _kernel_common_interrupt_process
#define EXC_ENTRY(exchdr) _kernel_common_interrupt_process

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *������C�����ǤϤ��ޤ������Ǥ��ʤ����ᡢ������֥饽�������
 *�����������Ѱդ��롣
 */
#define INTHDR_ENTRY(inthdr) extern void INT_ENTRY(inthdr)(void)

/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 */
#define EXCHDR_ENTRY(exchdr) extern void EXC_ENTRY(exchdr)(void)

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */
#ifndef _MACRO_ONLY

/*
 *  CPU�㳰��ȯ���������Υ���ƥ�����Ƚ��
 *    H8S�ǤǤϡ��ƤФ�뤳�Ȥ�̵���������󥿡��ե������򤽤��뤿�ᡢ
 *�����������Ƥ��롣
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
        return(TRUE);
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 *    H8S�ǤǤϡ��ƤФ�뤳�Ȥ�̵���������󥿡��ե������򤽤��뤿�ᡢ
 *�����������Ƥ��롣
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
 *  ��ipr : ���󥿥�ץȥץ饤����ƥ��쥸����( IPRA - IPRK ) ����16�ӥå�
 *  ��mask : IPR�����ѥޥ����ʾ�̤����̤������( IPR_UPR, IPR_LOW )
 *  ��level : ����ߥ�٥�( 0 - 7 )
 */
#ifndef _MACRO_ONLY

Inline void icu_set_ilv( UH ipr, BOOL mask, INT level ) {
	UB val;
	
	if( mask == IPR_UPR ) {
		val = (UB)(( h8s_reb_reg( ipr ) & ~IPR_UPR_MASK ) | TO_HI4((UB) level));
		h8s_wrb_reg( ipr, val );
	} else if( mask == IPR_LOW ) {
		val = (UB)(( h8s_reb_reg( ipr ) & ~IPR_LOW_MASK ) | TO_LO4((UB) level));
		h8s_wrb_reg( ipr, val );
	}
}

/*
 *  ̤��������ȯ�����Υ��顼���� (cpu_config.c, cpu_support.src)
 */

/*
 * �����å�����Ƭ����ƥ쥸�����ΤޤǤΥ��ե��å�
 * 
 * ��������
 * ���������ɥХ󥹥ɥ⡼��
 * ���������������⡼�ɣ�
 * 
 * �������å���¤
 *���� +0:er0
 *���� +4:er1
 *���� +8:er2
 *����+12:er3
 *����+16:er4
 *����+20:er5
 *����+24:er6
 *����+28:exr
 *����+29:�ꥶ����
 *����+30:crr
 *����+31:pc
 *����+34��:��������˻��Ѥ���Ƥ��������å��ΰ�
 */

#ifndef __2000A__
#error support Advanced mode only.(Normal mode isn't supported)
#endif

/*
 * �����ȯ��ľ���Υ����å��ݥ��󥿤ޤǤΥ��ե��å�
 * ����̤��������ȯ������
 */
#define OFFSET_SP	34

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
	UB	exr;
	UB	dummy;
	UW	pc;	/*  �ץ���ࡦ������  	*/
} EXCSTACK;


extern void	cpu_experr(EXCSTACK *sp);

#endif /* _MACRO_ONLY_ */

#endif /* _CPU_CONFIG_H_ */
