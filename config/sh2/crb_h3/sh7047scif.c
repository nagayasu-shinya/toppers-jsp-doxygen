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

/*
 *  SH7047��¢���ꥢ�륳�ߥ�˥�������󥤥󥿡��ե�����SCI�� �ʰץɥ饤��
 */

#include <s_services.h>
#include "sh7047.h"
#include "sh7047scif.h"

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
static const SIOPINIB siopinib_table[TNUM_PORT] = {
	{
		(IOREG_SCI_BASE+IOREG_SCI_WINDOW*1),
		(IOREG_INTC_BASE+IOREG_IPRI_OFFSET),
		9,
		ISR_SCR3_SHIFT
	},
	{
		(IOREG_SCI_BASE+IOREG_SCI_WINDOW*2),
		(IOREG_INTC_BASE+IOREG_IPRI_OFFSET),
		8,
		ISR_SCR4_SHIFT
	}
};

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 *      ID = 1 ��SCI3���б������Ƥ���.
 */
SIOPCB siopcb_table[TNUM_PORT];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ʸ��������Ǥ��뤫��
 */
Inline BOOL
sh7047scif_getready (SIOPCB * siopcb)
{
	/* �쥷���֥ǡ����쥸�����ե롦�ե饰�Υ����å� */
	return (sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET)) & SSR_RDRF);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
sh7047scif_putready (SIOPCB * siopcb)
{
	/* �ȥ�󥹥ߥå�FIFO�ǡ����쥸��������ץƥ����ե饰�Υ����å� */
	return (sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET)) & SSR_TDRE);
}

/*
 *  ��������ʸ���μ��Ф�
 */
Inline char
sh7047scif_getchar (SIOPCB * siopcb)
{
	VB data;

	data = sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_RDR_OFFSET));
	/* �쥷���֥ǡ����쥸�����ե롦�ե饰�Υ��ꥢ */
	sil_wrb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET),
		sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET)) & ~SSR_RDRF);
	return data;
}

/*
 *  ��������ʸ���ν����
 */
Inline void
sh7047scif_putchar (SIOPCB * siopcb, char c)
{
	sil_wrb_mem((VP)(siopcb->siopinib->cntrl+IOREG_TDR_OFFSET), c);
	/* �ȥ�󥹥ߥå�FIFO�ǡ����쥸��������ץƥ����ե饰�Υ��ꥢ */
	sil_wrb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET),
		sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET)) & ~SSR_TDRE);
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
sh7047scif_initialize ()
{
	SIOPCB *siopcb;
	UINT i;

	/*
     *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
     */
	for (siopcb = siopcb_table, i = 0; i < TNUM_PORT; siopcb++, i++) {
		siopcb->siopinib = &siopinib_table[i];
		siopcb->openflag = FALSE;
	}
}

/*
 *  �����ץ󤷤Ƥ���ݡ��ȤϤ��뤫��
 */
BOOL
sh7047scif_openflag (ID siopid)
{
	if(siopcb_table[INDEX_SIOP(siopid)].openflag)
		return TRUE;
	sil_dly_nse(sh2scif_DELAY*4);	/* Wait for Banner */
	return FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sh7047scif_opn_por (ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb;
	UW     base;
	unsigned char  dummy;

	siopcb = get_siopcb (siopid);
	base   = siopcb->siopinib->cntrl;
	/* ��������� */
	sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET),
		 sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) & ~(SCR_TE | SCR_RE));
	/* �⡼�ɥ쥸���������� */
	sil_wrb_mem((VP)(base+IOREG_SMR_OFFSET), DEFAULT_SMR);
	/* �ܡ��졼�Ȥ����� */
	sil_wrb_mem((VP)(base+IOREG_BRR_OFFSET), DEFAULT_BRR);

	sil_dly_nse(sh2scif_DELAY);
	/* ����������������ߵ��� */
	sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), SCR_RIE|SCR_TE|SCR_RE);
	dummy = sil_reb_mem((VP)(base+IOREG_SSR_OFFSET));		/* Dummy read */
	/* ����ߥ���ȥ�������� */
	sil_wrb_mem((VP)(base+IOREG_SSR_OFFSET), SSR_TDRE);		/* Clear error flags */
	siopcb->exinf    = exinf;
	siopcb->openflag = TRUE;
	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sh7047scif_cls_por (SIOPCB * siopcb)
{
	/* ��������ߡ�����߶ػ� */
	sil_wrb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SCR_OFFSET),
			sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SCR_OFFSET)) & ~(SCR_TIE|SCR_RIE|SCR_TE|SCR_RE));

	siopcb->openflag = FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
