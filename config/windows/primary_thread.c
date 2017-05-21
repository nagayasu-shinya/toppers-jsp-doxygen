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
 *  @(#) $Id: primary_thread.c,v 1.10 2007/04/19 07:44:46 honda Exp $
 */

#include <vwindows.h>
#include <hal_msg.h>
#include <hw_timer.h>

#include <objbase.h>
#include <shellapi.h>
#include <resource.h>

#include "jsp_kernel.h"
#include "task.h"
#include <eventlog.h>
#include <cpu_rename.h>

    /* ��λ�����˴���Ԥ��ؿ��Υ��塼 */
struct tagDestructionProcedureQueue
{
	struct tagDestructionProcedureQueue * Next;
	void (*DestructionProcedure)(void *);
	void * Parameter;
};

 /*
  *   �ץ�ȥ��������
  */
extern void kernel_start();
extern void kernel_exit();

 /*
  *   ����ѿ�
  */
HINSTANCE ProcessInstance;
HANDLE    PrimaryThreadHandle;
HWND      PrimaryDialogHandle;
HANDLE    CurrentRunningThreadHandle;
BOOL      ShutdownPostponementRequest;

static HANDLE WorkerThreadHandle = NULL;
static struct tagDestructionProcedureQueue * DestructionProcedureQueue;


 /*
  *  ���߼¹���Υ���åɤ����ꤵ�줿�������Ǥ��뤫�ɤ����Υ����å�
  */
Inline 
int isTaskThreadRunning(TCB * tcb)
{   return (tcb != 0) && (tcb->tskctxb.ThreadHandle == CurrentRunningThreadHandle);   }


 /*
  * �����ͥ륹������
  *   kernel_start�ϺǸ��exit_and_dispatch��Ƥ֤Τǡ�����ƥ������˴���
  *   �����ƿ���������åɤ��������롣
  */

static DWORD WINAPI
KernelStarter(LPVOID param)
{
    TlsAlloc();
	TlsSetValue(TLS_LOGMASK, (LPVOID)1);
	TlsSetValue(TLS_THREADHANDLE, (LPVOID)CurrentRunningThreadHandle);

    kprintf(("KernelStarter begins performing kernel initialization.\n"));

    kernel_start();

    /* �ץ����Ϥ����ˤ���ʤ� */

	return 0;
}

 /*
  *  �������㳰��ư�롼���� 
  *     Visual C++   -> cpu_config.c �˰�ư���ޤ���
  *     mingw/cygwin -> cpu_insn.S   �˰�ư���ޤ���
  */
extern void TaskExceptionPerformer(void);

 /*
  * �������ǥ롼����
  *   �������֤��ʤ����֥��������˴��ץ������к�
  */
DWORD WINAPI
ForceShutdownHandler(LPVOID param)
{
	do {
		ShutdownPostponementRequest = FALSE;
		Sleep(5000);
	} while(ShutdownPostponementRequest == TRUE);
	ExitProcess(0);
	return 0;
}

 /*
  * �ǥХå����ѥ��������Υ�å������ϥ�ɥ�
  */
Inline LRESULT CALLBACK
PrimaryDialogCommandHandler(WPARAM wParam, LPARAM lParam)
{
	static BOOL lock_flag;

	switch(wParam)
	{
			/* �֥���å��ζ������ߤ���ץܥ��� */
		case IDC_CLOCKSUPPLY:
		{
			int state;

			state = SendDlgItemMessage(PrimaryDialogHandle, IDC_CLOCKSUPPLY,BM_GETCHECK,0,0);
			switch(state)
			{
					/* ����å���� -> ����å���ߤ�� and ��ư���Ƥ��륹��åɤ������ */
			case BST_CHECKED:
				if((lock_flag = sense_lock()) != TRUE)
					dis_int(0);
				hw_timer_terminate();
				if(CurrentRunningThreadHandle != NULL)
					SuspendThread(CurrentRunningThreadHandle);
				break;

					/* ����å�����Ƴ� -> �Ǹ�˻ߤ᤿����åɤκƳ� and ����å�����Ƴ� */
			case BST_UNCHECKED:
				if(CurrentRunningThreadHandle != NULL)
					ResumeThread(CurrentRunningThreadHandle);
				hw_timer_initialize();
				if(lock_flag != TRUE)
					ena_int(0);
				break;
			}
			break;
		}

	default:
		return FALSE;
	}

	return TRUE;
}

    /*
     *  TOPPERS/JSP ����åɥ�ǥ� �������ǥ����ѥå��� 
     */
static void task_dispatcher(int is_taskschedule_required)
{
		/* ����ư���Ƥ��륹��å�(=�����+������)������С������ߤ�� */
	if(CurrentRunningThreadHandle != NULL)
	{
		wait_for_thread_suspension_completion(CurrentRunningThreadHandle);

            //ư���Ƥ����Τ��������Ǥ���С�����ߥޥ�����٥����¸����
        if(isTaskThreadRunning(runtsk))
			vget_ims(&runtsk->tskctxb.InterruptLevel);
	}

		/* ���������� */

        //�ǥ����ѥå�����ɬ�פ�����
    if(is_taskschedule_required != 0 && enadsp && runtsk != schedtsk)
        runtsk = schedtsk;

        //�ڴ��西������¸�ߤ���ʤ顢���Υ�������ư����
	if(runtsk != 0l)
	{
		CurrentRunningThreadHandle = runtsk->tskctxb.ThreadHandle;

			/* �������㳰�������ä��� */
		if (runtsk->enatex && runtsk->texptn != 0) 
		{
				/* �������㳰��ư�롼����ؤȺ����ؤ��� */
			CONTEXT context;
			context.ContextFlags = CONTEXT_FULL;
			GetThreadContext(CurrentRunningThreadHandle,&context);
			*(DWORD *)(context.Esp -= 4) = context.Eip;
			context.Eip = (DWORD)TaskExceptionPerformer;
			SetThreadContext(CurrentRunningThreadHandle,&context);
		}else
			chg_ims(runtsk->tskctxb.InterruptLevel);
		
		LOG_DSP_LEAVE(runtsk);
		ResumeThread(runtsk->tskctxb.ThreadHandle);
	}else
	{
			/* ư������Τ��ʤ��ʤ顢�����ߤ򤢤����Ԥ� */
		CurrentRunningThreadHandle = NULL;
		ena_int(0);
	}
}



	/*
	 * TOPPERS/JSP ����åɥ�ǥ� �����ͥ��å������ϥ�ɥ�
	 */
Inline LRESULT CALLBACK
HALMessageHandler(WPARAM wParam,LPARAM lParam)
{
	switch(wParam)
	{
			/*
			 *�֥��������˴����Ƥ��������ץ�å����� 
			 *  lParam : �˴��оݥ�������TCB�Υ��ɥ쥹
			 */
	case HALMSG_DESTROY:
        {
            TCB * tcb = (TCB *)lParam;

				    /* tcb == 0 ����Ω����Τϡ�KernelStarter��exit_and_dispatch�����Ȥ��Τ� */
            if(tcb == 0 || isTaskThreadRunning(tcb)){
                CurrentRunningThreadHandle = NULL;

                    /* �����������ε�ư�׵��Ф���ext_tsk����ȡ����λ����Ǥ��Ǥ˿���������åɤΥϥ�ɥ뤬���äƤ���ΤǾä��ƤϤ����ʤ� */

                if(tcb == runtsk)
                    runtsk = 0;
            }
        }

			/*
			 *�֥��������ڤ��ؤ��Ƥ��������ץ�å�����
			 */
	case HALMSG_DISPATCH:
        task_dispatcher(1);
        break;

		/*
		 *�ֳ����ߤ�ȯ�������Ƥ��������ץ�å�����
		 * lParam : ������ֹ� (>0)
		 */
	case HALMSG_INTERRUPT:
        if(lParam == 0 || iniflg == FALSE || ras_int((unsigned int)lParam) == FALSE)
            break;

            /* ����߼��ս��� : ���Τޤ޼��� */

        /*
         * �ּ��˼¹Ԥ��٤������ߤ�õ���ơ�����߽����򳫻Ϥ��Ƥ��������ץ�å�����
         */
    case HALMSG_INTERRUPT_FINISH:
        {
			    /* ���߼¹Ԥ��Ƥ��륹��åɤ���� */
		    wait_for_thread_suspension_completion(CurrentRunningThreadHandle);

				/* ����ߥ���å����� and �ǥ����ѥå� */
			if((CurrentRunningThreadHandle = sch_int()) != NULL)
			{
                    //����ޤ�ư�����Ƥ����������γ���ߥޥ�����٥������
				if(isTaskThreadRunning(runtsk))
					vget_ims(&runtsk->tskctxb.InterruptLevel);

                ResumeThread(CurrentRunningThreadHandle);   //����ߥ���åɵ�ư
			}
            else {
                    // �������ؤ����
                task_dispatcher(reqflg);
                reqflg = 0;
            }

			break;
		}

		/*
		 *�ִ�������åɤθ��¤Ǥ�äƴؿ���¹Ԥ��Ƥ��������ץ�å�����
		 *  lParam : �ѥ�᡼�����Ǽ���빽¤�ΤؤΥݥ���
		 *    �ѥ�᡼����¤������
		 *      func  : �¹Ԥ������ؿ�
		 *      param : �ѥ�᡼���Ȥ����Ϥ����Ǥ⥢��("void *")����
		 *
		 * ��) �������ǥ�����ɥ��Ȥ�����ȡ��������˴��ǥ�����ɥ����ä��Ƥ��ޤ���
		 */
	case HALMSG_EXECUTEPROCEDURE:
		{
			void ** work = (void **)lParam;
			((void (*)(void *))(*work))(*(work+1));
			break;
		}

		/*
		 *�ֺǸ�κǸ�ˤ��ν�����ư�����Ƥ�������(onExit�ϥ�ɥ�)�ץ�å�����
		 * lParam : �ؿ��¹ԥ�å������Ȥ��ä��� ( func,param�ؤΥݥ��� )
		 */
	case HALMSG_ADDDESTRUCTIONPROCEDURE:
		{
			struct tagDestructionProcedureQueue * scope;
			void ** work = (void **)lParam;

			scope = DestructionProcedureQueue;

			if((DestructionProcedureQueue = GlobalAlloc(GMEM_FIXED, sizeof(struct tagDestructionProcedureQueue))) != NULL)
			{
				DestructionProcedureQueue->DestructionProcedure = *(work);
				DestructionProcedureQueue->Parameter = *(work+1);
				DestructionProcedureQueue->Next = scope;
			}else
				FatalAssertion(TRUE, "GlobalAlloc could not acquire a memory block at " __FILE__);

			break;
		}

		/*
		 *�֥ץ�����ߤ�Ƥ��������ץ�å�����
		 */
	case HALMSG_QUITREQUEST:
		{
			struct tagDestructionProcedureQueue * destqueue;
			void * destarea;

			dis_int(0);		// ����߼��դ⤳�Υ���åɤ����Τǡ��̤˶ػߤ��ʤ��Ƥ������

//			WorkerThreadHandle = CreateThread(NULL, 0, ForceShutdownHandler, 0, NULL, NULL);

			hw_timer_terminate();

			if(CurrentRunningThreadHandle != NULL)
				wait_for_thread_suspension_completion(CurrentRunningThreadHandle);

			destqueue = DestructionProcedureQueue;
			while(destqueue != NULL)
			{
				(*destqueue->DestructionProcedure)(destqueue->Parameter);
				destarea = destqueue;
				destqueue = destqueue->Next;
				GlobalFree((HGLOBAL)destarea);
			}

			DestroyWindow(PrimaryDialogHandle);
			break;
		}

	default:
		return FALSE;
	}
	return TRUE;
}

/*
 * �����ͥ륷�ߥ�졼������ˤȤʤ륹��åɤΥ�å������ϥ�ɥ�
 */
LRESULT CALLBACK PrimaryDialogProc(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	switch(Msg)
	{
		/* �������ȥ쥤��������Ǳ�����å� */
	case HALMSG_MESSAGE+1:
		if(lParam == WM_RBUTTONUP)
			kernel_exit();

		break;

		/* �����ͥ��å����� */
	case HALMSG_MESSAGE:
		return HALMessageHandler(wParam,lParam);

		/* �ǥХå��ѥ���������Υ����ƥ�Υ�å����� */
	case WM_COMMAND:
		return PrimaryDialogCommandHandler(wParam,lParam);
	
		/* ������������(��å������ϥ�ɥ����) */
	case WM_INITDIALOG:
		{
			DWORD ThreadID;
			NOTIFYICONDATA nid;

			PrimaryDialogHandle = hDlg;	//���Ū

				/* �������ȥ쥤�˥����������Ͽ */
			nid.cbSize = sizeof(NOTIFYICONDATA);
			nid.uFlags = NIF_ICON|NIF_TIP|NIF_MESSAGE;
			nid.uID = ID_NOTIFYICON;
			lstrcpy(nid.szTip,"TOPPERS/JSP");
			nid.hWnd = hDlg;
			nid.uCallbackMessage = HALMSG_MESSAGE+1;
			nid.hIcon = LoadIcon(ProcessInstance,MAKEINTRESOURCE(IDI_ERTLICON));

			Shell_NotifyIcon(NIM_ADD,&nid);

				/* �����ͥ���̥���åɤǵ�ư���� */
			PrimaryThreadHandle = (HANDLE)hDlg;
			CurrentRunningThreadHandle = CreateThread(NULL,0,KernelStarter,NULL,CREATE_SUSPENDED,&ThreadID);
            ResumeThread(CurrentRunningThreadHandle);

			FatalAssertion(CurrentRunningThreadHandle != NULL, "CreateThread at " __FILE__);

			break;
		}

		/* �����������Ĥ��褦�Ȥ��Ƥ��ޤ� */
	case WM_CLOSE:
			HALQuitRequest();
			break;

		/* �����������˴�����ޤ��� */
	case WM_DESTROY:
		{
				/* �������ȥ쥤���� */
			NOTIFYICONDATA nid;

			nid.cbSize = sizeof(NOTIFYICONDATA);
			nid.uFlags = 0;
			nid.hWnd = hDlg;
			nid.uID = ID_NOTIFYICON;
			Shell_NotifyIcon(NIM_DELETE,&nid);

			PrimaryThreadHandle = NULL;
			PostQuitMessage(0);
			break;
		}

		/* �����޽��� */
	case WM_TIMER:
			/* ���16�ӥåȤ�����1 -> �����ͥ�Υ����� */
		if((wParam & 0xffff0000) == 0xffff0000)
		{
				/* ����16�ӥåȤϳ�����ֹ� */
			return HALMessageHandler(HALMSG_INTERRUPT,(wParam & 0x0000ffff));
		}
	default:
		return FALSE;
	}
	return TRUE;
}


    /* �ޥ���ץ��å��Ǥ���ꤹ��褦���虜��ñ��Υץ��å��Τߤǽ���������褦�ˤ��� */
void setAffinityMask(void)
{
    DWORD process;
    DWORD system;
    DWORD newaffinitymask;

    if(GetProcessAffinityMask(GetCurrentProcess(), &process, &system) != 0) {
        newaffinitymask = 1;
        while((process & newaffinitymask) == 0)
            newaffinitymask <<= 1;
        SetProcessAffinityMask(GetCurrentProcess(), newaffinitymask);
    }

    kprintf(("setAffinityMask : 0x%08x\n", newaffinitymask));
}

static void initialize(HANDLE hInstance)
{
	ProcessInstance            = hInstance;
	DestructionProcedureQueue  = NULL;
	PrimaryThreadHandle        = NULL;
	CurrentRunningThreadHandle = NULL;

#ifdef KERNEL_DEBUG_MODE
    AllocConsole();
#endif
        /* �ץ��å������դ��� */
    setAffinityMask();

}

static void finalRelease(void)
{
	int i;

    kprintf(("finalRelease()\n"));

	/* �˴�����Ƥʤ��������θ���� */
	for(i=0;i<_kernel_tmax_tskid;i++)
	{
		if(_kernel_tcb_table[i].tskctxb.ThreadHandle != NULL)
		{
			if(TerminateThread(_kernel_tcb_table[i].tskctxb.ThreadHandle,0) != 0)
    			CloseHandle(_kernel_tcb_table[i].tskctxb.ThreadHandle);
			_kernel_tcb_table[i].tskctxb.ThreadHandle = NULL;
		}
	}

    /* COM�̿��򤷤Ƥ��륹��åɤ������ */
	if(WorkerThreadHandle  != NULL)
	{
		TerminateThread(WorkerThreadHandle ,0);
		CloseHandle(WorkerThreadHandle);
        WorkerThreadHandle = NULL;
	}

#ifdef KERNEL_DEBUG_MODE
    MessageBox(NULL, "The kernel will be shut down.", "TOPPERS/JSP", MB_OK);
    FreeConsole();
#endif

}


/*
 * �ᥤ��ؿ�
 */
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShow)
{
	MSG msg;
	HANDLE hDlg;

    TlsAlloc();

    initialize(hInstance);

	TlsSetValue(TLS_LOGMASK, 0);
    hDlg = CreateDialog(hInstance,"PrimaryDialog",NULL,PrimaryDialogProc);
	if(hDlg != NULL)
	{		
		ShowWindow(PrimaryDialogHandle,SW_HIDE);

		OnDebug(ShowWindow(PrimaryDialogHandle,SW_SHOW));

		while(GetMessage(&msg,NULL,0,0) != 0)
		{
			if(msg.message == WM_QUIT)
				msg.message = 0;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	else
		FatalAssertion(hDlg != NULL, "CreateDialog at " __FILE__ "("  ")");

    finalRelease();

    ExitProcess(msg.wParam);
	return msg.wParam;
}

