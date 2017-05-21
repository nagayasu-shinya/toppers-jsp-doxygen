/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Katsuhiro Amano
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
 *  @(#) $Id: cpu_config.c,v 1.7 2007/03/23 07:58:33 honda Exp $
 */

/*
 *  �ץ��å���¸�⥸�塼���H8�ѡ�
 *�����������ͥ������ǻ��Ѥ������
 *��������C����ؿ��μ���
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "sil.h"
#include <hw_serial.h>  /*  SCI_putchar_pol()  */

#ifdef SUPPORT_CHG_IPM
/*
 *  ����������ƥ����ȤǤγ���ߥޥ���
 */
volatile UB      task_intmask = 0;
#endif /* SUPPORT_CHG_IPM */

/*
 *  �󥿥�������ƥ����ȤǤγ���ߥޥ���
 */
volatile UB      int_intmask = 0;

/*
 *  ����ߥͥ��ȥ�����
 */
volatile UB      intnest = 0;

/*
 *  CPU��å����֤�ɽ���ե饰
 */
volatile BOOL    iscpulocked = TRUE;

/*
 *  �����ޤΥץ饤����ƥ���٥������ѤΥǡ���
 *      �����hw_timer.h�˵��Ҥ���٤����������������
 *      hw_timer.h�򥤥󥯥롼�ɤ����ե�����Ǥ��٤Ƽ��β������
 *�����������ΰ����ͭ���Ƥ��ޤ����ᡢ���ΤϤ����˵��Ҥ��롣
 */
const IRC TIMER_IRC = {(UB*)SYSTEM_TIMER_IPR,
                        SYSTEM_TIMER_IP_BIT,
                        SYSTEM_TIMER_IPM
};

/*
 *  SYSCR�ν����
 *      $CPU�ǥ��쥯�ȥ�������������
 *      ���ӥå�7 SSBY=0��sleep̿��ǥ��꡼�ץ⡼�ɤذܹ�
 *      ���ӥå�3 UE=1��CCR.UI�����ߥޥ����ӥåȤȤ�������
 *      ���ӥå�1 1���ꥶ���֥ӥå�
 *      ���ӥå�0 RAME=1����¢RAMͭ��
 *      $SYS�ǥ��쥯�ȥ��SYSCR_SYS�Ȥ��������������
 *      ���ӥå�6-4 STS��������Х��������ޡ����쥯��
 *      ���ӥå�2 NMIEG��NMI���å�
 */
#define SYSCR_INI	(H8SYSCR_UE | BIT1 | H8SYSCR_RAME | SYSCR_SYS)

/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize(void)
{
        /*
         *  �ʲ��Σ��Ĥϥ������ȥ��åץ롼����ǽ�������Ѥ�Ǥ��롣
         *  ����������ߥͥ��ȥ����� intnest
         *  �������󥿥�������ƥ����Ȥγ���ߥޥ��� int_intmask
         *  ����������������ƥ����Ȥγ���ߥޥ��� task_intmask
         *  ����������chg_ipm�򥵥ݡ��Ȥ������
         */

        /*
         *  SYSCR������
         */
        sil_wrb_mem((VP)H8SYSCR, (VB)SYSCR_INI);
         
        /*  ̤����  */
        /*  sleep̿������ܤ�������Ͼ��֤�����  */

        /*  ���٥�����ѥ��ꥢ��ݡ��Ȥν����  */
        SCI_initialize(SCI_LOW_PORTID);
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate(void)
{
}

#ifdef SUPPORT_CHG_IPM
/*
 *  ����ߥޥ������ѹ�
 *
 *��IPM������Ǥ����ͤȤ���IPM_LEVEL0��IPM_LEVEL1���ޥ����������Ƥ��롣
 *
 *
 *��IPM_LEVEL0����٥룰�����٤Ƥγ���ߤ�����դ���
 *��IPM_LEVEL1����٥룱��NMI����ӥץ饤����ƥ���٥룱�γ���ߤΤߤ�
 *�����������������������������դ���
 *
 *  chg_ipm ��Ȥä� IPM ���٥�2��NMI �ʳ��Τ��٤Ƥγ���ߤ�ػߡˤ�
 *  �ѹ����뤳�ȤϤǤ��ʤ���NMI �ʳ��Τ��٤Ƥγ���ߤ�ػߤ��������
 *  �ˤϡ�loc_cpu �ˤ��CPU��å����֤ˤ���Ф褤��
 *  IPM �� 0 �ʳ��λ��ˤ⡤�������ǥ����ѥå�����α����ʤ���IPM �ϡ�
 *  �������ǥ����ѥå��ˤ�äơ��������¹Ծ��֤ˤʤä��������ذ����Ѥ�
 *  ��롥���Τ��ᡤ���������¹���ˡ��̤Υ������ˤ�ä� IPM ���ѹ���
 *  ����礬���롥JSP�����ͥ�Ǥϡ�IPM ���ѹ��ϥ������㳰�����롼��
 *  ��ˤ�äƤⵯ����Τ�������ˤ�äư������񤷤��ʤ�����Ͼ��ʤ���
 *  �פ��롥
 *��IPM ���ͤˤ�äƥ������ǥ����ѥå���ػߤ��������ˤϡ�dis_dsp��
 *  ʻ�Ѥ���Ф褤��
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
        ER      ercd = E_OK;

        LOG_CHG_IPM_ENTER(ipm);
        CHECK_TSKCTX_UNL();
        CHECK_PAR( (ipm == IPM_LEVEL0) || (ipm == IPM_LEVEL1) || (ipm == IPM_LEVEL2));

        t_lock_cpu();
        task_intmask = ipm;
        t_unlock_cpu();

    exit:
        LOG_CHG_IPM_LEAVE(ercd)
        return(ercd);
}

/*
 *  ����ߥޥ����λ���
 */
SYSCALL ER
get_ipm(IPM *p_ipm)
{
        ER      ercd = E_OK;

        LOG_GET_IPM_ENTER(p_ipm);
        CHECK_TSKCTX_UNL();

        t_lock_cpu();
        *p_ipm = task_intmask;
        t_unlock_cpu();

    exit:
        LOG_GET_IPM_LEAVE(ercd, *p_ipm);
        return(ercd);
}

#endif /* SUPPORT_CHG_IPM */

/*
 * ���������Ԥ�
 * ������ջ��ࡧ
 * ������ɸ��Ǥ�dlytim��UINT������16�ӥåȤ����ʤ��Τǡ�
 * ������UW�����ѹ����Ƥ��롣
 * ������sil_dly_nse()��������sil_dly_nse2()��ƤӽФ���
 */
void sil_dly_nse(UINT dlytim) {
	sil_dly_nse_long((UW)dlytim);
}

/*****�ʲ����������ȤΥ��󥿡��ե������˴ޤޤ�ʤ���ʬ*********/

/*
 * ��Ͽ����Ƥ��ʤ������ߤΥǥե���Ƚ���
 */

/*
 * �����å�����Ƭ����ƥ쥸�����ΤޤǤΥ��ե��å�
 * 
 * �������å���¤
 *���� +0:er0
 *���� +4:er1
 *���� +8:er2
 *����+12:er3
 *����+16:er4
 *����+20:er5
 *����+24:er6
 *����+28:crr
 *����+29:pc
 *����+32��:��������˻��Ѥ���Ƥ��������å��ΰ�
 */

/*
 * �����ȯ��ľ���Υ����å��ݥ��󥿤ޤǤΥ��ե��å�
 */
#define OFFSET_SP	32

/*
 * ��Ͽ����Ƥ��ʤ������ߤ�ȯ������ȸƤӽФ����
 */
void 
cpu_experr(EXCSTACK *sp)
{
    UW sp2, pc, ccr, tmp;
    
    sp2 = (UW)sp + OFFSET_SP;
    tmp = sp->pc;
    ccr = (tmp >> 24U) & 0xff;	/*  ���1�Х���  */
    pc = tmp & 0x00ffffffUL;	/*  ����3�Х���  */
    
	/*
	 *  %x���������ˤǤ�2�Х��Ȥ���ɽ���Ǥ��ʤ��Τ�
	 *  %p�ʥݥ��󥿷��ˤ��Ѥ���4�Х���ɽ�����Ƥ��롣
	 */
    syslog(LOG_EMERG, "Unexpected interrupt.");
    syslog(LOG_EMERG, "PC  = 0x%08p SP  = 0x%08p CCR  = 0x%02x",
                       (VP)pc, (VP)sp2, (INT)ccr);
    syslog(LOG_EMERG, "ER0 = 0x%08p ER1 = 0x%08p ER2 = 0x%08p ER3 = 0x%08p",
           (VP)(sp->er0), (VP)(sp->er1), (VP)(sp->er2), (VP)(sp->er3));
    syslog(LOG_EMERG, "ER4 = 0x%08p ER5 = 0x%08p ER6 = 0x%08p",
                       (VP)(sp->er4), (VP)(sp->er5), (VP)(sp->er6));
    while(1)
    	;
}

/*
 *  �������åȥ����ƥ��ʸ������
 *
 *  �����ƥ�����٥��ʸ�����ϥ롼����
 */
void
cpu_putc(char c)
{
    if (c == '\n') {
        SCI_putchar_pol('\r');
    }
    SCI_putchar_pol((UB)c);
}
