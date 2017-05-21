/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include <sys_rename.h>

/*
 *  �����ƥ��¸�Υ��󥯥롼�ɥե�������ɤ߹���
 */
#include <h8s2350.h>
#include <mispo_h8s2350.h>

/*
 *  vgxet_tim �򥵥ݡ��Ȥ��뤫�ɤ��������
 */
#define	SUPPORT_VXGET_TIM

/*
 *  ���ꥢ��ݡ��ȿ������
 */
#define TNUM_PORT	2u	/* ���ݡ��Ȥ��륷�ꥢ��ݡ��Ȥο� */
#define	TNUM_SIOP	2u	/* ���ݡ��Ȥ��륷�ꥢ��I/O�ݡ��Ȥο� */

/*
 *  �����ƥॿ�����˴ؤ������
 */
#define	LOGTASK_PORTID	1	/* �����ƥ������Ϥ��륷�ꥢ��ݡ����ֹ� */
#define	CONSOLE_PORTID	1	/* ���󥽡����������Ϥ��륷�ꥢ��ݡ����ֹ� */
		/* CONSOLE_PORTID : monitor ���� */

/*
 *  ���������Ԥ��Τ�������
 */
#define	SIL_DLY_TIM1	22620
#define	SIL_DLY_TIM2	3865

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

extern void	sys_putc(char c) throw();

#endif /* _MACRO_ONLY */

/*============================================================================*/
/* �ʲ��ϡ����̥ɥ�����Ȥ�̵���ȼ������ */

/*
 *  JSP�����ͥ�ư����Υ���ޥå� (release.ld)
 *      0x000000 - 0x01ffff     �������ΰ�(128kB)
 *      0x200000 -              �ǡ����ΰ�(128kB)
 *               - 0x21ffff     ��������Ω���ѥ����å������꽪λ
 */

/*
 *  JSP�����ͥ�ư����Υ���ޥå� (debug.ld)
 *      0x200000 - 0x20ffff     �������ΰ�(64kB)
 *      0x210000 -              �ǡ����ΰ�(64kB-8kB(for GDB_STUB))
 *               - 0x21efff     ��������Ω���ѥ����å������꽪λ
 */

/*
 *   �����å��ΰ�����
 */
#ifndef GDB_STUB
#define STACKTOP    	0x21fffc	/* ��������Ω���ѥ����å��ν���� */
#else /* GDB_STUB */
#define STACKTOP    	0x21effc	/* ��������Ω���ѥ����å��ν���� */
#endif /* GDB_STUB */

#define str_STACKTOP	TO_STRING(STACKTOP)

/*
 *  ����ߥ�٥����
 */
#define SCI0_INT_LVL	3u		/* SCI����ͥ�0�γ����ߥ�٥� */
#define SCI1_INT_LVL	3u		/* SCI����ͥ�1�γ����ߥ�٥� */
#define TPU0_INT_LVL	5u		/* TPU����ͥ�0�γ����ߥ�٥� */

/*
 *  ���ꥢ�륳��ȥ���Υܡ��졼�Ȥ�����
 */
/* #define BAUD_RATE	9600u */	/* bps */
#define BAUD_RATE	38400u
/* #define BAUD_RATE	57600u */

#endif /* _SYS_CONFIG_H_ */
