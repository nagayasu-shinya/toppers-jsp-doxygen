/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2010 by Cronus Computer Works, JAPAN
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
 *  @(#) $Id
 */

/*
 *	�������åȥ����ƥ�˰�¸���������CQ_FRKSH2A�ѡ�
 *�������������ץꥱ�������ɬ�פȤ������
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�kernel.h �� sil.h �ǥ��󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��뤳�ȤϤʤ������Υե�����򥤥�
 *  ���롼�ɤ������ˡ�t_stddef.h �� itron.h �����󥯥롼�ɤ����Τǡ�
 *  �����˰�¸���Ƥ�褤��
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

#define CQ_FRKSH2A			/* �����ƥ�ά�� */

#define COPYRIGHT_SYS \
"Copyright (C) 2010 by Cronus Computer Works, JAPAN\n\n"

#ifndef _MACRO_ONLY

/*
 *  ������ֹ�η��ȳ���ߤζػߡ�����
 */
#if 0 /* �������Ǥϥ��ݡ��Ȥ��Ƥ��ʤ� */

typedef	UINT	INTNO;		/* ������ֹ� */

extern ER	dis_int(INTNO intno) throw();
extern ER	ena_int(INTNO intno) throw();

#endif /* 0 */

#endif /* _MACRO_ONLY */

/*
 *  ����å���⡼�ɤ�����
 */
//#define CCR_MODE      0x00000101    /* �饤�ȥХå��⡼�� */
#define CCR_MODE      0x00000103    /* �饤�ȥ��롼�⡼�� */

/*
 *  ���ե⥸�塼��ؤζ��륯��å��μ��ȿ�
 *  CQ_SH7262�Ǥϡ�P������å���24MHz
 */
#define PCLOCK          24000000

/*
 *  ������ƥ��å������
 */
#define	TIC_NUME	1u	/* ������ƥ��å��μ�����ʬ�� */
#define	TIC_DENO	1u	/* ������ƥ��å��μ�����ʬ�� */

/*
 *   �����ޤؤ����ϥ���å���ʬ��������
 *
 *   CQ_SH7262�Ǥϡ�P������å���24MHz
 *   0: P��/8   3MHz      tick 3000  0.33 ��sec
 *   1: P��/32  750KHz    tick 750   1.33 ��sec
 *   2: P��/128 187.5KHz  tick 187   5.33 ��sec
 *   3: P��/512 46.875KHz tick 47    21.33 ��sec
 */
#define TCR_CKS         0

/*
 *  SDRAM�⡼�ɥ쥸�����Υ��ɥ쥹
 *  �����ɥ쥹���⡼��������
 */
//#define SDRAM_MODE  ((VH *)0xfffc58c0)


#ifndef _MACRO_ONLY

/*
 *  �����ƥ����߽���
 */
#ifdef GDB_STUB

Inline void
kernel_abort()
{
	/* �ƥ��Ȥ��Ƥ��ʤ� */
	Asm("trapa #0x20"::);
}

#else /* GDB_STUB */

Inline void
kernel_abort()
{
	while(1);
}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _SYS_DEFS_H_ */
