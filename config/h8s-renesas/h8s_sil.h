/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

#ifndef _H8S_SIL_H_
#define _H8S_SIL_H_

#ifndef _MACRO_ONLY
#include <sil.h>
#endif /* _MACRO_ONLY */

/*
 *  H8S�����쥸�����������������󥿥ե�����
 *�����١������ɥ쥹H8S_BASE_ADDR��h8s.h���������
 *����CPUư��⡼�ɤˤ�ꡢ�Ȥ�ʬ���롣
 */

/*
 *  �١������ɥ쥹�βû�
 *����UH�ǥ��㥹�Ȥ��Ƥ���Τϡ����Ĥΰ�̣�����롣
 *������������16�ӥåȤ���Ф�
 *���������û��κݤ�����ĥ���ɤ�
 */
#define ADD_BASE_ADDR(addr)	(VP)(H8S_BASE_ADDR + (UW)(UH)(addr))

/*  �쥸�����ؤΥ�������  */
#define h8s_reb_reg(addr)	sil_reb_mem(ADD_BASE_ADDR(addr) )
#define h8s_wrb_reg(addr, val)	sil_wrb_mem(ADD_BASE_ADDR(addr), (VB)(val))

#define h8s_reh_reg(addr)	sil_reh_mem(ADD_BASE_ADDR(addr) )
#define h8s_wrh_reg(addr, val)	sil_wrh_mem(ADD_BASE_ADDR(addr), (VH)(val))

/*
 *  �����黻
 */
#define h8s_orb_reg(addr, val)	h8s_wrb_reg(addr, h8s_reb_reg(addr) | (val))
#define h8s_andb_reg(addr, val) h8s_wrb_reg(addr, h8s_reb_reg(addr) & (val))

#define h8s_orh_reg(addr, val)	h8s_wrh_reg(addr, h8s_reh_reg(addr) | (val))
#define h8s_andh_reg(addr, val)	h8s_wrh_reg(addr, h8s_reh_reg(addr) & (val))

#endif /* _H8S_SIL_H_ */
