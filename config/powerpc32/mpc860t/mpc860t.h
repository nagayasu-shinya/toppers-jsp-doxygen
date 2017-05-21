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
 *  @(#) $Id: mpc860t.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *  MPC860�Υϡ��ɥ������񸻤����
 */

#ifndef _MPC860_H_
#define _MPC860_H_

/*
 *  ����ߤ��ܿ�
 */
#define TMAX_SIU_INTNO      16  /*  �����ƥ।�󥿡��ե�������˥å�SIU  */
#define TMAX_CPM_INTNO      32  /*  �̿��ץ��å��⥸�塼��CPM  */
                                /*  MPC860����  */
#define TMAX_INTNO          (TMAX_SIU_INTNO+TMAX_CPM_INTNO)

/*
 *  ����ߴ�Ϣ�����
 *  ��������װ����3������ͤ�������Ƥ���
 *  ������������ֹ�
 *  ������SIU�ؤγ�����׵��٥�
 *  ������������٥������
 *  ������CPM����ߤ����ΤǤҤȤޤȤ�ΰ���
 *  ��������(1) No.��0��7�ο���
 *  ���������������ʹ֤ˤ�ʬ����䤹�������ץ������Ǥ�
 *  ��������������ľ�ܡ����Ѥ���ʤ�
 *  ��������(1-2) ������װ��μ���
 *  �������������������٥����ơ��֥�Υ���ǥå����Ȥ����ɤ߽Ф�
 *  �������������������ʤΤǡ�¨�ͤȤ��ƥޥ���������Ƥ���ɬ�פϤʤ�
 *  ��������������ͽ��2�ӥåȥ��եȤ���Ƥ���
 *  ��������(2) 1�Х��ȤΥӥåȥѥ����� 
 *  ��������������������׵��٥�����ꤹ��ݤ˥쥸�����˥��åȤ�����
 *  ����������������������1�ӥåȤ����򥻥åȤ���
 *  ������SIU��IPM
 *  ������2�Х��ȤΥӥåȥѥ�����
 *  ������CPM����ߤ����ΤǤҤȤޤȤ�ΰ���
 *  ��������(1) ����ߥޥ���
 *  ��������������SIU����ߥ쥸����SIMASK�����ꤹ����
 *  ����������������ʬ����٥���㤤������׵�򤹤٤ƥޥ�������
 *  ��������(2) ��α��γ�����װ�
 *  ����������������������ӥåȤ��������åȤ���Ƥ���
 *  
 *  ��������٥�2-(1)���������ֹ桢����ߥ�٥������ѥӥåȥѥ�����
 *  ��IPM�������������ˤǼ���
 *  
 */

/*
 *  ������ֹ�����
 *      �ϡ��ɥ������ޥ˥奢��ˤ�SIU����ߥ�������16��31�֤�ͽ���
 *      �ߤȤ��뤬�������٥����ơ��֥뤬̵�̤��礭���ʤ�����ʤΤǡ�
 *      CPM����ߥ������������ƤƤ���
 *      
 *      ������ֹ��ͥ���٤δط���SIU����ߤ�CPM����ߡʥǥե���ȡ�
 *      �ǵդʤΤ����
 *      ��SIU�����
 *      ����������ֹ桡��0���Ǿ��
 *      ����������ֹ桡 15���ǲ���
 *      ��CPM����ߡʥǥե���ȡ�
 *      ����������ֹ桡 0x0���ǲ���
 *      ����������ֹ桡0x1f���Ǿ��
 */

    /*  SIU����ߥ�����  */
#define INTNO_IRQ0      0x0     /*  IRQ0  */
#define INTNO_LVL0      0x1     /*  ������٥�0  */
#define INTNO_IRQ1      0x2     /*  IRQ1  */
#define INTNO_LVL1      0x3     /*  ������٥�1  */
#define INTNO_IRQ2      0x4     /*  IRQ2  */
#define INTNO_LVL2      0x5     /*  ������٥�2  */
#define INTNO_IRQ3      0x6     /*  IRQ3  */
#define INTNO_LVL3      0x7     /*  ������٥�3  */
#define INTNO_IRQ4      0x8     /*  IRQ4  */
#define INTNO_LVL4      0x9     /*  ������٥�4  */
#define INTNO_IRQ5      0xa     /*  IRQ5  */
#define INTNO_LVL5      0xb     /*  ������٥�5  */
#define INTNO_IRQ6      0xc     /*  IRQ6 */
#define INTNO_LVL6      0xd     /*  ������٥�6  */
#define INTNO_IRQ7      0xe     /*  IRQ7  */
#define INTNO_LVL7      0xf     /*  ������٥�7  */

    /*  CPM����ߥ�����  */
#define INTNO_ERR       0x10    /*  ���顼��0x0  */
#define INTNO_PC4       0x11    /*  �ѥ���I/O PC4��0x1  */
#define INTNO_PC5       0x12    /*  �ѥ���I/O PC5��0x2  */
#define INTNO_SMC2      0x13    /*  SMC2/PIP��0x3  */
#define INTNO_SMC1      0x14    /*  SMC1��0x4  */
#define INTNO_SPI       0x15    /*  SPI��0x5  */
#define INTNO_PC6       0x16    /*  �ѥ���I/O PC6��0x6  */
#define INTNO_TIMER4    0x17    /*  ������4��0x7  */
/*  CPM������ֹ�8��ͽ��Ѥ�  */
#define INTNO_PC7       0x19    /*  �ѥ���I/O PC7��0x9  */
#define INTNO_PC8       0x1a    /*  �ѥ���I/O PC8��0xa  */
#define INTNO_PC9       0x1b    /*  �ѥ���I/O PC9��0xb  */
#define INTNO_TIMER3    0x1c    /*  ������3��0xc  */
/*  CPM������ֹ�0xd��ͽ��Ѥ�  */
#define INTNO_PC10      0x1e    /*  �ѥ���I/O PC10��0xe  */
#define INTNO_PC11      0x1f    /*  �ѥ���I/O PC11��0xf  */
#define INTNO_I2C       0x20    /*  I2C��0x10  */
#define INTNO_RISC      0x21    /*  RISC�����ޥơ��֥롧0x11  */
#define INTNO_TIMER2    0x22    /*  ������2��0x12  */
/*  CPM������ֹ�0x13��ͽ��Ѥ�  */
#define INTNO_IDMA2     0x24    /*  IDMA2��0x14  */
#define INTNO_IDMA1     0x25    /*  IDMA1��0x15  */
#define INTNO_SDMA      0x26    /*  SDMA����ͥ�Х����顼��0x16  */
#define INTNO_PC12      0x27    /*  �ѥ���I/O PC12��0x17  */
#define INTNO_PC13      0x28    /*  �ѥ���I/O PC13��0x18  */
#define INTNO_TIMER1    0x29    /*  ������1��0x19  */
#define INTNO_PC14      0x2a    /*  �ѥ���I/O PC14��  */
#define INTNO_SCC4      0x2b    /*  SCC4��0x1a  */
#define INTNO_SCC3      0x2c    /*  SCC3��0x1c  */
#define INTNO_SCC2      0x2d    /*  SCC2��0x1d  */
#define INTNO_SCC1      0x2e    /*  SCC1��0x1e  */
#define INTNO_PC15      0x2f    /*  �ѥ���I/O PC15��0x1f  */

/*
 *  SIU��IPM�����
 *    2�Х��ȤΥӥåȥѥ�����
 *    �ϡ��ɥ������Υǥե���Ȥ�ͥ���٤˹�碌�Ƥ���
 */
#define IPM_IRQ0	0x00u			/*  IRQ0  */
#define IPM_LVL0	BIT0_16			/*  ������٥�0  */
#define IPM_IRQ1	(IPM_LVL0 | BIT1_16)	/*  IRQ1  */
#define IPM_LVL1	(IPM_IRQ1 | BIT2_16)	/*  ������٥�1  */
#define IPM_IRQ2	(IPM_LVL1 | BIT3_16)	/*  IRQ2  */
#define IPM_LVL2	(IPM_IRQ2 | BIT4_16)	/*  ������٥�2  */
#define IPM_IRQ3	(IPM_LVL2 | BIT5_16)	/*  IRQ3  */
#define IPM_LVL3	(IPM_IRQ3 | BIT6_16)	/*  ������٥�3  */
#define IPM_IRQ4	(IPM_LVL3 | BIT7_16)	/*  IRQ4  */
#define IPM_LVL4	(IPM_IRQ4 | BIT8_16)	/*  ������٥�4  */
#define IPM_IRQ5	(IPM_LVL4 | BIT9_16)	/*  IRQ5  */
#define IPM_LVL5	(IPM_IRQ5 | BIT10_16)	/*  ������٥�5  */
#define IPM_IRQ6	(IPM_LVL5 | BIT11_16)	/*  IRQ6  */
#define IPM_LVL6	(IPM_IRQ6 | BIT12_16)	/*  ������٥�6  */
#define IPM_IRQ7	(IPM_LVL6 | BIT13_16)	/*  IRQ7  */
#define IPM_LVL7	(IPM_IRQ7 | BIT14_16)	/*  ������٥�7  */


/*  ����ߥ�٥뤫�������ֹ�ؤ��Ѵ�  */
#define _LEVEL_TO_INHNO(level)      INTNO_LVL##level
#define  LEVEL_TO_INHNO(level)      _LEVEL_TO_INHNO(level)

/*  ����ߥ�٥뤫����Ͽ�ѥӥåȥѥ�����ؤ��Ѵ�  */
#define _LEVEL_TO_BIT_PATTERN(level)      (0x1<<(7-(level)))
#define  LEVEL_TO_BIT_PATTERN(level)      _LEVEL_TO_BIT_PATTERN(level)

/*  ����ߥ�٥뤫��IPM�ؤ��Ѵ�  */
#define _LEVEL_TO_IPM(level)      IPM_LVL##level
#define  LEVEL_TO_IPM(level)      _LEVEL_TO_IPM(level)

/*  ����ߥ�٥뤫�����ߵ��ĥӥåȤؤ��Ѵ�  */
#define _LEVEL_TO_ENABLE_BIT(level)  SIMASK_LVM##level
#define  LEVEL_TO_ENABLE_BIT(level)  _LEVEL_TO_ENABLE_BIT(level)


/*
 *  CPU�������쥸����
 */

/*
 *   8. ̿�ᥭ��å��塦�ǡ�������å����Ϣ�����
 */

/*  ����쥸���� */

/*  ̿�ᥭ��å����Ϣ */
#define IC_CST	560	/*  ���椪��ӥ��ơ��������쥸���� */
#define IC_ADR	561	/*  ���ɥ쥹���쥸����  */
#define IC_DAT	562	/*  �ǡ������ݡ��ȡ��쥸����  */

/*  �ǡ���������å����Ϣ */
#define DC_CST	568	/*  ���椪��ӥ��ơ��������쥸���� */
#define DC_ADR	569	/*  ���ɥ쥹���쥸����  */
#define DC_DAT	570	/*  �ǡ������ݡ��ȡ��쥸����  */

/*
 *   9. ���������˥å�MMU��Ϣ�����
 */
/*  ����쥸����  */
#define MI_CTR	784	/*  IMMU ����쥸����  */
#define MD_CTR	792	/*  DMMU ����쥸����  */

/*  TLB���������쥸����  */
#define MI_EPN	787	/*  IMMU �¸��ڡ����ֹ�쥸����  */
#define MD_EPN	795	/*  DMMU �¸��ڡ����ֹ�쥸����  */
#define MI_TWC	789	/*  IMMU �ơ��֥륦����������쥸����  */
#define MD_TWC	797	/*  DMMU �ơ��֥륦����������쥸����  */
#define MI_RPN	790	/*  IMMU �¡�ʪ���˥ڡ����ֹ�ݡ���  */
#define MD_RPN	798	/*  DMMU �¡�ʪ���˥ڡ����ֹ�ݡ���  */

/*  �ơ��֥륦���������١������쥸����  */
#define M_TWD	796	/*  MMU �ơ��֥륦���������١������쥸����  */

/*  �ݸ�쥸����  */
#define M_CASID	793	/*  MMU �����ȡ����ɥ쥹����ID �쥸����  */
#define MI_AP	786	/*  IMMU ���������ݸ�쥸����  */
#define MD_AP	794	/*  DMMU ���������ݸ�쥸����  */

/*  ������å����쥸����  */
#define M_TB	799	/*  MMU �ơ��֥륦�����������ڥ���롦�쥸����  */

/*  �ǥХå����쥸����  */
#define MI_CAM	816	/*  IMMU CAM ����ȥꡦ�꡼�ɡ��쥸����  */
#define MI_RAM0	817	/*  IMMU RAM ����ȥꡦ�꡼�ɡ��쥸���� 0  */
#define MI_RAM1	818	/*  IMMU RAM ����ȥꡦ�꡼�ɡ��쥸���� 1  */
#define MD_CAM	824	/*  DMMU CAM ����ȥꡦ�꡼�ɡ��쥸����  */
#define MD_RAM0	825	/*  DMMU RAM ����ȥꡦ�꡼�ɡ��쥸���� 0  */
#define MD_RAM1	826	/*  DMMU RAM ����ȥꡦ�꡼�ɡ��쥸���� 1  */

/*
 *  11. �����ƥ।�󥿡��ե�������˥å�SIU��Ϣ�����
 */


/*
 *  ��������ޥåץ쥸����
 *  ���������쥸����������Ƭ���ɥ쥹
 *  ����
 *  �������ꥻ�å�ľ���0x0000,0000���Ϥ�ؤ��Ƥ��뤬SDRAM��
 *  �������֤Ĥ���Τǡ��̤Υ��ɥ쥹���Ѥ���ɬ�פ�����
 */
#define IMMR        638                 /*  �쥸�����ֹ�  */
#define IMMR_UPPER_2BYTE  0xff00              /*  ���16�ӥå�  */
#define IMMR_BASE   (IMMR_UPPER_2BYTE << 16)  /*  �١������ɥ쥹  */  

#define TADR_SIU_SIUMCR  0x0    /* SIU�⥸�塼�륳��ե�����졼����� */
                                /*                     �쥸����SIUMCR  */

/*
 *  11.5 SIU����ߥ���ȥ����Ϣ�����
 */
#define TADR_SIU_SIPEND 0x10    /* SIU�������α�쥸����SIPEND */
#define TADR_SIU_SIMASK 0x14    /* SIU����ߥޥ����쥸����SIMASK */

				/*  ���2�Х��ȤΤ߻��Ѥ���  */
#define SIMASK		(VH *)(IMMR_BASE + TADR_SIU_SIMASK)
#define SIMASK_IRM0	BIT0_16		/*  IRQ0  */
#define SIMASK_LVM0	BIT1_16		/*  ������٥�0  */
#define SIMASK_IRM1	BIT2_16		/*  IRQ1  */
#define SIMASK_LVM1	BIT3_16		/*  ������٥�1  */
#define SIMASK_IRM2	BIT4_16		/*  IRQ2  */
#define SIMASK_LVM2	BIT5_16		/*  ������٥�2  */
#define SIMASK_IRM3	BIT6_16		/*  IRQ3  */
#define SIMASK_LVM3	BIT7_16		/*  ������٥�3  */
#define SIMASK_IRM4	BIT8_16		/*  IRQ4  */
#define SIMASK_LVM4	BIT9_16		/*  ������٥�4  */
#define SIMASK_IRM5	BIT10_16	/*  IRQ5  */
#define SIMASK_LVM5	BIT11_16	/*  ������٥�5  */
#define SIMASK_IRM6	BIT12_16	/*  IRQ6  */
#define SIMASK_LVM6	BIT13_16	/*  ������٥�6  */
#define SIMASK_IRM7	BIT14_16	/*  IRQ7  */
#define SIMASK_LVM7	BIT15_16	/*  ������٥�7  */

#define TADR_SIU_SIEL   0x18    /* SIU����ߥ��å�����٥�쥸����SIEL */
#define TADR_SIU_SIVEC  0x1c    /* SIU����ߥ٥����쥸����SIVEC */
#define TADR_SIU_TESR   0x20    /* ž�����顼���ơ������쥸����TESR */
#define TADR_SIU_SDCR   0x30    /* SDMA����ե�����졼�����쥸����SDCR */

/*
 *  11.7 ���եȥ������������å��ɥå������޴�Ϣ�����
 */
#define TADR_SIU_SYPCR   0x4    /* �����ƥ��ݸ��ȥ���쥸����SYPCR */
#define SYPCR_SWE 	 BIT29_32  /*  ���͡��֥�  */
#define SYPCR_SWRI 	 BIT30_32  /*  �ꥻ�åȡ����������  */ 
#define TADR_SIU_SWSR    0xe       /* ���եȥ����������ӥ��쥸����SWSR */
#define SWSR_CLEAR1      0x556c    /* ���ꥢ���˽񤭹�������� */
#define SWSR_CLEAR2      0xaa39    /* ���ꥢ���˽񤭹�������� */

/*
 *  12 �ꥻ�åȴ�Ϣ�����
 */
#define TADR_SIU_RSR  0x288  /* �ꥻ�åȡ����ơ��������쥸����RSR */
#define TADR_SIU_RSRK 0x388  /* �ꥻ�åȡ����ơ��������쥸���������� */
#define RSR_EHRS BIT0_32    /* �����ϡ��ɡ��ꥻ�åȡ����ơ����� */
#define RSR_ESRS BIT1_32    /* �������եȡ��ꥻ�åȡ����ơ����� */
#define RSR_LLRS BIT2_32    /* ��å�����ꥻ�åȡ����ơ����� */
#define RSR_SWRS BIT3_32    /* ���եȥ������������å��ɥå����ꥻ�å� */
#define RSR_CSRS BIT4_32    /* �����å������ȥåס��ꥻ�åȡ����ơ����� */
    		/* �ǥХå����ݡ��ȡ��ϡ��ɡ��ꥻ�åȡ����ơ����� */
#define RSR_DBHRS BIT5_32
    		/* �ǥХå����ݡ��ȡ����եȡ��ꥻ�åȡ����ơ����� */
#define RSR_DBSRS BIT6_32
#define RSR_JTRS BIT4_32    /* JTAG�ꥻ�åȡ����ơ����� */


/*
 *  �̿��ץ��å��⥸�塼��CPM��Ϣ
 */

/*
 *  35. CPM����ߥ���ȥ����Ϣ�����
 */
#define TADR_CPM_CIVR   0x930   /* CPM����ߥ٥����쥸����CIVR */
#define TADR_CPM_CICR   0x940   /* CPM����ߥ���ե�����졼����� */
                                /*                   �쥸����CICR  */
#define TADR_CPM_CIPR   0x944   /* CPM�������α�쥸����CIPR */
#define TADR_CPM_CIMR   0x948   /* CPM����ߥޥ����쥸����CIMR */
#define TADR_CPM_CISR   0x94c   /* CPM����ߥ��󥵡��ӥ��쥸����CISR */

/* CPM����ߥ���ե�����졼����� �쥸����CICR */
#define CICR            (VW *)(IMMR_BASE + TADR_CPM_CICR)
#define CICR_IEN        BIT24_32

/* CPM����ߥޥ����쥸����CIMR */
#define CIMR            (VW *)(IMMR_BASE + TADR_CPM_CIMR)
#define CIMR_PC15       BIT0_32     
#define CIMR_SCC1       BIT1_32     
#define CIMR_SCC2       BIT2_32     
#define CIMR_SCC3       BIT3_32     
#define CIMR_SCC4       BIT4_32     
#define CIMR_PC14       BIT5_32     
#define CIMR_TIMER1     BIT6_32     
#define CIMR_PC13       BIT7_32     
#define CIMR_PC12       BIT8_32     
#define CIMR_SDMA       BIT9_32     
#define CIMR_IDMA1      BIT10_32        
#define CIMR_IDMA2      BIT11_32        
#define CIMR_TIMER2     BIT13_32        
#define CIMR_RTT        BIT14_32        
#define CIMR_I2C        BIT15_32        
#define CIMR_PC11       BIT16_32        
#define CIMR_PC10       BIT17_32        
#define CIMR_TIMER3     BIT19_32        
#define CIMR_PC9        BIT20_32        
#define CIMR_PC8        BIT21_32        
#define CIMR_PC7        BIT22_32        
#define CIMR_TIMER4     BIT24_32        
#define CIMR_PC6        BIT25_32        
#define CIMR_SPI        BIT26_32        
#define CIMR_SMC1       BIT27_32        
#define CIMR_SMC2       BIT28_32        
#define CIMR_PC5        BIT29_32        
#define CIMR_PC4        BIT30_32        

/* CPM����ߥ��󥵡��ӥ��쥸����CISR */
#define CISR            (VW *)(IMMR_BASE + TADR_CPM_CISR)
#define CISR_BIT(device)	_CISR_BIT(device)
#define _CISR_BIT(device)	CIMR_##device

/*
 *  CPM���������ӥåȤ����
 */
    /*  CPM����ߥ٥����쥸����CIVR�쥸������IACK�ӥå�  */
#define TA_CPM_CIVR_IACK    0x1 


/*
 *  15. ����å���������������Ϣ�Υ쥸�������
 */

/*  �����ƥ९��å�����ӥꥻ�å�����쥸����  */
#define TADR_SCCR   0x280
#define SCCR        (VW *)(IMMR_BASE + TADR_SCCR)
#define TADR_SCCRK  0x380       /*  �����쥸����  */
#define SCCRK       (VW *)(IMMR_BASE + TADR_SCCRK)

#define SCCR_RTDIV  BIT7_32     /*  �ꥢ�륿���९��å�ʬ��  */
                                /*  0��4��ʬ����1��512��ʬ��  */
#define SCCR_RTSEL  BIT8_32     /*  �ꥢ�륿���९��å�����  */
                                /*  0��OSCM�ʿ徽�����졼���ˡ�1��EXTCLK  */
#define SCCR_CRQEN  BIT9_32     /*  CPM�׵ᥤ�͡��֥�  */
#define SCCR_PRQEN  BIT10_32    /*  �ѥ�ޥͥ������׵ᥤ�͡��֥�  */
#define SCCR_EBDF   (BIT13_32 | BIT14_32)   /*  �����Х�ʬ������  */
#define SCCR_DFBRG  (BIT19_32 | BIT20_32)   /*  BRGCLK��ʬ������  */

/*  SPLL �������ϡ�����ӥꥻ�å�����쥸����  */
#define TADR_PLPRCRK    0x384   /*  �쥸����������  */
#define TADR_PLPRCR     0x284   
#define PLPRCR_TIMIST   BIT19_32    /*  �����޳���ߥ��ơ�����  */
#define PLPRCR_CSRC     BIT21_32    /*  ����å�������  */
                                    /*  �����ϥ⡼��  */
#define PLPRCR_LPM      (BIT22_32 | BIT23_32)
#define PLPRCR_LPM10    BIT22_32


/*
 *  16. ���ꥳ��ȥ���Υ쥸�������
 */

/*  �١����쥸����BRx  */
#define TADR_BR0    0x100
#define TADR_BR1    0x108
#define TADR_BR2    0x110
#define TADR_BR3    0x118
#define TADR_BR4    0x120
#define TADR_BR5    0x128
#define TADR_BR6    0x130
#define TADR_BR7    0x138

/*  ���ץ����쥸����ORx  */
#define TADR_OR0    0x104
#define TADR_OR1    0x10c
#define TADR_OR2    0x114
#define TADR_OR3    0x11c
#define TADR_OR4    0x124
#define TADR_OR5    0x12c
#define TADR_OR6    0x134
#define TADR_OR7    0x13c

#define TADR_MAMR   0x170   /*  �ޥ���A�⡼�ɡ��쥸����  */
#define TADR_MBMR   0x174   /*  �ޥ���B�⡼�ɡ��쥸����  */
#define TADR_MSTAT  0x178   /*  ���ꥹ�ơ��������쥸����MSTAT  */

#define TADR_MCR    0x168   /*  ���ꡦ���ޥ�ɡ��쥸����MCR  */
#define TADR_MDR    0x17c   /*  ���ꡦ�ǡ������쥸����MDR  */
#define TADR_MAR    0x164   /*  ���ꡦ���ɥ쥹���쥸����MAR  */
#define TADR_MPTPR  0x17a   /*  ������������ޡ��ץꥹ������  */
                            /*  ���������������������쥸����MPTPR  */

/*
 *  19. �̿��ץ��å�CP��Ϣ�Υ쥸�������
 */

/*  CP���ޥ�ɥ쥸����  */
#define CPCR        (VH *)(IMMR_BASE + 0x9c0)
#define CPCR_RST            BIT0_16  /*  �ꥻ�åȡ��ե饰  */
#define CPCR_FLG            BIT15_16 /*  ���ޥ�ɡ����ޥե����ե饰 */
#define CPCR_CH_NUM_SMC1    0x9      /*  SMC1�Υ���ͥ��ֹ�  */

/*  CP���ޥ�ɤΥ��ڥ�����  */
#define CPCR_INIT_RX_TX_PARAMETERS	0x0
#define CPCR_STOP_TX			0x4
#define CPCR_RESTART_TX			0x6



/*  �ǥ奢�롦�ݡ���RAM����Ƭ���ɥ쥹  */
#define DUAL_PORT_RAM   (IMMR_BASE + 0x2000)


/*
 *  20. SDMA�����IDMA���ߥ�졼�����
 *  ��������SDMA�����ꥢ��DMA
 *  ��������IDMA������SDMA
 */

/*  SDMA����ե�����졼����󡦥쥸����  */
#define SDCR            (VW *)(IMMR_BASE + 0x30)
	/* RISC����ȥ����CP�ˤ�Ĵ��ID */
	/* SDMA ��U �Х�Ĵ��ͥ����5���̾���� */
#define SDCR_RAID_RB5   0x1

/*
 *  21. ���ꥢ�륤�󥿡��ե�����SI��Ϣ�Υ쥸�������
 */

/*  SI�⡼�ɡ��쥸����  */
#define SIMODE      (VW *)(IMMR_BASE + 0xae0)
#define SIMODE_SMC1 BIT16_32    /*  SMC1����³  */
                                /*  ��0:NMSI�⡼��  */
                                /*  ��1:¿�Ž����⡼��  */

                                /*  SMC1����å�������  */
#define SIMODE_SMC1CS   (BIT17_32 | BIT18_32 | BIT19_32)    

/*  �ܡ��졼�ȡ������ͥ졼��������ե�����졼����󡦥쥸����  */
#define BRGC1       (VW *)(IMMR_BASE + 0x9f0)
#define BRGC1_RST   BIT14_32    /*  BRG�ꥻ�å�  */
#define BRGC1_EN    BIT15_32    /*  BRG������ȥ��͡��֥�  */
#define BRGC1_EXTC  (BIT16_32 | BIT17_32)   /*  ��������å�������  */
#define BRGC1_ATB   BIT18_32    /*  �����ȥܡ�  */
#define BRGC1_CD    0x1ffe      /*  ����å����ǥХ���  */
#define BRGC1_DIV16 BIT31_32    /*  16ʬ��  */


/*
 *  34. �ѥ���I/O��Ϣ�Υ쥸�������
 */

/*  �ݡ���B�ԥ󡦥������󡦥쥸����  */
#define TADR_PBPAR  0xabc
#define PBPAR       (VW *)(IMMR_BASE + TADR_PBPAR)
#define PBPAR_DD24  BIT24_32    /*  PB24�ԥ����ѥڥ�ե���뵡ǽ  */
#define PBPAR_DD25  BIT25_32    /*  PB25�ԥ����ѥڥ�ե���뵡ǽ  */
#define PBPAR_DD27  BIT27_32    /*  PB27�ԥ����ѥڥ�ե���뵡ǽ  */

/*  �ݡ���B�ǡ������ǥ��쥯����󡦥쥸����  */
#define TADR_PBDIR  0xab8
#define PBDIR       (VW *)(IMMR_BASE + TADR_PBDIR)
#define PBDIR_DR24  BIT24_32    /*  PB24�ԥ󡧥ڥ�ե���뵡ǽ1  */
#define PBDIR_DR25  BIT25_32    /*  PB25�ԥ󡧥ڥ�ե���뵡ǽ1  */
#define PBDIR_DR27  BIT27_32    /*  PB25�ԥ󡧥ڥ�ե���뵡ǽ1  */

/*  �ݡ���B�����ץ󡦥ɥ쥤�󡦥쥸����  */
#define TADR_PBODR  0xac0
#define PBODR       (VW *)(IMMR_BASE + TADR_PBODR)
#define PBODR_OD24  BIT24_32    /*  PB24�ԥ󡧥����ץ󡦥ɥ쥤�󡦥ɥ饤��  */
#define PBODR_OD25  BIT25_32    /*  PB25�ԥ󡧥����ץ󡦥ɥ쥤�󡦥ɥ饤��  */
#define PBODR_OD27  BIT27_32    /*  PB25�ԥ󡧥����ץ󡦥ɥ쥤�󡦥ɥ饤��  */

/*  �ݡ���B�ǡ����쥸����  */
#define TADR_PBDAT  0xac4
#define PBDAT_D27   BIT27_32


/*  �����å��κݤ˥����쥸�����˽񤭹������  */
#define UNLOCK_KEY  0x55ccaa33

/*
 *  �����쥸�����ݸ�Υ�å��ȥ����å�
 *
 *�������ꥢ��ɥ饤�Фȥ����ޥɥ饤�Ф�ξ�����Ѥ��뤿�ᡢ
 *�������Υե����������Ƥ���
 */

/*  SCCR��å�  */
    	/*  �ͤ�UNLOCK_KEY�ʳ��Ǥ�����ɤ�  */
#define lock_sccr()     mpc860_wrw_mem(SCCRK, 0)

/*  SCCR�����å�  */
#define unlock_sccr()	mpc860_wrw_mem(SCCRK, UNLOCK_KEY)


#endif /* _MPC860_H_ */
/*  end of file  */
