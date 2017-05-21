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
 *  @(#) $Id: cpu_config.c,v 1.4 2006/08/03 04:15:57 honda Exp $
 */

/*
 *  �ץ��å���¸�⥸�塼���M16C�ѡ�
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/* 
 *  �����/CPU�㳰�ͥ��ȥ�����
 */
char	intnest;

/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize(void)
{
	/* ����ߥͥ��ȥ�����Ƚ����(����������ƥ�����) */
	intnest = 0;
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate(void)
{
}

/*
 * software_init_hook�β����
 */
#ifndef EXTERNAL_SOFT_HOOK
const VP_INT software_init_hook = 0;
#endif  /* EXTERNAL_SOFT_HOOK */


/*
 * ����������쥸����������ͥ�����ѹ�
 *
 * ����������쥸�����ϡ����Υ쥸�������б����������׵᤬ȯ�����ʤ��ս��
 * �ѹ�����ɬ�פ����롥���Τ��ᡤ����ߤ�ػߤ����塤�ѹ�����ɬ�פ����롥
 * ����ߤ�ػߤ��Ƴ��������쥸�������ѹ�������ϡ����Ѥ���̿�����դ���
 * ɬ�פ����롥
 * IR�ӥåȰʳ����ѹ�������ˤϡ�AND,OR,BCLR,BSET̿�����Ѥ��뤳�ȡ�
 * IR�ӥåȤ�MOV̿�����Ѥ��뤳�ȡ�
 * �ޤ���I�ե饰���Ѥ��Ƴ���ߤ�ػߤ�����ϡ����Ĥ������˿�̿�ᤪ�����ȡ�
 * �ܺ٤ϡ�M16C�ϡ��ɥ������ޥ˥奢���
 *       "���Ѿ�����->������->���������쥸�������ѹ�"
 * �򻲾ȤΤ��ȡ� 
 */
void
set_ic_ilvl(VP addr, UB val){
    BOOL    locked;
    
    locked = sense_lock();
    if (!(locked)) {
        sense_context() ? i_lock_cpu() : t_lock_cpu();
    }
    
    _asm("PUSH.W A0");
    _asm("PUSH.B R0L");
    _asm("MOV.W $$[FB], A0", addr);
    _asm("MOV.B $$[FB], R0L", val);
    _asm("AND.B #08H, [A0]");
    _asm("OR.B  R0L, [A0]");
    _asm("NOP");
    _asm("NOP");    
    _asm("POP.B R0L");
    _asm("POP.W A0");

    if (!(locked)) {
        sense_context() ? i_unlock_cpu() : t_unlock_cpu();
    }
    
}

