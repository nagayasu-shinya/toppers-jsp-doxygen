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
 *  @(#) $Id: cpu_config.h,v 1.9 2003/12/24 07:24:40 honda Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���Linux�ѡ�
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include <cpu_rename.h>

#ifndef _MACRO_ONLY

/*
 *  Linux��ɸ�।�󥯥롼�ɥե�����
 */

#include <signal.h>
#include <setjmp.h>

/*
 *  chg_ims/get_ims �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define	SUPPORT_CHG_IMS

/*
 *  TCB ��Ϣ�����
 *
 *  cpu_context.h ��������������쥬��Ȥ��������Ȥΰ�¸���δط��ǡ�
 *  cpu_context.h �ˤ�������ʤ���
 */

/*
 *  TCB ��Υե�����ɤΥӥå��������
 */
#define	TBIT_TCB_PRIORITY	8	/* priority �ե�����ɤΥӥå��� */
#define	TBIT_TCB_TSTAT		8	/* tstat �ե�����ɤΥӥå��� */

/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	jmp_buf env;		/* CPU����ƥ����� */
} CTXB;

/*
 *   CPU�㳰�ϥ�ɥ�
 */

#define EXCHNO_ZDIV  SIGFPE

/*
 *  �����ƥ���ֻ���
 */


Inline int
current_stack()
{
    struct sigaltstack      ss;

    sigaltstack(((void *)0), &ss);
    return(ss.ss_flags & SS_ONSTACK);
}


Inline BOOL
sense_context()
{
	return(current_stack());
}

Inline BOOL
sense_lock()
{
    sigset_t currentSet;
    
    sigprocmask(SIG_BLOCK, ((void *)0), &currentSet);

#if defined(linux) & (defined(i386) | defined(_i386_) | defined(__i386__))
    if(currentSet.__val[0] == ~(0 | (1<<(SIGKILL-1)) | (1<<(SIGSTOP-1)))
       &&  currentSet.__val[1] == ~0 )
        return(TRUE);
    else
        return(FALSE);
#else
    
#error not supported.
    
#endif /* linux */    
}


#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU��å��Ȥ��β���ʥ���������ƥ������ѡ�
 *
 *  task_intmask �ϡ�chg_ipm �򥵥ݡ��Ȥ��뤿����ѿ���chg_ipm �򥵥ݡ�
 *  �Ȥ��ʤ����ˤϡ�task_intmask ����� 0 �ˤʤäƤ���ȹͤ���Ф褤��
 */

#ifdef SUPPORT_CHG_IMS
extern IMS	task_sigmask;	/* ����������ƥ����ȤǤγ���ߥޥ��� */
#endif /* SUPPORT_CHG_IMS */

Inline void
t_lock_cpu()
{
    sigset_t  newmask;
    
    sigfillset(&newmask);
    sigprocmask(SIG_SETMASK,&newmask,0);
}

Inline void
t_unlock_cpu()
{
#ifdef SUPPORT_CHG_IMS
	/*
	 *  t_unlock_cpu ���ƤӽФ����Τ� CPU��å����֤ΤߤǤ��뤿
	 *  �ᡤ����������� task_intmask ���񤭴���뤳�ȤϤʤ���
	 */
    sigprocmask(SIG_SETMASK,&task_sigmask,0);
#else /* SUPPORT_CHG_IMS */
    sigset_t  mask;
    
    sigemptyset(&mask);
    sigprocmask(SIG_SETMASK,&mask,0);
#endif /* SUPPORT_CHG_IMS */
}

/*
 *  CPU��å��Ȥ��β�����󥿥�������ƥ������ѡ�
 */

extern IMS	int_sigmask;	/* �󥿥�������ƥ����ȤǤγ���ߥޥ��� */

Inline void
i_lock_cpu()
{
    sigset_t  mask;
    
    sigfillset(&mask);
    sigprocmask(SIG_SETMASK,&mask,&int_sigmask);
}

Inline void
i_unlock_cpu()
{
    sigprocmask(SIG_SETMASK,&int_sigmask,0);
}

