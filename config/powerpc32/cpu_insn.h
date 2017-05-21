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
 *  @(#) $Id: cpu_insn.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *	�ץ��å����ü�̿��Υ���饤��ؿ������PowerPC�ѡ�
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  ����쥸���������ؿ�
 */

/*
 *  �ޥ��󥹥ơ������쥸������MSR�ˤθ����ͤ��ɽФ�
 */
Inline UW
current_msr(void)
{
	UW msr;
	Asm("mfmsr %0" : "=r"(msr));
	return(msr);
}


/*
 *  �ޥ��󥹥ơ������쥸������MSR�ˤθ����ͤ��ѹ�
 */
Inline void
set_msr(UW msr)
{
	Asm("mtmsr %0" : : "r"(msr) );
}


/*
 *  NMI��������٤Ƥγ���ߤ�ػ�
 */
Inline void
disint(void)
{
#if !defined(IBM_PPC_EMB_ENV)
	/*  
	 *   ���ꥸ�ʥ��PowerPC�������ƥ�����ξ��
	 *   ������ȥ���MPC���꡼����IPM PowerPC6xx/7xx���꡼����
	 *   ����������˳������롣
	 */   
	UW msr;
	
	msr = current_msr();
	msr |= MSR_EE;
	msr ^= MSR_EE;
	set_msr(msr);

#else	/*  IBM_PPC_EMB_ENV  */
	/*  
	 *   The IBM PowerPC Embedded Environment�ξ��
	 *   ��IBM��PowerPC40x���꡼���б�
	 *   ����wrteei̿���ľ��EE�ӥåȤ򥯥ꥢ�Ǥ��롣
	 */   
	Asm("wrteei 0" : );	/*  MSR.EE��0  */

#endif	/*  IBM_PPC_EMB_ENV  */
}


/*
 *  ����ߤ����
 */
Inline void
enaint()
{
#if !defined(IBM_PPC_EMB_ENV)
	/*  
	 *   ���ꥸ�ʥ��PowerPC�������ƥ�����ξ��
	 *   ������ȥ���MPC���꡼����IPM PowerPC6xx/7xx���꡼����
	 *   ����������˳������롣
	 */   
	UW msr;
	
	msr = current_msr();
	msr |= MSR_EE;
	set_msr(msr);

#else	/*  IBM_PPC_EMB_ENV  */
	/*  
	 *   The IBM PowerPC Embedded Environment�ξ��
	 *   ��IBM��PowerPC40x���꡼���б�
	 *   ����wrteei̿���ľ��EE�ӥåȤ򥻥åȤǤ��롣
	 */   
	Asm("wrteei 1" : );	/*  MSR.EE��1  */

#endif	/*  IBM_PPC_EMB_ENV  */
}


/*
 *  ���ڥ���롦�ѡ��ѥ������쥸������SPR�ˤθ����ͤ��ɽФ�
 *     no :�쥸�����ֹ�
 *     dst:�ɤ߽Ф����ͤ��Ǽ�����ѿ�
 */

#define _current_spr(no, dst)	Asm("mfspr %0," #no : "=r"(dst))
#define current_spr(no, dst)	_current_spr(no, dst)


/*
 *  ���ڥ���롦�ѡ��ѥ������쥸������SPR�ˤθ����ͤ��ѹ�
 *     no :�쥸�����ֹ�
 *     src:���ꤹ����
 */
#define set_spr(no, src)	_set_spr(no, src)
#define _set_spr(no, src)	Asm("mtspr "#no", %1" : : "r"(src) )

/*
 *  SPRG0�θ����ͤ��ɽФ�
 */
Inline UW
current_sprg0()
{
    UW sprg0;
    
    current_spr(SPRG0, sprg0);	/*  sprg0 �� SPRG0  */
    return(sprg0);
}



/*
 *  ��ǥ����塼�������Τ���Υӥåȥޥåץ������ؿ�
 *
 *�����������¸�����Ѱդ���ؿ������Ѥ���Τ�
 *����CPU_BITMAP_SEARCH�ޥ����������ʤ�
 */


#endif /* _CPU_INSN_H_ */
/*  end of file  */
