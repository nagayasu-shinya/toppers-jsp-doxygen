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
 *                2009 by Suikan
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
 *    �������åȥ����ƥ��¸�⥸�塼���CQ-FRK-NXP-ARM��
 */

#include "jsp_kernel.h"
#include <lpc2388.h>

/*
 *  ������ѤΥơ��֥�
 */
#define VICVectAddress ((volatile FP **)0xFFFFF100)




/*
 *  ����ߴ�Ϣ�ν����(LPC2388����)
 */
void
init_IRQ()
{
	int i;

	for( i=0; i<32; i++ )
		VICVectAddress[i] = (volatile FP *)undef_interrupt;
}

extern unsigned int __data_start;

/*
 * LPC2388��SRAM�ΰ��FLASH�Υ٥��ȥ�򥳥ԡ�����
 * ��ޥåפ��롣LPC2388���̤�ɬ�ס�
 */
void
init_vector()
{
	unsigned char *flash, *sram;
	int i;

		/* ROM�������ɤ�SRAM���ư�������ɤǤϡ��㳰�٥��ȥ�ΰ������㤦��
		 * ROM��������ϡ�SRAM REMAP������Flash ROM����㳰�٥��ȥ���ͤ�
		 * SRAM��Υ�ޥå��ΰ�˰ܤ��ʤ���Фʤ�ʤ���������SRAM���ư���
		 * ���ϡ���ޥå��ΰ�ؤϥǥХå�������ͤ�񤭹��ࡣ
		 * ���Τ��ᡢ��ޥå��ΰ�ν������礬ɬ�פ��ݤ���Ƚ�̤�Ԥ���Ƚ�̤�
		 * __data_start���ͤ�Ȥ��������ͤ�lpc2388_sram.ld�����0�˽��������
		 * ���롣lpc2388.ld����Ǥ��󥼥�Υ��ɥ쥹����������롣�������äơ�
		 * ��ޥå��ΰ�ν������__data_start���󥼥�ΤȤ������Ԥ��� */
	if ( __data_start != 0 )
	{
		flash =(unsigned char*) 0;				/* FLASH����Ƭ���ɥ쥹 */
		sram = (unsigned char*) 0x40000000;	/* SRAM����Ƭ���ɥ쥹 */

			/* FLASH����Ƭ64�Х��Ȥ�SRAM�˥��ԡ� */
		for (i=0; i<64; i++)
		{
			*sram = *flash;
			sram++;
			flash++;
		}
	}
		/* SRAM ��٥��ȥ륨�ꥢ�˥�ޥåפ��� */
	MEMMAP = 0x02;
}

/*
 * LPC2388��¸��UART������롼����sys_putc()�Ѥ�uart0���������롣
 */
#define	DLAB 0x80
void
init_uart0()
{
    /*
     *  ʬ���������
     */
    /* Divisor Enable */
	U0LCR |= DLAB;
    U0DLL = UART0_DIVISOR & 0xFF ;
    U0DLM = UART0_DIVISOR >> 8;
    /* Divisor Disable */
    U0LCR &= ~DLAB;

    /* �⡼������, �ѥ�ƥ�̵�� 8bit data, 1 stop bit */
    U0LCR = 0x03;

    /* ����߶ػ� */
    U0IER = 0;
}

/*
 *  �����ƥཪλ�եå����ե����०�����˥����ƥཪλAPI������ʤ�
 *  �����Ƥ֤Ȥ褤��
 */
void
sys_exit()
{
	while(1)
		;
}



/*
 *  �������åȥ����ƥ��ʸ�����ϡ�syslog����������ư�������˥ץ��Ȥ�Ԥ������
 *  �롼����Ǥ��ꡢ�����Ǥϥݡ���󥰤�ԤäƤ��롣LF���椬�����Ƥ����顢
 *  CR LF���Ѵ����ƥץ��Ȥ��롣sys_putc�ϥǥХ������������ʤ���
 *  �������kernel_start()����ǽ���äƤ���Ȳ��ꤷ�Ƥ��롣
 */

void
sys_putc(char c)
{
	if ( c== 0x0A )			/* �⤷ LF �ʤ�� */
		sys_putc( 0x0D );	/* CR���ʸ������ */

	while( !( U0LSR & (1<<5)) )
		;		/* UART0 LSR��THRE��1�ˤʤ�ޤ��Ԥġ�1�ʤ�������쥸����������*/

	U0THR = c;	/* ��ʸ������ */
}


/*
 *  ����ߥϥ�ɥ������
 *
 *  ������ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 *  VICVectAddress[]��Ʊ̾�Υ쥸������˥ޥåפ���Ƥ��롣�������äơ�
 *  define_inh��Ƥ֤ȡ�VICVectAddressX�쥸���������������롣
 */
void
define_inh(INHNO inhno, FP inthdr)
{
    assert(inhno <= MAX_INT_NUM);
    VICVectAddress[inhno] = (volatile FP*)inthdr;

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
 * �����ߤΥ��͡��֥롢�ǥ������֥�
 */
/*
 * intno�Ǥ���蘆�������ߤ��ǥ������֥�ˤʤ롣
 */
ER dis_int(INTNO intno)
{
	if ( intno > MAX_INT_NUM )
		return E_PAR;
	VICIntEnClr = 1<<intno;
	return 0;
}

/*
 * intno�Ǥ���蘆�������ߤ����͡��֥�ˤʤ롣
 */
ER ena_int(INTNO intno)
{
	if ( intno > MAX_INT_NUM )
		return E_PAR;
	VICIntEnable = 1<<intno;
	return 0;
}

/*
 * �����ߥ��͡��֥�ޥ�������ꤹ�롣�ޥ�����VICIntEnable�����������
 */
ER chg_ims(unsigned int enableMask)
{
	VICIntEnClr = 0xFFFFFFFF;
	VICIntEnable = enableMask;
	return 0;
}

/*
 * �����ߥ��͡��֥�ޥ����������
 */
ER get_ims(unsigned int *p_enableMask)
{
	*p_enableMask = VICIntEnable;
	return 0;
}


