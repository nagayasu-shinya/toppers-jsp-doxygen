/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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

#ifndef _H8S_2339F_H_
#define _H8S_2339F_H_

/*
 *  H8S/2339F �����
 */

/*
 *  �⥸�塼�륹�ȥåץ���ȥ���쥸����
 *  (�͡��ʥ⥸�塼��� ON��OFF �˻ȤäƤ���Τǡ�������������롣)
 */
#define MSTPCR		0xff3c
#define MSTPCR_TPU	BIT13
#define MSTPCR_SCI2	BIT7
#define MSTPCR_SCI1	BIT6
#define MSTPCR_SCI0	BIT5


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
/* 2-4 �ϡ������ƥ�ͽ�� */
#define IRQ_TRACE	5		/* �ȥ졼�� */
/* 6 �ϡ������ƥ�ͽ�� */
#define IRQ_NMI		7		/* ����ü�� */
#define IRQ_TRAP0	8		/* �ȥ�å�̿�� */
#define IRQ_TRAP1	9		/* �ȥ�å�̿�� */
#define IRQ_TRAP2	10		/* �ȥ�å�̿�� */
#define IRQ_TRAP3	11		/* �ȥ�å�̿�� */
/* 12-15 �ϡ������ƥ�ͽ�� */
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
#define IRQ_ERI2	88		/* SCI����ͥ�2 */
#define IRQ_RXI2	89		/* SCI����ͥ�2 */
#define IRQ_TXI2	90		/* SCI����ͥ�2 */
#define IRQ_TEI2	91		/* SCI����ͥ�2 */

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
 *  I/O �ݡ���
 */

#define TNUM_IO_PORT	15	/*  I/O�ݡ��Ȥ��ܿ�  */

/* �ƥݡ��ȥ쥸�����Υ��ɥ쥹 */

/* port1 */
#define P1DDR		0xfeb0
#define P1DR		0xff60
#define PORT1		0xff50

/* port2 */
#define P2DDR		0xfeb1
#define P2DR		0xff61
#define PORT2		0xff51

/* port3 */
#define P3DDR		0xfeb2
#define P3DR		0xff62
#define PORT3		0xff52
#define P3ODR		0xff76

/* port4 */
#define PORT4		0xff53

/* port5 */
#define P5DDR		0xfeb4
#define P5DR		0xff64
#define PORT5		0xff54

/* port6 */
#define P6DDR		0xfeb5
#define P6DR		0xff65
#define PORT6 		0xff55

/* port7 */
#define P7DDR		0xfeb6

/* port8 */
#define P8DDR		0xfeb7

/* port9 */
#define P9DDR		0xfeb8

/*  portA  */
#define PADDR		0xfeb9
#define PADR		0xff69
#define PORTA		0xff59

/* portB */
#define PBDDR		0xfeba

/* portC */
#define PCDDR		0xfebb

/* portD */
#define PDDDR		0xfebc

/*  portE  */
#define PEDDR		0xfebd
#define PEDR		0xff6d
#define PORTE		0xff5d
#define PEPCR		0xff74

/*  portF  */
#define PFDDR		0xfebe
#define PFDR		0xff6e
#define PORTF		0xff5e

/*  portG  */
#define PGDDR		0xfebf	/* �ݡ��ȣǥǡ����ǥ�������ץ����쥸���� */
#define PGDR		0xff6f	/* �ݡ��ȣǥǡ����쥸���� */
#define PORTG		0xff5f	/* �ݡ��ȣǥ쥸���� */

/* �ƥ쥸�����Υӥåȥѥ����� */

/* P2DDR */
#define P27DDR		BIT7
#define P26DDR		BIT6
#define P25DDR		BIT5
#define P24DDR		BIT4
#define P23DDR		BIT3
#define P22DDR		BIT2
#define P21DDR		BIT1
#define P20DDR		BIT0

/* P3DDR */
#define P37DDR		BIT7
#define P36DDR		BIT6
#define P35DDR		BIT5
#define P34DDR		BIT4
#define P33DDR		BIT3
#define P32DDR		BIT2
#define P31DDR		BIT1
#define P30DDR		BIT0

/* PGDDR */
#define PG4DDR		BIT4
#define PG3DDR		BIT3
#define PG2DDR		BIT2
#define PG1DDR		BIT1
#define PG0DDR		BIT0

#endif /* _H8S_2339F_H_ */
