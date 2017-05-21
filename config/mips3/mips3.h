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

#ifndef _MIPS3_H_
#define _MIPS3_H_

#include <util.h>

/*
 *  MIPS3 �����
 */

/* CPU�����������쥸������̾�� */
#define zero    $0      /* ������� */
#define at      $1      /* ������֥�Υƥ�ݥ�� */
#define v0      $2      /* �ؿ�������� */
#define v1      $3
#define a0      $4      /* �ؿ��ΰ��� */
#define a1      $5
#define a2      $6
#define a3      $7
#define t0      $8      /* �ƥ�ݥ��쥸���� tx (x=0-9)���ؿ��ƤӽФ����˲� */
#define t1      $9
#define t2      $10
#define t3      $11
#define t4      $12
#define t5      $13
#define t6      $14
#define t7      $15
#define s0      $16     /* sx (x=0-7) : �ؿ��ƤӽФ������Ѥʥ쥸���� */
#define s1      $17
#define s2      $18
#define s3      $19
#define s4      $20
#define s5      $21
#define s6      $22
#define s7      $23
#define t8      $24     /* �ƥ�ݥ��쥸���� tx (x=0-9)���ؿ��ƤӽФ����˲� */
#define t9      $25
#define k0      $26     /* OS�Ѥ�ͽ��Ѥ� */
#define kt0     $26
#define k1      $27
#define kt1     $27
#define gp      $28     /* ����ѿ��ΰ�Υ١������ɥ쥹 */
#define sp      $29     /* �����å��ݥ��� */
#define fp      $30     /* �ե졼��ݥ��� */
/* �⤷���� */
#define s8      $30     /* s8 : �ؿ��ƤӽФ������Ѥʥ쥸���� */
#define ra      $31     /* �ؿ��������ꥢ�ɥ쥹 */

/* CP0�������쥸������̾�� */
#define Index           $0
#define Random          $1
#define EntryLo0        $2
#define EntryLo1        $3
#define Context         $4
#define PageMask        $5
#define Wired           $6
#define Error           $7
#define BadVAddr        $8
#define Count           $9
#define EntryHi         $10
#define Compare         $11
#define Status          $12
#define Cause           $13
#define EPC             $14
#define PRId            $15
#define Config          $16
#define LLAddr          $17
#define WatchLo         $18
#define WatchHi         $19
#define XContext        $20
/* $21-$24 - ͽ�� */
#define Performance     $25
#define ParityErr       $26
#define CacheErr        $27
#define TagLo           $28
#define TagHi           $29
#define ErrorEPC        $30
/* $31 - ͽ�� */

/*  ����饤�󥢥���֥���ǻȤ��������  */
#define str_k0		"$26"
#define str_Status	"$12"

/*  ���ơ������쥸�����ط�  */
#define SR_IE		BIT0			/*  IE�ӥå�  */
#define SR_EXL		BIT1			/*  EXL�ӥå�  */
#define SR_ERL		BIT2			/*  ERL�ӥå�  */

#define SR_EXL_IE	(SR_EXL | SR_IE)	/*  EXL,IE�ӥå�  */
#define SR_ERL_EXL	(SR_ERL | SR_EXL)	/*  ERL,EXL�ӥå�  */
#define SR_ERL_EXL_IE	(SR_ERL_EXL | SR_IE)	/*  ERL,EXL,IE�ӥå�  */
#define SR_IM		0xff00			/*  IM�ӥåȤ���Ф��ޥ���  */

#define SR_UX		BIT5			/*  UX�ӥå�  */
#define SR_SX		BIT6			/*  SX�ӥå�  */
#define SR_KX		BIT7			/*  SX�ӥå�  */
#define SR_DE		BIT16			/*  DE�ӥå�  */
#define SR_SR		BIT20			/*  SR�ӥå�  */
#define SR_BEV		BIT22			/*  BEV�ӥå�  */
#define SR_RE		BIT25			/*  RE�ӥå�  */
#define SR_CU0		BIT28			/*  CU0�ӥå�  */
#define SR_CU1		BIT29			/*  CU1�ӥå�  */
#define SR_CU2		BIT30			/*  CU2�ӥå�  */
#define SR_XX		BIT31			/*  XX�ӥå�  */

