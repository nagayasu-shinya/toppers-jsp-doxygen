/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
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
 *  @(#) $Id: sfruart.c,v 1.4 2005/11/24 12:41:23 honda Exp $
 */

/*
 *	OAKS32 UART�ѥ��ꥢ��I/O�⥸�塼��
 */
#include <s_services.h>
#include "oaks32.h"
#include <sfruart.h>

/*
 *  �ǥХ��������ץ�Υ�ȥ饤�������
 *
 *  500���ȥ饤����С���ʬ�˽�λ���롥
 */
#define	SFRUART_COUNT	500

/*
 * ���ꥢ�륳��ȥ���쥸������������ 
 */
#define	MR_DEF		0x05	/* ��������å�����Ʊ����8�ӥåȡ��ѥ�ƥ��ʤ������꡼�פʤ� */
#define MR_DISABLE_DEF	0x00	/* ���ꥢ��⥸�塼��̵�� */
#define	C0_DEF		0x10	/* RTS/CTS̤����, ������ȥ�����f1, ����������װ��ϡ������Хåե����� */
#define	C1_DEF		0x00	/* ���ꥢ���������ػ� */
#define	BRG1_DEF	48	/* 30000000/{(UxBRG+1)*16} = 38400 */
#define	BRG2_DEF	97	/* 30000000/{(UxBRG+1)*16} = 19200 */

#define	TB_LEVEL	4	/* ��������ߥ�٥� */
#define	RB_LEVEL	5	/* ��������ߥ�٥� */
#define DISABLE_LEVEL	0	/* ����߶ػߥ�٥� */

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å������
 */
typedef struct sio_port_initialization_block {
	UH  cntrl_addr;	/* ����쥸���������� */
	UH  tic_addr;	/* �������������쥸���������� */
	UH  ric_addr;	/* �������������쥸���������� */

	UB  mr_def;	/* �ǥե���Ȥ������� (MR) */
	UB  c0_def;	/* �ǥե���Ȥ������� (C0) */
	UB  brg_def;	/* �ǥե���Ȥ������� (BRG) */
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*siopinib;	/* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
	VP_INT exinf;	/* ��ĥ���� */
	UB     uc1;	/* ����������쥸����UiC1�������� */
};

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 *
 *  ID = 1 ��uart0��ID = 2 ��uart1���б������Ƥ��롥
 */
static const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{ TADR_SFR_UART0_BASE, (TADR_SFR_INT_BASE+TADR_SFR_S0TIC_OFFSET),
	  (TADR_SFR_INT_BASE+TADR_SFR_S0RIC_OFFSET), MR_DEF, C0_DEF, BRG1_DEF },
#if TNUM_SIOP>1
	{ TADR_SFR_UART1_BASE, (TADR_SFR_INT_BASE+TADR_SFR_S1TIC_OFFSET),
	  (TADR_SFR_INT_BASE+TADR_SFR_S1RIC_OFFSET), MR_DEF, C0_DEF, BRG1_DEF }
#endif
};

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
static SIOPCB siopcb_table[TNUM_SIOP];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
sfruart_initialize(void)
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->siopinib = &(siopinib_table[i]);
		siopcb->uc1 = C1_DEF;
		/*
		 * ����Ū�˥ݡ��Ȥ��Գ��������Ƥ���
		 */
		/* �����߶ػ� */
		sil_wrb_mem((VP)(siopcb->siopinib->tic_addr), DISABLE_LEVEL);
		sil_wrb_mem((VP)(siopcb->siopinib->ric_addr), DISABLE_LEVEL);
		/* �������ػ� */
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
	}
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sfruart_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB		*siopcb;
	const SIOPINIB	*siopinib;
	int i;

	siopcb = get_siopcb(siopid);
	siopinib = siopcb->siopinib;

	/* �������ػ� */
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET),
	   sil_reb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET))&~(TBIT_UiC1_TE | TBIT_UiC1_RE));

	/* �ݡ�������(ư��⡼�ɡ��̿�®��) */
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UMR_OFFSET), siopinib->mr_def);
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC0_OFFSET), siopinib->c0_def);
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UBRG_OFFSET), siopinib->brg_def);

	/*
	 *  ���ꥢ�����ߤ�����
	 */
	sil_wrb_mem((VP)(siopinib->tic_addr), TB_LEVEL);
	sil_wrb_mem((VP)(siopinib->ric_addr), RB_LEVEL);

	/* �����ץ���ϥ�����Хå��ػ� */
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);

	/*
	 * ���ߡ��ǡ�������
	 */
	sil_reb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_URB_OFFSET));
	sil_reb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_URB_OFFSET));

	for(i = 0 ; i < SFRUART_COUNT ; i++){	/* �����ץ������READY�ޤ��Ԥ� */
		if(sil_reb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET)) & TBIT_UiC1_TI)
			break;
	}

	siopcb->exinf = exinf;
	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sfruart_cls_por(SIOPCB *siopcb)
{
	const SIOPINIB	*siopinib;

	siopinib = siopcb->siopinib;

	/* �����߶ػ� */
	sil_wrb_mem((VP)(siopinib->tic_addr), DISABLE_LEVEL);
	sil_wrb_mem((VP)(siopinib->ric_addr), DISABLE_LEVEL);

	/* �������ػ� */
	siopcb->uc1 = C1_DEF;
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);

	/* ���ꥢ��⥸�塼���̵���ˤ��� */
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UMR_OFFSET), MR_DISABLE_DEF);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
sfruart_snd_chr(SIOPCB *siopcb, char c)
{
	if(sil_reb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET)) & TBIT_UiC1_TI){
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UTB_OFFSET), c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
sfruart_rcv_chr(SIOPCB *siopcb)
{
	if(sil_reb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET)) & TBIT_UiC1_RI){
		return((INT)sil_reb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_URB_OFFSET)));
	}
	return(-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
sfruart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		siopcb->uc1 |= TBIT_UiC1_TE;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
		break;
	case SIO_ERDY_RCV:
		siopcb->uc1 |= TBIT_UiC1_RE;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
		break;
	default:
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
sfruart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		siopcb->uc1 &= ~TBIT_UiC1_TE;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
		break;
	case SIO_ERDY_RCV:
		siopcb->uc1 &= ~TBIT_UiC1_RE;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
		break;
	default:
		break;
	}
}

