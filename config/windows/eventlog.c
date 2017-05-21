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
 *  @(#) $Id: eventlog.c,v 1.7 2003/12/15 07:19:22 takayuki Exp $
 */


#include <s_services.h>

#ifdef EVENTLOG_ENABLE

#include "jsp_kernel.h"
#include "task.h"
#include "semaphore.h"
#include "dataqueue.h"
#include "eventflag.h"
#include "mempfix.h"
#include "mailbox.h"

//#include <kernel_debug.h>

extern SEMCB 	semcb_table[1];
extern UINT		tmax_semid;
extern FLGCB	flgcb_table[1];
extern UINT		tmax_flgid;
extern DTQCB 	dtqcb_table[1];
extern UINT		tmax_dtqid;
extern MBXCB 	mbxcb_table[1];
extern UINT		tmax_mbxid;
extern MPFCB 	mpfcb_table[1];
extern UINT		tmax_mpfid;

/*
 *  ���٥�ȥ������� ���������ּ����ؿ�
 *    (com_support.c��C++�ˤʤ�Τǡ��������֤�)
 */

Inline BOOL is_inside_of(void * src, void * min, void * sup)
{	return ((long)src >= (long)min) && ((long)src <  (long)sup);	}

static void decode_waitstatus(TCB * tcb, unsigned int * objtype, int * objid)
{
	QUEUE * queue;

	if((tcb->tstat & TS_WAIT_SLEEP) != 0)
	{
		*objtype = TTW_SLP;
	}else
	{
		if((tcb->tstat & TS_WAIT_WOBJCB) != 0)
		{
			do {
				queue = tcb->task_queue.next;
			} while( queue != &tcb->task_queue && is_inside_of(queue, tcb_table, &tcb_table[TNUM_TSK]) );

			if(queue == &tcb->task_queue)
				*objtype = 0;

				/* ���ޥե� */
			else if(is_inside_of(queue, semcb_table, &semcb_table[tmax_semid-1]))
			{
				*objtype = TTW_SEM;
				*objid   = ((long)queue - (long)semcb_table) / sizeof(SEMCB) + 1;
			}
				/* ���٥�ȥե饰 */
			else if(is_inside_of(queue, flgcb_table, &flgcb_table[tmax_flgid-1]))
			{
				*objtype = TTW_FLG;
				*objid   = ((long)queue - (long)flgcb_table) / sizeof(FLGCB) + 1;
			}
				/* �ǡ������塼 */
			else if(is_inside_of(queue, dtqcb_table, &dtqcb_table[tmax_dtqid-1]))
			{
				if(((long)queue % sizeof(DTQCB)) == (long)(&((DTQCB *)0)->rwait_queue))
					*objtype = TTW_RDTQ;
				else
					*objtype = TTW_SDTQ;
				*objid   = ((long)queue - (long)dtqcb_table) / sizeof(DTQCB) + 1;
			}
				/* �᡼��ܥå��� */
			else if(is_inside_of(queue, mbxcb_table, &mbxcb_table[tmax_mbxid-1]))
			{
				*objtype = TTW_MBX;
				*objid   = ((long)queue - (long)mbxcb_table) / sizeof(MBXCB) + 1;
			}
				/* ����Ĺ����ס��� */
			else if(is_inside_of(queue, mpfcb_table, &mpfcb_table[tmax_mpfid-1]))
			{
				*objtype = TTW_MPL;
				*objid   = ((long)queue - (long)mpfcb_table) / sizeof(MPFCB) + 1;
			}
		}else
		{
				/* slp_tsk�ǤϤʤ������֥��������Ԥ����塼�ˤĤʤ���Ƥ��ʤ������ॢ�����դ����Ԥ� -> dly_tsk */
			if(tcb->winfo->tmevtb != NULL)
				*objtype = TTW_DLY;
		}
	}
}

void decode_taskstatus(TCB * tcb, int * tskid, unsigned int * tskstat, unsigned int * objtype, int * objid)
{
	int stat = tcb->tstat;

		/* ������ID */
	*tskid = TSKID(tcb);

		/* ���������� */
	*tskstat = TTS_DMT;
	if((stat & TS_RUNNABLE) != 0)
	{
		*tskstat = TTS_RDY;
	}else
	{
		if((stat & TS_WAITING) != 0)
		{
				/* �Ԥ�����Υǥ����� */
			decode_waitstatus((TCB *)tcb, objtype, objid);

			if((stat & TS_SUSPENDED) != 0)
				*tskstat = TTS_WAS;
			else
				*tskstat = TTS_WAI;
		}else
		{
			if((stat & TS_SUSPENDED) != 0)
				*tskstat = TTS_SUS;
		}
	}
}

#endif

