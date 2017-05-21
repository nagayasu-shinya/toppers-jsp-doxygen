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
 *  @(#) $Id: sh1_sil.h,v 1.4 2004/09/22 08:47:52 honda Exp $
 */

/*
 *  SH1��¢������쥸�����ؤΥ����������桼�ƥ���ƥ��ʥӥåȱ黻��
 *  
 *  sh1.h�˵��Ҥ���Τ����쥬��Ȥ�����sil.h�ȤΥ��󥯥롼�ɤ�
 *  ���֤δط�����Ω�����ե�����Ȥ���
 *  t_config.h��ľ�ܥ��󥯥롼�ɤ����Ȥ���sil.h�����ˤ���
 *  �ե����뤬���󥯥롼�ɤ�����ǽ�������롣
 *  
 *  ����ѥ���η������å���ǽ��ͭ���ˤ��뤿�ᡢ�ݥ��󥿷���
 *  VB *��VH *��VW *���Ѥ��Ƥ��롣
 *  
 */

#ifndef _SIL_SH1_H_
#define _SIL_SH1_H_

#ifndef _MACRO_ONLY

/*
 *  8�ӥåȥ쥸������AND�黻
 */
Inline void
sh1_anb_reg(VB *mem, VB data)
{
	VB reg = sil_reb_mem((VP)mem);
	reg &= data;
	sil_wrb_mem((VP)mem, reg);
}

/*
 *  8�ӥåȥ쥸������OR�黻
 */
Inline void
sh1_orb_reg(VB *mem, VB data)
{
	VB reg = sil_reb_mem((VP)mem);
	reg |= data;
	sil_wrb_mem((VP)mem, reg);
}


/*
 *  16�ӥåȥ쥸������AND�黻
 */
Inline void
sh1_anh_reg(VH *mem, VH data)
{
	VH reg = sil_reh_mem((VP)mem);
	reg &= data;
	sil_wrh_mem((VP)mem, reg);
}

/*
 *  16�ӥåȥ쥸������OR�黻
 */
Inline void
sh1_orh_reg(VH *mem, VH data)
{
	VH reg = sil_reh_mem((VP)mem);
	reg |= data;
	sil_wrh_mem((VP)mem, reg);
}

/*
 *  32�ӥåȥ쥸������AND�黻
 */
Inline void
sh1_anw_reg(VW *mem, VW data)
{
	VW reg = sil_rew_mem((VP)mem);
	reg &= data;
	sil_wrw_mem((VP)mem, reg);
}

/*
 *  32�ӥåȥ쥸������OR�黻
 */
Inline void
sh1_orw_reg(VW *mem, VW data)
{
	VW reg = sil_rew_mem((VP)mem);
	reg |= data;
	sil_wrw_mem((VP)mem, reg);
}


/*
 *  �����ߥ�٥������
 *  
 *  ��mem  ���ѹ�����쥸����������
 *  ��level�����ꤹ�����ߥ�٥�
 *  ��shift�����ӥåȺ����եȤ����Ȥ�����������Ľ꤫
 *  
 */
Inline void
define_int_plevel(VH *mem, UW level, UINT shift)
{
	VH reg = sil_reh_mem((VP)mem);
	reg = (VH)((reg & ~(0xfu << shift)) | (level << shift));
	sil_wrh_mem((VP)mem, reg);
}



#endif /* _MACRO_ONLY */
#endif	/*  _SIL_SH1_H_  */
