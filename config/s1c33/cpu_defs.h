/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */

/*
 *  �ץ��å��˰�¸�������(S1C33��)
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define S1C33

/*
 *  CPU �ΥХ��Ƚ�˴ؤ������
 */

#define SIL_ENDIAN		SIL_ENDIAN_LITTLE

#ifndef _MACRO_ONLY

typedef UINT	INHNO;		/* ����ߥϥ�ɥ��ֹ�	*/
typedef UINT	EXCNO;		/* CPU�㳰�ϥ�ɥ��ֹ�	*/
typedef UINT	ILEVNO;		/* ����ߥ�٥�		*/

/*
 *  ����ߥ�٥��ѹ�����������
 */
extern	ER	chg_ilv(ILEVNO ilevno);
extern	ER	get_ilv(ILEVNO *p_ilevno);

/*
 *  ����ߵ��ġ��ػ߽���
 */
typedef UINT	INTNO;		/* ������ֹ�		*/

/*
 *  ��¸�ط��ˤ�ꤳ���ǥ�͡���
 */
#define ena_int		_kernel_ena_int
#define dis_int		_kernel_dis_int

#ifdef LABEL_ASM
#define _ena_int	__kernel_ena_int
#define _dis_int	__kernel_dis_int
#endif /* LABEL_ASM */

extern	ER	ena_int(INTNO intno);
extern	ER	dis_int(INTNO intno);

/*
 *  ���ߤγ���ߵ��ĥե饰���ɽФ�
 */
Inline UW
_current_intflag_(void)
{
	UW	psr;

	Asm("ld.w %0, %%psr" : "=r"(psr));
	return(psr & 0x00000010);
}

/*
 *  NMI��������٤Ƥγ���ߤ�ػ�
 */
Inline void
_disint_(void)
{
	UW	psr;

	Asm("ld.w %0, %%psr" : "=r"(psr));
	psr &= 0xffffffef;
	Asm("ld.w %%psr, %0" : : "r"(psr));
}

/*
 *  ����ߵ��ĥե饰������
 */
Inline void
_enaint_(UW intmask)
{
	UW	psr;

	Asm("ld.w %0, %%psr" : "=r"(psr));
	psr |= intmask;
	Asm("ld.w %%psr, %0" : : "r"(psr));
}

/*
 *  ����ߥ�å����֤�����
 */
#define SIL_PRE_LOC	UW _intmask_ = _current_intflag_()
#define SIL_LOC_INT()	_disint_()
#define SIL_UNL_INT()	_enaint_(_intmask_)

#define OMIT_VGET_TIM

typedef	UW  SYSUTIM;		/* ��ǽɾ���ѥ����ƥ���� */

extern ER	vxget_tim(SYSUTIM *p_sysutim) throw();

/*
 *  �����ƥ�����ǽ���
 */

Inline void
kernel_abort (void)
{
	while (1){
		;
	}
}

#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