/*
 *  uart0����μ��������
 */
void serial_in_handler1(void)
{
	SIOPCB *siopcb = &siopcb_table[0];
	if((siopcb->uc1 & TBIT_UiC1_RE) != 0) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sfruart_ierdy_rcv(siopcb->exinf);
	}
}

/*
 *  uart0��������������
 */
void serial_out_handler1(void)
{
	SIOPCB *siopcb = &siopcb_table[0];

	if((siopcb->uc1 & TBIT_UiC1_TE) != 0) {
		/*
		 *  ������ǽ������Хå��롼�����ƤӽФ���
		 */
		sfruart_ierdy_snd(siopcb->exinf);
	}
}

#if TNUM_SIOP > 1
/*
 *  uart1����μ��������
 */
void serial_in_handler2(void)
{
	SIOPCB *siopcb = &siopcb_table[1];
	if((siopcb->uc1 & TBIT_UiC1_RE) != 0){
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sfruart_ierdy_rcv(siopcb->exinf);
	}
}

/*
 *  uart1��������������
 */
void serial_out_handler2(void)
{
	SIOPCB *siopcb = &siopcb_table[1];
	if((siopcb->uc1 & TBIT_UiC1_TE) != 0) {
		/*
		 *  ������ǽ������Хå��롼�����ƤӽФ���
		 */
		sfruart_ierdy_snd(siopcb->exinf);
	}
}
#endif
