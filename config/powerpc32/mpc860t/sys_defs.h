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
 *  @(#) $Id: sys_defs.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *	�������åȥ����ƥ�˰�¸���������MPC860T TB6102S�ѡ�
 *�������������ץꥱ�������ɬ�פȤ������
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�kernel.h �� sil.h �ǥ��󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��뤳�ȤϤʤ������Υե�����򥤥�
 *  ���롼�ɤ������ˡ�t_stddef.h �� itron.h �����󥯥롼�ɤ����Τǡ�
 *  �����˰�¸���Ƥ�褤��
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

/*
 *  �桼�����������
 */
#include <user_config.h>

#define TB6102S			/* �����ƥ�ά�� */
#define MPC860T			/* �ץ��å�ά�� */


#ifndef _MACRO_ONLY

/*
 *  ICU�����ꤹ��IPM�η����
 *  ����MPC860�Ǥϥ����ƥ।�󥿡��ե�������˥å�SIU�γ���ߥޥ���
 *  ������SIU����ߥޥ����쥸����SIMASK�ˤΤߥ����ͥ�Ǵ������롣
 *  �����̿��ץ��å��⥸�塼��CPM�γ���ߥޥ����δ����Ϥ��٤ƥϡ���
 *  �������������ԤäƤ��롣
 */
typedef UH IPM;

/*
 *  ������ֹ�η��ȳ���ߤζػߡ�����
 */
 	/*  
 	 * �� PowerPC MPC860T�ǤǤϥ��ݡ��Ȥ��Ƥ��ʤ���
	 *  �������ˤ����빩���ϳ���ߥ���ȥ���ι�¤��
	 *  ���礭����¸����  
	 */
#if 0
typedef	UINT	INTNO;		/* ������ֹ� */

extern ER	dis_int(INTNO intno) throw();
extern ER	ena_int(INTNO intno) throw();

#endif /* 0 */

#endif /* _MACRO_ONLY */

#ifndef _MACRO_ONLY

/*
 *  ��ǽɾ���ѥ����ƥ����λ���
 */
#ifdef SUPPORT_VXGET_TIM

typedef	UD	SYSUTIM;	/* ��ǽɾ���ѥ����ƥ���� */
extern ER	vxget_tim(SYSUTIM *p_sysutim) throw();

#endif	/*  SUPPORT_VXGET_TIM  */

/*
 *  �����ƥ����߽���
 */
#ifdef GDB_STUB

Inline void
kernel_abort()
{
	/*  ̤����  */
}

#else /* GDB_STUB */

Inline void
kernel_abort()
{
	while(1);
}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _SYS_DEFS_H_ */
/*  end of file  */
