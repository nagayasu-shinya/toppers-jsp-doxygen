/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

/*
 *  H8S��¢SCI�� �ʰ�SIO�ɥ饤��
 *  �������ϡ��������ͥ��Ѥ˵��Ҥ��Ƥ��롣H8S���꡼������ˤϡ��������ͥ�
 *    �ʾ奵�ݡ��Ȥ��Ƥ�����åפ⤢�뤬�����ΤȤ����б����ưפǤ��롣
 */

#include <h8s_sci.h>

/* SCI�쥸�����Υ��ɥ쥹 */
/* �١������ɥ쥹 */
#define SCI0_BASE_ADDR	0xff78	/* ����ͥ룰 */
#define SCI1_BASE_ADDR	0xff80	/* ����ͥ룱 */
#define SCI2_BASE_ADDR	0xff88	/* ����ͥ룲 */

/* �쥸�������ե��å� */
#define SMR		0	/* ���ꥢ��⡼�ɥ쥸���� */
#define BRR		1	/* �ӥåȥ졼�ȥ쥸���� */
#define SCR		2	/* ���ꥢ�륳��ȥ���쥸���� */
#define TDR		3	/* �ȥ�󥹥ߥåȥǡ����쥸���� */
#define SSR		4	/* ���ꥢ�륹�ơ������쥸���� */
#define RDR		5	/* �쥷���֥ǡ����쥸���� */
#define SCMR		6	/* ���ޡ��ȥ����ɥ⡼�ɥ쥸���� */

/* �ƥ쥸�����Υӥåȥѥ����� */

/* RSR, RDR, TSR, TDR */
/* ������٤���Τϡ��ä�̵�� */

/* SMR */
#define CA	BIT7
#define	CHR	BIT6	/* 8bit = 0 / 7bit = 1 */
#define	PE	BIT5	/* Parity OFF = 0 / Parity ON = 1 */
#define	OE	BIT4	/* EVEN Parity = 0 / ODD Parity = 1 */
#define	STOP	BIT3	/* 1 STOP BIT = 0 / 2 STOP BIT = 1 */
#define MP	BIT2
#define	CSK1	BIT1
#define	CSK0	BIT0

/*
 *��SMR�ν����
 *
 *���ӥå�7=0��Ĵ��Ʊ�����⡼��
 *���ӥå�6=0������饯����󥰥�=8�ӥå�
 *���ӥå�5=0���ѥ�ƥ����ղá������å���ػ�
 *���ӥå�4�����ѥ�ƥ��⡼�ɡ�̤���ѡ�
 *���ӥå�3=0�����ȥåץӥåȥ�󥰥���1�ӥå�
 *���ӥå�1,0���ܡ��졼�ȥ����ͥ졼���ؤΥ���å�����������
 *���������������ܡ��ɰ�¸����SCRn_CKS�Ȥ��������n��ch�ֹ��
 */
#define SMR_INIT	0

/* SCR */
#define TIE	BIT7
#define	RIE	BIT6
#define	TE	BIT5
#define	RE	BIT4
#define	MPIE	BIT3
#define TEIE	BIT2
#define	CKE1	BIT1
#define	CKE0	BIT0

/* SSR */
#define TDRE	BIT7
#define	RDRF	BIT6
#define	ORER	BIT5
#define	FER	BIT4
#define	PER	BIT3
#define TEND	BIT2
#define	MPB	BIT1
#define	MPBT	BIT0


/* 
 * TNUM_PORT : ���ꥢ��ɥ饤�С�serial.c�ˡ��Ĥޤ� GDIC��٥�ǥ��ݡ��Ȥ���
 * ���������������ꥢ��ݡ��Ȥο� 
 * TNUM_SIOP : PDIC��٥�ʥץ��å���¢SIO�ˤǥ��ݡ��Ȥ��륷�ꥢ��I/O�ݡ���
 *������������ �ο��ʸ��ߤμ����ǤϺ���3��
 *  
 *���������user_config.h��������롣
 */

/* �ʲ��ǡ��쥸�����Υ��ɥ쥹��UW ���إ��㥹�Ȥ򤷤Ƥ��롣����ϡ��١���
   ���ɥ쥹�˥��ե��å��ͤ�ä��ơ��ǽ�Ū�ʥ쥸�����Υ��ɥ쥹����Ƥ���
   ����Ǥ��롣������ˡ��ǽ�Ū�� VP ���˥��㥹�Ȥ���Ƥ��롣(h8s_sci.h) */

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å������
 */
