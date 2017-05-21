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
 *  @(#) $Id: vea_oea_emb.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*  
 *   PowerPC�������ƥ�����VEA,OEA��¸�����
 *   ��The IBM PowerPC Embedded Environment�ξ��
 *   ����IBM��PowerPC40x�ե��ߥꤳ����˳������롣
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


#ifndef _VEA_OEA_EMB_H_
#define _VEA_OEA_EMB_H_

/*  
 *  �쥸�����ֹ�����
 */   

/*
 *  Special Purpose Register�Υ쥸�����ֹ�
 *  ����(*)��������PowerPC�������ƥ�����Ǥ��������Ƥ��ʤ��쥸����
 */

/*
 *  �㳰�����˴ؤ���쥸����
 */
#define SRR0	  26	/* Save/Restore Register0  */
#define SRR1	  27	/* Save/Restore Register1  */
#define SRR2	 990	/* Save/Restore Register2(*)  */
#define SRR3	 991	/* Save/Restore Register3(*)  */
#define ESR	 980	/* Exception Syndrome Register(*)  */
#define DEAR	 981	/* Data Exception Address Register(*)  */
#define EVPR	 982	/* Exception Vector Prefix Register(*)  */

#define SPRG0	 272	/* SPR General 0  */
#define SPRG1	 273	/* SPR General 1  */
#define SPRG2	 274	/* SPR General 2  */
#define SPRG3	 275	/* SPR General 3  */

/*
 *  ����¾�Υ쥸����
 */
#define DAC	1014	/* Data Address Compare(*) */
#define DBCR	1010	/* Debug Control Register(*) */
#define DBSR	1008	/* Debug Status Register(*) */
#define DCCR	1018	/* Data Cache Cacheability Register(*) */
#define DCWR	 954	/* Data Cache Write-thru Register(*) */

#define IAC	1012	/* Instruction Address Compare(*) */
#define ICCR	1019	/* Instruction Cache Cacheability Register(*) */

#define PID	 945	/* Process ID Register  */
#define PIT	 987	/* Programmable Interval Timer(*) */
#define PVR	 287	/* Processor Version Register  */

#define SGR	 953	/* Storage Guarded Register(*) */
#define SLER	 955	/* Storage Little-Endian Register(*) */
#define SMR	 952	/* Storage Memory-Coherent Register(*) */

/*  VEA  */
#define TBL	 268	/* Time Base Lower(for read)  */
#define TBU	 269	/* Time Base Upper(for read)  */
/*  OEA  */
#define TBLw	 284	/* Time Base Lower(for write)  */
#define TBUw	 285	/* Time Base Upper(for write)  */

#define TCR	 986	/* Timer Control Registe(*) */
#define TSR	 984	/* Timer Status Register(*) */
#define ZPR	 944	/* Zone Protection Register(*) */

/*
 *  MSR�Υӥå�����
 */
/*  0-10:Reserved  */
#define MSR_APE	BIT11_32	/* Auxiliary Processor Exception Enable */
#define MSR_APA	BIT12_32	/* Auxiliary Processor Available */
#define MSR_WE	BIT13_32	/* Wait State Enable */
#define MSR_CE	BIT14_32	/* Critical Enable */
#define MSR_ILE	BIT15_32	/* Interrupt Little Endian */
#define MSR_EE	BIT16_32	/* External Enable */
#define MSR_PR	BIT17_32	/* Problem State */
#define MSR_FP	BIT18_32	/* Floating Point Available */
#define MSR_ME	BIT19_32	/* Machine Check Enable */
#define MSR_FE0	BIT20_32	/* Floating Point Exception Mode 0 */
/*  21:Reserved  */
#define MSR_DE	BIT22_32	/* Debug Interrupts Enable */
#define MSR_FE1	BIT23_32	/* Floating Point Exception Mode 1 */
/*  23-25:Reserved  */
#define MSR_IR	BIT26_32	/* Instruction Relocate */
#define MSR_DR	BIT27_32	/* Data Relocate */
/*  28-30:Reserved  */
#define MSR_LE	BIT31_32	/* Little Endian */


/*
 *  ESR(Exception Syndrome Register)�Υӥå�����
 */
#define ESR_PIL	BIT4_32	 /* Program - Illegal Instruction exception */
#define ESR_PPR	BIT5_32	 /* Program - Privileged Instruction exception */
#define ESR_PTR	BIT6_32	 /* Program - Trap exception */
#define ESR_PFE	BIT7_32	 /* Program - Floating Point Enabled exception */
#define ESR_DST	BIT8_32	 /* Data Storage / Data TLB Miss - Store Operations */
#define ESR_DIZ	BIT9_32	 /* Data / Instruction Storage - Zone exception */
	/* Program - Auxiliary Processor Unavailable exception */
#define ESR_PAU	BIT12_32
	/* Program - Floating Point Enabled but Unimplemented exception */
#define ESR_PFEU BIT13_32
	/* Program - Auxiliary Processor Enabled exception */
#define ESR_PAE	BIT14_32


/*  
 *   CPU�㳰�װ������
 *   ���ֹ椬��Ϣ³�ʤΤ�CPU�㳰�����٥����ơ��֥�˰���̵�̤����뤬��
 *   ��PowerPC�������ƥ����������˹�碌������ͥ�褷����
 */   
#define EXC_NO_CRITICAL_INPUT           	0x1
#define EXC_NO_MACHINE_CHECK            	0x2
#define EXC_NO_DATA_STORAGE             	0x3
#define EXC_NO_INSTRUCTION_STORAGE      	0x4
#define EXC_NO_EXTERNAL_INTERRUPT       	0x5   /*  ���������  */
#define EXC_NO_ALIGNMENT                	0x6
			/*  �ץ�����㳰���װ������*/
#define EXC_NO_PROGRAM                  	0x7
#define EXC_NO_FLOATING_POINT_UNAVAILABLE 	0x8
/*  ��APU�����PowerPC405��440�Τߡ�  */

/*  0x900��Reserved  */
/*  0xa00��Reserved  */
/*  0xb00��Reserved  */
#define EXC_NO_SYSTEM_CALL              	0xc	/*  �����ƥॳ����  */
/*  0xd00��Reserved  */
/*  0xe00��Reserved  */
/*  0xe10-0xff0��Reserved  */
/* 0x1000��Programmable Interval Timer  */
/* 0x1010��Fixed Interval Timer  */
/* 0x1020��Watchdog Timer  */
/* 0x1030-0x10f0��Reserved  */
/* 0x1100��Data TLB miss  */
/* 0x1110-0x11f0��Reserved  */
/* 0x1200��Instruction TLB miss  */
/* 0x1210-0x1ff0��Reserved  */
/* 0x2000��Debug���װ������   */
/* 0x2010-0x2ff0��Implementation Specific  */

/*  
 *   �㳰�μ��̿�
 *   ����������ߤ⣱�Ĥȿ�����
 *   ����0�֤�̤����
 *   ���������㳰�٥����Υ��ե��åȤ��б�
 *   �����������������ߤ⣱�Ĥȿ�����
 *   ����������������Τ��ᡢ+1���Ƥ���
 */   

#define TMAX_EXCNO       ( 0x20 + 1 + NUM_IMPLEMENT_EXCEPTION )


/*
 *  DCR�ؤΥ�������
 *     DCR:Device Control Register
 *     �ʲ��Υ롼����ϥǥХ����ɥ饤�и����˺������Ƥ��롣
 *     DCR�ζ���Ū��̾�Τ䵡ǽ�ϥǥХ�����¸�Ǥ��롣
 *     
 *     ����
 *     ��mfdcr,mtdcr̿���DCR���ֹ�����ѥ쥸�����ǤϤʤ���
 *     ��¨�ͤǻ��ꤹ�뤿�ᡢ����饤��ؿ��ˤǤ��ʤ���
 */

/*
 *  DCR�θ����ͤ��ɽФ�
 *     reg:�쥸�����ֹ�����������
 *     val:�ɤ߽Ф����ͤ��Ǽ�����ѿ���UW����
 */
#define _sil_rew_dcr(reg, val)	Asm("mfdcr %0," #reg : "=r"(val))
#define sil_rew_dcr(reg, val)	_sil_rew_dcr(reg, val)

/*
 *  DCR�θ����ͤ��ѹ�
 *     reg:�쥸�����ֹ�����������
 *     val:���ꤹ���ͤ���Ǽ���줿�ѿ���UW����
 */
#define _sil_wrw_dcr(reg, val)	Asm("mtdcr "#reg",%0" : : "r"(val) )
#define sil_wrw_dcr(reg, val)	_sil_wrw_dcr(reg, val)


#endif /* _VEA_OEA_EMB_H_ */
/*  end of file  */
