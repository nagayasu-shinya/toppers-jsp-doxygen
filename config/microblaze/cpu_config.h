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
 *  @(#) $Id: cpu_config.h,v 1.9 2005/07/06 01:48:21 honda Exp $
 */


/*
 *  �ץ��å���¸�⥸�塼���MicroBlaze�ѡ�
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
#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif /* _MACRO_ONLY */


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


/*
 *  ����å���ξ���
 */
#if defined(D_CACHE_ENABLE) && defined(I_CACHE_ENABLE)
#define MSR_CACHE_SETTING  MSR_DCE|MSR_ICE
#elif defined(D_CACHE_ENABLE)
#define MSR_CACHE_SETTING  MSR_DCE
#elif defined(I_CACHE_ENABLE)
#define MSR_CACHE_SETTING  MSR_ICE
#else
#define MSR_CACHE_SETTING  0x00
#endif        


#ifndef _MACRO_ONLY
/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
        VP	sp;             /* �����å��ݥ��� */
        FP  pc;             /* �ץ���५���� */
} CTXB;


/*
 * �����ߤΥͥ��Ȳ���Υ������
 */
extern UW interrupt_count;

/*
 *  �����ƥ���ֻ���
 */

Inline BOOL
sense_context()
{
  return(interrupt_count > 0);    
}

Inline BOOL
sense_lock()
{
  return((current_msr() & MSR_IE) == 0);
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock



/*
 *  CPU��å��Ȥ��β��
 *
 */
#define t_lock_cpu      lock_cpu
#define i_lock_cpu      lock_cpu
#define t_unlock_cpu    unlock_cpu
#define i_unlock_cpu    unlock_cpu

Inline void
lock_cpu()
{
	disint();
}

Inline void
unlock_cpu()
{
	enaint();
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
 *  MicroBlaze���㳰�٥�����¸�ߤ��뤬���㳰��ȯ��������ݤϤʤ�����
 *  �㳰��Ϣ�϶��δؿ����Ѱդ��Ƥ���
 */


/*
 *  �����ߥϥ�ɥ�/�ӥåȥޥ����Υơ��֥�
 *  int_handler_table[] �ϳ���ߥϥ�ɥ����Ͽ����ơ��֥�
 *  int_bit_table[]���ϳ���ߤ�ͥ���̤˱������ӥåȤΥơ��֥�Ǥ��ꡤ
 *  MicroBlaze�Υ��ե�̿��ϡ�1̿���1�ӥåȤ������եȤǤ��ʤ����ᡤ
 *  ����ߤ�ȯ�����Ƥ��餳�Υӥåȥѥ��������������Ȼ��֤������뤿��
 *  
 */
extern FP	int_handler_table[32];
extern UW   int_bit_table[32];

/*
 *  CPU�㳰�ϥ�ɥ�ε����ơ��֥�
 */
/*
extern FP	exc_table[];
*/

extern FP exception_entry();
extern FP interrupt_entry();


/*
 *
 *  ����ߥϥ�ɥ������
 *
 *  �����ͥ���� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 *  �����ơ��֥����Ͽ����
 *  
 */

Inline void
define_inh(INHNO inhno, FP inthdr)
{
  int_handler_table[inhno-1] = inthdr;
}

/*
 *   CPU�㳰�ϥ�ɥ������
 *   �����٥������ơ��֥����Ͽ
 *   Not Support! 
 */   
Inline void
define_exc(EXCNO excno, FP exchdr)
{

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
 *  Not Support! 
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
  	return(interrupt_count > 1); 
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 *  Not Support!
 *  Not Yet!   
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return(FALSE);
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
extern void     no_reg_interrupt(void);
/* extern void     cpu_expevt(VW,VW,VW,VW); */
extern void     cpu_interrupt(void);

#endif /* _MACRO_ONLY_ */

/*
 *  vxget_tim �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define	SUPPORT_VXGET_TIM

/*                                                                             
 *  ���ꥢ��ݡ����ֹ�˴ؤ������      
 */
#define TNUM_PORT   1   /* ���ݡ��Ȥ��륷�ꥢ��ݡ��Ȥο� */
#define TNUM_SIOP   1   /* ���ݡ��Ȥ��륷�ꥢ��I/O�ݡ��Ȥο� */

/*
 *  �����ƥॿ�����˴ؤ������
 */
#define	LOGTASK_PORTID	1	/* �����ƥ������Ϥ��륷�ꥢ��ݡ����ֹ� */


#endif /* _CPU_CONFIG_H_ */