/*
 *  �������ǥ����ѥå���
 */

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå�
 *
 *  dispatch �ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ����������
 *  ��ǡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	dispatch();


/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå�
 *
 *  exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */

extern void    exit_and_dispatch(void);

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ������
 */


/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 */

Inline void
define_inh(INHNO inhno, FP inthdr)
{
    /*
     *  SIGUSR1��֥�å��������å��ڤ��ؤ�ͭ�����Ͽ���롣
     *  ͥ���٤��դ��������ϥޥ�������ӥåȤ���ꤹ��
     *  ɬ�פ�����ΤǤ�����ˡ�ϻȤ��ʤ���
     */
    
    struct sigaction action;

    action.sa_handler = inthdr;
    sigemptyset(&action.sa_mask);
    sigaddset(&action.sa_mask,SIGUSR1);
    action.sa_flags = SA_ONSTACK;
    
    sigaction(inhno, &action, 0);    
}

/*
 *  CPU�㳰�ϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� excno ��CPU�㳰�ϥ�ɥ�ε�ư���Ϥ� exchdr �����ꤹ�롥
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
    /*
     * �֥�å�����ޥ���̵���������å��ڤ��ؤ�ͭ�����Ͽ���롣
     */
    struct sigaction action;

    action.sa_handler = exchdr;
    sigemptyset(&action.sa_mask);
    sigaddset(&action.sa_mask,SIGUSR1);    
    action.sa_flags = SA_ONSTACK;    
    sigaction(excno, &action, 0);
}

/*
 *  ����ߥϥ�ɥ顿CPU�㳰�ϥ�ɥ�ν���������
 */

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *
 *  �����ʥ뤬ȯ�Ԥ���Ƥ�ȥ����ʥ륹���å��˼�ưŪ���ڤ��ؤ�롣
 *  ���Ƥγ����ߥϥ�ɥ�ϥǥ����ѥå����ư����SIGUSR1��ޥ�������
 *  ư��롣���Τ���reqflg�Υ����å��奷���ʥ뤬ȯ�Ԥ���Ƶ�ư���줿
 *  �ϥ�ɥ�ǥǥ����ѥå����׵ᤵ��Ƥ�������ư��
 */


#define	INTHDR_ENTRY(inthdr)      \
void inthdr##_entry(void){        \
     inthdr();                           /* �����ߥϥ�ɥ��ƤӽФ� */ \
     if(_kernel_reqflg)                  /* regflg ��TRUE�Ǥ����      */ \
       raise(SIGUSR1);                   /* �ǥ����ѥå����ƤӽФ�   */ \
}                                      

#define INT_ENTRY(inthdr)   inthdr##_entry


/*
 *  CPU�㳰�ϥ�ɥ�ν����������������ޥ���
 *
 *  �����ʥ뤬ȯ�Ԥ���Ƥ�ȥ����ʥ륹���å��˼�ưŪ���ڤ��ؤ�롣 
 *  ���Ƥ�CPU�㳰�ϥ�ɥ�ϥǥ����ѥå����ư����SIGUSR1��ޥ�������
 *  ư��롣���Τ���reqflg�Υ����å��奷���ʥ뤬ȯ�Ԥ���Ƶ�ư���줿
 *  �ϥ�ɥ�ǥǥ����ѥå����׵ᤵ��Ƥ�������ư�� 
 */
#define	EXCHDR_ENTRY(exchdr)	  \
void exchdr##_entry(VP sp){        \
     exchdr(sp);                         /* �����ߥϥ�ɥ��ƤӽФ� */ \
     if(_kernel_reqflg)                  /* regflg ��TRUE�Ǥ����      */ \
       raise(SIGUSR1);                   /* �ǥ����ѥå����ƤӽФ�   */ \
}

#define EXC_ENTRY(exchdr) exchdr##_entry

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */

/*
 *  CPU�㳰��ȯ���������Υǥ����ѥå�
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return((*((UH *) p_excinf) & 0x1000) == 0);
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return((*((UH *) p_excinf) & 0x0700) == 0x0700);
}


/*
 *  �ץ��å���¸�ν����
 */
extern void	cpu_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void	cpu_terminate(void);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */







