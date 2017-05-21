/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: hw_serial.h,v 1.9 2003/12/15 07:19:22 takayuki Exp $
 */



/*
 *  TOPPERS/JSP for Windows - ���ꥢ�륨�ߥ�졼��
 */

#ifndef __HW_SERIAL_H
#define __HW_SERIAL_H

#include <s_services.h>

/*
 *  ������Хå��롼����μ����ֹ�
 *  OPB_UARTLITE �ϡ�����������ߤ�ʬ����Ƥ��ʤ����ᡤ��̣�Ϥʤ���
 */
#define SIO_ERDY_SND    1u              /* ������ǽ������Хå� */
#define SIO_ERDY_RCV    2u              /* �������Υ�����Хå� */

	/* �ǥХ����򳫤�¦������ */
#define SIO_MOD_MASK		0x80000000
#define SIO_MOD(x)			((x) & SIO_MOD_MASK)
#define SIO_MOD_SERVER		0x80000000
#define SIO_MOD_CLIENT		0x00000000

	/* �ǥХ����μ��� */
#define SIO_TYP_MASK		0x000000ff
#define SIO_TYP(x)			((x) & SIO_TYP_MASK)
#define SIO_TYP_CONSOLE		0x00000001			/* ������ɥ����󥽡���  */
#define SIO_TYP_TTY			0x00000002			/* Windows�Υ��󥽡��� */
#define SIO_TYP_SCRBUF		0x00000003			/* �����꡼��Хåե�    */
#define SIO_TYP_RAWSIO		0x00000004			/* ���ꥢ��              */

	/* �ǥХ����ξ��� */
#define SIO_STA_MASK		0x0fff0000
#define SIO_STA(x)			((x) & SIO_STA_MASK)
#define SIO_STA_OPEN		0x00010000
#define SIO_STA_INTRCV		0x00020000
#define SIO_STA_INTSND		0x00040000

#define INHNO_SERIAL	3

#define TNUM_PORT		1

#ifndef _MACRO_ONLY

typedef struct serial_port_descriptor
{
	int					Flag;
	HANDLE				Handle;
	volatile int		ReceiveBuffer;
	void *				versatile;
	VP_INT              exinf;
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void	sio_initialize(void);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB * sio_opn_por(ID siopid, VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void	sio_cls_por(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern BOOL	sio_snd_chr(SIOPCB *siopcb, INT chr);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern INT	sio_rcv_chr(SIOPCB *siopcb);

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
extern void	sio_isr(void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void sio_ena_cbr(SIOPCB * siopcb, UINT cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void sio_dis_cbr(SIOPCB * siopcb, UINT cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ��������λ������Хå�
 */
extern void sio_ierdy_snd(VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ��������λ������Хå�
 */
extern void sio_ierdy_rcv(VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ���������Υ�����Хå�
 */
extern void	sio_ercv_chr(ID siopid, INT chr);

/*
 *  ���ꥢ��I/O�ݡ��ȳ���ߥϥ�ɥ�
 */
extern void	sio_handler(void);

#endif

#endif

