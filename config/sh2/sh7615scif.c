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
 *  @(#) $Id: sh7615scif.c,v 1.3 2005/07/06 00:45:07 honda Exp $
 */

/*
 *   SH2��¢���ꥢ�륳�ߥ�˥�������󥤥󥿥ե�����SCIF�� �ʰץɥ饤��
 */

#include <s_services.h>
#include "sh7615scif.h"

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 */
/* �����ϥݡ��Ȥ������sys_config.c */
/* ����ߥ٥����ֹ�������hw_serial.h */
/* �����֥�å��������sh7615scif.c */

#ifndef GDB_STUB

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{0xfffffcc0, BRR9600, 0x0, 6}, /* SCIF1 */
#if TNUM_PORT >= 2
	{0xfffffce0, BRR9600, 0x0, 6}, /* SCIF2 */
#endif /* TNUM_PORT >= 2 */
};

#else /* GDB_STUB */

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{0xfffffce0, BRR9600, 0x0, 6}, /* SCIF2 */
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
sh2scif_getready (SIOPCB * siopcb)
{
	/*  �쥷���֥ǡ����쥸�����ե롦�ե饰�Υ����å�  */
	return (sil_reh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR)) &
			SC1SSR_RDRF);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
sh2scif_putready (SIOPCB * siopcb)
{
	/*  �ȥ�󥹥ߥå�FIFO�ǡ����쥸��������ץƥ����ե饰�Υ����å� */
	return (sil_reh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR)) &
			SC1SSR_TDFE);
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
sh2scif_getchar (SIOPCB * siopcb)
{
	VB data;

	data = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFRDR));
	/*  �쥷���֥ǡ����쥸�����ե롦�ե饰�Υ��ꥢ  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_RDRF);
	return data;
}

/*
 *  ��������ʸ���ν����
 */
