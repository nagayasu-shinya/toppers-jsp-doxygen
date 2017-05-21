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

#ifndef _VR4131_ICU_H_
#define _VR4131_ICU_H_

/*
 *  ����ߥ���ȥ���(ICU)�ط������
 */

/*  ������ֹ�������0-7�֤� mips3.h �ǻ��ѡ�8�ְʹߤ���ꤹ�롣�� */
/*  SYSINT1REG  */
#define INTNO_BAT        8	/*  �Хåƥ�����  */
#define INTNO_POWER      9	/*  �ѥ�����å������  */
#define INTNO_RTCL1     10	/*  RTCLong1�����  */
#define INTNO_ETIME     11	/*  ElipsedTime�����޳���� */
#define INTNO_GIU       12	/*  GIU�����  */
#define INTNO_SIU       13	/*  SIU�����  */
#define INTNO_SOFTINT   14	/*  ���եȥ����������  */
#define INTNO_CLKRUN    15	/*  CLKRUN�����  */

/*  SYSINT2REG  */
#define INTNO_RTCL2     16	/*  RTCLong2�����  */
#define INTNO_LED       17	/*  LED�����  */
#define INTNO_TCLK      18	/*  TClock�����󥿳����  */
#define INTNO_FIR       19	/*  FIR�����  */
#define INTNO_DSIU      20	/*  DSIU�����  */
#define INTNO_PCI       21	/*  PCI�����  */
#define INTNO_SCU       22	/*  SCU�����  */
#define INTNO_CSI       23	/*  CSI�����  */
#define INTNO_BCU       24	/*  BCU�����  */

/*  ����ߥ���ȥ��餬�����������ߤ��ܿ�  */
#define TMAX_ICU_INTNO	17u

/*  ����ߥ���ȥ���Υ쥸�����Υ��ɥ쥹���  */
/* �ʲ��� xxx_asm��xxx_offset �ϡ�������֥�Ǥ����Ѹ����� */
#define ICU_BASE_ADDR		0x0f000000
#define ICU_BASE_ADDR_asm	ASM_SIL( ICU_BASE_ADDR )

#define SYSINT1_offset		0x80
#define MSYSINT1_offset		0x8c
#define MDSIUINT_offset		0x96
#define SYSINT2_offset		0xa0
#define MSYSINT2_offset		0xa6

#define MSYSINT1REG	(ICU_BASE_ADDR + MSYSINT1_offset)
				/* �����ƥ����ߥޥ����쥸����1(��٥�1) */
#define MDSIUINTREG	(ICU_BASE_ADDR + MDSIUINT_offset)
				/* DSIU����ߥޥ����쥸����(��٥�2)  */
#define MSYSINT2REG	(ICU_BASE_ADDR + MSYSINT2_offset)
				/* �����ƥ����ߥޥ����쥸����2(��٥�1) */

/*  ������װ��ӥåȥѥ����� (������������֥���ʬ�Ǥ����Ѥ��Ƥ��롣) */
/* MSYSINT1REG / SYSINT1REG �ط� */
#define CLKRUNINTR	BIT12	/* CLKRUN ����� */
#define SOFTINTR	BIT11	/* ���եȥ���������� */
#define SIUINTR		BIT9	/* SIU ����� */
#define	GIUINTR		BIT8	/* GIU(����) ����� */
#define	ETIMERINTR	BIT3	/* ElapsedTime������ ����� */
#define RTCL1INTR	BIT2	/* RTCLong1������ ����� */
#define POWERINTR	BIT1	/* �ѥ�����å������ */
#define BATINTR		BIT0	/* �Хåƥ����� */

/* MSYSINT2REG / SYSINT2REG �ط� */
#define BCUINTR		BIT9	/* BCU ����� */
#define CSIINTR		BIT8	/* CSI ����� */
#define SCUINTR		BIT7	/* SCU ����� */
#define PCIINTR		BIT6	/* PCI ����� */
#define DSIUINTR	BIT5	/* DSIU ����� */
#define FIRINTR		BIT4	/* FIR ����� */
#define TCLKINTR	BIT3	/* VTClock������ ����� */
#define LEDINTR		BIT1	/* LED ����� */
#define RTCL2INTR	BIT0	/* RTCLong2 ����� */

