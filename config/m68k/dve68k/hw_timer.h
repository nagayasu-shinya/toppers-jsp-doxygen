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
 *  @(#) $Id: hw_timer.h,v 1.9 2003/07/08 14:57:15 hiro Exp $
 */

/*
 *	�����ޥɥ饤�С�DVE68K/40�ѡ�
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include <dve68k_dga.h>

/*
 *  �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define	INHNO_TIMER	TVEC_TT0

#ifndef _MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef UW	CLOCK;

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *
 *  DVE68K/40 CPU�ܡ��ɤǤϡ������ޤ�1������˥�����ȥ��åפ��롥
 */
#define	TIMER_CLOCK		1000
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define	MAX_CLOCK	((CLOCK) 0xffffff)

/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define	GET_TOLERANCE	100	/* �����٤�θ��Ѥ��͡�ñ�̤�����ɽ����*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  ��������ߤޤǤλ��֡�nsecñ�̡�
 *
 *  �ͤ˺���Ϥʤ���
 */
#define	TIMER_STOP_DELAY	200

/*
 *  �쥸������������
 */
#define	CSR12_START	0x80000000u	/* ������ư�� */

/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize()
{
	CLOCK	cyc = TO_CLOCK(TIC_NUME, TIC_DENO);

	/*
	 *  �����޼��������ꤷ�������ޤ�ư��򳫻Ϥ��롥
	 */
	assert(cyc <= MAX_CLOCK);
	dga_write((VP) TADR_DGA_CSR12, CSR12_START | cyc);

	/*
	 *  �����޳���ߤγ���ߥ�٥�����ꤷ���׵�򥯥ꥢ�����塤
	 *  �ޥ����������롥
	 */
	dga_set_ilv((VP) TADR_DGA_CSR25, TBIT_TT0IL, TIRQ_LEVEL4);
	dga_write((VP) TADR_DGA_CSR23, TBIT_TT0);
	dga_bit_or((VP) TADR_DGA_CSR21, TBIT_TT0);
}

/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{
	dga_write((VP) TADR_DGA_CSR23, TBIT_TT0);
}

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
Inline void
hw_timer_terminate()
{
	/*
	 *  �����ޤ�ư�����ߤ��롥
	 */
	dga_bit_and((VP) TADR_DGA_CSR12, ~CSR12_START);

	/*
	 *  �����޳���ߤ�ޥ��������׵�򥯥ꥢ���롥
	 */
	dga_bit_and((VP) TADR_DGA_CSR21, ~TBIT_TT0);
	dga_write((VP) TADR_DGA_CSR23, TBIT_TT0);
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK
hw_timer_get_current()
{
	CLOCK	clk;

	/*
	 *  �����ޤ�ư�����Ū����ߤ����������ͤ��ɤ߽Ф���
	 */
	dga_bit_and((VP) TADR_DGA_CSR12, ~CSR12_START);
	sil_dly_nse(TIMER_STOP_DELAY);
	clk = dga_read((VP) TADR_DGA_CSR13) & 0x00ffffffu;
	dga_bit_or((VP) TADR_DGA_CSR12, CSR12_START);
	return(clk);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
hw_timer_fetch_interrupt()
{
	return((dga_read((VP) TADR_DGA_CSR20) & TBIT_TT0) != 0);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
