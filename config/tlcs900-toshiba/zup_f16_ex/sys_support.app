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
;   @(#) $Id: sys_support.app,v 1.1 2006/04/10 08:19:25 honda Exp $
;

	$MAXIMUM
	module sys_support_app

;
;	�������åȥ����ƥ��¸�⥸�塼�� ������֥������
;	��Zup-F16��ĥ�ܡ����ѡ�
;

#include "jsp_rename.h"
#include "cpu_rename.h"
#include "sys_rename.h"
#include "tmp91cy22.h"

f_code section code large align=1,1

;
; �������åȥϡ��ɥ������˰�¸����ɬ�פʽ����������������
;
	public hardware_init_hook
hardware_init_hook:
; ư���å�����(��®����å�1ʬ����4���ܤ�1/2)��6.144*(1/1)*4*(1/2)=12.288��
	ldb		(TADR_SFR_SYSCR0), 0xa0
	ldb		(TADR_SFR_SYSCR1), 0x00
	ldb		(TADR_SFR_SYSCR2), 0x2c ; halt̿��ˤ�IDLE2������
	ldb		(TADR_SFR_DFMCR1), 0x0b
	ldb		(TADR_SFR_DFMCR0), 0x40
lockup:			; ��å����å��Ԥ�
	bit		5, (TADR_SFR_DFMCR0)
	jr		nz, lockup
	ldb		(TADR_SFR_DFMCR0), 0x80

; �������ɥ쥹����2̵��
	ldb		(TADR_SFR_B2CS), 0x00
; �������ɥ쥹����1ͭ��(1MByteSRAM)
	ldb		(TADR_SFR_P1CR), 0x00
	ldb		(TADR_SFR_P1FC), 0xff	; AD0��AD15�����
	ldb		(TADR_SFR_P2CR), 0xff
	ldb		(TADR_SFR_P2FC), 0x0f	; A16��A19�����(�Ĥ�ϥݡ���)
	ldb		(TADR_SFR_P2), 0xff
	ldb		(TADR_SFR_P3), 0x78
	ldb		(TADR_SFR_P3CR), 0x7f
	ldb		(TADR_SFR_P3FC), 0x07	; RD/WR/HWR�����
	ldb		(TADR_SFR_P4FC), 0x02	; CS1�����
	ldb		(TADR_SFR_P4CR), 0x0e
	ldb		(TADR_SFR_MSAR1), 0x10	; 0x00100000��
	ldb		(TADR_SFR_MAMR1), 0x3f	; 0x001fffff
	ldb		(TADR_SFR_B1CS), 0x83	; 0��������/16bitDataBus

; WDT���
	ldb		(TADR_SFR_WDMOD), 0x00
	ldb		(TADR_SFR_WDCR), 0xb1

	ret

;
;  ���������Ԥ�
;
	public _sil_dly_nse
_sil_dly_nse:
	ld	WA, (XSP+0x4)
	sub	WA, 3173
	ret	le
	nop
sil_dly_nse1:
	sub	WA, 732
	jr	gt, sil_dly_nse1
	ret


	end


