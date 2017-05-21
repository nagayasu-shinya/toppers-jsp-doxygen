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
 *  @(#) $Id: hw_timer.c,v 1.5 2003/12/15 07:19:22 takayuki Exp $
 */

/*
 *	�������åȰ�¸�����ޥ⥸�塼���Windows�ѡ�
 */

#ifndef _HW_TIMER_C_
#define _HW_TIMER_C_

#include <s_services.h>
#include <hw_timer.h>
#include <hal_msg.h>

extern HANDLE PrimaryThreadHandle;

/*
 *  Windows��ɸ�ॿ����
 */
#if defined(TIMER_WINDOWSTIMER)

	/* �����ޤε�ư���� */
void hw_timer_initialize()
{
    kprintf(("hw_timer_initialize()\n"));
	SetTimer((HWND)PrimaryThreadHandle,RTC_EVENT,TIMER_CLOCK_WINDOWS,NULL);
}

	/* �����ޤ���߽��� */
void hw_timer_terminate()
{
    kprintf(("hw_timer_terminate()\n"));
	KillTimer((HWND)PrimaryThreadHandle,RTC_EVENT);
}


/*
 *  �ޥ����ǥ���������
 */
#elif defined(TIMER_MULTIMEDIATIMER)

#include <mmsystem.h>

static DWORD TimerID = 0;

static void CALLBACK MultiMediaTimerCallbackFunction(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2)
{	HALInterruptRequest(INHNO_TIMER);	}

	/* �����ޤε�ư���� */
void hw_timer_initialize()
{
	MMRESULT result;
	TIMECAPS devcap;

    kprintf(("hw_timer_initialize()\n"));

    result = timeGetDevCaps(&devcap, sizeof(TIMECAPS));
	FatalAssertion(result == TIMERR_NOERROR &&  TIMER_CLOCK_WINDOWS >= devcap.wPeriodMin && TIMER_CLOCK_WINDOWS <= devcap.wPeriodMax, "���ꤵ�줿����å��ƥ��å��ϥޥ����ǥ��������ޤ������ǽ���ϰϤ�Ķ���Ƥ��ޤ���");

	timeBeginPeriod(TIMER_CLOCK_WINDOWS);	//timeBeginPeriod(devcap.wPeriodMin); �ȼ¹Ԥ���ȡ���٤Ȱ������������٤��夬��

	TimerID = timeSetEvent(TIMER_CLOCK_WINDOWS, TIMER_CLOCK_WINDOWS,  MultiMediaTimerCallbackFunction, 0, TIME_PERIODIC|TIME_CALLBACK_FUNCTION);
	FatalAssertion(TimerID != 0, "hw_tiemr_initialize failed to perform 'timeSetEvent' function.");
}

	/* �����ޤ���߽��� */
void hw_timer_terminate()
{
    kprintf(("hw_timer_terminate()\n"));

    if(TimerID != 0)
	{
		timeKillEvent(TimerID);
		timeEndPeriod(TIMER_CLOCK_WINDOWS);
	}
}

#elif defined(TIMER_NOTHING)

void hw_timer_initialize() {}
void hw_timer_terminate()  {}

#else

#error "���Ѥ��륿���ޤμ��̤����򤵤�Ƥ��ޤ���"

#endif



#endif /* _HW_TIMER_H_ */

