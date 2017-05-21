/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
 *  Copyright (C) 2008 by Takahisa Yokota
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
 *  @(#) $Id: mcfuart.c,v 1.3 2005/07/06 00:45:07 honda Exp $
 */

/*
 *   COLDFIRE��¢UART�� �ʰץɥ饤��
 */

#include <s_services.h>
#include "mcfuart.h"

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 */
/* �����ϥݡ��Ȥ������sys_config.c */
/* ����ߥ٥����ֹ�������hw_serial.h */
/* �����֥�å��������mcfuart.c */

#ifndef GDB_STUB

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{IPSBAR + 0x00000200, BRR9600, 0x0, 0x27}, /* UART0 */
#if TNUM_PORT >= 2
	{IPSBAR + 0x00000240, BRR9600, 0x0, 0x27}, /* UART1 */
#endif /* TNUM_PORT >= 2 */
};

#else /* GDB_STUB */

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{IPSBAR + 0x00000200, BRR9600, 0x0, 6}, /* SCIF2 */
};

#endif /* GDB_STUB */

#if defined(TTM)
/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 *  ��2ch���ݡ��Ȥ˳�ĥ������Ͻ�����ѤΥǡ�����ޤ��
 */
struct sio_port_control_block
{
	VP_INT exinf;				/* ��ĥ���� */
	BOOL openflag;				/* �����ץ�Ѥߥե饰 */
};
#endif
/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
static SIOPCB siopcb_table[TNUM_PORT];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ʸ��������Ǥ��뤫��
 */
Inline BOOL
mcfuart_getready (SIOPCB * siopcb)
{
  return (sil_reb_mem((VB *) (siopcb->siopinib->reg_base + MCF_UART_USR)) & MCF_UART_USR_RXRDY);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
mcfuart_putready (SIOPCB * siopcb)
{
  /* Wait until space is available in the FIFO */
  return (sil_reb_mem((VB*)(siopcb->siopinib->reg_base + MCF_UART_USR)) & MCF_UART_USR_TXRDY);
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
mcfuart_getchar (SIOPCB * siopcb)
{
	VB data;
        data = sil_reb_mem ((VB*)(siopcb->siopinib->reg_base + MCF_UART_URB));
	return data;
}

/*
 *  ��������ʸ���ν����
 */
Inline void
mcfuart_putchar (SIOPCB * siopcb, char c)
{
    /* Send the character */
    sil_wrb_mem ((VB*)(siopcb->siopinib->reg_base + MCF_UART_UTB), c);
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
mcfuart_initialize ()
{
	SIOPCB *siopcb;
	UINT i;
        /*
	 *  ���륢��I/O�ݡ��ȴ����֥�å��ν����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_PORT; siopcb++, i++) {
		siopcb->openflag = FALSE;
		siopcb->siopinib = (&siopinib_table[i]);
	}
}

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
BOOL
mcfuart_openflag (ID siopid)
{
	return (siopcb_table[siopid -1].openflag);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
mcfuart_opn_por (ID siopid, VP_INT exinf)
{
        volatile int i;
	SIOPCB *siopcb = get_siopcb(siopid);
        // �������
  	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCR), (VB) (MCF_UART_UCR_MISC_RR));
    	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCR), (VB) (MCF_UART_UCR_MISC_RT));
      	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCR), (VB) (MCF_UART_UCR_MISC_RRC));

        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UMR1), 0x93);
        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UMR2), 0x07);
        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCSR), 0xDD);

        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UBG1), (VB) (siopcb->siopinib->brr >> 8));
    	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UBG2), (VB) (siopcb->siopinib->brr & 0x00ff));

         /*  ����ߵ���  */
        siopcb->imr = (VB)MCF_UART_UIMR_RXRDY;
    	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UIMR), (VB) (siopcb->imr));

        /*  ����������  */
  	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCR), (VB) (MCF_UART_UCR_TC_EN | MCF_UART_UCR_RC_EN));

	siopcb->exinf = exinf;
        siopcb->openflag = TRUE;
        if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000200)) {  
          sil_wrw_mem ((VW*)MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem((VW*)MCF_INTC_IMRL(MCF_INTC0)) & (~(1 << (TBIT_GP0))));
        } else if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000240)) {
          sil_wrw_mem ((VW*)MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem((VW*)MCF_INTC_IMRL(MCF_INTC0)) & (~(1 << (TBIT_GP1))));
        }
        for (i = 0; i < 1000;i++);
	return (siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
mcfuart_cls_por (SIOPCB * siopcb)
{
	/*  �������ػ�  */
  	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCSR),
				 (VB) (MCF_UART_UCR_TC_DIS | MCF_UART_UCR_RC_DIS));
	/*  ����߶ػ�  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UIMR), 0);
        if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000200)) {    
          sil_wrw_mem (MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRL(MCF_INTC0)) | (1 << TBIT_GP0));
        }  else if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000240)) {
          sil_wrw_mem (MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRL(MCF_INTC0)) | (1 << TBIT_GP1));
        }
	siopcb->openflag = FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
mcfuart_snd_chr (SIOPCB * siopcb, char c)
{
	if (mcfuart_putready (siopcb)) {
		mcfuart_putchar (siopcb, c);
		return (TRUE);
	}
	return (FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
mcfuart_rcv_chr (SIOPCB * siopcb)
{
	if (mcfuart_getready (siopcb)) {
		return ((INT) (UB) mcfuart_getchar (siopcb));
	}
	return (-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
mcfuart_ena_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* �����������׵����� */
                siopcb->imr |= MCF_UART_UIMR_TXRDY;
		break;
	case SIO_ERDY_RCV:			/* �����������׵����� */
                siopcb->imr |= MCF_UART_UIMR_RXRDY;
		break;
	}
        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UIMR), siopcb->imr);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
mcfuart_dis_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* �����������׵��ػ� */
                siopcb->imr &= ~MCF_UART_UIMR_TXRDY;
		break;
	case SIO_ERDY_RCV:			/* �����������׵��ػ� */
                siopcb->imr &= ~MCF_UART_UIMR_RXRDY;
		break;
	}
        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UIMR), siopcb->imr);
}

/*
 * �ݡ���󥰤ˤ��ʸ��������
 */
void
mcfuart_putc_pol (ID portid, char c)
{
	while (!mcfuart_putready (&siopcb_table[portid - 1]));
	mcfuart_putchar (&siopcb_table[portid - 1], c);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф�����������߽���
 */
Inline void
mcfuart_isr_siop (SIOPCB * siopcb)
{
	VB uisr = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UISR));
        uisr &= siopcb->imr;
	if ((uisr & MCF_UART_UISR_TXRDY) && mcfuart_putready (siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		mcfuart_ierdy_snd (siopcb->exinf);
	}
	else if ((uisr & MCF_UART_UISR_RXRDY) && mcfuart_getready (siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		mcfuart_ierdy_rcv (siopcb->exinf);
        }
}

/* �����߸��� */
void
mcfuart_isr (void)
{
  if (siopcb_table[0].openflag) {
    mcfuart_isr_siop (get_siopcb (1));
  }
}

#if TNUM_PORT >= 2
/* �����߸��� */
void
mcfuart_isr2 (void)
{

  if (siopcb_table[1].openflag) {
    mcfuart_isr_siop (get_siopcb (2));
  }
}
#endif
