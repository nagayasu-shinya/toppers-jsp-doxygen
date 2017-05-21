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

#ifndef _PIC_ICU_H_
#define _PIC_ICU_H_

#ifndef _MACRO_ONLY
#include <sil.h>
#endif /* _MACRO_ONLY */

#include <rte_vr5500_cb.h>	/* ICU_BASE_ADDR */

/*
 *  ����ߥ���ȥ���(Programable Interrupt Controler)�ط������
 */

/*  ������ֹ�������0-7��mips3.h�ǻ��ѡ�8�ʹߤ���ꤹ�롣�� */
#define INTNO_TIMER0	 8	/*  �����ޣ�      */
#define INTNO_SERIAL0	 9	/*  ���ꥢ�룰    */
#define INTNO_GBUS	10	/*  GBUS-INT0-    */
#define	INTNO_BUS_ERR	11	/*  BUS_ERROR     */
#define	INTNO_TIMER1	12	/*  �����ޣ�      */
#define INTNO_SERIAL1	13	/*  ���ꥢ�룱    */
#define INTNO_PARALEL	14	/*  �ѥ���      */
#define INTNO_DMAC	15	/*  DMAC_INTREQ-  */

/*  ����ߥ���ȥ��餬�����������ߤ��ܿ�  */
#define TMAX_ICU_INTNO	8u

/*  ����ߥ���ȥ���Υ쥸�����Υ��ɥ쥹���  */
/* �ʲ���xxx_offset�ϡ�������֥�ǻȤ��� */
#define INT0M_offset	0x00
#define INT1M_offset	0x10
#define INTR_offset	0x20
#define INTEN_offset	0x30

#define ICU_INT0M	INT0M_offset
#define ICU_INT1M	INT1M_offset
#define ICU_INTR	INTR_offset
#define ICU_INTEN	INTEN_offset

/*  ������װ��ӥåȥѥ����� (������������֥���ʬ�Ǥ����Ѥ��Ƥ��롣) */
#define TIMER0		BIT0
#define SERIAL0		BIT1
#define GBUS		BIT2
#define	BUS_ERR		BIT3
#define	TIMER1		BIT4
#define SERIAL1		BIT5
#define PARALEL		BIT6
#define DMAC		BIT7

/* ICU��Υ쥸�������������Ѥδؿ�  */
#define icu_reb( addr )		sil_reb_mem( (VP)(ICU_BASE_ADDR + addr) )
#define icu_wrb( addr, val )	sil_wrb_mem( (VP)(ICU_BASE_ADDR + addr), val )

#define icu_orb( mem, val )	icu_wrb( mem, icu_reb( mem ) | val )
#define icu_andb( mem, val )	icu_wrb( mem, icu_reb( mem ) & val )

/*
 *  ����ߥ���ȥ���γ���ߥޥ����ط�
 */

/*  ��¤��ICU_IPM��Υ��ե��åȤ���뤿��Υޥ����makeoffset.c���Ѥ����
    �ʤ������Υޥ������������ͤϡ��ä����Ѥ��Ƥ��ʤ���*/
#define OFFSET_DEF_ICU_IPM	OFFSET_DEF(ICU_IPM, int1m)

/*  ����ߥ���ȥ���������ǽ�ʳ���ߥޥ����ӥåȥѥ�����ʺǹ��͡�*/
#define MAX_ICU_IPM  0xff

/*  ����ߥ���ȥ�������ꤹ�����ߥޥ����Υ����å�  */
#define CHECK_ICU_IPM(ipm)						       \
		CHECK_PAR( 0 < (ipm.int0m) && (ipm.int0m) <= MAX_ICU_IPM );    \
		CHECK_PAR( 0 < (ipm.int1m) && (ipm.int1m) <= MAX_ICU_IPM )

#ifndef _MACRO_ONLY

/*  ����ߥ���ȥ�����Ф������ߥޥ����ε����ơ��֥�  */
extern ICU_IPM icu_intmask_table[];

/*  ����ߥ���ȥ����intmask�ơ��֥������  */
Inline void icu_set_ilv(INTNO intno, ICU_IPM *ipm) {
	/* CHECK_ICU_IPM(ipm) �ϡ���̥롼����Ǽ¹ԺѤ� */
	icu_intmask_table[intno].int0m = ipm->int0m;
	icu_intmask_table[intno].int1m = ipm->int1m;
}

/*  �����ߥ���ȥ���Υޥ�������  */
Inline void icu_set_ipm(ICU_IPM *ipm) {
	/* CHECK_ICU_IPM(ipm) �ϡ���̥롼����Ǽ¹ԺѤ� */
	icu_wrb( (VP) ICU_INT0M, ipm->int0m );
	icu_wrb( (VP) ICU_INT1M, ipm->int1m );
}

/*  �����ߥ���ȥ���Υޥ�������  */
Inline void icu_get_ipm(ICU_IPM *ipm) {
	ipm->int0m = icu_reb( (VP) ICU_INT0M );
	ipm->int1m = icu_reb( (VP) ICU_INT1M );
}

