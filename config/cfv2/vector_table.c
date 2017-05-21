/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
 *  Copyright (C) 2008 by Takahisa Yokota
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
 *  @(#) $Id: vector_table.c,v 1.3 2005/07/06 00:45:07 honda Exp $
 */

/*
 *	�㳰�٥����������COLDFIRE�ѡ�
 */

#include "jsp_kernel.h"


#ifdef KERNEL_HAS_A_VECTOR_TABLE

static VP _current_vbr = EXCVT_ORIG;

extern void start(void);		/*  start.S  */
extern void no_reg_exception(void);	/*  cpu_support.S  */

VP
current_vbr()
{
        return _current_vbr;
}

void
set_vbr(VP vbr)
{
        _current_vbr = vbr;
	Asm("movec %0, %%vbr" : : "r"(vbr));
}

FP vector_table [192] = {
	(FP)INIT_STACK,		/*   0:�����å��ݥ��󥿤ν����  */
        RESET_VECTOR,		/*   1:�ѥ����ꥻ�å�  */
	ACC_VECTOR,		/*   2:�����������顼      */
  	ADD_VECTOR,		/*   3:���ɥ쥹���顼      */
  	II_VECTOR,		/*   4:��������̿��        */
	RESERVED_VECTOR,	/*   5:d zero              */
	RESERVED_VECTOR,        /*   6:ͽ��                */
        II_VECTOR,              /*   7:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*   8:pv�����ƥ�ͽ��        */
        RESERVED_VECTOR,        /*   9:trace               */
	RESERVED_VECTOR,	/*  10:line a emulator     */
	RESERVED_VECTOR,	/*  11:line f emulator     */
	RESERVED_VECTOR,	/*  12:�����ƥ�ͽ��        */
        RESERVED_VECTOR,        /*  13:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*  14:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*  15:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*  16:�����ƥ�ͽ��        */
        RESERVED_VECTOR,        /*  17:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*  18:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*  19:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*  20:�����ƥ�ͽ��        */
        RESERVED_VECTOR,        /*  21:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*  22:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*  23:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*  24:���ץꥢ��������  */
				/*  �Ĥ�ϥǥե���Ȥ��㳰����  */
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
};

#endif /* KERNEL_HAS_A_VECTOR_TABLE */

