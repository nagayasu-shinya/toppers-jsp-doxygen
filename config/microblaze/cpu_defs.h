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
 *  @(#) $Id: cpu_defs.h,v 1.10 2005/07/27 10:38:55 honda Exp $
 */

/*
 *  �ץ��å��˰�¸���������Microblaze�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�kernel.h �� sil.h �ǥ��󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��뤳�ȤϤʤ������Υե�����򥤥�
 *  ���롼�ɤ������ˡ�t_stddef.h �� itron.h �����󥯥롼�ɤ����Τǡ�
 *  �����˰�¸���Ƥ�褤��
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

//#include "microblaze.h"

#ifndef MICROBLAZE
#define MICROBLAZE   /* �ץ��å�ά�� */
#endif 
/*
 *  �ץ��å��˰�¸�������
 */
#ifndef _MACRO_ONLY

typedef	UINT		INHNO;		/* ����ߥϥ�ɥ��ֹ� */
typedef	UINT		IPM;		/* ����ߥޥ��� */
typedef	UINT		EXCNO;		/* CPU�㳰�ϥ�ɥ��ֹ� */


/*
 *  INTNO���ȳ���ߤζػ�/����
 */

typedef	UINT		INTNO;		/* ������ֹ� */

extern ER	dis_int(INTNO intno) throw(); 
extern ER	ena_int(INTNO intno) throw();


/*
 *  �������åȥ����ƥ��¸�Υ����ӥ�������
 */
typedef	UW  SYSUTIM;	/* ��ǽɾ���ѥ����ƥ���� */
extern  ER   vxget_tim(SYSUTIM *pk_sysutim) throw();


/*
 *  MSR�Υӥå�
 */
#define MSR_IE 0x02
#define MSR_BE 0x01


/*
 *  ���٤Ƥγ���ߤ�ػ�
 */
Inline void
_disint_()
{
    UW msr;
  
    Asm("mfs %0,rmsr": "=r"(msr));
    msr &= ~MSR_IE;
    Asm("mts rmsr,%0" : : "r"(msr));
}


/*
 *  ����ߤ����
 */
Inline void
_enaint_()
{
    UW msr;
    
    Asm("mfs %0,rmsr": "=r"(msr));
    msr |= MSR_IE;
    Asm("mts rmsr,%0" : : "r"(msr));    
}


/*
 *  ����ߥ�å����֤�����
 */
#define SIL_PRE_LOC 
#define SIL_LOC_INT()   _disint_()
#define SIL_UNL_INT()   _enaint_()

/*
 * �����ƥ�����ǽ���
 */
Inline void
kernel_abort()
{
    Asm("brki r16 0x20");
}

/*
 *  ���������Ԥ�
 */
Inline void
sil_dly_nse(UINT dlytim)
{
    Asm("add r5, r0, %0; \
         brlid r15, _sil_dly_nse; \
         nop\n"
        : 
        : "r"(dlytim)
        : "r15", "r5");
    
}


#endif /* _MACRO_ONLY */

/*
 *  �ץ��å��Υ���ǥ�����
 */
#define SIL_ENDIAN  SIL_ENDIAN_BIG  /* �ӥå�����ǥ����� */


#endif /* _CPU_DEFS_H_ */
