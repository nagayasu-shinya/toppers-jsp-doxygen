/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */

/*
 * �������åȰ�¸���ꥢ��I/O�⥸�塼��(DMT33209)
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include "s_services.h"

/*
 *  ���ꥢ��I/O�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define INHNO_SERIAL_IN		S1C33_INHNO_SERIAL0RX
#define INHNO_SERIAL_OUT	S1C33_INHNO_SERIAL0TX
#define INHNO_SERIAL_ERR	S1C33_INHNO_SERIAL0ERR

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND		1	/* ������ǽ������Хå�	*/
#define SIO_ERDY_RCV		2	/* �������Υ�����Хå�	*/

#define INDEX_SIO(sioid)	((UINT)((sioid) - 1))

/*
 *  SIO�������װ��ե饰 �ӥåȰ���
 */
#define SIO_INT_ERR		0x01
#define	SIO_INT_RCV		0x02
#define	SIO_INT_SND		0x04

/*
 * ���顼�ե饰 �ӥåȰ���
 */
#define SIO_ERR_FRAME		0x10
#define SIO_ERR_PARITY		0x08
#define SIO_ERR_OVERRUN		0x04

#ifndef _MACRO_ONLY
/*
 *	���ꥢ��ݡ��ȤΥϡ��ɥ�������¸��������
 */
typedef struct {
	UB	ch_no;		/* SIO����ͥ��ֹ�		*/
	UB	err_vector;	/* �̿����顼�����ߥ٥����ֹ�	*/
	UB	rx_vector;	/* ���������ߥ٥����ֹ�	*/
	UB	tx_vector;	/* ������λ�����ߥ٥����ֹ�	*/
} SIOPINIB;

/*
 *  ���ꥢ��ݡ��Ȥ�����֥�å�
 */