#endif /* _MACRO_ONLY */

/*============================================================================*/
/*  ������֥�����ط�  */

/*  ����ߵ��ĥӥåȤ����������  */
/*  ����ߥ���ȥ���ICU��IPM�򥹥��å�����¸  */
/*  ��ɶ����δط��ǡ������1�Х��ȤΥޥ����ǤϤ��뤱��ɤ⡢
    ��ɶ����Τ����2�Х���ñ�̤ǰ���ɬ�פ����롣 */
#define PUSH_ICU_IPM						\
	li	t1, ICU_BASE_ADDR;				\
	addi	sp, sp, -2*2;					\
	lb	t3, INT0M_offset(t1);	/* t3 = INT0M */	\
	lb	t4, INT1M_offset(t1);	/* t4 = INT1M */	\
	sh	t3, (sp);					\
	sh	t4, 2(sp)

/*  ����ߥ���ȥ���ICU��IPM�򥹥��å���������  */
#define POP_ICU_IPM						\
	li	t1, ICU_BASE_ADDR;				\
	lh	t3, (sp);					\
	lh	t4, 2(sp);					\
	sb	t3, INT0M_offset(t1);	/* INT0M = t3 */	\
	sb	t4, INT1M_offset(t1);	/* INT1M = t4 */	\
	addi	sp, sp, 2*2

/*  ����ߥ���ȥ���ICU��IPM������  */
/*      t0�˳�����װ��ֹ椬���ä����֤ǸƤФ��  */
/*      t0�����Ƥ�����ƤϤ����ʤ�  */
/*      t1�˳�����׵᥯�ꥢ����������äƤ���Τ��˲����ƤϤʤ�ʤ���  */
#define SET_ICU_IPM								\
	la	t4, icu_intmask_table;	/*  �ǡ����ơ��֥����Ƭ���ɥ쥹  */	\
	sll	t2, t0, 1;		/*  ���ե��åȡ������װ��ֹ��2��	\
						(�ޥ����ϡ�2�Х���)  */		\
	li	t3, ICU_BASE_ADDR;						\
	add	t4, t4, t2;		/*  ��Ƭ���ɥ쥹�ܥ��ե��å�  */	\
	lh	t5, (t4);		/*  t5 = INT0M:INT1M  */		\
					/*  ��ա���ȥ륨��ǥ������¸  */	\
	sb	t5, INT0M_offset(t3);	/*  INT0M=t5�β���1�Х���  */		\
	srl	t6, t5, 8;							\
	sb	t6, INT1M_offset(t3);	/*  INT1M=t5�ξ��1�Х���  */

/*  �ǥХ���̾������̽�����Ÿ������ޥ���  */
/*    ������װ���t0������� proc_END ������  */
#define MAKE_PROC(device)		\
proc_##device:				\
	li	t0, INTNO_##device;	\
 	j	proc_END;		\
	nop;

/*  ������װ���Ƚ��  */
/*    ����ߥ���ȥ����MIPS3������Int0����³����Ƥ���  */
/*    �ޥ����Υ����å�*/
#define PROC_INT0				\
	li      t2, ICU_BASE_ADDR;		\
	lb      t3, INTR_offset(t2);		\
	lb	t4, INT0M_offset(t2);		\
	and	t5, t3, t4;		/* INT0M �ȥޥ��� */	\
	beq	t5, zero, proc_END;		\
	nop;					\
						\
proc_BIT0:					\
	andi	t4, t3, TIMER0;			\
	beq	t4, zero, proc_BIT1;		\
	nop;					\
MAKE_PROC(TIMER0)				\
						\
proc_BIT1:					\
	andi	t4, t3, SERIAL0;		\
	beq	t4, zero, proc_BIT2;		\
	nop;					\
MAKE_PROC(SERIAL0)				\
						\
proc_BIT2:					\
	andi	t4, t3, GBUS;			\
	beq	t4, zero, proc_BIT3;		\
	nop;					\
MAKE_PROC(GBUS)					\
						\
proc_BIT3:					\
	andi	t4, t3, BUS_ERR;		\
	beq	t4, zero, proc_BIT4;		\
	nop;					\
MAKE_PROC(BUS_ERR)				\
						\
proc_BIT4:					\
	andi	t4, t3, TIMER1;			\
	beq	t4, zero, proc_BIT5;		\
	nop;					\
MAKE_PROC(TIMER1)				\
						\
proc_BIT5:					\
	andi	t4, t3, SERIAL1;		\
	beq	t4, zero, proc_BIT6;		\
	nop;					\
MAKE_PROC(SERIAL1)				\
						\
proc_BIT6:					\
	andi	t4, t3, PARALEL;		\
	beq	t4, zero, proc_BIT7;		\
	nop;					\
MAKE_PROC(PARALEL)				\
						\
proc_BIT7:					\
	andi	t4, t3, DMAC;			\
	beq	t4, zero, proc_END;		\
	nop;					\
MAKE_PROC(DMAC)					\
						\
proc_END:

#endif /* _PIC_ICU_H_ */
