/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

#ifndef _H8S_H_
#define _H8S_H_

#include <util.h>

/*
 *  H8S/2600, H8S/2000 CPU �����
 *    ����ӡ��Х�����ȥ��顢����ߥ���ȥ����Ϣ�����
 */

/*
 *  ����ǥ�����󥳡��ɥ쥸����(CCR)
 */
#define CCR_I		BIT7
#define CCR_UI		BIT6
#define CCR_H		BIT5
#define CCR_U		BIT4
#define CCR_N		BIT3
#define CCR_Z		BIT2
#define CCR_V		BIT1
#define CCR_C		BIT0

/*
 *  �������ƥ�ɥ쥸����(EXR)
 */
#define EXR_T		BIT7		/* �ȥ졼���ӥå� */
#define EXR_I2		BIT2		/* ����ߥޥ����ӥå� */
#define EXR_I1		BIT1		/* ����ߥޥ����ӥå� */
#define EXR_I0		BIT0		/* ����ߥޥ����ӥå� */

/* ����ߥޥ����ӥåȼ����ѥޥ��� */
#define EXR_I_MASK	(EXR_I2|EXR_I1|EXR_I0)

/*
 *  MCUư��⡼�ɴ�Ϣ�Υ쥸����
 */

/* �쥸�����Υ��ɥ쥹 */
#define MDCR		0xff3b
#define SYSCR		0xff39

/* �ƥ쥸�����Υӥåȥѥ����� */

/* MDCR */
#define MDS2		BIT2
#define MDS1		BIT1
#define MDS0		BIT0

/* SYSCR */
#define INTM1		BIT5
#define INTM0		BIT4
#define NMIEG		BIT3
#define RAME		BIT0

#define RAME_BIT	0x0

/*
 *  ����ߥ���ȥ���
 */
/* �쥸�����Υ��ɥ쥹 */
/* �����ƥॳ��ȥ���쥸�����ϡ���������Ѥ� */
#define ISCRH		0xff2c		/* IRQ���󥹥���ȥ���쥸����H */
#define ISCRL		0xff2d		/* IRQ���󥹥���ȥ���쥸����L */
#define IER		0xff2e		/* IRQ���͡��֥�쥸���� */
#define ISR		0xff2f		/* IRQ���ơ������쥸���� */
#define IPRA		0xfec4		/* ���󥿥�ץȥץ饤����ƥ��쥸����A */
#define IPRB 		0xfec5		/* ���󥿥�ץȥץ饤����ƥ��쥸����B */
#define IPRC		0xfec6		/* ���󥿥�ץȥץ饤����ƥ��쥸����C */
#define IPRD		0xfec7		/* ���󥿥�ץȥץ饤����ƥ��쥸����D */
#define IPRE		0xfec8		/* ���󥿥�ץȥץ饤����ƥ��쥸����E */
#define IPRF		0xfec9		/* ���󥿥�ץȥץ饤����ƥ��쥸����F */
#define IPRG		0xfeca		/* ���󥿥�ץȥץ饤����ƥ��쥸����G */
#define IPRH		0xfecb		/* ���󥿥�ץȥץ饤����ƥ��쥸����H */
#define IPRI		0xfecc		/* ���󥿥�ץȥץ饤����ƥ��쥸����I */
#define IPRJ		0xfecd		/* ���󥿥�ץȥץ饤����ƥ��쥸����J */
#define IPRK		0xfece		/* ���󥿥�ץȥץ饤����ƥ��쥸����K */

/* �ƥ쥸�����Υӥåȥѥ����� */

/* IPRx (x = A-K) */
#define IPR6		BIT6
#define IPR5		BIT5
#define IPR4		BIT4
#define IPR2		BIT2
#define IPR1		BIT1
#define IPR0		BIT0

/* icu_set_ilv�� */
#define IPR_UPR		TRUE
#define IPR_LOW		FALSE
#define IPR_UPR_MASK	(IPR6|IPR5|IPR4)	/* IPR��̥ӥåȥޥ��� */
#define IPR_LOW_MASK	(IPR2|IPR1|IPR0)	/* IPR���̥ӥåȥޥ��� */

/* IER */
#define IRQ7E		BIT7
#define IRQ6E		BIT6
#define IRQ5E		BIT5
#define IRQ4E		BIT4
#define IRQ3E		BIT3
#define IRQ2E		BIT2
#define IRQ1E		BIT1
#define IRQ0E		BIT0

