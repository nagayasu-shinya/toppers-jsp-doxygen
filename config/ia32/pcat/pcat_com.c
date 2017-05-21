/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2002 by Monami software, Limited Partners.
 *  Copyright (C) 2002 by MURANAKA Masaki
 *  Copyright (C) 2008-     by Monami Software Limited Partnership, JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
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
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id$
 */

/*
 *	COM�ɥ饤�С�PC/AT�ѡ�
 */

#include <s_services.h>
#include <pcat_com.h>

#define PCAT_COM_IIR_RLS (0x06)
#define PCAT_COM_IIR_RXD (0x04)
#define PCAT_COM_IIR_TXD (0x02)

#define PCAT_COM_IER_LS (4)
#define PCAT_COM_IER_TX (2)
#define PCAT_COM_IER_RX (1)

#define PCAT_COM_RBR 0
#define PCAT_COM_THR 0
#define PCAT_COM_DLL 0
#define PCAT_COM_IER 1
#define PCAT_COM_DLM 1
#define PCAT_COM_IIR 2
#define PCAT_COM_FCR 2
#define PCAT_COM_LCR 3
#define PCAT_COM_MCR 4
#define PCAT_COM_LSR 5
#define PCAT_COM_MSR 6
#define PCAT_COM_SCR 7

#define PCAT_COM_DIVISOR_LATCH(a) (24000000 / 13 / 16 / (a))

#ifndef PCAT_COM1_BAUD_RATE
#define PCAT_COM1_BAUD_RATE 9600
#endif
#if TNUM_SIOP >= 2
#ifndef PCAT_COM2_BAUD_RATE
#define PCAT_COM2_BAUD_RATE 9600
#endif
#endif

/*
 *  ���٥�ݡ��Ⱦ�������֥�å��ν����
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{
		PCAT_COM1_BASE,
		TO_INTNO(PCAT_COM1_INHNO),
		PCAT_COM_DIVISOR_LATCH(PCAT_COM1_BAUD_RATE)
	},
#if TNUM_SIOP >= 2
	{
		PCAT_COM2_BASE,
		TO_INTNO(PCAT_COM2_INHNO),
		PCAT_COM_DIVISOR_LATCH(PCAT_COM2_BAUD_RATE)
	},
#endif
};
SIOPCB siopcb_table[TNUM_SIOP];

Inline UB pcat_com_read(UH base, UH offset) {
	return sil_reb_iop((VP)(base + offset));
}

Inline void pcat_com_write(UH base, UH offset, UB data) {
	sil_wrb_iop((VP)(base + offset), data);
}

/*
 *  ʸ���������������
 */
