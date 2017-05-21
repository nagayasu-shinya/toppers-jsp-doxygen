/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 
#include <vr4131_dsiu.h>

/*
 *	VR4131��¢DSIU�� �ʰ�SIO�ɥ饤��
 */

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å������
 */
typedef struct sio_port_initialization_block {
	UB	lcr_def;	/* LCR������ b0-b6;
				   (�������ӥåȿ������ȥåץӥåȡ��ѥ�ƥ�) */
	UB	boud_hi_def;	/* DLM�����͡ʥܡ��졼�Ⱦ�̤������͡� */
	UB	boud_lo_def;	/* DLL�����͡ʥܡ��졼�Ȳ��̤������͡� */
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
 *  �ʥݡ��Ȥϣ��Ĥ����ʤ�����¾�Υ����������ɤȤο����������������������
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{ (UB)	WORD_LENGTH_8 | STOP_BITS_1 | PARITY_NON,
	  (UB)	HI8(DIVISOR),
	  (UB)	LO8(DIVISOR) }
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
 *  ���֤��ɽФ���IID���ɽФ���
 */
static void
vr4131_dsiu_get_stat(SIOPCB *siopcb)
{
	UB	iid;

	iid = vr4131_reb_mem( (VP) DSIUIID ) & INT_MASK;

	switch( iid ) {
		case INT_TRANS_EMPTY :
			siopcb->putready = TRUE;
			break;
		case INT_RECEIVE_DATA :
		case INT_CHAR_TIME_OUT :
			siopcb->getready = TRUE;
			break;
		default :
			break;
	}


}

/*
 *  ʸ��������Ǥ��뤫��
 */
Inline BOOL
vr4131_dsiu_getready(SIOPCB *siopcb)
{
	return(siopcb->getready);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
vr4131_dsiu_putready(SIOPCB *siopcb)
{
	return(siopcb->putready);
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
vr4131_dsiu_getchar(SIOPCB *siopcb)
{
	siopcb->getready = FALSE;
	return((char) vr4131_reb_mem( (VP) DSIURB ));
}

/*
 *  ��������ʸ���ν����
 */
Inline void
vr4131_dsiu_putchar(SIOPCB *siopcb, char c)
{
	siopcb->putready = FALSE;

#ifndef GDB_STUB
	vr4131_wrb_mem( (VP) DSIUTH, c );
#else /* GDB_STUB */
	stub_putc( c );
#endif /* GDB_STUB */
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
vr4131_dsiu_initialize()
{
	SIOPCB	*siopcb = siopcb_table;
	UINT	i = 0;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
	 */
	siopcb->siopinib = &(siopinib_table[i]);
	siopcb->openflag = FALSE;
}

/*
 *  SIO�쥸����������롼����
 */
void
vr4131_dsiu_init_siopinib( const SIOPINIB  *siopinib )
{
	/*
	 * DSIU�쥸�����ν����
	 */
	/* ������� */
	vr4131_wrb_mem( (VP) DSIUIE,  DIS_INT );

	/* �ܡ��졼�Ȥ����� */
	vr4131_wrb_mem( (VP) DSIULC,  siopinib->lcr_def | DIVISOR_LATCH_ACC );

	vr4131_wrb_mem( (VP) DSIUDLL, siopinib->boud_lo_def );
	vr4131_wrb_mem( (VP) DSIUDLM, siopinib->boud_hi_def );

	/* �⡼�ɤ����� */
	vr4131_wrb_mem( (VP) DSIULC,  siopinib->lcr_def );

	/* FIFO������ */
	vr4131_wrb_mem( (VP) DSIUFC,  FIFO_ENABLE );
	vr4131_wrb_mem( (VP) DSIUFC,  FIFO_ENABLE | RECEIVE_FIFO_RESET | TRANS_FIFO_RESET | RECEIVE_TRIG_1_BYTE );
	vr4131_wrb_mem( (VP) DSIUFC,  FIFO_ENABLE | RECEIVE_TRIG_1_BYTE );

	/* ��λ���� */
	vr4131_wrb_mem( (VP) DSIUMC,  RTS );

	vr4131_wrb_mem( (VP) DSIUIE,  RECEIVE_DATA_AVAILABLE);
}

/*
 *  �����ͥ뵯ư���ΥС��ʡ������Ѥν����
 */
void
vr4131_dsiu_init(void)
{
	vr4131_dsiu_init_siopinib( get_siopinib(1) );
}

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
BOOL
vr4131_dsiu_openflag(void)
{
	return( siopcb_table[0].openflag );
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
vr4131_dsiu_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB		*siopcb = get_siopcb(siopid);
	const SIOPINIB	*siopinib = siopcb->siopinib;

#ifndef GDB_STUB
	/* DSIU�쥸�����ν���� */
	vr4131_dsiu_init_siopinib( siopinib );
#endif	/*  GDB_STUB  */

	/* ����ߥ�٥����ꡢ������׵᥯�ꥢ�ϡ�sio_opn_por(hw_serial.h)�ǹԤ��� */

	siopcb->exinf = exinf;
	siopcb->getready = siopcb->putready = FALSE;
	siopcb->openflag = TRUE;

	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
vr4131_dsiu_cls_por(SIOPCB *siopcb)
{
	vr4131_wrb_mem( (VP) DSIUIE, DIS_INT );

	siopcb->openflag = FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
vr4131_dsiu_snd_chr(SIOPCB *siopcb, char c)
{
	if (vr4131_dsiu_putready(siopcb)) {
		vr4131_dsiu_putchar(siopcb, c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
vr4131_dsiu_rcv_chr(SIOPCB *siopcb)
{
	if (vr4131_dsiu_getready(siopcb)) {
		return((INT)(UB) vr4131_dsiu_getchar(siopcb));
	}
	return(-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
vr4131_dsiu_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ie_bit = 0;

	switch (cbrtn) {
	case SIO_ERDY_SND:
		ie_bit = TRANS_REG_EMPTY;
		break;
	case SIO_ERDY_RCV:
		ie_bit = RECEIVE_DATA_AVAILABLE | RECEIVE_LINE_STATUS;
		break;
	}

	vr4131_orb( (VP) DSIUIE, ie_bit );
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
vr4131_dsiu_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ie_bit = 0;

	switch (cbrtn) {
	case SIO_ERDY_SND:
		ie_bit = TRANS_REG_EMPTY;
		break;
	case SIO_ERDY_RCV:
		ie_bit = RECEIVE_DATA_AVAILABLE | RECEIVE_LINE_STATUS;
		break;
	}

	vr4131_andb( (VP) DSIUIE, ~ie_bit );
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф������߽���
 */
static void
vr4131_dsiu_isr_siop(SIOPCB *siopcb)
{
	vr4131_dsiu_get_stat(siopcb);

	if ( vr4131_dsiu_getready(siopcb) ) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		vr4131_dsiu_ierdy_rcv(siopcb->exinf);
	}
	if ( vr4131_dsiu_putready(siopcb) ) {
		/*
		 *  ������ǽ������Хå��롼�����ƤӽФ���
		 */
		vr4131_dsiu_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
void
vr4131_dsiu_isr()
{
	if (siopcb_table[0].openflag) {
		vr4131_dsiu_isr_siop(&(siopcb_table[0]));
	}
}

/*
 *  VR4131 ��¢ DSIU �ѥݡ���󥰽��� (sys_putc������)
 */
void
vr4131_dsiu_putchar_pol( char val ) {

	/* ����������ץƥ��ˤʤ�ޤ��Ԥġ� */
	while( (vr4131_reb_mem( (VP)DSIULS ) & (TEMT) ) == 0 );

	vr4131_wrb_mem( (VP)DSIUTH, (VB) val );
}
