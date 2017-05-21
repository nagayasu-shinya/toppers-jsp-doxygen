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
 *  @(#) $Id: sys_config.c,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���MPC860T TB6102S�ѡ�
 *���������������ͥ������ǻ��Ѥ������
 *������������C����ؿ��μ���
 */

#include "jsp_kernel.h"
#include <mpc860_sil.h>

/*
 *  �����ȯ�����˥����å������򤵤줿���֤�IPM�Υǡ�����¤
 *    4�Х��ȶ�����ݻ����뤿�ᡢ���ߡ��ΰ褬����
 */
typedef struct ipm_stack {
	UH	ipm;
	UH	dummy;
} IPM_STACK;

/*
 *  ����ߥޥ����ѵ����٥����ơ��֥�
 *	ipm_table���Τ�$(CPU)�ȤΥ��󥿡��ե������˴ޤޤ�ʤ�
 *��������define_ipm�ˤ�ꡢ���ä���Ƥ����
 */
IPM ipm_table[TMAX_EXCNO];

/*
 *  SIL����Ѥ����Ȥ��Υ���ǽ
 */
#ifdef SIL_DEBUG

BOOL sil_debug_on = FALSE;
char sil_buffer[SIL_BUFFER_SIZE];
int sil_pos = -1;
UW sil_log_id = 0;

#endif	/* SIL_DEBUG */

/*
 *  �������åȥ����ƥ��¸�ν����
 */
void
sys_initialize()
{
    	INHNO j;
	
	/*
	 *  �̿��ץ��å�CPM�ν����
	 */
	
	/*  �ꥻ�åȡ����ޥ�ɤ�ȯ��  */
    	mpc860_wrh_mem(CPCR, CPCR_RST | CPCR_FLG);
	
	/*
	 *  ����ߥ���ȥ���ν����
	 *����IRL��SIU���Ф������ߥ�٥�
	 *����IEN=1��CPM����ߥ��͡��֥�
	 */
	mpc860_wrw_mem(CICR, CICR_IRL0 | CICR_IEN);

	/*  IPM�ν������CPM����ߤε���  */
	mpc860_wrh_mem(SIMASK, ENABLE_CPM);


	/*
	 *  �����ǡ����ν����
	 */

    	/* IPM�ơ��֥�ν���� */
    	for( j = 0; j < TMAX_EXCNO; j++ ) {
        	ipm_table[j] = DEFAULT_IPM;
    	}
    	
    	/*  CPM����ߤ�IPM������  */
    	ipm_table[INHNO_CPM] = IPM_CPM;
	
	/*
	 *  �ץ��å����̤Τ�����ѿ��ν����
	 */
	/*  ̤����  */
}

/*
 *  �������åȥ����ƥ�ν�λ
 */
void
sys_exit()
{
	tb6102s_exit();
}

/*
 *  �������åȥ����ƥ��ʸ������
 */
void
sys_putc(char c)
{
	if (c == '\n') {
		tb6102s_putc('\r');
	}
	tb6102s_putc(c);
}

/*
 * ��Ͽ����Ƥ��ʤ������ȯ�����Υ�����
 * �����ޥ���PROC_ICU����ǸƤӽФ����
 * �����ؿ�̾������η��ϥץ��å���˷����ɤ�
 *
 *     MPC860�Ǥϳ���ߥ���ȥ��餬������������³����Ƥ��뤿�ᡢ
 *���� �Ƴ���ߥ���ȥ�������Ѥδؿ����Ѱդ�����
 *
 */

/*  SIU����ߡ�CPM����߰ʳ���  */
void no_reg_SIU_interrupt(INHNO intno, UW *sp)
{
    syslog(LOG_EMERG, "SIU interrupt error occurs.");
    syslog(LOG_EMERG, "Interrupt No.=%d", intno);
    syslog(LOG_EMERG, "IPM=0x%04x", ((IPM_STACK *)sp)->ipm);

    /*  
     *  �����å���Υǡ�����ɽ��
     *    ����ߥޥ����򥹥��å����Ѥ�Ǥ���Τ�
     *��  ����ʬ�������åפ���
     */
    ++sp;
    syslog_data_on_stack((EXCSTACK *)sp);
    
    while(1);
}

/*  CPM�����  */
void no_reg_CPM_interrupt(INHNO intno, UW *sp)
{
    syslog(LOG_EMERG, "CPM interrupt error occurs.");
    syslog(LOG_EMERG, "Interrupt No.=%d(total %d)", 
           intno, intno + TMAX_SIU_INTNO);
    syslog(LOG_EMERG, "IPM=0x%04x", ((IPM_STACK *)sp)->ipm);

    /*  
     *  �����å���Υǡ�����ɽ��
     *    ����ߥޥ����򥹥��å����Ѥ�Ǥ���Τ�
     *��  ����ʬ�������åפ���
     */
    ++sp;
    syslog_data_on_stack((EXCSTACK *)sp);
    
    while(1);
}

/*  end of file  */
