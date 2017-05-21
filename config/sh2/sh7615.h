/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ���
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ���ξ��Τ����줫�����������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ�������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 *
 *  @(#) $Id: sh7615.h,v 1.5 2005/07/06 00:45:07 honda Exp $
 */

#ifndef _SH7615_H_
#define _SH7615_H_

#include <sil.h>

/*
 *  ����ߤΥ٥����ֹ����
 */
#define GII	 4					/*  ��������̿��:General Illegal Instruction  */
#define SII	 6					/*  ����å�����̿��:Slot Illegal Instruction */
#define CAE	 9					/*  CPU���ɥ쥹���顼:CPU Address Error       */
#define DAE	10					/*  DMA���ɥ쥹���顼:DMA Address Error       */

#define NMI	11					/*  NMI         */
#define USBK	12				/*  �桼�����֥졼��    */
#define HUDI	13				/*  �桼�����ǥХå����󥿡��ե�����    */
/* �����٥����ֹ����ꤹ���硢��������̤�������� */
#define IRQ0	64				/*  ����������׵�      */
#define IRQ1	65
#define IRQ2	66
#define IRQ3	67
#define IRL1	64
#define IRL2	65
#define IRL3	65
#define IRL4	66
#define IRL5	66
#define IRL6	67
#define IRL7	67
#define IRL8	68
#define IRL9	68
#define IRL10	69
#define IRL11	69
#define IRL12	70
#define IRL13	70
#define IRL14	71
#define IRL15	71

/* �٥����ֹ��ͳ�˻��ꤹ���硢��������̤�������� */
	/*  DMAC:�����쥯�ȥ��ꥢ����������ȥ���  */
#define DMAC0	72				/*  DMAC0  */
#define DMAC1	73				/*  DMAC1  */

#define ITI	74					/*  WDT:�����å��ɥå�������        */
#define CMI	75					/*  REF:DRAM��ե�å�������        */
#define EINT	76				/*  EINT:EtherC������         */

	/*  FRT:�ե꡼���˥󥰥�����  */
#define ICI	77					/*  FRT  */
#define OCI	78
#define OVI	79

	/*  TPU:�����ޥѥ륹��˥å�  */
#define TGI0A	80				/*  TPU0  */
#define TGI0B	81
#define TGI0C	82
#define TGI0D	83
#define TCI0V	84
#define TGI1A	85				/*  TPU1  */
#define TGI1B	86
#define TCI1V	87
#define TCI1U	88
#define TGI2A	89				/*  TPU2  */
#define TGI2B	90
#define TCI2V	91
#define TCI2U	92

	/*  SCIF:���ꥢ�륳�ߥ�˥�������󥤥󥿡��ե�����  */
#define ERI1	93				/*  SCI1  */
#define RXI1	94
#define BRI1	95
#define TXI1	96
#define ERI2	97				/*  SCI2  */
#define RXI2	98
#define BRI2	99
#define TXI2	100

	/*  SIO:���ꥢ��I/O  */
#define EREI0	101				/*  SCI0  */
#define TERI0	102
#define RDFI0	103
#define TDEI0	104
#define EREI1	105				/*  SCI1  */
#define TERI1	106
#define RDFI1	107
#define TDEI1	108
#define EREI2	109				/*  SCI2  */
#define TERI2	110
#define RDFI2	111
#define TDEI2	112



#ifndef _MACRO_ONLY

/*
 *  SH2�������쥸�������
 */

/* �쥸�����Υ��������ϸ�§32bit�� */
/*
 *   �Х����ơ��ȥ���ȥ���
 */
/* �Х�����ȥ���쥸���� */
#define BCR1    ((VW *)0xffffffe0)
#define BCR2    ((VW *)0xffffffe4)
#define BCR3    ((VW *)0xfffffffc)
/* �������ȥ���ȥ���쥸���� */
#define WCR1    ((VW *)0xffffffe8)
#define WCR2    ((VW *)0xffffffc0)
#define WCR3    ((VW *)0xffffffc4)
/* ���̥��ꥳ��ȥ���쥸���� */
#define MCR     ((VW *)0xffffffec)
/* ��ե�å��奿���ޥ���ȥ���/���ơ������쥸���� */
#define RTCSR   ((VW *)0xfffffff0)
/* ��ե�å��奿���ޥ����� */
#define RTCNT   ((VW *)0xfffffff4)
/* ��ե�å��奿���ॳ�󥹥���ȥ쥸���� */
#define RTCOR   ((VW *)0xfffffff8)
/*-----����ȯ����ϩ-----*/
#define FMR     ((VB *)0xfffffe90)

/*
 * �ԥ�ե��󥯥���󥳥�ȥ���
 */
#define PACR    ((VH *)0xfffffc80)	/*  �ݡ���A ����ȥ���쥸����  */
#define PAIOR   ((VH *)0xfffffc82)	/*  �ݡ���A I/O�쥸����       */
#define PBCR    ((VH *)0xfffffc88)	/*  �ݡ���B ����ȥ���쥸����  */
#define PBIOR   ((VH *)0xfffffc8a)	/*  �ݡ���B I/O�쥸����       */
#define PBCR2   ((VH *)0xfffffc8e)	/*  �ݡ���B ����ȥ���쥸����2 */
#define PADR    ((VH *)0xfffffc84)	/*  �ݡ���A �ǡ����쥸����        */
#define PBDR    ((VH *)0xfffffc8c)	/*  �ݡ���B �ǡ����쥸����        */

/* ������ͥ���٥�٥�����쥸���� */
#define IPRA    ((VH *)0xfffffee2)
#define IPRB    ((VH *)0xfffffe60)
#define IPRC    ((VH *)0xfffffee6)
#define IPRD    ((VH *)0xfffffe40)
#define IPRE    ((VH *)0xfffffec0)
/* �٥����ֹ�����쥸���� */
#define VCRA    ((VH *)0xfffffe62)
#define VCRB    ((VH *)0xfffffe64)
#define VCRC    ((VH *)0xfffffe66)
#define VCRD    ((VH *)0xfffffe68)
#define VCRE    ((VH *)0xfffffe42)
#define VCRF    ((VH *)0xfffffe44)
#define VCRG    ((VH *)0xfffffe46)
#define VCRH    ((VH *)0xfffffe48)
#define VCRI    ((VH *)0xfffffe4a)
#define VCRJ    ((VH *)0xfffffe4c)
#define VCRK    ((VH *)0xfffffe4e)
#define VCRL    ((VH *)0xfffffe50)
#define VCRM    ((VH *)0xfffffe52)
#define VCRN    ((VH *)0xfffffe54)
#define VCRO    ((VH *)0xfffffe56)
#define VCRP    ((VH *)0xfffffec2)
#define VCRQ    ((VH *)0xfffffec4)
#define VCRR    ((VH *)0xfffffec6)
#define VCRS    ((VH *)0xfffffec8)
#define VCRT    ((VH *)0xfffffeca)
#define VCRU    ((VH *)0xfffffecc)
#define VCRWDT  ((VH *)0xfffffee4)
#define DMA_VCRDMA0     ((VW *)0xffffffa0)
#define DMA_VCRDMA1     ((VW *)0xffffffa8)
/* �����ߥ���ȥ���쥸���� */
#define ICR     ((VH *)0xfffffee0)
/* �����ߥ���ȥ���/���ơ������쥸���� */
#define IRQCSR  ((VH *)0xfffffee8)

/*
 * �����ߥ���ȥ���ν����
 */
Inline void
sh2_init_intcontorller (void)
{
	sil_wrh_mem (IPRA, 0x0000);
	sil_wrh_mem (IPRB, 0x0000);
	sil_wrh_mem (IPRC, 0x0000);
	sil_wrh_mem (IPRD, 0x0000);
	sil_wrh_mem (IPRE, 0x0000);
}

#endif /* _MACRO_ONLY */

#endif /* _SH7615_H_ */
