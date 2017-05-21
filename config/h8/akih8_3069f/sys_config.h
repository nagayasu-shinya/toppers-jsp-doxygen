/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2010 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Kunihiko Ohnaka
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
#include <h8_3069f.h>

/*
 *  ��ư��å������Υ������å�̾
 */

#define	TARGET_NAME	"AKI-H8/3069F"


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
#ifdef REDBOOT
#define STACKTOP    	(0x50fff0)
#else	/*  REDBOOT  */
#define STACKTOP    	(H8IN_RAM_BASE + H8IN_RAM_SIZE)
#endif	/*  #ifdef REDBOOT  */

#define str_STACKTOP	_TO_STRING(STACKTOP)

/* Redboot��RAM��˻��ĥ٥����ơ��֥����Ƭ���ɥ쥹 */
#define VECTOR_TABLE_ADDR 	0x00fffd20

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
 *  ���ݡ��Ȥ��륷�ꥢ��ǥ��Х����ο��Ϻ��� 3��
 *  
 *  ����ץ�ץ�����ư��������
 *  sys_defs.h�ˤ���TASK_PORTID������ˤ����
 */
#define TNUM_PORT	2

#define	CONSOLE_PORTID		SYSTEM_PORTID	/* ���󥽡�����Ѥ��륷�ꥢ��ݡ����ֹ�     */
#define	LOGTASK_PORTID		SYSTEM_PORTID	/* �����ƥ������Ϥ��륷�ꥢ��ݡ����ֹ� */

#define H8_MIN_BAUD_RATE	9600		/* SCI �򥯥������������Ԥ����֤η׻��˻��Ѥ��롣*/

/* ���顼�����ߤ����ϳ����ߤ��̤�������ϥ����Ȥ�Ϥ�����*/
#if 0
#define H8_CFG_SCI_ERR_HANDLER
#endif

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

#define SYSTEM_BAUD_RATE	38400			/* bps	*/

#define	SYSTEM_PORTID		1

#define INHNO_SERIAL_IN		IRQ_RXI1
#define INHNO_SERIAL_OUT	IRQ_TXI1
#define INHNO_SERIAL_ERR	IRQ_ERI1

#if TNUM_PORT >= 2

#define USER_SCI			H8SCI0

#define USER_SCI_IPR		H8IPRB
#define USER_SCI_IP_BIT		H8IPR_SCI0_BIT

#define USER_SCI_SMR		0
			/* �������ե����ޥå�			*/
	     		/* Ĵ��Ʊ����				*/
	     		/* ����饯����󥰥���8�ӥå�		*/
	     		/* �ѥ�ƥ��ʤ�				*/
	     		/* ���ȥåץӥåȥ�󥰥���1		*/
	     		/* ����å����쥯�ȡ�ʬ�����:1		*/

#define USER_BAUD_RATE		38400			/* bps	*/

#define	USER_PORTID		2

#define INHNO_SERIAL2_IN	IRQ_RXI0
#define INHNO_SERIAL2_OUT	IRQ_TXI0
#define INHNO_SERIAL2_ERR	IRQ_ERI0

#endif	/* of #if TNUM_PORT >= 2 */


#if TNUM_PORT >= 3

#define USER2_SCI			H8SCI2

#define USER2_SCI_IPR		H8IPRB
#define USER2_SCI_IP_BIT	H8IPR_SCI2_BIT

#define USER2_SCI_SMR		0
			/* �������ե����ޥå�			*/
	     		/* Ĵ��Ʊ����				*/
	     		/* ����饯����󥰥���8�ӥå�		*/
	     		/* �ѥ�ƥ��ʤ�				*/
	     		/* ���ȥåץӥåȥ�󥰥���1		*/
	     		/* ����å����쥯�ȡ�ʬ�����:1		*/

#define USER2_BAUD_RATE		38400			/* bps	*/

#define	USER2_PORTID		3

#define INHNO_SERIAL3_IN	IRQ_RXI2
#define INHNO_SERIAL3_OUT	IRQ_TXI2
#define INHNO_SERIAL3_ERR	IRQ_ERI2

#endif	/* of #if TNUM_PORT >= 3 */



/*  �ץ饤����ƥ���٥������ѤΥǡ���  */

/*  ������׵�Υ�٥�����  */
#define SYSTEM_SCI_IPM			IPM_LEVEL0
#define USER_SCI_IPM			IPM_LEVEL0
#define USER2_SCI_IPM			IPM_LEVEL0