typedef struct sio_port_initialization_block {
	UW	reg_base;	/* �쥸�����Υ١������ɥ쥹 */
	UH	boud_rate;	/* �ܡ��졼��[bps]��*/
	UB	boud_brr_def;	/* BRR �����͡ʥܡ��졼�Ȥ������͡� */
	UB	smr_def;	/* SMR ������
				   (�������ӥåȿ������ȥåץӥåȡ��ѥ�ƥ�) */
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 */
struct sio_port_control_block {
	const SIOPINIB	*siopinib;	/* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
	VP_INT		exinf;		/* ��ĥ���� */
	BOOL		openflag;	/* �����ץ�Ѥߥե饰 */
	BOOL		getready;	/* ʸ��������������� */
	BOOL		putready;	/* ʸ���������Ǥ������ */
};

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{ (UW)SCI0_BASE_ADDR,
	  (UH)BAUD_RATE1,
	  (UB)BRR0_RATE,			/* N �� */
	  (UB)(SMR_INIT | (SCR0_CKS & (CKE1 | CKE0)))
	},
#if TNUM_SIOP >= 2
	{ (UW)SCI1_BASE_ADDR,
	  (UH)BAUD_RATE1,
	  (UB)BRR1_RATE,			/* N �� */
	  (UB)(SMR_INIT | (SCR1_CKS & (CKE1 | CKE0)))
	}
#endif /* TNUM_SIOP >= 2 */
#if TNUM_SIOP >= 3
	,{(UW)SCI2_BASE_ADDR,
	  (UH)BAUD_RATE2,
	  (UB)BRR2_RATE,			/* N �� */
	  (UB)(SMR_INIT | (SCR2_CKS & (CKE1 | CKE0)))
	}
#endif /* TNUM_SIOP >= 3 */
};

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å��μ�Ф�
 */
#define INDEX_SIOPINIB(siopid)	((UINT)((siopid) - 1))
#define get_siopinib(siopid)	(&(siopinib_table[INDEX_SIOPINIB(siopid)]))

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  SCI�ѥ����ƥ।�󥿥ե������쥤��
 *
 *   base : �ݡ��ȤΥ١������ɥ쥹
 *   offset : �쥸�������ե��å�
 *   val : �쥸������ 
 */
#define h8s_sci_wrb( base, offset, val ) h8s_wrb_reg( (base) + (offset), (val) )
#define h8s_sci_reb( base, offset )	h8s_reb_reg( (base) + (offset) )

/*
 *  SCI�ѥ쥸�������ؿ�
 */
Inline void
h8s_sci_or( const SIOPINIB *siopinib, INT offset, INT val )
{
	UB reg = h8s_sci_reb( siopinib->reg_base, offset );
	h8s_sci_wrb( siopinib->reg_base, offset, reg | (UB)val );
}

Inline void
h8s_sci_and( const SIOPINIB *siopinib, INT offset, INT val )
{
	UB reg = h8s_sci_reb( siopinib->reg_base, offset );
	h8s_sci_wrb( siopinib->reg_base, offset, reg & (UB)val );
}

/*
 *  ʸ��������Ǥ��뤫��
 */
