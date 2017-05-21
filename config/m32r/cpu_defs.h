/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006 by Monami Software Limited Partnership, JAPAN	
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ� *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: cpu_defs.h,v 1.8 2007/05/30 03:56:47 honda Exp $
 */

/*
 *	�ץ��å��˰�¸���������M32R�ѡ�
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define M32R

/* �㳰�װ��ֹ� */
#define NUM_EXCEPTION	20

#define EXC_RESET	0
#define EXC_SBI		1
#define EXC_RIE		2
#define EXC_AE		3
#define EXC_TRAP00	4
#define EXC_TRAP01	5
#define EXC_TRAP02	6
#define EXC_TRAP03	7
#define EXC_TRAP04	8
#define EXC_TRAP05	9
#define EXC_TRAP06	10
#define EXC_TRAP07	11
#define EXC_TRAP08	12
#define EXC_TRAP09	13
#define EXC_TRAP10	14
#define EXC_TRAP11	15
#define EXC_TRAP12	16
#define EXC_TRAP13	17
#define EXC_TRAP14	18
#define EXC_TRAP15	19

/* ������װ��ֹ� */
#define INT_INT0	1
#define INT_INT1	2
#define INT_INT2	3
#define INT_INT3	4
#define INT_INT4	5
#define INT_INT5	6
#define INT_INT6	7
#define INT_MFT0	16
#define INT_MFT1	17
#define INT_MFT2	18
#define INT_MFT3	19
#define INT_MFT4	20
#define INT_MFT5	21
#define INT_DMA0	32
#define INT_SIO0RCV	48
#define INT_SIO0XMT	49
#define INT_SIO1RCV	50
#define INT_SIO1XMT	51
#define INT_SIO2RCV	52
#define INT_SIO2XMT	53
#define INT_SIO3RCV	54
#define INT_SIO3XMT	55
#define INT_SIO4RCV	56
#define INT_SIO4XMT	57


#ifndef _MACRO_ONLY

typedef unsigned int   INHNO;		/* ����ߥϥ�ɥ��ֹ�  */
typedef unsigned char  IPR;			/* �����ͥ����        */
typedef unsigned int   EXCNO;		/* CPU�㳰�ϥ�ɥ��ֹ� */

/* �����ͥ뵯ư���Υ�å����� */
#define COPYRIGHT_CPU \
"Copyright (C) 2006 by Monami Software Limited Partnership, JAPAN\n" \
"Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory\n" \
"            Graduate School of Information Science, Nagoya Univ., JAPAN\n"

#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
