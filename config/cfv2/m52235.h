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
 *  @(#) $Id: m52235.h,v 1.8 2003/06/18 12:40:08 hiro Exp $
 */

/*
 *	M52235 CPU�ܡ��ɤΥϡ��ɥ������񸻤����
 */

#ifndef _M52235_H_
#define _M52235_H_

#include <sil.h>

#define	MCF_UART0    77
#define	MCF_UART1    78
#define	MCF_UART2    79
#define MCF_PIT0     119

#define TBIT_GP0     (13)
#define TBIT_GP1     (14)

#define TBIT_GP2     (15)

#define TBIT_TT0     (55 - 32)
#define TBIT_TT1     (56 - 32)

#define REF_CLK_MHZ         (25)
#define SYS_CLK_MHZ         (60)
#define REF_CLK_KHZ         (REF_CLK_MHZ * 1000)
#define SYS_CLK_KHZ         (SYS_CLK_MHZ * 1000)
#define SYSTEM_CLOCK        SYS_CLK_MHZ

#define IPSBAR       (0x40000000)

#define MCF_SCM_RAMBAR            (IPSBAR + 0x000008)
#define MCF_SCM_RAMBAR_BDE        (0x00000200)
#define MCF_SCM_RAMBAR_BA(x)      ((x)&0xFFFF0000)

#define MCF_CLK_SYNCR  (IPSBAR + 0x00120000)
#define MCF_CLK_SYNSR  (IPSBAR + 0x00120002)

#define MCF_CLK_SYNCR_PLLEN     (0x0001)
#define MCF_CLK_SYNCR_PLLMODE   (0x0002)
#define MCF_CLK_SYNCR_CLKSRC    (0x0004)
#define MCF_CLK_SYNCR_FWKUP     (0x0020)
#define MCF_CLK_SYNCR_DISCLK    (0x0040)
#define MCF_CLK_SYNCR_LOCEN     (0x0080)
#define MCF_CLK_SYNCR_RFD(x)    (((x)&0x0007)<<8)
#define MCF_CLK_SYNCR_LOCRE     (0x0800)
#define MCF_CLK_SYNCR_MFD(x)    (((x)&0x0007)<<12)
#define MCF_CLK_SYNCR_LOLRE     (0x8000)

#define MCF_CLK_SYNSR_LOCS      (0x04)
#define MCF_CLK_SYNSR_LOCK      (0x08)
#define MCF_CLK_SYNSR_LOCKS     (0x10)
#define MCF_CLK_SYNSR_CRYOSC    (0x20)
#define MCF_CLK_SYNSR_OCOSC     (0x40)
#define MCF_CLK_SYNSR_EXTOSC    (0x80)

#define MCF_CLK_LPCR_LPD(x)     (((x)&0x0F)<<0)

#define MCF_CLK_CCHR_PFD(x)     (((x)&0x07)<<0)

#define MCF_CLK_RTCDR_RTCDF(x)  (((x)&0xFFFFFFFF)<<0)

/* 
 * PLL min/max specifications
 */
#define MAX_FVCO    60000   /* KHz */
#define MAX_FSYS    60000   /* KHz */
#define MAX_FREF    48000   /* KHz */
#define MIN_FREF    1000    /* KHz */
#define MAX_MFD     18      /* Multiplier (not encoded) */
#define MIN_MFD     4       /* Multiplier (not encoded) */
#define MAX_RFD     128     /* Divider (not encoded) */
#define MIN_RFD     1       /* Divider (not encoded) */

/*
 * Low Power Divider specifications
 */
#define MIN_LPD     (1 << 0)    /* Divider (not encoded) */
#define MAX_LPD     (1 << 15)   /* Divider (not encoded) */

#define MCF_CLK_LPCR            (IPSBAR + 0x120007)
#define MCF_CLK_CCHR            (IPSBAR + 0x120008)
#define MCF_CLK_RTCDR           (IPSBAR + 0x12000C)

#define MCF_INTC0    (IPSBAR + 0x0C00)
#define MCF_INTC1    (IPSBAR + 0x0D00)

#define MCF_INTC_IMRL(ch)  (ch + 0x0c)
#define MCF_INTC_IMRH(ch)  (ch + 0x08)
#define MCF_INTC_ICR(ch, n)  (ch + 0x40 + n)

#define MCF_INTC_IMRH_ALL  (0x00000000)
#define MCF_INTC_IMRL_ALL  (0x00000001)

#define MCF_GPIO_PUAPAR     (IPSBAR + 0x100071)
#define MCF_GPIO_PUBPAR     (IPSBAR + 0x100072)
#define MCF_GPIO_PUCPAR     (IPSBAR + 0x100073)
#define MCF_GPIO_PUBPAR_TXD1_TXD1      (0x01)
#define MCF_GPIO_PUBPAR_RXD1_RXD1      (0x04)
#define MCF_GPIO_PUCPAR_TXD2_TXD2      (0x01)
#define MCF_GPIO_PUCPAR_RXD2_RXD2      (0x02)
#define MCF_GPIO_PUAPAR_TXD0_TXD0      (0x01)
#define MCF_GPIO_PUAPAR_RXD0_RXD0      (0x04)

#endif /* _M52235_H_ */
