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
 *  @(#) $Id: pit.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *	�����ޥɥ饤��
 *����������MPC860T��¢�μ�������ߥ�����PIT�����
 */

#ifndef _PIT_H_
#define _PIT_H_

#include <mpc860_sil.h>

/*
 *  SIU����������ߥ�٥�ʥӥåȥѥ������
 */
#define SIU_INT_PIT	LEVEL_TO_BIT_PATTERN(INTLVL_PIT)


/*
 *  �������ͤ�����ɽ���η�
 */
typedef UH	CLOCK;

/*
 *	�����ޤ˶��뤵��륯��å����ȿ�[kHz]
 *   	TIMER_CLOCK=SYSTEM_CLOCK[MHz] / 4
 */
#define	TIMER_CLOCK		(SYSTEM_CLOCK * 1000 / 4)

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
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

/*  ��������ߥ��ơ��������������쥸����  */
#define PISCR       (VH *)(IMMR_BASE + 0x240)
#define PISCRK      (VW *)(IMMR_BASE + 0x340)  /*  �����쥸����  */
#define PISCR_PIRQ  0xff00      /*  ����������׵��٥�ӥå�  */  
#define PISCR_PS    BIT8_16     /*  ��������ߥ��ơ�����  */    
#define PISCR_PIE   BIT13_16    /*  ��������ߥ��͡��֥�  */
#define PISCR_PITF  BIT14_16    /*  PIT�ե꡼�������͡��֥�  */
#define PISCR_PTE   BIT15_16    /*  ���������ޡ����͡��֥�  */

/*  PIT������ȥ쥸�����ʾ��2�Х��ȤΤߡ�  */
#define PITC        (VH *)(IMMR_BASE + 0x244)
#define PITCK       (VW *)(IMMR_BASE + 0x344)  /*  �����쥸����  */

/*  PIT�쥸�����ʾ��2�Х��ȤΤߡ�  */
#define PITR        (VH *)(IMMR_BASE + 0x248)



#ifndef _MACRO_ONLY

/*
 *  �����쥸�����ݸ�Υ�å��ȥ����å�
 */

/*  PISCR��å�  */
Inline void
lock_piscr()
{
    	/*  �ͤ�UNLOCK_KEY�ʳ��Ǥ�����ɤ�  */
    mpc860_wrw_mem(PISCRK, 0);
}

/*  PISCR�����å�  */
Inline void
unlock_piscr()
{
    mpc860_wrw_mem(PISCRK, UNLOCK_KEY);
}

/*  PITC��å�  */
Inline void
lock_pitc()
{
    	/*  �ͤ�UNLOCK_KEY�ʳ��Ǥ�����ɤ�  */
    mpc860_wrw_mem(PITCK, 0);
}

/*  PITC�����å�  */
Inline void
unlock_pitc()
{
    mpc860_wrw_mem(PITCK, UNLOCK_KEY);
}

/*
 *  �����ޥ�������
 */
Inline void
pit_start()
{
    unlock_piscr();         	/*  PISCR�����å�  */
    mpc860_orh_mem(PISCR, PISCR_PTE);
    lock_piscr();         	/*  PISCR��å�  */
}

/*
 *  �����ް�����
 */
Inline void
pit_stop()
{
    unlock_piscr();         	/*  PISCR�����å�  */
    mpc860_andh_mem(PISCR, ~PISCR_PTE);
    lock_piscr();         	/*  PISCR��å�  */
}

/*
 *  �����޳�����׵�Υ��ꥢ
 *          PISCR�쥸������PS�ӥåȤ�1��񤭹���
 */
Inline void
pit_int_clear()
{
	/*
	 *  SIL����Ѥ����Ȥ��Υ���ǽ�򥪥դ�
	 */
#ifdef SIL_DEBUG
    BOOL sil_debug_tmp = sil_debug_on;
    sil_debug_on = FALSE;
#endif /* SIL_DEBUG */

    unlock_piscr();         	/*  PISCR�����å�  */
    mpc860_orh_mem(PISCR, PISCR_PS);
    lock_piscr();         	/*  PISCR��å�  */

	/*
	 *  SIL����Ѥ����Ȥ��Υ���ǽ������
	 */
#ifdef SIL_DEBUG
    sil_debug_on = sil_debug_tmp;
#endif /* SIL_DEBUG */

}


/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
pit_initialize()
{
    VH piscr;
    VW sccr;
    
    /* �����޾����=�ѿ��κ����ͤʤΤǥ����å��Ͼ�ά */

    pit_stop();		/* ��������� */
    
    /*
     *  �����޴�Ϣ������
     */
    
    /*  ����å�����������ʬ��������  */
    unlock_sccr();              /*  SCCR�����å�  */
    sccr = mpc860_rew_mem(SCCR);
    sccr = (sccr & ~SCCR_RTDIV) /*  �ꥢ�륿���९��å�ʬ��:4  */
            | SCCR_RTSEL;       /*  ����å���������EXTCLK  */
    mpc860_wrw_mem(SCCR, sccr);
    lock_sccr();                /*  SCCR��å�  */


    /*  ��������ɸ������  */
    unlock_pitc();                  /*  PITC�����å�  */
    mpc860_wrh_mem(PITC, CLOCK_PER_TICK);
    lock_pitc();                    /*  PITC��å�  */
    
    
    unlock_piscr();                 /*  PISCR�����å�  */
    piscr = mpc860_reh_mem(PISCR);
    piscr = (piscr & ~PISCR_PIRQ)
            | (SIU_INT_PIT << 8)	/*  ����ߥ�٥�����  */
            | PISCR_PIE;                /*  PIT����ߵ���  */
    mpc860_wrh_mem(PISCR, piscr);
    lock_piscr();                   /*  PISCR��å�  */
}

/*
 *  �����ޤ���߽���
 *
 *  �������ޤ�ư�����ߤ����롥
 */
Inline void
pit_terminate()
{
    pit_stop();				/* �����ޤ���� 	*/
    pit_int_clear();			/* �������׵�򥯥ꥢ */

    unlock_piscr();                 	/*  PISCR�����å�  */
    mpc860_andh_mem(PISCR, ~PISCR_PIE);	/* �����޳���ߤ�ػ�   */
    lock_piscr();                   	/*  PISCR��å�  */
    
    /*  �����ϥ����ޤؤΥ���å��������ߤ���  */
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 *����������߶ػ߶����ǸƤӽФ�����
 */
Inline CLOCK
pit_get_current()
{
    CLOCK pitr;
    
    pitr = mpc860_reh_mem(PITR);
    return(CLOCK_PER_TICK - pitr);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
pit_fetch_interrupt()
{
    VH piscr;
    
    /*  �ɤ߽Ф��ʤΤǡ������å����ʤ����ɤ�  */
    piscr = mpc860_reh_mem(PISCR);
    return(piscr & PISCR_PS);
}

#endif /* _MACRO_ONLY */
#endif /* _PIT_H_ */
/*  end of file  */
