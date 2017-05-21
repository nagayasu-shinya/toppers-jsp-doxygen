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
 *  @(#) $Id: vea_oea.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*  
 *   PowerPC�������ƥ�����VEA,OEA��¸�����
 *   �����ꥸ�ʥ��PowerPC�������ƥ�����ξ��
 *   ������ȥ���MPC���꡼����IPM PowerPC6xx/7xx���꡼����
 *   ����������˳������롣
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

#ifndef _VEA_OEA_H_
#define _VEA_OEA_H_

/*  
 *  �쥸�����ֹ�����
 */   

/*  
 *  Configuration Register
 */   
#define PVR	287	/*  �ץ��å����С�����󡦥쥸����  */

/*  
 *  Memory Management Registers
 */   
/*  Instruction BAT Registers  */
#define IBAT0U	528
#define IBAT0L	529
#define IBAT1U	530
#define IBAT1L	531
#define IBAT2U	532
#define IBAT2L	533
#define IBAT3U	534
#define IBAT3L	535

/*  Instruction BAT Registers  */
#define DBAT0U	536
#define DBAT0L	537
#define DBAT1U	538
#define DBAT1L	539
#define DBAT2U	540
#define DBAT2L	541
#define DBAT3U	542
#define DBAT3L	543

#define SDR1	 25
#define ASR	280

/*  
 *  Exception Handling Registers
 */   
#define DAR	 19	/*  Data Address Register  */

#define SPRG0   272     /*  �ü�쥸������OS��  */
#define SPRG1   273     /*  �ü�쥸������OS��  */
#define SPRG2   274     /*  �ü�쥸������OS��  */
#define SPRG3   275     /*  �ü�쥸������OS��  */

#define DSISR    18     /*  DSI���ơ��������쥸����(*)  */
                        /*  ��DSI���ǡ��������ȥ������  */
#define SRR0     26     /*  ���������쥸����0  */
#define SRR1     27     /*  ���������쥸����1  */

#define FPECR	1022	/*  Floating-Point Exception Cause Register  */


/*  
 *  Miscellaneous Registers
 */   
/*  Time Base Facility(OEA:for Writing)  */
#define TBLw	284
#define TBUw	285

/*  Time Base Facility(VEA:for Reading)  */
#define TBL	268
#define TBU	269

#define DEC      22     /*  �ǥ�������ȡ��쥸����(*)  */

#define PIR	1023	/*  Processor Identification Register  */

#define DABR	1013	/*  DATA Address Breakpint Register(option)  */
#define EAR	 282	/*  Exception Access Register(option)  */



/*  
 *   �ӥå��ֹ�����
 *   ����ա�PowerPC�Υӥå��ֹ���̾�ȵդˤʤäƤ���
 *   ���������ޤ���32�ӥåȥ쥸������16�ӥåȥ쥸�����Ǥ�
 *   ���������ǲ��̥ӥåȤΥӥå��ֹ椬�ۤʤ����ˤ����
 */   

/*  �ޥ��󥹥ơ������쥸�����γƥӥåȤ����  */
/*  ����ա�32�ӥåȡ�����ץ��������  */
#define MSR_POW BIT13_32    /*  �ѥ�ޥ͡������ȡ����͡��֥�  */
#define MSR_ILE BIT15_32    /*  �㳰�������Υ���ǥ�����⡼��  */
                            /*  ���㳰���ջ���MSR.LE��MSR.ILE  */
#define MSR_EE  BIT16_32    /*  ��������ߥ��͡��֥�  */
#define MSR_PR  BIT17_32    /*  �ø���٥�  */
                            /*  ��0�������ѥХ�������٥�  */
                            /*  ��1���桼������٥�  */
#define MSR_FP  BIT18_32    /*  ��ư���������͡��֥�  */
#define MSR_ME  BIT19_32    /*  �ޥ�������å������͡��֥�  */
#define MSR_FE0 BIT20_32    /*  ��ư�������㳰�⡼��0  */
#define MSR_FE1 BIT23_32    /*  ��ư�������㳰�⡼��1  */
                            /*  ����ա��ֹ椬��Ϣ³  */
#define MSR_SE  BIT21_32    /*  ���󥰥륹�ƥåץȥ졼�������͡��֥�  */
#define MSR_BE  BIT22_32    /*  ʬ���ȥ졼�������͡��֥�  */
#define MSR_IP  BIT25_32    /*  �㳰�ץ�ե��å���  */
                            /*  ��0��0x000n,nnnn  */
                            /*  ��1��0xfffn,nnnn  */
#define MSR_IR  BIT26_32    /*  ̿�ᥢ�ɥ쥹�Ѵ����͡��֥�  */
#define MSR_DR  BIT27_32    /*  �ǡ������ɥ쥹�Ѵ����͡��֥�  */
#define MSR_RI  BIT30_32    /*  ������ǽ���㳰  */
                            /*  ��0:�����Բ�ǽ  */
                            /*  ��1:������ǽ  */
#define MSR_LE  BIT31_32    /*  ��ȥ륨��ǥ����󡦥⡼��  */
                            /*  ��0���ӥå�����ǥ�����  */
                            /*  ��1����ȥ륨��ǥ�����  */
/*  0��ͽ�󤵤�Ƥ���ӥåȤΤ���Υޥ���  */
#define MSR_MASK    ~(BIT0_32 | BIT1_32 | BIT2_32 | BIT3_32 | BIT4_32 \
                    | BIT5_32 | BIT6_32 | BIT7_32 | BIT8_32 | BIT9_32 \
                    | BIT10_32 | BIT11_32 | BIT12_32 | BIT24_32 \
                    | BIT28_32 | BIT29_32)


