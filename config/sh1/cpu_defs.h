/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2010 by Industrial Technology Institute,
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
 *  @(#) $Id: cpu_defs.h,v 1.14 2005/11/14 08:00:44 honda Exp $
 */

/*
 *	�ץ��å��˰�¸���������SH1�ѡ�
 *�������������ץꥱ�������ɬ�פȤ������
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�kernel.h �� sil.h �ǥ��󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��뤳�ȤϤʤ������Υե�����򥤥�
 *  ���롼�ɤ������ˡ�t_stddef.h �� itron.h �����󥯥롼�ɤ����Τǡ�
 *  �����˰�¸���Ƥ�褤��
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

/*
 *  �桼�����������
 */
#include <user_config.h>	/*  SUPPORT_VXGET_TIM�ޥ�������  */


#define SH1			/* �ץ��å�ά�� */
#define SH7032

/* �����ͥ뵯ư���Υ�å�����   */
#define COPYRIGHT_CPU \
"Copyright (C) 2001-2004 by Industrial Technology Institute,\n" \
"                            Miyagi Prefectural Government, JAPAN\n"

#ifndef _MACRO_ONLY

/*
 *  ����ߡ�CPU�㳰�ϥ�ɥ��ֹ�η�
 */
typedef	UINT	INHNO;		/* ����ߥϥ�ɥ��ֹ� */
typedef	UINT	EXCNO;		/* CPU�㳰�ϥ�ɥ��ֹ� */

/*
 *  ����ߥޥ����η��ȳ���ߥޥ������ѹ�������
 *  
 *  �����#ifdef SUPPORT_CHG_IPM��#endif�ǰϤ�٤�������
 *  ���Υե����뤬cpu_config.h�����˥��󥯥롼�ɤ���뤿��
 *  ��ά���Ƥ��롣
 *  ������ʬ���Ĥ뤳�Ȥˤ�ꡢ��������륳���ɤϤۤȤ�ɤʤ��Τ�
 *  �³��Ϥʤ���Ƚ�Ǥ�����
 */
typedef	UINT	IPM;		/* ����ߥޥ��� */

extern ER	chg_ipm(IPM ipm) throw();
extern ER	get_ipm(IPM *p_ipm) throw();

/*
 *  SIL��Ϣ�����
 */


/*
 *  ���ߤγ���ߥޥ������ɽФ�
 */
#define _current_intmask_	current_intmask

/*
 *  ����ߥޥ���������
 */
#define _set_intmask_		set_intmask

/*
 *  NMI��������٤Ƥγ���ߤ�ػ�
 *  ��disint()�������ͥ뤬�����������ߤΤߤ�ػߤ���Τ��Ф���
 *  ��_disint_()�ϥ����ͥ�������γ���ߤ�ޤ�ƶػߤ��롣
 *  ������Ū�ˤ�GDB stub�Υ��ꥢ���������ߤΰ������ۤʤ롣
 */
Inline void
_disint_(void)
{
	UW sr;

	Asm("stc  sr,%0" : "=r"(sr));
	sr |= 0x000000f0u;
	Asm("ldc %0, sr" : : "r"(sr) : "memory", "t");
}


/*
 *  ����ߥ�å����֤�����
 */
#define	SIL_PRE_LOC	UW _intmask_ = _current_intmask_()
#define	SIL_LOC_INT()	_disint_()
#define	SIL_UNL_INT()	_set_intmask_(_intmask_)


#endif /* _MACRO_ONLY */

/*
 *  �ץ��å��Υ���ǥ�����
 */
#define	SIL_ENDIAN	SIL_ENDIAN_BIG	/* �ӥå�����ǥ����� */


#ifndef _MACRO_ONLY
/*
 *  ��ǽɾ���ѥ����ƥ����λ���
 */

#ifdef SUPPORT_VXGET_TIM
typedef	UD	SYSUTIM;	/* ��ǽɾ���ѥ����ƥ���� */

extern ER	vxget_tim(SYSUTIM *p_sysutim) throw();

#endif /*  SUPPORT_VXGET_TIM  */

#endif /* _MACRO_ONLY */


#endif /* _CPU_DEFS_H_ */