typedef struct {
	const SIOPINIB	*inib;		/* ������֥�å�	*/
	VP_INT		exinf;		/* ��ĥ����		*/
	BOOL		openflag;	/* �����ץ�Ѥߥե饰	*/
	BOOL		tx_cbrflag;	/* ����������Хå��¹ԥե饰*/
	BOOL		rx_cbrflag;	/* ����������Хå��¹ԥե饰*/
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  �����ؿ��λ���
 */
extern void	sio_initialize (void);
extern void	sio_ena_cbr(SIOPCB *siopcb, UINT cbrtn);
extern void	sio_dis_cbr(SIOPCB *siopcb, UINT cbrtn);
extern void	serial_handler_in(ID portid);
extern void	serial_handler_out(ID portid);
extern void	sio_ierdy_snd(VP_INT exinf);
extern void	sio_ierdy_rcv(VP_INT exinf);
extern ER	ena_int(INTNO);
extern ER	dis_int(INTNO);

/*
 *  ���ꥢ��ݡ��Ȥν����
 */
Inline SIOPCB
*sio_opn_por(ID siopid, VP_INT exinf)
{
	B	temp;

	/*
	 *  �����ߤζػ�
	 */
	if(siopid == 1){
		dis_int(S1C33_INHNO_SERIAL0RX);
		dis_int(S1C33_INHNO_SERIAL0TX);
#ifdef SIO_ERR_HANDLER
		dis_int(S1C33_INHNO_SERIAL0ERR);
#endif
	} else {
		dis_int(S1C33_INHNO_SERIAL1RX);
		dis_int(S1C33_INHNO_SERIAL1TX);
#ifdef SIO_ERR_HANDLER
		dis_int(S1C33_INHNO_SERIAL1ERR);
#endif
	}

	/*
	 *  ���ꥢ��I/F������
	 *
	 *  8bitĴ��Ʊ��  �ѥ�ƥ��ʤ� ���ȥåץӥå�1bit  ��������å�
	 */
	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[INDEX_SIO(siopid)].bControl = 0x07;

	((s1c33Port_t *)S1C33_PORT_BASE)->stPPort[INDEX_SIO(siopid)].bFuncSwitch = 0x07;
	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[INDEX_SIO(siopid)].bIrDA = 0x00;

	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[INDEX_SIO(siopid)].bControl = 0xc7;

	/*
	 *  ������װ��򥯥ꥢ
	 */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntFactor[6] |= (0x07 << INDEX_SIO(siopid));

	/*
	 *  �����Хåե��Υ��ꥢ
	 */
	temp = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[INDEX_SIO(siopid)].bRxd;

	/*
	 *  ������������
	 */
	siopcb_table[INDEX_SIO(siopid)].openflag = TRUE;
	if(exinf != NULL){
		siopcb_table[INDEX_SIO(siopid)].exinf = exinf;
	}

	/*
	 *  �����ߤε���
	 */
	if(siopid == 1){
		ena_int(S1C33_INHNO_SERIAL0RX);
		ena_int(S1C33_INHNO_SERIAL0TX);
#ifdef SIO_ERR_HANDLER
		ena_int(S1C33_INHNO_SERIAL0ERR);
#endif
	} else {
		ena_int(S1C33_INHNO_SERIAL1RX);
		ena_int(S1C33_INHNO_SERIAL1TX);
#ifdef SIO_ERR_HANDLER
		ena_int(S1C33_INHNO_SERIAL1ERR);
#endif
	}

	return (&(siopcb_table[INDEX_SIO(siopid)]));
}

/*
 *  �̿������
 */
Inline void
sio_cls_por(SIOPCB *siopcb)
{
	UB	ch_no;

	ch_no = siopcb->inib->ch_no;
	/*
	 *  ž����λ���Ԥ�
	 */
	while(((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bStatus & 0x20){
		;
	}

	/*
	 *  �̿���ػߤ���
	 */
	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bControl = 0x07;

	return;
}

/*
 *  ������ǽ�ξ��֤����
 */
Inline BOOL
sio_get_txready(UB ch_no)
{
	UB	bSioSts;

	bSioSts = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bStatus;

	return(!(bSioSts & 0x20));
}

/*
 *  ������ǽ�ξ��֤����
 */
Inline BOOL
sio_get_rxready(UB ch_no)
{
	UB	bSioSts;

	bSioSts = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bStatus;

	return(bSioSts & 0x01);
}

/*
 *  ��������1ʸ�����ɤ߹���
 */
Inline INT
sio_rcv_chr(SIOPCB *siopcb)
{
	BOOL	blRxSts;
	UB	ch_no;


	ch_no = siopcb->inib->ch_no;
	blRxSts  = sio_get_rxready(ch_no);

	if(blRxSts){
		return (((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bRxd);
	}

	return (-1);
}

/*
 *  ��������1ʸ����񤭹���
 */
Inline BOOL
sio_snd_chr(SIOPCB *siopcb, char c)
{
	BOOL	blTxSts;
	UB	ch_no;

	ch_no = siopcb->inib->ch_no;
	blTxSts = sio_get_txready(ch_no);
	if(blTxSts){
		((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bTxd = c;
	}

	return(blTxSts);
}

/*
 *  ���ꤵ�줿SIO����ͥ�γ������װ��򥯥ꥢ����
 */
Inline void
sio_clr_factor(UB bFlag)
{
	((volatile s1c33Intc_t *) S1C33_INTC_BASE)->bIntFactor[6] |= bFlag;
}

/*  ���ꤵ�줿SIO����ͥ�Υ��顼�ե饰�򥯥ꥢ����
 *
 */
Inline void
sio_clr_errflag(UB ch_no)
{
	((volatile s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bStatus
		&= ~(SIO_ERR_OVERRUN | SIO_ERR_PARITY | SIO_ERR_FRAME);
}

#endif /* _MACRO_ONLY   */
#endif /* _HW_SERIAL_H_ */
