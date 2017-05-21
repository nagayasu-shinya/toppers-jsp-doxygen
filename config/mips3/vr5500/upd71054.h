/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 */

#ifndef _UPD71054_H_
#define _UPD71054_H_

#include <s_services.h>

/*
 *  ������ uPD71054(NEC) ��Ϣ�����
 */

/* uPD71054�Υ쥸�����Υ��ɥ쥹 */
#define PCNT0		0x00
#define PCNT1		0x10
#define PCNT2		0x20
#define PCNTL		0x30

/* control word foemat */
#define BINARY			0u	/* BIT0 */
#define BCD			BIT0

#define MODE_0			0u	/* BIT1, 2, 3 */
#define MODE_1			BIT1
#define MODE_2			BIT2
#define MODE_3			(BIT2 | BIT1)
#define MODE_4			BIT3
#define MODE_5			(BIT3 | BIT1)

#define COUNT_LATCH_COMM	0u	/* BIT5, 4 */
#define LOWER_BYTE		BIT4
#define HIGH_BYTE		BIT5
#define LOW_HIGH_BYTE		(BIT5 | BIT4)

#define COUNTER_0		0u	/* BIT6, 7 */
#define COUNTER_1		BIT6
#define COUNTER_2		BIT7
#define MULT_LATCH_COMM		(BIT7 | BIT6)

/* multiple latch command format */
#define SEL_COUNTER_0		BIT1
#define SEL_COUNTER_1		BIT2
#define SEL_COUNTER_2		BIT3
#define DO_NOT_LATCH_STATUS	BIT4
#define LATCH_STATUS		0u	/* BIT4 */
#define DO_NOT_LATCH_COUNT	BIT5
#define LATCH_COUNT		0u	/* BIT5 */

/*
 *  �����ޤΥ쥸�����ؤΥ��������ؿ�
 */
#define upd71054_reb( addr )		sil_reb_mem( (VP)(TIMER_BASE_ADDR + addr) )
#define upd71054_wrb( addr, val )	sil_wrb_mem( (VP)(TIMER_BASE_ADDR + addr), val )

#endif /* _UPD71054_H_ */
