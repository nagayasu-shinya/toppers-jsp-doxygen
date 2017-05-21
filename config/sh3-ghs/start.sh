/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                                  Toyohashi Univ. of Technology, JAPAN
 *                     2003        by Advanced Data Controls, Corp
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
 *  @(#) $Id: start.sh,v 1.3 2003/12/19 11:24:55 honda Exp $
 */
        
/*
 *  �����ͥ��ѤΥ������ȥ��åץ⥸�塼��
 */               
#define _MACRO_ONLY
#include <t_config.h>
#include <sys_defs.h>

/*GHS������֥鵼��̿���Ѵ�*/
#define   long   data.l

/*
 *   SH3�ѥ������ȥ��åץ⥸�塼��
 *   �����ͥ�ϥ��ץꥱ�������ȥ�󥯤��ƻ��Ѥ���
 *   �����ʤΤ�JSP�����ͥ�Τ߻��Ѥ��롣	
 */
	.global	_start
	.global _main
	.align 2
_main:
_start:
	/*
	 *  ����å���ν����
	 */
	mov.l _ccr_addr,r1
	mov.l _ccr_disable,r2
	mov.l r2,@r1
	mov.l _ccr_mode,r2
	mov.l r2,@r1

	/*
	 *  SR���������롣
	 *  MD=1, RB=0, BL=0, I3��I0=e f��stub�Τ�
	 */
	mov.l _init_sr,r0
	ldc   r0,sr
	mov   #0x01,r0
	ldc   r0,r7_bank
	/*
	 * ��������Ω�Υ����å���STACKTOP�˽��������
	 * STACKTOP�ϡ�sys_config.h�����
	 */
	mov.l  _stack_k, r15

	/*
	 *  _hardware_init_hook ��ƤӽФ���(0�Ǥʤ����)
	 *
	 *  �ϡ��ɥ�������¸��ɬ�פʽ����������������ϡ�
	 *  hardware_init_hook �Ȥ����ؿ����Ѱդ���Ф褤��
	 *  ����Ū�ˤ�ROM���κݡ�RAM����Ѳ�ǽ�ˤ��뤿���
	 *  �Х�����ȥ���ν��������Ԥ���
	 *  sys_support.S ��� _hardware_init_hook ��������Ƥ�
	 *  �롥
	 */

start_0:
	mov.l  _hardware_init_hook_k, r0
	tst    r0,r0
	bt     start_5
	jsr    @r0
     	or      r0,r0

	/*
	 *  _software_init_hook ��ƤӽФ���0 �Ǥʤ����ˡ�
	 *
	 *  ���եȥ������Ķ����ä˥饤�֥��ˤ˰�¸����ɬ�פʽ������
	 *  ����������ϡ�software_init_hook �Ȥ����ؿ����Ѱդ����
	 *  �褤��
	 */
start_5:	
	mov.l  _software_init_hook_k, r0
	tst    r0,r0
	bt     start_6		
	jsr    @r0
	or     r0,r0

		
start_6:
	/*�����ͥ��ư����*/

	mov.l _kernel_start_k,r0
	jsr	  @r0
	or	   r0,r0


	.align 4
_ccr_addr:	
	.long CCR
_ccr_disable:	
	.long CCR_DISABLE
_ccr_mode:	
	.long CCR_MODE
_init_sr:	
	.long  0x40000000 + MAX_IPM << 4
_stack_k:	
	.long   STACKTOP
_kernel_start_k:	
	.long	_kernel_start
	.weak _hardware_init_hook
	.weak _software_init_hook
_hardware_init_hook_k:	
	.long   _hardware_init_hook
_software_init_hook_k:	
	.long   _software_init_hook	


















