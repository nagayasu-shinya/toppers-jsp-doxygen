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
 *  @(#) $Id: mpc860_sil.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

#include <sil.h>

/*
 *  MPC860��¢������쥸�����ؤΥ����������桼�ƥ���ƥ�
 *  
 *  powerpc.h�˵��Ҥ���Τ����쥬��Ȥ�����sil.h�ȤΥ��󥯥롼�ɤ�
 *  ���֤δط�����Ω�����ե�����Ȥ��롣
 *  t_config.h��ľ�ܥ��󥯥롼�ɤ����Ȥ���sil.h������powerpc.h��
 *  ���󥯥롼�ɤ�����ǽ�������롣
 *  
 *  ����ѥ���η������å���ǽ��ͭ���ˤ��뤿�ᡢ�ݥ��󥿷���
 *  VB *��VH *��VW *���Ѥ��Ƥ��롣
 *  
 */

#ifndef _MPC860_SIL_H_
#define _MPC860_SIL_H_

#ifndef _MACRO_ONLY

/*
 *  SIL��Ʊ���Υ��������ؿ��ʷ������å���ǽ�դ���
 */

#ifndef SIL_DEBUG

/*
 *  8�ӥå�ñ�̤��ɽФ��������
 */
Inline VB
mpc860_reb_mem(VB *mem)
{
	VB reg = sil_reb_mem((VP)mem);
	return(reg);
}

Inline void
mpc860_wrb_mem(VB *mem, VB data)
{
	sil_wrb_mem((VP)mem, data);
}

/*
 *  16�ӥå�ñ�̤��ɽФ��������
 */
Inline VH
mpc860_reh_mem(VH *mem)
{
	VH reg = sil_reh_mem((VP)mem);
	return(reg);
}

Inline void
mpc860_wrh_mem(VH *mem, VH data)
{
	sil_wrh_mem((VP)mem, data);
}

/*
 *  32�ӥå�ñ�̤��ɽФ��������
 */
Inline VW
mpc860_rew_mem(VW *mem)
{
	VW reg = sil_rew_mem((VP)mem);
	return(reg);
}

Inline void
mpc860_wrw_mem(VW *mem, VW data)
{
	sil_wrw_mem((VP)mem, data);
}



/*
 *  �ӥåȱ黻
 */

/*
 *  8�ӥåȥ쥸������AND�黻
 */
Inline void
mpc860_andb_mem(VB *mem, VB data)
{
	VB reg = mpc860_reb_mem((VP)mem);
	reg &= data;
	mpc860_wrb_mem(mem, reg);
}

/*
 *  8�ӥåȥ쥸������OR�黻
 */
Inline void
mpc860_orb_mem(VB *mem, VB data)
{
	VB reg = mpc860_reb_mem(mem);
	reg |= data;
	mpc860_wrb_mem(mem, reg);
}


/*
 *  16�ӥåȥ쥸������AND�黻
 */
Inline void
mpc860_andh_mem(VH *mem, VH data)
{
	VH reg = mpc860_reh_mem(mem);
	reg &= data;
	mpc860_wrh_mem(mem, reg);
}

/*
 *  16�ӥåȥ쥸������OR�黻
 */
Inline void
mpc860_orh_mem(VH *mem, VH data)
{
	VH reg = mpc860_reh_mem(mem);
	reg |= data;
	mpc860_wrh_mem(mem, reg);
}

/*
 *  32�ӥåȥ쥸������AND�黻
 */
Inline void
mpc860_andw_mem(VW *mem, VW data)
{
	VW reg = mpc860_rew_mem(mem);
	reg &= data;
	mpc860_wrw_mem(mem, reg);
}

/*
 *  32�ӥåȥ쥸������OR�黻
 */
Inline void
mpc860_orw_mem(VW *mem, VW data)
{
	VW reg = mpc860_rew_mem(mem);
	reg |= data;
	mpc860_wrw_mem(mem, reg);
}

#else	/*  SIL_DEBUG  */

extern UW sil_log_id;
extern BOOL sil_debug_on;

/*
 *  SIL�Υ����Ϥ������Ƥ�������٤����
 *����user.txt�Ρ�4.4 ������ν����١׻��ȡ�
 */
#ifndef LOG_SIL
#define LOG_SIL	LOG_EMERG
#endif	/*  LOG_SIL  */


/*
 *  8�ӥå�ñ�̤��ɽФ�
 */
#define mpc860_reb_mem(mem)	mpc860_reb_mem_deb(#mem, mem)

Inline VB
mpc860_reb_mem_deb(char *str, VB *mem)
{
	BOOL sil_debug_tmp, is_end_of_line;
	SYSUTIM sysutim;
	VB reg;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	reg = sil_reb_mem((VP)mem);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		is_end_of_line = (reg == '\n') || (reg == '\r');
		if (!is_end_of_line) {
			syslog(LOG_SIL, 
			"%d time:%08d read VB %s(0x%08x) data=0x%02x(%c)",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UB)reg, (UW)(UB)reg);
		} else {
			syslog(LOG_SIL, 
			"%d time:%08d read VB %s(0x%08x) data=0x%02x(%s)",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UB)reg, 
			(reg == '\n') ? "\\n" : "\\r");
		}
	}
	
	return(reg);
}