/*  
 * ����ߥϥ�ɥ�¹���γ���ߥޥ�������
 * ����¾�γ���ߤ�ޥ������뤿�������  
 * ������ʬ��Ʊ����٥�γ�����׵��֥�å����뤿�ᡢ
 * �����嵭�γ�����׵��٥��꣱�Ĺ⤤��٥�����ꤹ�롣
 */

/*  �ݡ���1�������ƥࡦ�ݡ���  */
#if SYSTEM_SCI_IPM == IPM_LEVEL0
#define sio_in_handler_intmask		IPM_LEVEL1
#elif SYSTEM_SCI_IPM == IPM_LEVEL1
#define sio_in_handler_intmask		IPM_LEVEL2
#endif 	/* SYSTEM_SCI_IPM == IPM_LEVEL0 */


/*  �ݡ���2���桼�������ݡ���  */
#if TNUM_PORT >= 2
#if USER_SCI_IPM == IPM_LEVEL0
#define sio_in2_handler_intmask		IPM_LEVEL1
#elif USER_SCI_IPM == IPM_LEVEL1
#define sio_in2_handler_intmask		IPM_LEVEL2
#endif 	/* USER_SCI_IPM == IPM_LEVEL0 */
#endif	/* of #if TNUM_PORT >= 2 */

/*  �ݡ���3���桼�������ݡ���2  */
#if TNUM_PORT >= 3
#if USER2_SCI_IPM == IPM_LEVEL0
#define sio_in3_handler_intmask		IPM_LEVEL1
#elif USER2_SCI_IPM == IPM_LEVEL1
#define sio_in3_handler_intmask		IPM_LEVEL2
#endif 	/* USER2_SCI_IPM == IPM_LEVEL0 */
#endif	/* of #if TNUM_PORT >= 3 */


#define sio_out_handler_intmask		sio_in_handler_intmask
#define sio_err_handler_intmask		sio_in_handler_intmask
#define sio_out2_handler_intmask	sio_in2_handler_intmask
#define sio_err2_handler_intmask	sio_in2_handler_intmask
#define sio_out3_handler_intmask	sio_in3_handler_intmask
#define sio_err3_handler_intmask	sio_in3_handler_intmask


/*
 *  �����ޤ�����
 */

#define SYSTEM_TIMER		H816TU0

#define SYSTEM_TIMER_CNT	(SYSTEM_TIMER + H8TCNT)
#define SYSTEM_TIMER_TCR	(SYSTEM_TIMER + H8TCR)
#define SYSTEM_TIMER_TIOR	(SYSTEM_TIMER + H8TIOR)
#define SYSTEM_TIMER_IER	H816TU_TISRA
#define SYSTEM_TIMER_IFR	H816TU_TISRA
#define SYSTEM_TIMER_TSTR	H816TU_TSTR
#define SYSTEM_TIMER_GR		(SYSTEM_TIMER + H8GRA)

#define SYSTEM_TIMER_STR	H8TSTR_STR0
#define SYSTEM_TIMER_STR_BIT	H8TSTR_STR0_BIT
#define SYSTEM_TIMER_IE		H8TISRA_IMIEA0		/* interrupt mask */
#define SYSTEM_TIMER_IE_BIT	H8TISRA_IMIEA0_BIT
#define SYSTEM_TIMER_IF		H8TISRA_IMFA0		/* match flag */
#define SYSTEM_TIMER_IF_BIT	H8TISRA_IMFA0_BIT

#define INHNO_TIMER		IRQ_IMIA0

#define SYSTEM_TIMER_TCR_BIT	(H8TCR_CCLR0 | H8TCR_TPSC1 | H8TCR_TPSC0)
#define SYSTEM_TIMER_TIOR_BIT	(0)

#define TIMER_CLOCK		((CPU_CLOCK)/8000)	
				/* 20MHz / 8 = 2.5MHz = 2500KHz */

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

#define	ENABLE_P8_CS	(H8P8DDR_CS0|H8P8DDR_CS1|H8P8DDR_CS2|H8P8DDR_CS3)

#if 0

#define	ENABLE_LOWER_DATA
#define	ENABLE_PB_CS	(H8PADDR_CS4|H8PADDR_CS5|H8PADDR_CS6|H8PBDDR_CS7)