sh7047scif_snd_chr (SIOPCB * siopcb, char c)
{
	if (sh7047scif_putready (siopcb)) {
		sh7047scif_putchar (siopcb, c);
		return (TRUE);
	}
	return (FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
sh7047scif_rcv_chr (SIOPCB * siopcb)
{
	if (sh7047scif_getready (siopcb)) {
		return ((INT) (UB) sh7047scif_getchar (siopcb));
	}
	return (-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå�����
 */
void
sh7047scif_ena_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	UW base = siopcb->siopinib->cntrl;

	switch (cbrtn) {
	case SIO_ERDY_SND:		/* ����������׵����� */
		sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) | SCR_TIE);
		break;
	case SIO_ERDY_RCV:		/* ����������׵����� */
		sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) | SCR_RIE);
		break;
	default:
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ػ�
 */
void
sh7047scif_dis_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	UW base = siopcb->siopinib->cntrl;

	switch (cbrtn) {
	case SIO_ERDY_SND:		/* ����������׵��ػ� */
		sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) & ~SCR_TIE);
		break;
	case SIO_ERDY_RCV:		/* ����������׵��ػ� */
		sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) & ~SCR_RIE);
		break;
	default:
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф�����������߽���
 */
Inline void
sh7047scif_isr_siop_out (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SCR_OFFSET));

	if ((scr0 & SCR_TIE) != 0 && sh7047scif_putready (siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sh7047scif_ierdy_snd (siopcb->exinf);
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф����������߽���
 */
Inline void
sh7047scif_isr_siop_in (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SCR_OFFSET));

	if ((scr0 & SCR_RIE) != 0 && sh7047scif_getready (siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sh7047scif_ierdy_rcv (siopcb->exinf);
	}
}

/*
 *  SIO��������ߥ����ӥ��롼����(SCI3��)
 */
void
sh7047scif3_isr_out ()
{
	if (siopcb_table[0].openflag) {
		sh7047scif_isr_siop_out (&(siopcb_table[0]));
	}
}

/*
 *  SIO��������ߥ����ӥ��롼����(SCI4��)
 */
void
sh7047scif4_isr_out ()
{
	if (siopcb_table[1].openflag) {
		sh7047scif_isr_siop_out (&(siopcb_table[1]));
	}
}

/*
 *  SIO��������ߥ����ӥ��롼����(SCI3��)
 */
void
sh7047scif3_isr_in ()
{
	if (siopcb_table[0].openflag) {
		sh7047scif_isr_siop_in (&(siopcb_table[0]));
	}
}

/*
 *  SIO��������ߥ����ӥ��롼����(SCI4��)
 */
void
sh7047scif4_isr_in ()
{
	if (siopcb_table[1].openflag) {
		sh7047scif_isr_siop_in (&(siopcb_table[1]));
	}
}

/*
 *  SIO�������顼����ߥ����ӥ��롼����(SCI3��)
 */
void
sh7047scif3_isr_error (void)
{
	UW base = siopcb_table[0].siopinib->cntrl;

	if (siopcb_table[0].openflag) {
		sil_wrb_mem((VP)(base+IOREG_SSR_OFFSET), sil_reb_mem((VP)(base+IOREG_SSR_OFFSET)) & ~(SSR_OPER|SSR_FER|SSR_PER));
	}
}

/*
 *  SIO�������顼����ߥ����ӥ��롼����(SCI4��)
 */
void
sh7047scif4_isr_error (void)
{
	UW base = siopcb_table[1].siopinib->cntrl;

	if (siopcb_table[1].openflag) {
		sil_wrb_mem((VP)(base+IOREG_SSR_OFFSET), sil_reb_mem((VP)(base+IOREG_SSR_OFFSET)) & ~(SSR_OPER|SSR_FER|SSR_PER));
	}
}


