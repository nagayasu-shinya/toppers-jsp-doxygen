/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id$
 */


#include "jsp_kernel.h"
#include "sh7047.h"
#include <sil.h>

void hardware_init_hook(void)
{
	unsigned long *p = (unsigned long *)SRAM_START;

	/* initial Module Standby register */
	sil_wrh_mem((VP)(IOREG_MST_BASE+IOREG_CR1_OFFSET), 0xf023);	/* sci4,sci3,sci2	*/
	sil_wrh_mem((VP)(IOREG_MST_BASE+IOREG_CR2_OFFSET), 0xe0f0);	/* cmt */

	/* initial base state */
	sil_wrh_mem((VP)(IOREG_BSC_BASE+IOREG_BCR1_OFFSET), 0x600e);/* CS0:8bit */
	sil_wrh_mem((VP)(IOREG_BSC_BASE+IOREG_BCR2_OFFSET), 0xffff);/* CS0:idle cycle 3*/
	sil_wrh_mem((VP)(IOREG_BSC_BASE+IOREG_WCR1_OFFSET), 0xfff2);/* CS0 2Wait */

	/* �ɣϥݡ������� */
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PACRL1_OFFSET), 0x1115);	/*	0001 0001 0001 0101	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PACRL2_OFFSET), 0x4000);	/*	0100 0000 0000 0000	*/	/*	PA6	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PACRL3_OFFSET), 0x03bf);	/*	0000 0011 1011 1111	*/	/*	PA6	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PAIORL_OFFSET), 0x5ebf);	/*	0101 1110 1011 1111	*/

	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PBCR1_OFFSET), 0x2c00);	/*	0010 1100 0000 0000	*/	/*	TXD4,RXD4	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PBCR2_OFFSET), 0x04f5);	/*	0000 0100 1111 0101	*/	/*	TXD4,RXD4	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PBIOR_OFFSET), 0x0023);	/*	0000 0000 0010 0011	*/	/*	TXD4,RXD4	*/

	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PDCRL1_OFFSET), 0x00ff);	/*	0000 0000 1111 1111	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PDCRL2_OFFSET), 0x0000);	/*	0000 0000 0000 0000	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PDIORL_OFFSET), 0x0000);	/*	0000 0000 0000 0000	*/

	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PECRH_OFFSET), 0x0fff);	/*	0000 1111 1111 1111	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PECRL1_OFFSET), 0x0000);	/*	0000 0000 0000 0000	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PECRL2_OFFSET), 0xff00);	/*	1111 1111 0000 0000	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PEIORH_OFFSET), 0x003f);	/*	0000 0000 0011 1111	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PEIORL_OFFSET), 0x00f0);	/*	0000 0000 1111 0000	*/

	/* SRAM clear */
	while(p < (unsigned long *)SRAM_END){
		*p++ = 0L;
	}
}

/*
 * �����ߥ���ȥ���ν����
 */
void sh2_init_intcontorller (void)
{
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRA_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRD_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRE_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRF_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRG_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRH_OFFSET), 0x0000);
}

