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
 *  @(#) $Id: hw_serial.h,v 1.2 2007/05/28 02:03:55 honda Exp $
 */

/*
 *  ���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�M32102��¢��Ʊ�����ꥢ���ѡ�
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <sil.h>
#include <sys_config.h>

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND    1u              /* ������ǽ������Хå� */
#define SIO_ERDY_RCV    2u              /* �������Υ�����Хå� */

/*
 *  ���ꥢ��I/O�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define INHNO_SERIAL_IN		(48 + ((CONSOLE_PORTID-1)*2))
#define INHNO_SERIAL_OUT	(49 + ((CONSOLE_PORTID-1)*2))

#define SIO_TYP(x)			( (x) & 0x000000ff )
#define SIO_TYP_M32RUART	0x00000001

#define SIO_STS(x)			( (x) & 0xffff0000 )
#define SIO_STS_SENDING		0x80000000

typedef struct
{
	int		flags;
	int		port;
	VP_INT	exinf;
} SIOPCB;

//extern SIOPCB siopcb_table[TNUM_PORT];

extern void sio_handler_in(void);
extern void sio_handler_out(void);

/*
 *  ���ꥢ��ݡ��Ȥν����
 */
extern void sio_initialize(void);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB * sio_opn_por(ID siopid, VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void sio_cls_por(SIOPCB *siopcb);

/*
 *  ��ʸ������
 */
Inline BOOL
sio_snd_chr(SIOPCB * siopcb, INT chr)
{
	if((siopcb->flags & SIO_STS_SENDING) != 0)
		return FALSE;

	switch(SIO_TYP(siopcb->flags))
	{
	case SIO_TYP_M32RUART:	
		if((sil_reb_mem((void *)(SIOSTS(siopcb->port)+3)) & 0x3) != 0)
		{
			siopcb->flags |= SIO_STS_SENDING;
			sil_wrb_mem((void *)(SIOTXB(siopcb->port)+3), (char)chr);
		} else
			return FALSE;
		break;
	default:
		return FALSE;
	}
	return TRUE;
}


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

#endif /* _HW_SERIAL_H_ */
