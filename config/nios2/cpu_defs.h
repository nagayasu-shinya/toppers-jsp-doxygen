/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
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
 *  @(#) $Id: cpu_defs.h,v 1.3 2007/01/15 06:05:22 honda Exp $
 */

/*
 *  �ץ��å��˰�¸���������Nios2�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�kernel.h �� sil.h �ǥ��󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��뤳�ȤϤʤ������Υե�����򥤥�
 *  ���롼�ɤ������ˡ�t_stddef.h �� itron.h �����󥯥롼�ɤ����Τǡ�
 *  �����˰�¸���Ƥ�褤��
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define OMIT_SIL_ACCESS

/*
 *  ����ǥ������ȿž
 *  sil.h�Ǥ�������Ƥ��뤬��OMIT_SIL_ACCESS�ˤ�ꤳ�Υե������
 *  ���������ؿ���������Ƥ뤿�ᡤ������������� 
 */
#ifndef SIL_REV_ENDIAN_H
#define	SIL_REV_ENDIAN_H(data) \
	((VH)((((UH)(data) & 0xff) << 8) | (((UH)(data) >> 8) & 0xff)))
#endif /* SIL_REV_ENDIAN_H */

#ifndef SIL_REV_ENDIAN_W
#define	SIL_REV_ENDIAN_W(data) \
	((VW)((((UW)(data) & 0xff) << 24) | (((UW)(data) & 0xff00) << 8) \
		| (((UW)(data)>> 8) & 0xff00) | (((UW)(data) >> 24) & 0xff)))
#endif /* SIL_REV_ENDIAN_H */


#ifndef NIOS2
#define NIOS2   /* �ץ��å�ά�� */
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
typedef	UD  SYSUTIM;	/* ��ǽɾ���ѥ����ƥ���� */
extern  ER  vxget_tim(SYSUTIM *pk_sysutim) throw();


/*
 *  ����ߵ��ĥӥå�
 */
#define STATUS_PIE 0x01

/*
 *  ���٤Ƥγ���ߤ�ػ�
 */
Inline void
_disint_()
{
    UW status;
    
    Asm("rdctl %0, status" : "=r" (status));
    status &= ~STATUS_PIE;
    Asm("wrctl status, %0" :: "r" (status));
}


/*
 *  ����ߤ����
 */
Inline void
_enaint_()
{
    UW status;

    Asm("rdctl %0, status" : "=r" (status));
    status |= STATUS_PIE;
    Asm("wrctl status, %0" :: "r" (status));
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

}


#endif /* _MACRO_ONLY */

/*
 *  �ץ��å��Υ���ǥ�����
 */
#define SIL_ENDIAN  SIL_ENDIAN_LITTLE 

#ifndef _MACRO_ONLY

/*
 * ���ꥢ�������ؿ�
 */

/*
 *  8�ӥå�ñ�̤��ɽФ��������
 */
Inline VB
sil_reb_mem(VP mem)
{
  return(__builtin_ldbuio(mem));
}

Inline void
sil_wrb_mem(VP mem, VB data)
{
    __builtin_stbio(mem, data);
}


/*
 *  16�ӥå�ñ�̤��ɽФ��������
 */
Inline VH
sil_reh_mem(VP mem)
{
	return(__builtin_ldhuio(mem));
}

Inline void
sil_wrh_mem(VP mem, VH data)
{
    __builtin_sthio(mem, data);
}


#define	sil_reh_lem(mem)	sil_reh_mem(mem)
#define	sil_wrh_lem(mem, data)	sil_wrh_mem(mem, data)

Inline VH
sil_reh_bem(VP mem)
{
	VH	data;

	data = __builtin_ldhuio(mem);
	return(SIL_REV_ENDIAN_H(data));
}

Inline void
sil_wrh_bem(VP mem, VH data)
{
    __builtin_sthio(mem, SIL_REV_ENDIAN_H(data));
}


/*
 *  32�ӥå�ñ�̤��ɽФ��������
 */
Inline VW
sil_rew_mem(VP mem)
{
    return(__builtin_ldwio(mem));
}

Inline void
sil_wrw_mem(VP mem, VW data)
{
    __builtin_stwio(mem, data);
}


#define	sil_rew_lem(mem)	sil_rew_mem(mem)
#define	sil_wrw_lem(mem, data)	sil_wrw_mem(mem, data)

Inline VW
sil_rew_bem(VP mem)
{
	VW	data;

	data = __builtin_ldwio(mem);
	return(SIL_REV_ENDIAN_W(data));
}

Inline void
sil_wrw_bem(VP mem, VW data)
{
    __builtin_stwio(mem, SIL_REV_ENDIAN_W(data));
}

/*
 *  ���������Ԥ�
 */
Inline void
sil_dly_nse(UINT dlytim)
{
    
}

#endif /* _MACRO_ONLY */


#endif /* _CPU_DEFS_H_ */