/*
 *  8�ӥå�ñ�̤ν񤭹���
 */
#define mpc860_wrb_mem(mem, data)	mpc860_wrb_mem_deb(#mem, mem, data)

Inline void
mpc860_wrb_mem_deb(char *str, VB *mem, VB data)
{
	BOOL sil_debug_tmp, is_end_of_line;
	SYSUTIM sysutim;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	sil_wrb_mem((VP)mem, data);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		is_end_of_line = (data == '\n') || (data == '\r');
		if (!is_end_of_line) {
			syslog(LOG_SIL, 
			"%d time:%08d write VB %s(0x%08x) data=0x%02x(%c)",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UB)data, (UW)(UB)data);
		} else {
			syslog(LOG_SIL, 
			"%d time:%08d write VB %s(0x%08x) data=0x%02x(%s)",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UB)data, 
			(data == '\n') ? "\\n" : "\\r");
		}
	}
}

/*
 *  16�ӥå�ñ�̤��ɽФ�
 */
#define mpc860_reh_mem(mem)	mpc860_reh_mem_deb(#mem, mem)

Inline VH
mpc860_reh_mem_deb(char *str, VH *mem)
{
	BOOL sil_debug_tmp;
	SYSUTIM sysutim;
	VH reg;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	reg = sil_reh_mem((VP)mem);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		syslog(LOG_SIL, 
			"%d time:%08d read VH %s(0x%08x) data=0x%04x",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UH)reg);
	}
	
	return(reg);
}

/*
 *  16�ӥå�ñ�̤ν񤭹���
 */
#define mpc860_wrh_mem(mem, data)	mpc860_wrh_mem_deb(#mem, mem, data)

Inline void
mpc860_wrh_mem_deb(char *str, VH *mem, VH data)
{
	BOOL sil_debug_tmp;
	SYSUTIM sysutim;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	sil_wrh_mem((VP)mem, data);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		syslog(LOG_SIL, 
			"%d time:%08d write VH %s(0x%08x) data=0x%04x",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UH)data);
	}
}


/*
 *  32�ӥå�ñ�̤��ɽФ�
 */
#define mpc860_rew_mem(mem)	mpc860_rew_mem_deb(#mem, mem)

Inline VW
mpc860_rew_mem_deb(char *str, VW *mem)
{
	BOOL sil_debug_tmp;
	SYSUTIM sysutim;
	VW reg;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	reg = sil_rew_mem((VP)mem);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		syslog(LOG_SIL, 
			"%d time:%08d read VW %s(0x%08x) data=0x%08x",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)reg);
	}
	
	return(reg);
}


/*
 *  32�ӥå�ñ�̤ν񤭹���
 */
#define mpc860_wrw_mem(mem, data)	mpc860_wrw_mem_deb(#mem, mem, data)

Inline void
mpc860_wrw_mem_deb(char *str, VW *mem, VW data)
{
	BOOL sil_debug_tmp;
	SYSUTIM sysutim;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	sil_wrw_mem((VP)mem, data);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		syslog(LOG_SIL, 
			"%d time:%08d write VW %s(0x%08x) data=0x%08x",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)data);
	}
}


