/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2006 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2006 by Logic Research Co., Ltd.
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
 */

/*
 *    �������åȥ����ƥ��¸�⥸�塼���FRK_ADuC�ѡ�
 */

#include "jsp_kernel.h"
#include "frk_aduc.h"


/*interrupt mask*/
const UW int_mask_table[MAX_INT_NUM]={
	MASK_ALL_INT,
	MASK_IRQ_SWI,
	MASK_IRQ_TIMER0,
	MASK_IRQ_TIMER1,
	MASK_IRQ_TIMER2,
	MASK_IRQ_TIMER3,
	MASK_IRQ_FLA_CTRL,
	MASK_IRQ_ADC_CH,
	MASK_IRQ_PLL_LOCK,
	MASK_IRQ_I2C0_SLV,
	MASK_IRQ_I2C0_MST,
	MASK_IRQ_I2C1_MST,
	MASK_IRQ_SPI_SLV,
	MASK_IRQ_SPI_MST,
	MASK_IRQ_UART,
	MASK_IRQ_EXT_IRQ0,
	MASK_IRQ_COMP,
	MASK_IRQ_PSM,
	MASK_IRQ_EXT_IRQ1,
	MASK_IRQ_PLA_IRQ0,
	MASK_IRQ_PLA_IRQ1,
	MASK_IRQ_EXT_IRQ2,
	MASK_IRQ_EXT_IRQ3,
	MASK_IRQ_PWM_TRIP
};


/*
 * ����ߥϥ�ɥ���Ͽ�ѥơ��֥�
 */
FP   int_table[MAX_INT_NUM];


/*
 * OSC�ν����
 */
void
init_clock(void)
{
    UW    reg;

    /* POWCON key1 */
    sil_wrw_mem((VP)POWKEY1, POWKEY1_DATA);

    /* Core Clock 41.78MHz , Active mode*/
    reg = (POWCON_PC_ACT | POWCON_CD_41M);
    sil_wrw_mem((VP)POWCON, reg);

    /* POWCON key2 */
    sil_wrw_mem((VP)POWKEY2, POWKEY2_DATA);
}


/*
 * GPIO�ν����
 */
void
init_gpio(void)
{
	/* LED port */
	sil_wrw_mem((VP)GP4CON, 0);			/* GPIO mode */
	sil_wrw_mem((VP)GP4DAT, P47_DIR);	/* Output */
	sil_wrw_mem((VP)GP4SET, LED);		/* LED off */

	/* UART port */
	sil_wrw_mem((VP)GP0CON, GP07_SIN);
	sil_wrw_mem((VP)GP1CON, (GP10_SIN|GP11_SOUT|GP12_RTS|
							 GP13_CTS|GP14_RI|GP15_DCD|
							 GP16_DSR|GP17_DTR));
	sil_wrw_mem((VP)GP2CON, GP20_SOUT);

}


/*
 *  ����ߴ�Ϣ�ν����
 */
void
init_IRQ(void)
{
    int i;
    
    /* IRQ����߶ػ� */
    sil_wrw_mem((VP)IRQCLR, INT_DISABLE_ALL);
    
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

	init_gpio();

    init_IRQ();

	/*
	 * SRAM
	 */
    for(i = 0; i <=7; i++){
        arm_vector_add[i] = arm_vector_add[i] + VCT_TB_SRAM/4;
    }

  	for(i=0; i <=14; i++) {
		*((volatile UW *)VCT_TB_SRAM + i) = *((volatile UW *)VCT_TB + i);
	}

 	sil_wrw_mem((VP)REMAP, REMAP_SRAM);

    /*
     *  ARM�Υ٥����ơ��֥�س���ߥϥ�ɥ����Ͽ
     */
    arm_install_handler(IRQ_Number, IRQ_Handler);

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
    
    //while(*IRQEN & int_mask);
    for(i=0;i<INT_CLEAR_DELAY;i++);
    enaint();

}

