;
;   TOPPERS/JSP Kernel
;       Toyohashi Open Platform for Embedded Real-Time Systems/
;       Just Standard Profile Kernel
;
;   Copyright (C) 2006-2010 by Witz Corporation, JAPAN
;  
;   The above copyright holders grant permission gratis to use,
;   duplicate, modify, or redistribute (hereafter called use) this
;   software (including the one made by modifying this software),
;   provided that the following four conditions (1) through (4) are
;   satisfied.
;  
;   (1) When this software is used in the form of source code, the above
;       copyright notice, this use conditions, and the disclaimer shown
;       below must be retained in the source code without modification.
;  
;   (2) When this software is redistributed in the forms usable for the
;       development of other software, such as in library form, the above
;       copyright notice, this use conditions, and the disclaimer shown
;       below must be shown without modification in the document provided
;       with the redistributed software, such as the user manual.
;  
;   (3) When this software is redistributed in the forms unusable for the
;       development of other software, such as the case when the software
;       is embedded in a piece of equipment, either of the following two
;       conditions must be satisfied:
;  
;     (a) The above copyright notice, this use conditions, and the
;            disclaimer shown below must be shown without modification in
;         the document provided with the redistributed software, such as
;         the user manual.
;  
;     (b) How the software is to be redistributed must be reported to the
;         TOPPERS Project according to the procedure described
;         separately.
;  
;   (4) The above copyright holders and the TOPPERS Project are exempt
;       from responsibility for any type of damage directly or indirectly
;       caused from the use of this software and are indemnified by any
;       users or end users of this software from any and all causes of
;       action whatsoever.
;  
;   THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
;   THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
;   INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
;   PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
;   TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
;   INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
;
;   �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ������������˸¤ꡤ�ܥ��եȥ���
;   �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�
;   �����ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
;   (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭�����
;       ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ�����
;       ��������˴ޤޤ�Ƥ��뤳�ȡ�
;   (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻���
;       �Ǥ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ����Ѽԥ�
;       �˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ�����̵��
;       �ڵ����Ǻܤ��뤳�ȡ�
;   (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻���
;       �Ǥ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ������������ȡ�
;     (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
;         ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
;     (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ���
;         �𤹤뤳�ȡ�
;   (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»��
;       ����⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ��ޤ���
;       �ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���ͳ�˴��
;       �����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
;  
;   �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ���
;   ��TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū���Ф�
;   ��Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ�����������
;   �ˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ����
;   ��ʤ���
;  
;   @(#) $Id: cpu_support.app,v 1.1 2006/04/10 08:19:25 honda Exp $
;

	$MAXIMUM
	module cpu_support_app

;
;	�ץ��å���¸�⥸�塼�� ������֥��������TLCS-900L1�ѡ�
;

#define	SUPPORT_CHG_IPM
#include "jsp_rename.h"
#include "cpu_rename.h"
#include "sys_rename.h"
#include "offset.inc"

; �������ȥ���ܥ����
	extern large	__StackTop
	extern large	_reqflg
	extern large	_enadsp
	extern large	_intcnt
	extern large	_runtsk
	extern large	_schedtsk
	extern large	_call_texrtn
	extern large	_task_intmask


f_code section code large align=1,1

;
;	�������ǥ����ѥå���
;
;   dispatch �ϡ�����������ƥ����Ⱦ��֡�����߶ػ߾��֤ǸƤӽФ��ʤ�
;   ��Фʤ�ʤ���exit_and_dispatch �⡤����������ƥ����Ⱦ��֡����
;   �߶ػ߾��֤ǸƤӽФ��Τ���§�Ǥ��뤬�������ͥ뵯ư�����б����뤿�ᡤ
;   ����ߥ���ƥ����Ⱦ��֤ǸƤӽФ������ˤ��б����Ƥ��롥
;	�ƤӽФ����: SR��IFF=7 (����߶ػ߾���),
;				  intcnt = 0(����������ƥ�����), �����������å�
;
	public _dispatch

_dispatch:
	push	xiz			; �ؿ��ƽФ��ݸɬ�פʥ쥸��������¸
	ld		xwa, (_runtsk)	; ư���楿������TCB�����
	ld		(xwa+TCB_sp), xsp	;
	lda		xhl, dispatch_r	;
	ld		(xwa+TCB_pc), xhl	;
	jr		dispatcher	;

;
;	�ƤӽФ����: SR��IFF=7 (����߶ػ߾���),
;				  intcnt = 0(����������ƥ�����), �����������å�
;
;	xwa �ˤ�runtsk �Υ��ɥ쥹����Ǽ����Ƥ���
;
dispatch_r:
	pop		xiz		;
	ld		bc, (xwa+TCB_enatex)	;
	bit		TCB_enatex_bit, bc	;
	jr		z, dispatch_r_1	; enatex �� FALSE �ʤ�꥿����
	cpw		(xwa+TCB_texptn), 0	; �������㳰�װ���������
	jp		nz, _call_texrtn	;
	; call_texrtn����ľ��dispatch �ƤӽФ��������.
dispatch_r_1:				; �������㳰��¹Ԥ��ʤ����
	ret				; dispatch �ƤӽФ��������.

;
;	��������ư������
;
;	�����Ǥ�, CPU��å�������֤ˤ�, ��������ư����.
;
;	�ƤӽФ����: SR��IFF=7 (����߶ػ߾���),
;				  intcnt = 0(����������ƥ�����), �����������å�
;
	public _activate_r

_activate_r:
	pop		xhl		; �������ε�ư���Ϥ�whl ������
#ifdef SUPPORT_CHG_IPM			/* t_unlock_cpu �����ν��� */
	push	sr			; ����ߥޥ����� task_intmask ������
	ld		wa, (_task_intmask)	;
	andw	(xsp), ~0x7000	;
	or		(xsp), wa	;
	pop		sr			;
#else /* SUPPORT_CHG_IPM */
	ei		0		; ����ߵ���
#endif /* SUPPORT_CHG_IPM */
	jp		xhl

;
;	dispatcher�ƤӽФ����:
;		�����٤ƤΥ������Υ���ƥ����Ȥ���¸����Ƥ���.
;		��SR��IFF=7 (����߶ػ߾���)
;		������ƥ����Ȥϥ���������ƥ�����(intcnt=0)
;	dispatcher �ƽл��Υ����å�:
;		dispatch ���餭�����: �����������å�
;		exit_and_dispatch ���餭�����: 
;			exit_task ���餭�����ϥ����������å�
;			�����ͥ뵯ư���ϳ���ߥ����å�
;		ret_int ���餭�����: �����������å�
;		dispatcher_2 �Ǥγ�����Ԥ����餭�����: ����ߥ����å�
;
	public _exit_and_dispatch

_exit_and_dispatch:
	ldw		(_intcnt), 0	; �ͥ��ȥ����󥿥��ꥢ(����������ƥ�����)
dispatcher:
	ld		xwa, (_schedtsk)	; schedtsk �� runtsk ������
	ld		(_runtsk), xwa	;
	or		xwa, xwa		; �¹Ԥ��륿������̵����Х����ɥ�롼�פ�
	jr		z, pre_idle_loop	;
	ld		xsp, (xwa+TCB_sp)	; �����������å��ݥ��󥿤�����
	ld		xhl, (xwa+TCB_pc)	;
	jp		xhl			; �¹ԺƳ����Ϥإ�����
;
;	�¹Ԥ��٤��������������ޤ��ԤĽ���
;
pre_idle_loop:
	ld		xsp, __StackTop ; ������ѤΥ����å������ؤ�
	incw	1, (_intcnt)	; �󥿥�������ƥ�����
;
;	�������󥿥�������ƥ�����,����ߥ����å����ڤ괹�����Τ�,
;	������ȯ���������߽����ˤɤΥ����å���Ȥ����Ȥ�������β���,
;	����ߥϥ�ɥ���ǤΥǥ����ѥå��ɻߤȤ���2�Ĥΰ�̣�����롥
;
idle_loop:
#ifdef SUPPORT_CHG_IPM			/* t_unlock_cpu �����ν��� */
	push	sr			; ����ߥޥ����� task_intmask ������
	ld		wa, (_task_intmask)	;
	andw	(xsp), ~0x7000	;
	or		(xsp), wa	;
	pop		sr			;
#else /* SUPPORT_CHG_IPM */
	ei		0		; ����ߵ���
#endif /* SUPPORT_CHG_IPM */

	halt 		; IDLE2���֤�����
	nop			; �嵭halt�򥳥���(nop�Τ�)�ˤ����
	nop			; �����ư���Ԥ�ʤ������ɥ�롼�פȤʤ�.
	nop			; 
	nop			; 
	ei		7			; ����߶ػ�
	cpw		(_reqflg), 0	; reqflg �� FALSE �Ǥ����
	jr		z, idle_loop	;         idle_loop ��
	ldw		(_reqflg), 0	; reqflg <--- FALSE
	decw		1, (_intcnt)	; ����������ƥ����Ȥ��᤹
	jr		dispatcher		; dispatcher �����

;
;  �ٱ�ǥ����ѥå�����
;
;	�ƤӽФ����: SR��IFF=7 (����߶ػ߾���),
;				  intcnt = 0(����������ƥ�����), �����������å�
;				  reqflg = TRUE
;				  INTNEST�쥸���� = 1
;
ret_int:
	ldw		(_reqflg), 0	; reqflg <--- FALSE
	ld		de, 0	;
	ldc		intnest, de	; �ǥ����ѥå�������intnest ��0
	push	xiz			; �ؿ��ƽФ��ݸɬ�פʥ쥸��������¸
	ld		xwa, (_runtsk)	; runtsk �����
	cpw		(_enadsp), 0	; enadsp �� FALSE �ʤ�
	jr		z, ret_int_r	; ret_int_r ��
	cp		xwa, (_schedtsk)	; runtsk ��schedtsk ��Ʊ���ʤ�
	jr		z, ret_int_r	; ret_int_r ��
	or		xwa, xwa	; runtsk = NULL �ʤ�
	jr		z, dispatcher	; ��¸����dispather ��
	ld		(xwa+TCB_sp), xsp	;
	lda		xhl, ret_int_r	;
	ld		(xwa+TCB_pc), xhl	;
	jr		dispatcher	;

;
;	�ƤӽФ����: SR��IFF=7 (����߶ػ߾���),
;				  intcnt = 0(����������ƥ�����), �����������å�
;				  INTNEST�쥸���� = 0
;
;	xwa �ˤ�runtsk �Υ��ɥ쥹����Ǽ����Ƥ���
;
ret_int_r:
	pop		xiz
#ifdef SUPPORT_CHG_IPM		/* �����å��ˤ���SR ��IFF ����� */
	ld		de, (_task_intmask)	;
	andw	(xsp+24), ~0x7000	;
	or		(xsp+24), de	;
#endif /* SUPPORT_CHG_IPM */
	ld		bc, (xwa+TCB_enatex)	;
	bit		TCB_enatex_bit, bc	;
	jr		z, nest_ctrl_r	; enatex �� FALSE �ʤ�꥿����
	cpw		(xwa+TCB_texptn), 0	; �������㳰�װ���������
	call	nz, _call_texrtn	;
nest_ctrl_r:
	ld		de, 1	;
	ldc		intnest, de	; reti�Ѥ˵���Ū��intnest ��1
	jr		interrupt_r

;
;	�����/CPU�㳰�ζ��̽���
;
;	�ƽФ����:
;	��SR��IFF=7.
;	�������å���¿�ų����ߤʤ����ߥ����å�, �����Ǥʤ����
;	  �����������å�
;	��XHL �ˤϳ����/CPU�㳰�ϥ�ɥ�Υ��ɥ쥹����Ǽ����Ƥ���.
;	��AW �ˤ��ܳ���ߤ�ͥ���٤����ꤵ�줿 SR ����Ǽ����Ƥ���.
;
;	�쥸�����������å���ˤɤΤ褦����¸����Ƥ��뤫��ʲ��˼���.
;	���οޤǤϾ夬���, ������̤Υ��ɥ쥹��, �����å��ϲ�����
;	�������˸����ä��Ѥ߾夲�����ΤȤ���.
;
;	--------------------------------------
;	|        CPU�㳰�ϥ�ɥ�ΰ���       |
;	|          CPU�㳰����(4byte)        |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XSP(4byte)             | �����������å��ݥ��󥿡�
;	|             �����ʤΤ�             | ���ʤγ���ߤΤ��ݻ�����롥
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XIY(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XIX(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XDE(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XBC(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	-------------------------------------- <-- ���������������ǽ�������롥
;	|             XHL(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XAW(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	-------------------------------------- <-- �����ȯ�����˥ϡ��ɥ�����
;	|              SR(2byte)             |     �ˤƽ�������롥 p_excinf��
;	|                                    |     ������ؤ��褦�˱黻���롥
;	--------------------------------------
;	|              PC(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;
;	�ϥ�ɥ餫��꥿���󤷤����, ¿�ų���ߤǤʤ�, ���� reqflg ��
;	TRUE �ˤʤä����ˡ�ret_int ��ʬ�����롥
;
;	¿�ų���ߤ��ɤ����ϳ���ߥͥ��ȥ����󥿤��ͤ�Ƚ�ꤹ��.
;	intcnt != 0 �ʤ��¿�ų���ߤǤ����Ƚ�ꤹ��.
;	�ʤ����ϡ��ɥ��������;塤�����ȯ���������߶ػߤ�Ԥ��ޤǤδ֤�
;	¿�ų���ߤ�ȯ������ȡ�¿�ų���ߤǤ��뤳�Ȥ򥽥եȥ������Ǹ��Τ�
;	���ʤ����ᡤ�ǽ��ȯ����������߽�����¹Ԥ��ʤ��ޤޥ������ǥ���
;	�ѥå������ǽ�������롥����¿�ų���ߤ��Τ��뤿��˥ϡ��ɥ�����
;	INTNEST �쥸���������Ѥ��롥
;
;	reqflg ��CPU��å����֤ǥ����å�����. �����Ǥʤ��ȡ�
;	reqflg �����å���˵�ư���줿����ߥϥ�ɥ����
;	�ǥ����ѥå����׵ᤵ�줿���ˡ��ǥ����ѥå�����ʤ�.
;
	public _interrupt

_interrupt:
	push	xbc			; ������å��쥸�����λĤ����¸
	push	xde			;
	push	xix			;
	push	xiy			;

	ld		xbc, xsp	; CPU�㳰��������˻��Ѥ��뤿�ᤳ���Ǽ���
	cpw		(_intcnt), 0	;
	jr		nz, from_int	;
	ld		xsp, __StackTop ; ���ʤγ���ߤξ�祹���å����ڤ��ؤ�
	push	xbc			; ������SP���ݻ�
from_int:				;
	incw	1, (_intcnt)	; ����ߥͥ��ȥ�����Ȥ򥤥󥯥����

	add		xbc, 24	; CPU�㳰�����������
	push	xbc			; ����߽����Ǥ�̤����
	push	wa			;
	pop		sr			; �ܳ���ߤ��ͥ���٤ι⤤����ߵ���
	call	xhl			; ����ߥϥ�ɥ�/CPU�㳰������ƤӽФ�
	ei		7			; ����߶ػ�
	pop		xbc			; �����å�����碌(CPU�㳰�������)

	decw	1, (_intcnt)	; ����ߥͥ��ȥ�����Ȥ�ǥ������
	jr		nz, from_int_r	;
	pop		xbc			; ���ʤγ���ߤξ�祿����SP������
	ld		xsp, xbc	;
	ldc		de, intnest	; �����ȯ���������߶ػߤޤǤδ֤�¿�ų���ߤ�
	djnz	de, from_int_r	; ȯ�����Ƥ�����ϥǥ����ѥå����ʤ�
	cpw		(_reqflg), 0	; reqflg �� TRUE �Ǥ����
	jp		nz, ret_int	;              ret_int ��
from_int_r:		;
interrupt_r:	;
	pop		xiy	;������å��쥸����������
	pop		xix	;
	pop		xde	;
	pop		xbc	;
	pop		xhl	;
	pop		xwa	;
	reti	;

;
; ̤���ѳ���ߤν���
;
	public unused_interrupt

unused_interrupt:
	reti


	end


