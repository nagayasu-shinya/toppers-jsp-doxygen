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

#ifndef _H8S_TPU_H_
#define _H8S_TPU_H_

#include <s_services.h>		/* �ǥХ����ɥ饤����ɸ�।�󥯥롼�ɥե����� */
#include <h8s_sil.h>

/*
 *  H8S��¢16�ӥåȥ����ޥѥ륹��˥å�(TPU)��Ϣ�����
 */

/* TPU��쥸�����Υ��ɥ쥹 */

/* ����ͥ룰 */
#define TCR0		0xffd0		/* �����ޥ���ȥ���쥸������ */
#define TMDR0		0xffd1		/* �����ޥ⡼�ɥ쥸������ */
#define TIOR0H		0xffd2		/* ������I/O����ȥ���쥸�������� */
#define TIOR0L		0xffd3		/* ������I/O����ȥ���쥸�������� */
#define TIER0		0xffd4		/* �����ޥ��󥿥�ץȥ��͡��֥�쥸������ */
#define TSR0		0xffd5		/* �����ޥ��ơ������쥸������ */
#define TCNT0		0xffd6		/* �����ޥ����󥿣� */
#define TGR0A		0xffd8		/* �����ޥ����ͥ��쥸�������� */
#define TGR0B		0xffda		/* �����ޥ����ͥ��쥸�������� */
#define TGR0C		0xffdc		/* �����ޥ����ͥ��쥸�������� */
#define TGR0D		0xffde		/* �����ޥ����ͥ��쥸�������� */

/* ����ͥ룱 */
#define TCR1		0xffe0		/* �����ޥ���ȥ���쥸������ */
#define TMDR1		0xffe1		/* �����ޥ⡼�ɥ쥸������ */
#define TIOR1		0xffe2		/* ������I/O����ȥ���쥸������ */
#define TIER1		0xffe4		/* �����ޥ��󥿥�ץȥ��͡��֥�쥸������ */
#define TSR1		0xffe5		/* �����ޥ��ơ������쥸������ */
#define TCNT1		0xffe6		/* �����ޥ����󥿣� */
#define TGR1A		0xffe8		/* �����ޥ����ͥ��쥸�������� */
#define TGR1B		0xffea		/* �����ޥ����ͥ��쥸�������� */

/* ����ͥ룲 */
#define TCR2		0xfff0		/* �����ޥ���ȥ���쥸������ */
#define TMDR2		0xfff1		/* �����ޥ⡼�ɥ쥸������ */
#define TIOR2		0xfff2		/* ������I/O����ȥ���쥸������ */
#define TIER2		0xfff4		/* �����ޥ��󥿥�ץȥ��͡��֥�쥸������ */
#define TSR2		0xfff5		/* �����ޥ��ơ������쥸������ */
#define TCNT2		0xfff6		/* �����ޥ����󥿣� */
#define TGR2A		0xfff8		/* �����ޥ����ͥ��쥸�������� */
#define TGR2B		0xfffa		/* �����ޥ����ͥ��쥸�������� */

/* ����ͥ룳 */
#define TCR3		0xfe80		/* �����ޥ���ȥ���쥸������ */
#define TMDR3		0xfe81		/* �����ޥ⡼�ɥ쥸������ */
#define TIOR3H		0xfe82		/* ������I/O����ȥ���쥸�������� */
#define TIOR3L		0xfe83		/* ������I/O����ȥ���쥸�������� */
#define TIER3		0xfe84		/* �����ޥ��󥿥�ץȥ��͡��֥�쥸������ */
#define TSR3		0xfe85		/* �����ޥ��ơ������쥸������ */
#define TCNT3		0xfe86		/* �����ޥ����󥿣� */
#define TGR3A		0xfe88		/* �����ޥ����ͥ��쥸�������� */
#define TGR3B		0xfe8a		/* �����ޥ����ͥ��쥸�������� */
#define TGR3C		0xfe8c		/* �����ޥ����ͥ��쥸�������� */
#define TGR3D		0xfe8e		/* �����ޥ����ͥ��쥸�������� */

