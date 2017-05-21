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
 *  @(#) $Id: cpu_config.c,v 1.8 2003/12/24 07:24:40 honda Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���Linux�ѡ�
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  ����������ƥ����ȤǤγ���ߥޥ���
 */
#ifdef SUPPORT_CHG_IMS
IMS     task_sigmask;
#endif /* SUPPORT_CHG_IMS */

/*
 *  �󥿥�������ƥ����ȤǤγ���ߥޥ���
 */
IMS	int_sigmask;

void
dispatch()
{
    sigset_t waitmask;
    sigemptyset(&waitmask);
    sigaddset(&waitmask,SIGUSR1);
        if (enadsp && (!runtsk || (runtsk != schedtsk
                        && _setjmp(runtsk->tskctxb.env) == 0))) {
            while (!(runtsk = schedtsk)) {
                sigsuspend(&waitmask);
            }
            _longjmp(runtsk->tskctxb.env, 1);
        }else{
            calltex();
        }
}


/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå�
 *
 *  exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */

void
exit_and_dispatch() 
{                   
    runtsk = 0;
    dispatch();
}


/*
 *  �ץ��å���¸�ν����
 */


extern void kernel_start();

void
cpu_initialize()
{

	/*
	 *  ����������ƥ����ȤǤγ���ߥޥ����ν����
	 */
#ifdef SUPPORT_CHG_IPM
    sigemptyset(&task_sigmask);
#endif /* SUPPORT_CHG_IPM */

    /*
     *  �����ʥ륹���å��򡤥ץ��������å���˼�롥
     *  BSD�Υ����ʥ�Ȱۤʤ�ss.ss_flags��SS_ONSTACK��
     *  �񤭹���Ǥ�ȿ�Ǥ���ʤ����ᡢ��������Ω����ɽ��
     *  inSigStack����Ѥ��롣
     */


    /*
     *  �ǥ����ѥå��ѤΥ����ʥ�ϥ�ɥ�����ꡥ
     *  �����ߥϥ�ɥ�νи���SIGUSR1����Ѥ��ƸƤӽФ�
     *  ���Ȥˤ��롣
     */
	{
            struct sigaction dis_action;
            dis_action.sa_handler = dispatch;
            dis_action.sa_flags   =  0;
            sigfillset(&dis_action.sa_mask);
            sigaction(SIGUSR1,&dis_action,((void *)0));

	}
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate()
{
}



#ifdef SUPPORT_CHG_IMS
/*
 *   IMASK�����껲�ȵ�ǽ
 */
SYSCALL ER
chg_ims(IMS ims)
{

    if(sense_context()){
        if(!sigismember(&ims,SIGUSR1))
            return(E_PAR);
    }else{
        if(sigismember(&ims,SIGUSR1))
            return(E_PAR);
    }
    
    
    sigprocmask(SIG_SETMASK,&ims,0);    
	return(E_OK);
}

/*
 *  ����ߥޥ����λ���
 */
SYSCALL ER
get_ims(IMS *p_ims)
{
    sigprocmask(SIG_SETMASK,p_ims,0);        
	return(E_OK);
}


#endif /* SUPPORT_CHG_IMS */


/*
 * ��������ư�롼����
 *
 */

void
activate_r()
{
    /*
     *  �����ʥ�ޥ��������ꤷ�ơ���������ư���롥
     */
#ifdef SUPPORT_CHG_IMS
    sigprocmask(SIG_SETMASK,&task_sigmask,((void *)0));
#else /* SUPPORT_CHG_IMS */
    sigset_t set;
    sigemptyset(&set);
    sigprocmask(SIG_SETMASK,&set,((void *)0));
#endif /* SUPPORT_CHG_IMS */
    (*runtsk->tinib->task)(runtsk->tinib->exinf);
    
    ext_tsk();
}



