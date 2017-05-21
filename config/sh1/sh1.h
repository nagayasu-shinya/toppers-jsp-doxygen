/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 * 
 *  @(#) $Id: sh1.h,v 1.8 2004/10/07 17:13:56 honda Exp $
 */

#ifndef _SH1_H_
#define _SH1_H_

/*
 *  ����ߤΥ٥����ֹ����
 */
#define GII	 4	/*  ��������̿��:General Illegal Instruction  */
#define SII	 6	/*  ����å�����̿��:Slot Illegal Instruction */
#define CAE	 9	/*  CPU���ɥ쥹���顼:CPU Address Error       */
#define DAE	10	/*  DMA���ɥ쥹���顼:DMA Address Error       */

#define NMI	11	/*  NMI  		*/
#define USBK	12	/*  �桼�����֥졼��  	*/
#define IRQ0	64	/*  ����������׵�  	*/
#define IRQ1	65
#define IRQ2	66
#define IRQ3	67
#define IRQ4	68
#define IRQ5	69
#define IRQ6	70
#define IRQ7	71

	/*  DMAC:�����쥯�ȥ��ꥢ����������ȥ���  */
#define DEI0	72	/*  DMAC0  */
#define DEI1	74	/*  DMAC1  */
#define DEI2	76	/*  DMAC2  */
#define DEI3	78	/*  DMAC3  */

	/*  ITU:����ƥ��졼�ƥåɥ����ޥѥ륹��˥å�  */
#define IMIA0	80	/*  ITU0  */
#define IMIB0	81
#define OVI0	82
#define IMIA1	84	/*  ITU1  */
#define IMIB1	85
#define OVI1	86
#define IMIA2	88	/*  ITU2  */
#define IMIB2	89
#define OVI2	90
#define IMIA3	92	/*  ITU3  */
#define IMIB3	93
#define OVI3	94
#define IMIA4	96	/*  ITU4  */
#define IMIB4	97
#define OVI4	98

	/*  SCI:���ꥢ�륳�ߥ�˥�������󥤥󥿡��ե�����  */
#define ERI0	100	/*  SCI0  */
#define RXI0	101
#define TXI0	102
#define TEI0	103
#define ERI1	104	/*  SCI1  */
#define RXI1	105
#define TXI1	106
#define TEI1	107

#define PEI	108	/*  PRT:�Х�����ȥ���Υѥ�ƥ�����  */
#define ADI	109	/*  A/D����С���  			*/
#define ITI	112	/*  WDT:�����å��ɥå�������  		*/
#define CMI	113	/*  REF:DRAM��ե�å�������  		*/



#ifndef _MACRO_ONLY

/*
 *  SH1�������쥸�������
 *  
 *  ������ѥ���η������å���ǽ��ͭ���ˤ��뤿�ᡢ�ݥ��󥿷��ˤ�
 *  ��VP�ǤϤʤ���VB *,VH *, VW *���Ѥ��Ƥ��롣
 */

/*
 * �ԥ�ե��󥯥���󥳥�ȥ��� �ʥ�������2�Х��ȡ�
 */
#define	PAIOR	((VH *)0x5ffffc4)	/*  �ݡ���A I/O�쥸����  	  */
#define	PACR1	((VH *)0x5ffffc8)	/*  �ݡ���A ����ȥ���쥸����1 */
#define	PACR2	((VH *)0x5ffffca)	/*  �ݡ���A ����ȥ���쥸����2 */
#define	PBIOR	((VH *)0x5ffffc6)	/*  �ݡ���B I/O�쥸����  	  */
#define	PBCR1	((VH *)0x5ffffcc)	/*  �ݡ���B ����ȥ���쥸����1 */
#define	PBCR2	((VH *)0x5ffffce)	/*  �ݡ���B ����ȥ���쥸����2 */
#define	PADR	((VH *)0x5ffffc0)	/*  �ݡ���A �ǡ����쥸����  	  */

#define PBCR1_TD0_RD0_MASK 	~0xfu	/*  TxD0,RxD0ü�������ѥޥ���	*/
#define PBCR1_TD0 		 0x8u	/*  TxD0ü�������ѥޥ���  	*/
#define PBCR1_RD0 		 0x2u	/*  RxD0ü�������ѥޥ���  	*/


/*
 * �����ߥ���ȥ���쥸����
 */
#define	IPRA	((VH *)0x5ffff84)	/*  ����ߥ�٥�����쥸����  */
#define	IPRB	((VH *)0x5ffff86)	/*  �ʥ�������2�Х��ȡ�  */
#define	IPRC	((VH *)0x5ffff88)
#define	IPRD	((VH *)0x5ffff8a)
#define	IPRE	((VH *)0x5ffff8c)
#define	ICR	((VH *)0x5ffff8e)	/*  ����ߥ���ȥ���쥸����  */
					/*  �ʥ�������2�Х��ȡ�  */

#endif /* _MACRO_ONLY */

#endif /* _SH1_H_ */
