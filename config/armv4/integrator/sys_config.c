/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003      by Advanced Data Controls, Corp
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
 *  @(#) $Id: sys_config.c,v 1.1 2004/05/23 12:18:56 honda Exp $
 */

/*
 *    �������åȥ����ƥ��¸�⥸�塼���Integrator�ѡ�
 */

#include "jsp_kernel.h"
#include <integrator.h>


/*interrupt mask*/
UW int_mask_table[MAX_INT_NUM]={
    MASK_IRQ_SOFTINT,
    MASK_IRQ_UART0,
    MASK_IRQ_UART1,
    MASK_IRQ_KBDINT,
    MASK_IRQ_MOUSEINT,
    MASK_IRQ_TM0,
    MASK_IRQ_TM1,
    MASK_IRQ_TM2,
    MASK_IRQ_RTCINT,
    MASK_IRQ_EXPINT0,
    MASK_IRQ_EXPINT1,
    MASK_IRQ_EXPINT2,
    MASK_IRQ_EXPINT3,
    MASK_IRQ_PCIINT0,
    MASK_IRQ_PCIINT1,
    MASK_IRQ_PCIINT2,
    MASK_IRQ_PCIINT3,
    MASK_IRQ_LINT,
    MASK_IRQ_DEGINT,
    MASK_IRQ_ENUMINT,
    MASK_IRQ_PCILBINT,
    MASK_IRQ_EXTINT
};


/*
 * ����ߥϥ�ɥ���Ͽ�ѥơ��֥�
 */
FP   int_table[MAX_INT_NUM];

/*
 * OSC�ν����
 */
void
init_clock(){
    UW    reg;

    /* CM_OSC�Υ����å� */
    sil_wrw_mem((VP)CM_LOCK, LOCKVAL_UNLOCK);

    reg = sil_rew_mem((VP)CM_OSC);

    reg &= ~( LCLK_MASK | CORECLK_MASK);
    /* �١�������å� 50MHz CPU��������å� 133MHz������ */
    reg |= LCLK_50MHZ | CORECLK_133MHZ;

    sil_wrw_mem((VP)CM_OSC, reg);

    /* CM_OSC�Υ�å� */
    sil_wrw_mem((VP)CM_LOCK, LOCKVAL_LOCK);
}


/*
 *  ����ߴ�Ϣ�ν����
 */
void
init_IRQ(){
    int i;
    
    /* IRQ����߶ػ� */
    sil_wrw_mem((VP)IRQ0_ENABLECLR,INT_DISABLE_ALL);
    
    /*
     *  ����ߥơ��֥�ν����
     */
    for(i = 0; i < MAX_INT_NUM; i++){
        int_table[i] = 0x00;        /* �ꥻ�å� */   
    }
}


/*
 *  �������åȥ����ƥ��¸�ν����
 */
void
sys_initialize()
{
    int i;

    init_clock();

    init_IRQ();

    /*
     *  SSRAM �� 0x00000000�˥ޥåԥ�
     */
    sil_wrw_mem((VP)CM_CTRL,CM_CTRL_REMAP);

    /*
     *  ARM�Υ٥����ơ��֥�س���ߥϥ�ɥ����Ͽ
     */
    arm_install_handler(IRQ_Number,IRQ_Handler);
     
    /*
     *  sys_putc ����ǽ�ˤʤ�褦��UART������
     */
    init_uart();
}


/*
 *  �������åȥ����ƥ�ν�λ
 */
void
sys_exit(void)
{
    syslog(LOG_EMERG, "End Kernel.....!");
    while(1);
}


/*
 *  �������åȥ����ƥ��ʸ������
 */

void
sys_putc(char c)
{
    if (c == '\n') {
        uart_putc('\r');
    }
    uart_putc(c);
}


/*
 *  ����ߥϥ�ɥ������
 *
 *  ������ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 */
void
define_inh(INHNO inhno, FP inthdr)
{
    assert(inhno < MAX_INT_NUM);
    int_table[inhno] = inthdr;

}

/*
 *  ̤����γ���ߤ����ä����ν���
 */
void
undef_interrupt(){
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
    while(1);
}


/*IRQ�쥸���������ꥢ�����ޤ��Ԥ�*/
#define INT_CLEAR_DELAY  0x70
void poll_intreg(int int_mask)
{
    int i;
    
    //while(*IRQ0_ENABLESET & int_mask);
    for(i=0;i<INT_CLEAR_DELAY;i++);
    enaint();

}


