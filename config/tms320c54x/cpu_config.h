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
 *  @(#) $Id: cpu_config.h,v 1.9 2003/12/04 08:25:44 honda Exp $
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

#include "api.h"

/*
 *  �����ͥ���������̾�Υ�͡���
 */
#include "cpu_rename.h"

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#ifndef _MACRO_ONLY
#include "cpu_insn.h"
#endif /* _MACRO_ONLY */

#include "c54x.h"


#define TBIT_TCB_TSTAT      6
#define TBIT_TCB_PRIORITY   4

#ifndef _MACRO_ONLY

typedef struct task_context_block{
  VP  sp;
  FP  pc;
}CTXB;

extern UH  nest;

Inline BOOL
sense_context(void)
{
  return (nest > 0);
}

Inline BOOL
sense_lock()
{
  volatile UH temp_st1;
  temp_st1 = ST1;
  return ((temp_st1 & 0x0800) > 0);
}

#define t_sense_lock sense_lock
#define i_sense_lock sense_lock

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

extern void dispatch(void);
extern void exit_and_dispatch(void);

extern FP  int_table[32];
extern const UH  int_mask_table[32];


Inline void
define_inh(INHNO inhno, FP inthdr)
{
  int_table[inhno] = inthdr;
}

#define INTHDR_ENTRY(inthdr) extern void inthdr(void)
#define INT_ENTRY(inthdr) inthdr

/*
 *  TMS320VC54x DSP�ˤ�CPU�㳰��¸�ߤ��ʤ��Τ�
 *  �ʲ���Ŭ��������
 */

/*
 *   CPU�㳰�ϥ�ɥ������
 *   �����٥������ơ��֥����Ͽ
 */   

Inline void
define_exc(EXCNO excno, FP exchdr)
{
}

/*
 *  CPU�㳰��ȯ���������Υ���ƥ�����Ƚ��
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
   return(TRUE);
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
   return(TRUE);
}

extern void cpu_initialize(void);
extern void cpu_terminate(void);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
