/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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

#ifndef _KZ_VR4131PCI_01_
#define _KZ_VR4131PCI_01_

#define KZ_VR4131PCI_01

/*
 *  �ǥХ����γ�����ƥ١������ɥ쥹
 */

#define VR4131_BASE_ADDR	0xa0000000

/*
 *  �ǥХ����˶��뤵��륯��å�
 */
/*
 *  VR4131 �ϵ�ư���� CLKSEL(2:0) ü�Ҥ򸫤ơ��ѥ��ץ饤�󥯥�å�PClock��
 *  ���ꤹ�롣����Υ������åȥܡ��ɤΥǥե���Ȥϡ�
 *        CLKSEL(2:0) = 110
 *  �ѥ�ޥͥ����ȥ�˥åȤΡ�PMUTCLKDIVREG���ѹ��ϲä��ʤ����᲼���Ȥʤ롣
 *        PClock 199.1[MHz], VTClock 33.2[MHz], TClock 16.6[MHz]
 */
/* ���ꥢ��˶��뤵��륯��å����ȿ� [Hz]�ʥܡ��졼������ǻ��ѡ�
 * ��18.432MHz = 18432000 Hz ; �ϡ��ɥ�������p193���ȡ� */
#define XIN_CLOCK	18432000u	/* [Hz] */

/* �����ޤ˶��뤵��륯��å����ȿ� [kHz]��TO_CLOCK�ǻ��ѡ�
 * ��TO_CLOCK ��1�ߥ��ü���(1kHz)��ȯ�������뤿��˻��ѡ�
 * ��VTClock=33.2MHz = 33200kHz ; �ϡ��ɥ�������p22���ȡ� */
#define TIMER_CLOCK	33200u	/* [kHz] */

/*
 *  �ǥХ����γ���ߥޥ��������
 *
 *  ͥ���� : (��) DSIU -> TClock������ -> �Хåƥ������­���� (��)
 */
/* MSYSINT1 �� BATINTR ������ˤĤ��Ƥϡ��ϡ��ɥ�������p224����  */

/*
 *  DSIU ����ߤγ���ߥޥ��������������ѡ�
 *  ������ߥ�٥�������������Ʊ����٥�����ꤷ�Ƥ���
 */
#define CORE_IPM_DSIU		INIT_CORE_IPM	/* MIPS3����(SR)�ѥǡ��� */

/* BATINTR��TCLKINTR ����ߤΤߤ���Ĥ��롣 */
#define ICU_IPM_SYSINT1_DSIU	BATINTR		/* ����ߥ���ȥ����ѥǡ��� */
#define ICU_IPM_SYSINT2_DSIU	TCLKINTR

/*  ���ꤹ�����ߥޥ�����IPM���ǵ��Ҥ���� */
#define IPM_DSIU	{ CORE_IPM_DSIU, {ICU_IPM_SYSINT1_DSIU, ICU_IPM_SYSINT2_DSIU} }

/*
 *  RTC ��Ϣ�γ���ߥޥ���
 */
#define CORE_IPM_TIMER		INIT_CORE_IPM	/* MIPS3����(SR)�ѥǡ��� */

/* BATINTR ����ߤΤߤ���Ĥ��롣 */
#define ICU_IPM_SYSINT1_TCLK	BATINTR		/* ����ߥ���ȥ����ѥǡ��� */
#define ICU_IPM_SYSINT2_TCLK	0u

/*  ���ꤹ�����ߥޥ�����IPM���ǵ��Ҥ���� */
#define IPM_TIMER	{ CORE_IPM_TIMER, {ICU_IPM_SYSINT1_TCLK, ICU_IPM_SYSINT2_TCLK} }

#endif /* _KZ_VR4131PCI_01_ */
