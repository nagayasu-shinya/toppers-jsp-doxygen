/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2003 by Industrial Technology Institute,
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
 *  @(#) $Id: sh7145sci.c,v 1.3 2005/07/06 00:45:07 honda Exp $
 */

/*
 *   SH2��¢���ꥢ�륳�ߥ�˥�������󥤥󥿥ե�����SCI�� �ʰץɥ饤��
 */

#include <s_services.h>
#include "sh7145sci.h"

/*
 * ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
#ifndef GDB_STUB
const SIOPINIB siopinib_table[TNUM_PORT] = {
	{0xffff81b0, BRR9600, 0x0, 6}, /* SCI1 */
#if TNUM_PORT >= 2
	{0xffff81a0, BRR9600, 0x0, 6}, /* SCI0 */
#endif /* TNUM_PORT >= 2 */
};
#else /* GDB_STUB */
const SIOPINIB siopinib_table[TNUM_PORT] = {
	{0xffff81a0, BRR9600, 0x0, 6}, /* SCI0 */
};
#endif /* GDB_STUB */


/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
static SIOPCB siopcb_table[TNUM_PORT];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
				/*  �ݡ���ID����ǥХ����ֹ�����ޥ���  */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ʸ��������Ǥ��뤫��
 */
Inline BOOL
sh2sci_getready (SIOPCB * siopcb)
{
	/*  �쥷���֥ǡ����쥸�����ե롦�ե饰�Υ����å�  */
	return (sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR)) &
			SSR_RDRF);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
sh2sci_putready (SIOPCB * siopcb)
{
	/*  �ȥ�󥹥ߥåȥǡ����쥸��������ץƥ����ե饰�Υ����å� */
	return (sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR)) &
			SSR_TDRE);
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
sh2sci_getchar (SIOPCB * siopcb)
{
	char data;

	data = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_RDR));
	/*  �쥷���֥ǡ����쥸�����ե롦�ե饰�Υ��ꥢ  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SSR)) & ~SSR_RDRF);
	return data;
}

/*
 *  ��������ʸ���ν����
 */
Inline void
sh2sci_putchar (SIOPCB * siopcb, char c)
{
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_TDR), c);
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SSR)) & ~SSR_TDRE);
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
sh2sci_initialize ()
{
	SIOPCB *siopcb;
	UINT i;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
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
sh2sci_openflag (ID siopid)
{
	return (siopcb_table[siopid - 1].openflag);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sh2sci_opn_por (ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb = get_siopcb (siopid);

	/*  ���������  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR), 0x00);

	/*  SCI�ǡ��������ϥݡ��Ȥ�����  */
	/*  �ԥ󥢥����� */
	/* sys_initialize������ */

	/*  �������ե����ޥå�  */
	/*  Ĵ��Ʊ����  */
	/*  8�ӥåȡ��ѥ�ƥ��ʤ�  */
	/*  ���ȥåץӥåȥ�󥰥���1   */
	/*  ����å����쥯�� */

	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SMR),
				 siopcb->siopinib->smr);
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_BRR),
				 (VB) siopcb->siopinib->brr);

	/*
	 * �ܡ��졼�Ȥ�����塢1�������ʬ�Ԥ��ʤ���Фʤ�ʤ���
	 */
	sil_dly_nse (sh2sci_DELAY);	/* �ͤϣ�裱��Ʊ�� */

	/* ���顼�ե饰�򥯥ꥢ */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SSR)) & ~(SSR_ORER | SSR_FER |
													SSR_PER));
	/*���������ġ����������ߵ��� */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
				 (VB) (SCI_RIE | SCI_TE | SCI_RE));

	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	return (siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sh2sci_cls_por (SIOPCB * siopcb)
{
	/*  ��������ߡ�����߶ػ�  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SCR)) & (VB) ~ (SCI_TIE | SCI_RIE |
														  SCI_TE | SCI_RE));
	siopcb->openflag = FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
sh2sci_snd_chr (SIOPCB * siopcb, char c)
{
	if (sh2sci_putready (siopcb)) {
		sh2sci_putchar (siopcb, c);
		return (TRUE);
	}
	return (FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
sh2sci_rcv_chr (SIOPCB * siopcb)
{
	if (sh2sci_getready (siopcb)) {
		return ((INT) (UB) sh2sci_getchar (siopcb));
		/*  (UB)�ǥ��㥹�Ȥ���Τϥ����ĥ�ˤ��뤿��  */
	}
	return (-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
sh2sci_ena_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* �����������׵����� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCI_SCR)) | SCI_TIE);
		break;
	case SIO_ERDY_RCV:			/* �����������׵����� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCI_SCR)) | SCI_RIE);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
sh2sci_dis_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* �����������׵��ػ� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCI_SCR)) & ~SCI_TIE);
		break;
	case SIO_ERDY_RCV:			/* �����������׵��ػ� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCI_SCR)) & ~SCI_RIE);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф�����������߽���
 */
Inline void
sh2sci_isr_siop_out (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR));

	if ((scr0 & SCI_TIE) != 0 && sh2sci_putready (siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sh2sci_ierdy_snd (siopcb->exinf);
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф����������߽���
 */
Inline void
sh2sci_isr_siop_in (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR));

	if ((scr0 & SCI_RIE) != 0 && sh2sci_getready (siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sh2sci_ierdy_rcv (siopcb->exinf);
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф���������顼����߽���
 */
Inline void
sh2sci_isr_siop_err (SIOPCB * siopcb)
{
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SSR)) & ~(SSR_ORER | SSR_FER |
													SSR_PER));
}

/*
 *  SCI��������ߥ����ӥ��롼����
 *  
 */
void
sh2sci_isr_out (void)
{
	if (siopcb_table[0].openflag) {
		sh2sci_isr_siop_out (get_siopcb (1));
	}
}

/*
 *  SIO��������ߥ����ӥ��롼����
 *  
 */
void
sh2sci_isr_in (void)
{
	if (siopcb_table[0].openflag) {
		sh2sci_isr_siop_in (get_siopcb (1));
	}
}

/*
 *  SIO�������顼����ߥ����ӥ��롼����
 */
void
sh2sci_isr_error (void)
{
	if (siopcb_table[0].openflag) {
		sh2sci_isr_siop_err (get_siopcb (1));
	}
}

/*
 * �ݡ���󥰤ˤ��ʸ��������
 */
void
sh2sci_putc_pol (ID portid, char c)
{
	while (!sh2sci_putready (&siopcb_table[portid - 1]));
	sh2sci_putchar (&siopcb_table[portid - 1], c);
}


#if TNUM_PORT >= 2
/*
 *  SIO��������ߥ����ӥ��롼����
 *  
 */
void
sh2sci_isr2_in (void)
{
	if (siopcb_table[1].openflag) {
		sh2sci_isr_siop_in (get_siopcb (2));
	}
}

/*
 *  SCI��������ߥ����ӥ��롼����
 *  
 */
void
sh2sci_isr2_out (void)
{
	if (siopcb_table[1].openflag) {
		sh2sci_isr_siop_out (get_siopcb (2));
	}
}

/*
 *  SIO�������顼����ߥ����ӥ��롼����
 */
void
sh2sci_isr2_error (void)
{
	if (siopcb_table[1].openflag) {
		sh2sci_isr_siop_err (get_siopcb (2));
	}
}
#endif /* of #if TNUM_PORT >= 2 */
