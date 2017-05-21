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
 *  @(#) $Id: sys_config.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���MPC860T TB6102S�ѡ�
 *���������������ͥ������ǻ��Ѥ������
 *�������������ǡ��������ޥ����ؿ��Υץ�ȥ��������
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �桼�����������
 */
#include <user_config.h>

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include <sys_rename.h>

/*
 *  �������åȥ����ƥ�Υϡ��ɥ������񸻤����
 */
#include <tb6102s.h>
#include <mpc860t.h>


/*
 *  ��ư��å������Υ������åȥ����ƥ�̾
 */
#define	TARGET_NAME	"TANBAC TB6102S CompactPCI CPU Board"

/*
 *  ���������Ԥ��Τ�������
 */
#ifdef DOWNLOAD_TO_RAM      /*  �ǥХå���  */

#define	SIL_DLY_TIM1	1425
#define	SIL_DLY_TIM2	 350

#else /* DOWNLOAD_TO_RAM */ /*  ROM��  */

#define	SIL_DLY_TIM1	3445
#define	SIL_DLY_TIM2	 867

#endif /* DOWNLOAD_TO_RAM */

#ifndef _MACRO_ONLY

/*
 *  �������åȥ����ƥ��¸�ν����
 */
extern void	sys_initialize(void);

/*
 *  �������åȥ����ƥ�ν�λ
 *
 *  �����ƥ��λ������˻Ȥ���
 *����ROM��˥���GDB STUB�ƽФ���̤����
 */
extern void	sys_exit(void);

/*
 *  �������åȥ����ƥ��ʸ������
 *
 *  �����ƥ�����٥��ʸ�����ϥ롼����
 *����ROM��˥���GDB STUB�ƽФ���̤����
 */
extern void	sys_putc(char c) throw();

#endif /* _MACRO_ONLY */

/*
 * ��CPM�ؤγ�����׵�Υ��ꥢ
 * ����CPM����ߥ��󥵡��ӥ��쥸����CISR�γ����ӥåȤˣ��򥻥åȤ����
 * �������ꥢ����롣
 */
#define CLEAR_IRQ_TO_ICU(device)		\
	mpc860_wrw_mem(CISR, CISR_BIT(device))	


/*
 * ����Ͽ����Ƥ��ʤ�SIU����ߤˤ������������
 * �������ʤγ���ߤ�¿�ų���ߤǡ�sp�μ��Ф������ۤʤ�
 */
#define SET_NO_REG_SIU_INTERRUPT_ARG_FROM_TASK	\
	lwz	r4, 0(sp)	/*  ����ߥ����å�����sp������  */

#define SET_NO_REG_SIU_INTERRUPT_ARG_FROM_INT	\
	addi	r4, sp, 8	/*  sp+8  */

/*
 * ����Ͽ����Ƥ��ʤ�CPM����ߤˤ������������
 * �������ʤγ���ߤ�¿�ų���ߤǡ�sp�μ��Ф������ۤʤ�
 */
#define SET_NO_REG_CPM_INTERRUPT_ARG_FROM_TASK	\
	lwz	r4, 8(sp)	/*  ����ߥ����å�����sp������  */

#define SET_NO_REG_CPM_INTERRUPT_ARG_FROM_INT	\
	addi	r4, sp, 16	/*  sp+16  */


#ifndef _MACRO_ONLY
/*
 * ��Ͽ����Ƥ��ʤ������ȯ�����Υ�����
 * �����ޥ���PROC_ICU����ǸƤӽФ���롣
 *     �ؿ�̾������η��ϥץ��å���˷����ɤ���
 *
 *     MPC860�Ǥϳ���ߥ���ȥ��餬������������³����Ƥ��뤿�ᡢ
 *���� �Ƴ���ߥ���ȥ�������Ѥδؿ����Ѱդ�����
 *
 */

/*  SIU����ߡ�CPM����߰ʳ���  */
extern void     no_reg_SIU_interrupt(INHNO intno, UW *sp);

/*  CPM�����  */
extern void     no_reg_CPM_interrupt(INHNO intno, UW *sp);

#endif /* _MACRO_ONLY */

#define EXCEPTION_VECTOR_START_SRC	0x10000100
#define EXCEPTION_VECTOR_END_SRC	0x10002000
#define EXCEPTION_VECTOR_START_DST	0x100



/*  --------------------------------------------------------------  */
/*
 * PowerPC�������ȤΥ��󥿡��ե����������
 */

/*
 *   MSR�ν����
 */
#define INIT_MSR    	0

/*
 *  ����߽�����ICU��¸��ʬ
 *  ����������
 *  ������������װ���Ƚ��
 *  ����������ߥޥ���������
 *  ����������ߵ���
 *  ������C����롼����ƤӽФ�
 *  ����������߶ػ�
 *  ��������ɬ�פǤ���С˳������׵�ե饰�Υ��ꥢ
 *  ��
 *  ������
 *  ��  label����٥뼱����ʸ����
 *  ��  ����������ʣ���ս�Ǥ��Υޥ������ѤǤ���褦�ˤ��뤿���
 *  ��
 *
 *  ��MPC860�γ���ߥ������ƥ������
 *  �����������ƥࡦ���󥿡��ե���������˥å�SIU
 *  �������̿��ץ��å��⥸�塼��CPM
 *  ����2���ؤˤʤäƤ���
 *  ��
 *  ����MPC860�Ǥϥ����ƥ।�󥿡��ե�������˥å�SIU�γ���ߥޥ���
 *  ������SIU����ߥޥ����쥸����SIMASK�ˤΤߤ򥫡��ͥ�Ǵ������롣
 *  �����̿��ץ��å��⥸�塼��CPM�γ���ߥޥ����δ����Ϥ��٤�
 *  �����ϡ��ɥ��������ԤäƤ��롣
 *  ��
 *  ��CPM����ߥ���ȥ���ʥϡ��ɥ������ˤ�ư��
 *  ��  ������ߤ�ȯ�������
 *  ��  �������������α�쥸����CIPR�γ����ӥåȤγ����ӥåȤ򥻥å�
 *  ��  ������ȯ����������ߤ�ͥ���٤�
 *  ��  ��������������ߥޥ����쥸����CIMR
 *  ��  �������������󥵡��ӥ��쥸����CISR
 *  ��  ������������Ӥ��Ƥ���SIU������
 *  ��  ���������٥����쥸����CIVR��IACK�ӥåȤ򥻥åȤ����
 *  ��  ������SIU�ؤγ�����׵�򥯥ꥢ
 *  ��  �������٥����쥸����CIVR�˥٥����ֹ�򥻥å�
 *  ��  �������٥����쥸����CIVR��IACK�ӥåȤ򥯥ꥢ
 *  ��  �������������α�쥸����CIPR�γ����ӥåȤ򥯥ꥢ
 *  ��  ���������󥵡��ӥ��쥸����CISR�γ����ӥåȤ򥻥å�
 *  ��  ���������ʸ塢�����겼�̤γ���ߤ�ޥ�������
 *  ��  ��������������CPM�ˤĤ��Ƥϥ��եȥ������ˤ��ޥ�������ɬ�פʤ�
 *  ��  ����
 *  ��CPM����ߤ˴ؤ��Ƥϡ�SIU��IPM�˰�礷��Ʊ���ͤ����ꤹ��
 *  ��  ����
 *  ��
 *  ���쥸����������ơ�
 *  ��  SPRG1:�����٥����ơ��֥����Ƭ���ɥ쥹int_table
 *  ��  SPRG3:IPM�ơ��֥����Ƭ���ɥ쥹ipm_table
 *  ��  r0���ͣ�
 *  ��  r3�������쥸�����ΰ����Ƭ���ɥ쥹
 *  ��  r4������ߥ٥����ֹ�ߣ�
 *  ��
 */
#define _PROC_ICU(label)                                                \
    /*  SIU�γ�����װ�Ƚ��  */                                         \
    lis     r3, IMMR_UPPER_2BYTE; /* �����쥸�����ΰ����Ƭ���ɥ쥹 */  \
        /*  �٥����ֹ���ɤ߽Ф�  */                                    \
        /*  SIVEC�쥸�����ˤ�"�٥����ֹ��4"����Ǽ����Ƥ���  */        \
    lbz     r4, TADR_SIU_SIVEC(r3); /*  r4���٥����ֹ��4  */           \
                                                                        \
    /*  ����ߥޥ���������  */                                          \
    /*  ��SIU����ߡ�������װ�����ͤ�IPM�����ꤹ��  */      		\
    /*  ��CPM����ߡ���礷��Ʊ���ͤ�SIU��IPM�����ꤹ��  */   		\
    mfspr   r5, SPRG3;      /*  r5��ipm_table  */                       \
    srwi    r6, r4, 1;      /*  r6��r4>>1�ʳ�����ֹ��2�ܡ�  */        \
    lhzx    r7, r5, r6;     /*  r7������ߥޥ���  */                    \
    	/*  ���ߤγ���ߥޥ������ǧ���ơ�  */				\
    	/*  ���������Ĥ���Ƥ��ʤ�����ߤϵ��Ĥ��ʤ��褦�ˤ���  */	\
    lhz     r8, TADR_SIU_SIMASK(r3);					\
    and     r9, r8, r7;							\
    sth     r9, TADR_SIU_SIMASK(r3);/*  ����ߥޥ�������  */            \
                                                                        \
    /*  CPM����ߤʤ��ʬ��  */                                         \
    cmpwi   crf0, r4, INHNO_CPM*4;                                      \
    beq     label##_CPM_INTERRUPT;                                      \
                                                                        \
    /*  SIU����ߡ�CPM����߰ʳ��ˤξ��  */                            \
    /*  ��SIU��ľ�ܡ���³����Ƥ���ǥХ�������γ���ߤξ���  */     \
    mfspr   r8, SPRG1;  /*  r8��SPRG1��int_table  */                    \
                        /*  r4��������ֹ��4  */                       \
    lwzx    r9, r8, r4; /*  r9��C����롼�������Ƭ���ɥ쥹  */         \
    mtctr   r9;         /*  CTR��r9  */                                 \
    mfmsr   r10;                                                        \
    ori     r11, r10, MSR_EE;   /*  EE�ӥåȤ򥻥å�  */                \
    mtmsr   r11;                /*  ����ߵ���  */                      \
    cmpwi   crf0, r9, 0;	/*  ����ߥϥ�ɥ餬��Ͽ����Ƥ��뤫 */ \
    beq     label##_call_no_reg_SIU_interrupt; /*  �����å�  */         \
    bctrl;                      /*  C����롼����ƤӽФ�  */           \
    mfmsr   r10;                                                        \
    xori    r11, r10, MSR_EE;   /*  EE�ӥåȤ򥯥ꥢ  */                \
    mtmsr   r11;        /*  ����߶ػ�  */                              \
    b       label##_exit;/*  PROC_ICU�ޥ���νи��إ�����  */         \
                                                                        \
    /*                                                                  \
���� *����SIU����ߡ�CPM����߰ʳ��ˤǳ���ߥϥ�ɥ餬                  \
���� *������Ͽ����Ƥ��ʤ����                                          \
���� */                                                                 \
label##_call_no_reg_SIU_interrupt:;                                     \
    srwi    r3, r4, 2;          /*  r3��������ֹ�  */                  \
    SET_NO_REG_SIU_INTERRUPT_ARG_##label;                               \
    LI32(r9, no_reg_SIU_interrupt);                                     \
    mtctr   r9;         /*  CTR��r9  */                                 \
    bctr;                                                               \
    /*  �����ˤ���äƤ��ʤ�  */                                        \
                                                                        \
    /*                                                                  \
���� *����CPM����ߤǳ���ߥϥ�ɥ餬                                   \
���� *������Ͽ����Ƥ��ʤ����                                          \
���� */                                                                 \
label##_call_no_reg_CPM_interrupt:;                                     \
    srwi    r3, r4, 2;          /*  r3��������ֹ�  */                  \
    SET_NO_REG_CPM_INTERRUPT_ARG_##label;                               \
    LI32(r9, no_reg_CPM_interrupt);                                     \
    mtctr   r9;         /*  CTR��r9  */                                 \
    bctr;                                                               \
    /*  �����ˤ���äƤ��ʤ�  */                                        \
                                                                        \
                                                                        \
    /*  CPM����ߤξ��  */                                             \
    /*  ����SIU��IPM������Ѥ�  */                                      \
    /*  ����CPM��IPM����ϥϡ��ɥ��������Ԥ�  */                        \
label##_CPM_INTERRUPT:;                                                 \
    /*  CIVR�쥸������IACK�ӥåȤ򥻥å�  */                            \
    li      r5, TA_CPM_CIVR_IACK;                                       \
    sth     r5, TADR_CPM_CIVR(r3);                                      \
    /*  CPM����ߥ٥����ֹ��ɤ߽Ф�  */                                 \
            /*  ����ߥ٥����쥸����CIVR�ˤϥ٥����ֹ椬  */            \
            /*  11�ӥåȺ����եȤ��줿���֤ǳ�Ǽ����Ƥ���  */          \
    lhz     r6, TADR_CPM_CIVR(r3);  /*  r6���٥����ֹ�<<11  */          \
    srwi    r4, r6, 9;  /*  r4��r6>>9�ʳ�����ֹ��4�ܡ�  */            \
    stwu    r4, -STACK_MARGIN(sp); /*  �٥����ֹ����¸  */             \
    		/*  sp��8�Х��Ȥ��餹�Τϡ�C����롼����  */		\
    		/*  sp+4���Ϥ˽񤭹��ߤ�Ԥ�����  */			\
        /*  CPM������Υ٥����ֹ��SIU���ΤΥ٥����ֹ���Ѵ�  */      \
    addi    r5, r4, TMAX_SIU_INTNO*4;                                   \
    mfspr   r8, SPRG1;  /*  r8��SPRG1��int_table  */                    \
                        /*  r4��������ֹ��4  */                       \
    lwzx    r9, r8, r5; /*  r9��C����롼�������Ƭ���ɥ쥹  */         \
    mtctr   r9;         /*  CTR��r9  */                                 \
    mfmsr   r10;                                                        \
    ori     r11, r10, MSR_EE;   /*  EE�ӥåȤ򥻥å�  */                \
    mtmsr   r11;                /*  ����ߵ���  */                      \
    cmpwi   crf0, r9, 0;	/*  ����ߥϥ�ɥ餬��Ͽ����Ƥ��뤫 */ \
    beq     label##_call_no_reg_CPM_interrupt; /*  �����å�  */         \
    bctrl;                      /*  C����롼����ƤӽФ�  */           \
    mfmsr   r10;                                                        \
    xori    r11, r10, MSR_EE;   /*  EE�ӥåȤ򥯥ꥢ  */                \
    mtmsr   r11;        /*  ����߶ػ�  */                              \
    /*  ���󥵡��ӥ��쥸����CISR�γ����ӥåȤ򥯥ꥢ  */                \
    /*      �ʣ���񤭹���ȥ��ꥢ������  */                          \
    lwz     r4, 0(sp);  /*  �٥����ֹ��4���ɤ߽Ф�  */                 \
    addi    sp, sp, STACK_MARGIN;                                       \
    srwi    r5, r4, 2;  /*  r5��r4>>2�ʳ�����ֹ��  */                 \
    li      r6, 1;                                                      \
    slw     r7, r6, r5; /*  r7��1<<(������ֹ�)  */                     \
    lis     r3, IMMR_UPPER_2BYTE; /* �����쥸�����ΰ����Ƭ���ɥ쥹 */  \
    stw     r7, TADR_CPM_CISR(r3);                                      \
label##_exit:    /*  PROC_ICU�νи���٥�  */

/* �ޥ������label��μ¤�Ÿ�����뤿�ᡢ�ޥ����2�Ťˤ��Ƥ��� */
#define PROC_ICU(label) _PROC_ICU(label)


/*
 * �����ߥ���ȥ���Υޥ���IPM��Ϣ�����
 *  ����MPC860�Ǥϥ����ƥ।�󥿡��ե�������˥å�SIU�γ���ߥޥ���
 *  ������SIU����ߥޥ����쥸����SIMASK�ˤΤߥ����ͥ�Ǵ������롣
 *  �����̿��ץ��å��⥸�塼��CPM�γ���ߥޥ����δ����Ϥ��٤ƥϡ���
 *  �������������ԤäƤ��롣
 */

/*  IPM������  */
#define PUSH_ICU_IPM                	\
    lis     r4, IMMR_UPPER_2BYTE;      	\
    lhz     r5, TADR_SIU_SIMASK(r4);    \
    sthu    r5, -4(sp)
    /*  ���ȥ���sp�ι�����1̿��Ǽ¹Ԥ����  */
    /*  ��¸����ǡ�����2�Х��ȤǤ��뤬��  */
    /*  sp��4�Х��ȶ����˰ݻ����뤿�ᡢ���ե��åȤ�-4�Ȥ��Ƥ���  */

/*  IPM������  */
#define POP_ICU_IPM                 			\
    lhz     r4, 0(sp);              			\
    lis     r5, IMMR_UPPER_2BYTE;   			\
    addi    sp, sp, 4;           /*  �嵭����  */	\
    sth     r4, TADR_SIU_SIMASK(r5) 


#ifdef SUPPORT_CHG_IPM
/*
 * ICU�����ꤹ��IPM�ѥ�᡼���Υ����å�
 *
 *��C�����
 *  ��if (ipm���ͤ�����) {
 *	ercd = E_PAR;
 *	goto exit;
 *    }
 *����Ʊ���ν�����Ԥ��ޥ���
 */
#define CHECK_IPM(ipm)
	/*  MPC860�Ǥϲ�������å����ʤ�  */

/*
 * �����ߥ���ȥ���Υޥ�������
 */
#define GET_IPM(p_ipm)	*(p_ipm) = sil_reh_mem((VP)SIMASK)

/*
 * �����ߥ���ȥ���Υޥ�������
 */
#define CHG_IPM(ipm)	sil_wrh_mem((VP)SIMASK, ipm)

#endif	/*  SUPPORT_CHG_IPM  */


#ifndef _MACRO_ONLY

/*
 *  ����ߥޥ����ѵ����٥����ơ��֥�
 *	ipm_table���Τ�$(CPU)�ȤΥ��󥿡��ե������˴ޤޤ�ʤ�
 *��������define_ipm�ˤ�ꡢ���ä���Ƥ����
 */
extern IPM ipm_table[];

/*
 *  �����ߥ�٥������
 *	������ֹ�inhno�γ���ߤ�����դ����Ȥ��˳���ߥ���ȥ����
 *	IPM�����ꤹ���ͤ�������롣
 *	�ǥХ����ɥ饤�Фν���������ǻ��Ѥ���뤳�Ȥ����ꤷ�Ƥ��롣
 *
 *����������
 *��������inhno������ߥϥ�ɥ��ֹ�
 *��������ipm������ߥޥ���
 *
 */
Inline void
define_ipm(INHNO inhno, IPM ipm)
{
	ipm_table[inhno] = ipm;
}

#endif /* _MACRO_ONLY */

/*  
 *  �����ϥ⡼�ɤؤΰܹԤȳ���ߵ���
 *  ���¹Ԥ��٤����������ʤ��Ƴ�����Ԥ��ˤʤ�Ȥ���
 *  ���ǥ����ѥå������ǻ��Ѥ���롣
 *
 *  ��������ߤ�����äƤ�����˳���߶ػߤ�Ԥ�
 *  ����r0��r4�����Ƥ��˲����ƤϤʤ�ʤ�
 *  ��
 *  ��MCP860�Ǥϥɡ����������⡼�ɤ��Ѥ���
 *  ��
 *  ���쥸�����������
 *  ����r0���ͣ�
 *  ����r5�������쥸��������Ƭ���ɥ쥹
 *  ����r6����å����������0x55ccaa33
 */ 
#define SAVE_POWPER                                                 \
    lis     r5, IMMR_UPPER_2BYTE;                                   \
    LI32(r6, UNLOCK_KEY);                                           \
    stw     r6, TADR_SCCRK(r5);   /* SCCR�����å� */              \
                                                                    \
    /* CRQEN=1��CP��ư���Ȥ����ɡ������ϥ����⡼�ɤ�    */      \
    /* PRQEN=1��������׵�ǥΡ��ޥ롦�ϥ����⡼�ɤ�        */      \
    lwz     r7, TADR_SCCR(r5);                                      \
    oris    r7, r7, (SCCR_CRQEN | SCCR_PRQEN)>>16;                  \
    stw     r7, TADR_SCCR(r5);                                      \
                                                                    \
    stw     r0, TADR_SCCRK(r5);     /* SCCR��å� */                \
                                                                    \
    stw     r6, TADR_PLPRCRK(r5);   /* PLPRC�����å� */           \
                                                                    \
    /* PLPRCR                                   */                  \
    /*    TMIST=0������ߥ������򥯥ꥢ���Ƥ�   */                  \
    /*           �ɡ����������⡼�ɤ����ʤ� */                  \
    lwz     r8, TADR_PLPRCR(r5);                                    \
    ori     r8, r8, PLPRCR_TIMIST;                                  \
    xori    r8, r8, PLPRCR_TIMIST;                                  \
    stw     r8, TADR_PLPRCR(r5);                                    \
                                                                    \
    /* �ɡ����������⡼�ɤ����ܤ��뤿���������   */              \
    /*      CSRC=1��                                */              \
    /*      LPM=01��                                */              \
    ori     r8, r8, (PLPRCR_CSRC | PLPRCR_LPM);                     \
    xori    r8, r8, PLPRCR_LPM10;                                   \
    stw     r8, TADR_PLPRCR(r5);                                    \
                                                                    \
    stw     r0, TADR_PLPRCRK(r5);   /* PLPRC��å� */               \
                                                                    \
    /* ����ߵ��Ĥȥɡ����������⡼�ɤؤΰܹ� */                  \
    mfmsr   r9;                                                     \
    ori     r9, r9, MSR_EE;         /*  EE�ӥåȥ��å�  */          \
    oris    r9, r9, MSR_POW>>16;    /*  POW�ӥåȥ��å�  */         \
    mtmsr   r9;                                                     \
    /*  �����ǳ���ߤ�����ʥɡ����������⡼�ɤ��Ԥġ�  */        \
    /*  ������ߤ�����ä��Ȥ���r9�⸵���ͤˤʤäƤ���  */          \
                                                                    \
    /*  ����߶ػ�  */                                              \
    xori    r9, r9, MSR_EE;         /*  EE�ӥåȥ��ꥢ  */          \
    xoris   r9, r9, MSR_POW>>16;    /*  POW�ӥåȥ��ꥢ  */         \
    mtmsr   r9


/*
 * ����ץ���ơ�������ͭ���㳰0x01000�ν������Ƥ���������ޥ���
 * ��
 * �ޥ���IMPLEMENT_EXCEPTION_01000���������Ƥ�����Τ�ͭ���Ȥʤ롣
 * �������Ƥϥץ��å��Υ���ץ���ơ�������ͭ�Τ�ΤʤΤǡ�
 * �����ͥ�ˤ��������������������줺�����Υޥ������������������Ƥ�
 * ľ�ܸƤӽФ���롣�ʤĤޤꡢ�����ͥ�δ�����������
 * ���Τ��ᡢ���ν�����ǥ����ͥ�ε�ǽ��ƤӽФ�������ư���̤�����
 * ���롣
 * ��
 * ���ե��å�0x01000�ʹߤ����֤�����㳰�װ��ϣ��ĤȤϸ¤�ʤ���2�İʾ�
 * ���㳰�٥��������֤�����硢���ե��åȤλ�����ˡ����դ��뤳�ȡ�
 * ������Ū�ˤ�
 *     .org ���ե��å� - EXCEPTION_VECTOR_BASE
 * �Τ褦�˻��ꤹ�롣�ܤ�����cpu_support.S�γ����Ľ�򻲾ȡ�
 * ��
 */
#define MAKE_EXCEPTION_VECTOR(offset, name)	\
    .org offset - EXCEPTION_VECTOR_BASE;	\
name:;						\
  MAKE_EXCEPTION_ENTRY(offset)


#define IMPLEMENT_EXCEPTION_01000_PROC				\
software_emulation:;						\
  MAKE_EXCEPTION_ENTRY(0x1000);					\
								\
MAKE_EXCEPTION_VECTOR(0x1100, instruction_TLB_miss);		\
MAKE_EXCEPTION_VECTOR(0x1200, data_TLB_miss);			\
MAKE_EXCEPTION_VECTOR(0x1300, instruction_TLB_error);		\
MAKE_EXCEPTION_VECTOR(0x1400, data_TLB_error);			\
MAKE_EXCEPTION_VECTOR(0x1c00, data_break_point);		\
MAKE_EXCEPTION_VECTOR(0x1d00, instruction_break_point);		\
MAKE_EXCEPTION_VECTOR(0x1e00, peripheral_break_point);		\
MAKE_EXCEPTION_VECTOR(0x1f00, non_maskable_developement_port)


#endif /* _SYS_CONFIG_H_ */

/*  end of file  */
