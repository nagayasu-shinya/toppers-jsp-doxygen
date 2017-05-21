/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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

#include <h8s_sci.h>

/*
 *  H8S��¢SCI�� �ʰ�SIO�ɥ饤��
 *  �������ϡ��������ͥ��Ѥ˵��Ҥ��Ƥ��롣H8S���꡼������ˤϡ��������ͥ�
 *    �ʾ奵�ݡ��Ȥ��Ƥ�����åפ⤢�뤬�����ΤȤ����б����ưפǤ��롣
 */

/* TNUM_SIOP : ���ݡ��Ȥ��륷�ꥢ��ݡ��Ȥο� (�ǥե������ 2)
   TNUM_PORT : ���ݡ��Ȥ��륷�ꥢ��I/O�ݡ��Ȥο� (�ǥե������ 2)
   (sys_config.h �˵���) */

/* �ʲ��ǡ��쥸�����Υ��ɥ쥹��UW ���إ��㥹�Ȥ򤷤Ƥ��롣����ϡ��١���
   ���ɥ쥹�˥��ե��å��ͤ�ä��ơ��ǽ�Ū�ʥ쥸�����Υ��ɥ쥹����Ƥ���
   ����Ǥ��롣������ˡ��ǽ�Ū�� VP ���˥��㥹�Ȥ���Ƥ��롣(h8s_sci.h) */

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å������
 */
