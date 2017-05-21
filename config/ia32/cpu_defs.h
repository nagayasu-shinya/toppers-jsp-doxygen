/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2002 by Monami software, Limited Partners.
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
 *  @(#) $Id: cpu_defs.h,v 1.1 2004/07/21 02:49:36 monaka Exp $
 */

/*
 *	�ץ��å��˰�¸���������i386�ѡ�
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define IA32

#ifndef _MACRO_ONLY

typedef	UINT		EXCNO;		/* CPU�㳰�ϥ�ɥ��ֹ� */

#define SIL_ENDIAN SIL_ENDIAN_LITTLE

#define SIL_REV_ENDIAN_H(data) ((VH)((((UH)(data) & 0xff) << 8) | (((UH)(data) >> 8) & 0xff)))

#define SIL_REV_ENDIAN_W(data) ((VW)((((UW)(data) & 0xff) << 24) | (((UW)(data) & 0xff00) << 8) | (((UW)(data) >> 8) & 0xff00) | (((UW)(data) >> 24) & 0xff)))

Inline VB sil_reb_iop(VP iop) {
	VB data;
	Asm("inb %%dx, %%al" : "=a"(data) : "d"(iop));
	return data;
}

Inline VH sil_reh_iop(VP iop) {
	VH data;
	Asm("inw %%dx, %%ax" : "=a"(data) : "d"(iop));
	return data;
}

Inline VW sil_rew_iop(VP iop) {
	VW data;
	Asm("inl %%dx, %%eax" : "=a"(data) : "d"(iop));
	return data;
}

#define sil_reh_lep(iop) sil_reh_iop(iop)
#define sil_rew_lep(iop) sil_rew_iop(iop)

Inline VH sil_reh_bep(VP iop) {
	return SIL_REV_ENDIAN_H(sil_reh_iop(iop));
}

Inline VW sil_rew_bep(VP iop) {
	return SIL_REV_ENDIAN_W(sil_rew_iop(iop));
}

Inline void sil_wrb_iop(VP iop, VB data) {
	Asm("outb %%al, %%dx" : : "a"(data), "d"(iop));
}

Inline void sil_wrh_iop(VP iop, VH data) {
	Asm("outw %%ax, %%dx" : : "a"(data), "d"(iop));
}

Inline void sil_wrw_iop(VP iop, VW data) {
	Asm("outl %%eax, %%dx" : : "a"(data), "d"(iop));
}

#define sil_wrh_lep(iop, data) sil_wrh_iop(iop, data)
#define sil_wrw_lep(iop, data) sil_wrw_iop(iop, data)

Inline void sil_wrh_bep(VP iop, VH data) {
	sil_wrh_iop(iop, SIL_REV_ENDIAN_H(data));
}

Inline void sil_wrw_bep(VP iop, VW data) {
	sil_wrw_iop(iop, SIL_REV_ENDIAN_W(data));
}

#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