#endif	/* of #if 0 */


/*
 *  ���������Ԥ��Τ�������
 */

#if defined(ROM)

/*  ROM���ʳ���RAM���ѡ�  */
#define	SIL_DLY_TIM1	 2350
#define	SIL_DLY_TIM2	  530

#elif defined(INMEM_ONLY)

/*  ROM������¢����Τ߻��ѡ� */
#define	SIL_DLY_TIM1	 1668
#define	SIL_DLY_TIM2	  519

#else	/* of #if defined(ROM) */

/*  �ʰץ�˥��ʥ桼�����ץ����ϳ���RAM��˥�������ɡ�  */
#define	SIL_DLY_TIM1	3914
#define	SIL_DLY_TIM2	1110

#endif	/* of #if defined(ROM) */


/*
 *  DDR�ν���ͤ����
 */
#ifdef INMEM_ONLY	/*  ROM�����ĳ���DRAM�ʤ�  */

/*  �⡼�ɤˤ�äƤ�DDR�ν���ͤ��ۤʤ�Τǡ����  */
#define	H8P1DDR0        0x00				/*  �ݡ���1  */
#define	H8P2DDR0        0x00				/*  �ݡ���2  */
#define	H8P3DDR0        0x00				/*  �ݡ���3  */
#define	H8P4DDR0        0x00				/*  �ݡ���4  */
#define	H8P5DDR0        0x00				/*  �ݡ���5  */
#define	H8P6DDR0        0x00				/*  �ݡ���6  */

/*  �ݡ���7���������Ѥ�DDR�쥸�������ʤ����ᡢ��ά���Ƥ��롣  */

#ifdef SUPPORT_ETHER
#define	H8P8DDR0        (H8P8DDR_CS1 | H8P8DDR_CS2)	/*  �ݡ���8  */
#else 	/* SUPPORT_ETHER */
#define	H8P8DDR0        0x00				/*  �ݡ���8  */
#endif 	/* SUPPORT_ETHER */

#define	H8P9DDR0        0x00				/*  �ݡ���9  */
#define	H8PADDR0        0x00				/*  �ݡ���A  */
#define	H8PBDDR0        0x00				/*  �ݡ���B  */

#else 	/*  of #ifdef INMEM_ONLY  */

#define	H8P1DDR0        0xff				/*  �ݡ���1  */
#define	H8P2DDR0        0xff				/*  �ݡ���2  */
#define	H8P3DDR0        0xff				/*  �ݡ���3  */
#define	H8P4DDR0        DUMMY				/*  �ݡ���4  */
#define	H8P5DDR0        H8P5DDR_A16			/*  �ݡ���5  */
#define	H8P6DDR0        DUMMY				/*  �ݡ���6  */

/*  �ݡ���7���������Ѥ�DDR�쥸�������ʤ����ᡢ��ά���Ƥ��롣  */

#define	H8P8DDR0        (H8P8DDR_CS1 | H8P8DDR_CS2)	/*  �ݡ���8  */
#define	H8P9DDR0        DUMMY				/*  �ݡ���9  */
#define	H8PADDR0        DUMMY				/*  �ݡ���A  */
#define	H8PBDDR0        H8PBDDR_UCAS			/*  �ݡ���B  */

#endif 	/*  of #ifdef INMEM_ONLY  */


#ifdef REDBOOT
/*
 *  ����ߥץ饤����ƥ��ν���ͤ����
 *����Redboot�ξ�硢IRQ5����Ѥ��롣
 */
#define H8IPRA_INI	H8IPR_IRQ5_BIT

/*
 *  Redboot�����Ѥ������ߥ٥��������������
 */

/* �٥����ơ��֥���⡢trapa̿���Ѥ˳��ݤ��Ƥ������ͥ�� */
#define TRAP_VECTOR_SIZE	4

#ifndef _MACRO_ONLY
/*  ���򥹥ڡ����Υǡ��������  */
typedef struct {
	UW trap_vector[TRAP_VECTOR_SIZE];
	UW irq5;
} TMP_VECTOR;

/*  ����ߥ٥���������  */
extern void load_vector(TMP_VECTOR *p);
/*  ����ߥ٥���������  */
extern void save_vector(TMP_VECTOR *p);

#endif	/*  _MACRO_ONLY  */

#endif	/* of #ifdef REDBOOT */


#endif /* _SYS_CONFIG_H_ */
