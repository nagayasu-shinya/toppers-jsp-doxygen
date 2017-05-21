/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.3 2005/11/24 12:41:23 honda Exp $
 */


/*
 *  �ץ��å���¸�⥸�塼���M32C�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

#ifdef NEED_API
#include "api.h"
#endif /* NEED_API */

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
 *  TCB ��Υե�����ɤΥӥå��������
 *
 *  cpu_context.h ��������������쥬��Ȥ��������Ȥΰ�¸���δط��ǡ�
 *  cpu_context.h �ˤ�������ʤ���
 */
#define TBIT_TCB_TSTAT		8	/* tstat �ե�����ɤΥӥå��� */
#define TBIT_TCB_PRIORITY	4	/* priority �ե�����ɤΥӥå��� */

#ifndef _MACRO_ONLY

/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	VP	sp;	/*  �����å��ݥ���  */
	FP	pc;	/*  �ץ���५����  */
} CTXB;

/* 
 *  �����/CPU�㳰�ͥ��ȥ�����
 */
extern char	intnest;

/*
 *  �����ƥ���֤λ���
 */

/*
 *  ���ߤΥ���ƥ����Ȥ��֤��ؿ�.
 *  �󥿥�������ƥ����Ȥʤ�TRUE���֤�.
 */
Inline BOOL
sense_context(void)
{
	/*  �ͥ��ȥ�����0�����ʤ��󥿥�������ƥ�����  */
	return(intnest > 0);
}

/*
 *  ���ߤ�CPU��å����֤��֤��ؿ�.
 *  CPU��å����֤ʤ�TRUE���֤�.
 */
Inline BOOL
sense_lock(void)
{
	return((current_flgreg() & FLG_I_MASK) == 0);
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU��å��Ȥ��β��
 */
Inline void
lock_cpu(void)
{
	disint();
}

Inline void
unlock_cpu(void)
{
	enaint();
}

#define t_lock_cpu	lock_cpu
#define i_lock_cpu	lock_cpu
#define t_unlock_cpu	unlock_cpu
#define i_unlock_cpu	unlock_cpu

/*
 *  �������ǥ����ѥå���
 */

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���cpu_support.a30��
 *
 *  dispatch �ϡ�����������ƥ����Ȥ���ƤӽФ��줿
 *  �����ӥ�������������椫�顤CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	dispatch(void);

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå�(cpu_support.a30)
 *  exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	exit_and_dispatch(void);

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ������
 */

/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 *  ����ߥϥ�ɥ����Ͽ����٥����ơ��֥��ROM��˼��,
 *  �����˽񤭹���. ���Τ��ᤳ���Ǥϲ��⤷�ʤ���
 */

Inline void
define_inh(INHNO inhno, FP inthdr)
{
}

/*
 *  CPU�㳰�ϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� excno ��CPU�㳰�ϥ�ɥ�ε�ư���Ϥ� exchdr �����ꤹ�롥
 *  ����ߥϥ�ɥ����Ͽ����٥����ơ��֥��ROM��˼��,
 *  �����˽񤭹���. ���Τ��ᤳ���Ǥϲ��⤷�ʤ���
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
}

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ�ν�����������Ⱦ
 *
 *  ����ߡ�CPU�㳰��ȯ������CPU�ξ��֤ϼ��ΤȤ���.
 *
 *  FLG�쥸������I�ӥåȤ� 0(����߶ػ�) 
 *  FLG�쥸������IPL�ϼ����դ�������ߤ�IPL
 *  FLG�쥸������U�ӥåȤ�, ����ߤμ���ˤ�äưۤʤ뤬,
 *  �����ͥ�Ǥ�ISP�Τߤ���Ѥ�, USP����Ѥ��Ƥ��ʤ�����,
 *  �����Ǥ�����Ȥʤ�ʤ�.
 *
 *  �����/�㳰ȯ�����ˤ�, ��ưŪ�� FLG, PC�������å�����¸�����.
 *  ������������ǤϤޤ��Ĥ�Υ쥸�����򥹥��å�����¸����.
 *  ���ʤγ���ߤξ��ϥ������Υ����å���,
 *  ¿�ų����ߤξ��ϳ�����ѤΥ����å���, ���줾����¸�����.
 *
 *  ���θ�, �����å��ݥ��󥿤��ͤ� r3r1 ��, 
 *  ����ߥϥ�ɥ�Υ��ɥ쥹�� a0 �˳�Ǽ�������֤�
 *  ����߽����������θ�Ⱦ�إ����פ���.
 */

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *
 *  �����ȯ�������¹���Υ쥸�������ͤ򥹥��å������򤹤롥���θ塢��
 *  ���å��ݥ��󥿤��ͤ�R3R1�쥸�����˥��åȤ���������֥�ǵ��Ҥ��줿
 *  �ϥ�ɥ�󥰥ץ�����ʬ�����롥
 */

#define INTHDR_ENTRY(inthdr)\
extern void inthdr##_entry(void);\
asm("	.glb _" #inthdr "						");\
asm("	.glb __kernel_interrupt						");\
asm("	.section program, code, align					");\
asm("_" #inthdr "_entry:						");\
asm("	pushm	r0,r1,r2,r3,a0,a1,sb,fb	; �쥸�����򥿥��������å�������");\
asm("	stc	isp, r3r1		; �����å��ݥ��󥿤���Ф�	");\
asm("	mov.l	#_" #inthdr ", a0	; ����ߥϥ�ɥ�Υ��ɥ쥹��a0��");\
asm("	jmp	__kernel_interrupt	; ����߽����롼�����Ⱦ��	");

#define INT_ENTRY(inthdr)	inthdr##_entry

/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 */
#define EXC_ENTRY(exchdr)	INT_ENTRY(exchdr)
#define EXCHDR_ENTRY(exchdr)	INTHDR_ENTRY(exchdr)


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
	 *  �ͥ��ȥ����󥿤�1�����ʤ��󥿥�������ƥ�����
	 */
	return( intnest > 1);
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	/*
	 *  �㳰ȯ������FLG�쥸����I�ӥåȤ�0�ʤ�CPU��å�����
	 *
	 *  ���������28��CPU�㳰����������ǥ쥸�����������å��ˤɤ�
	 *  ��¸����Ƥ��뤫�˰�¸���Ʒ��ꤹ�����
	 */
	return( ( *(char *)((char *)p_excinf+28) & FLG_I_MASK ) == 0);
}

/*
 *  �ץ��å���¸�ν����(cpu_config.c)
 */
extern void	cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������(cpu_config.c)
 */
extern void	cpu_terminate(void);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
