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
 *  @(#) $Id: cpu_defs.c,v 1.14 2003/12/15 07:19:22 takayuki Exp $
 */

#define _WIN32_WINNT 0x400

#include <s_services.h>
#include <hal_msg.h>

/*
 * m68k�äݤ�����ߥ��ߥ�졼�� (Windows HAL)
 */

	/* ���ߤγ���ߥޥ�����٥� */
unsigned int CurrentInterruptLevel;

	/* ����ߴ����ơ��֥� */
static struct tagInterruptLevel InterruptLevel[INT_NUMINTERRUPTS];

	/* ����ߥޥ�����٥��ͭ���ϰϥ����å� */
#define CHECK_IMS(x) ( (x) != 0 && (x) <= INT_NUMINTERRUPTS )

	/* �㳰�����ơ��֥� */
struct tagExceptionLevel ExceptionLevel[EXC_MAXITEMS];

	/* ��ʬ��������Ͽ����Ƥ�����¤���㳰�ϥ�ɥ�Υ��ɥ쥹 */
static LPTOP_LEVEL_EXCEPTION_FILTER AnotherExceptionFilter;

/*
 *   �����ƥ����ΤΥ���ƥ����륻������������롼����
 *     ���ɤ�����CRITICAL_SECTION��Ȥ��Τ��᤿�Τ�
 *        -> Windows�Υ���ƥ����륻�������ϡ�ITRON�Ǹ����Ȥ���Υǥ����ѥå��ػߤǼ������Ƥ���餷����
 *           �������٥�Ȥǵ������Ƥ��ޤä�����åɤ�����ƥ����륻���������ˤ��륹��åɤ�ư���
 *           ��ߤ����Ƥ��ޤ����Ȥ��Ǥ���餷�����ʤΤ�CPU��å��ΤĤ��ǥ���ƥ����륻��������ȤäƤ���ȡ�
 *           �¤Ϥ����Υǥ����ѥå��ػߤʤΤǥϥ�ɥ餬��ư���Ƥ��ޤ���PrimaryThread��SuspendThread��ȯ�Ԥ��ƥǥåɥ�å����Ƥ��ޤ���
 *           ��������ϻ���ȯ��������������������ä������ޤ�������ʤ��Ȥ��������Ȥϻפ�����ʤ��ä���
 *           WinProg�Ϥ�ML�Ǥ�ָ�������������Ʊ��������ʤ饯��ƥ����륻�������ϻȤ�ʤ��ۤ����褤�פȤ��äƤ��롣
 */

static HANDLE SystemMutex = NULL;		                //�����ƥ��å��ѤΥߥ塼�ƥå������֥�������
static DWORD  SystemMutexOwnerThreadID = 0;				//�����ƥ��å��������������åɤ�ID
static DWORD  SystemMutexLastOwnerThreadID = 0;			//�Ǹ�˥����ƥ��å���������Ƥ�������åɤ�ID (�ǥХå���)

	/*
	 *   enter_system_critical_section : �����ƥ�Υ�å������������
	 *     BOOL * lock : ���å���(��ʬ���Ϥ�ƥ�å�������������TRUE���֤�)
	 */
void enter_system_critical_section(BOOL * lock)
{
	if(SystemMutex != NULL && SystemMutexOwnerThreadID != GetCurrentThreadId())
	{
		WaitForSingleObject(SystemMutex, INFINITE);	
		if(lock != NULL)
			*lock = TRUE;
		SystemMutexOwnerThreadID = GetCurrentThreadId();
	}else
	{
		if(lock != NULL)
			*lock = FALSE;
	}
}

	/*
	 *   leave_system_critical_section : �����ƥ�Υ�å�����������
	 *		BOOL * lock : enter_system_critical_section�ǻ��Ѥ������å���
	 */
void leave_system_critiacl_section(BOOL * lock)
{
	assert(lock != NULL);

	if(*lock == TRUE)
	{
		SystemMutexLastOwnerThreadID = SystemMutexOwnerThreadID;
		SystemMutexOwnerThreadID = 0;
		if(SystemMutex != NULL)
			ReleaseMutex(SystemMutex);	
	}
}

	/*
	 *   wait_for_thread_suspension_completion : ����åɤ��å����������֤���ߤ����� 
	 */
ER wait_for_thread_suspension_completion(HANDLE thread)
{
	BOOL lock;

	if(thread == 0 || thread == NULL)
		return E_PAR;

	enter_system_critical_section(&lock);
	SuspendThread(thread);
	leave_system_critiacl_section(&lock);

	return 0;
}



/*
 *  ���˼¹Ԥ��٤�����ߥϥ�ɥ�Τ����٥���������
 *      ipl : ����ߥޥ�����٥�
 *
 *    �����ߥ�٥�ޥ�����ipl�ޤǲ����ä��Ȥ��ˡ�����ư�����٤�����ߤ����򤹤롣
 *    �ޥ�����٥�����̤γ���ߤξ�硢�ڥ�ǥ��󥰤��줿�׵� or ���˼¹Ԥ�
 *    �ϤޤäƤ���ϥ�ɥ� ��¹Ԥ��롣�ޥ�����٥�ʲ��ξ�硢����ư���Ƥ���
 *    �ϥ�ɥ餬������Τ߼¹Ԥ��롣����ʤ�����0���֤���
 */
static unsigned int
isns_int( unsigned int ipl )
{
	unsigned int result = INT_NUMINTERRUPTS;
	
	if((CPUStatus & CPU_STAT_LOCK) != 0)
		return 0;

	while(result > ipl)
	{
		result --;
		if( (InterruptLevel[result].Flags & (INT_STAT_PENDING|INT_STAT_RUNNING)) != 0)
			return result+1;
	}
	while(result > 0)
	{
		result --;
		if( (InterruptLevel[result].Flags & INT_STAT_RUNNING) != 0)
			return result+1;
	}
	return 0;
}

static DWORD WINAPI
InterruptHandlerWrapper(LPVOID param)
{
	unsigned int   i;
	unsigned int   PrevLevel;
	BOOL           systemLock;

	struct tagInterruptLevel * intlv = (struct tagInterruptLevel *)param;

	TlsAlloc();

    kprintf(("InterruptHandlerWrapper (%d) : start\n", (intlv - InterruptLevel) + 1 ));

	while(1==1)
	{
			/* ����������� */

		set_logcontrol((intlv->Flags & INT_MOD_LOGMASK) != 0);
		LOG_INH_ENTER((intlv - InterruptLevel)+1);

        assert((CPUStatus & CPU_STAT_LOCK) == 0);
        enter_system_critical_section(&systemLock);
        PrevLevel = CurrentInterruptLevel;
		CurrentInterruptLevel = (unsigned int)(intlv - InterruptLevel)+1;
		intlv->Flags &= ~INT_STAT_PENDING;
		intlv->Flags |=  INT_STAT_RUNNING;
		leave_system_critiacl_section(&systemLock);

        ( (void (*)(void) )(intlv->Routine))();
        
			/* ����߸���� 
             *    �����ǰ쵤��PrevLevel�ޤ���Ȥ��ƤϤ����ʤ�.
             *    �����ߤ��������ˤ�äƤϡ�ͥ���٤��㤤����ߤ�æ�н�����ͥ���٤ι⤤�����ߤο���������ľ��˼¹Ԥ��졢
             *    ����������ͥ���٤ι⤤����ߤ�CurrentInterruptLevel = 0�ξ��֤����äƤ��ޤ����Ȥˤʤ롣
             */
		enter_system_critical_section(&systemLock);
		intlv->Flags &= ~INT_STAT_RUNNING;
		i = isns_int(PrevLevel);
		if(i > PrevLevel)
			CurrentInterruptLevel = i - 1;
		else
			CurrentInterruptLevel = PrevLevel;
		leave_system_critiacl_section(&systemLock);

		LOG_INH_LEAVE((intlv - InterruptLevel)+1);

            /* ���γ���ߤ��������褦������ */
	    HALInterruptRequestAndWait();
	}

    kprintf(("InterruptHandlerWrapper (%d) : exit\n", (intlv - InterruptLevel) + 1 ));

    ExitThread(0);
	return 0;
}

BOOL
def_int(unsigned int ims, void * rtn)
{
	BOOL lock;

	if(!CHECK_IMS(ims) || rtn == NULL)
		return FALSE;

    kprintf(("def_int : [ims:%d]\n", ims));

	ims--;

	enter_system_critical_section(&lock);
	if(InterruptLevel[ims].ThreadHandle != NULL)
	{
		TerminateThread(InterruptLevel[ims].ThreadHandle,0);
		CloseHandle(InterruptLevel[ims].ThreadHandle);
	}
	InterruptLevel[ims].Routine = rtn;
	InterruptLevel[ims].ThreadHandle = CreateThread(NULL,0,InterruptHandlerWrapper,(LPVOID)&InterruptLevel[ims],CREATE_SUSPENDED,&InterruptLevel[ims].ThreadID);
	leave_system_critiacl_section(&lock);

	return TRUE;
}

BOOL
ini_int(void)
{
	int i;

    kprintf(("ini_int : [Start]\n"));

    SystemMutex = CreateMutex(NULL,TRUE,NULL);

	for(i=0;i<INT_NUMINTERRUPTS;i++)
	{
		InterruptLevel[i].Routine      = (void *)0l;
		InterruptLevel[i].ThreadHandle = NULL;
		InterruptLevel[i].ThreadID     = 0;
		InterruptLevel[i].Flags        = INT_MOD_LOGMASK;
	}

		/* �����ư��CPU��å����֤ذܹԤ����� */
	CurrentInterruptLevel = 0;	//����ߥޥ�����������
	CPUStatus |= CPU_STAT_LOCK;	//CPU�ǳ���߶ػߤ�

	ReleaseMutex(SystemMutex);

    kprintf(("ini_int : [Exit]\n"));

	return TRUE;
}

void
fin_int(void)
{
	int    i;
	HANDLE work;

    kprintf(("fin_int : [Start]\n"));

	enter_system_critical_section(NULL);

	for(i=0;i<INT_NUMINTERRUPTS;i++)
	{
		if(InterruptLevel[i].ThreadHandle != NULL)
		{
			TerminateThread(InterruptLevel[i].ThreadHandle,0);
			CloseHandle(InterruptLevel[i].ThreadHandle);
		}
		InterruptLevel[i].Routine = (void *)0l;
		InterruptLevel[i].ThreadHandle = NULL;
		InterruptLevel[i].ThreadID = 0;
		InterruptLevel[i].Flags    = 0;
	}
	CurrentInterruptLevel = 0;

        /* CloseHandle(SystemMutex), SystemMutex = INVALID_HANDLE; ������ˤ�� */
	work = SystemMutex;
	SystemMutex = NULL;
	CloseHandle(work);

		//����ʹߤ�CPU��å����֤��Ȼפ�����
	CPUStatus |= CPU_STAT_LOCK;

    kprintf(("fin_int : [Exit]\n"));
}

BOOL
ras_int(unsigned int ims)
{
	BOOL lock;
	BOOL result = TRUE;

	if(!CHECK_IMS(ims))
		return FALSE;

	ims --;

	enter_system_critical_section(&lock);
	if(InterruptLevel[ims].ThreadHandle == NULL)
	{
		result = FALSE;
	}else
		InterruptLevel[ims].Flags |= INT_STAT_PENDING;
	leave_system_critiacl_section(&lock);
	return result;
}

unsigned int
sns_int( void )
{
	BOOL lock;
	int  result;

	if(sense_lock() == TRUE)
		return 0;

	enter_system_critical_section(&lock);
	result = isns_int(CurrentInterruptLevel);
	leave_system_critiacl_section(&lock);
	return result;
}

HANDLE
sch_int( void )
{
	BOOL   lock;
	HANDLE result;
	unsigned int level;

	if(sense_lock() == TRUE)
		return NULL;

	enter_system_critical_section(&lock);
	level = isns_int(CurrentInterruptLevel);
	if(level != 0)
	{
		result = InterruptLevel[level-1].ThreadHandle;
	}else
		result = NULL;
	leave_system_critiacl_section(&lock);

	return result;
}

DWORD LockerThreadID = 0;

ER
ena_int(unsigned int ims)
{
	BOOL lock;
	int  i;

	enter_system_critical_section(&lock);
	i = isns_int(CurrentInterruptLevel);
	CPUStatus &= ~CPU_STAT_LOCK;
	LockerThreadID = 0;
	leave_system_critiacl_section(&lock);

	if(i != 0)
		HALInterruptRequest(0);

	return 0 /*E_OK*/;
}

ER
dis_int(unsigned int ims)
{
	BOOL lock;

	enter_system_critical_section(&lock);
	CPUStatus |= CPU_STAT_LOCK;
	if(LockerThreadID == 0)
	{
		LockerThreadID = GetCurrentThreadId();
	}else
	{
		DWORD newThreadID = GetCurrentThreadId();
		LockerThreadID = GetCurrentThreadId();	//�֥졼���֤���
	}
	leave_system_critiacl_section(&lock);

	return 0;
}

ER
chg_ims(unsigned int ims)
{
	BOOL lock;
	int  i;

		//chg_ims �� ims==0 �����
	if(ims != 0 && !CHECK_IMS(ims))
		return -17 /*E_PAR*/;

	enter_system_critical_section(&lock);
	CurrentInterruptLevel = ims;
	if(CurrentInterruptLevel == INT_NUMINTERRUPTS)
		CPUStatus |= CPU_STAT_LOCK;
	else
		CPUStatus &= ~CPU_STAT_LOCK;
	i = isns_int(ims);
	leave_system_critiacl_section(&lock);

	if(i != 0)
		HALInterruptRequest(0);

	return 0 /*E_OK*/;
}

ER
get_ims(unsigned int *p_ims)
{
	BOOL lock;

	if(p_ims == (void *)0l)
		return -17 /*E_PAR*/;

	enter_system_critical_section(&lock);
	if((CPUStatus & CPU_STAT_LOCK) != 0)
		*p_ims = INT_NUMINTERRUPTS;
	else
		*p_ims = CurrentInterruptLevel;
	leave_system_critiacl_section(&lock);
	return 0 /*E_OK*/;
}

ER
vget_ims(unsigned int *p_ims)
{
	BOOL lock;

	if(p_ims == (void *)0l)
		return -17 /*E_PAR*/;

	enter_system_critical_section(&lock);
	*p_ims = CurrentInterruptLevel;
	leave_system_critiacl_section(&lock);
	return 0 /*E_OK*/;
}

/*
 * �Ǿ�̥�٥�Windows��¤���㳰�ϥ�ɥ�
 */

LONG WINAPI
HALExceptionHandler( EXCEPTION_POINTERS * exc )
{
	int i;
	int result;

	if((CPUStatus & CPU_STAT_EXC) == 0)
		CPUStatus |= CPU_STAT_DOUBLEFAULT;

        /* �ϼ������� (���֤����ޤ�����...) */
	CPUStatus |= CPU_STAT_EXC;
	for(i=0;i<EXC_MAXITEMS;i++)
	{
		if(ExceptionLevel[i].ExceptionCode == exc->ExceptionRecord->ExceptionCode)
		{
			result = EXCEPTION_CONTINUE_SEARCH;
	
			LOG_EXC_ENTER(i);
			( * ((void (*)(void *,int *))ExceptionLevel[i].Routine)) (exc,&i);
			LOG_EXC_LEAVE(i);

			CPUStatus &= ~CPU_STAT_EXC;
			return result;
		}
	}
	CPUStatus &= ~CPU_STAT_EXC;
	return EXCEPTION_CONTINUE_SEARCH;
}

BOOL
ini_exc(void)
{
	int i;

	for(i=0;i<EXC_MAXITEMS;i++)
	{
		ExceptionLevel[i].ExceptionCode = 0;
		ExceptionLevel[i].Routine = 0l;
	}

	AnotherExceptionFilter = SetUnhandledExceptionFilter(HALExceptionHandler);
	
	return TRUE;
}

void
fin_exc(void)
{
    SetUnhandledExceptionFilter(AnotherExceptionFilter);
}

BOOL
def_exc(DWORD exc, void * routine)
{
	int j;
	int i;

        /* ����롼���� */
	if(routine == 0l)
	{
        kprintf(("def_exc : [UNREG] 0x%08x\n", exc));

		for(i=0;i<EXC_MAXITEMS;i++)
			if(ExceptionLevel[i].ExceptionCode == exc)
			{
				ExceptionLevel[i].ExceptionCode = 0;
				ExceptionLevel[i].Routine = 0;
				return TRUE;
			}
		return FALSE;
	}

    /* ��Ͽ�롼���� */

    kprintf(("def_exc : [REG] 0x%08x\n", exc));

	j = EXC_MAXITEMS;
	for(i=0;i<EXC_MAXITEMS;i++)
	{
		if(ExceptionLevel[i].ExceptionCode != 0)
		{
				/* ��Ͽ���褦�Ȥ��Ƥ����ֹ椬������Ͽ����Ƥ��ʤ����ɤ���Ĵ�٤� */
			if(ExceptionLevel[i].ExceptionCode == exc)
				return FALSE;
		}else
		{
				/* �����ֹ�κǾ���Ф��� */
			if(j > i)
				j = i;

            /* ����Ͽ�����å�������Τǡ�������break���Ƥϥ��� */
		}
	}

	FatalAssertion(i == EXC_MAXITEMS, "No available exception slots left.");

		//This sequence will never change
	ExceptionLevel[j].Routine       = routine;
	ExceptionLevel[j].ExceptionCode = exc;

	return TRUE;
}

ER set_intlogmask( unsigned int ims, BOOL mask )
{
	BOOL lock;

	if( !CHECK_IMS(ims) )
		return FALSE;

	-- ims;

	enter_system_critical_section(&lock);
	if(mask == TRUE)
		InterruptLevel[ims].Flags |= INT_MOD_LOGMASK;
	else
		InterruptLevel[ims].Flags &= ~INT_MOD_LOGMASK;
	leave_system_critiacl_section(&lock);

	return TRUE;
}

unsigned int current_timer_clock_unit = TIMER_CLOCK_WINDOWS;

ER set_clk(unsigned int clk)
{
    BOOL lock;

    if(clk == 0)
        clk = TIMER_CLOCK_WINDOWS;

    hw_timer_terminate();
    enter_system_critical_section(&lock);
    current_timer_clock_unit = clk;
    leave_system_critiacl_section(&lock);
    hw_timer_initialize();

    return E_OK;
}