/* ISCRH */
#define IRQ7SCB		BIT7
#define IRQ7SCA		BIT6
#define IRQ6SCB		BIT5
#define IRQ6SCA		BIT4
#define IRQ5SCB		BIT3
#define IRQ5SCA		BIT2
#define IRQ4SCB		BIT1
#define IRQ4SCA		BIT0

/* ISCRL */
#define IRQ3SCB		BIT7
#define IRQ3SCA		BIT6
#define IRQ2SCB		BIT5
#define IRQ2SCA		BIT4
#define IRQ1SCB		BIT3
#define IRQ1SCA		BIT2
#define IRQ0SCB		BIT1
#define IRQ0SCA		BIT0

/* ISR */
#define IRQ7F		BIT7
#define IRQ6F		BIT6
#define IRQ5F		BIT5
#define IRQ4F		BIT4
#define IRQ3F		BIT3
#define IRQ2F		BIT2
#define IRQ1F		BIT1
#define IRQ0F		BIT0

/* ������㳰�����٥����ơ��֥�Υ٥����ֹ� */
					/* �׵�ȯ���� */
#define IRQ_POWRESET	0		/* �ѥ����ꥻ�å� */
#define IRQ_MANRESET	1		/* �ޥ˥奢��ꥻ�å� */
/* 2-4 �ϡ��㳰�����٥����ơ��֥���б�����Τǡ���ά */
#define IRQ_TRACE	5		/* �ȥ졼�� */
/* 6 �ϡ��㳰�����٥����ơ��֥���б�����Τǡ���ά */
#define IRQ_NMI		7		/* ����ü�� */
#define IRQ_TRAP0	8		/* �ȥ�å�̿�� */
#define IRQ_TRAP1	9		/* �ȥ�å�̿�� */
#define IRQ_TRAP2	10		/* �ȥ�å�̿�� */
#define IRQ_TRAP3	11		/* �ȥ�å�̿�� */
/* 12-15 �ϡ��㳰�����٥����ơ��֥���б�����Τǡ���ά */
#define IRQ_IRQ0	16		/* ����ü�� */
#define IRQ_IRQ1	17		/* ����ü�� */
#define IRQ_IRQ2	18		/* ����ü�� */
#define IRQ_IRQ3	19		/* ����ü�� */
#define IRQ_IRQ4	20		/* ����ü�� */
#define IRQ_IRQ5	21		/* ����ü�� */
#define IRQ_IRQ6	22		/* ����ü�� */
#define IRQ_IRQ7	23		/* ����ü�� */
#define IRQ_SWDTEND	24		/* DTC */
#define IRQ_WOVI	25		/* �����å��ɥå������� */
#define IRQ_CMI 	26		/* ��ե�å��女��ȥ��� */
/* 27 �֤ϡ��ꥶ���� */
#define IRQ_ADI		28		/* A/D */
/* 29, 30, 31 �֤ϡ��ꥶ���� */
#define IRQ_TGI0A	32		/* TPU����ͥ�0 */
#define IRQ_TGI0B	33		/* TPU����ͥ�0 */
#define IRQ_TGI0C	34		/* TPU����ͥ�0 */
#define IRQ_TGI0D	35		/* TPU����ͥ�0 */
#define IRQ_TCI0V	36		/* TPU����ͥ�0 */
/* 37, 38, 39 �֤ϡ��ꥶ���� */
#define IRQ_TGI1A	40		/* TPU����ͥ�1 */
#define IRQ_TGI1B	41		/* TPU����ͥ�1 */
#define IRQ_TCI1V	42		/* TPU����ͥ�1 */
#define IRQ_TCI1U	43		/* TPU����ͥ�1 */
#define IRQ_TGI2A	44		/* TPU����ͥ�2 */
#define IRQ_TGI2B	45		/* TPU����ͥ�2 */
#define IRQ_TCI2V	46		/* TPU����ͥ�2 */
#define IRQ_TCI2U	47		/* TPU����ͥ�2 */
#define IRQ_TGI3A	48		/* TPU����ͥ�3 */
#define IRQ_TGI3B	49		/* TPU����ͥ�3 */
#define IRQ_TGI3C	50		/* TPU����ͥ�3 */
#define IRQ_TGI3D	51		/* TPU����ͥ�3 */
#define IRQ_TCI3V	52		/* TPU����ͥ�3 */
/* 53, 54, 55 �֤ϡ��ꥶ���� */
#define IRQ_TGI4A	56		/* TPU����ͥ�4 */
#define IRQ_TGI4B	57		/* TPU����ͥ�4 */
#define IRQ_TCI4V	58		/* TPU����ͥ�4 */
#define IRQ_TCI4U	59		/* TPU����ͥ�4 */
#define IRQ_TGI5A	60		/* TPU����ͥ�5 */
#define IRQ_TGI5B	61		/* TPU����ͥ�5 */
#define IRQ_TCI5V	62		/* TPU����ͥ�5 */
#define IRQ_TCI5U	63		/* TPU����ͥ�5 */
/* 64, 65, 66, 67, 68, 69, 70, 71 �֤ϡ��ꥶ���� */
#define IRQ_DEND0A	72		/* DMAC */
#define IRQ_DEND0B	73		/* DMAC */
#define IRQ_DEND1A	74		/* DMAC */
#define IRQ_DEND1B	75		/* DMAC */
/* 76, 77, 78, 79 �֤ϡ��ꥶ���� */
#define IRQ_ERI0	80		/* SCI����ͥ�0 */
#define IRQ_RXI0	81		/* SCI����ͥ�0 */
#define IRQ_TXI0	82		/* SCI����ͥ�0 */
#define IRQ_TEI0	83		/* SCI����ͥ�0 */
#define IRQ_ERI1	84		/* SCI����ͥ�1 */
#define IRQ_RXI1	85		/* SCI����ͥ�1 */
#define IRQ_TXI1	86		/* SCI����ͥ�1 */
#define IRQ_TEI1	87		/* SCI����ͥ�1 */
/* 88, 89, 90, 91 �֤ϡ��ꥶ���� */