/* MDSIUINTREG �ط� */
#define INTDSIU  	BIT11	/* DSIU���Ѳ�����ߵ��� */

/*
 *  ����ߥ���ȥ���γ���ߥޥ����ط�
 */

/*  ��¤��ICU_IPM��Υ��ե��åȤ���뤿��Υޥ����makeoffset.c���Ѥ����
    �ʤ������Υޥ������������ͤϡ��ä����Ѥ��Ƥ��ʤ���*/
#define OFFSET_DEF_ICU_IPM	OFFSET_DEF(ICU_IPM, msysint2)

/*  MSYSINT1,2�����ꤷ�ƤϤ����ʤ��ӥå�  */
#define NG_BIT_MSYSINT1	(BIT4 | BIT5 | BIT6 | BIT7 | BIT10 | BIT13 |BIT14 | BIT15)
#define NG_BIT_MSYSINT2	(BIT2 | BIT10 | BIT11 | BIT12 | BIT13 | BIT14 | BIT15)

/*  ����ߥ���ȥ�������ꤹ�����ߥޥ����Υ����å�  */
#define CHECK_ICU_IPM(ipm)						\
		CHECK_PAR(!(ipm.msysint1 & NG_BIT_MSYSINT1));		\
		CHECK_PAR(!(ipm.msysint2 & NG_BIT_MSYSINT2))

#ifndef _MACRO_ONLY

/*  ����ߥ���ȥ�����Ф������ߥޥ����ε����ơ��֥�  */
extern ICU_IPM icu_intmask_table[];

/*  ����ߥ���ȥ����intmask�ơ��֥������  */
Inline void icu_set_ilv(INTNO intno, ICU_IPM *ipm) {
	/* CHECK_ICU_IPM(ipm) �ϡ���̥롼����Ǽ¹ԺѤ� */
	icu_intmask_table[intno].msysint1 = ipm->msysint1;
	icu_intmask_table[intno].msysint2 = ipm->msysint2;
}

/*  �����ߥ���ȥ���Υޥ�������  */
Inline void icu_set_ipm(ICU_IPM *ipm) {
	/* CHECK_ICU_IPM(ipm) �ϡ���̥롼����Ǽ¹ԺѤ� */
	vr4131_wrh_mem( (VP) MSYSINT1REG, ipm->msysint1 );
	vr4131_wrh_mem( (VP) MSYSINT2REG, ipm->msysint2 );
}

/*  �����ߥ���ȥ���Υޥ�������  */
Inline void icu_get_ipm(ICU_IPM *ipm) {
	ipm->msysint1 = vr4131_reh_mem( (VP) MSYSINT1REG );
	ipm->msysint2 = vr4131_reh_mem( (VP) MSYSINT2REG );
}

#endif /* _MACRO_ONLY */

/*============================================================================*/
/*  ������֥�����ط�  */

/*  ����ߵ��ĥӥåȤ����������  */
/*  ����ߥ���ȥ���ICU��IPM�򥹥��å�����¸  */
#define PUSH_ICU_IPM						\
    li      t1, ICU_BASE_ADDR_asm;				\
    addi    sp, sp, -2*2;					\
    lh      t3, MSYSINT1_offset(t1);	/* t3 = MSYSINT1REG */	\
    lh      t4, MSYSINT2_offset(t1);	/* t4 = MSYSINT2REG */	\
    sh      t3, (sp);						\
    sh      t4, 2(sp)

/*  ����ߥ���ȥ���ICU��IPM�򥹥��å���������  */
#define POP_ICU_IPM							      \
    li      t1, ICU_BASE_ADDR_asm;					      \
    lw      t3, (sp);			/* t3 = MSYSINT2REG:MSYSINT1REG */    \
					/* ��ա���ȥ륨��ǥ������¸ */    \
    sh      t3, MSYSINT1_offset(t1);	/* MSYSINT1REG = t3�β���2�Х���*/    \
    srl     t4, t3, 16;							      \
    sh      t4, MSYSINT2_offset(t1);	/* MSYSINT2REG = t3�ξ��2�Х���*/    \
    addi    sp, sp, 2*2

