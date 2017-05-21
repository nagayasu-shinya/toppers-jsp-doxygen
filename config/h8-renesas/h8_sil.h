/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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
 *  @(#) $Id: h8_sil.h,v 1.7 2007/03/23 07:58:33 honda Exp $
 */

/*
 *  H8����SIL�γ�ĥ�ʥӥåȱ黻��
 *
 *  h8.h�˵��Ҥ���Τ����쥬��Ȥ�����sil.h�ȤΥ��󥯥롼�ɤ�
 *  ���֤δط�����Ω�����ե�����Ȥ���
 *  t_config.h��ľ�ܥ��󥯥롼�ɤ����Ȥ���sil.h�����ˤ���
 *  �ե����뤬���󥯥롼�ɤ�����ǽ�������롣
 *
 *  ����ѥ���η������å���ǽ��ͭ���ˤ��뤿�ᡢ�ݥ��󥿷���
 *  UB *��UH *��UW *���Ѥ��Ƥ��롣
 *
 */

#ifndef _SIL_H8_H_
#define _SIL_H8_H_

#ifndef _MACRO_ONLY

#include <sil.h>
#include <cpu_insn.h>	/*  bitset(), bitclr()  */

/*
 *  8�ӥåȥ쥸������AND�黻
 */
Inline void
h8_anb_reg(UB *mem, UB data)
{
        UB reg = sil_reb_mem((VP)mem);
        reg &= data;
        sil_wrb_mem((VP)mem, (VB)reg);
}

/*
 *  8�ӥåȥ쥸������OR�黻
 */
Inline void
h8_orb_reg(UB *mem, UB data)
{
        UB reg = sil_reb_mem((VP)mem);
        reg |= data;
        sil_wrb_mem((VP)mem, (VB)reg);
}


/*
 *  16�ӥåȥ쥸������AND�黻
 */
Inline void
h8_anh_reg(UH *mem, UH data)
{
        UH reg = sil_reh_mem((VP)mem);
        reg &= data;
        sil_wrh_mem((VP)mem, (VH)reg);
}

/*
 *  16�ӥåȥ쥸������OR�黻
 */
Inline void
h8_orh_reg(UH *mem, UH data)
{
        UH reg = sil_reh_mem((VP)mem);
        reg |= data;
        sil_wrh_mem((VP)mem, (VH)reg);
}

/*
 *  32�ӥåȥ쥸������AND�黻
 */
Inline void
h8_anw_reg(UW *mem, UW data)
{
        UW reg = sil_rew_mem((VP)mem);
        reg &= data;
        sil_wrw_mem((VP)mem, (VW)reg);
}

/*
 *  32�ӥåȥ쥸������OR�黻
 */
Inline void
h8_orw_reg(UW *mem, UW data)
{
        UW reg = sil_rew_mem((VP)mem);
        reg |= data;
        sil_wrw_mem((VP)mem, (VW)reg);
}

/*
 *  ����ߥ�٥������
 *
 *  ��irc  ��IRC�ǡ�������Ƭ���ɥ쥹
 *
 *  ����UB *ipr�����ꤹ��IPR�쥸����������
 *  ����UB bit ��IPR�쥸�����γ�������ӥå��ֹ�
 *  ����IPM ipm�����ꤹ�����ߥ�٥�
 *  ��������������IPM_LEVEL0,IPM_LEVEL1�Τ����줫
 */
Inline void
define_int_plevel(const IRC *irc)
{
        UB *ipr = irc->ipr;
        UB bit = irc->bit;
        IPM ipm = irc->ipm;

        switch(ipm) {
                case IPM_LEVEL0:        /*  �ץ饤����ƥ���٥�0������  */
                        bitclr(ipr, bit);
                        break;
                case IPM_LEVEL1:        /*  �ץ饤����ƥ���٥�1������  */
                        bitset(ipr, bit);
                        break;
                default:
                        assert(FALSE);
        }
}

/*
 *��I/O�ݡ��ȤΥǡ������ǥ��쥯����󡦥쥸����DDR�ؤΥ�������
 *��
 *����H8��DDR�Ͻ񤭹������ѤǤ��ꡢ���ΤޤޤǤϽ�˾�ΥӥåȤ�����
 *�����ѹ����뤳�Ȥ��Ǥ��ʤ�����bset,bclr̿��Ǥ�����Բġ�
 *�������Τ��ᡢ�ܼ����Ǥϡ������˥ƥ�ݥ����Ѱդ��ơ�DDR��
 *���������ͤ��ݻ�������ˡ��ΤäƤ��롣
 */
/*
 *��DDR���ֹ����
 *��
 *��������Υ���ǥå������Ѥ��롣
 *�����ݡ���7���������ѤΤ��ᡢ��ά���Ƥ��롣
 */
typedef enum {
	IO_PORT1,
	IO_PORT2,
	IO_PORT3,
	IO_PORT4,
	IO_PORT5,
	IO_PORT6,
	IO_PORT8,
	IO_PORT9,
	IO_PORTA,
	IO_PORTB
} IO_PORT;

extern UB sil_reb_ddr(IO_PORT port) throw();
extern void sil_wrb_ddr(IO_PORT port, UB data) throw();
extern void sil_anb_ddr(IO_PORT port, UB data) throw();
extern void sil_orb_ddr(IO_PORT port, UB data) throw();

#endif /* _MACRO_ONLY */
#endif  /*  _SIL_H8_H_  */
