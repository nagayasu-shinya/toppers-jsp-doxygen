/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2007 by Industrial Technology Institute,
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

#ifndef _UTIL_H_
#define _UTIL_H_

/*
 *  �ӥå��ֹ�����
 */
#define BIT0              0x1u
#define BIT1              0x2u
#define BIT2              0x4u
#define BIT3              0x8u
#define BIT4             0x10u
#define BIT5             0x20u
#define BIT6             0x40u
#define BIT7             0x80u
#define BIT8            0x100u
#define BIT9            0x200u
#define BIT10           0x400u
#define BIT11           0x800u
#define BIT12          0x1000u
#define BIT13          0x2000u
#define BIT14          0x4000u
#define BIT15          0x8000u
#define BIT16         0x10000ul
#define BIT17         0x20000ul
#define BIT18         0x40000ul
#define BIT19         0x80000ul
#define BIT20        0x100000ul
#define BIT21        0x200000ul
#define BIT22        0x400000ul
#define BIT23        0x800000ul
#define BIT24       0x1000000ul
#define BIT25       0x2000000ul
#define BIT26       0x4000000ul
#define BIT27       0x8000000ul
#define BIT28      0x10000000ul
#define BIT29      0x20000000ul
#define BIT30      0x40000000ul
#define BIT31      0x80000000ul


/*
 *  ����ܥ�̾�η��
 */
#define JOINT(a,b)      _JOINT(a,b)
#define _JOINT(a,b)     a##b

#define JOINT3(a,b,c)   _JOINT3(a,b,c)
#define _JOINT3(a,b,c)  JOINT(a,JOINT(b,c))

#define JOINT4(a,b,c,d)   _JOINT4(a,b,c,d)
#define _JOINT4(a,b,c,d)  JOINT(a,JOINT3(b,c,d))

#define HI2(data)	(UH)(data >> 16)
#define LO2(data)	(UH)(data)

#endif /* _UTIL_H_ */
