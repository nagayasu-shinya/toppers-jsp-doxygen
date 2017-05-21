/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
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
 *  @(#) $Id: sys_defs.h,v 1.7 2007/03/23 06:56:03 honda Exp $
 */


/*
 *  �����ƥ�˰�¸���������Altera NiosII Development Board �ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�kernel.h �� sil.h �ǥ��󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��뤳�ȤϤʤ������Υե�����򥤥�
 *  ���롼�ɤ������ˡ�t_stddef.h �� itron.h �����󥯥롼�ɤ����Τǡ�
 *  �����˰�¸���Ƥ�褤��
 */


#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

#define ALTERA_DEV


/*
 *  ��ư��å������Υ������å�̾
 */
#define    TARGET_NAME    "Nios Development Board(Nios2)"

/*
 *  ����ե�����졼������¸�����
 */

/*
 *   �����å��ΰ�����
 */                 
#define STACKTOP    0x02000000    /* ��������Ω���ѥ����å��ν���� */


/*
 *  �������ͤ�����ɽ���ȥߥ���ñ�̤Ȥ��Ѵ�
 */
#define TIMER_CLOCK     50000

/*
 *  ������ƥ��å������
 */
#define    TIC_NUME    1        /* ������ƥ��å��μ�����ʬ�� */
#define    TIC_DENO    1        /* ������ƥ��å��μ�����ʬ�� */


#define USE_JTAG_UART


/*
 * �ڥ�ե����Υ١������ɥ쥹
 */
#ifdef  STRATIX_II_2S180
#define PERI_BASE 0x08000000u
#else
#define PERI_BASE 0x00800000u
#endif  /* STRATIX_II_2S180 */

/*
 *  TIMER �Υ١������ɥ쥹
 */
#define TIM_BASE (PERI_BASE + 0x00010800u)

/*
 * �����ͥ�ǻ��Ѥ��� UART �Υ١������ɥ쥹
 */
#ifndef USE_JTAG_UART
#define UART_BASE  (PERI_BASE + 0x00010840)
#else
#define UART_BASE  (PERI_BASE + 0x00010820)
#endif /* USE_JTAG_UART */


/*
 *  TIM ����ߤγ�����ֹ�
 */
#define TIM_INTLVL        1

/*
 * UART ����ߤγ�����ֹ�
 */
#ifndef USE_JTAG_UART
#define UART_INTLVL       3
#else
#define UART_INTLVL       2
#endif /* USE_JTAG_UART */


/*                                                                             
 *  ���ꥢ��ݡ����ֹ�˴ؤ������      
 */
#define TNUM_PORT   1   /* ���ݡ��Ȥ��륷�ꥢ��ݡ��Ȥο� */
#define TNUM_SIOP   1   /* ���ݡ��Ȥ��륷�ꥢ��I/O�ݡ��Ȥο� */

/*
 *  �����ƥॿ�����˴ؤ������
 */
#define LOGTASK_PORTID    1    /* �����ƥ������Ϥ��륷�ꥢ��ݡ����ֹ� */


/*
 *  ���������Ԥ��Τ�������
 */
#define SIL_DLY_TIM1    420
#define SIL_DLY_TIM2    90

/*
 * ����å��������
 */ 
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE 4

/*
 * ROM���ξ��Ρ�ROM(FLASH)��RAM
 */ 
#define ROM_BASE   0x00000000
#define RAM_BASE   0x01000000

#endif /* _SYS_DEFS_H_ */