typedef struct sio_port_initialization_block {
	UW	reg_base;	/* �쥸�����Υ١������ɥ쥹 */
	UB	smr_def;	/* SMR ������ b6-b3;
				   (�������ӥåȿ������ȥåץӥåȡ��ѥ�ƥ�) */
	UB	boud_brr_def;	/* BRR �����͡ʥܡ��졼�Ȥ������͡� */
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
	{ (UW)	SCI0_BASE_ADDR,
	  (UB)	0,
	  (UB)	BRR_RATE		/* N �� */
	},
#if TNUM_SIOP >= 2
	{ (UW)	SCI1_BASE_ADDR,
	  (UB)	0,
	  (UB)	BRR_RATE		/* N �� */
	}
#endif /* TNUM_SIOP >= 2 */
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
 *  SCI�ѥ쥸�������ؿ�
 */
Inline void
h8s_sci_or( const SIOPINIB *siopinib, UW reg, UB val )
{
	h8s_sci_wrb( siopinib->reg_base, reg, h8s_sci_reb( siopinib->reg_base, reg ) | val );
}

Inline void
h8s_sci_and( const SIOPINIB *siopinib, UW reg, UB val )
{
	h8s_sci_wrb( siopinib->reg_base, reg, h8s_sci_reb( siopinib->reg_base, reg ) & val );
}

/*
 *  ʸ��������Ǥ��뤫��
 */
Inline BOOL
h8s_sci_getready(SIOPCB *siopcb)
{
	siopcb->getready = FALSE;
	if( h8s_sci_reb( siopcb->siopinib->reg_base, (UW) SSR ) & RDRF )
		siopcb->getready = TRUE;

	return( siopcb->getready );
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
h8s_sci_putready(SIOPCB *siopcb)
{
	siopcb->putready = FALSE;
	if( h8s_sci_reb( siopcb->siopinib->reg_base, (UW) SSR ) & TDRE )
		siopcb->putready = TRUE;

	return( siopcb->putready );
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
h8s_sci_getchar(SIOPCB *siopcb)
{
	/* RDRF���ꥢ */
	h8s_sci_and( siopcb->siopinib, (UW) SSR, (UB) ~RDRF );

	return( (char) h8s_sci_reb( siopcb->siopinib->reg_base, (UW) RDR ) );
}

/*
 *  ��������ʸ���ν����
 */
Inline void
h8s_sci_putchar(SIOPCB *siopcb, char c)
{
#ifndef GDB_STUB
	h8s_sci_wrb( siopcb->siopinib->reg_base, (UW) TDR, c );

	/* TDRE���ꥢ */
	h8s_sci_and( siopcb->siopinib, (UW) SSR, (UB) ~TDRE );
#else
	stub_putc( c );
#endif
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
h8s_sci_initialize()
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
	h8s_sci_and( siopinib, (UW) SCR, (UB) ~( TE | RE ) );

	/* �ӥå�Ĺ�ʤ����� */
	h8s_sci_wrb( siopinib->reg_base, (UW) SMR, siopinib->smr_def );

	/* �ܡ��졼������ */
	h8s_sci_wrb( siopinib->reg_base, (UW) BRR, siopinib->boud_brr_def );

	/* ����߶ػߤȥ���å����������� */
	h8s_sci_and( siopinib, (UW) SCR, (UB) ~( TIE | RIE | MPIE | TEIE | CKE1 | CKE0 ) );

	/* �ܡ��졼�Ȥΰ��경(1bitʬ���Ԥ�) */
	sil_dly_nse( 1/BAUD_RATE );

	/* ���顼�ե饰�򥯥ꥢ */
	h8s_sci_and( siopinib, (UW) SSR, ~( ORER | FER | PER ) );

	/* ���������ġ���������ߵ��� */
	h8s_sci_or( siopinib, (UW) SCR, ( RIE | TE | RE ) );
}

/*
 *  �����ͥ뵯ư���ΥС��ʡ������Ѥν����
 */
void
h8s_sci_init(void)
{
	h8s_sci_init_siopinib( get_siopinib(1) );
#if TNUM_SIOP >= 2
	h8s_sci_init_siopinib( get_siopinib(2) );
#endif /* TNUM_SIOP >= 2 */
}

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
BOOL
h8s_sci_openflag(void)
{
#if TNUM_SIOP < 2
	return( siopcb_table[0].openflag );
#else /* TNUM_SIOP < 2 */
	return( siopcb_table[0].openflag || siopcb_table[1].openflag );
#endif /* TNUM_SIOP < 2 */
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
h8s_sci_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB 		*siopcb = get_siopcb(siopid);
	const SIOPINIB  *siopinib = siopcb->siopinib;

#ifndef GDB_STUB
	/* SCI�쥸�����ν���� */
	h8s_sci_init_siopinib( siopinib );
#endif	/* GDB_STUB */

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
	while ( !(h8s_sci_reb( siopcb->siopinib->reg_base, (UW) SSR ) & TEND ) );

	h8s_sci_and( siopcb->siopinib, (UW) SCR, ~( TE | RE ) );
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
			/* UB �Υ��㥹�Ȥϡ�����ĥ�ɻߤ��뤿�� */
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
		h8s_sci_or( siopcb->siopinib, (UW) SCR, TIE );
		return;
	case SIO_ERDY_RCV:
		h8s_sci_or( siopcb->siopinib, (UW) SCR, RIE );
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
		h8s_sci_and( siopcb->siopinib, (UW) SCR, (UB) ~TIE );
		return;
	case SIO_ERDY_RCV:
		h8s_sci_and( siopcb->siopinib, (UW) SCR, (UB) ~RIE );
		return;
	}
}

/*
 *  SIO�γ���ߥ����ӥ��롼���� (SCI0����)
 */
void
h8s_sci0_isr_in()
{
	SIOPCB *siopcb = get_siopcb(1);

	/* �������Υ�����Хå��롼����θƤӽФ� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_rcv( siopcb->exinf );
	}
}

void
h8s_sci0_isr_out()
{
	SIOPCB *siopcb = get_siopcb(1);

	/* ������ǽ������Хå��롼����θƤӽФ� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_snd( siopcb->exinf );
	}
}

/*
 *  SIO�μ������顼����ߥ����ӥ��롼���� (SCI0����)
 *
 *  ���顼�����ϡ��������顼�ե饰�Υ��ꥢ�Τߡ�
 *  �������С���󥨥顼���ե졼�ߥ󥰥��顼���ѥ�ƥ����顼
 */
void
h8s_sci0_isr_error(void)
{
	SIOPCB *siopcb = get_siopcb(1);

	if( siopcb->openflag ) {
		/*  ���顼�ե饰���ꥢ  */
		h8s_sci_and( siopcb->siopinib, (UW) SSR, ~( RDRF | ORER | FER | PER ) );
	}
}

/*
 *  SIO�γ���ߥ����ӥ��롼���� (SCI1����)
 */
void
h8s_sci1_isr_in()
{
	SIOPCB *siopcb = get_siopcb(2);

	/* �������Υ�����Хå��롼����θƤӽФ� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_rcv( siopcb->exinf );
	}
}

void
h8s_sci1_isr_out()
{
	SIOPCB *siopcb = get_siopcb(2);

	/* ������ǽ������Хå��롼����θƤӽФ� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_snd( siopcb->exinf );
	}
}

/*
 *  SIO�μ������顼����ߥ����ӥ��롼���� (SCI1����)
 *
 *  ���顼�����ϡ��������顼�ե饰�Υ��ꥢ�Τߡ�
 *  �������С���󥨥顼���ե졼�ߥ󥰥��顼���ѥ�ƥ����顼
 */
void
h8s_sci1_isr_error(void)
{
	SIOPCB *siopcb = get_siopcb(2);

	if( siopcb->openflag ) {
		/*  ���顼�ե饰���ꥢ  */
		h8s_sci_and( siopcb->siopinib, (UW) SSR, ~( RDRF | ORER | FER | PER ) );
	}
}

/*
 *  H8S ��¢ SCI �ѥݡ���󥰽��� (LOGTASK_PORTID���ѡ�sys_putc������)
 */
void
h8s_sci0_putchar_pol( char c )
{

	const SIOPINIB  *siopinib = get_siopinib( LOGTASK_PORTID );

	/* TDRE �� 1 �ˤʤ�ޤ��Ԥ� */
	while ( !(h8s_sci_reb( siopinib->reg_base, (UW) SSR ) & TDRE ) );

	h8s_sci_wrb( siopinib->reg_base, (UW) TDR, (UB) c );

	/* TDRE���ꥢ */
	h8s_sci_and( siopinib, (UW) SSR, (UB) ~TDRE );

	/* TEND �� 1 �ˤʤ�ޤ��Ԥ� */
	while ( !(h8s_sci_reb( siopinib->reg_base, (UW) SSR ) & TEND ) );
}
