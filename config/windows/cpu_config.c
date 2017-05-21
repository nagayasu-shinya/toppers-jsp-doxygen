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
 *  @(#) $Id: cpu_config.c,v 1.15 2003/12/15 07:19:22 takayuki Exp $
 */


/*
 *	�ץ��å���¸�⥸�塼���Windows�ѡ�
 */
#include <cpu_rename.h>

#include <s_services.h>

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

#include <hal_msg.h>

volatile char CPUStatus = CPU_STAT_LOCK;	//CPU���֥ե饰

/*
 *  �������ǥ����ѥå���
 *    �ǥ����ѥå������Τ�primary_thread.c�ˤ���
 *    �����Ǥϴ�������åɤ˥ǥ����ѥå������Ф�����
 */
void
dispatch()
{
	LOG_DSP_ENTER_TSK(runtsk);
	HALDispatchRequest();	
}

/* ������ѥǥ����ѥå��� (���Ϥ��������Τߤ��ۤʤ�) */
void
idispatch()
{
	LOG_DSP_ENTER_INT(runtsk);
	HALDispatchRequest();
}


/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå�
 *    exit_and_dispatch �ϡ�CPU��å����֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 *
 *    ���߼¹���Υ�������TCB����ꤷ���˴����ꡣ�˴��弫ưŪ�˥ǥ����ѥå���ء�
 */
void
exit_and_dispatch() 
{
    HANDLE handle;

	HALDestroyRequest(runtsk);

    if((handle = (HANDLE)TlsGetValue(TLS_THREADHANDLE)) != NULL)
        CloseHandle(handle);

    TlsFree(TLS_THREADHANDLE);
    TlsFree(TLS_LOGMASK);

	ExitThread(0);
}


/*
 *  �ץ��å���¸�ν����
 */

void
cpu_initialize()
{
    kprintf(("cpu_initialize()\n"));

	/*
	 *  ����ߥ��ߥ�졼���ν����
	 */
	ini_int();

	/*
	 * �Ǿ�̹�¤���㳰�ϥ�ɥ������
	 */
	ini_exc();
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate()
{
    kprintf(("cpu_terminate()\n"));

    fin_int();  //����ߥ��ߥ�졼�������
	fin_exc();  //�Ǿ�̹�¤���㳰�ϥ�ɥ�β��
}


/*
 * ��������ư�롼����
 *
 */

DWORD WINAPI
activate_r( LPVOID param)
{
	TCB * tcb = (TCB *)param;

	TlsAlloc();
	TlsSetValue(TLS_LOGMASK, 0);
    TlsSetValue(TLS_THREADHANDLE, tcb->tskctxb.ThreadHandle);

    kprintf(("Task %d : activated\n", (tcb - tcb_table) + 1));

	(*(void(*)(VP_INT))tcb->tinib->task)(tcb->tinib->exinf);
	ext_tsk();
	return 0;
}

/*
 *  atexit����Ͽ���줿�ؿ����ɽФ� (Windows�ϲ��⤷�ʤ� -> CRT��Ǥ����)
 */
void call_atexit(void)
{}


/*
 *   ��̿Ū�ʼ��Ԥ��Ф����н�롼����
 */
void FatalAssertion(int exp, LPCSTR format, ...)
{
	extern HANDLE PrimaryThreadHandle;
	extern HANDLE CurrentRunningThreadHandle;

	if(!exp)
	{
		va_list vl;
		char    buffer[1024];

			/* ���顼���������������ͤ��ߤ�� */
		wsprintf(buffer, "Critical assertion fail occured !!\nGetLastError = 0x%08x\n\n", GetLastError());

			/* �����ͥ뤬ư���Ф��Ƥ�����... */		
		if(PrimaryThreadHandle != NULL)
		{
				/* �����ͥ�μ¹Ԥ�ߤ�� */
			dis_int(0);
			if(CurrentRunningThreadHandle != NULL)
				SuspendThread(CurrentRunningThreadHandle);
			hw_timer_terminate();
		}

			/* �ٹ�ɽ�� */
		va_start(vl, format);
		wvsprintf(buffer + lstrlen(buffer), format, vl);
		MessageBox(PrimaryDialogHandle, buffer, "Assertion Failed", MB_OK|MB_ICONERROR);

			/* �����ͥ���� */
		HALQuitRequest();
	}
}

	/*
	 *   �����Ϥ�ɤ����뤫������
	 */
void set_logcontrol(BOOL enable)
{
	BOOL result;
	result = TlsSetValue(TLS_LOGMASK, (LPVOID)(enable == TRUE ? 0 : 1));
	if(result == 0)
	{
		TlsAlloc();
		TlsSetValue(TLS_LOGMASK, (LPVOID)(enable == TRUE ? 0 : 1));
	}
}

    /*
     *   �����ͥ�ΥǥХå���printf
     */
void _kernel_debugprintf(const char * format, ... )
{
    va_list vl;
    int     words;
    DWORD   count;
    char    buffer[1024];

    va_start(vl, format);
    words = wvsprintf(buffer, format, vl);

    if(words != 0)
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), buffer, words, &count, NULL);
}

#ifdef _MSC_VER     //cygwin�ξ���cpu_insn.S�˵���

 /*
  * �������㳰��ư�롼����
  *   ����ƥ����Ȥ���פ����뤿�ᡢ
  *   �������㳰��ư�������������Υ���åɾ��ư����뤿��Υ롼����
  */
void __declspec(naked) TaskExceptionPerformer(void)
{
		/* �쥸�������� */
	__asm	pusha
	__asm	sub		esp, FPU_CONTEXTSIZE
	__asm	fsave	[esp]

		/* �������㳰�ε�ư */
	__asm	call	call_texrtn

		/* ����ߥޥ����ᤷ */
	__asm	mov		ebx, DWORD PTR runtsk
	__asm	mov		eax, [ebx]TCB.tskctxb.InterruptLevel
	__asm	push	eax
	__asm	call	chg_ims
	__asm	add		esp, 4

		/* �쥸�������� */
	__asm	finit
	__asm	frstor	[esp]
	__asm	add		esp, FPU_CONTEXTSIZE
	__asm	popa
	__asm	ret
}

#endif

