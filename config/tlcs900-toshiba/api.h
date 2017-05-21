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
 *  @(#) $Id: api.h,v 1.1 2006/04/10 08:19:25 honda Exp $
 */

#ifndef API_H
#define API_H

#define __cycini
#define __cycenq
#define __sta_cyc
#define __stp_cyc
#define __cyccal
#define __dtqini
#define __dtqenq
#define __dtqfenq
#define __dtqdeq
#define __dtqsnd
#define __dtqrcv
#define __snd_dtq
#define __psnd_dtq
#define __ipsnd_dtq
#define __tsnd_dtq
#define __fsnd_dtq
#define __ifsnd_dtq
#define __rcv_dtq
#define __prcv_dtq
#define __trcv_dtq
#define __flgini
#define __flgcnd
#define __set_flg
#define __iset_flg
#define __clr_flg
#define __wai_flg
#define __pol_flg
#define __twai_flg
#define __excini
#define __vxsns_ctx
#define __vxsns_loc
#define __vxsns_dsp
#define __vxsns_dpn
#define __vxsns_tex
#define __inhini
#define __mbxini
#define __snd_mbx
#define __rcv_mbx
#define __prcv_mbx
#define __trcv_mbx
#define __mpfini
#define __mpfget
#define __get_mpf
#define __pget_mpf
#define __tget_mpf
#define __rel_mpf
#define __semini
#define __sig_sem
#define __isig_sem
#define __wai_sem
#define __pol_sem
#define __twai_sem
#define __rot_rdq
#define __irot_rdq
#define __get_tid
#define __iget_tid
#define __loc_cpu
#define __iloc_cpu
#define __unl_cpu
#define __iunl_cpu
#define __dis_dsp
#define __ena_dsp
#define __sns_ctx
#define __sns_loc
#define __sns_dsp
#define __sns_dpn
#define __logini
#define __vwri_log
#define __vrea_log
#define __vmsk_log
#define __logter
#define __tskini
#define __tsksched
#define __tskrun
#define __tsknrun
#define __tskdmt
#define __tskact
#define __tskext
#define __tskpri
#define __tskrot
#define __tsktex
#define __ras_tex
#define __iras_tex
#define __dis_tex
#define __ena_tex
#define __sns_tex
#define __act_tsk
#define __iact_tsk
#define __can_act
#define __ext_tsk
#define __ter_tsk
#define __chg_pri
#define __get_pri
#define __slp_tsk
#define __tslp_tsk
#define __wup_tsk
#define __iwup_tsk
#define __can_wup
#define __rel_wai
#define __irel_wai
#define __sus_tsk
#define __rsm_tsk
#define __frsm_tsk
#define __dly_tsk
#define __tmeini
#define __tmeup
#define __tmedown
#define __tmeins
#define __tmedel
#define __isig_tim
#define __set_tim
#define __get_tim
#define __vxget_tim
#define __waimake
#define __waicmp
#define __waitmo
#define __waitmook
#define __waican
#define __wairel
#define __wobjwai
#define __wobjwaitmo
#define __wobjpri


#endif