/*  ����ߥ���ȥ���ICU��IPM������  */
/*      t0�˳�����װ��ֹ椬���ä����֤ǸƤФ��  */
/*      t0�����Ƥ�����ƤϤ����ʤ�  */
/*      t1�˳�����׵᥯�ꥢ����������äƤ���Τ��˲����ƤϤʤ�ʤ���  */
#define SET_ICU_IPM							      \
    la      t4, icu_intmask_table;	/* �ǡ����ơ��֥����Ƭ���ɥ쥹 */    \
    sll     t2, t0, 2;			/* ���ե��åȡ������װ��ֹ��4�� */ \
    li      t3, ICU_BASE_ADDR_asm;					      \
    add     t4, t4, t2;			/* ��Ƭ���ɥ쥹�ܥ��ե��å� */        \
    lw      t5, (t4);			/* t5 = MSYSINT2REG:MSYSINT1REG */    \
					/* ��ա���ȥ륨��ǥ������¸ */    \
    sh      t5, MSYSINT1_offset(t3);	/* MSYSINT1REG = t5�β���2�Х��� */   \
    srl     t6, t5, 16;							      \
    sh      t6, MSYSINT2_offset(t3)	/* MSYSINT2REG = t5�ξ��2�Х��� */

/*  �ǥХ���̾������̽�����Ÿ������ޥ���
      ������װ��� t0 ������� proc_END ������  */
#define MAKE_PROC(device)	\
proc_##device:			\
    li      t0, INTNO_##device;	\
    j       proc_END;		\
    nop;

/*  ������װ���Ƚ��  */
/*    ����ߥ���ȥ����MIPS3������Int0����³����Ƥ���ޥ����Υ����å� */
#define PROC_INT0						\
/*  �����ޤα�������夲�뤿�ᡢSYSINT2REG����Ĵ�٤�  */	\
    li      t1, ICU_BASE_ADDR_asm;				\
    lh      t3, SYSINT2_offset(t1);    /* t3 = SYSINT2REG */	\
    lh      t4, MSYSINT2_offset(t1);   /* t4 = MSYSINT2REG */	\
    and     t5, t3, t4;     /*  ������׵�ӥåȤ˥ޥ���  */	\
    beq     t5, zero, proc_SYSINT1;				\
    andi    t6, t5, (BIT0 | BIT1 | BIT2 | BIT3 | BIT4 );	\
    beq     t6, zero, proc_SYSINT2_HIGH_5BIT;			\
								\
/*  SYSINT2REG (b0:4) �ν���  */				\
    andi    t7, t5, ( RTCL2INTR | LEDINTR );			\
    beq     t7, zero, proc_SYSINT2_BIT3_4;			\
    andi    t8, t5, LEDINTR;					\
    beq     t8, zero, proc_LED;					\
MAKE_PROC(RTCL2);						\
MAKE_PROC(LED);							\
								\
proc_SYSINT2_BIT3_4:						\
    andi    t1, t5, TCLKINTR;					\
    beq     t1, zero, proc_FIR;					\
MAKE_PROC(TCLK);						\
MAKE_PROC(FIR);							\
								\
/*  SYSINT2REG (b5:9) �ν���  */				\
proc_SYSINT2_HIGH_5BIT:						\
    andi    t7, t5, (DSIUINTR | PCIINTR);			\
    beq     t7, zero, proc_SYSINT2_BIT7_7;			\
    andi    t2, t5, DSIUINTR;					\
    beq     t2, zero, proc_PCI;					\
MAKE_PROC(DSIU);						\
MAKE_PROC(PCI);							\
								\
proc_SYSINT2_BIT7_7:						\
    andi    t3, t5, SCUINTR;					\
    beq     t3, zero, proc_SYSINT2_BIT8_9;			\
MAKE_PROC(SCU);							\
								\
proc_SYSINT2_BIT8_9:						\
    andi    t4, t5, CSIINTR;					\
    beq     t4, zero, proc_BCU;					\
MAKE_PROC(CSI);							\
MAKE_PROC(BCU);							\
								\
