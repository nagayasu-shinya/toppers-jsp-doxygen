/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2003-2004 by CHUO ELECTRIC WORKS Co.,LTD. JAPAN
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
 *   SH1��¢���ꥢ�륳�ߥ�˥�������󥤥󥿥ե�����SCI�� �ʰץɥ饤��
 *
 *��������SCI0/1���ݡ���
 *
 *��������sh1sci.{c,h}��hw_serial.h��ʬ��δ��
 *��������������sh1sci.{c,h}�����ꥢ��ǥХ����˰�¸������ʬ�Τߵ���
 *��������������hw_serial.h�����ꥢ��ǥХ����ʳ��˵�����������
 *�������� ������������������hw_serial.h�˵��Ҥ���
 *��������������������������������ߥ���ȥ����¸�ʤ�
 */

#ifndef _SH1SCI2_H_
#define _SH1SCI2_H_

#include <t_services.h>
#include <sh1_sil.h>

/*
 *  ���ꥢ��ݡ��ȥ��󥿡��ե�����
 */
#define	PORT1			1
#define	PORT2			2

#define RS232C_INTERFACE	0	/* RS232C I/F�ξ�硢������������ */
#define RS485_INTERFACE		1	/* RS485 I/F�ξ�硢������������ */

/*
 *  ���ꥢ��ݡ��Ȥν�����֥�å�
 */
typedef struct sio_port_initialization_block {
	UW 	base;		/* SCI �Υ١������ɥ쥹		*/
	UW	baudrate;	/* �ܡ��쥤��			*/	
	VH  	*ipr;		/* �����ߥ���ȥ��饢�ɥ쥹 */
	UH	shift;		/* �����ߥ���ȥ��饷�ե�	*/
	UB	smr_init;	/* SMR ��������			*/
	UINT	delay;		/* �ܡ��졼�Ȥ�������Ԥ�	*/
	UB	rs485if;	/* RS232C | RS485		*/
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 *  ��2ch�˳�ĥ
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*inib;		/* ������ѤΥǡ��� 	*/
	VP_INT		exinf;		/* ��ĥ���� 		*/
	BOOL		openflag;	/* �����ץ�Ѥߥե饰 	*/
} SIOPCB;

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND	1u		/* ������ǽ������Хå� */
#define SIO_ERDY_RCV	2u		/* �������Υ�����Хå� */

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void	sh1sci_initialize(void);

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
extern BOOL	sh1sci_openflag(ID siopid);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB	*sh1sci_opn_por(ID siopid, VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void	sh1sci_cls_por(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern BOOL	sh1sci_snd_chr(SIOPCB *siopcb, char c);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern INT	sh1sci_rcv_chr(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void	sh1sci_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void	sh1sci_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
extern void	sh1sci_isr_in(void);
extern void	sh1sci_isr_out(void);

/*
 *  SIO�μ������顼����ߥ����ӥ��롼����
 */
extern void	sh1sci_isr_error(void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void	sh1sci_ierdy_snd(VP_INT exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void	sh1sci_ierdy_rcv(VP_INT exinf);



#endif /* _SH1SCI2_H_ */
