/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005-2007 by Y.D.K.Co.,LTD Technologies company
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
 *  @(#) $Id: sys_config.c,v 1.2 2007/05/21 01:33:50 honda Exp $
 */

/*
 *    �������åȥ����ƥ��¸�⥸�塼��
 */

#include "jsp_kernel.h"
#include <ns9360.h>


/*
 * GPIO Setup 
 */
static void	cpuSetupGPIO(void);
/*
 * CS0 Setup
 */
static void	cpuSetupCS0(void);
/*
 * CS2 Setup
 */
static void	cpuSetupCS2(void);
/*
 * CS3 Setup
 */
static void	cpuSetupCS3(void);
/*
 * CS5 Setup
 */
static void	cpuSetupCS5(void);
/*
 * CS6 Setup
 */
static void	cpuSetupCS6(void);
/*
 * CS7 Setup
 */
static void	cpuSetupCS7(void);


/*
 * ����ߥϥ�ɥ���Ͽ�ѥơ��֥�
 */
FP   int_table[MAX_INT_NUM];
UW   int_mask_table[MAX_INT_NUM];

/*
 * IRQ��INT ID���б��ơ��֥롢IRQ���б�����INT ID�����ꤹ�롣
 * ���Υơ��֥�Υǡ������顢IntConfigRegistar�����ꤹ�롣
 * ̤���Ѥ�IRQ�ˤ�INT_ID_NONE�򥻥åȤ���
 */
const	UW	int_id_table[] = {
	INT_ID_NONE,			/* IRQ0 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ1 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ2 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ3 INT ID  : unuse							*/
	INT_ID_TIMER0,			/* IRQ4 INT ID  : TIMER 0 Interrupt				*/
	INT_ID_NONE,			/* IRQ5 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ6 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ7 INT ID  : unuse							*/
	INT_ID_BBUS_INT,		/* IRQ8 INT ID  : BBus Aggregate Interrupt		*/
	INT_ID_NONE,			/* IRQ9 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ10 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ11 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ12 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ13 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ14 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ15 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ16 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ17 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ18 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ19 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ20 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ21 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ22 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ23 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ24 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ25 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ26 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ27 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ28 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ29 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ30 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ31 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ32 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ33 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ34 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ35 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ36 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ37 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ38 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ39 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ40 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ41 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ42 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ43 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ44 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ45 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ46 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ47 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ48 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ49 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ50 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ51 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ52 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ53 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ54 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ55 INT ID : unuse							*/
	INT_ID_SERC_TX,			/* IRQ56 INT ID : SER C Tx Interrupt			*/
	INT_ID_SERC_RX,			/* IRQ57 INT ID : SER C Rx Interrupt			*/
	INT_ID_SERA_TX,			/* IRQ58 INT ID : SER A Tx Interrupt			*/
	INT_ID_SERA_RX,			/* IRQ59 INT ID : SER A Rx Interrupt			*/
	INT_ID_NONE,			/* IRQ60 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ61 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ62 INT ID : unuse							*/
	INT_ID_NONE				/* IRQ63 INT ID : unuse							*/
};


/*--- GPIO ������� ---*/
/*
 **** Control Registers ****
 */
/* Control Registers #1 (GPIO[0]��[31]) */
const	UW	BbusGpio_ContSts1 = (BBUS_GPIO_CONT_STS1_GPIO2 | BBUS_GPIO_CONT_STS1_GPIO16);

/* Control Registers #2 (GPIO[32]��[63]) */
const	UW	BbusGpio_ContSts2 = (BBUS_GPIO_CONT_STS2_GPIO36 | BBUS_GPIO_CONT_STS2_GPIO37 
                                            | BBUS_GPIO_CONT_STS2_GPIO38 | BBUS_GPIO_CONT_STS2_GPIO39);
	
/* Control Registers #3 (GPIO[64]��[72]) */
const	UW	BbusGpio_ContSts3 = 0;

/*
 **** Configration Registers ****
 */

/* Configration Registers #1 (GPIO[0]��[7]) */
const	UW	BbusGpio_Config1 = (BBUS_GPIO_CONFIG1_GPIO0 | BBUS_GPIO_CONFIG1_GPIO1
                              | BBUS_GPIO_CONFIG1_GPIO2 | BBUS_GPIO_CONFIG1_GPIO3
                              | BBUS_GPIO_CONFIG1_GPIO4 | BBUS_GPIO_CONFIG1_GPIO5
                              | BBUS_GPIO_CONFIG1_GPIO6 | BBUS_GPIO_CONFIG1_GPIO7);

/* Configration Registers #2 (GPIO[8]��[15]) */
const	UW	BbusGpio_Config2 = (BBUS_GPIO_CONFIG2_GPIO8 | BBUS_GPIO_CONFIG2_GPIO9
                              | BBUS_GPIO_CONFIG2_GPIO10 | BBUS_GPIO_CONFIG2_GPIO11
                              | BBUS_GPIO_CONFIG2_GPIO12 | BBUS_GPIO_CONFIG2_GPIO13
                              | BBUS_GPIO_CONFIG2_GPIO14 | BBUS_GPIO_CONFIG2_GPIO15);

/* Configration Registers #3 (GPIO[16]��[23]) */
const	UW	BbusGpio_Config3 = (BBUS_GPIO_CONFIG3_GPIO16 | BBUS_GPIO_CONFIG3_GPIO17
                              | BBUS_GPIO_CONFIG3_GPIO18 | BBUS_GPIO_CONFIG3_GPIO19
                              | BBUS_GPIO_CONFIG3_GPIO20 | BBUS_GPIO_CONFIG3_GPIO21
                              | BBUS_GPIO_CONFIG3_GPIO22 | BBUS_GPIO_CONFIG3_GPIO23);

/* Configration Registers #4 (GPIO[24]��[31]) */
const	UW	BbusGpio_Config4 = (BBUS_GPIO_CONFIG4_GPIO24 | BBUS_GPIO_CONFIG4_GPIO25
                              | BBUS_GPIO_CONFIG4_GPIO26 | BBUS_GPIO_CONFIG4_GPIO27
                              | BBUS_GPIO_CONFIG4_GPIO28 | BBUS_GPIO_CONFIG4_GPIO29
                              | BBUS_GPIO_CONFIG4_GPIO30 | BBUS_GPIO_CONFIG4_GPIO31);

/* Configration Registers #5 (GPIO[32]��[39]) */
const	UW	BbusGpio_Config5 = (BBUS_GPIO_CONFIG5_GPIO32 | BBUS_GPIO_CONFIG5_GPIO33
                              | BBUS_GPIO_CONFIG5_GPIO34 | BBUS_GPIO_CONFIG5_GPIO35
                              | BBUS_GPIO_CONFIG5_GPIO36 | BBUS_GPIO_CONFIG5_GPIO37
                              | BBUS_GPIO_CONFIG5_GPIO38 | BBUS_GPIO_CONFIG5_GPIO39);

/* Configration Registers #6 (GPIO[40]��[47]) */
const	UW	BbusGpio_Config6 = (BBUS_GPIO_CONFIG6_GPIO40 | BBUS_GPIO_CONFIG6_GPIO41
                              | BBUS_GPIO_CONFIG6_GPIO42 | BBUS_GPIO_CONFIG6_GPIO43
                              | BBUS_GPIO_CONFIG6_GPIO44 | BBUS_GPIO_CONFIG6_GPIO45
                              | BBUS_GPIO_CONFIG6_GPIO46 | BBUS_GPIO_CONFIG6_GPIO47);

/* Configration Registers #7 (GPIO[48]��[55]) */
const	UW	BbusGpio_Config7 = (BBUS_GPIO_CONFIG7_GPIO48 | BBUS_GPIO_CONFIG7_GPIO49
                              | BBUS_GPIO_CONFIG7_GPIO50 | BBUS_GPIO_CONFIG7_GPIO51
                              | BBUS_GPIO_CONFIG7_GPIO52 | BBUS_GPIO_CONFIG7_GPIO53
                              | BBUS_GPIO_CONFIG7_GPIO54 | BBUS_GPIO_CONFIG7_GPIO55);

/* Configration Registers #8 (GPIO[56]��[63]) */
const	UW	BbusGpio_Config8 = (BBUS_GPIO_CONFIG8_GPIO56 | BBUS_GPIO_CONFIG8_GPIO57
                              | BBUS_GPIO_CONFIG8_GPIO58 | BBUS_GPIO_CONFIG8_GPIO59
                              | BBUS_GPIO_CONFIG8_GPIO60 | BBUS_GPIO_CONFIG8_GPIO61
                              | BBUS_GPIO_CONFIG8_GPIO62 | BBUS_GPIO_CONFIG8_GPIO63);

/* Configration Registers #9 (GPIO[64]��[71]) */
const	UW	BbusGpio_Config9 = (BBUS_GPIO_CONFIG9_GPIO64 | BBUS_GPIO_CONFIG9_GPIO65
                              | BBUS_GPIO_CONFIG9_GPIO66 | BBUS_GPIO_CONFIG9_GPIO67
                              | BBUS_GPIO_CONFIG9_GPIO68 | BBUS_GPIO_CONFIG9_GPIO69
                              | BBUS_GPIO_CONFIG9_GPIO70 | BBUS_GPIO_CONFIG9_GPIO71);

/* Configration Registers #10 (GPIO[72]) */
const	UW	BbusGpio_Config10 = (BBUS_GPIO_CONFIG10_GPIO72);


/*
 *  �������åȥ����ƥ��¸�ν����
 */
void
sys_initialize()
{
    /*
     *  ARM�Υ٥����ơ��֥�س���ߥϥ�ɥ����Ͽ
     */
    arm_install_handler(IRQ_Number,IRQ_Handler);
  
    /*
     *  sys_putc ����ǽ�ˤʤ�褦��UART������
     */
    uart_init(LOGTASK_PORTID);
    /*
     * BBus�γ���ߵ���
     */
     sil_wrw_mem((VP)BBBIE_REG, sil_rew_mem((VP)BBBIE_REG) | BBBI_GLBL);
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
	VW	reg;
	
    assert(inhno < MAX_INT_NUM);
    int_table[inhno] = inthdr;
    
    if(INT_ID_BBUS_F > inhno)
    {
		/*
		 * BBusBridge��ͳ�ǤϤʤ�����ߤ���Ͽ
		 */
	    sil_wrw_mem((VP)(IVARV_REG+inhno*4),(VW)inthdr);     /* Interruput Vector Reg ������ */
	    
	    /* IntConfigReg������ */
	    reg = sil_rew_mem((VP)((INT_CONFIG_REG+inhno)&0xfffffffc));
	    reg &= ~(0xff000000 >> (inhno%4)*8);
	    reg |= ((int_id_table[inhno] | INT_CFG_BIT_IT)<<24) >> ((inhno%4)*8);
	    sil_wrw_mem((VP)((INT_CONFIG_REG+inhno)&0xfffffffc), reg);
	}
}


/*
 * ����ߥϥ�ɥ鵯ư���˳���ߥ���ȥ��顼�˥��åȤ���ޥ����ͤ����ꡥ
 */
void
define_inh_mask(INHNO inhno, UW mask)
{
    assert(inhno < MAX_INT_NUM);
    int_mask_table[inhno] = mask;
}


/*
 *  ̤����γ���ߤ����ä����ν���
 */
void
undef_interrupt(){
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
    while(1);
}

/*
 *  BBus����ߥ����ӥ��롼����
 */
void
BBus_isr()
{
	UW	i;
	UW	int_sts;
	
	int_sts = sil_rew_mem((VP)(BBBIS_REG)) & BBBIS_MASK;
	for( i = INT_ID_BBUS_F ; i < MAX_INT_NUM ; ++i )
	{
		if(int_sts & 0x80000000)
		{
			if(0 == int_table[i])
			{
				 undef_interrupt();
			}
			else
			{
				int_table[i]();
			}
		}
		int_sts <<= 1;
	}
}

/*
 *  CS��GPIO����
 */
void cpu_CsGpioInit(void)
{
    BOOL    debugger, software_restart;
	software_restart = 0;
        cpuSetupGPIO();
		*(UW*)(BBUS_GPIO_CONT1_REG) |= 0x10;

	
    /* �ꥹ�����ȥե饰�μ��������å� */
    software_restart = ((~AHB_ABT_CFG_REG_restart) & sil_rew_mem((VP)AHB_ABT_CFG_REG));
    														/* Restart Flag get		*/
	
	sil_wrw_mem((VP)AHB_ABT_CFG_REG , (AHB_ABT_CFG_REG_restart | sil_rew_mem((VP)AHB_ABT_CFG_REG)));
															/* Restart Flag set	*/

	
    /* �ǥХå��ե饰�μ��� */
    debugger = ((~AHB_ABT_CFG_REG_debug) & sil_rew_mem((VP)AHB_ABT_CFG_REG));	/* Debug Flag get */
 
    if (!software_restart)
    {
        /* Setup the GPIO ports. */
        cpuSetupGPIO();

		*(UW*)(BBUS_GPIO_CONT1_REG) |= 0x10;

		/* Enable Instruction Cache */
		cpuEnableICache();

        /* Setup the Static chip selects */
        cpuSetupCS0();							/* CS0 setup 			*/
        cpuSetupCS2();							/* CS2 setup 			*/
        cpuSetupCS3();							/* CS3 setup 			*/

        /* Setup the Dynamic chip selects */
        cpuSetupCS5();							/* CS5 setup 			*/
        cpuSetupCS6();							/* CS6 setup 			*/
        cpuSetupCS7();							/* CS7 setup 			*/

    }
    else
    {
        /* Setup the GPIO ports. */
        cpuSetupGPIO();
        ;
        cpuEnableICache();
    }
    return;
}


/*
 * CS0 Setup
 */
static void	cpuSetupCS0(void)
{
	/*
	 * �������åȤ˹�碌�ƽ���������򵭽Ҥ���
	 * Boot�������ˤ�����Ѥߤξ�硢�����Ǥ����������
	 */
}
/*
 * CS2 Setup
 */
static void	cpuSetupCS2(void)
{
	/*
	 * �������åȤ˹�碌�ƽ���������򵭽Ҥ���
	 * Boot�������ˤ�����Ѥߤξ�硢�����Ǥ����������
	 */
}
/*
 * CS3 Setup
 */
static void	cpuSetupCS3(void)
{
	/*
	 * �������åȤ˹�碌�ƽ���������򵭽Ҥ���
	 * Boot�������ˤ�����Ѥߤξ�硢�����Ǥ����������
	 */
}
/*
 * CS5 Setup
 */
static void	cpuSetupCS5(void)
{
	/*
	 * �������åȤ˹�碌�ƽ���������򵭽Ҥ���
	 * Boot�������ˤ�����Ѥߤξ�硢�����Ǥ����������
	 */
}
/*
 * CS6 Setup
 */
static void	cpuSetupCS6(void)
{
	/*
	 * �������åȤ˹�碌�ƽ���������򵭽Ҥ���
	 * Boot�������ˤ�����Ѥߤξ�硢�����Ǥ����������
	 */
}
/*
 * CS7 Setup
 */
static void	cpuSetupCS7(void)
{
	/*
	 * �������åȤ˹�碌�ƽ���������򵭽Ҥ���
	 * Boot�������ˤ�����Ѥߤξ�硢�����Ǥ����������
	 */
}

/*
 * GPIO Setup 
 */
static void	cpuSetupGPIO(void)
{
	UW config;

	/*
	 **** Control Registers ****
	 */
	/* ����pin��GPIO���Ϥ����ꤷ�����˥ǥե���Ƚ��Ϥ���ꤷ�������˰ʲ��򵭽Ҥ��� */
	
	/* Control Registers #1 (GPIO[0]��[31]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONT1_REG , BbusGpio_ContSts1);

	/* Control Registers #2 (GPIO[32]��[63]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONT2_REG , BbusGpio_ContSts2);
	
	/* Control Registers #3 (GPIO[64]��[72]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONT3_REG , BbusGpio_ContSts3);

	/*
	 **** Configration Registers ****
	 */
	/* Configration Registers #1 (GPIO[0]��[7]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG1_REG , BbusGpio_Config1);

	/* Configration Registers #2 (GPIO[8]��[15]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG2_REG , BbusGpio_Config2);

	/* Configration Registers #3 (GPIO[16]��[23]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG3_REG , BbusGpio_Config3);

	/* Configration Registers #4 (GPIO[24]��[31]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG4_REG , BbusGpio_Config4);

	/* Configration Registers #5 (GPIO[32]��[39]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG5_REG , BbusGpio_Config5);

	/* Configration Registers #6 (GPIO[40]��[47]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG6_REG , BbusGpio_Config6);

	/* Configration Registers #7 (GPIO[48]��[55]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG7_REG , BbusGpio_Config7);

	/* Configration Registers #8 (GPIO[56]��[63]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG8_REG , BbusGpio_Config8);

	/* Configration Registers #9 (GPIO[64]��[71]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG9_REG , BbusGpio_Config9);

	/* Configration Registers #10 (GPIO[72]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG10_REG , BbusGpio_Config10);
}