Inline BOOL
hw_port_getready(SIOPCB *p)
{
  UB stat;
  stat = pcat_com_read(p->siopinib->base_address, PCAT_COM_LSR);

  return ((stat & 0x01) != 0);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
hw_port_putready(SIOPCB *p)
{
  UB stat;
  stat = pcat_com_read(p->siopinib->base_address, PCAT_COM_LSR);

  return ((stat & 0x20) != 0);
}

SIOPCB *
pcat_com_set_mode(ID portid) {
  SIOPCB *p;

  p = &(siopcb_table[portid - 1]);
	if (p->initflag) {
		return p;
	}
  pcat_com_write(p->siopinib->base_address, PCAT_COM_IER, 0); // Disable interrupt.
  pcat_com_write(p->siopinib->base_address, PCAT_COM_LCR, 0x83); // DLAB=1, 8bit, stop=1, Non parity.
  pcat_com_write(p->siopinib->base_address, PCAT_COM_DLL, (UB)p->siopinib->divisor_latch);
  pcat_com_write(p->siopinib->base_address, PCAT_COM_DLM, (UB)(p->siopinib->divisor_latch >> 8));
  pcat_com_write(p->siopinib->base_address, PCAT_COM_LCR, 0x03); // DLAB=0, 8bit, stop=1, Non parity.
  pcat_com_write(p->siopinib->base_address, PCAT_COM_FCR, 0x07);  // Enable FIFO.


  pcat_com_read(p->siopinib->base_address, PCAT_COM_LSR);
  pcat_com_read(p->siopinib->base_address, PCAT_COM_RBR);
  pcat_com_read(p->siopinib->base_address, PCAT_COM_IIR);
  pcat_com_read(p->siopinib->base_address, PCAT_COM_MCR);

  p->initflag = TRUE;			/* ������ե饰���� */

  return p;
}

void pcat_com_isr(VP_INT exinf) {
	SIOPCB *p = (SIOPCB *)exinf;
	while (1) {
		switch (pcat_com_read(p->siopinib->base_address, PCAT_COM_IIR) & 7) {
		case PCAT_COM_IIR_TXD:
			pcat_com_ierdy_snd(p->spcb);
			break;
		case PCAT_COM_IIR_RXD:
			pcat_com_ierdy_rcv(p->spcb);
			break;
		case PCAT_COM_IIR_RLS:
			pcat_com_read(p->siopinib->base_address, PCAT_COM_LSR);
			break;
		default:
			return;
		}
	}
}

void
pcat_com_initialize()
{
	UINT i;
	for (i = 0; i < TNUM_SIOP; ++i) {
		siopcb_table[i].siopinib = &siopinib_table[i];
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥγ���ߥϥ�ɥ�
 */
void
pcat_com1_handler()
{
	pcat_com_isr(&siopcb_table[0]);
}
#if TNUM_PORT >= 2
void
pcat_com2_handler()
{
	pcat_com_isr(&siopcb_table[1]);
}
#endif

SIOPCB *
pcat_com_opn_por(ID portid, VP_INT spcb)
{
  SIOPCB *p;

  p = pcat_com_set_mode(portid);
  p->spcb = spcb;

  pcat_com_write(p->siopinib->base_address, PCAT_COM_MCR, 0x0b); // Enable OUT2 interrupt.

  return p;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥν�λ
 */
void
pcat_com_cls_por(SIOPCB *p)
{
    
  p->initflag = FALSE;
  pcat_com_write(p->siopinib->base_address, PCAT_COM_IER, 0); // Disable interrupt.
}

/*
 *  ��������ʸ���μ��Ф�
 */
INT
pcat_com_rcv_chr(SIOPCB *p)
{
  UB ch;
  
	if (!hw_port_getready(p)) {
		return -1;
	}
  ch = pcat_com_read(p->siopinib->base_address, PCAT_COM_RBR);
  return (INT)ch;
}

/*
 *  ��������ʸ���ν񤭹���
 */
BOOL
pcat_com_snd_chr(SIOPCB *p, char c)
{
  if (!hw_port_putready(p)) {
    return FALSE;
  }
  pcat_com_write(p->siopinib->base_address, PCAT_COM_THR, c);
  return TRUE;
}

void
pcat_com_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB ier = pcat_com_read(siopcb->siopinib->base_address, PCAT_COM_IER);
	if (cbrtn == SIO_ERDY_SND) {
		ier |= PCAT_COM_IER_TX;
	} else if (cbrtn == SIO_ERDY_RCV) {
		ier |= PCAT_COM_IER_LS | PCAT_COM_IER_RX;
	}
	pcat_com_write(siopcb->siopinib->base_address, PCAT_COM_IER, ier);
}

void
pcat_com_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB ier = pcat_com_read(siopcb->siopinib->base_address, PCAT_COM_IER);
	if (cbrtn == SIO_ERDY_SND) {
		ier &= ~PCAT_COM_IER_TX;
	} else if (cbrtn == SIO_ERDY_RCV) {
		ier &= ~(PCAT_COM_IER_LS | PCAT_COM_IER_RX);
	}
	pcat_com_write(siopcb->siopinib->base_address, PCAT_COM_IER, ier);
}

void pcat_com_init(ID siopid) {
	pcat_com_initialize();
	pcat_com_set_mode(siopid);
}

void pcat_com_putc(ID siopid, char c) {
	SIOPCB *p;
	p = &siopcb_table[siopid - 1];
	while (!pcat_com_snd_chr(p, c)) {
	}
}
