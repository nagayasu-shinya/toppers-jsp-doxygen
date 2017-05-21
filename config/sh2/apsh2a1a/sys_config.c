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

	/* SCIF3 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x10));
	sil_wrh_mem (PECRL4, sil_reh_mem (PECRL4) | (0x0030 | 0x0003));

#else /* GDB_STUB */

	/* SCIF3 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x10));
	sil_wrh_mem (PECRL4, sil_reh_mem (PECRL4) | (0x0003 | 0x0030));

#endif /* GDB_STUB */

	/* CMT0 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x04));
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
	sil_wrh_mem (FRQCR, 0x0104);	/* ����å����� I��=200MHz, B��=66.666MHz, P��=33.333MHz */

	/* �Х�����ȥ�������� */
	sil_wrw_mem (CMNCR, 0x00001010);
	sil_wrw_mem (CS0BCR, 0x24920400);
	sil_wrw_mem (CS0WCR, 0x00001382);
	sil_wrw_mem (CS3BCR, 0x24924600);
	sil_wrw_mem (CS3WCR, 0x00004912);
	sil_wrw_mem (SDCR, 0x00000909);
	sil_wrw_mem (RTCSR, 0xa55a0010);
	sil_wrw_mem (RTCOR, 0xa55a0040);

	/* I/O�ݡ��Ȥ����� */
	sil_wrh_mem (PBIORL, 0x0c00);	/* PC11,PC10 �������� (LED��³�ݡ���) */
	sil_wrh_mem (PBCRL4, 0x5a00);
	sil_wrh_mem (PBCRL3, 0x0000);	/* PC11,PC10�⡼�� �ݡ������� (LED��³�ݡ���) */
	sil_wrh_mem (PBCRL2, 0x0000);
	sil_wrh_mem (PBCRL1, 0x0000);
	sil_wrh_mem (PCIORL, 0x0000);
	sil_wrh_mem (PCCRL4, 0x0011);
	sil_wrh_mem (PCCRL3, 0x1111);
	sil_wrh_mem (PCCRL2, 0x1111);
	sil_wrh_mem (PCCRL1, 0x1111);
	sil_wrh_mem (PDIORL, 0x0000);
	sil_wrh_mem (PDCRL4, 0x1111);
	sil_wrh_mem (PDCRL3, 0x1111);
	sil_wrh_mem (PDCRL2, 0x1111);
	sil_wrh_mem (PDCRL1, 0x1111);
	sil_wrh_mem (PEIORL, 0x0000);
	sil_wrh_mem (PECRL4, 0x0000);
	sil_wrh_mem (PECRL3, 0x1010);
	sil_wrh_mem (PECRL2, 0x1111);
	sil_wrh_mem (PECRL1, 0x1111);
	sil_wrh_mem (PFIORH, 0x7fff);
	sil_wrh_mem (PFIORL, 0xffff);
	sil_wrh_mem (PFCRH4, 0x0000);
	sil_wrh_mem (PFCRH3, 0x0000);
	sil_wrh_mem (PFCRH2, 0x0000);
	sil_wrh_mem (PFCRH1, 0x0000);
	sil_wrh_mem (PFCRL4, 0x0000);
	sil_wrh_mem (PFCRL3, 0x0000);
	sil_wrh_mem (PFCRL2, 0x0000);
	sil_wrh_mem (PFCRL1, 0x0000);

	/* CMT �إ���å����� */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x04));

	/* 100usec �Ԥ� */
	sil_wrh_mem (CMSTR, 0x0000);	/* STR0=0 ������0 ��� */
	sil_wrh_mem (CMCSR_0, 0x0000);	/* CKS=00 ����å����� P��/8 */
	sil_wrh_mem (CMCNT_0, 0);		/* ������0 ���ꥢ�������󥹥���������� */
	sil_wrh_mem (CMCOR_0, ((((PCLOCK / 8)/1000000) * 100) - 1));
	sil_wrh_mem (CMSTR, 0x0001);	/* STR0=1 ������0 ���� */
	while ((sil_reh_mem (CMCSR_0) & 0x0080) == 0);
									/* CMF==1 �ˤʤ�ޤ��Ԥ� */

	sil_wrh_mem (SDRAM_MODE, 0x000);	/* SDRAM�⡼�ɥ쥸���������� */

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
