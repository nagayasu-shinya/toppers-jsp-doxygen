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
 *  @(#) $Id: hal_msg.h,v 1.14 2003/12/15 07:19:22 takayuki Exp $
 */


#ifndef __HAL_MSG_H
#define __HAL_MSG_H

#include <constants.h>
#include <t_services.h>
#include <vwindows.h>


#ifndef __HAL_MSG_MSGONLY

    /* OS��ư���������륹��åɤΥϥ�ɥ� */
extern HWND PrimaryDialogHandle;

    /* ��������åɤ��å������ʤ������SendMessage */
Inline void HALSendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if(PrimaryDialogHandle != GetCurrentThread())
        SendMessage(PrimaryDialogHandle, uMsg, wParam, lParam);
    else
        PostMessage(PrimaryDialogHandle, uMsg, wParam, lParam);
}

    //�ǥ����ѥå�����
Inline void
HALDispatchRequest(void)
{   HALSendMessage(HALMSG_MESSAGE, HALMSG_DISPATCH, (LPARAM)0);   }

    //����ƥ������˴����� (�� : inline����������򻲾Ȥ��Ƥ�����ϤҤȤĤ����ʤΤǤ��Τޤޤˤ���)
Inline void
HALDestroyRequest(void * tcb)
{	PostMessage(PrimaryDialogHandle,HALMSG_MESSAGE,HALMSG_DESTROY,(LPARAM)tcb);   }

    //����߰��� (intno : ������ֹ�)
Inline void
HALInterruptRequest(unsigned int intno)
{	PostMessage(PrimaryDialogHandle,HALMSG_MESSAGE,HALMSG_INTERRUPT,(LPARAM)intno);   }

    //����߽�����λ����
Inline void
HALInterruptRequestAndWait(void)
{
	SendMessage(PrimaryDialogHandle,HALMSG_MESSAGE,HALMSG_INTERRUPT_FINISH,(LPARAM)0);
}

    //Ǥ�դΥ롼����μ¹��׵�
Inline BOOL
HALExecuteProcedure(void * func, void * param)
{
	void * _workofHALExecuteProcedure[2];
	
	if(func == NULL)
		return FALSE;

	_workofHALExecuteProcedure[0] = func;
	_workofHALExecuteProcedure[1] = param;
	HALSendMessage(HALMSG_MESSAGE,HALMSG_EXECUTEPROCEDURE,(LPARAM)_workofHALExecuteProcedure);

	return TRUE;
}

    //�˴���������˴ؿ�����Ͽ
Inline BOOL
HALAddDestructionProcedure(void * func, void * param)
{
	void * _workofHALAddDestructionProcedure[2];

	if(func == NULL)
		return FALSE;

	_workofHALAddDestructionProcedure[0] = func;
	_workofHALAddDestructionProcedure[1] = param;
    HALSendMessage(HALMSG_MESSAGE,HALMSG_ADDDESTRUCTIONPROCEDURE,(LPARAM)_workofHALAddDestructionProcedure);

	return TRUE;
}

    //�����ͥ�ư��ν�λ�׵�
Inline void
HALQuitRequest(void)
{
    HALSendMessage(HALMSG_MESSAGE,HALMSG_QUITREQUEST,0);
}

#endif

#endif

/***/