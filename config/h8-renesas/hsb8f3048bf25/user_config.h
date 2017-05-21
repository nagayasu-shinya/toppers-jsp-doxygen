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
 *  @(#) $Id: user_config.h,v 1.7 2007/03/23 07:58:33 honda Exp $
 */

#ifndef _USER_CONFIG_H_
#define _USER_CONFIG_H_

/*
 *  �桼����������ե�����졼������������
 */

/*
 *  chg_ipm�򥵥ݡ��Ȥ��뤫�ɤ��������
 *����������֥��Ѥ�user_config_asm.inc�ˤ�Ʊ�ͤ������ɬ�פʤΤ����
 */
#define SUPPORT_CHG_IPM

/*
 *  vxget_tim�򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define SUPPORT_VXGET_TIM

/*
 *  ����å����ȿ� [Hz]
 *������user_config_asm.inc�ˤ�Ʊ�ͤ������ɬ�פʤΤ����
 */
#define CPU_CLOCK               24576000ul


/*
 *  ���ꥢ��ݡ��Ȥ�����
 */

/*
 *  ���ݡ��Ȥ��륷�ꥢ��ǥХ����ο��ʺ��� 2��
 *����user_config_asm.inc�ˤ�Ʊ�ͤ������ɬ�פʤΤ����
 */
#define TNUM_PORT               1u

/*
 *  �ݡ����ֹ�
 *
 *  �������hw_serial.h��������٤�����������ץ�ץ���फ��
 *  �����Ȥ��뤿�ᡢ������������롣
 */
#define SCI_PORTID1				1		/*  �ѹ��ػ�  */
#define SCI_PORTID2				2		/*  Ʊ��  */

/*
 *  �ݡ����ֹ�γ������
 *
 *  ��E10T-USB�ǥǥХå���Ԥ��ݤˤϡ�SCI1����ͭ����뤿�ᡢ
 *  ���桼�����ץ�����SCI0�Τߤ���Ѥ��롣
 *
 *�����ݡ��ȿ����ΤȤ�
 *���������ܡ��ȣ�(SCI0)�������ƥ�ݡ��ȡʸ����
 *�����ݡ��ȿ����ΤȤ�
 *���������ܡ��ȣ�(SCI0)�������ƥ�ݡ��ȡ��桼�����ݡ��������ǽ
 *���������ܡ��ȣ�(SCI1)��Ʊ��
 */
#if TNUM_PORT == 1u

#define SYSTEM_PORTID           SCI_PORTID1		/*  ����  */

#elif TNUM_PORT == 2u    /* of #if TNUM_PORT == 1u */

#define SYSTEM_PORTID           SCI_PORTID1		/*  �򴹲�ǽ  */
#define USER_PORTID             SCI_PORTID2

#else   /* of #if TNUM_PORT == 1u || TNUM_PORT == 2u */

#error TNUM_PORT <= 2u

#endif  /* of #if TNUM_PORT == 1u */

/*
 *  ���٥���Ϥ��Ѥ��륷�ꥢ��ݡ��ȤΥݡ����ֹ�
 */
#define SCI_LOW_PORTID			SYSTEM_PORTID

/*  �ܡ��졼�Ȥȥץ饤����ƥ�����٥�  */
#define SCI_PORT1_BAUD_RATE     38400ul		/* �ܡ��졼�� [bps]     */
#define SCI_PORT1_IPM           IPM_LEVEL0	/* �ץ饤����ƥ���٥�  */

#if TNUM_PORT == 2u

#define SCI_PORT2_BAUD_RATE     38400ul		/* �ܡ��졼�� [bps]     */
#define SCI_PORT2_IPM           IPM_LEVEL0	/* �ץ饤����ƥ���٥�  */

#endif  /* of #if TNUM_PORT == 2u */


/*
 * ���顼�����ߤ����ϳ����ߤ��̤�������ϥ����Ȥ򳰤���
 *����user_config_asm.inc�ˤ�Ʊ�ͤ������ɬ�פʤΤ����
 */
#if 0
#define H8_CFG_SCI_ERR_HANDLER
#endif


/*
 *  �����ޤ�����
 */

/*
 *  ������ƥ��å������
 */

#define TIC_NUME        1u               /* ������ƥ��å��μ�����ʬ�� */
#define TIC_DENO        1u               /* ������ƥ��å��μ�����ʬ�� */

/*  �����ޤ˶��뤵��륯��å����ȿ� [kHz]  */
#define TIMER_CLOCK     ((CPU_CLOCK)/8000ul)     /* 8ʬ�� */

/*  �ץ饤����ƥ���٥�  */
#define SYSTEM_TIMER_IPM                IPM_LEVEL1


#endif /* _USER_CONFIG_H_ */
