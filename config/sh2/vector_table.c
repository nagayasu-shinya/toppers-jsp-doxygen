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
 *	�㳰�٥����������SH1/2�ѡ�
 */

#include "jsp_kernel.h"

#ifdef KERNEL_HAS_A_VECTOR_TABLE

extern void start(void);		/*  start.S  */
extern void no_reg_exception(void);	/*  cpu_support.S  */

FP vector_table [] = {
	RESET_VECTOR,		/*   0:�ѥ����ꥻ�å�  */
	(FP)INIT_STACK,		/*     �����å��ݥ��󥿤ν����  */
	RESET_VECTOR,		/*   2:�ޥ˥奢��ꥻ�å�  */
	(FP)INIT_STACK,		/*     �����å��ݥ��󥿤ν����  */
	GII_VECTOR,		/*   4:��������̿��        */
	RESERVED_VECTOR,	/*   5:�����ƥ�ͽ��        */
	SII_VECTOR,		/*   6:����å�����̿��    */
	RESERVED_VECTOR,	/*   7:�����ƥ�ͽ��        */
	RESERVED_VECTOR,	/*   8:�����ƥ�ͽ��        */
	CAE_VECTOR,		/*   9:CPU���ɥ쥹���顼   */
	DAE_VECTOR,		/*  10:DMA���ɥ쥹���顼   */
	NMI_VECTOR,		/*  11:MNI                 */

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
	no_reg_exception
};

#endif /* KERNEL_HAS_A_VECTOR_TABLE */

