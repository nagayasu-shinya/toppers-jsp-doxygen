/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2003 by Industrial Technology Institute,
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
 * 
 *  @(#) $Id: pit.h,v 1.1 2004/09/03 16:39:56 honda Exp $
 */

/*
 *	�����ޥɥ饤�ФΥ���ץ�
 */

#ifndef _PIT_H_
#define _PIT_H_

/*  �ܡ������SIL���Ѱդ���  */
//#include <sil_mpc860.h>


/*
 *  �������ͤ�����ɽ���η�
 */
typedef UH	CLOCK;

/*
 *	�����ޤ˶��뤵��륯��å����ȿ�[kHz]
 */

#define TIMER_CLOCK	12500

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *������TIMER_CLOCK��tb6102s.h��������Ƥ���
 */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)
#define CLOCK_PER_TICK	((CLOCK) (TO_CLOCK(TIC_NUME, TIC_DENO) - 1))

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define	MAX_CLOCK	((CLOCK) 0xffffu)

/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define	GET_TOLERANCE	100	/* �����٤�θ��Ѥ��͡�ñ�̤�����ɽ����*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  ����ȥ���쥸���������
 */


#ifndef _MACRO_ONLY

/*
 *  �����ޥ�������
 */
Inline void
pit_start()
{
}

/*
 *  �����ް�����
 */
Inline void
pit_stop()
{
}

/*
 *  �����޳�����׵�Υ��ꥢ
 *          PISCR�쥸������PS�ӥåȤ�1��񤭹���
 */
Inline void
pit_int_clear()
{
}


/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
pit_initialize()
{
}

/*
 *  �����ޤ���߽���
 *
 *  �������ޤ�ư�����ߤ����롥
 */
Inline void
pit_terminate()
{
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 *����������߶ػ߶����ǸƤӽФ�����
 */
Inline CLOCK
pit_get_current()
{
	return ((CLOCK)0);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
pit_fetch_interrupt()
{
	return (TRUE);
}

#endif /* _MACRO_ONLY */
#endif /* _PIT_H_ */
/*  end of file  */
