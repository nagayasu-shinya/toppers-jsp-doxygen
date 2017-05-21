/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RICOH COMPANY,LTD. JAPAN
 * 
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ��� 
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ����(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ�������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: serial_mini.c,v 1.4 2007/01/05 02:33:59 honda Exp $
 */

/*
 *	���ꥢ�륤�󥿥ե������ɥ饤��
 */

#include <t_services.h>
#include <serial.h>
#include <hw_serial.h>
#include "kernel_id.h"

/*
 *  ���ꥢ��ݡ��ȴ����֥�å������
 */

#define	SERIAL_BUFSZ	9	/* ���ꥢ�륤�󥿥ե������ѥХåե��Υ����� */

typedef struct serial_queue_block {
	BOOL openflag;				/* �����ץ�Ѥߥե饰 */
	UH   base;					/* hardware port base address */
	ID   rsemid;				/* receive semaphore id */
	ID   ssemid;				/* send semaphore id */
	char head;					/* queue head */
	char tail;					/* queue tail */
	char size;					/* �Хåե������� */
	char buffer[SERIAL_BUFSZ];	/* �Хåե����ꥢ */
} SQUE;

static SQUE	in_queue[TNUM_SIOP] ={
	FALSE, TADR_SFR_UART0_BASE, SERIAL_RCV_SEM1, SERIAL_SND_SEM1, 0, 0, SERIAL_BUFSZ, "",
	FALSE, TADR_SFR_UART1_BASE, SERIAL_RCV_SEM2, SERIAL_SND_SEM2, 0, 0, SERIAL_BUFSZ, ""
};

/*
 *  ���ꥢ��ݡ��ȴ����֥�å�������Ƚ����
 */

#define get_sque(portid)	(&(in_queue[portid-1]))

/*
 *  SFR UART�ν����
 */
Inline void
SFR_uart_initialize(ID portid)
{
	SQUE  *q;
	VB *ip = (VB*)(TADR_SFR_INT_BASE+TADR_SFR_S0RIC_OFFSET);

	q = get_sque(portid);
	  			/* �������⡼�ɥ쥸�����ν���� */
	sil_wrb_mem((VP)(q->base+TADR_SFR_UMR_OFFSET), MR_DEF);
				/* ��������쥸�����ν���� */
	sil_wrb_mem((VP)(q->base+TADR_SFR_UC0_OFFSET), C0_DEF);
				/* ž��®�٥쥸�����ν���� */
	sil_wrb_mem((VP)(q->base+TADR_SFR_UBRG_OFFSET), BRG1_DEF);
				/* ����ߥ�٥������ */
	set_ic_ilvl((VP)(ip + ((INT)portid-1)*2), RB_LEVEL);
	sil_wrb_mem((VP)(q->base+TADR_SFR_UC1_OFFSET), C1R_DEF);
	sil_reb_mem((VP)(q->base+TADR_SFR_URB_OFFSET));		/* ���ߡ��ǡ������� */
	sil_reb_mem((VP)(q->base+TADR_SFR_URB_OFFSET));		/* ���ߡ��ǡ������� */
	q->openflag = TRUE;
}

/*
 *  SQUE�μ����Хåե����饵��������Ф�
 */
Inline int
queue_size(SQUE *q)
{
	int size = q->head - q->tail;
	if(size < 0)
		size += q->size;
	return size;
}

/*
 *  ���ꥢ�륤�󥿥ե������ɥ饤�Фε�ư
 */
void
serial_initialize(VP_INT exinf)
{
	SFR_uart_initialize(LOGTASK_PORTID);
}

/*
 *  ���ꥢ��ݡ��ȤΥ����ץ�
 */
ER
serial_opn_por(ID portid)
{
	SQUE  *q;
	VB    *ip=(VB*)(TADR_SFR_INT_BASE+TADR_SFR_S0RIC_OFFSET);
	ER	ercd;

	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �ݡ����ֹ�Υ����å� */
	}
	q = get_sque(portid);

	_syscall(loc_cpu());
	if (q->openflag) {		/* �����ץ�Ѥߤ��Υ����å� */
		ercd = E_OBJ;
	}
	else {
		SFR_uart_initialize(portid);
		ercd = E_OK;
	}
	_syscall(unl_cpu());
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��ȤΥ�����
 */
ER
serial_cls_por(ID portid)
{
	SQUE  *q;
	VB    *ip=(VB*)(TADR_SFR_INT_BASE+TADR_SFR_S0RIC_OFFSET);
	ER	ercd;

	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �ݡ����ֹ�Υ����å� */
	}
	q = get_sque(portid);

	_syscall(loc_cpu());
	if (!(q->openflag)) {	/* �����ץ�Ѥߤ��Υ����å� */
		ercd = E_OBJ;
	}
	else {
		set_ic_ilvl((VP)(ip + ((INT)portid-1)*2), 0);
		sil_wrb_mem((VP)(q->base+TADR_SFR_UC1_OFFSET), C1S_DEF);
		q->openflag = FALSE;
		ercd = E_OK;
	}
	_syscall(unl_cpu());
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥؤ�����
 */

ER_UINT
serial_wri_dat(ID portid, char *buf, UINT len)
{
	SQUE	*q;
	unsigned int	i;
	unsigned char   c;

	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �ݡ����ֹ�Υ����å� */
	}

	q = get_sque(portid);
	if (!(q->openflag)) {	/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}

	wai_sem(q->ssemid);
	for (i = 0; i < len; i++) {
		while((sil_reb_mem((VP)(q->base+TADR_SFR_UC1_OFFSET)) & 0x2) == 0);
		sil_wrb_mem((VP)(q->base+TADR_SFR_UTB_OFFSET), *buf++);
	}
	sig_sem(q->ssemid);
	return(len);
}

