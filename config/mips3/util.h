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

#ifndef _UTIL_H_
#define _UTIL_H_

/*
 *  �ӥå��ֹ�����
 */
#define BIT0              0x1
#define BIT1              0x2
#define BIT2              0x4
#define BIT3              0x8
#define BIT4             0x10
#define BIT5             0x20
#define BIT6             0x40
#define BIT7             0x80
#define BIT8            0x100
#define BIT9            0x200
#define BIT10           0x400
#define BIT11           0x800
#define BIT12          0x1000
#define BIT13          0x2000
#define BIT14          0x4000
#define BIT15          0x8000
#define BIT16         0x10000
#define BIT17         0x20000
#define BIT18         0x40000
#define BIT19         0x80000
#define BIT20        0x100000
#define BIT21        0x200000
#define BIT22        0x400000
#define BIT23        0x800000
#define BIT24       0x1000000
#define BIT25       0x2000000
#define BIT26       0x4000000
#define BIT27       0x8000000
#define BIT28      0x10000000
#define BIT29      0x20000000
#define BIT30      0x40000000
#define BIT31      0x80000000

/*
 *  �Х��ȥǡ�������ѥޥ���
 */
/* �ʲ��ˤ����ơ�x������ */

/* �ʲ��Τ褦�ʽ����ȡ��ɤä����ɤ�����
     (UH) (((UW) (c)) & 0x0000ffff)
     (UH) (((UW) (c)) & 0xffff0000) >> 16
*/

/* (UH) xxaa -> (UB) aa */
#define LO8(c)		(UB)( (UH)(c) & 0xff )	/*  ����1�Х��ȼ��Ф�  */
/* (UH) aaxx -> (UB) aa */
#define HI8(c)		LO8( (UH)(c) >>  8 )	/*  ���1�Х��ȼ��Ф�  */

/* (UW) xxxxaaaa -> (UH) aaaa */
#define LO16(c)		(UH)( (UW)(c) & 0xffff )/*  ����2�Х��ȼ��Ф�  */
/* (UW) aaaaxxxx -> (UH) aaaa */
#define HI16(c)		LO16( (UW)(c) >> 16 )	/*  ���2�Х��ȼ��Ф�  */

/* (UH) aaaa, (UH) bbbb -> (UW) aaaabbbb */
#define JOIN16(hi, lo)	(UW)( ((UW)(hi) << 16) | (lo) )	/*  2�Х��ȥǡ����η��  */
/* (UB) aa, (UB) bb -> (UH) aabb */
#define JOIN8(hi, lo)	(UH)( ((UH)(hi) <<  8) | (lo) )	/*  1�Х��ȥǡ����η��  */

/* (UB) xxxxaaaa�ʣ��ʿ��� -> (UB) ooooaaaa�ʣ��ʿ��� */
#define TO_LO4(c)	( (UB)(c) & 0xf )		/*  0-3�ӥåȤ�����  */
/* �ʣ��ʿ���xxxxaaaa -> �ʣ��ʿ���aaaaoooo */
#define TO_HI4(c)	(((UB)(c) << 4) & 0xf0)		/*  4-7�ӥåȤ�����  */

/*
 *  ���ͥǡ���ʸ�����ѥޥ���
 */
#define _TO_STRING(arg)	#arg
#define TO_STRING(arg)	_TO_STRING(arg)

#endif /* _UTIL_H_ */
