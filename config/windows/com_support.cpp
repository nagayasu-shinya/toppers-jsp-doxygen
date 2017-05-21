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
 *  @(#) $Id: com_support.cpp,v 1.10 2003/12/15 07:19:22 takayuki Exp $
 */

#include <vitron.h>
#include <com_support.h>
#include <eventlog.h>
#include "syslog.h"

#include <resource.h>

#include <commctrl.h>

/*
 *  ����ʹ���줿��������
 *     Q: C�������륳���Ȥ�C++�������륳���Ȥ������äƤ��ޤ���?
 *     A: ���ڤ˥����ȥ����Ȥ����Ⱥ��������C�������륳���Ȥǡ������褦�ʽ����򤹤����������C++�������륳���Ȥ�ȤäƤ��ޤ���
 *
 *     Q: �ѿ���̾�Ť���§������㤯����Ǥ���?
 *     A: ����Ū�˥��������ϰϤǻȤ�ʬ���Ƥ��ޤ���
 *          �����뤬��ʸ��+"_", �����Х뤬��ʸ����ʸ��, ���Ф�Java�äݤ���������
 *
 *     Q: INVALID_HANDLE_VALUE �� NULL ��ɤ��Ȥ�ʬ���Ƥ���ΤǤ���?
 *     A: CreateXxxx�����Ի����ֵѤ����ͤǤ��碌�ޤ�����
 *        ����Ū�ˤϡ��ե������INVALID_HANDLE_VALUE(CreateFile)�ǡ�����ʳ���NULL�ˤʤäƤޤ���
 */

#ifndef __COM_NOT_REQUIRED__


//===================================================
/*
 *   ������
 */
extern "C" SYSTIM		_kernel_systim_offset;
extern "C" SYSTIM		_kernel_current_time;
extern "C" HINSTANCE	ProcessInstance;
extern "C" HANDLE		PrimaryDialogHandle;
extern "C" BOOL			ShutdownPostponementRequest;
extern "C" int          CPUStatus;

extern "C" void FatalAssertion(int exp, LPCSTR format, ... );

extern "C" void enter_system_critical_section(BOOL * cookie);
extern "C" void leave_system_critiacl_section(BOOL * cookie);

#ifdef KERNEL_DEBUG_MODE
   extern "C" _kernel_debugprintf(const char * format, ... );
#  define kprintf(x) _kernel_debugprintf x
#else
#  define kprintf(x)
#endif

//===================================================

	/* �桼������Υ� */
#define USERDEFINED	0x60
#define LOG_MODULENAME (0 | USERDEFINED)	/* �⥸�塼���̾��   */
#define LOG_TIMESTAMP  (1 | USERDEFINED)    /* ��Ͽ�򳫻Ϥ������� (SYSTEMTIME��¤�Τ򤽤Τޤޥ����) */

#define  __HAL_MSG_MSGONLY
#include <hal_msg.h>

#include <string>

namespace
{
	/*
	 *   COM���󥿡��ե�������Ϣ�����
	 */

		//������ID�����
	const IID   IID_IKernelEvents = {0x1353969D,0xE84F,0x463F,{0xB2,0x11,0x33,0x7E,0x9B,0xCF,0xB9,0x9E}};
	const IID   IID_IKernel       = {0xD3E42099,0x3FDD,0x4A78,{0xBD,0xBD,0x4E,0x57,0xD3,0x62,0xF5,0xED}};
	const CLSID CLSID_Kernel      = {0x51789667,0x9F20,0x40AF,{0xAF,0x7F,0x98,0x56,0x32,0x5D,0xFB,0x0B}};

		// IKernel���󥿡��ե��������
	class IKernel : public IUnknown
	{
	public:
		STDMETHOD(Read)(unsigned long address,unsigned long sz,char __RPC_FAR data[]) PURE;
		STDMETHOD(IsValid)(BOOL __RPC_FAR * valid) PURE;
		STDMETHOD(Write)(unsigned long address,unsigned long sz,char __RPC_FAR data[]) PURE;
		STDMETHOD(OnLogEvent)(long sz, unsigned char __RPC_FAR data[]) PURE;
	};

		// IKernelEvents���󥿥ե��������
	class IKernelEvents : public IUnknown
	{
	public:
		STDMETHOD(QueryInterface)(REFIID iid, void ** unk);
		STDMETHOD_(ULONG,AddRef)();
		STDMETHOD_(ULONG,Release)();
		STDMETHOD(OnInterruptRequest)(long inhno);

		IKernelEvents(void);

		long RefCount;
	};

	/*
	 *   IKernelEvents����
	 */

	IKernelEvents::IKernelEvents(void) : RefCount(0)
	{}

    STDMETHODIMP IKernelEvents::QueryInterface(REFIID iid, void ** unk)
	{
		if( iid == IID_IKernelEvents || iid == IID_IUnknown )
		{
			*unk = this;
			::InterlockedIncrement(&RefCount);
			return S_OK;
		}

		return E_NOINTERFACE;
	}

	STDMETHODIMP_(ULONG) IKernelEvents::AddRef()
	{	return ::InterlockedIncrement(&RefCount);	}

	STDMETHODIMP_(ULONG) IKernelEvents::Release()
	{
		if( ::InterlockedDecrement(&RefCount) == 0)
			delete this;
		return RefCount;
	}

	STDMETHODIMP IKernelEvents::OnInterruptRequest(long inhno)
	{

		if(inhno < 0)
		{
			/* inhno < 0 ���ü�ʰ�̣����� */

			/* inhno = -1 : keep-alive */
		}else
			::PostMessage((HWND)PrimaryDialogHandle,HALMSG_MESSAGE,HALMSG_INTERRUPT,(LPARAM)inhno);
		return S_OK;
	}
}

namespace {
	/*
	 *   COM�̿��Ѻ�ȥ���åɤ˴ؤ������
	 */

	HANDLE request_semaphore    = NULL;		//�׵��Ԥ����ޥե�
	HANDLE worker_thread_handle = NULL;		//��ȥ���åɤΥϥ�ɥ�

	//==============================================================================

		//COM��ȥ���åɤ�����˺�ư���Ƥ��뤫�ݤ�
	inline bool IsValid(void)
	{	return (request_semaphore != NULL) && (worker_thread_handle != NULL);	}

	//===================================================

		/*
		 *    Q: �ɤ����ƥ����ƥ��å���ɬ�פʤ�?
		 *    A: �����٥�Ȥ򥭥塼���󥰤��뤿��˳ƥ�����/����ߥ���åɤ��������
		 *        -> VisualC++�Υޥ������å��ѥ�����ݥ饤�֥��������ǥ���ƥ����륻������󥪥֥������Ȥ�Ȥä���¾���椷�Ƥ���
		 *        -> TOPPERS/JSP Windows�Υǥ����ѥå���(��������å�)���׵᤬���Ⱥ�ư���Ƥ��륹��åɤ�ߤ�ˤ�����
		 *        -> ��������ѤΥ���ƥ����륻����������ä��ޤ�SuspendThread����Ƥ��ޤ�����������׵��Ф���¾�Υ���å����Ƥ���å�
		 *        -> ��������åɤ����Ф�����˥����Ȥ�����Τǡ���������åɤ��å�
		 *        -> ��������åɤ���å������ȡ��ǽ��SuspendThread���줿��Ĥ򵯤�������åɤ����ʤ�
		 *        -> �ǥåɥ�å�
		 *    ��­ : COM�̿���ȥ���åɤ䥳�󥽡����������åɤΤ褦�˴�������åɤ�SuspendThread���оݤˤʤ�ʤ�����åɤϥ�å����ʤ��Ƥ⤤��
		 */

	//===================================================

		/* ��ȥ���åɤ�Ϳ����ǡ������ݻ����륯�饹 */
	class Request
	{
	public:
		enum tagRequestType
		{
			Confirmation = 0x00,	/* �������åɤ�ư���ǧ (���ޥե��򤿤�������) */
			
			DeviceRead   = 0x01,	/* �ǥХ������ߥ�졼����� �ɽФ���� */
			DeviceWrite  = 0x02,	/* �ǥХ������ߥ�졼����� �������� */

			EventLog     = 0x03,	/* ���٥�ȥ����� */

			QuitThread   = 0xff		/* ��ȥ���åɤν�λ */
		};

	protected:
		bool                blocking;
		bool				allocated;
		enum tagRequestType type;
		unsigned long       address;		/* �ǥХ��� : �ǥХ����Τ��륢�ɥ쥹 */
		unsigned long       size;			/* ����     : storage�����ĥǡ����Υ����� */
		HGLOBAL             storage;		/* ����     : �ǡ������Ǽ���Ƥ����ΰ�Υ��ɥ쥹(�ϥ�ɥ�) */
		int                 result;			/* ����     : �֥�å��󥰼¹Ի����ֵ��� */
		HANDLE              signalobject;	/* ����     : �֥�å��󥰼¹Ի��Υ���åɥϥ�ɥ� */

		Request *           next;		/* ���塼�ˤ��뤿��Υ�� */

		static LONG      RequestCount;	//���塼�ˤĤʤ��äƤ���ꥯ�����Ȥο�
		static Request * top;			//�ꥯ�����ȥ��塼����Ƭ (��äȤ�Ť��ꥯ������)
		static Request * tail;			//�ꥯ�����ȥ��塼������ (��äȤ⿷�����ꥯ������)
		static CRITICAL_SECTION cs;		//��¾���塼����Ѵ��ΰ襪�֥�������

		void connect(void)
		{
				//�׵�򥭥塼�ˤĤʤ�
			::EnterCriticalSection(&cs);
			next = NULL;
			if(tail != NULL)
				tail->next = this;
			tail = this;
			if(top == NULL)
				top = tail;
			::LeaveCriticalSection(&cs);

			::InterlockedIncrement(&RequestCount);
		}

	protected:
			//���󥹥ȥ饯��
		Request(enum tagRequestType _type, bool _block, unsigned int _size = 0, void * _storage = NULL, unsigned long _address = 0)
            :   blocking(_block), allocated(false), type(_type), address(_address), 
                size(0), storage(NULL), result(-1), signalobject(NULL), next(NULL)
		{
			size    = _size;

			if(size != 0)
			{
					//�ΰ褬���ꤵ��Ƥʤ���硢ưŪ�˳��ݤ���
				if(_storage != NULL)
					storage = static_cast<HGLOBAL>(_storage);
				else
					allocate(size, false);
			}
		}

	public:
			//�ǥ��ȥ饯��
		virtual ~Request(void)
		{

				//�ΰ褬ưŪ���ݤ���Ƥ�����硢�˴���Ԥ�
			if(storage != NULL && allocated)
			{
				BOOL lock;

				enter_system_critical_section(&lock);
	            ::GlobalFree(storage);
				leave_system_critiacl_section(&lock);
			}
		}

		static void initialize(void)
		{
            kprintf(("Request::initialize()\n"));
			if(RequestCount == -1)
			{
				::InitializeCriticalSection(&cs);
				RequestCount = 0;
				top  = NULL;
				tail = NULL;
			}
		}

		static void finalize(void)
		{
            kprintf(("Request::finalize()\n"));
			if(RequestCount != -1)
			{
				while(top != NULL)
				{
					Request * target = top;
					top = top->next;
					delete target;
				}

				::DeleteCriticalSection(&cs);	
				RequestCount = -1;
			}
		}

			// �����ƥ���å����ʤ��ǥ��곫��
		inline void release(void)
		{
			if(storage != NULL && allocated)
			{
				::GlobalFree(storage);
				storage = 0;
			}
		}

		inline bool isBlockingRequest(void) const
		{	return blocking;	}

		inline enum tagRequestType getType(void) const
		{	return type;	}

		inline bool operator == (enum tagRequestType _type) const
		{	return type == _type;	}

		inline bool operator != (enum tagRequestType _type) const
		{	return !(operator ==(_type));	}

		inline void * getStorage(void)
		{	return reinterpret_cast<void *>(storage);	}

		inline unsigned long getAddress(void) const
		{	return address;   }

		inline unsigned long getSize(void) const
		{	return size;	}

		inline int getResult(void) const
		{	return result;	}

		static inline LONG getRequestCount(void)
		{	return RequestCount;	}

			//�ΰ�γ���
			//	_size   : ɬ�פȤ����ΰ�Υ�����
			//	realloc : ���Ƥ��ݻ����뤫�ݤ�
		bool allocate(unsigned int _size, bool realloc = false)
		{
			unsigned long old_size;
			HGLOBAL       old_storage;
			BOOL          lock;

			FatalAssertion(type != Confirmation, "Request::allocate was performed with Confirmation Request Object.");

			old_size    = size;
			old_storage = storage;

			enter_system_critical_section(&lock);
			storage = ::GlobalAlloc(GMEM_FIXED, _size);

			FatalAssertion(storage != NULL, "Request::allocate failed to allocate a memory block.");

				//�������Ƥ��ݻ� ������ΰ��˴�
			if(old_storage != NULL)
			{
				if(realloc)
					::CopyMemory(storage, old_storage, old_size);

				if(allocated)
					::GlobalFree(old_storage);
			}
			leave_system_critiacl_section(&lock);

			allocated = true;
			size = _size;

			return true;
		}

			//���Ƥ��ݻ������ޤ޺ƥ�������
		inline bool reallocate(unsigned int _size)
		{	return allocate(_size, true);   }

			//�ݻ��ΰ���Ф�������
		inline void set(void * data, unsigned int sz, unsigned int offset = 0)
		{
			if(size < sz)
				reallocate(sz + offset);

			::CopyMemory(reinterpret_cast<char *>(storage) + offset, data, sz);
		}

			//�ݻ��ΰ���Ф����ɹ���
		inline bool get(void * data, unsigned int sz, unsigned int offset = 0)
		{
			if(size < sz + offset)
				return false;

			::CopyMemory(data, reinterpret_cast<char *>(storage) + offset, sz);
		}

			//�ݻ��ΰ��Ǥ�դΰ��֤��Ф���ݥ��󥿼���
			//		offset : ��Ƭ����ΥХ��ȥ��ե��å�
		void * getptr(unsigned int offset = 0)
		{
			if(offset > size || storage == NULL)
				return NULL;

			return reinterpret_cast<void *>(reinterpret_cast<char *>(storage) + offset);
		}

			/*
			 *   Request���֥������ȥե����ȥ�
			 *     Q: �ɤ����ƥե����ȥ꤬ɬ�פʤΤ�?
			 *     A: ������ݤ������CPU���å�����ɬ�פ����뤿�� (�ܺ٤Ͼ嵭CPU��å�������ͳ�򻲾�)
			 */			
		static Request * Create(enum tagRequestType _type, bool _block, unsigned int _size = 0, void * _storage = NULL, unsigned long _address = 0)
		{
			Request * request;
			BOOL      lock;

			enter_system_critical_section(&lock);
			request = new Request(_type, _block, _size, _storage, _address);
			leave_system_critiacl_section(&lock);
		
			return request;
		}

		static Request * GetRequest(void)
		{
			Request * result;

			::EnterCriticalSection(&cs);
			result = top;
			if(top != NULL)
			{
				top = top->next;
				if(top == NULL)
					tail = NULL;
			}
			::LeaveCriticalSection(&cs);

			::InterlockedDecrement(&RequestCount);

			return result;
		}

		void Finalize(bool succeeded)
		{
			if(this != 0) {
				if(isBlockingRequest())
					signal(succeeded ? getSize() : -1);
				else
				{
					BOOL lock;

					enter_system_critical_section(&lock);
					delete this;
					leave_system_critiacl_section(&lock);
				}
			}
		}

        virtual void signal(int _result = 0)
		{
			result = _result;
			if(signalobject != NULL)
				::PostThreadMessage((DWORD)signalobject, WM_QUIT, 0, 0);
		}
				
			/*
			 *   �������׵��ȯ��
			 *     (���δؿ���Ȥ�����å� : ��������å�, ����ߥ���å�, ����������å�)
			 */
		virtual int invoke(void)
		{
			int  _result;
			BOOL lock;
			MSG  msg;

			_result = 0;

			if(!IsValid())
				return -1;

			enter_system_critical_section(&lock);

			connect();

				//�׵�μ¹��Ԥ�
			if(blocking)
			{
				signalobject = (HANDLE)::GetCurrentThreadId();

					//�������׵����������Ȥ�����
				::ReleaseSemaphore(request_semaphore,1,NULL);
				leave_system_critiacl_section(&lock);

					//WM_QUIT��å�������Ȥä�Ʊ������
				while(::GetMessage(&msg, 0, 0, 0) != 0)
					::DispatchMessage(&msg);

					//���Υ��֥������Ȥ��˴�����ΤǥХå����åפ���
				_result = result;

					//���塼����Ϥ��������Ϻ�ȥ���åɤ����
					//delete request�ϡ��Υ�֥�å��󥰤ʤ��ȥ���å���Ǥ���֥�å��󥰤ʤ餳���Ǥ��
                enter_system_critical_section(&lock);
				delete this;
                leave_system_critiacl_section(&lock);
			}else
			{
					//�������׵����������Ȥ�����
				::ReleaseSemaphore(request_semaphore,1,NULL);
				leave_system_critiacl_section(&lock);
			}

			return _result;
		}
	};

	class EventDumpRequest : public Request
	{
	protected:
		static HANDLE FileHandle;

		EventDumpRequest(enum tagRequestType _type, bool _block, unsigned int _size = 0, void * _storage = NULL, unsigned long _address = 0) : Request(_type, _block, _size, _storage, _address) 
		{}

	public:
		static void initialize(void)
		{
			SYSTEMTIME systim;
			DWORD      written;
			char       buffer[1024];
			char *     top;
			char *     work;

			::GetLocalTime(&systim);
			::wsprintf(buffer, "kernel-log-%04d%02d%02d-%02d%02d%02d.log", systim.wYear, systim.wMonth, systim.wDay, systim.wHour, systim.wMinute, systim.wSecond);
			FileHandle = ::CreateFile(buffer, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN, NULL);

            kprintf(("EventDumpRequest : initialize (filename = '%s')\n", buffer));

			T_RGLOG_HEADER log;
			
			log.logtype = LOG_TIMESTAMP;
			log.logtim  = 0;
			log.bufsz   = sizeof(SYSTEMTIME);
			log.valid   = 1;
			::WriteFile(FileHandle, &log, sizeof(log), &written, NULL);
			::WriteFile(FileHandle, &systim, sizeof(SYSTEMTIME), &written, NULL);

				/* �⥸�塼��̾����Ф� */
			::lstrcpyn(buffer, ::GetCommandLine(), 1023);
			top = buffer;
			buffer[1023] = '\x0';	//����������ʼ

			if(*top == '"')
			{
				++ top;
				for(work = top; *work != '\x0' && *work != '"'; ++work);
			}
			else
				for(work = top; *work != '\x0' && *work != ' '; ++work);

			*work = '\x0';	//�����ߥ͡��Ƚ���

			log.logtype = LOG_MODULENAME;
			log.logtim  = 0;
			log.bufsz   = work - top + 1;	//�����ߥ͡�����ʬ
			log.valid   = 1;
			::WriteFile(FileHandle, &log, sizeof(log), &written, NULL);
			::WriteFile(FileHandle, top, log.bufsz, &written, NULL);
		}

		static void finalize(void)
		{
            kprintf(("EventDumpRequest : finalize()\n"));

			if(FileHandle != INVALID_HANDLE_VALUE)      //CreateFile returns INVALID_HANDLE_VALUE if it failed
				::CloseHandle(FileHandle);
		}

		static EventDumpRequest * Create(enum tagRequestType _type, bool _block, unsigned int _size = 0, void * _storage = NULL, unsigned long _address = 0)
		{
			EventDumpRequest * request;
			BOOL      lock;

			enter_system_critical_section(&lock);
			request = new EventDumpRequest(_type, _block, _size, _storage, _address);
			leave_system_critiacl_section(&lock);
		
			return request;
		}

		virtual int invoke(void)
		{
			DWORD written;
			BOOL  lock;

			enter_system_critical_section(&lock);
			if(FileHandle != INVALID_HANDLE_VALUE)      //CreateFile return INVALID_HANDLE_VALUE, not NULL, if it failed its operatation.
				::WriteFile(FileHandle, storage, size, &written, NULL);
			delete this;
			leave_system_critiacl_section(&lock);

			return 0;
		}
	};

    class ExclusiveDeviceRequest : public Request
    {
    protected:
        static HANDLE blocker;
    public:

        static void initialize(void) throw()
        {
            kprintf(("ExclusiveDeviceRequest::initialize()\n"));

            if(blocker == NULL) {
                blocker = ::CreateEvent(NULL, FALSE, FALSE, NULL);
            }
        }

        static void finalize(void) throw()
        {
            kprintf(("ExclusiveDeviceRequest::finalize()\n"));

            if(blocker != NULL) {
                ::CloseHandle(blocker);
            }
        }

        virtual void signal(int _result = 0)
        {
            result = _result;
            ::SetEvent(blocker);
        }

        virtual int invoke(void)
        {
            int  _result = 0;
            BOOL lock;
            BOOL cpustate;

                //�����ߤ�ػߤ���
            if((cpustate = CPUStatus) == 0)
                dis_int(0);

            enter_system_critical_section(&lock);

                //�׵�򥭥塼����Ƭ�ˤĤʤ�
            ::EnterCriticalSection(&cs);
            next = top;
            top = this;
            if(tail == NULL)
                tail = this;
            ::LeaveCriticalSection(&cs);
            ::InterlockedIncrement(&RequestCount);

            ::ReleaseSemaphore(request_semaphore, 1, NULL);
            leave_system_critiacl_section(&lock);

            if(blocking) {
                ::WaitForSingleObject(blocker, INFINITE);

                _result = result;

                enter_system_critical_section(&lock);
                delete this;
                leave_system_critiacl_section(&lock);
            }

            if(cpustate == 0)
                ena_int(0);

            return _result;
        }
    };

//	typedef class EventDumpRequest EventRequest;
	typedef class Request EventRequest;		//���٥�ȥ������׵�ǻ��Ѥ����ꥯ������
//	typedef class Request DeviceRequest;	//�ǥХ����̿��׵�ǻ��Ѥ����ꥯ������
	typedef class ExclusiveDeviceRequest DeviceRequest;	//�ǥХ����̿��׵�ǻ��Ѥ����ꥯ������

	//==============================================================================

	LONG				Request::RequestCount = -1;	//���塼�ˤĤʤ��äƤ���ꥯ�����Ȥο�
	Request *			Request::top  = NULL;		//�ꥯ�����ȥ��塼����Ƭ (��äȤ�Ť��ꥯ������)
	Request *			Request::tail = NULL;		//�ꥯ�����ȥ��塼������ (��äȤ⿷�����ꥯ������)
	CRITICAL_SECTION	Request::cs;				//��¾���塼����Ѵ��ΰ襪�֥�������

	HANDLE              EventDumpRequest::FileHandle    = INVALID_HANDLE_VALUE;     //CreateFile uses INVALID_HANDLE_VALUE for identifying an invalid instance 
    HANDLE              ExclusiveDeviceRequest::blocker = NULL;

	//==============================================================================

		/*
		 *   ��ȥ���åɤ����Ѥ����ȴؿ������
		 */

		//���ͥ������ݥ���Ȥؤ���³
	bool Advise(IUnknown * container, REFIID iid, IUnknown * sink, DWORD * cookie, IConnectionPoint ** p_cp = NULL)
	{
		IConnectionPointContainer * cp_container;
		IConnectionPoint * cp;

        if(container == 0 || sink == 0 || cookie == 0)
            return false;

		if(p_cp == 0)
			p_cp = &cp;

			//IUnknown���󥿥ե���������IConnectionPointContainer�إ��㥹��
		container->QueryInterface(IID_IConnectionPointContainer, (void **)&cp_container);
		if(cp_container == 0)
			return false;

			//ConnectionPointContainer�����׵�˹礦ConnectionPoint��õ��
		cp_container->FindConnectionPoint(iid, p_cp);
		cp_container->Release();
		if(*p_cp == 0)
			return false;

			//���ͥ������ݥ������³
		if(FAILED((*p_cp)->Advise(sink, cookie)))
			return false;

		if(p_cp == &cp)
			cp->Release();
		return true;
	}

	//==============================================================================
	
    /*
     *  PerformRequest : �׵�μ¹�
     *     �ֵ��� : ���٥�Ƚ������³����(true) or ��ȥ���åɤ���ߤ�����(false)
     */

    bool PerformRequest(IKernel * manager)
    {
        Request * request;
        bool succeeded;

			//���塼����ꥯ�����Ȥ�ȴ�����
		request = Request::GetRequest();
		FatalAssertion(request != NULL,"");

			//��λ�׵�
		if(request->getType() == Request::QuitThread)
		{
			if(!request->isBlockingRequest())
			{
				BOOL lock;

				enter_system_critical_section(&lock);
				delete request;
				leave_system_critiacl_section(&lock);
			}
            return false;
		}

			//�׵���ν���
		switch(request->getType())
		{
		case Request::Confirmation:
			succeeded = true;
			break;

		case Request::DeviceRead:
			succeeded = SUCCEEDED(manager->Read(request->getAddress(), request->getSize(), reinterpret_cast<char *>(request->getStorage())));
			break;

		case Request::DeviceWrite:
			succeeded = SUCCEEDED(manager->Write(request->getAddress(), request->getSize(), reinterpret_cast<char *>(request->getStorage())));
			break;

		case Request::EventLog:
			succeeded = SUCCEEDED(manager->OnLogEvent(request->getSize(), reinterpret_cast<unsigned char *>(request->getStorage())));

				//����åȥ�������ʤ���������Ϥ�����ޤ��ԤäƤ�餦
			ShutdownPostponementRequest = TRUE;
			break;

		default:
			succeeded = false;
		}

        request->Finalize(succeeded);

        return true;
    }

		/*
		 *   COM�̿���Ԥ�����κ�ȥ���å� ����
		 */
	DWORD WINAPI WorkerThreadProcess(LPVOID _param)
	{
		IKernel * manager;
		IKernelEvents * sink;
		IConnectionPoint * cp;
		DWORD cookie;
		BOOL Success;

        kprintf(("WorkerThreadProcess : start\n"));

			/* ����� */
		::CoInitialize(NULL);

			// �ǥХ����ޥ͡��������³
		manager = 0;
		if(FAILED(::CoCreateInstance(CLSID_Kernel, NULL, CLSCTX_ALL, IID_IKernel, (void **)&manager)))
			goto _WorkerThreadProc_Cleanup;

		cp = 0;
        sink = new(std::nothrow) IKernelEvents;
		if(!Advise(manager, IID_IKernelEvents, sink, &cookie,&cp))
		{
            if(sink != 0)
    			delete sink;
			goto _WorkerThreadProc_Cleanup;
		}

			/* �ᥤ��롼���� */
		manager->IsValid(&Success);
		if(Success != 0)
		{
            MSG msg;
			DWORD work;
            bool  loop_flag = true;
			
			do {
                    /*
                     * ��������COM�򤿤����ȥ�å������Ȥ�������Ǥ��뤿�ᡢWaitForSingleObject�ǥ��ޥե����ԤĤȳ���������׵��¹ԤǤ��ʤ��ʤ롣
                     * ���Τ��ᡢMsgWaitFor...���Ѥ�����å�����������Ǥ������Ϥ�����н�Ǥ���褦�ˤ��롣
                     */

                    /*
                     * cygwin�Ķ�����QS_ALLPOSTMESSAGE���������ʤ��Τǡ�������н�
                     */
#ifndef QS_ALLPOSTMESSAGE
#define QS_ALLPOSTMESSAGE (0x0100)
#endif

                    //�׵��Ԥ�
                work = ::MsgWaitForMultipleObjects(1, &request_semaphore, FALSE, INFINITE, QS_ALLPOSTMESSAGE);

                switch(work) {

                    //�����׵�μ¹�
                case WAIT_OBJECT_0:
                        loop_flag = PerformRequest(manager);
                        break;

                    //����������׵� (����ߤʤ�)
                case WAIT_OBJECT_0 + 1:
                        GetMessage(&msg, 0, 0, 0);
                        TranslateMessage(&msg);
                        DispatchMessage(&msg);
                        break;
                
                default:
                    loop_flag = false;
                }

			} while(loop_flag);
		}

			/*
			 * Finalize
			 */

		if(cp != 0)
		{
			cp->Unadvise(cookie);
			cp->Release();
			cp = 0;
			sink = 0;
		}

	_WorkerThreadProc_Cleanup:

        if(manager != 0)
			manager->Release();

		CloseHandle(worker_thread_handle);
		worker_thread_handle = NULL;
        manager = 0l;
		::CoUninitialize();

		/* ���塼����ˤ��� (�Ԥ����) */

		Request * request;
		while((request = Request::GetRequest()) != 0)
			request->Finalize(false);
		
        kprintf(("WorkerThreadProcess : exit\n"));

        return 0;
	}
}

//==============================================================================

/****************************************************
 *                                                  *
 * TOPPERS/JSP - Windows���ߥ�졼�����Ķ�        *
 *   COM���Ѥ����ǥХ������ߥ�졼�����ǽ        *
 *                                                  *
 ****************************************************/

#ifdef DEVICE_ENABLE

extern "C"
int _cdecl DeviceRead(unsigned long address, unsigned long size, void * storage)
{
	if(!IsValid() || storage == NULL)
		return -1;

	return DeviceRequest::Create(Request::DeviceRead, true, size, storage, address)->invoke();
}

extern "C"
int _cdecl DeviceWrite(unsigned long address, unsigned long size, void * storage)
{
	if(!IsValid() || storage == NULL)
		return -1;

	return DeviceRequest::Create(Request::DeviceWrite, true, size, storage, address)->invoke();
}

#endif


/****************************************************
 *                                                  *
 * TOPPERS/JSP - Windows���ߥ�졼�����Ķ�        *
 *   COM���Ѥ��������ͥ��������ǽ                *
 *                                                  *
 ****************************************************/

#ifdef EVENTLOG_ENABLE

	/* ¿�ť������ɻ��ѥ��ޥե� :  1��­������̤�1�Ǥ��ä��Ȥ�������������ϤǤ��� */
static LONG event_write_semaphore = 0;

void event_write(unsigned int logtype, unsigned int valid, UINT bufsz, ... )
{
	EventRequest * event_request;
	DBIFLOG * log;
	va_list   vl;

	if(IsValid() && TlsGetValue(TLS_LOGMASK) == 0)
	{
			// �ꥯ�������ΰ����
		event_request = EventRequest::Create(EventRequest::EventLog, false, sizeof(T_RGLOG_HEADER) + bufsz);
		log     = reinterpret_cast<DBIFLOG *>(event_request->getptr());

			// �إå�����
		log->header.logtype = logtype;
		log->header.logtim  = _kernel_systim_offset + _kernel_current_time;
		log->header.valid   = valid;
		log->header.bufsz   = bufsz;

			// ���Τγ�Ǽ
		va_start(vl, bufsz);
		for(unsigned int i=0;i<bufsz/sizeof(int);i++)
			*((int *)&log->body + i) = va_arg(vl, int);

			// �׵������ (Non-blocking)
		event_request->invoke();
	}
}

extern "C"
void event_write_svc_enter(int fncd, unsigned int params, ... )
{
	EventRequest * event_request;
	DBIFLOG *      log;
	va_list        vl;
	unsigned int   i;

	if(IsValid() && TlsGetValue(TLS_LOGMASK) == 0)
	{
			//�ΰ���� : ���ݤ��륵�����ϥѥ�᡼����������ʬ¿�� (�ƤӽФ������ɥ쥹���Ǽ)
		event_request = EventRequest::Create(EventRequest::EventLog, false, sizeof(T_RGLOG_HEADER) + sizeof(T_RGLOG_SVC) + params * sizeof(VP_INT));	
		log     = reinterpret_cast<DBIFLOG *>(event_request->getptr());

			//�ѥ��å�����
		log->header.logtype = LOG_TYPE_SVC;
		log->header.logtim  = _kernel_systim_offset + _kernel_current_time;
		log->header.valid   = 0x7fffffff >> (29 - params);
		log->header.bufsz   = (params+3) * sizeof(int);

		va_start(vl, params);

		log->body.svc.fncno  = fncd;
		log->body.svc.prmcnt = params;

			/* ���롼�פ�¿���ΤϺǸ�˸ƽи����ɥ쥹���Ѥ�Ǥ��뤿�� */
		for(i=0;i<params+1;i++)
			log->body.svc.prmary[i] = va_arg(vl, VP_INT);

		event_request->invoke();
	}
}

extern "C"
void event_write_svc_leave(int fncd, unsigned int ercd, unsigned int retaddr)
{
	EventRequest * event_request;
	DBIFLOG * log;

	if(IsValid() && TlsGetValue(TLS_LOGMASK) == 0)
	{
			//�ΰ���� : ���ݤ��륵�����ϥѥ�᡼�����(�ֵ��ͤΤߤʤΤǣ���)�����ʬ¿�� (�ƤӽФ������ɥ쥹���Ǽ)
		event_request = EventRequest::Create(EventRequest::EventLog, false, sizeof(T_RGLOG_HEADER) + sizeof(T_RGLOG_SVC) + sizeof(VP_INT));
		log     = reinterpret_cast<DBIFLOG *>(event_request->getptr());

			//�إå�������
		log->header.logtype = LOG_TYPE_SVC|LOG_LEAVE;
		log->header.logtim  = _kernel_systim_offset + _kernel_current_time;
		log->header.valid   = 0x7;
		log->header.bufsz   = 4 * sizeof(int);

			//�ܥǥ�������
		log->body.svc.fncno     = fncd;
		log->body.svc.prmcnt    = 1;
		log->body.svc.prmary[0] = (VP_INT)ercd;
		log->body.svc.prmary[1] = (VP_INT)retaddr;

		event_request->invoke();
	}
}

extern "C" void decode_taskstatus(void * tcb, int * tskid, unsigned int * tskstat, unsigned int * objtype, int * objid);

extern "C" 
void event_write_tskstat(void * tcb)
{
	EventRequest * event_request;
	DBIFLOG * log;

	if(IsValid())	//����ϥ����ͥ����ʤΤ�TLS_LOGMASK�򸫤ƤϤ����ʤ�
	{
			//�ΰ����
		event_request = EventRequest::Create(EventRequest::EventLog, false, sizeof(T_RGLOG_HEADER) + sizeof(T_RGLOG_TSKSTAT));
		log     = reinterpret_cast<DBIFLOG *>(event_request->getptr());

		log->header.logtype = LOG_TYPE_TSKSTAT;
		log->header.logtim  = _kernel_systim_offset + _kernel_current_time;
		log->header.valid   = 0xf;
		log->header.bufsz   = 4 * sizeof(int);

		decode_taskstatus(tcb, &log->body.tskstat.tskid, &log->body.tskstat.tskstat, &log->body.tskstat.tskwait, &log->body.tskstat.wobjid);

		event_request->invoke();
	}
}

#endif


static BOOL CALLBACK NotifyDialogProc(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	switch(Msg)
	{
	case WM_INITDIALOG:
		{
			LONG  count;
			HWND  hCtrl;
			
			hCtrl = ::GetDlgItem(hDlg, IDC_PROGRESS1);
			count = Request::getRequestCount();

			::SetWindowLong(hDlg, GWL_USERDATA, count);
			::SendMessage(hCtrl, PBM_SETRANGE32, 0, count);
			::SendMessage(hCtrl, PBM_SETPOS, count - Request::getRequestCount(), 0);

			::SetTimer(hDlg, 100, 200, NULL);
			break;
		}

	case WM_TIMER:
		if(wParam == 100)
		{
			LONG  count;
			HWND  hCtrl;

			hCtrl = ::GetDlgItem(hDlg, IDC_PROGRESS1);
			count = ::GetWindowLong(hDlg, GWL_USERDATA);

			::SendMessage(hCtrl, PBM_SETPOS, count - Request::getRequestCount(), 0);

			if(Request::getRequestCount() <= 0)
				::PostQuitMessage(0);
		}
		break;
	case WM_CLOSE:
		break;

	default:
		return FALSE;
	}
	return TRUE;
}

extern "C"
void _cdecl InitializeComSupportModule(void)
{
    kprintf(("InitializeComSupportModule()\n"));

	Request::initialize();
	DeviceRequest::initialize();
	EventRequest::initialize();


	request_semaphore = ::CreateSemaphore(0, 0, 65536, 0);
	FatalAssertion(request_semaphore != NULL, "Object Creation Error : request_semaphore");

	worker_thread_handle = ::CreateThread(0, 0, WorkerThreadProcess, 0, 0, 0);
	FatalAssertion(worker_thread_handle != NULL, "Object Creation Error : worker_thread");

	Request * request = Request::Create(Request::Confirmation, true);
	request->invoke();
}

extern "C"
void _cdecl FinalizeComSupportModule(void)
{
    kprintf(("FinalizeComSupportModule()\n"));

    if(IsValid())
	{
		HWND  hDlgitem;
		HWND  NotifyDialog;
		MSG   msg;

			//����ί�ޤꤹ����ȥ��Ǥ��˻��֤������ꡢ�ץ���ब˽�������褦�˸�����Τ�
			//�֥����Ǥ��Ƥ뤫���Ԥơפȷٹ��Ф���
		NotifyDialog = ::CreateDialog(ProcessInstance, MAKEINTRESOURCE(QUITNOTICEDIALOG), NULL, NotifyDialogProc);
		hDlgitem     = ::GetDlgItem(NotifyDialog, IDC_NOTIFYMSG);
		::SetWindowText(hDlgitem, "�� ������̿�����ͥ�Υ��٥�ȥ���Ф��Ƥ���Τǡ�����ޤǾ����ԤäƤ�������");
		::ShowWindow(NotifyDialog, SW_NORMAL);

		Request * request = Request::Create(Request::QuitThread, false);
		request->invoke();

			//��λ���������ѤΥ�å������ݥ��

        if(NotifyDialog != NULL) {
            while(GetMessage(&msg, NULL, 0, 0) != 0) {
        	    TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

			//�����ȥ���åɤ���λ����ޤ��Ե�
		if(worker_thread_handle != NULL)
            ::WaitForSingleObject(worker_thread_handle, INFINITE);
		::CloseHandle(request_semaphore);
        request_semaphore = NULL;

		EventRequest::finalize();
		DeviceRequest::finalize();
		Request::finalize();

		::DestroyWindow(NotifyDialog);
	}
}


#else	// __COM_NOT_REQUIRED__

extern "C"
void _cdecl InitializeComSupportModule(void)
{}

extern "C"
void _cdecl FinalizeComSupportModule(void)
{}

#endif // __COM_NOT_REQUIRED__