/*  SYSINT1REG�Υ����å�  */					\
/*  t1��ICU_BASE_ADDR�����ä����֤Ǥ��������  */		\
proc_SYSINT1:							\
    lh      t3, SYSINT1_offset(t1);	/* t3 = SYSINT1REG */	\
    lh      t4, MSYSINT1_offset(t2);	/* t4 = MSYSINT1REG */	\
    and     t5, t3, t4;     /*  ������׵�ӥåȤ˥ޥ���  */	\
    andi    t6, t5, 0xff;					\
    beq     t6, zero, proc_SYSINT1_HIGH_BYTE;			\
								\
/*  SYSINT1REG (���̥Х���) �ν���  */				\
    andi    t7, t5, (BATINTR | POWERINTR);			\
    beq     t7, zero, proc_SYSINT1_BIT2_3;			\
    andi    t8, t5, BATINTR;					\
    beq     t8, zero, proc_POWER;				\
MAKE_PROC(BAT);							\
MAKE_PROC(POWER);						\
								\
proc_SYSINT1_BIT2_3:						\
    andi    t1, t5, ETIMERINTR;					\
    beq     t1, zero, proc_ETIME;				\
MAKE_PROC(RTCL1);						\
MAKE_PROC(ETIME);						\
								\
/*  SYSINT1REG (��̥Х���) �ν���  */				\
proc_SYSINT1_HIGH_BYTE:						\
    andi    t8, t5, (GIUINTR | SIUINTR);			\
    beq     t8, zero, proc_SYSINT1_BIT11_12;			\
    andi    t9, t5, GIUINTR;					\
    beq     t9, zero, proc_SIU;					\
MAKE_PROC(GIU);							\
MAKE_PROC(SIU);							\
								\
proc_SYSINT1_BIT11_12:						\
    andi    t1, t5, SOFTINTR;					\
    beq     t1, zero, proc_CLKRUN;				\
MAKE_PROC(SOFTINT);						\
MAKE_PROC(CLKRUN);						\
								\
proc_END:

/*============================================================================*/

/* ����߽����˴ؤ��롢������װ���Ƚ��ʬ�������Υ����ƥ��¸�� */

	/*  �ƤӽФ��줿�Ȥ���       */
	/*    a1�˥��ơ������쥸���� */
	/*    a2�˸����쥸����       */
	/*  ���ͤ����äƤ���         */

#define PROC_INTERRUPT_SYS							\
	and     t2, a2, a1;          /*  ������׵�ӥåȤ˥ޥ����򤫤���  */	\
	andi    t3, t2, Cause_IP0;   /*  IP0�ӥåȼ��Ф�  */			\
	bne     t3, zero, proc_IP0;						\
	andi    t4, t2, Cause_IP1;   /*  IP1�ӥåȼ��Ф�  */			\
	bne     t4, zero, proc_IP1;						\
	andi    t5, t2, Cause_IP2;   /*  IP2�ӥåȼ��Ф�  */			\
	bne     t5, zero, proc_IP2;						\
	andi    t6, t2, Cause_IP3;   /*  IP3�ӥåȼ��Ф�  */			\
	bne     t6, zero, proc_IP3;						\
	andi    t7, t2, Cause_IP4;   /*  IP4�ӥåȼ��Ф�  */			\
	bne     t7, zero, proc_IP4;						\
	nop;									\
	/* VR4131�ξ�硢Cause_IP5��Cause_IP6��̤��³�ʤΤǾ�ά */		\
	/*�ʥϡ��ɥ�������p196���ȡ�*/						\
										\
	/* �ʤ�餫�θ�����ʬ���Ǥ��ʤ���� */					\
	j       join_interrupt_and_exception;					\
	nop;									\
										\
										\
/*  MIPS3������٥��ʬ��������٥�Ǥν���		*/			\
/*    ������װ��ֹ�� t0 �������			*/			\
/*    ������׵᥯�ꥢ�Τ��������� t1 �������	*/			\
/*    set_ICU_IPM ������				*/			\
proc_IP7:   /*  ������װ�IP7�ʥ����ޡˤξ��  */				\
	xori    t1, zero, Cause_IP7;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP7;						\
										\
