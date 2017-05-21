/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: eventlog.h,v 1.7 2003/12/15 07:19:22 takayuki Exp $
 */


#ifndef __EVENTLOG_H__
#define __EVENTLOG_H__

#include <constants.h>

#include <stdarg.h>
#include "syslog.h"

	/*
	 *  ITRON�ǥХå��󥰥��󥿥ե�������Ϣ�����
	 */

	/*
	 *  �ǥ����ѥå�����
	 */
#define DSP_NORMAL		0;	//����������ƥ����Ȥ���Υǥ����ѥå�
#define DSP_NONTSKCTX	1;	//����߽��������CPU�㳰����Υǥ����ѥå� 

	typedef	W		BITMASK;
	typedef UINT	INHNO;

	/* ����ߥϥ�ɥ� */
	typedef struct t_rglog_interrupt{
		INHNO	inhno;	//����ߥϥ�ɥ��ֹ�
	} T_RGLOG_INTERRUPT;

	/* ����ߥ����ӥ��ϥ�ɥ�(̤����) */
	typedef struct t_rglog_isr {
		ID		isrid;	//����ߥ����ӥ��롼����ID
		INHNO	inhno;	//����ߥϥ�ɥ��ֹ�
	} T_RGLOG_ISR;

	/* �����।�٥�ȥϥ�ɥ� */
	typedef struct t_rglog_timerhdr {
		UINT	type;	//�����ޡ��μ���
		ID		hdrid;	//�����।�٥�ȥϥ�ɥ��ID
		VP_INT	exinf;	//��ĥ����
	} T_RGLOG_TIMERHDR;

	/* CPU�㳰�ϥ�ɥ� */
	typedef struct t_rglog_cupexc {
		ID		tskid;	//�оݤȤʤ륿����ID
	} T_RGLOG_CPUEXC;

	/* �������㳰�����롼���� */
	typedef struct t_rglog_tskexc {
		ID		tskid;	//�оݤȤʤ륿����ID
	} T_RGLOG_TSKEXC;

	/* �����������Ѳ� */
	typedef struct t_rglog_tskstat {
		ID		tskid;		//������ID
		STAT	tskstat;	//�����西��������
		STAT	tskwait;	//�Ԥ�����
		ID		wobjid;		//�Ԥ��оݤΥ��֥�������ID
	} T_RGLOG_TSKSTAT;

	/* �ǥ����ѥå��㳫�� */
	typedef struct t_rglog_dispatch_enter {
		ID		tskid;		//������ID
		UINT	disptype;	//�ǥ����ѥå�����
	} T_RGLOG_DISPATCH_ENTER;

	/* �ǥ����ѥå��㽪λ */
	typedef struct t_rglog_dispatch_leave {
		ID		tskid;		//������ID
	} T_RGLOG_DISPATCH_LEAVE;

	/* �����ӥ������� */
	typedef struct t_rglog_svc {
		FN		fncno;		//��ǽ������
		UINT	prmcnt;		//�ѥ�᡼����
		VP_INT	prmary[1];	//�ѥ�᡼��
	} T_RGLOG_SVC;

	/* �����ȡ�ʸ����ΤߤΥ��� */
	typedef struct t_rglog_comment {
		UINT	length;		//ʸ�����Ĺ��
		char	strtext[1];	//ʸ����(NULL��ü)-���Ǥ���
	} T_RGLOG_COMMENT;

	typedef struct t_rglog_header {
		UINT	logtype;
		SYSTIM	logtim;
		BITMASK	valid;
		UINT	bufsz;
	} T_RGLOG_HEADER;

	typedef union t_rglog_body
	{
		T_RGLOG_INTERRUPT		interrupt;
		T_RGLOG_ISR				isr;
		T_RGLOG_TIMERHDR		timerhdr;
		T_RGLOG_CPUEXC			cpuexc;
		T_RGLOG_TSKEXC			tskexc;
		T_RGLOG_TSKSTAT			tskstat;
		T_RGLOG_DISPATCH_ENTER	dispatch_enter;
		T_RGLOG_DISPATCH_LEAVE	dispatch_leave;
		T_RGLOG_SVC				svc;
		T_RGLOG_COMMENT			comment;
	} T_RGLOG_BODY;

	typedef struct DBIFLOG
	{
		struct	t_rglog_header	header;
		union	t_rglog_body	body;
	} DBIFLOG;

	typedef struct t_rglog
	{
		UINT	logtype;
		SYSTIM	logtim;
		BITMASK	valid;
		UINT	bufsz;
		char	buf[1];
	} T_RGLOG;

#ifdef EVENTLOG_ENABLE
#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN extern
#endif

		EXTERN void event_write_syslog(const SYSLOG * str);
		EXTERN void event_write(unsigned int logtype, unsigned int valid, UINT bufsz, ... );
		EXTERN void event_write_svc_enter(int fncd, unsigned int params, ... );
		EXTERN void event_write_svc_leave(int fncd, unsigned int ercd, unsigned int retaddr);
		EXTERN void event_write_wait_unknown(int tskid);

#undef EXTERN

#endif //EVENTLOG_ENABLE

#endif //__EVENTLOG_H__

