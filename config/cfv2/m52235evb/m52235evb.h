/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
#   Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
 *  Copyright (C) 2008 by Takahisa Yokota
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
 *  @(#) $Id: m52235evb.h,v 1.2 2003/06/04 01:52:23 hiro Exp $
 */

/*
 *  �ե꡼�������롦���ߥ�������� M52235EVB
 *  �ܡ��ɸ�ͭ�����
 */

#ifndef _M52235EVB_H_
#define _M52235EVB_H_
#include "m52235.h"
/*
 *  ����ߥ�٥�����Τ�������
 */
#define	TIRQ_NMI	0x7u		/* �Υ�ޥ����֥����� */
#define	TIRQ_LEVEL6	0x6u		/* ����ߥ�٥�6 */
#define	TIRQ_LEVEL5	0x5u		/* ����ߥ�٥�5 */
#define	TIRQ_LEVEL4	0x4u		/* ����ߥ�٥�4 */
#define	TIRQ_LEVEL3	0x3u		/* ����ߥ�٥�3 */
#define	TIRQ_LEVEL2	0x2u		/* ����ߥ�٥�2 */
#define	TIRQ_LEVEL1	0x1u		/* ����ߥ�٥�1 */

#ifndef _MACRO_ONLY
/*
 *  GDB STUB�ƽФ��롼����
 */

extern void mcfuart_putc_pol(ID portid, char c);	/*  mcfuart.c  */

#ifdef GDB_STUB

#define cfv2_exit	gdb_stub_exit
#define cfv2_putc	gdb_stub_putc

Inline void
gdb_stub_exit (void)
{
	/* �ƥ��Ȥ��Ƥ��ʤ� */
	Asm("trap #3"::);
}

Inline int
gdb_stub_putc (ID portid, int c)
{
	mcfuart_putc_pol (portid, c);
	return(c);
}

#else /* GDB_STUB */

Inline void
cfv2_exit ()
{
	while (1);
}

Inline void
cfv2_putc (ID portid, char c)
{
	mcfuart_putc_pol (portid, c);
}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _M52235EVB_H_ */
