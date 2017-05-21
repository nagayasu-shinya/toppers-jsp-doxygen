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
 *  @(#) $Id: sys_config.c,v 1.5 2005/07/06 00:45:07 honda Exp $
 */

#include "jsp_kernel.h"
#include <sil.h>
#include <s_services.h>
#include "sh7615scif.h"
/*
 *  �������åȥ����ƥ��¸�ν����
 */
/* �����ϥݡ��Ȥ������sys_config.c */
/* ����ߥ٥����ֹ�������hw_serial.h */
/* �����֥�å��������sh7615scif.c */
void
sys_initialize ()
{
	SIOPCB *siopcb;

	/* ���Ѥ�����յ���Ϥ�����ͭ���ˤ��Ƥ����� */
	/*  SCIF�ǡ��������ϥݡ��Ȥ�����  */
#ifndef GDB_STUB

	/* SCIF1 */
	sil_wrh_mem (PBCR, sil_reh_mem (PBCR) | (0x0800 | 0x2000));
#if TNUM_PORT >= 2
	/* SCIF2 */
	sil_wrh_mem (PBCR2, sil_reh_mem (PBCR2) | (0x0200 | 0x0800));
#endif /* TNUM_PORT >= 2 */

#else	/*  GDB_STUB  */

	/* SCIF2 */
	sil_wrh_mem (PBCR2, sil_reh_mem (PBCR2) | (0x0200 | 0x0800));

#endif	/*  GDB_STUB  */
	/*
	 *  �ǥХ�����¸�Υ����ץ������
	 */
	/*�Хʡ����Ϥ��뤿�� */
	sh2scif_initialize();
	siopcb = sh2scif_opn_por (LOGTASK_PORTID, 0);

#ifndef GDB_STUB
	/* �٥����ֹ�ν���� */

	sil_wrw_mem (DMA_VCRDMA0, 72);
	sil_wrw_mem (DMA_VCRDMA1, 73);

	sil_wrh_mem (VCRWDT, 74 * 0x100 + 75);
	sil_wrh_mem (VCRA, 76 * 0x100);
	sil_wrh_mem (VCRC, 77 * 0x100 + 78);
	sil_wrh_mem (VCRD, 79 * 0x100);
	sil_wrh_mem (VCRE, 80 * 0x100 + 81);
	sil_wrh_mem (VCRF, 82 * 0x100 + 83);
	sil_wrh_mem (VCRG, 84 * 0x100);
	sil_wrh_mem (VCRH, 85 * 0x100 + 86);
	sil_wrh_mem (VCRI, 87 * 0x100 + 88);
	sil_wrh_mem (VCRJ, 89 * 0x100 + 90);
	sil_wrh_mem (VCRK, 91 * 0x100 + 92);
	sil_wrh_mem (VCRL, 93 * 0x100 + 94);
	sil_wrh_mem (VCRM, 95 * 0x100 + 96);
	sil_wrh_mem (VCRN, 97 * 0x100 + 98);
	sil_wrh_mem (VCRO, 99 * 0x100 + 100);
	sil_wrh_mem (VCRP, 101 * 0x100 + 102);
	sil_wrh_mem (VCRQ, 103 * 0x100 + 104);
	sil_wrh_mem (VCRR, 105 * 0x100 + 106);
	sil_wrh_mem (VCRS, 107 * 0x100 + 108);
	sil_wrh_mem (VCRT, 109 * 0x100 + 110);
	sil_wrh_mem (VCRU, 111 * 0x100 + 112);
#endif	/*  GDB_STUB  */

}

/*
 *  �������åȥ����ƥ�ν�λ
 */
void
sys_exit()
{
	sh2_exit();
}

/*
 *  �������åȥ����ƥ��ʸ������
 */
void
sys_putc(char c)
{
	if (c == '\n') {
		sh2_putc (LOGTASK_PORTID, '\r');
	}
	sh2_putc (LOGTASK_PORTID, c);
}

/* �ϡ��ɥ����������� */
void
hardware_init_hook (void)
{
}
