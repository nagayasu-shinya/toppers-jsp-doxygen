/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007-2010 by Monami Software Limited Partnership, JAPAN.
 * 
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
 * �������åȰ�¸���ꥢ��I/O�⥸�塼���D70F3716GC ��¢��Ʊ�����ꥢ��ch0�ѡ�
 *   �ǡ����ե����ޥåȤ�8bit data, non-parity, 1stop-bit����
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>

/*
 *  ���ꥢ��ݡ��Ȥν�����֥�å�
 */

typedef struct sio_port_initialization_block {
} SIOPINIB;

/*
 *  ���ꥢ��ݡ��Ȥ�����֥�å�
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*inib;		/* ������֥�å�	*/
	VP_INT		exinf;		/* ��ĥ����		*/
	BOOL		openflag;	/* �����ץ�Ѥߥե饰	*/
	int			port_id;	/* �ݡ����ֹ�(0��) */
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
 *  ���ꥢ��ݡ��ȤΥϡ��ɥ�������¸��������
 */

#define SERIAL_PORT				(CONSOLE_PORTID-1)		/* �����ƥ�Υݡ����ֹ� */
#define SERIAL_INT_PRIORITY		3	/* ������ͥ���� */
#define SERIAL_CLKDIV			0x01	/* clk = fxx/2     */
#define SERIAL_COMPAREVALUE		0x82	/* 38400bps */
//#define SERIAL_CLKDIV			0x00	/* clk = fxx/1     */
//#define SERIAL_COMPAREVALUE		0x57	/* 115200bps */


#define FLG_RECEIVED 1

extern volatile unsigned int _serial_flag;


/*
 *  ���ꥢ��I/O�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define INHNO_SERIAL_IN		(0x35)
#define INHNO_SERIAL_OUT	(0x36)

/*
 *  ���٥�ݡ��Ⱦ�������֥�å��ν����
 */

#define NUM_PORT	1	/* ���ݡ��Ȥ��륷�ꥢ��ݡ��Ȥο� */

/*
 *  ���ꥢ��I/O�ݡ��Ȥν����
 */
