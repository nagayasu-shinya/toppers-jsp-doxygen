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
 *  @(#) $Id: sys_config.c,v 1.1 2004/07/21 02:49:36 monaka Exp $
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���PC/AT�ѡ�
 */

#include "jsp_kernel.h"
#include <sil.h>
#include <i386.h>
#include <irc.h>
#include <irc_inline.h>

#ifndef SYS_PUTC_PORTID
#define SYS_PUTC_PORTID 1
#endif

#if SYS_PUTC_PORTID >= 1
#include <pcat_com.h>
#else
#define VIDEO_ADDRESS 0xb8000
#define VIDEO_ATTRIBUTE 7
#define VIDEO_X_SIZE 80
#define VIDEO_Y_SIZE 25
UB video_x;
UB video_y;
Inline void video_write(UB x, UB y, char c) {
	sil_wrb_mem((VP)(VIDEO_ADDRESS + (VIDEO_X_SIZE * y + x) * 2), c);
	sil_wrb_mem((VP)(VIDEO_ADDRESS + (VIDEO_X_SIZE * y + x) * 2 + 1), VIDEO_ATTRIBUTE);
}
void video_init(void) {
	UB y;
	for (y = 0; y < VIDEO_Y_SIZE; ++y) {
		UB x;
		for (x = 0; x < VIDEO_X_SIZE; ++x) {
			video_write(x, y, ' ');
		}
	}
}
void video_putc(char c) {
	switch (c) {
	case '\n':
		video_x = VIDEO_X_SIZE;
		break;
	case '\r':
		video_x = 0;
		break;
	default:
		video_write(video_x, video_y, c);
		++video_x;
		break;
	}
	if (video_x >= VIDEO_X_SIZE) {
		UB x;
		video_x = 0;
		++video_y;
		if (video_y >= VIDEO_Y_SIZE) {
			video_y = 0;
		}
		for (x = 0; x < VIDEO_X_SIZE; ++x) {
			video_write(x, video_y, ' ');
		}
	}
}
#endif

FP int_table[0x10]; /* ����ߥϥ�ɥ�Υơ��֥� */

/*
 *  �������åȥ����ƥ��¸�ν����
 */
void
sys_initialize()
{
	set_gate_descriptor(0x20, 0x8, interrupt0, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x21, 0x8, interrupt1, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x22, 0x8, interrupt2, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x23, 0x8, interrupt3, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x24, 0x8, interrupt4, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x25, 0x8, interrupt5, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x26, 0x8, interrupt6, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x27, 0x8, interrupt7, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x28, 0x8, interrupt8, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x29, 0x8, interrupt9, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x2a, 0x8, interrupt10, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x2b, 0x8, interrupt11, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x2c, 0x8, interrupt12, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x2d, 0x8, interrupt13, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x2e, 0x8, interrupt14, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(0x2f, 0x8, interrupt15, I386_TYPE_GATE_INTR, 0);

	irc_initialize();
#if SYS_PUTC_PORTID >= 1
	pcat_com_init(SYS_PUTC_PORTID);
#else
	video_init();
#endif
}

/*
 *  �������åȥ����ƥ�ν�λ
 */
void
sys_exit(void)
{
	while(1);
}

ER irc_dis_irq(UB irq)
{
	BOOL cpu_locked;

	if (irq > 15) {
		return E_PAR;
	}

	cpu_locked = sense_lock();

	if(!cpu_locked)
	{
		x_lock_cpu();
	}

	if(irq < 8)
	{
		sil_wrb_iop((VP)0x21, sil_reb_iop((VP)0x21) | (1 << irq));
	}
	else
	{
		sil_wrb_iop((VP)0xA1, sil_reb_iop((VP)0xA1) | (1 << (irq - 8)));
	}

	if(!cpu_locked)
	{
		x_unlock_cpu();
	}

	return E_OK;
}

ER irc_ena_irq(UB irq)
{
	BOOL cpu_locked;

	if (irq > 15) {
		return E_PAR;
	}

	cpu_locked = sense_lock();

	if(!cpu_locked)
	{
		x_lock_cpu();
	}

	if(irq < 8)
	{
		sil_wrb_iop((VP)0x21, sil_reb_iop((VP)0x21) & ~(1 << irq));
	}
	else
	{
		sil_wrb_iop((VP)0xA1, sil_reb_iop((VP)0xA1) & ~(1 << (irq - 8)));
	}

	if(!cpu_locked)
	{
		x_unlock_cpu();
	}

	return E_OK;
}

#if SYS_PUTC_PORTID >= 1
#define SYS_PUT_CHAR(c) pcat_com_putc(SYS_PUTC_PORTID, (c))
#else
#define SYS_PUT_CHAR(c) video_putc(c)
#endif

void
sys_putc(char c)
{
    if (c == '\n') {
        SYS_PUT_CHAR('\r');
    }
    SYS_PUT_CHAR(c);
}


void
define_inh(INHNO inhno, FP inthdr)
{
#if 0
	if (inhno >= 256 || inthdr == NULL)
	{
		return; /*??? Should I generate assertion? */
	}
#endif
	int_table[TO_INTNO(inhno)] = inthdr;
}

ER vdef_inh(INHNO inhno, const T_DINH *pk_dinh) {
	BOOL locked;
	if (!(0x20 <= inhno && inhno <= 0x2f)) {
		return E_PAR;
	}
	if (pk_dinh->inhatr != TA_HLNG) {
		return E_RSATR;
	}
	locked = sense_lock();
	if (!locked) {
		x_lock_cpu();
	}
	define_inh(inhno, pk_dinh->inthdr);
	if (!locked) {
		x_unlock_cpu();
	}
	return E_OK;
}
