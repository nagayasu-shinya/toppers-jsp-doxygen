/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2010 by Witz Corporation, JAPAN
 * 
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 * 
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 * 
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 * 
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 * 
 *    (a) The above copyright notice, this use conditions, and the
 *           disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 * 
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 * 
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�
 *  �����ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭�����
 *      ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ�����
 *      ��������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ����Ѽԥ�
 *      �˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ�����̵��
 *      �ڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ���
 *        �𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»��
 *      ����⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ��ޤ���
 *      �ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���ͳ�˴��
 *      �����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ���
 *  ��TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū���Ф�
 *  ��Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ�����������
 *  �ˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ����
 *  ��ʤ���
 * 
 *  @(#) $Id: makeoffset.c,v 1.1 2006/04/10 08:19:25 honda Exp $
 */


/*
 *	offset.inc (�⤷���� offset.h) �ˤĤ���
 *
 *	  offset.inc �Ϲ�¤�Τ���������Ǥ���¤�Τ���Ƭ���鲿�Х����ܤ�
 *	¸�ߤ��뤫�Ȥ������Ȥ�, ����Υӥåȥե�����ɤ���Ƭ����
 *	���Х�����β��ӥå��ܤ�¸�ߤ��뤫, �Ȥ��������
 *	������֥����ե������Ϳ���뤿���¸�ߤ��Ƥ���.
 *
 *	  offset.inc �ե��������Ȥ�, ñ�ʤ륷��ܥ�����ե�����Ǥ���.
 *	����ܥ�Ȥ��äƤ�������륷��ܥ��̾�Τˤϥѥ����󤬤���,
 *	�礭��ʬ���Ƽ���3�����ʬ��Ǥ���.
 *
 *	<��¤��̾>_<����̾>	(��) TCB_sp, TCB_pc, TCB_enatex �ʤ�
 *	<��¤��̾>_<����̾>_bit	(��) TCB_enatex_bit �ʤ�
 *	<��¤��̾>_<����̾>_mask (��) TCB_enatex_mask �ʤ�
 *
 *	(��)
 *		TCB_texptn		equ		14
 *		TCB_sp			equ		20
 *		TCB_pc			equ		24
 *		TCB_enatex		equ		12
 *		TCB_enatex_bit	equ		14
 *		TCB_enatex_mask	equ		0x4000
 *
 *	  ���֤Ϥ������������Ǥ���¤�Τ���Ƭ���鲿�Х�����ˤ��뤫
 *	�Ȥ������Ȥ򼨤����ͤˤĤ����٥��̾��.
 *	  �����ܤ�����Υӥåȥե��������ΥӥåȤ�, ���̤��������
 *	���ӥå��ܤˤ��뤫�Ȥ������Ȥ򼨤����ͤˤĤ����٥��̾��. 
 *	0����Ϥޤ���ͤ�ɽ������. �ǤⲼ�̤ΥӥåȤ���0�ӥåȤǤ���.
 *	  �����ܤ���ۤɤ� <��¤��̾>_<����̾>_bit �Ȥ��Ϣ���뤬,
 *	����Υӥåȥե��������ΥӥåȤΥޥ����ͤ�̾��.
 *	*_bit �� *_mask ���ͤδ֤ˤϼ��δط�������.
 *		(*_mask) == (1 << *_bit)
 *	(��) TCB_enatex_bit �� 14 �λ�, TCB_enatex_mask �� 0x4000
 *
 *	  ���ʤߤ�TLCS-900L1��¸���μ����Ǥ�, ����ӥåȤΥ����å��ʤɤ�
 *	�ӥå�̿�ᥢ�ɥ�å��󥰤���Ѥ��Ƥ���Τ� *_mask �Ȥ�����٥��
 *	���Ѥ��Ƥ��ʤ�.
 */

#include "jsp_kernel.h"
#include "task.h"


void makeoffset(void);

void
makeoffset()
{
	Asm("; BEGIN TCB_texptn\n");
	(((TCB *)0)->texptn) |= (TEXPTN)1;
	Asm("; END");

	Asm("; BEGIN TCB_sp\n");
	(((TCB *)0)->tskctxb.xsp) = (VP)1;
	Asm("; END");

	Asm("; BEGIN TCB_pc\n");
	(((TCB *)0)->tskctxb.pc)();
	Asm("; END");

	Asm("; BEGIN TCB_enatex\n");
	(((TCB *)0)->enatex) = 1;
	Asm("; END");
}

