/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007 by Kurusugawa-Electronics Technology Inc
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
 *  @(#) $Id: cpu_insn.h,v 1.9 2003/06/04 01:51:39 hiro Exp $
 */

/*
 *	�ץ��å����ü�̿��Υ���饤��ؿ������COLDFIRE�ѡ�
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  ���ơ������쥸������SR�ˤθ����ͤ��ɽФ�
 */
Inline UH
current_sr()
{
	UH	sr;

	Asm("move.w %%sr, %0" : "=d"(sr));
	return(sr);
}

/*
 *  ���ơ������쥸������SR�ˤθ����ͤ��ѹ�
 */
Inline void
set_sr(UH sr)
{
         Asm("move.w %0, %%sr" : : "d"(sr) : "cc");
}

/*
 *  NMI��������٤Ƥγ���ߤ�ػ�
 */
Inline void
disint()
{
  set_sr((current_sr() | 0x0700));
}

/*
 *  ���٤Ƥγ���ߤ����
 */
Inline void
enaint()
{
  set_sr((current_sr() & ~0x0700));
}

/*
 *  �٥����١����쥸������VBR�ˤθ����ͤ��ɽФ�
 *
 *  ColdFire��movec vbr, dx�򥵥ݡ��Ȥ��ʤ�����
 *  ���Τ褦�ʰ����ˤʤ�
 *
 */
extern VP current_vbr();


/*
 *  �٥����١����쥸������VBR�ˤ�����
 */
extern void set_vbr(VP vbr);


/*
 *  ��ǥ����塼�������Τ���Υӥåȥޥåץ������ؿ�
 *
 *  �ӥåȥޥåפβ���16�ӥåȤ���Ѥ����ǲ��̥ӥåȤ����ͥ���٤��б�
 *  �����롥
 */
#define	CPU_BITMAP_SEARCH
#define	PRIMAP_BIT(pri)		(0x8000u >> (pri))

Inline UINT
bitmap_search(UINT bitmap)
{
        UINT offset;
	/*
	 *  ���Υ����ɤϡ�bitmap��UINT���ˤ�32�ӥåȤǤ��뤳�Ȥ��ꤷ
	 *  �Ƥ��롥
	 */
        Asm("ff1.l %0" : "=d"(offset): "d"(bitmap & 0x0000FFFF));
	return(offset - 16);
}

#endif /* _CPU_INSN_H_ */
