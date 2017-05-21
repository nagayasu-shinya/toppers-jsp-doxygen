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
 */

#ifndef	_CQ_D70F3716GC_H_
#define	_CQ_D70F3716GC_H_
/*
 *	�ץ��å��˰�¸���������V850ES/JG2�ѡ�
 */

/*
 * ��¢RAM
 */
#define	IRAM_TOP	0x03FF9000		/* ��¢RAM����Ƭ���ɥ쥹 */
#define IRAM_SIZE	0x6000			/* ��¢RAM���礭�� 24Kbyte */
/*
 * ��¢FlashROM
 */
#define	IROM_TOP	0x0000000		/* ��¢FlashROM����Ƭ���ɥ쥹 */
#define IROM_SIZE	0x40000			/* ��¢FlashROM���礭�� 256Kbyte */


/* 
 * V850ES/JG2��IO�쥸�������
 */
#define PRCMD		(0xFFFFF1FC)	/* Command Register */
#define VSWC		(0xFFFFF06E)	/* System Wait Control Register */
#define OCDM		(0xFFFFF9FC)	/* OnChip Debug Mode Register */
#define WDTM2		(0xFFFFF6D0)	/* Watchdog Debug Mode Register2 */

/*
 * ����å���Ϣ
 */
#define PCC			(0xFFFFF828)	/* Processor Clock Control Register */
#define PLLCTL		(0xFFFFF82C)	/* PLL ����ȥ��롦�쥸���� */

/*
 * LED��Ϣ
 */
/* �ݡ���CT */
#define PCT			(0xFFFFF00A)	/* PCT Register vector */
#define PMCT		(0xFFFFF02A)	/* PCT Mode Register vector */
#define PMCCT		(0xFFFFF04A)	/* PCT Mode Control Register vector */

#define LED_BIT		(0x40)			/* LED */

/*
 * 16bit Interval Timer M
 */
#define TM0CTL0		(0xFFFFF690)
#define TM0CMP0		(0xFFFFF694)

/*
 * UART0��Ϣ
 */
/* �ݡ��� */
#define PMC3		(0xFFFFF446)
#define PFC3		(0xFFFFF466)
#define PFCE3L		(0xFFFFF706)

/* UART0 */
#define UA0CTL0		(0xFFFFFA00)	/* UARTA0 ����쥸����0 */
#define UA0OPT0		(0xFFFFFA03)	/* UARTA0 ���ץ��������쥸����0 */
#define UA0STR		(0xFFFFFA04)	/* UARTA0 ���֥쥸���� */
#define UA0RX		(0xFFFFFA06)	/* UARTA0 �����ǡ����쥸���� */
#define UA0TX		(0xFFFFFA07)	/* UARTA0 �����ǡ����쥸���� */

/* �ܡ��졼�� */
#define UA0CTL1		(0xFFFFFA01)	/* UARTA0 ����쥸����1 */
#define UA0CTL2		(0xFFFFFA02)	/* UARTA0 ����쥸����2 */

/*
 * IntC
 */
#define TM0EQIC0	(0xFFFFF150)	/* TM0EQ0 ���������쥸���� */
#define UA0RIC		(0xFFFFF162)	/* UART0 ������λ���������쥸���� */
#define UA0TIC		(0xFFFFF164)	/* UART0 �������ĳ��������쥸���� */
#define IMR2		(0xFFFFF104)	/* ����ߥޥ����쥸����2 */
#define IMR2H		(0xFFFFF105)	/* ����ߥޥ����쥸����2H */
#define IMR2L		(0xFFFFF104)	/* ����ߥޥ����쥸����2L */
#define ISPR		(0xFFFFF1FA)	/* ���󥵡��ӥ����ץ饤����ƥ����쥸���� */

#endif	/* _CQ_D70F3716GC_H_ */
