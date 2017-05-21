/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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
 */

#ifndef _MINET_H8S_2339F_H_
#define _MINET_H8S_2339F_H_

/*
 *  MiSPO MiNET-H8S/2339F�����
 */

#define MINET_H8S_2339F

/*
 *  SYSCR�ν����
 *  ����INTM1=1,INTM0=0�����������⡼�ɣ�
 *  ����NMIEG=0��NMI���Ϥ�Ω���ꥨ�å��ǳ������׵��ȯ��
 *  ����IRQPAS��IRQ����ü�ҥ��쥯��
 *  ����RAME=1����¢RAMͭ��
 */
#define	SYS_SYSCR	(INT_MODE2 | RAME)

/*
 *  CPU ����å�
 */
#define CPU_CLOCK	24576			/* kHzñ�� ��24.576MHz��*/

/*
 *  �����ޤ˶��뤵��륯��å� (��������å���/4�ǥ������)
 */
#define TIMER_CLOCK	((CPU_CLOCK)/4)		/* kHzñ�� */

/*
 *  ���ꥢ��ݡ��Ȥ�BRR�쥸�����ͤ����
 *    �׻������Ѥ�����ˡ�⤢�뤬������Ƚ�꤬ɬ�פʤΤǡ�
 *�������̤˥ޥ���������Ƥ��롣
 *����BRR_RATE�ޥ���ϥޥ˥奢����N���б����롣
 *�����������n=0�Ǥ��롣
 *����BAUD_RATE��user_config.h��������롣
 */
#if CPU_CLOCK != 24576
#error CPU_CLOCK is invalid value.
#else /*  CPU_CLOCK != 24576  */

/*  SCI0  */
#if BAUD_RATE0 == 9600		/* �ӥåȥ졼�ȡ� 9600[bps] */
	#define BRR0_RATE	79
#elif BAUD_RATE0 == 19200	/* �ӥåȥ졼�ȡ�19200[bps] */
	#define BRR0_RATE	39
#elif BAUD_RATE0 == 38400	/* �ӥåȥ졼�ȡ�38400[bps] */
	#define BRR0_RATE	19
#endif /* BAUD_RATE0 == 9600  */

/*  SCI1  */
#if BAUD_RATE1 == 9600		/* �ӥåȥ졼�ȡ� 9600[bps] */
	#define BRR1_RATE	79
#elif BAUD_RATE1 == 19200	/* �ӥåȥ졼�ȡ�19200[bps] */
	#define BRR1_RATE	39
#elif BAUD_RATE1 == 38400	/* �ӥåȥ졼�ȡ�38400[bps] */
	#define BRR1_RATE	19
#endif /* BAUD_RATE1 == 9600  */

/*  SCI1  */
#if BAUD_RATE2 == 9600		/* �ӥåȥ졼�ȡ� 9600[bps] */
	#define BRR2_RATE	79
#elif BAUD_RATE2 == 19200	/* �ӥåȥ졼�ȡ�19200[bps] */
	#define BRR2_RATE	39
#elif BAUD_RATE2 == 38400	/* �ӥåȥ졼�ȡ�38400[bps] */
	#define BRR2_RATE	19
#endif /* BAUD_RATE1 == 9600  */

/*
 *  SCR�쥸������CKS0,CKS1�ӥå�
 *�����ܡ��졼�ȷ׻�����n=0���б�
 *�����ܡ��졼������ͤ��ۤʤ��礬����Τ����
 */
#define SCR0_CKS		0	/*  SCI0  */
#define SCR1_CKS		0	/*  SCI1  */
#define SCR2_CKS		0	/*  SCI2  */

#endif /* CPU_CLOCK != 24576 */

/*
 *  DDR�쥸�����ν���ͤ����
 */
#define P1DDR0		0xf0
#define P2DDR0		DUMMY
#define P3DDR0		DUMMY
/*  �ݡ��ȣ���DDR���ʤ����ᡢ����  */
#define P5DDR0		DUMMY
#define P6DDR0		0xc3
#define P7DDR0		DUMMY
#define P8DDR0		DUMMY
#define P9DDR0		0xe0
#define PADDR0		0xff
#define PBDDR0		0xff
#define PCDDR0		0xff
#define PDDDR0		DUMMY
#define PEDDR0		DUMMY
#define PFDDR0		0xff
#define PGDDR0		0x1f




#endif /* _MINET_H8S_2339F_H_ */
