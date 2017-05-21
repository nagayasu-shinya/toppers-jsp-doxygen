/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2003 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: sys_rename.h,v 1.3 2003/07/01 13:49:51 takayuki Exp $
 */

/* This file is generated from sys_rename.def by genrename. */

#ifndef _SYS_RENAME_H_
#define _SYS_RENAME_H_

#ifndef OMIT_RENAME

#define siopcb_table		_kernel_siopcb_table
#define KeyEventTrapper		_kernel_KeyEventTrapper
#define SelectConsoleFont	_kernel_SelectConsoleFont
#define ConsoleCommandHandler	_kernel_ConsoleCommandHandler
#define ConsoleProc		_kernel_ConsoleProc
#define SerialConsole_FinalRelease	_kernel_SerialConsole_FinalRelease
#define CreateSerialConsole	_kernel_CreateSerialConsole
#define SerialConsole_PutChar	_kernel_SerialConsole_PutChar
#define SerialConsole_PushChar	_kernel_SerialConsole_PushChar
#define WinConsole_ReceiverThread	_kernel_WinConsole_ReceiverThread
#define WinConsole_CreatePort	_kernel_WinConsole_CreatePort
#define WinConsole_PutChar	_kernel_WinConsole_PutChar
#define WinConsole_ClosePort	_kernel_WinConsole_ClosePort
#define ScreenBuffer_ReceiverThread	_kernel_ScreenBuffer_ReceiverThread
#define ScreenBuffer_CreatePort	_kernel_ScreenBuffer_CreatePort
#define ScreenBuffer_PutChar	_kernel_ScreenBuffer_PutChar
#define ScreenBuffer_ClosePort	_kernel_ScreenBuffer_ClosePort
#define SerialRawPutc		_kernel_SerialRawPutc
#define MultiMediaTimerCallbackFunction	_kernel_MultiMediaTimerCallbackFunction

#ifdef LABEL_ASM

#define _siopcb_table		__kernel_siopcb_table
#define _KeyEventTrapper	__kernel_KeyEventTrapper
#define _SelectConsoleFont	__kernel_SelectConsoleFont
#define _ConsoleCommandHandler	__kernel_ConsoleCommandHandler
#define _ConsoleProc		__kernel_ConsoleProc
#define _SerialConsole_FinalRelease	__kernel_SerialConsole_FinalRelease
#define _CreateSerialConsole	__kernel_CreateSerialConsole
#define _SerialConsole_PutChar	__kernel_SerialConsole_PutChar
#define _SerialConsole_PushChar	__kernel_SerialConsole_PushChar
#define _WinConsole_ReceiverThread	__kernel_WinConsole_ReceiverThread
#define _WinConsole_CreatePort	__kernel_WinConsole_CreatePort
#define _WinConsole_PutChar	__kernel_WinConsole_PutChar
#define _WinConsole_ClosePort	__kernel_WinConsole_ClosePort
#define _ScreenBuffer_ReceiverThread	__kernel_ScreenBuffer_ReceiverThread
#define _ScreenBuffer_CreatePort	__kernel_ScreenBuffer_CreatePort
#define _ScreenBuffer_PutChar	__kernel_ScreenBuffer_PutChar
#define _ScreenBuffer_ClosePort	__kernel_ScreenBuffer_ClosePort
#define _SerialRawPutc		__kernel_SerialRawPutc
#define _MultiMediaTimerCallbackFunction	__kernel_MultiMediaTimerCallbackFunction

#endif /* LABEL_ASM */
#endif /* OMIT_RENAME */
#endif /* _SYS_RENAME_H_ */
