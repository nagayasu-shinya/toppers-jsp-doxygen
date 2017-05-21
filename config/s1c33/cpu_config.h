/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */

/*
 *  �ץ��å���¸�⥸�塼��(S1C33��)
 */


#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include "cpu_rename.h"


/*
 *  �����ǽ�ʺǹ������ͥ����
 */
#define	TPS_INTLEV_MAX	(0x04)
#define	TPS_CPULOCK_LEV	(TPS_INTLEV_MAX + 1)

/*
 *  TCB ��Υե�����ɤΥӥå��������
 */
#define	TBIT_TCB_PRIORITY	8	/* priority �ե�����ɤΥӥå��� */
#define	TBIT_TCB_TSTAT		8	/* tstat �ե�����ɤΥӥå���	 */


#ifndef _MACRO_ONLY
/*
 *  TCB ��Ϣ�����
 *  cpu_context.h ��������������쥬��Ȥ��������Ȥΰ�¸���δط��ǡ�
 *  cpu_context.h �ˤ�������ʤ���
 */
/*
 *  ����������ƥ����ȥ֥�å������
 *  Task context block.
 */
typedef struct task_context_block {
	VP sp;				/* �����å��ݥ���	*/
	FP pc;				/* �ץ���५����	*/
} CTXB;


/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå�(cpu_config.c)
 *
 *  dispatch �ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ����������
 *  ��ǡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void dispatch(void);

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå�(cpu_config.c)
 *
 *  exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void exit_and_dispatch(void);

/*
 *  �ץ��å���¸�ν����
 */
extern void	cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void	cpu_terminate(void);

/*
 *  CPU��å��������������������ߥ�٥�
 */
extern UINT	tps_OrgIntLevel;

/*
 *  ����ߥͥ��ȥ�����
 */
extern UINT	tps_IntNestCnt;

/*
 *  �ӥåȥ������ޥ�����Ѥ�����
 */
#ifndef __c33pe
#define CPU_BITMAP_SEARCH
#endif  /* __c33pe */

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#include "cpu_insn.h"

/*
 * �����ƥ���ֻ��ȴؿ�����̾���
 */
#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock
#define	t_lock_cpu	lock_cpu
#define	i_lock_cpu	lock_cpu
#define	t_unlock_cpu	unlock_cpu
#define	i_unlock_cpu	unlock_cpu

/*
 *  ���ߤΥ���ƥ����Ⱦ��֤򻲾�
 */
Inline BOOL
sense_context()
{
	return ((tps_IntNestCnt) ? TRUE : FALSE);
}

/*
 *  ���ߤ�CPU��å����֤򻲾�
 */
Inline BOOL
sense_lock()
{
	UW	ulIntLevel;

	ulIntLevel = get_psr();

	ulIntLevel = (ulIntLevel & S1C33_PSR_MASK_IL);
	return ((ulIntLevel < (TPS_CPULOCK_LEV << 8)) ? FALSE : TRUE);
}

/*
 * CPU��å������������
 */
Inline void
lock_cpu()
{
	UW	ulPsr, ulIntLevel;

	ulPsr = get_psr();
	ulIntLevel = (ulPsr & S1C33_PSR_MASK_IL);

	if(ulIntLevel < (TPS_CPULOCK_LEV << 8)){
		ulPsr &= ~S1C33_PSR_MASK_IL;
		set_psr(ulPsr | (TPS_CPULOCK_LEV << 8));
		tps_OrgIntLevel = ulIntLevel;
	}
}

Inline void
unlock_cpu()
{
	UW	ulPsr;

	ulPsr = get_psr();
	ulPsr &= ~S1C33_PSR_MASK_IL;
	ulPsr |= tps_OrgIntLevel;
	tps_OrgIntLevel = (TPS_INIT_INTLEVEL << 8);

	set_psr(ulPsr);
}

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */
/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥλ���
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return ((tps_IntNestCnt > 1) ? TRUE : FALSE);
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	UW	ulPsr;

	ulPsr = ((*((UW *)p_excinf) & S1C33_PSR_MASK_IL) >> 8);
	return (ulPsr == TPS_CPULOCK_LEV) ? TRUE : FALSE;
}

/*
 *  �㳰�٥����ơ��֥�ι�¤�����
 */
typedef struct exc_vector_entry {
	FP exchdr;				/* �㳰�ϥ�ɥ�ε�ư���� */
} EXCVE;

/*
 *  CPU�㳰�ϥ�ɥ������
 */
#define	define_exc	define_inh

/*
 *  ����ߥϥ�ɥ������
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{
	EXCVE	*excvt;

	excvt = (EXCVE *) get_ttbr();
	excvt[inhno].exchdr = inthdr;
}

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 */
#define INTHDR_ENTRY(inthdr)	void inthdr##_entry(void) { tpsIntPreWrap(); asm("xcall " #inthdr); tpsIntPostWrap(); }
#define	INT_ENTRY(inthdr)	inthdr##_entry

