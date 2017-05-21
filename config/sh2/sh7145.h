/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002 by Hokkaido Industrial Research Institute, JAPAN
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
 *  @(#) $Id: sh7145.h,v 1.5 2005/07/06 00:45:07 honda Exp $
 */

#ifndef _SH7145_H_
#define _SH7145_H_

#include <sil.h>

/*
 *  ����ߤΥ٥����ֹ����
 */

#define ERI0	128				/*  SCI0    */
#define RXI0	129				/*  SCI0    */
#define TXI0	130				/*  SCI0    */
#define ERI1	132				/*  SCI1    */
#define RXI1	133				/*  SCI1    */
#define TXI1	134				/*  SCI1    */
#define CMI0	144				/*  CMT    */
#define ERI2	168				/*  SCI2    */
#define RXI2	169				/*  SCI2    */
#define TXI2	170				/*  SCI2    */

#ifndef _MACRO_ONLY

/*
 *  SH2�������쥸�������
 */
/* �⥸�塼�륹����Х��쥸���� */
#define MSTCR1	((VH *)0xffff861c)
#define MSTCR2	((VH *)0xffff861e)

#define BCR1	((VH *)0xffff8620)
#define BCR2	((VH *)0xffff8622)
#define WCR1	((VH *)0xffff8624)
#define PACRH	((VH *)0xffff8388)
#define PACRL1	((VH *)0xffff838c)
#define PACRL2	((VH *)0xffff838e)
#define PBCR1	((VH *)0xffff8398)
#define PBCR2	((VH *)0xffff839a)
#define PCCR	((VH *)0xffff839c)
#define PDCRH1	((VH *)0xffff83a8)
#define PDCRH2	((VH *)0xffff83aa)
#define PDCRL1	((VH *)0xffff83ac)
#define PDCRL2	((VH *)0xffff83ae)
#define PECRL1	((VH *)0xffff83b8)
#define PECRL2	((VH *)0xffff83ba)
#define PAIORL	((VH *)0xffff8386)
#define PBIOR	((VH *)0xffff8394)
#define PEIORL	((VH *)0xffff83b4)
#define PEDRL	((VH *)0xffff83b0)

/* ������ͥ���٥�٥�����쥸���� */
#define IPRA    ((VH *)0xffff8348)
#define IPRB    ((VH *)0xffff834a)
#define IPRC    ((VH *)0xffff834c)
#define IPRD    ((VH *)0xffff834e)
#define IPRE    ((VH *)0xffff8350)
#define IPRF    ((VH *)0xffff8352)
#define IPRG    ((VH *)0xffff8354)
#define IPRH    ((VH *)0xffff8356)
#define IPRI    ((VH *)0xffff835c)
#define IPRJ    ((VH *)0xffff835e)

/*
 * �����ߥ���ȥ���ν����
 */
Inline void sh2_init_intcontorller(void)
{
	sil_wrh_mem (IPRA, 0x0000);
	sil_wrh_mem (IPRB, 0x0000);
	sil_wrh_mem (IPRC, 0x0000);
	sil_wrh_mem (IPRD, 0x0000);
	sil_wrh_mem (IPRE, 0x0000);
	sil_wrh_mem (IPRF, 0x0000);
	sil_wrh_mem (IPRG, 0x0000);
	sil_wrh_mem (IPRH, 0x0000);
	sil_wrh_mem (IPRI, 0x0000);
	sil_wrh_mem (IPRJ, 0x0000);
}
#endif /* _MACRO_ONLY */

#endif /* _SH7145_H_ */
