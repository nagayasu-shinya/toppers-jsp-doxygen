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
 *  @(#) $Id: sys_config.h,v 1.16 2007/03/23 07:22:15 honda Exp $
 */

/*
 *���������åȥ����ƥ��¸�⥸�塼��
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �����ͥ����������̾�Υ�͡���
 */

#include <sys_rename.h>

/*
 *  �������åȥ����ƥ�Υϡ��ɥ������񸻤����
 */
#include <h8.h>
#include <h8_3048f.h>

/*
 *  ��ư��å������Υ������å�̾
 */

#define	TARGET_NAME	"AKI-H8/3048F"

/*
 *  chg_ipm�򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define SUPPORT_CHG_IPM

/*
 *  vxget_tim �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define	SUPPORT_VXGET_TIM

/*
 *   �����å��ΰ�����
 */

			/* �󥿥�������ƥ������ѥ����å��ν���� */
#define STACKTOP    	(H8IN_RAM_BASE + H8IN_RAM_SIZE)	
#define str_STACKTOP	_TO_STRING(STACKTOP)

#ifndef _MACRO_ONLY

/*
 *  �������åȥ����ƥ��¸�ν����
 */

extern void	sys_initialize(void);

/*
 *  �������åȥ����ƥ�ν�λ
 *
 *  �����ƥ��λ������˻Ȥ���ROM��˥��ƽФ��Ǽ¸����뤳�Ȥ����ꤷ
 *  �Ƥ��롥
 */

extern void	sys_exit(void);

/*
 *  �������åȥ����ƥ��ʸ������
 *
 *  �����ƥ�����٥��ʸ�����ϥ롼����ROM��˥��ƽФ��Ǽ¸����뤳
 *  �Ȥ����ꤷ�Ƥ��롥
 */

extern void cpu_putc(char c);

Inline void
sys_putc(char c)
{
	cpu_putc(c);
};

#endif /* _MACRO_ONLY */

/*
 *  (1) ���ꥢ��ݡ��Ȥ�����
 *  (2) �����ޡ�������
 *  (3) �������ɥ쥹��������
 */

/*
 *  ���ݡ��Ȥ��륷�ꥢ��ǥ��Х����ο��Ϻ��� 2
 *  
 *  ����ץ�ץ�����ư��������
 *  sys_defs.h�ˤ���TASK_PORTID������ˤ����
 */
#define TNUM_PORT		2

/*
 *  SCI ����������ޥ���
 */

#define	CONSOLE_PORTID		SYSTEM_PORTID	/* ���󥽡�����Ѥ��륷�ꥢ��ݡ����ֹ�		*/
#define	LOGTASK_PORTID		SYSTEM_PORTID	/* �����ƥ������Ϥ��륷�ꥢ��ݡ����ֹ�	*/

#define H8_MIN_BAUD_RATE	9600		/* SCI �򥯥������������Ԥ����֤η׻��˻��Ѥ��롣*/

/* ���顼�����ߤ����ϳ����ߤ��̤�������ϥ����Ȥ�Ϥ�����*/
/*#define H8_CFG_SCI_ERR_HANDLER*/

/*
 *  SYSTEM �� SCI ��������
 */

#define SYSTEM_SCI		H8SCI1

#define SYSTEM_SCI_IPR		H8IPRB
#define SYSTEM_SCI_IP_BIT	H8IPR_SCI1_BIT

#define SYSTEM_SCI_SMR		0
			/* �������ե����ޥå�			*/
	     		/* Ĵ��Ʊ����				*/
	     		/* ����饯����󥰥���8�ӥå�		*/
	     		/* �ѥ�ƥ��ʤ�				*/
	     		/* ���ȥåץӥåȥ�󥰥���1		*/
	     		/* ����å����쥯�ȡ�ʬ�����:1		*/

#if TNUM_PORT == 1

#define SYSTEM_BAUD_RATE	38400			/* bps	*/

#define	SYSTEM_PORTID		1

#define INHNO_SERIAL_IN		IRQ_RXI1
#define INHNO_SERIAL_OUT	IRQ_TXI1
#define INHNO_SERIAL_ERR	IRQ_ERI1

#elif TNUM_PORT == 2	/* of #if TNUM_PORT == 1 */

#define USER_SCI		H8SCI0

#define USER_SCI_IPR		H8IPRB
#define USER_SCI_IP_BIT		H8IPR_SCI0_BIT

#define USER_SCI_SMR		0
			/* �������ե����ޥå�			*/
	     		/* Ĵ��Ʊ����				*/
	     		/* ����饯����󥰥���8�ӥå�		*/
	     		/* �ѥ�ƥ��ʤ�				*/
	     		/* ���ȥåץӥåȥ�󥰥���1		*/
	     		/* ����å����쥯�ȡ�ʬ�����:1		*/

#ifdef SUPPORT_PPP

#define USER_BAUD_RATE		9600			/* bps	*/

#else	/* of #ifdef SUPPORT_PPP */

#define USER_BAUD_RATE		38400			/* bps	*/

#endif	/* of #ifdef SUPPORT_PPP */

#define SYSTEM_BAUD_RATE	38400			/* bps	*/

#define	USER_PORTID		1
#define	SYSTEM_PORTID		2

#define INHNO_SERIAL_IN		IRQ_RXI0
#define INHNO_SERIAL_OUT	IRQ_TXI0
#define INHNO_SERIAL_ERR	IRQ_ERI0

#define INHNO_SERIAL2_IN	IRQ_RXI1
#define INHNO_SERIAL2_OUT	IRQ_TXI1
#define INHNO_SERIAL2_ERR	IRQ_ERI1

#else	/* of #if TNUM_PORT == 1 */

#error TNUM_PORT <= 2

#endif	/* of #if TNUM_PORT == 1 */

/*  �ץ饤����ƥ���٥������ѤΥǡ���  */

/*  ������׵�Υ�٥�����  */
#define SYSTEM_SCI_IPM			IPM_LEVEL0
#define USER_SCI_IPM			IPM_LEVEL0

/*  
 * ����ߥϥ�ɥ�¹���γ���ߥޥ�������
 * ����¾�γ���ߤ�ޥ������뤿�������  
 * ������ʬ��Ʊ����٥�γ�����׵��֥�å����뤿�ᡢ
 * �����嵭�γ�����׵��٥��꣱�Ĺ⤤��٥�����ꤹ�롣
 */
#if TNUM_PORT == 1	/*  �ݡ��ȣ��������ƥࡦ�ݡ���  */

/*  �����ƥࡦ�ݡ���  */
#if SYSTEM_SCI_IPM == IPM_LEVEL0
#define sio_in_handler_intmask		IPM_LEVEL1
#elif SYSTEM_SCI_IPM == IPM_LEVEL1
#define sio_in_handler_intmask		IPM_LEVEL2
#endif 	/* SYSTEM_SCI_IPM == IPM_LEVEL0 */


#elif TNUM_PORT == 2	/* of #if TNUM_PORT == 1 */
			/*  �ݡ��ȣ����桼�������ݡ���  */
			/*  �ݡ��ȣ��������ƥࡦ�ݡ���  */
/*  �桼�������ݡ���  */
#if USER_SCI_IPM == IPM_LEVEL0
#define sio_in_handler_intmask		IPM_LEVEL1
#elif USER_SCI_IPM == IPM_LEVEL1
#define sio_in_handler_intmask		IPM_LEVEL2
#endif 	/* USER_SCI_IPM == IPM_LEVEL0 */

/*  �����ƥࡦ�ݡ���  */
#if SYSTEM_SCI_IPM == IPM_LEVEL0
#define sio_in2_handler_intmask		IPM_LEVEL1
#elif SYSTEM_SCI_IPM == IPM_LEVEL1
#define sio_in2_handler_intmask		IPM_LEVEL2
#endif 	/* SYSTEM_SCI_IPM == IPM_LEVEL0 */

#endif	/* of #if TNUM_PORT == 1 */

#define sio_out_handler_intmask		sio_in_handler_intmask
#define sio_err_handler_intmask		sio_in_handler_intmask
#define sio_out2_handler_intmask	sio_in2_handler_intmask
#define sio_err2_handler_intmask	sio_in2_handler_intmask


/*
 *  �����ޤ�����
 */

#define SYSTEM_TIMER		H8ITU0

#define SYSTEM_TIMER_CNT	(SYSTEM_TIMER + H8TCNT)
#define SYSTEM_TIMER_TCR	(SYSTEM_TIMER + H8TCR)
#define SYSTEM_TIMER_TIOR	(SYSTEM_TIMER + H8TIOR)
#define SYSTEM_TIMER_IER	(SYSTEM_TIMER + H8TIER)
#define SYSTEM_TIMER_IFR	(SYSTEM_TIMER + H8TSR)
#define SYSTEM_TIMER_TSTR	H8ITU_TSTR
#define SYSTEM_TIMER_GR		(SYSTEM_TIMER + H8GRA)

#define SYSTEM_TIMER_STR	H8TSTR_STR0
#define SYSTEM_TIMER_STR_BIT	H8TSTR_STR0_BIT
#define SYSTEM_TIMER_IE		H8TIER_IMIEA		/* interrupt mask */
#define SYSTEM_TIMER_IE_BIT	H8TIER_IMIEA_BIT
#define SYSTEM_TIMER_IF		H8TSR_IMIFA		/* match flag */
#define SYSTEM_TIMER_IF_BIT	H8TSR_IMIFA_BIT

#define INHNO_TIMER		IRQ_IMIA0

#define SYSTEM_TIMER_TCR_BIT	(H8TCR_CCLR0 | H8TCR_TPSC1 | H8TCR_TPSC0)
#define SYSTEM_TIMER_TIOR_BIT	(0)

#define TIMER_CLOCK		((CPU_CLOCK)/8000)
				/* 16MHz / 8 = 2MHz = 2000KHz */

/*  �ץ饤����ƥ���٥������ѤΥǡ���  */

/*  ������׵�Υ�٥�����  */
#define SYSTEM_TIMER_IPR                H8IPRA
#define SYSTEM_TIMER_IP_BIT             H8IPR_ITU0_BIT
#define SYSTEM_TIMER_IPM                IPM_LEVEL1

/*  
 * ����ߥϥ�ɥ�¹���γ���ߥޥ�������
 * ����¾�γ���ߤ�ޥ������뤿�������  
 * ������ʬ��Ʊ����٥�γ�����׵��֥�å����뤿�ᡢ
 * �����嵭�γ�����׵��٥��꣱�Ĺ⤤��٥�����ꤹ�롣
 */
#if SYSTEM_TIMER_IPM == IPM_LEVEL0
#define timer_handler_intmask		IPM_LEVEL1
#elif SYSTEM_TIMER_IPM == IPM_LEVEL1
#define timer_handler_intmask		IPM_LEVEL2
#endif 	/* SYSTEM_TIMER_IPM == IPM_LEVEL0 */



/*
 *  �������ɥ쥹��������
 */

#if 0
#define ENABLE_LOWER_DATA
#define ENABLE_P8_CS	(H8P8DDR_CS0|H8P8DDR_CS1|H8P8DDR_CS2|H8P8DDR_CS3)
#define ENABLE_PA_CS	(H8PADDR_CS4|H8PADDR_CS5|H8PADDR_CS6)
#define ENABLE_PB_CS 	H8PBDDR_CS7

#define ENABLE_PA_A21_A23	(H8BRCR_A23E|H8BRCR_A22E|H8BRCR_A21E)

#endif


/*
 *  ���������Ԥ��Τ�������
 */

#ifdef ROM

#define	SIL_DLY_TIM1	 9400
#define	SIL_DLY_TIM2	  701

#else	/* of #ifdef ROM */

#define	SIL_DLY_TIM1	24900
#define	SIL_DLY_TIM2	 5260

#endif	/* of #ifdef ROM */

/*
 *  DDR�ν���ͤ����
 */
#define	H8P1DDR0        0xff				/*  �ݡ���1  */
#define	H8P2DDR0        0xff				/*  �ݡ���2  */
#define	H8P3DDR0        0xff				/*  �ݡ���3  */

#ifdef ENABLE_LOWER_DATA
#define	H8P4DDR0        0xff				/*  �ݡ���4  */
#else	/* #if ENABLE_LOWER_DATA */
#define	H8P4DDR0        DUMMY				/*  �ݡ���4  */
#endif	/* #if ENABLE_LOWER_DATA */

#define	H8P5DDR0        0xff				/*  �ݡ���5  */
#define	H8P6DDR0        DUMMY				/*  �ݡ���6  */

/*  �ݡ���7���������Ѥ�DDR�쥸�������ʤ����ᡢ��ά���Ƥ��롣  */

#ifdef ENABLE_P8_CS
#define	H8P8DDR0        ENABLE_P8_CS			/*  �ݡ���8  */
#else	/* #ifdef ENABLE_P8_CS */
#define	H8P8DDR0        DUMMY				/*  �ݡ���8  */
#endif	/* #ifdef ENABLE_P8_CS */

#define	H8P9DDR0        DUMMY				/*  �ݡ���9  */

#ifdef ENABLE_PA_CS
#define	H8PADDR0        ENABLE_PA_CS			/*  �ݡ���A  */
#elif defined(ENABLE_PA_A21_A23)
#define	H8PADDR0        ENABLE_PA_A21_A23		/*  �ݡ���A  */
#else
#define	H8PADDR0        DUMMY				/*  �ݡ���A  */
#endif	/* #ifdef ENABLE_PA_CS */

#ifdef ENABLE_PB_CS
#define	H8PBDDR0        ENABLE_PB_CS			/*  �ݡ���B  */
#else	/* #ifdef ENABLE_PB_CS */
#define	H8PBDDR0        DUMMY				/*  �ݡ���B  */
#endif	/* #ifdef ENABLE_PB_CS */

#endif /* _SYS_CONFIG_H_ */
