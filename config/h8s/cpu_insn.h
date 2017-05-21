/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/* �����ˤ����Ѥ��Ƥ��롢MAX_IPM �� cpu_config.h ����� */

#ifndef _MACRO_ONLY

/*
 *  ����쥸���������ؿ�
 */

/* ����ǥ���󥳡��ɥ쥸������CCR�ˤθ����ͤ��ɽФ� */
Inline UB current_ccr(void)
{
	UB	ccr;

	Asm( "stc.b	ccr, %0l" : "=r"(ccr) );

	return(ccr);
}

/* ����ǥ�����󥳡��ɥ쥸������CCR�ˤθ����ͤ��ѹ� */
Inline void set_ccr(UB ccr)
{
	Asm( "ldc.b	%0l, ccr" ::"r"(ccr) );
}

/* �������ƥ�ɥ쥸������EXR�ˤθ����ͤ��ɽФ� */
Inline UB current_exr(void)
{
	UB	exr;

	Asm( "stc.b	exr, %0l" : "=r"(exr) );

	return(exr);
}

/* ����ǥ���󥳡��ɥ쥸������EXR�ˤθ����ͤ��ѹ� */
Inline void set_exr(UB exr)
{
	Asm( "ldc.b	%0l, exr" :: "r"(exr) );
}

/*
 *  ����ߥޥ������饤�֥�� (����ߥ⡼�ɣ���)
 */

/* ���ߤγ���ߥޥ������ɽФ� */
Inline IPM current_intmask(void)
{
	return(  (IPM)  (current_exr() &  EXR_I_MASK) );
}

/* ����ߥޥ��������� */
Inline void set_intmask(IPM intmask)
{
	set_exr( (IPM) ((current_exr() & ~EXR_I_MASK) | intmask ) );
}

/* �����ͥ�������Τ��٤Ƥγ���� �� ����ߥ�٥뤬MAX_IPM �ʲ��γ���� */

/* �����ͥ�������Τ��٤Ƥγ���ߤ�ػ� (NMI�����)  */
Inline void disint(void)
{
	/* set_intmask( (IPM) MAX_IPM ); */
	set_exr( (IPM) ((current_exr() & ~EXR_I_MASK) | MAX_IPM ) );
}

/* �����ͥ�������Τ��٤Ƥγ���ߤ���� (NMI�����) */
/*   ���ν����ϡ����¾塢�����ͥ��������̵ͭ����鷺�����٤Ƥγ���ߤ�
     ���Ĥ��뤳�ȤˤʤäƤ��롣 */
Inline void enaint()
{
	/* set_intmask( (IPM) 0 ); */
	set_exr( (IPM)  (current_exr() & ~EXR_I_MASK) );
}

/*
 *  ����ߥ�å����֤������Ѵؿ�
 */

/* ���٤Ƥγ���ߤ�ػ� (NMI�����) */
Inline void _disint_()
{
	/* set_intmask( (IPM) 7 ); */
	set_exr( (IPM) (current_exr() | EXR_I_MASK) );
}

/*
 *  �ӥå�����Ѵؿ�
 */

/* �ӥåȥ��ꥢ */
Inline void bitclr(UW addr, UB bit)
{
	Asm( "bclr %1l, @%0" :: "r"(addr), "r"(bit) );
}

/* �ӥåȥ��å� */
Inline void bitset(UW addr, UB bit)
{
	Asm( "bset %1l, @%0" :: "r"(addr), "r"(bit) );
}

#endif /* _MACRO_ONLY */

#endif /* _CPU_INSN_H_ */
