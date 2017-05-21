/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2010 by Witz Corporation, JAPAN
 * 
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 * 
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 * 
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 * 
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 * 
 *    (a) The above copyright notice, this use conditions, and the
 *           disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 * 
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 * 
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�
 *  �����ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭�����
 *      ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ�����
 *      ��������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ����Ѽԥ�
 *      �˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ�����̵��
 *      �ڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ���
 *        �𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»��
 *      ����⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ��ޤ���
 *      �ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���ͳ�˴��
 *      �����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ���
 *  ��TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū���Ф�
 *  ��Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ�����������
 *  �ˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ����
 *  ��ʤ���
 * 
 *  @(#) $Id: hw_timer.h,v 1.1 2006/04/10 08:19:25 honda Exp $
 */

/*
 *	�����ޥɥ饤�С�Zup-F16��ĥ�ܡ����ѡ�
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include <sil.h>
#include <tmp91cy22.h>

/*
 *  �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define	INHNO_TIMER		INT_NO_TA0

/*
 *  �����ޡ��γ����ߥ�٥�
 */
#define INT_LEVEL_TIMER	0x04

#ifndef _MACRO_ONLY

/*
 *  1ms�Υ����ޡ������ߤ���Ѥ���ΤǤ��Υ���å���������롥
 */
#define TIMER_CLOCK		192


/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
#pragma inline hw_timer_initialize
void
hw_timer_initialize()
{
	/* ������0���	*/
	sil_wrb_mem((VP)TADR_SFR_TA01RUN,
		(VB)(sil_reb_mem((VP)TADR_SFR_TA01RUN) & ~TBIT_TA0RUN));
	/* �⡼������	 IDLE2:ư��,8bit�⡼��,����������å�/16,1ms	*/
	sil_wrb_mem((VP)TADR_SFR_TA01RUN,
		(sil_reb_mem((VP)TADR_SFR_TA01RUN) | TBIT_I2TA01));
	sil_wrb_mem((VP)TADR_SFR_TA01MOD,
		(sil_reb_mem((VP)TADR_SFR_TA01MOD) | TBIT_TA0CLK16));
	sil_wrb_mem((VP)TADR_SFR_TA0REG, (VB)(TIMER_CLOCK - 1) );
	/* ���������	������׵᥯�ꥢ,����ߥ�٥�5	*/
	sil_wrb_mem((VP)TADR_SFR_INTCLR, TBIT_TA0_CLR );
	sil_wrb_mem((VP)TADR_SFR_INTETA01,
		(VB)((sil_reb_mem((VP)TADR_SFR_INTETA01) & ~TBIT_INTM_L) | INT_LEVEL_TIMER));
	/* ������0����ӥץꥹ�����鵯ư	*/
	sil_wrb_mem((VP)TADR_SFR_TA01RUN,
		(VB)(sil_reb_mem((VP)TADR_SFR_TA01RUN) | (TBIT_TA01PRUN | TBIT_TA0RUN)));
}

/*
 *  �����޳�����׵�Υ��ꥢ
 */
#pragma inline hw_timer_int_clear
void
hw_timer_int_clear()
{
	/* ������׵᥯�ꥢ	*/
	sil_wrb_mem((VP)TADR_SFR_INTCLR, TBIT_TA0_CLR );
}

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
#pragma inline hw_timer_terminate
void
hw_timer_terminate()
{
	/* ������0���	*/
	sil_wrb_mem((VP)TADR_SFR_TA01RUN,
		(VB)(sil_reb_mem((VP)TADR_SFR_TA01RUN) & ~TBIT_TA0RUN));
}

/*
 *  �����޳�����׵�Υ����å�
 */
#pragma inline hw_timer_fetch_interrupt
BOOL
hw_timer_fetch_interrupt(void)
{
	return (sil_reb_mem((VP)TADR_SFR_INTETA01) & TBIT_INTC_L);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
