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

#ifndef _RTE_VR5500_CB_
#define _RTE_VR5500_CB_

#define RTE_VR5500_CB

/*
 *  �ǥХ����γ�����ƥ١������ɥ쥹
 */

/* ���ꥢ�륳��ȥ��� (TL16PIR552) */
#define UART_CH01	0xb9001000
#define UART_CH02	0xb9002000
#define PRINTER_PPCS	0xb9003000
#define PRINTER_ECPCS	0xb9004000

/* ������ (uPD71054) */
#define TIMER_BASE_ADDR	0xb9005000

/* ����ߥ���ȥ���(PIC) */
#define ICU_BASE_ADDR	0xb9000000

/*
 *  �ǥХ����˶��뤵��륯��å�
 */
/* ���ꥢ��˶��뤵��륯��å����ȿ� [Hz]�ʥܡ��졼������ǻ��ѡ�
 * ��16MHz = 16000000 Hz ; �ܡ��ɤΥޥ˥奢��p21���ȡ� */
#define XIN_CLOCK	16000000u

/* �����ޤ˶��뤵��륯��å����ȿ� [kHz]
 *��TO_CLOCK ��1�ߥ��ü���(1kHz)��ȯ�������뤿��˻��ѡ�
 * (2MHz = 2000kHz ; �ܡ��ɤΥޥ˥奢��p22����) */
#define TIMER_CLOCK	2000u

/*
 *  �ǥХ����γ���ߥޥ��������
 *
 *  ͥ���� : (��) ���ꥢ�룱 -> ���ꥢ�룰 -> �����ޣ� (��)
 */

/*
 *  ���ꥢ�룰����ߤγ���ߥޥ��������������ѡ�
 *  ������ߥ�٥�������������Ʊ����٥�����ꤷ�Ƥ���
 */
#define CORE_IPM_SCC		INIT_CORE_IPM	/* MIPS3����(SR)�ѥǡ��� */

#define ICU_IPM_INT0_SCC0	TIMER0		/* ����ߥ���ȥ����ѥǡ��� */
#define ICU_IPM_INT1_SCC0	0u

/*  ���ꤹ�����ߥޥ�����IPM���ǵ��Ҥ���� */
#define IPM_SCC0	{ CORE_IPM_SCC, {ICU_IPM_INT0_SCC0, ICU_IPM_INT1_SCC0} }

/*
 *  ���ꥢ�룱����ߤγ���ߥޥ��������������ѡ�
 *  ������ߥ�٥�������������Ʊ����٥�����ꤷ�Ƥ���
 *  ��MIPS3�����ѤΥǡ����ϡ�SCC0�ȶ���
 */
#define ICU_IPM_INT0_SCC1	(TIMER0 | SERIAL0) /* ����ߥ���ȥ����ѥǡ��� */
#define ICU_IPM_INT1_SCC1	0u

/*  ���ꤹ�����ߥޥ�����IPM���ǵ��Ҥ���� */
#define IPM_SCC1	{ CORE_IPM_SCC, {ICU_IPM_INT0_SCC1, ICU_IPM_INT1_SCC1} }

/*
 *  �����ޣ�����ߤγ���ߥޥ���
 *  �ܼ����Ǥϡ������޳���ߤ����ä��Ȥ��ϡ����Ƥγ�������ߤ�ػߤ��Ƥ��롣
 */
#define CORE_IPM_TIMER		INIT_CORE_IPM	/* MIPS3����(SR)�ѥǡ��� */

#define ICU_IPM_INT0_TIMER0	0u		/* ����ߥ���ȥ����ѥǡ��� */
#define ICU_IPM_INT1_TIMER0	0u

/*  ���ꤹ�����ߥޥ�����IPM���ǵ��Ҥ���� */
#define IPM_TIMER0	{ CORE_IPM_TIMER, {ICU_IPM_INT0_TIMER0, ICU_IPM_INT1_TIMER0} }

#endif /* _PIC_ICU_H_ */
