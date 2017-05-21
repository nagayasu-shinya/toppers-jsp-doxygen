
/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                                  Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: sh3.h,v 1.8 2006/04/10 09:58:15 honda Exp $
 */

/*
 *  SH3(SH7729R,SH7709A,SH7709,SH7708)�������쥸�������
 */

#ifndef _SH3_H_
#define _SH3_H_

#ifndef _MACRO_ONLY
#include <itron.h>
#include <sil.h>
#endif /* _MACRO_ONLY */

/*
 *  �㳰���٥�ȥ쥸����
 */
#define TRA	        0xFFFFFFD0		
#define EXPEVT	    0xFFFFFFD4		
#define INTEVT	    0xFFFFFFD8		
#define INTEVT2	    0xA4000000		

/*
 * INTEVT(2) �κ�����
 */ 
#ifdef SH7709A

#define MAX_INTIVT (0x980)

#elif defined(SH7727)

#define MAX_INTIVT (0xB80)

#elif defined(SH7729R)

#define MAX_INTIVT (0x980)

#elif defined(SH7750)

#define MAX_INTIVT (0x7E0)

#else

#define MAX_INTIVT (0xB80)

#endif 



/*
 *   �Х����ơ��ȥ���ȥ����Ϣ
 */
#define	RFCR	0xffffff74	/* H */

#define    RFCR_CLEAR         0xa400


/*
 * �����ߤˤ�ä�INTEVT2�쥸���������ꤵ�����
 */
#define    TMU0_INTEVT        0x400
#define    IRQ0_INTEVT        0x600
#define    SCI_RXI_INTEVT     0x500
#define    SCI_TXI_INTEVT     0x520
#define    SCI_BRI_INTEVT     0x4ed
#define    PINT0_7_INTEVT     0x700
#define    PINT8_15_INTEVT    0x720
#define    SCI1_RXI_INTEVT    0x8a0
#define    SCI1_TXI_INTEVT    0x8e0
#define    SCI1_BRI_INTEVT    0x8c0
#define    SCIF_RXI_INTEVT    0x920
#define    SCIF_TXI_INTEVT    0x960
#define    SCIF_BRI_INTEVT    0x940

        
/*
 * �����ߥ���ȥ��顼�쥸������
 */
#define	ICR0	0xfffffee0    /* H */
#define	ICR1	0xa4000010    /* H */
#define	ICR2	0xa4000012    /* H */
#define	PINTER	0xa4000014    /* H */
#define	IPRA	0xfffffee2    /* H */
#define	IPRB	0xfffffee4    /* H */
#define	IPRC	0xa4000016    /* H */
#define	IPRD	0xa4000018    /* H */
#define	IPRE	0xa400001a    /* H */
#define	IRR0	0xa4000004    /* B */
#define	IRR1	0xa4000006    /* B */
#define	IRR2	0xa4000008    /* B */

#define ICR2_PINT7S     0x80
#define ICR2_PINT6S     0x40
#define PINTER_PINT7E   0x80
#define PINTER_PINT6E   0x40

/*
 * �����ޡ��쥸����
 */
#define TMU_TOCR   0xfffffe90  /* B */
#define TMU_TSTR   0xfffffe92  /* B */
#define TMU_TCOR0  0xfffffe94  /* W */
#define TMU_TCNT0  0xfffffe98  /* W */
#define TMU_TCR0   0xfffffe9c  /* H */
#define TMU_TCOR1  0xfffffea0  /* W */
#define TMU_TCNT1  0xfffffea4  /* W */
#define TMU_TCR1   0xfffffea8  /* H */
#define TMU_TCOR2  0xfffffeac  /* W */
#define TMU_TCNT2  0xfffffeb0  /* W */
#define TMU_TCR2   0xfffffeb4  /* H */

#define	TMU_STR0	0x01
#define	TMU_STR1	0x02
#define	TMU_STR2	0x04
#define TCR_UNF     0x0100    


/*
 *  ���ꥢ�륳�ߥ�˥�������󥤥󥿡��ե�����(SCI)
 */
#define   SCI_SCSMR    0xfffffe80  /* B */
#define   SCI_SCBRR    0xfffffe82  /* B */
#define   SCI_SCSCR    0xfffffe84  /* B */
#define   SCI_SCTDR    0xfffffe86  /* B */
#define   SCI_SCSSR    0xfffffe88  /* B */
#define   SCI_SCRDR    0xfffffe8a  /* B */

/*
 *  ���ꥢ�륳�ߥ�˥�������󥤥󥿡��ե�����(SCI)��
 *  �ݡ���SC����ȥ���/�ǡ����쥸����
 *  SH7709�ڤ�SH7709A�Τ�
 */
#define	SCPDR     0xa4000136   /* B */
#define	SCPCR	  0xa4000116   /* H */


/*
 *  ���ꥢ�륳�ߥ�˥�������󥤥󥿡��ե�����(SCI)��
 *  ���ꥢ��ݡ��ȥ쥸����
 *  SH7708�Τ�
 */
#define	SCSPTR	  0xffffff7c  /* H */

#define	SCSMR_CHR	  0x0040
#define	SCSMR_PE	  0x0020
#define	SCSMR_OE	  0x0010
#define	SCSMR_STOP	  0x0008
#define	SCSMR_CKS1	  0x0002
#define	SCSMR_CKS0	  0x0001

#define SCSCR_TIE	  0x0080
#define SCSCR_RIE	  0x0040
#define SCSCR_TE	  0x0020
#define SCSCR_RE	  0x0010
#define SCSCR_CKE1	  0x0002
#define SCSCR_CKE0	  0x0001

