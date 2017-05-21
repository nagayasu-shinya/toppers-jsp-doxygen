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
 *  @(#) $Id: cpu_defs.h,v 1.16 2007/03/23 07:22:15 honda Exp $
 */

/*
 *	�ץ��å��˰�¸���������H8�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�kernel.h �� sil.h �ǥ��󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��뤳�ȤϤʤ������Υե�����򥤥�
 *  ���롼�ɤ������ˡ�t_stddef.h �� itron.h �����󥯥롼�ɤ����Τǡ�
 *  �����˰�¸���Ƥ�褤��
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#include <h8.h>		/*  IPM_LEVEL0,1,2�����  */
#define H8

/* �����ͥ뵯ư���Υ�å����� */
#define COPYRIGHT_CPU \
"Copyright (C) 2001-2010 by Industrial Technology Institute,\n" \
"                            Miyagi Prefectural Government, JAPAN\n" \
"Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering\n" \
"                 Tomakomai National College of Technology, JAPAN\n" \
"Copyright (C) 2003-2004 by Katsuhiro Amano\n"

/*
 *  ������ƥ��å������
 */

#define	TIC_NUME	1		/* ������ƥ��å��μ�����ʬ�� */
#define	TIC_DENO	1		/* ������ƥ��å��μ�����ʬ�� */

/*
 *  CPU �ΥХ��Ƚ�˴ؤ������
 */

#define SIL_ENDIAN		SIL_ENDIAN_BIG

#ifndef _MACRO_ONLY
typedef	UINT	INHNO;			/* ����ߥϥ�ɥ��ֹ� */
typedef	UINT	EXCNO;			/* CPU�㳰�ϥ�ɥ��ֹ� */
#endif /* _MACRO_ONLY */

/*
 *  �������åȥ����ƥ��¸�Υ����ӥ�������
 *
 * cpu_defs.h��sys_defs.h�򥤥󥯥롼�ɤ�����֤δط���
 * SUPPORT_CHG_IPM�ޥ����SUPPORT_VXGET_TIM�ޥ���ǤϰϤޤʤ�
 * ��_MACRO_ONLY�ޥ���ǰϤ�С���ʬ��
 */

/*
 *  ����ߥޥ����η��ȳ���ߥޥ������ѹ�������
 */
#ifndef _MACRO_ONLY
typedef UB              IPM;            /* ����ߥޥ��� */

extern ER       chg_ipm(IPM ipm) throw();
extern ER       get_ipm(IPM *p_ipm) throw();


/*
 *  �ץ饤����ƥ���٥������ѤΥǡ�����¤
 */
typedef struct {
        UB *ipr;        /* ���ꤹ��IPR�쥸���������� */
        UB bit;         /* IPR�쥸�����γ�������ӥå��ֹ� */
        IPM ipm;        /* ���ꤹ�����ߥ�٥� */
                        /* IPM_LEVEL0,IPM_LEVEL1�Τ����줫 */
} IRC;                  /* IRC:Interrupt Request Controller */


/*
 *  ��ǽɾ���ѥ����ƥ�����¬��ǽ
 */

/* ��ǽɾ���ѥ����ƥ���� */
#ifdef _int64_		/*  64�ӥå�������������  */
typedef	UD  SYSUTIM;
#else 	/*  _int64_  */
typedef	UW  SYSUTIM;
#endif	/*  _int64_  */

extern ER   vxget_tim(SYSUTIM *pk_sysutim) throw();

/*
 *  �����ƥ�����ǽ���
 */

Inline void
kernel_abort (void)
{
	while (1)
		;
}

#endif /* _MACRO_ONLY */

#endif /* _CPU_DEFS_H_ */
