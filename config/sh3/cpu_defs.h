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
 *  @(#) $Id: cpu_defs.h,v 1.13 2005/07/27 11:06:36 honda Exp $
 */

/*
 *  �ץ��å��˰�¸���������SH3/4�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�kernel.h �� sil.h �ǥ��󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��뤳�ȤϤʤ������Υե�����򥤥�
 *  ���롼�ɤ������ˡ�t_stddef.h �� itron.h �����󥯥롼�ɤ����Τǡ�
 *  �����˰�¸���Ƥ�褤��
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

/*
 *  �ץ��å��˰�¸�������
 */
#ifndef _MACRO_ONLY

/*
 * �����/CPU�㳰�ϥ�ɥ��ֹ�η�
 */
typedef	UINT		INHNO;		/* ����ߥϥ�ɥ��ֹ� */
typedef	UINT		EXCNO;		/* CPU�㳰�ϥ�ɥ��ֹ� */


/*
 * ����ߥޥ����η��ȳ���ߥޥ������ѹ�/����
 */
typedef	UINT		IPM;		/* ����ߥޥ��� */

extern ER	chg_ipm(IPM ipm)  throw();
extern ER	get_ipm(IPM *p_ipm)  throw();


/*
 *  INTNO���ȳ���ߤζػ�/����
 */
typedef	UINT		INTNO;		/* ������ֹ� */

extern ER	dis_int(INTNO intno)  throw();
extern ER	ena_int(INTNO intno)  throw();


/*
 *  �������åȥ����ƥ��¸�Υ����ӥ�������
 */
typedef	UD  SYSUTIM;	       /* ��ǽɾ���ѥ����ƥ���� */
extern ER	vxget_tim(SYSUTIM *p_sysutim) throw();

/*
 * ���ߤγ���ߥޥ������ɽФ�
 */
Inline UW
_current_intmask_()
{
    UW sr;

    Asm("stc  sr,%0" : "=r"(sr));
    return(sr & 0x000000f0);
}

/*
 *  ���Ƥγ���ߤ�ػ�
 */
Inline void
_disint_()
{
    UW sr;

    Asm("stc  sr,%0" : "=r"(sr));
    sr |= 0x000000f0;
    Asm("ldc %0, sr" : : "r"(sr) );
}

/*
 *  ����ߥޥ���������
 */
Inline void
_set_intmask_(UW intmask)
{
    UW sr;
    
    Asm("stc  sr,%0" : "=r"(sr));
    sr = (sr & ~0x000000f0) | intmask;
    Asm("ldc %0, sr" : : "r"(sr) );    
}


/*
 * ����ߥ�å����֤�����
 */
#define SIL_PRE_LOC UW _intmask_ = _current_intmask_()
#define SIL_LOC_INT()   _disint_()
#define SIL_UNL_INT()   _set_intmask_(_intmask_)


#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