Inline BOOL
h8s_sci_getready(SIOPCB *siopcb)
{
	UB ssr;
	
	siopcb->getready = FALSE;
	ssr =  h8s_sci_reb( siopcb->siopinib->reg_base, SSR );
	if( ssr & RDRF ) {
		siopcb->getready = TRUE;
	}
	return( siopcb->getready );
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
h8s_sci_putready(SIOPCB *siopcb)
{
	siopcb->putready = FALSE;
	if( h8s_sci_reb( siopcb->siopinib->reg_base, SSR ) & TDRE ) {
		siopcb->putready = TRUE;
	}
	return( siopcb->putready );
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
h8s_sci_getchar(SIOPCB *siopcb)
{
	/* RDRF���ꥢ */
	h8s_sci_and( siopcb->siopinib, SSR, ~RDRF );

	return( (char) h8s_sci_reb( siopcb->siopinib->reg_base, RDR ) );
}

/*
 *  ��������ʸ���ν����
 */
Inline void
h8s_sci_putchar(SIOPCB *siopcb, char c)
{
	h8s_sci_wrb( siopcb->siopinib->reg_base, TDR, c );

	/* TDRE���ꥢ */
	h8s_sci_and( siopcb->siopinib, SSR, ~TDRE );
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
h8s_sci_initialize(void)
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->siopinib = &(siopinib_table[i]);
		siopcb->openflag = FALSE;
	}
}

/*
 *  SIO�쥸����������롼����
 */
void
h8s_sci_init_siopinib( const SIOPINIB  *siopinib )
{
	/*
	 * SCI�쥸�����ν����
	 */

	/* ��������� */
	h8s_sci_and( siopinib, SCR, ~( TE | RE ) );

	/* �ӥå�Ĺ�ʤ����� */
	h8s_sci_wrb( siopinib->reg_base, SMR, siopinib->smr_def );

	/* �ܡ��졼������ */
	h8s_sci_wrb( siopinib->reg_base, BRR, siopinib->boud_brr_def );

	/*
	 *  ����߶ػߤȥ���å�����������
	 *��������å�����������������å�������
	 */
	h8s_sci_and( siopinib, SCR, ~( TIE | RIE | MPIE | TEIE | CKE1 | CKE0 ) );

	/* �ܡ��졼�Ȥΰ��경(1bitʬ���Ԥ�) */
	sil_dly_nse_long( 1000000000ul / (siopinib->boud_rate) );

	/* ���顼�ե饰�򥯥ꥢ */
	h8s_sci_and( siopinib, SSR, ~( ORER | FER | PER ) );	/* ���� */

	/* ���������ġ���������ߵ��� */
	h8s_sci_or( siopinib, SCR, ( RIE | TE | RE ) );
}


/*
 *  SCI0�������̷�⤬�ʤ��������å�
 */
#if defined(OMIT_SCI0) && (POL_PORTID == 1)
#error h8s_sci_putchar_pol serial port ID error.
#endif

/*
 *  �����ͥ뵯ư���ΥС��ʡ������Ѥν����
 */
void
h8s_sci_init(void)
{
	h8s_sci_init_siopinib( get_siopinib(POL_PORTID) );
}

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
BOOL
h8s_sci_openflag(void)
{
	BOOL ret;
#ifndef OMIT_SCI0
	ret = siopcb_table[0].openflag;
#else /* OMIT_SCI0 */
	ret = FALSE;
#endif /* OMIT_SCI0 */

#if TNUM_SIOP >= 2
	ret |= siopcb_table[1].openflag;
#endif /* TNUM_SIOP >= 2 */

#if TNUM_SIOP >= 3
	ret |= siopcb_table[2].openflag;
#endif /* TNUM_SIOP >= 3 */

	return(ret);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
h8s_sci_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB 		*siopcb = get_siopcb(siopid);
	const SIOPINIB  *siopinib = siopcb->siopinib;

	/* SCI�쥸�����ν���� */
	h8s_sci_init_siopinib( siopinib );

	/* ����ߥ�٥����ꡢ������׵᥯�ꥢ�ϡ�sio_opn_por �ǹԤ��� */

	siopcb->exinf = exinf;
	siopcb->getready = siopcb->putready = FALSE;
	siopcb->openflag = TRUE;

	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
h8s_sci_cls_por(SIOPCB *siopcb)
{
	/* TEND �� 1 �ˤʤ�ޤ��Ԥ� */
	while ( !(h8s_sci_reb( siopcb->siopinib->reg_base, SSR ) & TEND ) );

	h8s_sci_and( siopcb->siopinib, SCR, ~( TE | RE ) );	/* ���� */
	siopcb->openflag = FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
h8s_sci_snd_chr(SIOPCB *siopcb, char c)
{
	if( h8s_sci_putready(siopcb) ) {
		h8s_sci_putchar(siopcb, c);
		siopcb->putready = FALSE;
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
h8s_sci_rcv_chr(SIOPCB *siopcb)
{
	if( h8s_sci_getready(siopcb) ) {
		siopcb->getready = FALSE;
		return( (INT)(UB) h8s_sci_getchar(siopcb) );
			/* UB �Υ��㥹�Ȥϡ�����ĥ���ɻߤ��뤿�� */
	}

	return(-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
h8s_sci_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		h8s_sci_or( siopcb->siopinib, SCR, TIE );
		return;
	case SIO_ERDY_RCV:
		h8s_sci_or( siopcb->siopinib, SCR, RIE );
		return;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
h8s_sci_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch( cbrtn ) {
	case SIO_ERDY_SND:
		h8s_sci_and( siopcb->siopinib, SCR, ~TIE );
		return;
	case SIO_ERDY_RCV:
		h8s_sci_and( siopcb->siopinib, SCR, ~RIE );
		return;
	}
}

/*
 *  SIO�γ���ߥ����ӥ��롼����
 *����������ͥ붦����ʬ�򥤥�饤��ؿ��Ȥ���������Ƥ���
 */
Inline void
h8s_scix_isr_in(ID portid)
{
	SIOPCB *siopcb = get_siopcb(portid);

	/* �������Υ�����Хå��롼����θƤӽФ� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_rcv( siopcb->exinf );
	}
}

Inline void
h8s_scix_isr_out(ID portid)
{
	SIOPCB *siopcb = get_siopcb(portid);

	/* ������ǽ������Хå��롼����θƤӽФ� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_snd( siopcb->exinf );
	}
}

/*
 *  SIO�μ������顼����ߥ����ӥ��롼����
 *����������ͥ붦����ʬ�򥤥�饤��ؿ��Ȥ���������Ƥ���
 *
 *  ���顼�����ϡ��������顼�ե饰�Υ��ꥢ�Τߡ�
 *  �������С���󥨥顼���ե졼�ߥ󥰥��顼���ѥ�ƥ����顼
 */
Inline void
h8s_scix_isr_error(INT portid)
{
	SIOPCB *siopcb = get_siopcb(portid);

	if( siopcb->openflag ) {
		/*  ���顼�ե饰���ꥢ  */
		h8s_sci_and( siopcb->siopinib, SSR, ~( RDRF | ORER | FER | PER ) );
	}
}


#ifndef OMIT_SCI0
/*
 *  SIO�γ���ߥ����ӥ��롼���� (SCI0����)
 */
void
h8s_sci0_isr_in(void)
{
	h8s_scix_isr_in(1);
}

void
h8s_sci0_isr_out(void)
{
	h8s_scix_isr_out(1);
}

/*
 *  SIO�μ������顼����ߥ����ӥ��롼���� (SCI0����)
 */
void
h8s_sci0_isr_error(void)
{
	h8s_scix_isr_error(1);
}

#endif /*  OMIT_SCI0  */

#if TNUM_SIOP >=2
/*
 *  SIO�γ���ߥ����ӥ��롼���� (SCI1����)
 */
void
h8s_sci1_isr_in(void)
{
	h8s_scix_isr_in(2);
}

void
h8s_sci1_isr_out(void)
{
	h8s_scix_isr_out(2);
}

/*
 *  SIO�μ������顼����ߥ����ӥ��롼���� (SCI1����)
 */
void
h8s_sci1_isr_error(void)
{
	h8s_scix_isr_error(2);
}
#endif /* TNUM_SIOP >=2 */

#if TNUM_SIOP >=3
/*
 *  SIO�γ���ߥ����ӥ��롼���� (SCI2����)
 */
void
h8s_sci2_isr_in(void)
{
	h8s_scix_isr_in(3);
}

void
h8s_sci2_isr_out(void)
{
	h8s_scix_isr_out(3);
}

/*
 *  SIO�μ������顼����ߥ����ӥ��롼���� (SCI2����)
 */
void
h8s_sci2_isr_error(void)
{
	h8s_scix_isr_error(3);
}
#endif /* TNUM_SIOP >=3 */


/*
 *  H8S ��¢ SCI �ѥݡ���󥰽��� (POL_PORTID���ѡ�sys_putc������)
 */
void
h8s_sci_putchar_pol( char c )
{

	const SIOPINIB  *siopinib = get_siopinib( POL_PORTID );

	/* TDRE �� 1 �ˤʤ�ޤ��Ԥ� */
	while ( !(h8s_sci_reb( siopinib->reg_base, SSR ) & TDRE ) );

	h8s_sci_wrb( siopinib->reg_base, TDR, c );

	/* TDRE���ꥢ */
	h8s_sci_and( siopinib, SSR, ~TDRE );

	/* TEND �� 1 �ˤʤ�ޤ��Ԥ� */
	while ( !(h8s_sci_reb( siopinib->reg_base, SSR ) & TEND ) );
}