Inline BOOL
hw_port_initialize(int port_id)
{
#ifndef DEBUGGER
	while( (sil_reb_mem((VP)UA0STR) & 0x80) ) ;

	/* ��Ʊ�����ꥢ���̿�ϩ�ν���� */

	/* �ݡ��Ȥ򳫤��� */
	if (port_id == 0) {
		sil_wrh_mem((VP)PMC3, sil_reh_mem((VP)PMC3) | 0x0300);
		sil_wrh_mem((VP)PFC3, sil_reh_mem((VP)PFC3) & ~0x0300);
	} else {

	}

	/* �ܡ��졼��ȯ����ν���� */
	sil_wrb_mem((VP)UA0CTL1, SERIAL_CLKDIV);
	sil_wrb_mem((VP)UA0CTL2, SERIAL_COMPAREVALUE);

	sil_wrb_mem((VP)UA0CTL0, 0x80);	/* enable ASIO */

	__asm("nop; nop");

	/* �ѥ�ƥ��ʤ���8�ӥåȡ����ȥå�1�ӥåȡ�LSB�ե������� */
	sil_wrb_mem((VP)UA0CTL0, sil_reb_mem((VP)UA0CTL0) | 0x12);

	__asm("nop; nop");

	sil_wrb_mem((VP)UA0CTL0, sil_reb_mem((VP)UA0CTL0) | 0x60);	/* Tx, Rx enable */

	/* ��������� */
	sil_wrb_mem((VP)UA0RIC, SERIAL_INT_PRIORITY);
	sil_wrb_mem((VP)UA0TIC, SERIAL_INT_PRIORITY);
#endif
	return(FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥν�λ
 */
Inline void
hw_port_terminate(int port_id)
{
	sil_wrb_mem((VP)UA0RIC, sil_reb_mem((VP)UA0RIC) | 0x40);
	sil_wrb_mem((VP)UA0TIC, sil_reb_mem((VP)UA0TIC) | 0x40);

	sil_wrb_mem((VP)UA0CTL0, 0x10);	/* Tx, Rx disable */
}

/*
 *  ���ꥢ��ݡ��ȳ���ߥ����ӥ��롼������������ȡ�
 */
extern void	serial_handler_in(int portid);
extern void	serial_handler_out(int portid);

/*
 *  ʸ���������������
 */
Inline BOOL
hw_port_getready(int port_id)
{
	return ((_serial_flag & FLG_RECEIVED) != 0);
}


/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
hw_port_putready(int port_id)
{
	return ((sil_reb_mem((VP)UA0STR) & 0x80) == 0);
}


/*
 *  ��������ʸ���μ��Ф�
 */
Inline unsigned char
hw_port_getchar(int port_id)
{
	_serial_flag &= ~FLG_RECEIVED;
	return sil_reb_mem((VP)UA0RX);
}

/*
 *  ��������ʸ���ν񤭹���
 */
Inline void
hw_port_putchar(int port_id, unsigned char c)
{
	sil_wrb_mem((VP)UA0TX, c);
}

/*
 *  ��������ʸ���ν񤭹��ߡ�������ǽ�ˤʤ�ޤ��Ԥġ�
 */
Inline void
hw_port_wait_putchar(int port_id, unsigned char c)
{
	while( !hw_port_putready(port_id) ) ;
	hw_port_putchar(port_id, c);
}

/*
 *  ��������ؿ�
 */
Inline void
hw_port_sendstart(int port_id)
{
}

Inline void
hw_port_sendstop(int port_id)
{
}

extern void	sio_ierdy_rcv(VP_INT exinf);
extern void	sio_ierdy_snd(VP_INT exinf);

Inline void
hw_port_handler_in(int port_id)
{
	UB tmp;

	if((sil_reb_mem((VP)UA0STR) & 0x07) == 0) {
		_serial_flag |= FLG_RECEIVED;
		sio_ierdy_rcv(siopcb_table[port_id].exinf);	
	} else {
		/* ���顼������Хǡ������˴� */
		tmp = sil_reb_mem((VP)UA0RX);
	}
}

Inline void
hw_port_handler_out(int port_id)
{
	if(hw_port_putready(port_id)) {
		sio_ierdy_snd(siopcb_table[port_id].exinf);
	}
}

/***********************************************************************************/

/*
 *  sio_initialize -- ���ꥢ��ݡ��ȥɥ饤�Фν����
 */
Inline void
sio_initialize (void)
{
	int ix;

	/* SIO �����֥�å��ν���� */
	for (ix = TNUM_PORT; ix -- > 0; ) {
		siopcb_table[ix].openflag = FALSE;
	}
}

/*
 *  sio_opn_por -- �ݡ��ȤΥ����ץ�
 */
Inline SIOPCB *
sio_opn_por(ID sioid, VP_INT exinf)
{
	SIOPCB	*pcb;

	pcb = get_siopcb(sioid);
	pcb->inib     = NULL;
	pcb->exinf    = exinf;
	pcb->openflag = TRUE;
	pcb->port_id  = sioid-1;
	hw_port_initialize(pcb->port_id);
	return pcb;
}

/*
 *  sio_snd_chr -- ʸ������
 */
Inline BOOL
sio_snd_chr(SIOPCB *pcb, INT chr)
{
#if 0
	if (hw_port_putready(pcb->port_id)) {
		hw_port_putchar(pcb->port_id, (UB)chr);
		return TRUE;
	} else {
		return FALSE;
	}
#else
	/* ����ϡ����Τ褦�ˤ���٤������� */
	/* syslog���Ϥ��ߤޤäƤ��ޤ����ᡢ */
	/* ������� */
	while(!hw_port_putready(pcb->port_id)) ;
	hw_port_putchar(pcb->port_id, (UB)chr);
	return TRUE;
#endif
}

/*
 *  sio_rcv_chr -- ʸ������
 */
Inline INT
sio_rcv_chr(SIOPCB *pcb)
{
	if (hw_port_getready(pcb->port_id))
		return hw_port_getchar(pcb->port_id);
	else
		return -1;
}

/*
 *  sio_ena_cbr -- ���ꥢ�� I/O ����Υ�����Хå��ε���
 */
Inline void
sio_ena_cbr(SIOPCB *pcb, UINT cbrtn)
{
}

/*
 *  sio_dis_cbr -- ���ꥢ�� I/O ����Υ�����Хå��ζػ�
 */
Inline void
sio_dis_cbr(SIOPCB *pcb, UINT cbrtn)
{
}

/*
 *  sio_cls_por -- �ݡ��ȤΥ�����
 */
Inline void
sio_cls_por(SIOPCB *pcb)
{
	sio_dis_cbr(pcb, SIO_ERDY_SND);
	sio_dis_cbr(pcb, SIO_ERDY_RCV);
	pcb->openflag = FALSE;
}

Inline void
sio_in_handler(void)
{
	hw_port_handler_in(0);
}

Inline void
sio_out_handler(void)
{
	hw_port_handler_out(0);
}


#endif /* _HW_SERIAL_H_ */
