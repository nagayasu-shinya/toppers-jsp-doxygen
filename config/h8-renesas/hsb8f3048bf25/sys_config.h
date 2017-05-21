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
 *  @(#) $Id: sys_config.h,v 1.7 2007/03/23 07:58:33 honda Exp $
 */

/*
 *���������åȥ����ƥ��¸�⥸�塼��������Ż� HSB8F3048BF25�ѡ�
 *�����������ͥ������ǻ��Ѥ������
 *���������ǡ��������ޥ����ؿ��Υץ�ȥ��������
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
 *  �桼����������ե�����졼������������
 */
#include <user_config.h>


/*
 *  �������åȥ����ƥ�Υϡ��ɥ������񸻤����
 */

#include <h8_3048f.h>

/*
 *  ��ư��å������Υ������å�̾
 */

#define TARGET_NAME     "Hokuto Electronic H8/3048F-ONE STARTER KIT"


#ifndef _MACRO_ONLY

/*
 *  �������åȥ����ƥ��¸�ν����
 */

extern void     sys_initialize(void);

/*
 *  �������åȥ����ƥ�ν�λ
 *
 *  �����ƥ��λ������˻Ȥ���ROM��˥��ƽФ��Ǽ¸����뤳�Ȥ����ꤷ
 *  �Ƥ��롥
 */

extern void     sys_exit(void);

/*
 *  �������åȥ����ƥ��ʸ������
 *
 *  �����ƥ�����٥��ʸ�����ϥ롼����ROM��˥��ƽФ��Ǽ¸����뤳
 *  �Ȥ����ꤷ�Ƥ��롥
 */
extern void     sys_putc(char c) throw();

#endif /* _MACRO_ONLY */

/*
 *  SOFTWARE_TERM_HOOK�ޥ���atexit�ν���
 *  �������ؿ��γ������������С����δؿ�̾��SOFTWARE_TERM_HOOK
 *�����ޥ���Ȥ���������롣
 */
/*  ���������ʤ�  */


/*
 *  (1) ���ꥢ��ݡ��Ȥ�����
 *  (2) �����ޡ�������
 *  (3) �������ɥ쥹��������
 */

/*
 *  SCI ����������ޥ���
 */

        /* SCI �򥯥������������Ԥ����֤η׻��˻��Ѥ��롣*/
#define H8_MIN_BAUD_RATE        9600ul

/*
 *  SYSTEM �� SCI ��������
 */
                                /* �����ƥ������Ϥ��륷�ꥢ��ݡ����ֹ�     */
#define LOGTASK_PORTID          SYSTEM_PORTID   /*  user_config.h  */

/*  ����쥸�����Υ١������ɥ쥹  */
#define SCI_PORT1_BASE          H8SCI0

/*  �ץ饤����ƥ���٥������ѤΥǡ���  */
#define SCI_PORT1_IPR          H8IPRB
#define SCI_PORT1_IPR_BIT      H8IPR_SCI0_BIT

#define SCI_PORT1_SMR          0u
                        /* �������ե����ޥå�                   */
                        /* Ĵ��Ʊ����                           */
                        /* ����饯����󥰥���8�ӥå�          */
                        /* �ѥ�ƥ��ʤ�                         */
                        /* ���ȥåץӥåȥ�󥰥���1            */
                        /* ����å����쥯�ȡ�ʬ�����:1         */

#define INHNO_SERIAL_IN         IRQ_RXI0
#define INHNO_SERIAL_OUT        IRQ_TXI0
#define INHNO_SERIAL_ERR        IRQ_ERI0


#if TNUM_PORT == 2

#define SCI_PORT2_BASE          H8SCI1

/*  �ץ饤����ƥ���٥������ѤΥǡ���  */
#define SCI_PORT2_IPR          H8IPRB
#define SCI_PORT2_IPR_BIT      H8IPR_SCI1_BIT

#define SCI_PORT2_SMR          0u
                        /* �������ե����ޥå�                   */
                        /* Ĵ��Ʊ����                           */
                        /* ����饯����󥰥���8�ӥå�          */
                        /* �ѥ�ƥ��ʤ�                         */
                        /* ���ȥåץӥåȥ�󥰥���1            */
                        /* ����å����쥯�ȡ�ʬ�����:1         */

#define INHNO_SERIAL2_IN        IRQ_RXI1
#define INHNO_SERIAL2_OUT       IRQ_TXI1
#define INHNO_SERIAL2_ERR       IRQ_ERI1

#endif  /* of #if TNUM_PORT == 2u */

/*
 *  �����ޤ�����
 */

#define SYSTEM_TIMER            H8ITU0

#define SYSTEM_TIMER_CNT        (SYSTEM_TIMER + H8TCNT)
#define SYSTEM_TIMER_TCR        (SYSTEM_TIMER + H8TCR)
#define SYSTEM_TIMER_TIOR       (SYSTEM_TIMER + H8TIOR)
#define SYSTEM_TIMER_IER        (SYSTEM_TIMER + H8TIER)
#define SYSTEM_TIMER_IFR        (SYSTEM_TIMER + H8TSR)
#define SYSTEM_TIMER_TSTR       H8ITU_TSTR
#define SYSTEM_TIMER_GR         (SYSTEM_TIMER + H8GRA)

#define SYSTEM_TIMER_STR        H8TSTR_STR0
#define SYSTEM_TIMER_STR_BIT    H8TSTR_STR0_BIT
#define SYSTEM_TIMER_IE         H8TIER_IMIEA            /* interrupt mask */
#define SYSTEM_TIMER_IE_BIT     H8TIER_IMIEA_BIT
#define SYSTEM_TIMER_IF         H8TSR_IMIFA             /* match flag */
#define SYSTEM_TIMER_IF_BIT     H8TSR_IMIFA_BIT

#define INHNO_TIMER             IRQ_IMIA0

#define SYSTEM_TIMER_TCR_BIT    (H8TCR_CCLR0 | H8TCR_TPSC1 | H8TCR_TPSC0)
#define SYSTEM_TIMER_TIOR_BIT   (0u)

/*  �ץ饤����ƥ���٥������ѤΥǡ���  */
#define SYSTEM_TIMER_IPR                H8IPRA
#define SYSTEM_TIMER_IP_BIT             H8IPR_ITU0_BIT

/*
 *  I/O�ݡ��� DDR�ν����
 *      h8_sil.c��DDR���������롼����ǻ��Ѥ��롣
 *      �ݡ��ȣ����������ѤΤ��ᡢ��ά���Ƥ��롣
 */
#define H8P1DDR0        0xffu	/*  ���ɥ쥹���Х�  */
#define H8P2DDR0        0xffu	/*  ���ɥ쥹���Х�  */
#define H8P3DDR0        0u	    /*  �ǡ������Х���  */
#define H8P4DDR0        0u      /*  �ǡ������Х���  */
#define H8P5DDR0        0x0fu	/*  ���ɥ쥹���Х�  */
#define H8P6DDR0        0u
#define H8P8DDR0        H8P8DDR_CS1     /*  P83��CS1������  */
#define H8P9DDR0        0u
#define H8PADDR0        0u
#define H8PBDDR0        0u

/*
 *  SYSCR�ν����
 *      $SYS�ǥ��쥯�ȥ��SYSCR_SYS�Ȥ��������������
 *      ���ӥå�6-4 STS��������Х��������ޡ����쥯��
 *      ���ӥå�2 NMIEG��NMI���å�
 */
#define SYSCR_SYS	0u


#endif /* _SYS_CONFIG_H_ */
