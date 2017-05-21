/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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
 *  @(#) $Id: hw_timer.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *	�����ޥɥ饤�С�MPC860T�ѡ�
 *����������MPC860T��¢�μ�������ߥ�����PIT�����
 *
 *��������������ߥ���ȥ����¸�Ϥ��Υե�����˵��Ҥ���
 *���������������ޥǥХ������Τ˰�¸���������pit.h�˵��Ҥ���
 *
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>

#ifndef _MACRO_ONLY
#include <pit.h>
#endif /* _MACRO_ONLY */

/*  �����޳���ߥϥ�ɥ�Υ٥����ֹ�  */
#define	INHNO_TIMER	LEVEL_TO_INHNO(INTLVL_PIT)

/*  �����޳���ߤ�IPM  */
#define	IPM_PIT		LEVEL_TO_IPM(INTLVL_PIT)

/*  �����޳���ߤε��ĥӥå�  */
#define	ENABLE_PIT	LEVEL_TO_ENABLE_BIT(INTLVL_PIT)


#ifndef _MACRO_ONLY

/*
 *  �����޳�����׵�Υ��ꥢ
 */
#define hw_timer_int_clear	pit_int_clear


/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize()
{
	/*
	 *  �����ޥǥХ������Τν����
	 */
	pit_initialize();

	/*
	 *  �����ƥ।�󥿡��ե�������˥å�SIU��IPM�����
	 */
	mpc860_orh_mem(SIMASK, ENABLE_PIT);

	/*
	 *  �����ͥ������Υǡ��������
	 */
	define_ipm(INHNO_TIMER, IPM_PIT);	/* IPM�����ꡡ*/

	
	pit_int_clear();	/*  ������׵�򥯥ꥢ  */
	pit_start();		/*  �����ޥ�������    	*/
}

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
#define hw_timer_terminate		pit_terminate

/*
 *  �����ޤθ����ͤ��ɽФ�
 *�����������ޤ�ư�����Ū����ߤ����������ͤ��ɤ߽Ф���
 */
#define hw_timer_get_current		pit_get_current

/*
 *  �����޳�����׵�Υ����å�
 */
#define hw_timer_fetch_interrupt	pit_fetch_interrupt

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
/*  end of file  */
