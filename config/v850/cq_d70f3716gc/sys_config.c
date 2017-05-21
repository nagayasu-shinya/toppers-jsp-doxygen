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
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���D70F3716GC�ѡ�
 */

#include "jsp_kernel.h"

#include "hw_serial.h"


//void led(int num);

volatile unsigned int _serial_flag = 0;


/*  ���ꥢ��ݡ��Ȥ�����֥�å� */
SIOPCB siopcb_table[TNUM_PORT];

/*
 *  �������åȥ����ƥ��¸�ν����
 */
void
sys_initialize()
{
	volatile int i;

	/* LED �ݡ������� */
	sil_wrb_mem((VP)PMCCT, sil_reb_mem((VP)PMCCT) & (UB)~LED_BIT);
	sil_wrb_mem((VP)PMCT, sil_reb_mem((VP)PMCT) & (UB)~LED_BIT);

	sil_wrb_mem((VP)PCT, sil_reb_mem((VP)PCT) | (UB)LED_BIT);	/* LED off */

#if 0
	/* USB�ǥ��ꥢ���̿��򤹤�Ȥ��ˡ� */
	/* TOPPERS����ɽ�����뤿���wait������� */
	for(i=0; i<0x1000000; i++) ;
	led(1);
#endif
}

/*
 *  �������åȥ����ƥ�ν�λ
 */
void
sys_exit(void)
{
	kernel_abort();
}


#if 0
void
led(int num)
{
	volatile int i;
	int j;

	for(j=0; j<num; j++) {
		*((volatile UB *)PCT) &= (UB)~LED_BIT;
		for(i=0; i<0x40000; i++) ;
		*((volatile UB *)PCT) |= (UB)LED_BIT;
		for(i=0; i<0x40000; i++) ;
	}
}
#endif
