/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2010 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: hw_serial.h,v 1.17 2007/03/23 07:22:15 honda Exp $
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

/*
 *  �������åȰ�¸���ꥢ��I/O�⥸�塼���H8�ѡ�
 *    ���ݡ��Ȥ� 1�ܤξ��� HWPORT1_ADDR�˻��ꤵ�줿�ݡ��Ȥ���Ѥ���
 *      2�ܤξ��ϡ�HWPORT1_ADDR��桼���ѡ�HWPORT2_ADDR�򥳥󥽡���
 *      ���ϤȤ��ƻ��Ѥ��롣
 *      HWPORTx_ADDR�� �������åȰ�¸�� sys_config.h��ǻ��ꤹ�롣
 *    ���������Υ⥸�塼��ˤ�äơ�XON/XOFF�ե����椬�Ԥ�
 *      ��Ƥ���Τǡ���������TxD��RxD��2�ܤǤ褤
 */

#include <s_services.h>

#ifndef _MACRO_ONLY

/*
 *  ���ꥢ��ݡ��Ȥν�����֥�å�
 */

typedef struct sio_port_initialization_block {
	UW	base;		/* SCI �Υ١������ɥ쥹	*/
	UW	baudrate;	/* �ܡ��졼��		*/	
	IRC	irc;		/* ����ߥ�٥�������� */
	UB	smr_init;	/* SMR ��������		*/
} SIOPINIB;

/*
 *  ���ꥢ��ݡ��Ȥ�����֥�å�
 */