/*  
 *   CPU�㳰�װ������
 *   ���ֹ椬��Ϣ³�ʤΤ�CPU�㳰�����٥����ơ��֥�˰���̵�̤����뤬��
 *   ��PowerPC�������ƥ����������˹�碌������ͥ�褷����
 */   
#define EXC_NO_SYSTEM_RESET             0x1   /*  �����ƥ�ꥻ�å��㳰  */
#define EXC_NO_MACHINE_CHECK            0x2   /*  �ޥ��󡦥����å��㳰  */
#define EXC_NO_DSI                      0x3   /*  DSI�㳰  */
                                        /*  �ʥǡ��������ꡦ����������  */
#define EXC_NO_ISI                      0x4   /*  ISI�㳰��̿��ե��å���  */
#define EXC_NO_EXTERNAL_INTERRUPT       0x5   /*  ���������  */
#define EXC_NO_ALIGNMENT                0x6   /*  ���饤�����㳰  */
#define EXC_NO_PROGRAM                  0x7   /*  �ץ�����㳰  */
#define EXC_NO_FLOATING_POINT_UNAVAILABLE 0x8   /*  ��ư�����������Բ�  */
#define EXC_NO_DECREMENTER              0x9   /*  �ǥ������㳰  */
                            /*  ����ץ���ơ�������ͭ���㳰0x00a00  */
#define EXC_NO_IMPLEMENT_EXCEPTION_00A00 0xa 
#define EXC_NO_SYSTEM_CALL              0xc /*  �����ƥॳ����  */
#define EXC_NO_TRACE                    0xd /*  �ȥ졼���ʥ��ץ�����  */
#define EXC_NO_FLOATING_POINT_ASSIST    0xe /*  ��ư���������  */
                            /*  ����ץ���ơ�������ͭ���㳰0x01000  */
#define EXC_NO_IMPLEMENT_EXCEPTION_01000 0x10    


/*  
 *   �㳰�μ��̿�
 *   ����������ߤ⣱�Ĥȿ�����
 *   ����0�֤�̤����
 *   ���������㳰�٥����Υ��ե��åȤ��б�
 *   �����������������ߤ⣱�Ĥȿ�����
 *   ����������������Τ��ᡢ+1���Ƥ���
 */   

#ifdef IMPLEMENT_EXCEPTION_01000    /*  �㳰�٥���0x1000����Ѥ�����  */
#define TMAX_EXCNO       ( 0x10 + 1 )

#else /* IMPLEMENT_EXCEPTION_01000 */
#define TMAX_EXCNO       ( 0xe + 1 )

#endif /* IMPLEMENT_EXCEPTION_01000 */




#endif /* _VEA_OEA_H_ */
/*  end of file  */
