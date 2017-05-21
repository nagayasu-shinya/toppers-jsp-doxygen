/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: user_config.h,v 1.2 2007/03/23 07:59:26 honda Exp $
 */

#ifndef _USER_CONFIG_H_
#define _USER_CONFIG_H_

/*
 *  �桼����������ե�����졼������������
 */

/*
 *  chg_ipm�򥵥ݡ��Ȥ��뤫�ɤ��������
 *����������֥��Ѥ�user_config.inc�ˤ�Ʊ�ͤ������ɬ�פʤΤ����
 */
#define SUPPORT_CHG_IPM

/*
 *  vxget_tim�򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define SUPPORT_VXGET_TIM

/*
 *  �����ͥ뤬�����������ߤκǹ�ͥ���٥�
 *���������ͥ�������γ���� �� ����ߥ�٥뤬MAX_IPM �ʲ��γ����
 *���������ͥ�������γ���� �� �ץ饤����ƥ���٥�(MAX_IPM+1)
 *�������������������������������ʾ�γ���ߤ�NMI
 *
 *������user_config.inc�ˤ�Ʊ�ͤ������ɬ�פʤΤ����
 */
#define MAX_IPM                 0x7u

/*
 *  ���ꥢ��ݡ��Ȥ�����
 */

/*
 *  ���ꥢ��ݡ��ȿ������
 * 
 *������γ�ĥ���Τ��ᡢ�ʲ��Τ褦��������Ƥ��뤬�����ߤμ����Ǥϼ¼�Ū��
 *���㤤�Ϥʤ���
 *
 * TNUM_PORT : ���ꥢ��ɥ饤�С�serial.c�ˡ��Ĥޤ� GDIC��٥�ǥ��ݡ��Ȥ���
 * ���������������ꥢ��ݡ��Ȥο� 
 * TNUM_SIOP : PDIC��٥�ʥץ��å���¢SIO�ˤǥ��ݡ��Ȥ��륷�ꥢ��I/O�ݡ���
 *������������ �ο��ʸ��ߤμ����ǤϺ���3��
 */

#define TNUM_PORT	3u
#define	TNUM_SIOP	3u	/*  ���ߤμ����ǤϺ���3  */

/*
 *  �����ƥॿ�����˴ؤ������
 */
#define	LOGTASK_PORTID	2	/* �����ƥ������Ϥ��륷�ꥢ��ݡ����ֹ� */

/*
 *  ���٥���ϡʥݡ���󥰽��ϡˤ��Ѥ��륷�ꥢ��ݡ����ֹ�
 */
#define	POL_PORTID	3

/*
 *  ���ꥢ�륳��ȥ���Υܡ��졼�Ȥ����� [bps]
 */
#define BAUD_RATE0	38400	/*  SCI0  */
#define BAUD_RATE1	38400	/*  SCI1  */
#define BAUD_RATE2	38400	/*  SCI2  */
#if 0
#define BAUD_RATE0	 9600
#define BAUD_RATE1	 9600
#define BAUD_RATE2	 9600
#define BAUD_RATE0	19200
#define BAUD_RATE1	19200
#define BAUD_RATE2	19200
#endif

/*
 *  �����ޤ�����
 */

/*
 *  ������ƥ��å������
 */

#define TIC_NUME        1u               /* ������ƥ��å��μ�����ʬ�� */
#define TIC_DENO        1u               /* ������ƥ��å��μ�����ʬ�� */


/*
 *  ����ߥ�٥����
 */
#define SCI0_INT_LVL	3u		/* SCI����ͥ�0�γ����ߥ�٥� */
#define SCI1_INT_LVL	3u		/* SCI����ͥ�1�γ����ߥ�٥� */
#define SCI2_INT_LVL	3u		/* SCI����ͥ�2�γ����ߥ�٥� */
#define TPU0_INT_LVL	5u		/* TPU����ͥ�0�γ����ߥ�٥� */

#endif /* _USER_CONFIG_H_ */
