/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: sys_config.c,v 1.7 2003/07/08 14:57:15 hiro Exp $
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���MCF52235EVB�ѡ�
 */

#include "jsp_kernel.h"
#include <sil.h>
#include "mcfuart.h"

/*
 *  �������åȥ����ƥ��¸�ν����
 */
void
sys_initialize()
{
    SIOPCB *siopcb;

    sil_wrb_mem (MCF_GPIO_PUAPAR, (MCF_GPIO_PUAPAR_RXD0_RXD0|MCF_GPIO_PUAPAR_TXD0_TXD0));
    sil_wrb_mem (MCF_GPIO_PUBPAR, (MCF_GPIO_PUBPAR_RXD1_RXD1|MCF_GPIO_PUBPAR_TXD1_TXD1));
    mcfuart_initialize ();
    siopcb = mcfuart_opn_por (LOGTASK_PORTID, 0);
}

/*
 *  �������åȥ����ƥ�ν�λ
 */
void
sys_exit()
{
	cfv2_exit();
}

/*
 *  �������åȥ����ƥ��ʸ������
 */
void
sys_putc(char c)
{
	if (c == '\n') {
		cfv2_putc(LOGTASK_PORTID, '\r');
	}
	cfv2_putc(LOGTASK_PORTID, c);
}

/* �ϡ��ɥ����������� */
#ifndef GDB_STUB


static void init_clock_config (void)
{
    sil_wrb_mem ((VP)MCF_CLK_CCHR,  (UB)MCF_CLK_CCHR_PFD(0x4));
    
    sil_wrh_mem ((VP)MCF_CLK_SYNCR,  (UH)0x4103);
    while (!(sil_reb_mem((VP)MCF_CLK_SYNSR) & 0x08));
    
    sil_wrh_mem ((VP)MCF_CLK_SYNCR,  (UH)0x4003);
    
    while (!(sil_reb_mem((VP)MCF_CLK_SYNSR) & 0x08));
    
    sil_wrh_mem ((VP)MCF_CLK_SYNCR,  (UH)0x4007);
}

void
hardware_init_hook (void)
{
  init_clock_config ();
  sil_wrw_mem ((VP) MCF_INTC_IMRH(MCF_INTC0), ~MCF_INTC_IMRH_ALL);
  sil_wrw_mem ((VP) MCF_INTC_IMRL(MCF_INTC0), ~MCF_INTC_IMRL_ALL);
  sil_wrw_mem ((VP) MCF_INTC_IMRH(MCF_INTC1), ~MCF_INTC_IMRH_ALL);
  sil_wrw_mem ((VP) MCF_INTC_IMRL(MCF_INTC1), ~MCF_INTC_IMRL_ALL);
  sil_wrw_mem ((VP) MCF_SCM_RAMBAR, (MCF_SCM_RAMBAR_BA(0x20000000) | MCF_SCM_RAMBAR_BDE));  
  return;
}
#else
void
hardware_init_hook (void)
{
}
#endif
