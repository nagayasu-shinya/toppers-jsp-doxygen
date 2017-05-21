/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2002 by Monami software, Limited Partners.
 *  Copyright (C) 2002 by MURANAKA Masaki
 *  Copyright (C) 2008-     by Monami Software Limited Partnership, JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
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
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: sys_config.h,v 1.1 2004/07/21 02:49:37 monaka Exp $
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���PC/AT�ѡ�
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include <sys_rename.h>

/*
 *  ��ư��å������Υ������åȥ����ƥ�̾
 */
#define	TARGET_NAME	"IA-32(PC/AT)"

/*
 *  vxget_tim �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#if 0
#define	SUPPORT_VXGET_TIM
#endif

/*
 * �󥿥�������ƥ������ѤΥ����å��ν����
 */
#define	STACKTOP	$(stack + STACKSIZE)
#define	STACKSIZE	8192

/*
 *  ���ꥢ��ݡ��ȿ������
 */
#define TNUM_PORT	2	/* ���ݡ��Ȥ��륷�ꥢ��ݡ��Ȥο� */
#define	TNUM_SIOP	2	/* ���ݡ��Ȥ��륷�ꥢ��I/O�ݡ��Ȥο� */

/*
 *  ���ꥢ��ݡ����ֹ�˴ؤ������
 */
#ifndef LOGTASK_PORTID
#define	LOGTASK_PORTID	1	/* �����ƥ�����Ѥ��륷�ꥢ��ݡ����ֹ� */
#endif


#define PIT_INHNO 0x20

#define PCAT_COM1_INHNO 0x24
#define PCAT_COM2_INHNO 0x23
#define PCAT_COM1_BASE (0x03F8)
#define PCAT_COM2_BASE (0x02F8)

#define	IRQ0_VECTOR	0x20
#define	IRQ8_VECTOR	0x28
#define	IRQ_VECTOR(x)	(IRQ0_VECTOR + (x))

#define TO_INTNO(a) ((a) - 0x20)

#ifndef _MACRO_ONLY

/*
 *  �������åȥ����ƥ��¸�ν����
 */
extern void	sys_initialize(void);

/*
 *  �������åȥ����ƥ�ν�λ
 */
extern void	sys_exit(void);

/*
 *  �������åȥ����ƥ��ʸ������
 */
extern void	sys_putc(char c);

/*
 *  ����ߥϥ�ɥ������
 */

/*
 *  ����ߥϥ�ɥ�ν�����������sys_support.S��
 */
extern void interrupt0(void);
extern void interrupt1(void);
extern void interrupt2(void);
extern void interrupt3(void);
extern void interrupt4(void);
extern void interrupt5(void);
extern void interrupt6(void);
extern void interrupt7(void);
extern void interrupt8(void);
extern void interrupt9(void);
extern void interrupt10(void);
extern void interrupt11(void);
extern void interrupt12(void);
extern void interrupt13(void);
extern void interrupt14(void);
extern void interrupt15(void);

/*
 *  ����ߥϥ�ɥ�Υơ��֥��sys_config.c��
 *
 *  ����ߥϥ�ɥ�ϰ�ö���Υơ��֥����Ͽ���졢�̤��Ѱդ��줿����������
 *  ��ƤӽФ���
 */
extern FP int_table[0x10];

/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ� inhno �γ���ߥϥ�ɥ�ε�ư���Ϥ� inthdr �����ꤹ�롥
 */
extern void define_inh(INHNO inhno, FP inthdr);

/*
 *  ����ߥϥ�ɥ�ν���������
 */

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 */

#define INTHDR_ENTRY(inthdr) extern void inthdr(void)

#define INT_ENTRY(inthdr) inthdr

#endif /* _MACRO_ONLY */
#endif /* _SYS_CONFIG_H_ */
