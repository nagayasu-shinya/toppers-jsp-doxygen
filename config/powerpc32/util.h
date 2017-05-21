/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2004 by Industrial Technology Institute,
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
 *   �ӥå��ֹ�����
 *   ����ա�PowerPC�Υӥå��ֹ���̾�ȵդˤʤäƤ���
 *   ���������ޤ���32�ӥåȥ쥸������16�ӥåȥ쥸�����Ǥ�
 *   ���������ǲ��̥ӥåȤΥӥå��ֹ椬�ۤʤ����ˤ����
 */   

/*  32�ӥåȥ쥸������  */
#define BIT0_32    0x80000000
#define BIT1_32    0x40000000
#define BIT2_32    0x20000000
#define BIT3_32    0x10000000
#define BIT4_32     0x8000000
#define BIT5_32     0x4000000
#define BIT6_32     0x2000000
#define BIT7_32     0x1000000
#define BIT8_32      0x800000
#define BIT9_32      0x400000
#define BIT10_32     0x200000
#define BIT11_32     0x100000
#define BIT12_32      0x80000
#define BIT13_32      0x40000
#define BIT14_32      0x20000
#define BIT15_32      0x10000
#define BIT16_32       0x8000
#define BIT17_32       0x4000
#define BIT18_32       0x2000
#define BIT19_32       0x1000
#define BIT20_32        0x800
#define BIT21_32        0x400
#define BIT22_32        0x200
#define BIT23_32        0x100
#define BIT24_32         0x80
#define BIT25_32         0x40
#define BIT26_32         0x20
#define BIT27_32         0x10
#define BIT28_32          0x8
#define BIT29_32          0x4
#define BIT30_32          0x2
#define BIT31_32          0x1

/*  16�ӥåȥ쥸������  */
#define BIT0_16        0x8000
#define BIT1_16        0x4000
#define BIT2_16        0x2000
#define BIT3_16        0x1000
#define BIT4_16         0x800
#define BIT5_16         0x400
#define BIT6_16         0x200
#define BIT7_16         0x100
#define BIT8_16          0x80
#define BIT9_16          0x40
#define BIT10_16         0x20
#define BIT11_16         0x10
#define BIT12_16          0x8
#define BIT13_16          0x4
#define BIT14_16          0x2
#define BIT15_16          0x1

/*  8�ӥåȥ쥸������  */
#define BIT0_8           0x80
#define BIT1_8           0x40
#define BIT2_8           0x20
#define BIT3_8           0x10
#define BIT4_8            0x8
#define BIT5_8            0x4
#define BIT6_8            0x2
#define BIT7_8            0x1

/*  ����ܥ�̾��ʸ����  */
#define _TO_STRING(arg)	#arg
#define TO_STRING(arg)	_TO_STRING(arg)

#endif /* _UTIL_H_ */
/*  end of file  */
