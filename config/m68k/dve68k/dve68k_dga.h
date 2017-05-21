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
 *  @(#) $Id: dve68k_dga.h,v 1.2 2003/06/04 01:52:23 hiro Exp $
 */

/*
 *	DGA�Υ��������桼�ƥ���ƥ�
 */

#ifndef _DVE68K_DGA_H_
#define _DVE68K_DGA_H_

/*
 *  DGA�γ��������ӥåȤ����
 */
#define TBIT_ABT	0x40000000u	/* ���ܡ��ȳ���ߥӥå� */
#define TBIT_SQR	0x04000000u	/* SQR ����ߥӥå� */
#define	TBIT_TT0	0x00100000u	/* ������0 ����ߥӥå� */
#define	TBIT_GP0	0x00010000u	/* ���ꥢ��I/O ����ߥӥå� */

/*
 *  DGA�γ���ߥ�٥�����Τ�������
 */
#define	TIRQ_NMI	0x7u		/* �Υ�ޥ����֥����� */
#define	TIRQ_LEVEL6	0x6u		/* ����ߥ�٥�6 */
#define	TIRQ_LEVEL5	0x5u		/* ����ߥ�٥�5 */
#define	TIRQ_LEVEL4	0x4u		/* ����ߥ�٥�4 */
#define	TIRQ_LEVEL3	0x3u		/* ����ߥ�٥�3 */
#define	TIRQ_LEVEL2	0x2u		/* ����ߥ�٥�2 */
#define	TIRQ_LEVEL1	0x1u		/* ����ߥ�٥�1 */

#define TBIT_ABTIL	24		/* ���ܡ��ȳ���� */
#define TBIT_SQRIL	8		/* SRQ ����� */

#define TBIT_TT0IL	16		/* ������0 ����� */
#define TBIT_GP0IL	0		/* ���ꥢ��I/O ����� */

#ifndef _MACRO_ONLY

/*
 *  DGA�Υ쥸�����ؤΥ��������ؿ�
 */

Inline UW
dga_read(VP addr)
{
	return((UW) dga_rew_reg(addr));
}

Inline void
dga_write(VP addr, UW val)
{
	dga_wrw_reg(addr, (VW) val);
}

Inline void
dga_bit_or(VP addr, UW bitpat)
{
	dga_write(addr, dga_read(addr) | bitpat);
}

Inline void
dga_bit_and(VP addr, UW bitpat)
{
	dga_write(addr, dga_read(addr) & bitpat);
}

Inline void
dga_set_ilv(VP addr, UINT shift, UINT level)
{
	dga_write(addr, (dga_read(addr) & ~(0x07 << shift))
						| (level << shift));
} 

#endif /* _MACRO_ONLY */
#endif /* _DVE68K_DGA_H_ */
