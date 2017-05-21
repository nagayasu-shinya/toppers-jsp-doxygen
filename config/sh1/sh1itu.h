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
 *  @(#) $Id: sh1itu.h,v 1.8 2005/11/14 08:00:44 honda Exp $
 */

/*
 *	�����ޥɥ饤��
 *����������SH1��¢�Υ���ƥ��졼�ƥåɡ������ޡ��ѥ륹����˥å�ITU��
 *��������������ͥ�0�����
 */

#ifndef _SH1ITU_H_
#define _SH1ITU_H_

/*
 *  ����å����ȿ���¸������
 *  
 *  ��������å����ȿ��ϥ���ѥ��륪�ץ�����Ϳ������
 */

/*
 *   �����ޤؤ����ϥ���å���ʬ��������
 *   	f/8�ǥ������
 */
#define TCR_TPSC	0x3u

/*
 *   �����ޤ˶��뤵��륯��å����ȿ�[kHz]
 *   	20MHz/8 =2.5MHz =2500kHz
 */
#ifdef CONFIG_20MHZ
#define TIMER_CLOCK	2500
#endif

/*
 *   	19.6608MHz/8 =2.4576MHz =2457.6kHz
 */
#ifdef CONFIG_19MHZ
#define TIMER_CLOCK	2458
#endif

/*
 *   	16MHz/8 =2MHz =2000kHz
 */
#ifdef CONFIG_16MHZ
#define TIMER_CLOCK	2000
#endif



/*
 *  �������ͤ�����ɽ���η�
 */
typedef UH	CLOCK;

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *
 */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)
#define CLOCK_PER_TICK	((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define	MAX_CLOCK	((CLOCK) 0xffffu)

/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define	GET_TOLERANCE	100	/* �����٤�θ��Ѥ��͡�ñ�̤�����ɽ����*/
#define	BEFORE_IREQ(clock)  \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


/*
 *  ����ȥ���쥸�����Υ��ɥ쥹
 */

    	/*  ����  */
#define ITU_TSTR (VB *)0x5ffff00 /*  �����ޥ������ȥ쥸���� ��1�Х��ȡ�*/
#define ITU_TSNC (VB *)0x5ffff01 /*  �����ޥ��󥯥�쥸���� ��1�Х��ȡ�*/
#define ITU_TMDR (VB *)0x5ffff02 /*  �����ޥ⡼�ɥ쥸���� ��1�Х��ȡ�  */
	/*  �����ޥե��󥯥���󥳥�ȥ���쥸���� ��1�Х��ȡ� */
#define ITU_TFCR (VB *)0x5ffff03 
	/*  �����ޥ����ȥץåȥ���ȥ���쥸���� ��1�Х��ȡ�   */
#define ITU_TOCR (VB *)0x5ffff31

	/*  ITU0  */
#define ITU_TCR0  (VB *)0x5ffff04 /*  �����ޥ���ȥ���쥸����0 ��1�Х��ȡ�*/
		/*  ������I/O����ȥ���쥸����0 ��1�Х��ȡ�*/
#define ITU_TIOR0 (VB *)0x5ffff05 
		/*  �����ޥ��󥿥�ץȥ��͡��֥�쥸����0 ��1�Х��ȡ�*/
#define ITU_TIER0 (VB *)0x5ffff06 
#define ITU_TSR0  (VB *)0x5ffff07 /*  �����ޥ��ơ������쥸����0 ��1�Х��ȡ�*/
#define ITU_TCNT0 (VH *)0x5ffff08 /*  �����ޥ�����0 ��2�Х��ȡ�*/
#define ITU_GRA0  (VH *)0x5ffff0a /*  �����ͥ��쥸����A0 ��2�Х��ȡ�*/
#define ITU_GRB0  (VH *)0x5ffff0b /*  �����ͥ��쥸����B0 ��2�Х��ȡ�*/


/*
 *  ����ȥ���쥸������������
 */
