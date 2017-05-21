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
 *  @(#) $Id: cpu_config.c,v 1.1 2004/07/21 02:49:36 monaka Exp $
 */

/*
 *	�ץ��å���¸�⥸�塼���i386�ѡ�
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <i386.h>

UW nest = 0; /* �����ߥͥ��Ȳ�� */
FP exc_table[0x20]; /* CPU�㳰�ϥ�ɥ�Υơ��֥� */

static SEGDESC gdt[3];    /* �����Х�ǥ�������ץ��ơ��֥� */
static GATEDESC idt[256]; /* �����ߥǥ�������ץ��ơ��֥� */

/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize()
{
	DESCPTR desc_ptr;

	/* Flat model */
	set_segment_descriptor(0, 0x0, 0x00000, 0x00, 0);
	set_segment_descriptor(1, 0x0, 0xfffff, I386_TYPE_SEG_CODE | I386_TYPE_SEG_READABLE, 0);
	set_segment_descriptor(2, 0x0, 0xfffff, I386_TYPE_SEG_DATA | I386_TYPE_SEG_WRITEABLE, 0);

	desc_ptr.limit = sizeof(gdt) - 1;
	desc_ptr.base = (unsigned)gdt;

	Asm("movl	%0, %%eax": : "g"(&desc_ptr) : "eax");
	Asm("lgdt	(%eax)		\n"
	    "ljmp	$0x8, $csinit	\n" /* �ѥ��ץ饤������ɤߤ���̿��򥯥ꥢ���� */
	    "csinit:			\n"
	    "movw	$0x10, %ax	\n"
	    "movw	%ax, %ds	\n"
	    "movw	%ax, %es	\n"
	    "movw	%ax, %fs	\n"
	    "movw	%ax, %gs	\n"
	    "movw	%ax, %ss");

	set_gate_descriptor( 0, 0x8, exception0,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 1, 0x8, exception1,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 2, 0x8, exception2,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 3, 0x8, exception3,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 4, 0x8, exception4,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 5, 0x8, exception5,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 6, 0x8, exception6,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 7, 0x8, exception7,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 8, 0x8, exception8,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 9, 0x8, exception9,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(10, 0x8, exception10, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(11, 0x8, exception11, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(12, 0x8, exception12, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(13, 0x8, exception13, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(14, 0x8, exception14, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(16, 0x8, exception16, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(17, 0x8, exception17, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(18, 0x8, exception18, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(19, 0x8, exception19, I386_TYPE_GATE_INTR, 0);

	desc_ptr.limit = sizeof(idt) - 1;
	desc_ptr.base = (unsigned)idt;

	Asm("movl	%0, %%eax	" : : "g"(&desc_ptr) : "eax");
	Asm("lidt	(%eax)		");

}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate()
{
}


/*
 * i386�������ȥǥ�����ץ�������
 */
void
set_segment_descriptor(int sel, unsigned addr, unsigned limit, unsigned type, unsigned dpl)
{
	SEGDESC *desc;
	desc = &gdt[sel];
	desc->base_L = (addr & 0xffffff);
	desc->base_H = ((addr >> 24) & 0xff);
	desc->limit_L = (limit & 0xffff);
	desc->limit_H = ((limit >> 16) & 0xf);
	desc->type = (type & 0xf);
	desc->s = 1;		/* code/data segment */
	desc->dpl = dpl;
	desc->p = 1;		/* segment is existing */
	desc->avl = 0;		/* unused */
	desc->x = 0;		/* reserved */
	desc->db = 1;		/* 32bits segment */
	desc->g = 1;		/* 4KB limits */
}

void
set_gate_descriptor(int sel, unsigned selector, void *func, unsigned type, unsigned dpl)
{
	GATEDESC *desc;
	desc = &idt[sel];
	desc->offset_L = ((unsigned)func & 0xffff);
	desc->offset_H = (((unsigned)func >> 16) & 0xffff);
	desc->selector = selector;
	desc->copy = 0;
	desc->type = type;
	desc->s = 0;
	desc->dpl = dpl;
	desc->p = 1;
}


void
define_exc(EXCNO excno, FP exchdr)
{
#if 0
	if (inhno >= 0x20 || inthdr == NULL)
	{
		return; /*??? Should I generate assertion? */
	}
#endif
	exc_table[excno] = exchdr;
}
