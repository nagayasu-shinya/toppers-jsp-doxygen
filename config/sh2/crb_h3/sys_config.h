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
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id$
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���CRB_H3�ѡ�
 *���������������ͥ������ǻ��Ѥ������
 *�������������ǡ��������ޥ����ؿ��Υץ�ȥ��������
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �桼�����������
 */
#include <user_config.h>

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include <sys_rename.h>

/*
 *  �������åȥ����ƥ�Υϡ��ɥ������񸻤����
 */
#include "crb_h3.h"

/*
 *  ���ͥǡ���ʸ�����ѥޥ�������
 */
#include <util.h>

/*
 *  ��ư��å������Υ������åȥ����ƥ�̾
 */
#define	TARGET_NAME	"crb_h3"

/*
 *���󥿥�������ƥ������ѥ����å��ν����
 */
#define str_STACKTOP	TO_STRING(STACKTOP)

/*
 *  ���������Ԥ��Τ�������
 *  �������ϥ���å����ȿ��˰�¸���롣
 */
#define	SIL_DLY_TIM1	2286
#define	SIL_DLY_TIM2	1664

/*
 *  SIO�쥸����������
 */
#define DEFAULT_SPEED   38400
#define DEFAULT_SMR     0x00	/* Async, 8 bits, No parity, 1 stop bit, no MP, 1/1 */
#define DEFAULT_BRR		(CLOCK_RATE / 32 / DEFAULT_SPEED)

#ifndef _MACRO_ONLY

/*
 *  �������åȥ����ƥ��¸�ν����
 */
extern void	sys_initialize(void);

/*
 *  �������åȥ����ƥ�ν�λ
 *
 *  �����ƥ��λ������˻Ȥ���
 */
extern void	sys_exit(void);

/*
 *  �������åȥ����ƥ��ʸ������
 *
 *  �����ƥ�����٥��ʸ�����ϥ롼����
 */
extern void	sys_putc(char c) throw();

#endif /* _MACRO_ONLY */

/*
 *  �㳰�٥����ơ��֥��Ϣ�Υޥ������
 *  �����ޥ��������
 *  ������KERNEL_HAS_A_VECTOR_TABLE
 *  �������������ͥ뤬�㳰�٥����ơ��֥�����
 *  ������SIO_RESERVED
 *  �����������ꥢ��ǥХ������ǥХå��ˤ�äƻ��Ѥ���Ƥ���
 */
/*
 *  ROM���ξ��
 *  �����ꥻ�åȻ���ROM��ˤ����㳰�٥����ơ��֥�򻲾Ȥ���
 *  ����������塧RAM��ˤ����㳰�٥����ơ��֥�򻲾Ȥ���
 */
#define KERNEL_HAS_A_VECTOR_TABLE


#endif /* _SYS_CONFIG_H_ */