#define TSR_IMFA	0x01u	/*  GRA����ڥ��ޥå��ե饰  		*/
#define TSTR_STR0	0x01u	/*  �����ޥ������ȥӥå�  		*/
#define TCR_CCLR_GRA	0x20u	/*  GRA����ڥ��ޥå��ǥ����󥿤򥯥ꥢ */
#define TIER_RESERVE	0x78u	/*  TIER�쥸������ͽ��ӥå�  		*/
#define TIER_IMIEA	0x01u	/*  GRA����ڥ��ޥå��ˤ�������׵����� */
#define TIOR_RESERVE	0x08u	/*  TIOR�쥸������ͽ��ӥå�  		*/
#define TIOR_IOA	0x00u	/*  GRA����ڥ��ޥå��ˤ��ü�ҽ��϶ػ� */


#ifndef _MACRO_ONLY

/*
 *  �����ޥ�������
 */
Inline void
sh1_itu_start(void)
{
	sh1_orb_reg(ITU_TSTR, TSTR_STR0);
}

/*
 *  �����ް�����
 */
Inline void
sh1_itu_stop(void)
{
	sh1_anb_reg(ITU_TSTR, (VB)~TSTR_STR0);
}

/*
 *  �����޳�����׵�Υ��ꥢ
 *	TCR�쥸������IMFA�ӥåȤ�1���ɤ߽Ф�����ˣ���񤭹���
 */
Inline void
sh1_itu_int_clear(void)
{
	/* �������׵�򥯥ꥢ 	*/
	/*  ��GRA����ڥ��ޥå��ե饰�� */
	sh1_anb_reg(ITU_TSR0, (VB)~TSR_IMFA);
}


/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
Inline void
sh1_itu_initialize(void)
{
	CLOCK	cyc = TO_CLOCK(TIC_NUME, TIC_DENO);


	/*
	 *  �����޴�Ϣ������
	 */
	sh1_itu_stop();		/* ��������� */
			     		/* �����޾���ͤΥ����å� */
	assert(cyc <= MAX_CLOCK);
			/*  GRA����ڥ��ޥå��ǥ����󥿤򥯥ꥢ */
			/*  ʬ��������  			*/
	sil_wrb_mem(ITU_TCR0, TCR_CCLR_GRA | TCR_TPSC);
			/*  GRA����ڥ��ޥå��ˤ�������׵����� */
	sil_wrb_mem(ITU_TIER0, TIER_RESERVE | TIER_IMIEA);
			/*  GRA����ڥ��ޥå��ˤ��ü�ҽ��϶ػ� */
	sil_wrb_mem(ITU_TIOR0, TIOR_RESERVE | TIOR_IOA);
			/*  GRA�쥸��������ʥ�������ɸ�͡�  	*/
	sil_wrh_mem(ITU_GRA0, CLOCK_PER_TICK);
	sil_wrh_mem(ITU_TCNT0, 0);	/* �����󥿤򥯥ꥢ 	*/

}

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
Inline void
sh1_itu_terminate(void)
{
	sh1_itu_stop();			/* �����ޤ���� 	*/
	sh1_itu_int_clear();		/* �������׵�򥯥ꥢ */

					/* �����޳���ߤ�ػ�   */
			/*  ��OVIE,IMIEB,IMIEA�ӥåȤ򥯥ꥢ��  */
	sil_wrb_mem(ITU_TIER0, TIER_RESERVE);
}

/*
 *  �����ޤθ����ͤ��ɽФ�
 *�����������ޤ�ư�����Ū����ߤ����������ͤ��ɤ߽Ф���
 */
Inline CLOCK
sh1_itu_get_current(void)
{
	CLOCK	clk;
	

	sh1_itu_stop();			/*  ���������  */
	
	/*  ������Ԥ����֤������٤�  */
	
	clk = sil_reh_mem(ITU_TCNT0);
	sh1_itu_start();			/*  �����ޥ�������  */
	
	return(clk);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline BOOL
sh1_itu_fetch_interrupt(void)
{
	VB tsr0 = sil_reb_mem(ITU_TSR0);
	return(tsr0 & TSR_IMFA);
}

#endif /* _MACRO_ONLY */
#endif /* _SH1ITU_H_ */
