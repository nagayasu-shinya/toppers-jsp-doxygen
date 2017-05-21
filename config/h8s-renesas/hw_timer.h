/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <h8s_tpu.h>

/*
 *   �����ޥɥ饤�С�H8S�ե��ߥ꡼�ѡ�
 *     H8S�ե��ߥ꡼�ˤϡ�TPU(16bit������) �� 8bit������ �Σ����ब���
 *     ����Ƥ��ꡢ��������ܿ��ϡ��ƥץ��å��ˤ��ۤʤ롣
 *     �ܼ����Ǥϡ�TPU(16bit������) �����Ѥ��Ƥ��롣���ä˥����ͥ룰��
 *     ¾��H8S�ץ��å��ˤ����ơ�8bit������ �����Ѥ�����ϡ��ѹ���
 *     �Ԥ�ɬ�פ����롣
 */

/*
 *  �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define	INHNO_TIMER	IRQ_TGI0A

#ifndef _MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef UH	CLOCK;

#endif	/* _MACRO_ONLY */

/*
 *  �����޼�����ñ�̤�����ɽ�����Ѵ�
 *  	jsp/kernel/time_manage.c�Ǥ����
 */
#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)

/*
 *  �����޼�����ñ�̤�����ɽ�����Ѵ�
 */
#define CLOCK_PER_TICK	((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define MAX_CLOCK	((CLOCK) 0xffff)

/*
 *  ��ǽɾ���ѥ����ƥ�������Ф��ݤν������֤θ��Ѥ���
 *	��ñ�̤�����ɽ����
 *	��ա�������ʬ������å��˰�¸��
 */

#define GET_TOLERANCE	100u
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

#ifndef _MACRO_ONLY

/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear(void)
{
	/* ����ͥ룰�γ������׵᥯�ꥢ (TGFA = 0) */
	h8s_andb_reg( (VP) TSR0, ~TGFA );
}

/*
 *  �����ޤε�ư����
 *    �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize(void)
{
	/* �⥸�塼�륹�ȥåץ⡼�ɲ�� */
	h8s_andh_reg( (VP) MSTPCR, ~MSTPCR_TPU );

	/* ����ͥ룰��ư����� */
	h8s_andb_reg( (VP) TSTR, ~CST0 );

	/* TCR ������
	   ��TGRA����ڥ��ޥå��ǥ����󥿤򥯥ꥢ(CCLR = 1)
	   ��Ω���夬�ꥨ�å��ǥ������(CKEG1,0 = 0)
	�� ����������å���/4�ǥ������(ʬ�������ꡨTPSC0 =1) */
	h8s_wrb_reg( (VP) TCR0, (CCLR0 | TPSC0) );

	/* TIER ������
	   ��TGFA�ӥåȤˤ�������׵����� */
	h8s_wrb_reg( (VP) TIER0, TGIEA );

	/* TIOR ������
	   ��TGRA����ڥ��ޥå��ˤ��ü�ҽ��϶ػ� */
	/* ���ꤹ�٤���Τ�̵���� */

	/* TGR0A ������
	   ��TGRA�쥸��������ʥ�������ɸ�͡�*/
	h8s_wrh_reg( (VP) TGR0A, CLOCK_PER_TICK );

	h8s_wrh_reg( (VP) TCNT0, 0 );		/* �����󥿤򥯥ꥢ */

	/*
	 *  ����ߴ�Ϣ������
	 */
	icu_set_ilv( IPRF, IPR_UPR, TPU0_INT_LVL );
						/* ����ߥ�٥����� */
	hw_timer_int_clear();			/* ������׵�򥯥ꥢ */

	/* ����ͥ룰��ư��� */
	h8s_orb_reg( (VP) TSTR, CST0 );
}

/*
 *  �����ޤ���߽���
 */
Inline void
hw_timer_terminate(void)
{
	/* ����ͥ룰��ư����� */
	h8s_andb_reg( (VP) TSTR, ~CST0 );

	hw_timer_int_clear();			/* ������׵�򥯥ꥢ */
}

/*
 *  �����ޤθ����ͤ��ɤ߽Ф�
 *    ����߶ػ߶����ǸƤӽФ����ȡ�
 */
Inline CLOCK
hw_timer_get_current(void)
{
	/* ���åץ����󥿤ʤΤ� */
	return( (CLOCK) h8s_reh_reg( (VP) TCNT0 ) );
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return( h8s_reb_reg( (VP) TSR0 ) & TGFA );
}

#endif	/* _MACRO_ONLY */

#endif /* _HW_TIMER_H_ */
