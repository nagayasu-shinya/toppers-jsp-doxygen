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
 *  @(#) $Id: debugout.c,v 1.10 2003/12/15 07:19:22 takayuki Exp $
 */

#include <debugout.h>
#include <hal_msg.h>
#include <resource.h>

#ifdef DEBUG_ENABLE

#define DBG_SIZE_STRINGBUFFER 512

static HANDLE DebugConsole;     //�ǥХå�ʸ�����ɽ������ƥ����ȥܥå���
static HWND   DialogHandle;     //�ǥХå����ϥ�������

extern void FatalAssertion(int exp, LPCSTR format, ... );

/*
 * �ǥХå��ѥ��������Υ�å������ϥ�ɥ�
 */
static LRESULT CALLBACK DebugOutDialogProc(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	switch(Msg)
	{
	case WM_INITDIALOG:
		DebugConsole = GetDlgItem(hDlg,IDC_DEBUGOUT);       //������ƥ����ȥܥå���
		ShowWindow(hDlg,SW_SHOW);

	case WM_SIZE:
		{
			RECT client;
			GetClientRect(hDlg,&client);
			MoveWindow(DebugConsole,0,0,client.right,client.bottom,TRUE);
			break;
		}

	case WM_CLOSE:
			/* Never let this dialog close by pressing of the close button. */
		break;

	case WM_DESTROY:
		DialogHandle = 0;
		break;

	case WM_QUIT:
		DestroyWindow(hDlg);
		break;
	
	default:
		return FALSE;
	}
	return TRUE;
}

    /* ����2�ؿ�����������ꤹ�뤿��ι�¤�� */
struct tagInitializeDebugServicesParam {
    HINSTANCE hInstance;
    HWND      hDlg;
};

    /* �ǥХå��롼�����Ȥ�� */
void FinalizeDebugServices(void)
{
    if(DialogHandle != 0l) {
		DestroyWindow(DialogHandle);
    }
}

    /* ��������åɤ��¹Ԥ��륦����ɥ������롼���� */
static void _initializeDebugServices(void * _param)
{
    struct tagInitializeDebugServicesParam * param = (struct tagInitializeDebugServicesParam *)_param;
    DialogHandle = CreateDialog(param->hInstance, MAKEINTRESOURCE(DEBUGOUTDIALOG), param->hDlg, DebugOutDialogProc);
    FatalAssertion(DialogHandle != NULL, "DebugService could not create its own dialog.");     
}

    /* �ǥХå��롼����ν���� �ʴ�������åɤ˥����������äƤ�餦) */
void InitializeDebugServices(HINSTANCE hinst,HWND dlg)
{
    struct tagInitializeDebugServicesParam param;
    param.hInstance = hinst;
    param.hDlg      = dlg;

    HALExecuteProcedure(_initializeDebugServices, (void *)&param);      //��������
    HALAddDestructionProcedure(FinalizeDebugServices, 0);               //�˴��롼�������Ͽ
}

    /* �ǥХå�����printf */
int _debugOut(const char * format, ... )
{
	int result;
	int i;
	char buffer[DBG_SIZE_STRINGBUFFER*2];
	char * scope;
	const char * work;
	va_list vl;

	if(format == 0l)
		return 0;

	va_start(vl, format);

		/* format�˴ޤޤ�� '\n' �� '\r\n' ���ִ����� */
	scope = buffer;
	work  = format;

	while(*format != '\0')
	{
		if(*format == '\n')
		{
			i = format - work;
			lstrcpyn(scope, work, i);
			
			scope += i;
			work = format;

			*(scope++) = '\r';
		}
		format ++;
	}

	i = format - work + 1;
	lstrcpyn(scope, work, i);		//+1����'\x0'�⥳�ԡ�
	scope += i;

	if((result = wvsprintf(scope, buffer, vl)) > 0)
	{
			//���Ϥ��������龯�����å�
		i = GetWindowTextLength(DebugConsole);
		if(i > DEBUG_LIMITTERUPPERBOUND)
		{
			SendMessage(DebugConsole, EM_SETSEL, 0, i - DEBUG_LIMITTERUPPERBOUND);
			SendMessage(DebugConsole, EM_REPLACESEL, (WPARAM)FALSE, (LPARAM)"");
		}

		SendMessage(DebugConsole,EM_SETSEL,i,i);
		SendMessage(DebugConsole,EM_REPLACESEL,(WPARAM)FALSE,(LPARAM)scope);
	}

	return result;
}

#endif