Inline void
sh2scif_putchar (SIOPCB * siopcb, char c)
{
	/*  �ȥ�󥹥ߥå�FIFO�ǡ����쥸��������ץƥ����ե饰�Υ��ꥢ */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFTDR), c);
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_TDFE);
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
sh2scif_initialize ()
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
sh2scif_openflag (ID siopid)
{
	return (siopcb_table[siopid - 1].openflag);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sh2scif_opn_por (ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb;

	siopcb = get_siopcb (siopid);

	/*  ���������  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCIF_SCSCR)) & ~(SCSCR_TE | SCSCR_RE));

	/*  SCI�ǡ��������ϥݡ��Ȥ�����  */
	/*  �ԥ󥢥����� */
	/* sys_initialize������ */

	/*  FIFO�ν����  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFCR),
				 (VB) (SCFCR_TFRST | SCFCR_RFRST));

	/*  �������ե����ޥå�  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSMR), 0x00);
	/*  Ĵ��Ʊ����  */
	/*  8�ӥåȡ��ѥ�ƥ��ʤ�  */
	/*  ���ȥåץӥåȥ�󥰥���1   */
	/*  ����å����쥯�� */

	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCBRR), (VB) siopcb->siopinib->brr);	/* �ܡ��졼������ */


	/*
	 * �ܡ��졼�Ȥ�����塢1�������ʬ�Ԥ��ʤ���Фʤ�ʤ���
	 */
	sil_dly_nse (sh2scif_DELAY);	/* �ͤϣ�裱��Ʊ�� */

	/*  FIFO������  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFCR), 0x00);

	/* ���顼�ե饰�򥯥ꥢ */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_ER);

	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
				 (VB) (SCSCR_RIE | SCSCR_TE | SCSCR_RE));

	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	return (siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sh2scif_cls_por (SIOPCB * siopcb)
{
	/*  ��������ߡ�����߶ػ�  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
				 (VB) ~ (SCSCR_TIE | SCSCR_RIE | SCSCR_TE | SCSCR_RE));

	siopcb->openflag = FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
sh2scif_snd_chr (SIOPCB * siopcb, char c)
{
	if (sh2scif_putready (siopcb)) {
		sh2scif_putchar (siopcb, c);
		return (TRUE);
	}
	return (FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
sh2scif_rcv_chr (SIOPCB * siopcb)
{
	if (sh2scif_getready (siopcb)) {
		return ((INT) (UB) sh2scif_getchar (siopcb));
	}
	return (-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
sh2scif_ena_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* �����������׵����� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) | SCSCR_TIE);
		break;
	case SIO_ERDY_RCV:			/* �����������׵����� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) | SCSCR_RIE);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
sh2scif_dis_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* �����������׵��ػ� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) & ~SCSCR_TIE);
		break;
	case SIO_ERDY_RCV:			/* �����������׵��ػ� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) & ~SCSCR_RIE);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф�����������߽���
 */
Inline void
sh2scif_isr_siop_out (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR));

	if ((scr0 & SCSCR_TIE) != 0 && sh2scif_putready (siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sh2scif_ierdy_snd (siopcb->exinf);
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф����������߽���
 */
Inline void
sh2scif_isr_siop_in (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR));

	if ((scr0 & SCSCR_RIE) != 0 && sh2scif_getready (siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sh2scif_ierdy_rcv (siopcb->exinf);
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф���������顼����߽���
 */
Inline void
sh2scif_isr_siop_err (SIOPCB * siopcb)
{
	/* ���顼�ե饰�򥯥ꥢ */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_ER);
	/*  FIFO�ν����  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFCR),
				 (VB) SCFCR_RFRST);
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFCR), 0x30);
}

/* �֥졼�����н��� */
/* �ե饰��ꥻ�åȤ��� */
Inline void
sh2scif_isr_siop_brk (SIOPCB * siopcb)
{
	/* �ե饰�򥯥ꥢ */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_BRK);
}

/*
 *  SCI��������ߥ����ӥ��롼���� ��裱��Ʊ��
 *  
 *  ��SH1��¢��SCI�Ǥϳ�����ֹ椬�������̡�����ͥ��̤�ʬ����Ƥ���Τǡ�
 *  ��SCI0����������߰ʳ��Ǥ��Υ롼���󤬸ƤФ�뤳�ȤϤʤ�
 *  
 */
void
sh2scif_isr_out ()
{
	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_out (get_siopcb (1));
	}
}

/*
 *  SCI��������ߥ����ӥ��롼���󡡣�裱��Ʊ��
 *  
 *  ��SH1��¢��SCI�Ǥϳ�����ֹ椬�������̡�����ͥ��̤�ʬ����Ƥ���Τǡ�
 *  ��SCI0�μ�������߰ʳ��Ǥ��Υ롼���󤬸ƤФ�뤳�ȤϤʤ�
 *  
 */
void
sh2scif_isr_in ()
{
	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_in (get_siopcb (1));
	}
}

/*
 *  SIO�������顼����ߥ����ӥ��롼���󡡣�裱��Ʊ��
 *  
 *  ��SH1��¢��SCI�Ǥϳ�����ֹ椬����ͥ��̤�ʬ����Ƥ���Τǡ�
 *  ��SCI0�μ������顼����߰ʳ��Ǥ��Υ롼���󤬸ƤФ�뤳�ȤϤʤ�
 *  ��
 *  �����顼�������Τϥ��顼�ե饰�Υ��ꥢ�ΤߤˤȤɤ�Ƥ��롣
 *  �������������С���󥨥顼
 *  ���������ե졼�ߥ󥰥��顼
 *  ���������ѥ�ƥ����顼
 */
void
sh2scif_isr_error (void)
{

	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_err (get_siopcb (1));
	}
}

/* �֥졼������ */
void
sh2scif_isr_brk (void)
{

	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_brk (get_siopcb (1));
	}
}

/*
 * �ݡ���󥰤ˤ��ʸ��������
 */
void
sh2scif_putc_pol (ID portid, char c)
{
	while (!sh2scif_putready (&siopcb_table[portid - 1]));
	sh2scif_putchar (&siopcb_table[portid - 1], c);
}

#if TNUM_PORT >= 2
/*
 *  SCI��������ߥ����ӥ��롼����
 *  
 */
void
sh2scif_isr2_in (void)
{
	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_in (get_siopcb (2));
	}
}

/*
 *  SCI��������ߥ����ӥ��롼����
 *  
 */
void
sh2scif_isr2_out (void)
{
	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_out (get_siopcb (2));
	}
}

/*
 *  SCI�������顼����ߥ����ӥ��롼����
 */
void
sh2scif_isr2_error (void)
{
	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_err (get_siopcb (2));
	}
}

/* �֥졼������ */
void
sh2scif_isr2_brk (void)
{

	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_brk (get_siopcb (2));
	}
}
#endif /* of #if TNUM_PORT >= 2 */
