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
 *  @(#) $Id: dve68k.h,v 1.8 2003/06/18 12:40:08 hiro Exp $
 */

/*
 *	DVE68K/40 CPU�ܡ��ɤΥϡ��ɥ������񸻤����
 */

#ifndef _DVE68K_H_
#define _DVE68K_H_

/*
 *  ����ߥ٥��ȥ�����
 */
#define	TVEC_G0I	0x40u		/* ���롼��0 ����ߥ٥��ȥ� */
#define TVEC_SQR	0x42u		/* SQR ����ߥ٥��ȥ� */
#define TVEC_ABT	0x46u		/* ���ܡ��ȳ���ߥ٥��ȥ� */

#define	TVEC_G1I	0x48u		/* ���롼��1 ����ߥ٥��ȥ� */
#define	TVEC_GP0	0x48u		/* ���ꥢ��I/O ����ߥ٥��ȥ� */
#define	TVEC_TT0	0x4cu		/* ������0 ����ߥ٥��ȥ� */

#define	TVEC_SWI	0X50u		/* ���եȥ���������ߥ٥��ȥ� */
#define	TVEC_SPRI	0x40u		/* ���ץꥢ������ߥ٥��ȥ� */

/*
 *  CPU�ܡ��ɾ�Υ쥸����
 */
#define TADR_BOARD_REG0		0xfff48000
#define TADR_BOARD_REG1		0xfff48004
#define TADR_BOARD_REG2		0xfff48008

/*
 *  DGA-001�Υ쥸�����Υ��ɥ쥹
 */
#define TADR_DGA_CSR0		0xfff44000
#define TADR_DGA_CSR1		0xfff44004
#define TADR_DGA_CSR3		0xfff4400c
#define TADR_DGA_CSR4		0xfff44010
#define TADR_DGA_CSR5		0xfff44014
#define TADR_DGA_CSR12		0xfff44030
#define TADR_DGA_CSR13		0xfff44034
#define	TADR_DGA_CSR19		0xfff4404c
#define	TADR_DGA_CSR20		0xfff44050
#define	TADR_DGA_CSR21		0xfff44054
#define TADR_DGA_CSR23		0xfff4405c
#define TADR_DGA_CSR24		0xfff44060
#define	TADR_DGA_CSR25		0xfff44064
#define	TADR_DGA_IFR0		0xfff44070
#define TADR_DGA_IFR3		0xfff4407c

/*
 *  DGA�ؤΥ��������ؿ�
 */
#define	dga_rew_reg(addr)		sil_rew_mem(addr)
#define dga_wrw_reg(addr, val)		sil_wrw_mem(addr, val)

/*
 *  ��PD72001��MPSC�ˤΥ쥸�����Υ��ɥ쥹
 */
#define	TADR_UPD72001_DATAA	0xfff45003
#define	TADR_UPD72001_CTRLA	0xfff45007
#define	TADR_UPD72001_DATAB	0xfff4500b
#define	TADR_UPD72001_CTRLB	0xfff4500f

/*
 *  ��PD72001�ؤΥ��������ؿ�
 */
#define	upd72001_reb_reg(addr)		sil_reb_mem(addr)
#define upd72001_wrb_reg(addr, val)	sil_wrb_mem(addr, val)

/*
 *  GDB STUB�ƽФ��롼����
 */
#ifndef _MACRO_ONLY
#ifdef GDB_STUB

Inline void
dve68k_exit()
{
	Asm("trap #2");
}

Inline void
dve68k_putc(char c)
{
	Asm("move.l %0, %%d1; trap #3"
	  : /* no output */
	  : "g"((INT) c)
	  : "d0", "d1", "d2", "d6", "d7");
}

/*
 *  ��˥��ƽФ��롼����
 */
#else /* GDB_STUB */

Inline void
dve68k_exit()
{
	Asm("clr.l %%d0; trap #3"
	  : /* no output */
	  : /* no input */
	  : "d0", "d1", "d2", "d6", "d7");
}

Inline char
dve68k_getc()
{
	INT	c;

	Asm("moveq.l #3, %%d0; trap #3; move.l %%d0, %0"
	  : "=g"(c)
	  : /* no input */
	  : "d0", "d1", "d2", "d6", "d7");
	  return((char) c);
}

Inline void
dve68k_putc(char c)
{
	Asm("moveq.l #5, %%d0; move.l %0, %%d1; trap #3"
	  : /* no output */
	  : "g"((INT) c)
	  : "d0", "d1", "d2", "d6", "d7");
}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _DVE68K_H_ */
