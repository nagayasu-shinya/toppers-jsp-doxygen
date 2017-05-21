/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2003      by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2010 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�
 *  �����ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭�����
 *      ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ�����
 *      ��������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ����Ѽԥ�
 *      �˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ�����̵��
 *      �ڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ���
 *        �𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»��
 *      ����⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ��ޤ���
 *      �ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���ͳ�˴��
 *      �����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ���
 *  ��TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū���Ф�
 *  ��Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ�����������
 *  �ˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ����
 *  ��ʤ���
 */

/*
 *  �ץ��å���¸�⥸�塼���Xstormy16�ѡ�
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
#include <cpu_insn.h>

/*
 *  chg_ipm/get_ipm �ϥ��ݡ��Ȥ��ʤ�
 */
#undef  SUPPORT_CHG_IPM

/*
 *  calltex �ϻ��Ѥ��ʤ�
 */
#define OMIT_CALLTEX

/*
 *  ���ꥢ��ݡ��ȿ������
 */
#define TNUM_PORT   2   /* ���ݡ��Ȥ��륷�ꥢ��ݡ��Ȥο� */

/*
 *  ���ꥢ��ݡ����ֹ�˴ؤ������
 */
#define LOGTASK_PORTID  1   /* �����ƥ�����Ѥ��륷�ꥢ��ݡ����ֹ� */

/*
 *  ����������ɬ�ץ����å�������
 */
#define LOGTASK_STACK_SIZE 256

/*
 *  ���Хåե��Υ�����
 */
#define TCNT_SYSLOG_BUFFER  8

/*
 *  TCB ��Υե�����ɤΥӥå��������
 */
#define TBIT_TCB_TSTAT      8   /* tstat �ե�����ɤΥӥå��� */
#define TBIT_TCB_PRIORITY   4   /* priority �ե�����ɤΥӥå��� */

#ifndef _MACRO_ONLY

/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
    unsigned short sp;          /* �����å��ݥ��� */
    unsigned short mode;        /* dispatcher�������� */
} CTXB;

/*
 *  ������/�󥿥��������ѥ����Х��ѿ�
 */
extern unsigned short _kernel_intnest ;

/*
 *  �����ƥ���ֻ���
 */
#define sense_context() ( _kernel_intnest > 0)
#define sense_lock() (!( __PSW & 0x0080 ))
#define t_sense_lock sense_lock
#define i_sense_lock sense_lock
#define t_lock_cpu() ({__asm__( "clr1 psw,#7" );})
#define t_unlock_cpu() ({__asm__( "set1 psw,#7" );})
#define i_lock_cpu t_lock_cpu
#define i_unlock_cpu t_unlock_cpu

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥλ���
 */
#define exc_sense_context(p_excinf) ( _kernel_intnest > 1 )

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
#define exc_sense_lock(p_excinf) (!(((unsigned short*)p_excinf)[-1] & 0x0080))

/*
 *  ����ߥϥ�ɥ������ޥ���
 */
#define INTHDR_ENTRY(inthdr) extern void inthdr(void)
#define INT_ENTRY(inthdr) inthdr

/*
 *  CPU�㳰�����ޥ���
 */
#define EXCHDR_ENTRY(exchdr) extern void exchdr(VP sp)
#define EXC_ENTRY(exchdr) exchdr

/*
 *  �ץ��å���¸�ν����
 */
extern void cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void cpu_terminate(void);

/*
 *  ����ߥϥ�ɥ������
 */
extern void define_inh(INHNO inhno, FP inthdr) ;

/*
 *  CPU�㳰�ϥ�ɥ������
 */
extern void define_exc(EXCNO excno, FP exchdr) ;

/*
 *  �������åȥ����ƥ��ʸ������
 */
extern void sys_putc(char c);

/*
 *  �������ǥ����ѥå���
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���cpu_support.S���
 */
extern void dispatch(void);

/*
 *  �������ǥ����ѥå���
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���cpu_support.S���
 */
extern void exit_and_dispatch(void);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
