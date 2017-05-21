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
 *  Copyright (C) 2010 by Cronus Computer Works, JAPAN
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
 *  @(#) $Id
 */

#include "jsp_kernel.h"
#include <sil.h>
#include <s_services.h>
#include "sh726xscif.h"

/*
 *  �������åȥ����ƥ��¸�ν����
 */
/*
 *  ���ꥢ��I/O�ݡ��Ȥν���� banner���ϤΤ��ᥫ���ͥ�ν������̵�ط��˹Ԥ�
 */
void
sys_initialize ()
{
	SIOPCB *siopcb;

	/* ���Ѥ�����յ���Ϥ�����ͭ���ˤ��Ƥ����� */
	/*  SCIF�ǡ��������ϥݡ��Ȥ�����  */

#ifndef GDB_STUB

	/* SCIF2 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x20));
	sil_wrh_mem (PFCR0, sil_reh_mem (PFCR0) | (0x0400 | 0x0040));
#if TNUM_PORT >=2
	/* SCIF3 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x10));
	sil_wrh_mem (PFCR1, sil_reh_mem (PFCR1) | 0x0004);
	sil_wrh_mem (PFCR0, sil_reh_mem (PFCR0) | 0x4000);
#endif /*TNUM_PORT >=2 */

#else /* GDB_STUB */

	/* SCIF3 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x10));
	sil_wrh_mem (PFCR1, sil_reh_mem (PFCR1) | 0x0004);
	sil_wrh_mem (PFCR0, sil_reh_mem (PFCR0) | 0x4000);

#endif /* GDB_STUB */

	/* CMT0 */
	sil_wrb_mem (STBCR7, (VB) ((VB) sil_reb_mem (STBCR7) & ~0x04));
	/*
	 *  �ǥХ�����¸�Υ����ץ������
	 */
	/*�Хʡ����Ϥ��뤿�� */
	sh2scif_initialize();
	siopcb = sh2scif_opn_por (LOGTASK_PORTID, 0);
}

/*
 *  �������åȥ����ƥ�ν�λ
 */
void
sys_exit ()
{
	sh2_exit ();
}

/*
 *  �������åȥ����ƥ��ʸ������
 */
void
sys_putc (char c)
{
	if (c == '\n') {
		sh2_putc (LOGTASK_PORTID, '\r');
	}
	sh2_putc (LOGTASK_PORTID, c);
}

/* �ϡ��ɥ����������� */
/* �����ǤϥХ�������Τ߹Ԥ������յ���������sys_initialize�ǹԤ��� */
#ifndef GDB_STUB
void
hardware_init_hook (void)
{
	/* ����å�ȯ����ν���� */
	sil_wrh_mem (FRQCR, 0x1104);	/* ����å����� I��=144MHz, B��=48MHz, P��=24MHz */

	/* I/O�ݡ��Ȥ����� */
	sil_wrh_mem (PCIOR0, 0x0100);	/* PC8�ݡ��� �������� (LED��³�ݡ���) */
	sil_wrh_mem (PCCR2, 0x0000);	/* PC8�⡼�� �ݡ������� (LED��³�ݡ���) */

	/* ����å�������� */
	sil_wrw_mem (CCR1, 0x00000808);	/* ����å����ե�å��� */
	sil_wrw_mem (CCR1, CCR_MODE);	/* ����å���⡼�ɤ����� */
}
#else /*  GDB_STUB  */
void
hardware_init_hook (void)
{
}
#endif /*  GDB_STUB  */
