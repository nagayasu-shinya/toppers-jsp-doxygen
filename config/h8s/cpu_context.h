/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

/*
 *  ����������ƥ��������롼����
 *
 *  ���Υե������ cpu_conf.h ��ʬΥ���Ƥ���Τϡ����Υե������TCB��
 *  ������줿����ɤ�ɬ�פ�����Τ��Ф��ơ�cpu_conf.h �ˤ�TCB�������
 *  �������ɤ�ɬ�פ����������ޤ�Ǥ��뤿��Ǥ��롥
 */

#ifndef _CPU_CONTEXT_H_
#define _CPU_CONTEXT_H_

#include "task.h"

/*
 *  ����������ƥ����ȥ֥�å��ν����
 *
 *  ���������ٻ߾��֤˰ܹԤ�����ʥ����������������������ν�λ���ˤ˸�
 *  �Ф�롥����Ū�ˤϡ�����������ƥ����ȥ֥�å��򥿥�������ư�Ǥ���
 *  ���֤����ꤹ�������create_context �� activate_context �ǹԤ���
 *  �褤��¿���ν����Ϥɤ���δؿ��ǹԤäƤ�褤��
 */
Inline void
create_context(TCB *tcb)
{
}

/*
 *  �������ε�ư����
 *
 *  ���������ٻ߾��֤���¹ԤǤ�����֤˰ܹԤ�����˸ƤФ�롥
 *
 *  �����å���ˤϲ����Ѥޤʤ�
 *  activate_r�Ǥ�runtsk����ɬ�פʾ������Ф���Τǡ�
 *  �����å����Ѥ�ɬ�פϤʤ��ʸ�Ψ��������
 *  
 */

extern void	activate_r(void);	/*  cpu_support.S  */

Inline void
activate_context(TCB *tcb)
{
	VW	*sp;

	sp = (VW *)(((VB *) tcb->tinib->stk) + tcb->tinib->stksz);
	tcb->tskctxb.sp = sp;
	tcb->tskctxb.pc = activate_r;
}


/*
 *  ext_tsk �������å���˳��ݤ�����ߡ��ΰ�Υ������ϡ�
 *    H8S�Ǥ��������ɬ�פ�̵����
 */
/* #define ACTIVATED_STACK_SIZE	(sizeof(VW) * 3) */

/*
 *  calltex �ϻ��Ѥ��ʤ�
 */
#define OMIT_CALLTEX

#endif /* _CPU_CONTEXT_H_ */
