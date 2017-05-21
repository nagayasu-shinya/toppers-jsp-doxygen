/*
 *  TOPPERS/JSP Rose-RT Link Programs
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by CHUO ELECTRIC WORKS Co.,LTD. JAPAN
 * 
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ��� 
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ����(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ�������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 */
/*
 *  (��)������������ITRON���SH1CPU�ܡ�����
 *  LED,SW ����ؿ�
 */
#include <s_services.h>
#include <sh1_sil.h>
#include "zunda_sh1.h"
#include "device.h"

/*
 *  LED�ν����
 */
void
initial_led(void)
{
	set_led( LED1, OFF );
	set_led( LED2, OFF );
	set_led( LED3, OFF );
}

/*
 *  LED�������Ԥ�
 *  arg1: LED1 - 3
 *  arg2: ON|OFF
 */
void
set_led( int led, int req )
{
	if ( req != ON && req != OFF ) {
		return;
	}
	
	switch ( led ) {
	case LED1:
		if( req == OFF ) {
			sh1_orh_reg( PA_DR, LED_CTL1 );
		} else {
			sh1_anh_reg( PA_DR, ~LED_CTL1 );
		}
		break;
	case LED2:
		if( req == OFF ) {
			sh1_orh_reg( PB_DR, LED_CTL2 );
		} else {
			sh1_anh_reg( PB_DR, ~LED_CTL2 );
		}
		break;
	case LED3:
		if( req == OFF ) {
			sh1_orh_reg( PB_DR, LED_CTL3 );
		} else {
			sh1_anh_reg( PB_DR, ~LED_CTL3 );
		}
		break;
	default:
		break;
	}
}

/*
 *  LED�ξ��ּ���
 *  arg1: LED1 - 3
 */
int
get_led( int led )
{
	switch ( led ) {
	case LED1:
		if ( (sil_reh_mem( PA_DR ) & LED_CTL1) == 0 ) {
			return ON;
		}
		break;
	case LED2:
		if ( (sil_reh_mem( PB_DR ) & LED_CTL2) == 0 ) {
			return ON;
		}
		break;
	case LED3:
		if ( (sil_reh_mem( PB_DR ) & LED_CTL3) == 0 ) {
			return ON;
		}
		break;
	default:
		break;
	}
	return OFF;
}

/*
 *  �ǥ��åץ����å��ξ��ּ���
 *  return:ON OFF
 *  arg1:DSW11 �� DSW14
 */
int
get_dsw( int sw )
{
	UH	key = 0;
	int	result = OFF;

	key = sil_reh_mem( SW_DR );
	switch ( sw ) {
	case DSW11:
		if ((key & DSW11) == 0 ) {
			result = ON;
		}
		break;
	case DSW12:
		if ((key & DSW12) == 0 ) {
			result = ON;
		}
		break;
	case DSW13:
		if ((key & DSW13) == 0 ) {
			result = ON;
		}
		break;
	case DSW14:
		if ((key & DSW14) == 0 ) {
			result = ON;
		}
		break;
	default:
		break;
	}
	return result;
}

/*
 *  �����꡼�����å����ͼ���
 *  return:�����å�����
 */
int
get_rsw(void)
{
	return (sil_reh_mem( SW_DR ) & RSW_CTL);
}

