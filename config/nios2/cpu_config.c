/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
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
 *  @(#) $Id: cpu_config.c,v 1.3 2004/09/03 17:32:25 honda Exp $
 */

/*
 *  �ץ��å���¸�⥸�塼���Nios2�ѡ�
 */
#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <nios2.h>

/*
 * �����ߥϥ�ɥ�/�ӥåȥޥ����ơ��֥�
 */
FP  int_handler_table[MAX_INT_NUM];
UW  int_bit_table[MAX_INT_NUM];

/*
 * CPU�㳰�ϥ�ɥ�ơ��֥�
 */
FP	exc_handler_table[MAX_EXC_NUM]; 

/*
 * �����ߤΥͥ��Ȳ���Υ������
 * �����ͥ뵯ư���ϥ�������Ω���Ȥߤʤ�����1�ǽ��������
 */
UW interrupt_count = 1;

/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize()
{
    int i;
    
    /*
     * int_handler_table[],int_plevel_table[]�ν����
     * ̤��Ͽ�γ����ȯ������cpu_interrup()���ƤӽФ����褦��
     * no_reg_interrup()����Ͽ����
     */
    for(i = 0; i < MAX_INT_NUM; i++){
        int_handler_table[i] = no_reg_interrupt;
        int_bit_table[i]  = 1 << i; /* �ӥåȥѥ���������� */
    }

    /*
     *  CPU�㳰�ϥ�ɥ�ơ��֥�
     */
    for(i = 0; i < MAX_EXC_NUM; i++){
        exc_handler_table[i] = no_reg_exception; 
    }
}

/*
 *  �ץ��å���¸�ν�λ����
 *  ����߶ػ�
 */
void
cpu_terminate()
{
    disint();
}


/*
 * ����ߤε���/�ػ�
 */
SYSCALL ER
ena_int(INTNO intno){
    set_ienable((1 << intno) | current_ienable()); 
}

SYSCALL ER
dis_int(INTNO intno){
    set_ienable(~(1 << intno) & current_ienable());    
}


/*
 * ̤��Ͽ�γ���ߤ�ȯ���������˸ƤӽФ����
 */
void
no_reg_interrupt(void)
{
    syslog(LOG_EMERG, "Unregisted Interrupt Occur!");
    while(1);
}

/*
 * ̤��Ͽ���㳰��ȯ���������˸ƤӽФ����
 */
void
no_reg_exception(void)
{
    syslog(LOG_EMERG, "Unregisted Exception Occur!");
    while(1);    
}

/*
 * ������װ���Ƚ��ȳ���ߥϥ�ɥ�θƤӽФ�
 */
void
int_handler_call(){
    UW status;
    UW mask;
    int i;
    
    interrupt_count++;
    status = current_ipending();
    for(i = 0; i < 32; i++){
        if((status & (1 << i)) != 0x00){
            mask = current_ienable();
            set_ienable(~int_bit_table[i] & mask);
            
            enaint();
            (int_handler_table[i])();
            disint();
            
            set_ienable(mask);
            break;
        }
    }
    interrupt_count--;    
}

/*
 *  �㳰��Ƚ���CPU�㳰�ϥ�ɥ�θƤӽФ�
 *  ���ߤ�̤����̿���㳰�Τߤ򥵥ݡ��� 
 */
void
exc_handler_call(VP p_excinf){
    interrupt_count++;

    enaint();
    (exc_handler_table[0])(p_excinf);
    disint();
    
    interrupt_count--;    
}