/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 */
#define EXCHDR_ENTRY(exchdr)	INTHDR_ENTRY(exchdr)
#define	EXC_ENTRY(exchdr)	exchdr##_entry

/*
 *  �����/CPU�㳰�ϥ�ɥ�ν���������
 *
 *  idle��ϳ����ޤ줿�����å�==stacktop�ʤΤǡ�
 *  idle�롼����ˤ�reti�������Ǥ�����֤˳����ߥ����å������ꤷ�Ƥ���
 */
Inline void
tpsIntPreWrap(void)
{
#if TPS_DAREA_CNT == 4			/* �ǡ������ꥢ���˱���������	*/
	Asm("pushn %r11");		/* �쥸���������ѹ����롣	*/
#elif TPS_DAREA_CNT == 3
	Asm("pushn %r12");
#elif TPS_DAREA_CNT == 2
	Asm("pushn %r13");
#elif TPS_DAREA_CNT == 1
	Asm("pushn %r14");
#else
	Asm("pushn %r15");
#endif /* TPS_DAREA */

#ifdef	__c33adv
	Asm("pushs 	%sor				");
#else	/* __c33adv */
	Asm("ld.w	%r0, %ahr			");
	Asm("ld.w	%r1, %alr			");
#endif	/* __c33adv */

	Asm("ld.w	%r2, %sp			");	/* �����å����ڤ��ؤ���		*/
	Asm("xld.w	%r3, _kernel_tps_IntNestCnt	");	/* �����ߥ����󥿤ι�����	*/
	Asm("ld.w	%r5, [%r3]			");	/* ¿�ų����ߤε��Ĥ�Ԥ�	*/
	Asm("xld.w	%%r4, %0 - 8  " : : "g"(STACKTOP));
	Asm("cmp	%r5, 0x00			");
	Asm("jrne	0f				");
	Asm("ld.w	%sp, %r4			");
	Asm("0:						");
	Asm("add	%r5, 1				");
	Asm("ld.w	[%r3], %r5			");
	Asm("ld.w	%r4, %psr			");
	Asm("or		%r4, 0x10			");
	Asm("ld.w	%psr, %r4			");
	Asm("ld.w	%r6, %r2			");

#ifdef	__c33adv						/* pushs̿��ˤ�륹���å�����	*/
	Asm("add	%r6, 24");				/* ��������û�����		*/
#endif	/* __c33adv */
	
#if TPS_DAREA_CNT == 4
	Asm("add	%r6, 48");
#elif TPS_DAREA_CNT == 3
	Asm("add	%r6, 52");
#elif TPS_DAREA_CNT == 2
	Asm("add	%r6, 56");
#elif TPS_DAREA_CNT == 1
	Asm("add	%r6, 60");
#else
	Asm("ext	0x0001");
	Asm("add	%r6, 0x00");
#endif /* TPS_DAREA */
}

Inline void
tpsIntPostWrap(void)
{
	Asm("ld.w	%r4, %psr		");	/* �����ߤ�ǥ������֥뤹��	*/
	Asm("xand	%r4, 0xfffff0ff		");
	Asm("xld.w	%%r5, %0"
		: : "g"(TPS_CPULOCK_LEV << 8));
	Asm("or		%r4, %r5		");
	Asm("ld.w	%psr, %r4		");

	Asm("ld.w	%r4, [%r3]		");	/* tps_IntNestCnt�򹹿�����	*/
	Asm("sub	%r4, 1			");
	Asm("ld.w	[%r3], %r4		");

	Asm("ld.w	%sp, %r2		");	/* �����å��ΰ����������	*/

	Asm("cmp	%r4, 0x00		");
	Asm("xjrne	0f			");
	Asm("xld.w	%r3, _kernel_reqflg	");
	Asm("ld.w	%r3, [%r3]		");
	Asm("cmp	%r3, 1			");	/* tps_IntNestCnt== 0�ǥǥ���	  */
	Asm("xjreq	_kernel_ret_int		");	/* �ѥå���ȯ�����Ƥ���Х����� */
	Asm("0:					");	/* ����				  */

#ifdef	__c33adv					/* ���򤷤��ü�쥸�������������� */
	Asm("pops	%sor			");
#else	/* __c33adv */
	Asm("ld.w	%alr, %r1		");
	Asm("ld.w	%ahr, %r0		");
#endif	/* __c33adv */

#if TPS_DAREA_CNT == 4
	Asm("popn %r11");
#elif TPS_DAREA_CNT == 3
	Asm("popn %r12");
#elif TPS_DAREA_CNT == 2
	Asm("popn %r13");
#elif TPS_DAREA_CNT == 1
	Asm("popn %r14");
#else
	Asm("popn %r15");
#endif /* TPS_DAREA */

	Asm("reti");
}

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