#define SCSSR_TDRE	  0x80
#define SCSSR_RDRF	  0x40
#define SCSSR_ORER	  0x20
#define SCSSR_FER	  0x10
#define SCSSR_PER	  0x08
#define SCSSR_TEND	  0x04
#define SCSSR_MPB	  0x02
#define SCSSR_MPBT	  0x01


/*
 *  FIFO�դ����ꥢ�륳�ߥ�˥�������󥤥󥿡��ե�����(SCIF)�쥸����
 *  SH7709�ڤ�SH7709A�Τ�
 */
#define  SCIF_SCSMR2     0xa4000150  /* B */
#define  SCIF_SCBRR2     0xa4000152  /* B */
#define  SCIF_SCSCR2     0xa4000154  /* B */
#define  SCIF_SCFTDR2    0xa4000156  /* B */
#define  SCIF_SCSSR2     0xa4000158  /* H */
#define  SCIF_SCFRDR2    0xa400015a  /* B */
#define  SCIF_SCFCR2     0xa400015c  /* B */
#define  SCIF_SCFDR2     0xa400015e  /* H */

#define	SCSMR2_CHR	  0x0040
#define	SCSMR2_PE	  0x0020
#define	SCSMR2_OE	  0x0010
#define	SCSMR2_STOP	  0x0008
#define	SCSMR2_CKS1	  0x0002
#define	SCSMR2_CKS0	  0x0001

#define SCSCR2_TIE	  0x0080
#define SCSCR2_RIE	  0x0040
#define SCSCR2_TE	  0x0020
#define SCSCR2_RE	  0x0010
#define SCSCR2_CKE1	  0x0002
#define SCSCR2_CKE0	  0x0001

#define SCSSR2_ER	  0x0080
#define SCSSR2_TEND	  0x0040
#define SCSSR2_TDFE	  0x0020
#define SCSSR2_BRK	  0x0010
#define SCSSR2_FER	  0x0008
#define SCSSR2_PER	  0x0004
#define SCSSR2_RDF	  0x0002
#define SCSSR2_DR	  0x0001


#define SCFCR2_RTRG1  0x0080
#define SCFCR2_RTRG0  0x0040
#define SCFCR2_TTRG1  0x0020
#define SCFCR2_TTRG0  0x0010
#define SCFCR2_MCE	  0x0008
#define SCFCR2_TFRST  0x0004
#define SCFCR2_RFRST  0x0002
#define SCFCR2_LOOP	  0x0001


/*
 *  IrDA (SCI1)�쥸����
 *  SH7709�ڤ�SH7709A�Τ�
 */
#define  SCI1_SCSMR1    0xa4000140   /* B */ 
#define  SCI1_SCBRR1    0xa4000142   /* B */ 
#define  SCI1_SCSCR1    0xa4000144   /* B */ 
#define  SCI1_SCFTDR1   0xa4000146   /* B */ 
#define  SCI1_SCSSR1    0xa4000148   /* H */ 
#define  SCI1_SCFRDR1   0xa400014a   /* B */ 
#define  SCI1_SCFCR1    0xa400014c   /* B */ 
#define  SCI1_SCFDR1    0xa400014e   /* H */ 

#define	SCSMR1_IRMOD    0x0080
#define	SCSMR1_CHR	    0x0040
#define	SCSMR1_PE	    0x0020
#define	SCSMR1_OE	    0x0010
#define	SCSMR1_STOP	    0x0008
#define	SCSMR1_CKS1	    0x0002
#define	SCSMR1_CKS0	    0x0001

#define SCSCR1_TIE      0x0080
#define SCSCR1_RIE      0x0040
#define SCSCR1_TE       0x0020
#define SCSCR1_RE       0x0010
#define SCSCR1_CKE1     0x0002
#define SCSCR1_CKE0     0x0001

#define SCSSR1_ER	0x0080
#define SCSSR1_TEND	0x0040
#define SCSSR1_TDFE	0x0020
#define SCSSR1_BRK	0x0010
#define SCSSR1_FER	0x0008
#define SCSSR1_PER	0x0004
#define SCSSR1_RDF	0x0002
#define SCSSR1_DR	0x0001


#define SCFCR1_RTRG1    0x0080
#define SCFCR1_RTRG0    0x0040
#define SCFCR1_TTRG1    0x0020
#define SCFCR1_TTRG0    0x0010
#define SCFCR1_MCE      0x0008
#define SCFCR1_TFRST    0x0004
#define SCFCR1_RFRST    0x0002
#define SCFCR1_LOOP     0x0001



/*
 * ����å�������쥸����
 */
#define	CCR	   0xffffffec   /* W */

#define CCR_DISABLE   0x00000008     /* ����å����̵���� */

#ifndef _MACRO_ONLY

/*
 *   SH7709A�ڤ�SH7709��SCIF�ؤΥݡ���󥰤Ǥν���
 */
Inline int
scif_putc(int c)
{
    /* Wait TDRD = 1 */
    while((sil_reb_mem((VP)SCIF_SCSSR2) & SCSSR2_TDFE)==0);

    sil_wrb_mem((VP)SCIF_SCFTDR2, c);
    sil_wrh_mem((VP)SCIF_SCSSR2,
                (sil_reh_mem((VP)SCIF_SCSSR2) & ~SCSSR2_TDFE));
    return(c);
}

    
/*
 *  SCI�ˤ�����
 */
Inline int
sci_putc(int c)
{

    /* Wait TDRD = 1 */
    while((sil_reb_mem((VP)SCI_SCSSR) & SCSSR_TDRE) == 0);

    sil_wrb_mem((VP)SCI_SCTDR, c);
    sil_wrb_mem((VP)SCI_SCSSR,
                (sil_reb_mem((VP)SCI_SCSSR) & ~SCSSR_TDRE));
    return(c);
}

#endif /* _MACRO_ONLY */
#endif /* _SH3_H_ */
