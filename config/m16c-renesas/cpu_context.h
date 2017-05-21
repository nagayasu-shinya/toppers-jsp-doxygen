/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004, 2007 by Naoki Saito
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
 *  @(#) $Id: cpu_context.h,v 1.4 2007/03/23 07:08:04 honda Exp $
 */


/*
 *	����������ƥ��������롼�����M16C�ѡ�
 *
 *  ���Υե������ cpu_config.h ��ʬΥ���Ƥ���Τϡ����Υե������ TCB
 *  ��������줿����ɤ�ɬ�פ�����Τ��Ф��ơ�cpu_config.h �ˤ� TCB ��
 *  ������������ɤ�ɬ�פ����������ޤ�Ǥ��뤿��Ǥ��롥
 */

#ifndef _CPU_CONTEXT_H_
#define _CPU_CONTEXT_H_

#include "task.h"

#ifndef _MACRO_ONLY

/*
 *  ����������ƥ����Ȥν����
 *
 *  ���������ٻ߾��֤˰ܹԤ�����ʥ����������������������ν�λ���ˤ˸�
 *  �Ф�롥����Ū�ˤϡ�����������ƥ����Ȥ򥿥�������ư�Ǥ�����֤���
 *  �ꤹ�������create_context �� activate_context �ǹԤ��Ф褤��
 */
Inline void
create_context(TCB *tcb)
{
}

/*
 *  �������ε�ư����
 *
 *  ���������ٻ߾��֤���¹ԤǤ�����֤˰ܹԤ�����˸ƤФ�롥
 */
extern void	activate_r(void);

Inline void
activate_context(TCB *tcb)
{
	VW *sp;
	VW  return_point = (VW)ext_tsk;

	sp = (VW *)(((VB *) tcb->tinib->stk) + tcb->tinib->stksz);

	*--sp = (VW)(tcb->tinib->exinf);
	sp = (VW *)((VB*)sp - 1);
	*(VB*)sp = (VB)(return_point >> 16);
	sp = (VW *)((VH*)sp - 1);
	*(VH*)sp = (VH)return_point;
	*--sp = (VW)(tcb->tinib->task);

	tcb->tskctxb.pc = activate_r;	/*  cpu_support.a30  */
	tcb->tskctxb.sp = sp;
}

/*
 *  ext_tsk �������å���˳��ݤ�����ߡ��ΰ�Υ�����
 */
#define	ACTIVATED_STACK_SIZE	(sizeof(VW) * 3)

/*
 *  calltex ����Ѥ��ʤ�
 */
#define OMIT_CALLTEX

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONTEXT_H_ */
