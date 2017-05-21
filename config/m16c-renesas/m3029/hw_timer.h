/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
 * 
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ��� 
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ����(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ�������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: hw_timer.h,v 1.2 2006/08/03 04:14:02 honda Exp $
 */

/*
 *	�����ޥɥ饤�С�M3029�ѡ�
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include <sil.h>
#include <m3029.h>


/*
 *  �����ޡ��γ����ߥ�٥�
 */
#define INT_LEVEL_TIMER	0x05

/*
 * �����޳���ߥϥ�ɥ�Υ٥����ֹ�
 */
#ifdef USE_TA0
#define	INHNO_TIMER	       INT_TA0
#elif defined(USE_TA1)
#define	INHNO_TIMER	       INT_TA1
#endif


/*
 * �����ޥ⡼�ɥ쥸����
 */
#ifdef USE_TA0
#define TADR_SFR_TAMR TADR_SFR_TA0MR
#elif  defined(USE_TA1)
#define TADR_SFR_TAMR TADR_SFR_TA1MR
#endif

/*
 * ���åץ�����ե饰
 */
#ifdef USE_TA0
#define TBIT_UDF_TAUD TBIT_UDF_TA0UD
#elif  defined(USE_TA1)
#define TBIT_UDF_TAUD TBIT_UDF_TA1UD  
#endif

/*
 * �����ޥ쥸����
 */
#ifdef USE_TA0
#define TADR_SFR_TA TADR_SFR_TA0
#elif  defined(USE_TA1)
#define TADR_SFR_TA TADR_SFR_TA1
#endif

/*
 * ������ȳ��ϥӥå�
 */
#ifdef USE_TA0
#define TBIT_TABSR_TS  TBIT_TABSR_TA0S
#elif  defined(USE_TA1)
#define TBIT_TABSR_TS  TBIT_TABSR_TA1S
#endif

/*
 * ���������쥸�����Υ��ե��å�
 */
#ifdef USE_TA0
#define TADR_SFR_TAIC_OFFSET  TADR_SFR_TA0IC_OFFSET
#elif  defined(USE_TA1)
#define TADR_SFR_TAIC_OFFSET  TADR_SFR_TA1IC_OFFSET
#endif


#ifndef _MACRO_ONLY


/*
 *  �������ͤ�����ɽ���η�
 */
typedef UH	CLOCK;


/*
 *  �������ͤ�����ɽ���ȥߥ���ñ�̤Ȥ��Ѵ�
 *
 *  1ms�Υ����ޡ������ߤ���Ѥ���ΤǤ��Υ���å���������롥
 */
#define TIMER_CLOCK		20000
#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((unsigned long)(clock) * 1000 / TIMER_CLOCK)


/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define	MAX_CLOCK	((CLOCK) 0xffff)


/*
 *  ��ǽɾ���ѥ����ƥ�������Ф��ݤν������֤θ��Ѥ��͡�ñ�̤�����ɽ����
 */
#define	GET_TOLERANCE	100	/* �����٤�θ��Ѥ��͡�ñ�̤�����ɽ����*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
hw_timer_initialize()
{
    /*
     * �����޽����
     */
    /* �����ޥ��������� */
	sil_wrb_mem((VP)TADR_SFR_TABSR,
                sil_reb_mem((VP)TADR_SFR_TABSR) & ~TBIT_TABSR_TS);
    /* �����󥫥�������� */
	sil_wrb_mem((VP)TADR_SFR_UDF,
                sil_reb_mem((VP)TADR_SFR_UDF)   & ~TBIT_UDF_TAUD);
    /*  ������ȥ�����f1, �����ޥ⡼��  */
	sil_wrb_mem((VP)TADR_SFR_TAMR, 0x00);		
    
	/*
     *  �������ͤν����
	 *  �����ޤ� 1ms�� TIMER_CLOCK �������,
	 *  �쥸���������ͤϥޥ��ʥ�1����.
	 */
	sil_wrh_mem((VP)TADR_SFR_TA, (TIMER_CLOCK - 1));
    
    /* �����ߥ�٥������ */
    set_ic_ilvl((VP)(TADR_SFR_INT_BASE + TADR_SFR_TAIC_OFFSET), INT_LEVEL_TIMER);
    
    /* ������ȳ���	*/
	sil_wrb_mem((VP)TADR_SFR_TABSR,
                sil_reb_mem((VP)TADR_SFR_TABSR) | TBIT_TABSR_TS);
}


/*
 *  �����޳�����׵�Υ��ꥢ
 */
Inline void
hw_timer_int_clear()
{
	/*
	 *  ���δؿ��ϥ����޳����ߥϥ�ɥ餬
	 *  isig_tim ��ƤӽФ����˼¹Ԥ����.
	 *  ����ߤ������դ����Ƥ���
	 *  ����ߥϥ�ɥ�˽������ܤä�������
	 *  ������׵�ӥåȤϥ��ꥢ����뤿��
	 *  ���⤹��ɬ�פ��ʤ�. 
	 */
}


/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
Inline void
hw_timer_terminate()
{
    /* ����������	*/
	sil_wrb_mem((VP)TADR_SFR_TABSR,
                sil_reb_mem((VP)TADR_SFR_TABSR) & ~TBIT_TABSR_TS);    
}


/*
 *  �����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return ((TIMER_CLOCK-1) - sil_reh_mem((VP)TADR_SFR_TA));
}


/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return (sil_reb_mem((VP)(TADR_SFR_INT_BASE + TADR_SFR_TAIC_OFFSET)) & TBIT_IC_IR) != 0;
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
