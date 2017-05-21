
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
 *  @(#) $Id: sh4.h,v 1.4 2003/06/17 16:45:54 honda Exp $
 */

/*
 *  SH4(SH7750)�������쥸�������
 */

#ifndef _SH4_H_
#define _SH4_H_

/*
 *  �㳰���٥�ȥ쥸����
 */
#define TRA	        0xff000020
#define EXPEVT	    0xff000024
#define INTEVT	    0xff000028


/*
 *   �Х����ơ��ȥ���ȥ����Ϣ
 */
#define	RFCR	    0xff800028   /* H */

#define RFCR_CLEAR  0xa400

/*
 * �����ߤˤ�ä� INTEVT �쥸���������ꤵ�����
 */
#define    TMU0_INTEVT        0x400
#define    SCI_RXI_INTEVT     0x500
#define    SCI_TXI_INTEVT     0x520
#define    SCI_ERI_INTEVT     0x4e0
#define    SCIF_RXI_INTEVT    0x720
#define    SCIF_TXI_INTEVT    0x760
#define    SCIF_BRI_INTEVT    0x740


        
/*
 * ����ߥ���ȥ���쥸����
 */
#define	ICR   0xffd00000    /* H */
#define	IPRA  0xffd00004    /* H */
#define	IPRB  0xffd00008    /* H */
#define	IPRC  0xffd0000c    /* H */
#define	IPRD  0xffd00010    /* H */


/*
 * �����ޡ��쥸����
 */
#define TMU_TOCR   0xffd80000  /* B */
#define TMU_TSTR   0xffd80004  /* B */
#define TMU_TCOR0  0xffd80008  /* W */
#define TMU_TCNT0  0xffd8000c  /* W */
#define TMU_TCR0   0xffd80010  /* H */
#define TMU_TCOR1  0xffd80014  /* W */
#define TMU_TCNT1  0xffd80018  /* W */
#define TMU_TCR1   0xffd8001c  /* H */
#define TMU_TCOR2  0xffd80020  /* W */
#define TMU_TCNT2  0xffd80024  /* W */
#define TMU_TCR2   0xffd80028  /* H */

#define	TMU_STR0	0x01
#define	TMU_STR1	0x02
#define	TMU_STR2	0x04
#define TCR_UNF     0x0100    

/*
 *
 *  ���ꥢ�륳�ߥ�˥�������󥤥󥿡��ե�����(SCI)
 *
 */
#define SCI_SCSMR1  0xffe00000    /* B */
#define SCI_SCBRR1  0xffe00004    /* B */
#define SCI_SCSCR1  0xffe00008    /* B */
#define SCI_SCTDR1  0xffe0000c    /* B */
#define SCI_SCSSR1  0xffe00010    /* B */
#define SCI_SCRDR1  0xffe00014    /* B */
#define SCI_SCSPTR1 0xffe0001c    /* B */


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
 *
 *  FIFO�դ����ꥢ�륳�ߥ�˥�������󥤥󥿡��ե�����(SCIF)�쥸����
 *
 */
#define SCIF_SCSMR2    0xffe80000   /* H */
#define SCIF_SCBRR2    0xffe80004   /* B */
#define SCIF_SCSCR2    0xffe80008   /* H */
#define SCIF_SCFTDR2   0xffe8000c   /* B */
#define SCIF_SCFSR2    0xffe80010   /* H */
#define SCIF_SCFRDR2   0xffe80014   /* B */
#define SCIF_SCFCR2    0xffe80018   /* H */
#define SCIF_SCFDR2    0xffe8001c   /* H */
#define	SCIF_SCSPTR2   0xffe80020   /* H */
#define	SCIF_SCLSR2	   0xffe80024   /* H */

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

#define SCFSR2_ER	  0x0080
#define SCFSR2_TEND	  0x0040
#define SCFSR2_TDFE	  0x0020
#define SCFSR2_BRK	  0x0010
#define SCFSR2_FER	  0x0008
#define SCFSR2_PER	  0x0004
#define SCFSR2_RDF	  0x0002
#define SCFSR2_DR	  0x0001

#define SCFCR2_RTRG1  0x0080
#define SCFCR2_RTRG0  0x0040
#define SCFCR2_TTRG1  0x0020
#define SCFCR2_TTRG0  0x0010
#define SCFCR2_MCE	  0x0008
#define SCFCR2_TFRST  0x0004
#define SCFCR2_RFRST  0x0002
#define SCFCR2_LOOP	  0x0001

#define SCSPTR2_RTSIO  0x0080
#define SCSPTR2_RTSDT  0x0040
#define SCSPTR2_CTSIO  0x0020
#define SCSPTR2_CTSDT  0x0010
#define SCSPTR2_SPB2IO 0x0002
#define SCSPTR2_SPB2DT 0x0001


/*
 * ����å�������쥸����
 */
#define	CCR	0xff00001c   /* W */
#define CCR_DISABLE   0x00000808  /* ����å���̵�� */


#endif /* _SH4_H_ */






