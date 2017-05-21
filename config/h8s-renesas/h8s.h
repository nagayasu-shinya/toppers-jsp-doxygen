/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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

#ifndef _H8S_H_
#define _H8S_H_

#include <util.h>

/*
 *  H8S/2600, H8S/2000 CPU �����
 *    ����ߴ�Ϣ��I/O�ݡ��Ȥϥ��å���˰ۤʤ�Τ�
 *    h8sxxxx.h��������Ƥ��롣
 */

/*
 *  �١������ɥ쥹
 */
#ifndef H8S_NORMAL_MODE
#define H8S_BASE_ADDR	0xff0000	/* ���ɥХ󥹥ɥ⡼�� */
#else /* H8S_NORMAL_MODE */
#define H8S_BASE_ADDR	0x000000	/* �Ρ��ޥ�⡼�� */
#endif /* H8S_NORMAL_MODE */

/*
 *  ����ǥ�����󥳡��ɥ쥸����(CCR)
 */
#define CCR_I		BIT7
#define CCR_UI		BIT6
#define CCR_H		BIT5
#define CCR_U		BIT4
#define CCR_N		BIT3
#define CCR_Z		BIT2
#define CCR_V		BIT1
#define CCR_C		BIT0

/*
 *  �������ƥ�ɥ쥸����(EXR)
 */
#define EXR_T		BIT7		/* �ȥ졼���ӥå� */
#define EXR_I2		BIT2		/* ����ߥޥ����ӥå� */
#define EXR_I1		BIT1		/* ����ߥޥ����ӥå� */
#define EXR_I0		BIT0		/* ����ߥޥ����ӥå� */

/* ����ߥޥ����ӥåȼ����ѥޥ��� */
#define EXR_I_MASK	(EXR_I2|EXR_I1|EXR_I0)

/*
 *  MCUư��⡼�ɴ�Ϣ�Υ쥸����
 */

/* �쥸�����Υ��ɥ쥹 */
#define MDCR		0xff3b		/*  �⡼�ɥ���ȥ���쥸����  */
#define SYSCR		0xff39		/*  �����ƥॳ��ȥ���쥸����  */

/* �ƥ쥸�����Υӥåȥѥ����� */

/* MDCR */
#define MDS2		BIT2
#define MDS1		BIT1
#define MDS0		BIT0

/* SYSCR */
#define INTM1		BIT5
#define INTM0		BIT4
#define NMIEG		BIT3
#define LWROD		BIT2
#define IRQPAS		BIT1
#define RAME		BIT0

#define INT_MODE2	INTM1	/*  ���������⡼�ɣ�  */
#define RAME_BIT	0x0

#endif /* _H8S_H_ */