/*
 *  �ӥåȱ黻
 */

/*
 *  8�ӥåȥ쥸������AND�黻
 */
#define mpc860_andb_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s & 0x%02x",	 		\
			#mem, (UW)(UB)data);			\
	}							\
	mpc860_andb_mem_deb(mem, data)

Inline void
mpc860_andb_mem_deb(VB *mem, VB data)
{
	VB reg = mpc860_reb_mem((VP)mem);
	reg &= data;
	mpc860_wrb_mem(mem, reg);
}

/*
 *  8�ӥåȥ쥸������OR�黻
 */
#define mpc860_orb_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s | 0x%02x",	 		\
			#mem, (UW)(UB)data);			\
	}							\
	mpc860_orb_mem_deb(mem, data)

Inline void
mpc860_orb_mem_deb(VB *mem, VB data)
{
	VB reg = mpc860_reb_mem(mem);
	reg |= data;
	mpc860_wrb_mem(mem, reg);
}


/*
 *  16�ӥåȥ쥸������AND�黻
 */
#define mpc860_andh_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s & 0x%04x",	 		\
			#mem, (UW)(UH)data);			\
	}							\
	mpc860_andh_mem_deb(mem, data)

Inline void
mpc860_andh_mem_deb(VH *mem, VH data)
{
	VH reg = mpc860_reh_mem(mem);
	reg &= data;
	mpc860_wrh_mem(mem, reg);
}

/*
 *  16�ӥåȥ쥸������OR�黻
 */
#define mpc860_orh_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s | 0x%04x",	 		\
			#mem, (UW)(UH)data);			\
	}							\
	mpc860_orh_mem_deb(mem, data)

Inline void
mpc860_orh_mem_deb(VH *mem, VH data)
{
	VH reg = mpc860_reh_mem(mem);
	reg |= data;
	mpc860_wrh_mem(mem, reg);
}

/*
 *  32�ӥåȥ쥸������AND�黻
 */
#define mpc860_andw_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s & 0x%08x",	 		\
			#mem, (UW)data);			\
	}							\
	mpc860_andw_mem_deb(mem, data)

Inline void
mpc860_andw_mem_deb(VW *mem, VW data)
{
	VW reg = mpc860_rew_mem(mem);
	reg &= data;
	mpc860_wrw_mem(mem, reg);
}

/*
 *  32�ӥåȥ쥸������OR�黻
 */
#define mpc860_orw_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s | 0x%08x",	 		\
			#mem, (UW)data);			\
	}							\
	mpc860_orw_mem_deb(mem, data)

Inline void
mpc860_orw_mem_deb(VW *mem, VW data)
{
	VW reg = mpc860_rew_mem(mem);
	reg |= data;
	mpc860_wrw_mem(mem, reg);
}


#endif	/*  SIL_DEBUG  */

/*
 *  CP���ޥ�ɤ�ȯ�Բ�ǽ�ˤʤ�ޤ��Ԥ�
 */
Inline void
mpc860_wait_ready_CP_command(void)
{
	UH cpcr;
    	do {
		cpcr = mpc860_reh_mem(CPCR);
    	} while(cpcr & CPCR_FLG); 
}	


/*
 *  CP���ޥ�ɤ�ȯ�Ԥ���
 *	����
 *	��UW opcode�����ޥ�ɼ���
 *	��UW ch_num������ͥ��ֹ�ʥǥХ����ֹ��
 */
Inline void
mpc860_CP_command(UW opcode, UW ch_num)
{
	UH cpcr;
	
	/*  ¾��CP���ޥ�ɽ�λ�Ԥ�  */
	mpc860_wait_ready_CP_command();
	
	/*  CP���ޥ��ȯ��  */
	cpcr = (UH)((opcode << 8) | (ch_num << 4) | CPCR_FLG);
    	mpc860_wrh_mem(CPCR, cpcr);

	/*  CP���ޥ�ɽ�λ�Ԥ�  */
	mpc860_wait_ready_CP_command();
    	
}



#endif /* _MACRO_ONLY */
#endif	/*  _MPC860_SIL_H_  */
/*  end of file  */
