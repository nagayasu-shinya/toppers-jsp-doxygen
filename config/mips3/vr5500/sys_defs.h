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

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

/*
 *  �ץ��å�������
 */
#define VR5500

/*
 *  ��ư��å������Υ������åȥܡ���̾
 */
#define	TARGET_NAME	"RTE-VR5500-CB(64)"

/*
 *  INTNO���ȳ���ߤζػ�/����
 */
#ifndef _MACRO_ONLY

typedef	UINT	INTNO;			/* ������ֹ��icu_set_ilv�����ѡ� */

#if 0		/*  MIPS3�ǤǤϥ��ݡ��Ȥ��Ƥ��ʤ�  */
extern ER	dis_int(INTNO intno) throw();
extern ER	ena_int(INTNO intno) throw();
#endif

#endif /* _MACRO_ONLY */

/*
 *  ������ƥ��å������
 */
#define	TIC_NUME	1		/* ������ƥ��å��μ�����ʬ�� */
#define	TIC_DENO	1		/* ������ƥ��å��μ�����ʬ�� */

/*
 *  �������åȥ����ƥ��¸�Υ����ӥ�������
 */
#ifndef _MACRO_ONLY

typedef	UD 	SYSUTIM;		/* ��ǽɾ���ѥ����ƥ���� */
extern	ER	vxget_tim(SYSUTIM *pk_sysutim) throw();

#endif /* _MACRO_ONLY */

/*
 *  �ץ��å��Υ���ǥ�����
 */
#define	SIL_ENDIAN	SIL_ENDIAN_LITTLE	/* ��ȥ륨��ǥ����� */

#ifndef _MACRO_ONLY

/*  ����ߥ���ȥ���γ���ߥޥ����η����  */
typedef struct{
	UB	int0m;			/*  �ޥ����쥸����1  */
	UB	int1m;			/*  �ޥ����쥸����2  */
} ICU_IPM;

/*
 *  �����ƥ����߽���
 */
Inline void
kernel_abort()
{
	Asm("break");
}

#endif /* _MACRO_ONLY */

#endif /* _SYS_DEFS_H_ */