/* ����ͥ룴 */
#define TCR4		0xfe90		/* �����ޥ���ȥ���쥸������ */
#define TMDR4		0xfe91		/* �����ޥ⡼�ɥ쥸������ */
#define TIOR4		0xfe92		/* ������I/O����ȥ���쥸������ */
#define TIER4		0xfe94		/* �����ޥ��󥿥�ץȥ��͡��֥�쥸������ */
#define TSR4		0xfe95		/* �����ޥ��ơ������쥸������ */
#define TCNT4		0xfe96		/* �����ޥ����󥿣� */
#define TGR4A		0xfe98		/* �����ޥ����ͥ��쥸�������� */
#define TGR4B		0xfe9a		/* �����ޥ����ͥ��쥸�������� */

/* ����ͥ룵 */
#define TCR5		0xfea0		/* �����ޥ���ȥ���쥸������ */
#define TMDR5		0xfea1		/* �����ޥ⡼�ɥ쥸������ */
#define TIOR5		0xfea2		/* ������I/O����ȥ���쥸������ */
#define TIER5		0xfea4		/* �����ޥ��󥿥�ץȥ��͡��֥�쥸������ */
#define TSR5		0xfea5		/* �����ޥ��ơ������쥸������ */
#define TCNT		0xfea6		/* �����ޥ����󥿣� */
#define TGR5A		0xfea8		/* �����ޥ����ͥ��쥸�������� */
#define TGR5B		0xfeaa		/* �����ޥ����ͥ��쥸�������� */

/* ���� */
#define TSTR		0xffc0		/* �����ޥ��ơ��ȥ쥸���� */
#define TSYR		0xffc1		/* �����ޥ��󥯥�쥸���� */

/* �ƥ쥸�����Υӥåȥѥ����� */

/* TCR */
#define CCLR2		BIT7		/* ����ͥ룰�����Τ� */
#define CCLR1		BIT6
#define CCLR0		BIT5
#define CKEG1		BIT4
#define CKEG0		BIT3
#define TPSC2		BIT2
#define TPSC1		BIT1
#define TPSC0		BIT0

/* TMDR */
#define BFB		BIT5		/* ����ͥ룰�����Τ� */
#define BFA		BIT4		/* ����ͥ룰�����Τ� */
#define MD3		BIT3
#define MD2		BIT2
#define MD1		BIT1
#define MD0		BIT0

/* TIOR */
/* TIORx���ޤ��ϡ�TIORxH */
#define IOB3		BIT7
#define IOB2		BIT6
#define IOB1		BIT5
#define IOB0		BIT4
#define IOA3		BIT3
#define IOA2		BIT2
#define IOA1		BIT1
#define IOA0		BIT0

/* TIORxL */
#define IOD3		BIT7
#define IOD2		BIT6
#define IOD1		BIT5
#define IOD0		BIT4
#define IOC3		BIT3
#define IOC2		BIT2
#define IOC1		BIT1
#define IOC0		BIT0

/* TIER */
#define TTGE		BIT7
#define TCIEU		BIT5		/* ����ͥ룱�������������Τ� */
#define TCIEV		BIT4
#define TGIED		BIT3		/* ����ͥ룰�����Τ� */
#define TGIEC		BIT2		/* ����ͥ룰�����Τ� */
#define TGIEB		BIT1
#define TGIEA		BIT0

/* TSR */
#define TCFD		BIT7
#define TCFU		BIT5		/* ����ͥ룱�������������Τ� */
#define TCFV		BIT4
#define TGFD		BIT3		/* ����ͥ룰�����Τ� */
#define TGFC		BIT2		/* ����ͥ룰�����Τ� */
#define TGFB		BIT1
#define TGFA		BIT0

/* TCNT, TGR */
/* ������٤���Τϡ��ä�̵�� */

/* TSTR */
#define CST5		BIT5
#define CST4		BIT4
#define CST3		BIT3
#define CST2		BIT2
#define CST1		BIT1
#define CST0		BIT0

/* TSYR */
#define SYNC5		BIT5
#define SYNC4		BIT4
#define SYNC3		BIT3
#define SYNC2		BIT2
#define SYNC1		BIT1
#define SYNC0		BIT0

#endif /* _H8S_TPU_H_ */