/*  �����쥸�����ط�  */
#define Cause_IP0       BIT8    /*  IP0�ӥå�  */
#define Cause_IP1       BIT9    /*  IP1�ӥå�  */
#define Cause_IP2       BIT10   /*  IP2�ӥå�  */
#define Cause_IP3       BIT11   /*  IP3�ӥå�  */
#define Cause_IP4       BIT12   /*  IP4�ӥå�  */
#define Cause_IP5       BIT13   /*  IP5�ӥå�  */
#define Cause_IP6       BIT14   /*  IP6�ӥå�  */
#define Cause_IP7       BIT15   /*  IP7�ӥå�  */

/*  ���������ߤ��Ф���IP�ӥåȤ���̾  */
#define Cause_Int0	Cause_IP2  /*  Int0�׵�ӥå�  */
#define Cause_Int1	Cause_IP3  /*  Int1�׵�ӥå�  */
#define Cause_Int2	Cause_IP4  /*  Int2�׵�ӥå�  */
#define Cause_Int3	Cause_IP5  /*  Int3�׵�ӥå�  */
#define Cause_Int4	Cause_IP6  /*  Int4�׵�ӥå�  */

/*  �����쥸�������鸶�������ɤ���Ф��ޥ���  */
#define ExcCode_mask    0x7c

/* �㳰������ */
#define Int     0       /* �������㳰 */
#define Mod     1       /* TLB�ѹ��㳰 */
#define TLBL    2       /* TLB�԰����㳰 (���ɤޤ���̿��ե��å�) */
#define TLBS    3       /* TLB�԰����㳰 (���ȥ�) */
#define AdEL    4       /* ���ɥ쥹���顼�㳰 (���ɤޤ���̿��ե��å�) */
#define AdES    5       /* ���ɥ쥹���顼�㳰 (���ȥ�) */
#define IBE     6       /* �Х����顼�㳰 (̿��ե��å�) */
#define DBE     7       /* �Х����顼�㳰 (�ǡ����Υ��ɤޤ��ϥ��ȥ�) */
#define Sys     8       /* �����ƥॳ�����㳰 */
#define Bp      9       /* �֥쥤���ݥ�����㳰 */
#define RI      10      /* ͽ��̿���㳰 */
#define CpU     11      /* ���ץ��å������Բ��㳰 */
#define Ov      12      /* �黻�����С��ե��㳰 */
#define Tr      13      /* �ȥ�å��㳰 */
/* 14 - ͽ�� */
#define FPE     15      /* ��ư�������㳰 */
/* 16-22 - ͽ�� */
#define WATCH   23      /* �����å��㳰 */
/* 24-31 - ͽ�� */

/*  ������װ��ֹ�  */
#define INTNO_IP0               0
#define INTNO_IP1               1
#define INTNO_IP2               2
#define INTNO_IP3               3
#define INTNO_IP4               4
#define INTNO_IP5               5
#define INTNO_IP6               6
#define INTNO_IP7               7

/*  �����γ���ߤ��ܿ��ʥ��եȥ���������ߤ�ޤ�� */
#define TMAX_CORE_INTNO		8

/*
 *  MIPS3�����Υ��ơ������쥸�����������ǽ�ʺǹ����ߵ��ĥӥåȥѥ�����
 */
#define MAX_IPM  0xff

/*
 *  MIPS3���������ꤹ�����ߥޥ����Υ����å�
 */
#define CHECK_CORE_IPM(ipm)  CHECK_PAR(0 <= (ipm) && (ipm) <= MAX_IPM)

/*
 *  CPU�㳰�μ����
 */
#define TMAX_CORE_EXCNO	32u

/*
 *  �����ϻ��Υ����å���¤�����
 *    cpu_config.h�ˤ�����cpu_experr�ؿ���cpu_support.S�򻲾ȤΤ��ȡ�
 */
#ifndef _MACRO_ONLY

typedef struct exc_stack {

	/*  �쥸�����������  */
	UW	sp;
	UW	at;
	UW	v0;
	UW	v1;
	UW	a0;
	UW	a1;
	UW	a2;
	UW	a3;
	UW	t0;
	UW	t1;
	UW	t2;
	UW	t3;
	UW	t4;
	UW	t5;
	UW	t6;
	UW	t7;
	UW	t8;
	UW	t9;
	UW	gp;
	UW	fp;
	UW	ra;

	UW	CP0_Status;
	UW	CP0_EPC;

	UW	hi;
	UW	lo;

} EXCSTACK;

#endif /* _MACRO_ONLY */

#endif /* _MIPS3_H_ */