/*
 *  �Х�����ȥ���
 */
/* �쥸�����Υ��ɥ쥹 */
#define ABWCR		0xfed0		/* �Х�������ȥ���쥸���� */
#define ASTCR		0xfed1		/* �����������ơ��ȥ���ȥ���쥸���� */
#define WCRH		0xfed2		/* �������ȥ���ȥ���쥸����H */
#define WCRL      	0xfed3		/* �������ȥ���ȥ���쥸����L */
#define BCRH		0xfed4		/* �Х�����ȥ���쥸����H */
#define BCRL		0xfed5		/* �Х�����ȥ���쥸����L */
#define MCR		0xfed6		/* ���ꥳ��ȥ���쥸���� */
#define DRAMCR		0xfed7		/* DRAM����ȥ���쥸���� */
#define RTCNT		0xfed8		/* ��ե�å��奿���ޥ����� */
#define RTCOR		0xfed9		/* ��ե�å��奿���ޥ��󥹥���ȥ쥸���� */

/* �ƥ쥸�����Υӥåȥѥ����� */

/* ASTCR */
#define AST7 		BIT7
#define AST6 		BIT6
#define AST5 		BIT5
#define AST4 		BIT4
#define AST3 		BIT3
#define AST2 		BIT2
#define AST1 		BIT1
#define AST0 		BIT0

/* WCRH */
#define W71 		BIT7
#define W70 		BIT6
#define W61 		BIT5
#define W60 		BIT4
#define W51 		BIT3
#define W50 		BIT2
#define W41 		BIT1
#define W40 		BIT0

/* WCRL */
#define W31 		BIT7
#define W30 		BIT6
#define W21 		BIT5
#define W20 		BIT4
#define W11 		BIT3
#define W10 		BIT2
#define W01 		BIT1
#define W00 		BIT0

/* BCRH */
#define ICIS1 		BIT7
#define ICIS0 		BIT6
#define BRSTRM		BIT5
#define BRSTS1 		BIT4
#define BRSTS0		BIT3
#define RMTS2		BIT2
#define RMTS1		BIT1
#define RMTS0 		BIT0

/*
 *  ����߻��Υ����å��ˤ�����EXR�쥸�����Υ��ե��å�
 */
#define EXR_offset	28

/*
 *  ̤��������ȯ�����Υ��顼���ϻ��Υ����å���¤�����
 */
#ifndef _MACRO_ONLY

typedef struct exc_stack {
	UW	er6;
	UW	er5;
	UW	er4;
	UW	er3;
	UW	er2;
	UW	er1;
	UW	er0;
	UB	exr;
	UB	tmp;
	UH	ccr;	/* 1 byte : 1 byte = CCR : PC(��̣��Х���) */
	UH	pc;	/* 1 byte : 1 byte = PC(���̣��Х���) */
} EXCSTACK;

#endif /* _MACRO_ONLY */

#endif /* _H8S_H_ */
