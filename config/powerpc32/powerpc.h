/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 * 
 *  @(#) $Id: powerpc.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*  
 *   PowerPC�������ƥ������¸�����
 *   ����ա�������32�ӥåȡ�����ץ�������ѤˤʤäƤ���
 *   ��
 *   ��PowerPC�������ƥ����������ϰʲ��Σ��ĤΥ�٥뤫������
 *   ����USIA:User Instruction Set Architecture
 *   ����VEA: Virtual Environment Architecture
 *   ����OEA: Operating Environment Architecture
 *   ��
 *   ��USIA�ˤĤ��Ƥ������ﶦ�̤Ǥ��뤬��VEA��OEA�ˤĤ��Ƥ�
 *   �����ꥸ�ʥ��PowerPC�������ƥ������The IBM PowerPC 
 *   ��Embedded Environment���줾���̤��������Ƥ��뤿�ᡢ
 *   ��VEA��OEA������ϥե������ʬ���ơ�����򥤥󥯥롼��
 *   �����Ƥ��롣
 */   

#ifndef _POWERPC_H_
#define _POWERPC_H_

#include <util.h>


/*  
 *   VEA��OEA�����
 */   

#ifndef IBM_PPC_EMB_ENV
/*  
 *   ���ꥸ�ʥ��PowerPC�������ƥ�����ξ��
 *   ������ȥ���MPC���꡼����IPM PowerPC6xx/7xx���꡼����
 *   ����������˳������롣
 */   
#include <vea_oea.h>

#else	/*  IBM_PPC_EMB_ENV  */
/*  
 *   The IBM PowerPC Embedded Environment�ξ��
 *   ��IBM��PowerPC40x���꡼���б�
 */   
#include <vea_oea_emb.h>

#endif	/*  IBM_PPC_EMB_ENV  */


/*  
 *   UISA�����
 */   

/*  
 *  �쥸�����ֹ�����
 *  ����C������ѿ�̾�Ȥ֤Ĥ��ꤽ���ʤΤǡ�������֥���˸��ꤹ��
 */   
#ifdef _MACRO_ONLY

/* CPU�����������쥸������̾�� */

/*  ���ѥ쥸����  */
#define r0       0      /*  zero�ޤ������ѥ쥸����  */
#define r1       1
#define sp       r1     /*  �����å��ݥ���  */

#define r2       2      /*  TOC��Table of Contents  */
#define r3       3      /*  r3-4�������������  */
#define r4       4
#define r5       5      /*  r5-10������  */
#define r6       6
#define r7       7
#define r8       8
#define r9       9
#define r10     10
#define r11     11
#define r12     12
#define r13     13      /*  r13��small data  */
#define r14     14      /*  r14-30���������ѿ�  */
#define r15     15
#define r16     16
#define r17     17
#define r18     18
#define r19     19
#define r20     20
#define r21     21
#define r22     22
#define r23     23
#define r24     24
#define r25     25
#define r26     26
#define r27     27
#define r28     28
#define r29     29
#define r30     30
#define r31     31
#define fp      r31     /*  �ե졼��ݥ���  */

/*  ��ư�������쥸����  */
#define f0       0
#define f1       1      /*  f1�������������  */
#define f2       2      /*  f2-13������  */
#define f3       3
#define f4       4
#define f5       5
#define f6       6
#define f7       7
#define f8       8
#define f9       9
#define f10     10
#define f11     11
#define f12     12
#define f13     13
#define f14     14      /*  f14-31���������ѿ�  */
#define f15     15
#define f16     16
#define f17     17
#define f18     18
#define f19     19
#define f20     20
#define f21     21
#define f22     22
#define f23     23
#define f24     24
#define f25     25
#define f26     26
#define f27     27
#define f28     28
#define f29     29
#define f30     30
#define f31     31

/*  �ü�쥸����  */
#define XER      1      /* Fixed Point Exception Register  */
			/*  �������ڥ졼�����ξ�Ｑ�̥쥸���� */
			/*  �ʥ���꡼�䥪���Хե��ʤɡ�  */
#define LR       8      /*  ��󥯡��쥸����  */
#define CTR      9      /*  ������ȡ��쥸����  */

#endif  /* _MACRO_ONLY */

#define crf0        0   /*  ����ǥ������쥸����CR�Υե�����ɻ���  */

#endif /* _POWERPC_H_ */
/*  end of file  */
