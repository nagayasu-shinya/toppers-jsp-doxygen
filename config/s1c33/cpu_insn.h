/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  ����쥸���������ؿ�
 */

/*
 *  ���ơ������쥸����(PSR)�θ����ͤ��ɽФ�
 */
Inline UW
get_psr(void)
{
	UW psr;

	Asm("ld.w %0, %%psr": "=r"(psr));

	return psr;
}

/*
 *  ���ơ������쥸����(PSR)�θ����ͤ��ѹ�
 */
Inline void
set_psr(register UW psr)
{
	Asm("ld.w %%psr, %0": : "r"(psr));
}

/*
 *  �����å��ݥ���(SP)�θ����ͤ��ɽФ�
 */
Inline VP
get_sp(void)
{
	VP sp;

	Asm("ld.w %0, %%sp": "=r"(sp));

	return sp;
}

/*
 *  �����å��ݥ���(SP)�θ����ͤ��ѹ�
 */
Inline void
set_sp(VP sp)
{
	Asm("ld.w %%sp, %0": : "r"(sp));
}

/*
 *  �ץ���५����(PC)�θ����ͤ��ѹ�
 */
Inline void
set_pc(VP pc)
{
	Asm("jp %0": "=r"(pc) : "0"(pc));
}

/*
 *  �ȥ�åץ١����쥸����(TTBR)�θ����ͤ��ɽФ�
 */
Inline VP
get_ttbr(void)
{
#ifdef __c33std
	return (VP) ((volatile s1c33Bcu_t *) S1C33_BCU_BASE)->ulTtbr;
#else
	VP ttbr;

	Asm("ld.w %0, %%ttbr": "=r"(ttbr));

	return ttbr;
#endif /* __c33std */
}

/*
 *  ��ǥ����塼�������Τ���Υӥåȥޥåץ������ؿ�
 *  �ӥåȥޥåפβ���16�ӥåȤ���Ѥ����ǲ��̥ӥåȤ����ͥ���٤��б�������
 */
#ifdef CPU_BITMAP_SEARCH
Inline UINT
bitmap_search(UINT bitmap)
{
	INT offset;
	INT bit;

	Asm("swap %0, %1": "=r"(bitmap): "r"(bitmap));
	Asm("mirror %0, %1": "=r"(bitmap): "r"(bitmap));
	Asm("scan1 %0, %1": "=r"(bit): "r"(bitmap));
	if(bit != 8){
		return bit;
	}

	Asm("sll %0, %1": "=r"(bitmap): "r"(bit));
	offset = bit;
	Asm("scan1 %0, %1": "=r"(bit): "r"(bitmap));

	return offset + bit;
}
#endif	/* CPU_BITMAP_SEARCH */

#endif /* _CPU_INSN_H_ */