/*
 *  ���ꥢ��ݡ��Ȥ���μ���
 */

ER_UINT
serial_rea_dat(ID portid, char *buf, UINT len)
{
	SQUE	*q;
	UINT	i;

	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �ݡ����ֹ�Υ����å� */
	}

	q = get_sque(portid);
	if (!(q->openflag)) {	/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}

	for (i = 0; i < len; i++) {
		if (queue_size(q) == 0)
			wai_sem(q->rsemid);
		else
			pol_sem(q->rsemid);
		_syscall(loc_cpu());
		*buf++ = q->buffer[q->tail++];
		if (q->tail >= q->size) {
			q->tail = 0;
		}
		_syscall(unl_cpu());
	}
	return(len);
}

/*
 *  ���ꥢ��ݡ��Ȥ�����
 */
ER
serial_ctl_por(ID portid, UINT ioctl)
{
	return(E_OK);
}

/*
 *  ���ꥢ��ݡ��Ⱦ��֤λ���
 */
ER
serial_ref_por(ID portid, T_SERIAL_RPOR *pk_rpor)
{
	SQUE	*q;

	if (sns_ctx()) {		/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �ݡ����ֹ�Υ����å� */
	}

	q = get_sque(portid);
	if (!(q->openflag)) {	/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}

	pk_rpor->reacnt = queue_size(q);
	pk_rpor->wricnt = 0;
	return(E_OK);
}

/*
 *  ���ꥢ��ݡ��ȳ���ߥ����ӥ��롼����
 */

void
serial_handler_in(ID portid)
{
	SQUE	*q;
	int		rdata;				/* �����Хåե� */

	q = get_sque(portid);
	if (queue_size(q) < q->size) {
		rdata = sil_reb_mem((VP)(q->base+TADR_SFR_URB_OFFSET));	/* �ǡ������� */
		q->buffer[q->head++] = rdata;
		if (q->head >= q->size)
			q->head = 0;
		isig_sem(q->rsemid);
	}
}

/*
 *  ����ߥϥ�ɥ�
 */

void
serial_in_handler1(void)
{
	serial_handler_in(1);
}

void
serial_in_handler2(void)
{
	serial_handler_in(2);
}