typedef struct sio_port_control_block {
	const SIOPINIB	*inib;		/* ������֥�å�	*/
	VP_INT		exinf;		/* ��ĥ����		*/
	BOOL		openflag;	/* �����ץ�Ѥߥե饰	*/
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ��������֥�å��ؤ��Ѵ��ޥ���
 */

#define INDEX_SIO(sioid)	((UINT)((sioid) - 1))
#define get_siopcb(sioid)	(&(siopcb_table[INDEX_SIO(sioid)]))

/*
 *  ������Хå��롼����μ����ֹ�
 */

#define SIO_ERDY_SND		1u			/* ������ǽ������Хå�			*/
#define SIO_ERDY_RCV		2u			/* �������Υ�����Хå�			*/

/*
 *  SCI �ؿ��λ���
 */

extern void	SCI_initialize (ID sioid);		/* SCI �ν����				*/
extern void	SCI_cls_por(UW base);			/* SCI �Υ�����			*/
extern void	SCI_in_handler(ID sioid);		/* SCI ���ϳ����ߥϥ�ɥ�		*/
extern void	SCI_out_handler(ID sioid);		/* SCI ���ϳ����ߥϥ�ɥ�		*/
extern void	SCI_err_handler(ID sioid);		/* SCI ���ϥ��顼�����ߥϥ�ɥ�		*/
extern void	SCI_ierdy_snd(VP_INT exinf);		/* ���ꥢ�� I/O �����������ǽ������Хå�	*/
extern void	SCI_ierdy_rcv(VP_INT exinf);		/* ���ꥢ�� I/O ����μ������Υ�����Хå�	*/

/*
 *  SCI ��٥�δؿ�
 */

/*
 *  SCI �Υ����ץ�
 */

Inline SIOPCB *
SCI_opn_por (ID sioid)
{
	SCI_initialize(sioid);
	return get_siopcb(sioid);
}

/*
 *  SCI_putchar -- ��������ʸ���ν񤭹���
 */

Inline void
SCI_putchar(SIOPCB *p, UB c)
{
	UW addr = p->inib->base + H8SSR;

	sil_wrb_mem((VP)(p->inib->base + H8TDR), c);
	bitclr((UB *)addr, H8SSR_TDRE_BIT);
}

/*
 *  SCI_wait_putchar -- ľ�ܽ��� (�Ԥ�����)
 */

Inline void
SCI_wait_putchar (int base, char c)
{
	UW addr = base + H8SSR;

	/* TDRE �� 1 �ˤʤ�ޤ��Ԥ� */
	while ((sil_reb_mem((VP)addr) & H8SSR_TDRE) == 0)
		;
	sil_wrb_mem((VP)(base + H8TDR), c);
	bitclr((UB *)addr, H8SSR_TDRE_BIT);
}

/*
 *  SCI_getchar -- ��������ʸ�����ɤ߽Ф�
 */

Inline INT
SCI_getchar(SIOPCB *p)
{
	INT	ch;
	UW	addr = p->inib->base + H8SSR;

	ch = (INT)(UB)sil_reb_mem((VP)(p->inib->base + H8RDR));
	/*  UB���ؤΥ��㥹�Ȥϡ�����ĥ���ɤ�����  */

	bitclr((UB *)addr, H8SSR_RDRF_BIT);
	return ch;
}

/*
 *  SCI_putready -- ������ǽ��
 */

Inline BOOL
SCI_putready(SIOPCB *pcb)
{
	UB ssr = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
	return ((ssr & H8SSR_TDRE) != 0);
}

/*
 *  SCI_getready -- ������ǽ��
 */

Inline BOOL
SCI_getready(SIOPCB *pcb)
{
#ifndef HEW_SIMULATOR
	UB ssr = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
	return ((ssr & H8SSR_RDRF) != 0);
#else /* HEW_SIMULATOR */
	return TRUE;
#endif /* HEW_SIMULATOR */
}

/*
 *  ��������������ؿ�
 */

Inline void
SCI_enable_send(SIOPCB *p)
{
	UW addr = p->inib->base + H8SCR;
	
	bitset((UB *)addr, H8SCR_TIE_BIT);
}

Inline void
SCI_disable_send(SIOPCB *p)
{
	UW addr = p->inib->base + H8SCR;

	bitclr((UB *)addr, H8SCR_TIE_BIT);
}

/*
 *  ��������������ؿ�
 */

Inline void
SCI_enable_recv(SIOPCB *p)
{
	UW addr = p->inib->base + H8SCR;

	bitset((UB *)addr, H8SCR_RIE_BIT);
}

Inline void
SCI_disable_recv(SIOPCB *p)
{
	UW addr = p->inib->base + H8SCR;

	bitclr((UB *)addr, H8SCR_RIE_BIT);
}

/*
 *  SIO �ؿ��λ���
 */

extern void	sio_initialize(void);			/* SCI �ν����				*/
extern void	sio_ena_cbr(SIOPCB *pcb, UINT cbrtn);	/* ���ꥢ�� I/O ����Υ�����Хå�����	*/
extern void	sio_dis_cbr(SIOPCB *pcb, UINT cbrtn);	/* ���ꥢ�� I/O ����Υ�����Хå��ػ�	*/

/*
 *  �ؿ����ߥ�졼�����ޥ���
 */
												/* SCI �����ʸ������			*/
#ifdef HEW_SIMULATOR
extern BOOL hew_io_sim_snd_chr(char c);
#define sio_snd_chr(siopcb, c) hew_io_sim_snd_chr(c)

#else	/* HEW_SIMULATOR */
#define sio_snd_chr(p,c)	SCI_snd_chr(p,c)
#endif	/* HEW_SIMULATOR */
												/* SCI �����ʸ������			*/
#ifdef HEW_SIMULATOR
extern INT hew_io_sim_rcv_chr(void);
#define sio_rcv_chr(siopcb) hew_io_sim_rcv_chr( )

#else	/* HEW_SIMULATOR */
#define sio_rcv_chr(p)		SCI_rcv_chr(p)
#endif	/* HEW_SIMULATOR */

#define sio_ierdy_snd(e)	SCI_ierdy_snd(e)	/* ���ꥢ�� I/O �����������ǽ������Хå�	*/
#define sio_ierdy_rcv(e)	SCI_ierdy_rcv(e)	/* ���ꥢ�� I/O ����μ������Υ�����Хå�	*/

/*
 *  SIO ��٥�δؿ�
 */

/*
 *  sio_opn_por -- �ݡ��ȤΥ����ץ�
 */

Inline SIOPCB *
sio_opn_por(ID sioid, VP_INT exinf)
{
	SIOPCB	*pcb;

	pcb = SCI_opn_por(sioid);
	pcb->exinf    = exinf;
	pcb->openflag = TRUE;
	return pcb;
}

/*
 *  sio_cls_por -- �ݡ��ȤΥ�����
 */

Inline void
sio_cls_por(SIOPCB *pcb)
{
	SCI_cls_por(pcb->inib->base);
	pcb->openflag = FALSE;
}

/*
 *  sio_snd_chr -- ʸ������
 */

#ifndef HEW_SIMULATOR
Inline BOOL
sio_snd_chr(SIOPCB *pcb, INT chr)
{
	if (SCI_putready(pcb)) {
		SCI_putchar(pcb, (UB)chr);
		return TRUE;
	} else {
		return FALSE;
	}
}
#endif	/* HEW_SIMULATOR */

/*
 *  sio_rcv_chr -- ʸ������
 */

#ifndef HEW_SIMULATOR
Inline INT
sio_rcv_chr(SIOPCB *pcb)
{
	if (SCI_getready(pcb)) {
		return SCI_getchar(pcb);
	} else {
		return -1;
	}
}
#endif	/* HEW_SIMULATOR */

#endif	/* of #ifndef _MACRO_ONLY */

#endif /* _HW_SERIAL_H_ */