proc_IP0:   /*  ������װ�IP0�ʥ��եȥ����������0�ˤξ��  */			\
	xori    t1, zero, Cause_IP0;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP0;						\
										\
proc_IP1:   /*  ������װ�IP1�ʥ��եȥ����������1�ˤξ��  */			\
	xori    t1, zero, Cause_IP1;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP1;						\
										\
proc_IP2:   /*  ������װ�IP2��Int0�ˤξ��  */					\
            /*  �֤��٤Ƥγ���ߡפ����Τ���롣*/				\
	PROC_INT0;	/* ʬ�������� vr4131_icu.h �ǥޥ����������Ƥ��� */	\
	xori    t1, zero, Cause_IP2;						\
	j       set_ICU_IPM;							\
	nop;									\
										\
proc_IP3:   /*  ������װ�IP3��Int1�ˤξ��  */ 				\
            /*  ��rtc_long1_intr�סʥ��󥿡��Х륿���ޡˤ����Τ���롣*/	\
	xori    t1, zero, Cause_IP3;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP3;						\
										\
proc_IP4:   /*  ������װ�IP4��Int2�ˤξ��  */ 				\
            /*  ��rtc_long2_intr�סʥ��󥿡��Х륿���ޡˤ����Τ���롣*/	\
	xori    t1, zero, Cause_IP4;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP4;						\
										\
/*  ����ߥ���ȥ����¸�Υޥ�������  */					\
set_ICU_IPM:									\
										\
	SET_ICU_IPM;	/* ����ߥޥ��������ꤹ��ޥ���			    */	\
			/*   ������Ԥ��Ȥ��ˤϡ������ˤ�t0��t1�����Ѥ���� */	\
			/*   ���˲����ʤ��褦�ˡ���դ��ʤ���Фʤ�ʤ���   */	\
										\
/*  �����쥸����IP�ӥåȤ��ݻ�����Ƥ���Ƽ����ߤγ�����׵�򥯥ꥢ���롣	\
    t1�ˤϡ�������׵�ӥåȤ�ȿž������Τ����äƤ��롣 */			\
										\
	mfc0    t8, Cause;							\
	and     t8, t8, t1;							\
	mtc0    t8, Cause;							\
										\
/*  ���ơ������쥸�����Υޥ��������C����롼����ƤӽФ�  */			\
/*    t0�˳�����װ��ֹ椬���ꤵ�줿���֤Ǥ��������  */			\
	la      t3, int_table;   /* �����٥������ɥ쥹 */			\
	sll     t4, t0, 3;       /* ������װ��ֹ��8��				\
				      INT_TABLE���ϡ�				\
					�ϥ�ɥ�Υ��ɥ쥹(4�Х���)		\
					��MIPS3�����γ���ߥޥ���(4�Х���)	\
				      �Ρ����8�Х��ȡ� */			\
	add     t5, t3, t4;      /* �٥������ɥ쥹�򻻽� */			\
	lw      t6, INT_TABLE_intmask(t5);					\
           		    	/*  IPM(����ߵ��ĥӥå�)�ɤ߽Ф���		\
				    ����ߥޥ����ʳ����ͤϡ�			\
					IE�ӥåȤϥ��å�			\
					EXL�ӥåȤϥꥻ�å�			\
				    ���֤ˤʤäƤ��롣*/			\
	lw      t7, (t5);        /* C����롼������Ƭ���ɥ쥹�ɤ߽Ф�  */	\
										\
	jalr    ra, t7;          /* C����롼����ƤӽФ�  */			\
	mtc0    t6, Status;      /* ����ߵ��ġ����ơ������쥸�����Υޥ�������*/\
										\
	mfc0    t0, Status;							\
	ori     t0, t0, SR_EXL;  /* ����߶ػߡ�IE�ӥåȤ��ͤ��ݻ����ʤ���Фʤ�\
						�ʤ��Τ�EXL�ӥåȤ��Ѥ��롣*/	\
	mtc0    t0, Status;							\
										\
	/*  CP0�ϥ����ɤΤ���λ��ֲԤ�  */					\
	NOP_FOR_CP0_HAZARD;

#endif /* _VR4131_ICU_H_ */
