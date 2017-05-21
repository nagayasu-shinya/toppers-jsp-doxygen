/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2005 by Freelines CO.,Ltd 
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
 *  @(#) $Id: v850es_sg2.h,v 1.4 2007/03/23 08:20:08 honda Exp $
 */

#ifndef	_V850ES_SG2_H_
#define	_V850ES_SG2_H_
/*
 *	�ץ��å��˰�¸���������V850�ѡ�
 */
#ifndef _MACRO_ONLY
typedef unsigned char   byte;
typedef unsigned short  word;
typedef unsigned long   dword;
typedef volatile byte   IOREG;
typedef volatile word   HIOREG;
typedef volatile dword  LIOREG;
#endif /* _MACRO_ONLY */

/*
 * ��¢RAM
 */
#define	IRAM_TOP	0x03FF7000		/* ��¢RAM����Ƭ���ɥ쥹 */
#define IRAM_SIZE	0x8000			/* ��¢RAM���礭�� 32Kbyte(uPD70F3281Y) */
/*
 * ��¢FlashROM
 */
#define	IROM_TOP	0x0000000		/* ��¢FlashROM����Ƭ���ɥ쥹 */
#define IROM_SIZE	0x60000			/* ��¢FlashROM���礭�� 384Kbyte(uPD70F3281Y) */

/* 
 * V850ES/SG2��IO�쥸�������
 */
#define	PDL			0xFFFFF004		/* �ݡ���DL�쥸���� */
#define	PDLL		0xFFFFF004		/* �ݡ���DL�쥸����L */
#define	PDLH		0xFFFFF005		/* �ݡ���DL�쥸����H */
#define	PDH			0xFFFFF006		/* �ݡ���DH�쥸���� */
#define	PCT			0xFFFFF00A		/* �ݡ���CT�쥸���� */
#define	PCM			0xFFFFF00C		/* �ݡ���CM�쥸���� */
#define	PMDL		0xFFFFF024		/* �ݡ���DL�⡼�ɡ��쥸���� */
#define	PMDLL		0xFFFFF024		/* �ݡ���DL�⡼�ɡ��쥸����L */
#define	PMDLH		0xFFFFF025		/* �ݡ���DL�⡼�ɡ��쥸����H */
#define	PMDH		0xFFFFF026		/* �ݡ���DH�⡼�ɡ��쥸���� */
#define	PMCT		0xFFFFF02A		/* �ݡ���CT�⡼�ɡ��쥸���� */
#define	PMCM		0xFFFFF02C		/* �ݡ���CM�⡼�ɡ��쥸���� */
#define	PMCDL		0xFFFFF044		/* �ݡ���DL�⡼�ɡ�����ȥ��롦�쥸���� */
#define	PMCDLL		0xFFFFF044		/* �ݡ���DL�⡼�ɡ�����ȥ��롦�쥸����L */
#define	PMCDLH		0xFFFFF045		/* �ݡ���DL�⡼�ɡ�����ȥ��롦�쥸����H */
#define	PMCDH		0xFFFFF046		/* �ݡ���DH�⡼�ɡ�����ȥ��롦�쥸���� */
#define	PMCCT		0xFFFFF04A		/* �ݡ���CT�⡼�ɡ�����ȥ��롦�쥸���� */
#define	PMCCM		0xFFFFF04C		/* �ݡ���CM�⡼�ɡ�����ȥ��롦�쥸���� */
#define	BPC			0xFFFFF064		/* ����I/O�ΰ襻�쥯������쥸���� */
#define	BSC			0xFFFFF066		/* �Х���������������ե�����졼����󡦥쥸�������Х� */
#define	VSWC		0xFFFFF06E		/* �����ƥࡦ�������ȡ�����ȥ��롦�쥸���� */
#define	DSA0L		0xFFFFF080		/* DMA�����������ɥ쥹���쥸����0L */
#define	DSA0H		0xFFFFF082		/* DMA�����������ɥ쥹���쥸����0H */
#define	DDA0L		0xFFFFF084		/* DMA�ǥ��ƥ��͡�����󡦥��ɥ쥹���쥸����0L */
#define	DDA0H		0xFFFFF086		/* DMA�ǥ��ƥ��͡�����󡦥��ɥ쥹���쥸����0H */
#define	DSA1L		0xFFFFF088		/* DMA�����������ɥ쥹���쥸����1L */
#define	DSA1H		0xFFFFF08A		/* DMA�����������ɥ쥹���쥸����1H */
#define	DDA1L		0xFFFFF08C		/* DMA�ǥ��ƥ��͡�����󡦥��ɥ쥹���쥸����1L */
#define	DDA1H		0xFFFFF08E		/* DMA�ǥ��ƥ��͡�����󡦥��ɥ쥹���쥸����1H */
#define	DSA2L		0xFFFFF090		/* DMA�����������ɥ쥹���쥸����2L */
#define	DSA2H		0xFFFFF092		/* DMA�����������ɥ쥹���쥸����2H */
#define	DDA2L		0xFFFFF094		/* DMA�ǥ��ƥ��͡�����󡦥��ɥ쥹���쥸����2L */
#define	DDA2H		0xFFFFF096		/* DMA�ǥ��ƥ��͡�����󡦥��ɥ쥹���쥸����2H */
#define	DSA3L		0xFFFFF098		/* DMA�����������ɥ쥹���쥸����3L */
#define	DSA3H		0xFFFFF09A		/* DMA�����������ɥ쥹���쥸����3H */
#define	DDA3L		0xFFFFF09C		/* DMA�ǥ��ƥ��͡�����󡦥��ɥ쥹���쥸����3L */
#define	DDA3H		0xFFFFF09E		/* DMA�ǥ��ƥ��͡�����󡦥��ɥ쥹���쥸����3H */
#define	DBC0		0xFFFFF0C0		/* DMAž��������ȡ��쥸����0 */
#define	DBC1		0xFFFFF0C2		/* DMAž��������ȡ��쥸����1 */
#define	DBC2		0xFFFFF0C4		/* DMAž��������ȡ��쥸����2 */
#define	DBC3		0xFFFFF0C6		/* DMAž��������ȡ��쥸����3 */
#define	DADC0		0xFFFFF0D0		/* DMA���ɥ쥷�󥰡�����ȥ��롦�쥸����0 */
#define	DADC1		0xFFFFF0D2		/* DMA���ɥ쥷�󥰡�����ȥ��롦�쥸����1 */
#define	DADC2		0xFFFFF0D4		/* DMA���ɥ쥷�󥰡�����ȥ��롦�쥸����2 */
#define	DADC3		0xFFFFF0D6		/* DMA���ɥ쥷�󥰡�����ȥ��롦�쥸����3 */
#define	DCHC0		0xFFFFF0E0		/* DMA����ͥ롦����ȥ��롦�쥸����0 */
#define	DCHC1		0xFFFFF0E2		/* DMA����ͥ롦����ȥ��롦�쥸����1 */
#define	DCHC2		0xFFFFF0E4		/* DMA����ͥ롦����ȥ��롦�쥸����2 */
#define	DCHC3		0xFFFFF0E6		/* DMA����ͥ롦����ȥ��롦�쥸����3 */
#define	IMR0		0xFFFFF100		/* �����ߥޥ������쥸����0 */
#define	IMR0L		0xFFFFF100		/* �����ߥޥ������쥸����0L */
#define	IMR0H		0xFFFFF101		/* �����ߥޥ������쥸����0H */
#define	IMR1		0xFFFFF102		/* �����ߥޥ������쥸����1 */
#define	IMR1L		0xFFFFF102		/* �����ߥޥ������쥸����1L */
#define	IMR1H		0xFFFFF103		/* �����ߥޥ������쥸����1H */
#define	IMR2		0xFFFFF104		/* �����ߥޥ������쥸����2 */
#define	IMR2L		0xFFFFF104		/* �����ߥޥ������쥸����2L */
#define	IMR2H		0xFFFFF105		/* �����ߥޥ������쥸����2H */
#define	IMR3		0xFFFFF106		/* �����ߥޥ������쥸����3 */
#define	IMR3L		0xFFFFF106		/* �����ߥޥ������쥸����3L */
#define	IMR3H		0xFFFFF107		/* �����ߥޥ������쥸����3H */
#define	LVIIC		0xFFFFF110		/* ����������쥸���� */
#define	PIC0		0xFFFFF112		/* ����������쥸���� */
#define	PIC1		0xFFFFF114		/* ����������쥸���� */
#define	PIC2		0xFFFFF116		/* ����������쥸���� */
#define	PIC3		0xFFFFF118		/* ����������쥸���� */
#define	PIC4		0xFFFFF11A		/* ����������쥸���� */
#define	PIC5		0xFFFFF11C		/* ����������쥸���� */
#define	PIC6		0xFFFFF11E		/* ����������쥸���� */
#define	PIC7		0xFFFFF120		/* ����������쥸���� */
#define	TQ0OVIC		0xFFFFF122		/* ����������쥸���� */
#define	TQ0CCIC0	0xFFFFF124		/* ����������쥸���� */
#define	TQ0CCIC1	0xFFFFF126		/* ����������쥸���� */
#define	TQ0CCIC2	0xFFFFF128		/* ����������쥸���� */
#define	TQ0CCIC3	0xFFFFF12A		/* ����������쥸���� */
#define	TP0OVIC		0xFFFFF12C		/* ����������쥸���� */
#define	TP0CCIC0	0xFFFFF12E		/* ����������쥸���� */
#define	TP0CCIC1	0xFFFFF130		/* ����������쥸���� */
#define	TP1OVIC		0xFFFFF132		/* ����������쥸���� */
#define	TP1CCIC0	0xFFFFF134		/* ����������쥸���� */
#define	TP1CCIC1	0xFFFFF136		/* ����������쥸���� */
#define	TP2OVIC		0xFFFFF138		/* ����������쥸���� */
#define	TP2CCIC0	0xFFFFF13A		/* ����������쥸���� */
#define	TP2CCIC1	0xFFFFF13C		/* ����������쥸���� */
#define	TP3OVIC		0xFFFFF13E		/* ����������쥸���� */
#define	TP3CCIC0	0xFFFFF140		/* ����������쥸���� */
#define	TP3CCIC1	0xFFFFF142		/* ����������쥸���� */
#define	TP4OVIC		0xFFFFF144		/* ����������쥸���� */
#define	TP4CCIC0	0xFFFFF146		/* ����������쥸���� */
#define	TP4CCIC1	0xFFFFF148		/* ����������쥸���� */
#define	TP5OVIC		0xFFFFF14A		/* ����������쥸���� */
#define	TP5CCIC0	0xFFFFF14C		/* ����������쥸���� */
#define	TP5CCIC1	0xFFFFF14E		/* ����������쥸���� */
#define	TM0EQIC0	0xFFFFF150		/* ����������쥸���� */
#define	CB0RIC		0xFFFFF152		/* ����������쥸���� */
#define	IICIC1		0xFFFFF152		/* ����������쥸���� */
#define	CB0TIC		0xFFFFF154		/* ����������쥸���� */
#define	CB1RIC		0xFFFFF156		/* ����������쥸���� */
#define	CB1TIC		0xFFFFF158		/* ����������쥸���� */
#define	CB2RIC		0xFFFFF15A		/* ����������쥸���� */
#define	CB2TIC		0xFFFFF15C		/* ����������쥸���� */
#define	CB3RIC		0xFFFFF15E		/* ����������쥸���� */
#define	CB3TIC		0xFFFFF160		/* ����������쥸���� */
#define	UA0RIC		0xFFFFF162		/* ����������쥸���� */
#define	CB4RIC		0xFFFFF162		/* ����������쥸���� */
#define	UA0TIC		0xFFFFF164		/* ����������쥸���� */
#define	CB4TIC		0xFFFFF164		/* ����������쥸���� */
#define	UA1RIC		0xFFFFF166		/* ����������쥸���� */
#define	IICIC2		0xFFFFF166		/* ����������쥸���� */
#define	UA1TIC		0xFFFFF168		/* ����������쥸���� */
#define	UA2RIC		0xFFFFF16A		/* ����������쥸���� */
#define	IICIC0		0xFFFFF16A		/* ����������쥸���� */
#define	UA2TIC		0xFFFFF16C		/* ����������쥸���� */
#define	ADIC		0xFFFFF16E		/* ����������쥸���� */
#define	DMAIC0		0xFFFFF170		/* ����������쥸���� */
#define	DMAIC1		0xFFFFF172		/* ����������쥸���� */
#define	DMAIC2		0xFFFFF174		/* ����������쥸���� */
#define	DMAIC3		0xFFFFF176		/* ����������쥸���� */
#define	KRIC		0xFFFFF178		/* ����������쥸���� */
#define	WTIIC		0xFFFFF17A		/* ����������쥸���� */
#define	WTIC		0xFFFFF17C		/* ����������쥸���� */
#define	ERRIC0		0xFFFFF17E		/* ����������쥸���� */
#define	ERRIC		0xFFFFF17E		/* ����������쥸���� */
#define	WUPIC0		0xFFFFF180		/* ����������쥸���� */
#define	STAIC		0xFFFFF180		/* ����������쥸���� */
#define	RECIC0		0xFFFFF182		/* ����������쥸���� */
#define	IEIC1		0xFFFFF182		/* ����������쥸���� */
#define	TRXIC0		0xFFFFF184		/* ����������쥸���� */
#define	IEIC2		0xFFFFF184		/* ����������쥸���� */
#define	ISPR		0xFFFFF1FA		/* ���󥵡��ӥ����ץ饤����ƥ����쥸���� */
#define	PRCMD		0xFFFFF1FC		/* ���ޥ�ɡ��쥸���� */
#define	PSC			0xFFFFF1FE		/* �ѥ�������֡�����ȥ��롦�쥸���� */
#define	ADA0M0		0xFFFFF200		/* A/D����С������⡼�ɡ��쥸����0 */
#define	ADA0M1		0xFFFFF201		/* A/D����С������⡼�ɡ��쥸����1 */
#define	ADA0S		0xFFFFF202		/* A/D����С���������ͥ����쥸���� */
#define	ADA0M2		0xFFFFF203		/* A/D����С������⡼�ɡ��쥸����2 */
#define	ADA0PFM		0xFFFFF204		/* �ѥ���ե�������ӥ⡼�ɡ��쥸���� */
#define	ADA0PFT		0xFFFFF205		/* �ѥ���ե�������Ӥ������ͥ쥸���� */
#define	ADA0CR0		0xFFFFF210		/* A/D�Ѵ���̥쥸����0 */
#define	ADA0CR0H	0xFFFFF211		/* A/D�Ѵ���̥쥸����0H */
#define	ADA0CR1		0xFFFFF212		/* A/D�Ѵ���̥쥸����1 */
#define	ADA0CR1H	0xFFFFF213		/* A/D�Ѵ���̥쥸����1H */
#define	ADA0CR2		0xFFFFF214		/* A/D�Ѵ���̥쥸����2 */
#define	ADA0CR2H	0xFFFFF215		/* A/D�Ѵ���̥쥸����2H */
#define	ADA0CR3		0xFFFFF216		/* A/D�Ѵ���̥쥸����3 */
#define	ADA0CR3H	0xFFFFF217		/* A/D�Ѵ���̥쥸����3H */
#define	ADA0CR4		0xFFFFF218		/* A/D�Ѵ���̥쥸����4 */
#define	ADA0CR4H	0xFFFFF219		/* A/D�Ѵ���̥쥸����4H */
#define	ADA0CR5		0xFFFFF21A		/* A/D�Ѵ���̥쥸����5 */
#define	ADA0CR5H	0xFFFFF21B		/* A/D�Ѵ���̥쥸����5H */
#define	ADA0CR6		0xFFFFF21C		/* A/D�Ѵ���̥쥸����6 */
#define	ADA0CR6H	0xFFFFF21D		/* A/D�Ѵ���̥쥸����6H */
#define	ADA0CR7		0xFFFFF21E		/* A/D�Ѵ���̥쥸����7 */
#define	ADA0CR7H	0xFFFFF21F		/* A/D�Ѵ���̥쥸����7H */
#define	ADA0CR8		0xFFFFF220		/* A/D�Ѵ���̥쥸����8 */
#define	ADA0CR8H	0xFFFFF221		/* A/D�Ѵ���̥쥸����8H */
#define	ADA0CR9		0xFFFFF222		/* A/D�Ѵ���̥쥸����9 */
#define	ADA0CR9H	0xFFFFF223		/* A/D�Ѵ���̥쥸����9H */
#define	ADA0CR10	0xFFFFF224		/* A/D�Ѵ���̥쥸����10 */
#define	ADA0CR10H	0xFFFFF225		/* A/D�Ѵ���̥쥸����10H */
#define	ADA0CR11	0xFFFFF226		/* A/D�Ѵ���̥쥸����11 */
#define	ADA0CR11H	0xFFFFF227		/* A/D�Ѵ���̥쥸����11H */
#define	DA0CS0		0xFFFFF280		/* D/A����С����Ѵ�������쥸����0 */
#define	DA0CS1		0xFFFFF281		/* D/A����С����Ѵ�������쥸����1 */
#define	DA0M		0xFFFFF282		/* D/A����С������⡼�ɡ��쥸���� */
#define	KRM			0xFFFFF300		/* �������꥿���󡦥⡼�ɡ��쥸���� */
#define	SELCNT0		0xFFFFF308		/* ���쥯��ư������쥸���� */
#define	CRCIN		0xFFFFF310		/* CRC����ץåȡ��쥸���� */
#define	CRCD		0xFFFFF312		/* CRC�ǡ������쥸���� */
#define	NFC			0xFFFFF318		/* �Υ�����������쥸���� */
#define	PRSM1		0xFFFFF320		/* BRG1�ץꥹ�����顦�⡼�ɡ��쥸���� */
#define	PRSCM1		0xFFFFF321		/* BRG1�ץꥹ�����顦����ڥ����쥸���� */
#define	PRSM2		0xFFFFF324		/* BRG2�ץꥹ�����顦�⡼�ɡ��쥸���� */
#define	PRSCM2		0xFFFFF325		/* BRG2�ץꥹ�����顦����ڥ����쥸���� */
#define	PRSM3		0xFFFFF328		/* BRG3�ץꥹ�����顦�⡼�ɡ��쥸���� */
#define	PRSCM3		0xFFFFF329		/* BRG3�ץꥹ�����顦����ڥ����쥸���� */
#define	OCKS0		0xFFFFF340		/* IICʬ������å�����쥸����0 */
#define	OCKS1		0xFFFFF344		/* IICʬ������å�����쥸����1 */
#define	OCKS2		0xFFFFF348		/* IEBus����å�����쥸���� */
#define	BCR			0xFFFFF360		/* IEBus����ȥ��롦�쥸���� */
#define	PSR			0xFFFFF361		/* IEBus�ѥ�������֡��쥸���� */
#define	SSR			0xFFFFF362		/* IEBus���졼�֡����ơ��������쥸���� */
#define	USR			0xFFFFF363		/* IEBus��˥åȡ����ơ��������쥸���� */
#define	ISR			0xFFFFF364		/* IEBus���󥿥�ץȡ����ơ��������쥸���� */
#define	ESR			0xFFFFF365		/* IEBus���顼�����ơ��������쥸���� */
#define	UAR			0xFFFFF366		/* IEBus��˥åȡ����ɥ쥹���쥸���� */
#define	SAR			0xFFFFF368		/* IEBus���졼�֡����ɥ쥹���쥸���� */
#define	PAR			0xFFFFF36A		/* IEBus�ѡ��ȥʡ����ɥ쥹���쥸���� */
#define	RSA			0xFFFFF36C		/* IEBus�������졼�֡����ɥ쥹���쥸���� */
#define	CDR			0xFFFFF36E		/* IEBus����ȥ��롦�ǡ������쥸���� */
#define	DLR			0xFFFFF36F		/* IEBus��ʸĹ�쥸���� */
#define	DR			0xFFFFF370		/* IEBus�ǡ������쥸���� */
#define	FSR			0xFFFFF371		/* IEBus�ե�����ɡ����ơ��������쥸���� */
#define	SCR			0xFFFFF372		/* IEBus����������������ȡ��쥸���� */
#define	CCR			0xFFFFF373		/* IEBus���ߥ�˥�������󡦥�����ȡ��쥸���� */
#define	P0			0xFFFFF400		/* �ݡ���0�쥸���� */
#define	P1			0xFFFFF402		/* �ݡ���1�쥸���� */
#define	P3			0xFFFFF406		/* �ݡ���3�쥸���� */
#define	P3L			0xFFFFF406		/* �ݡ���3�쥸����L */
#define	P3H			0xFFFFF407		/* �ݡ���3�쥸����H */
#define	P4			0xFFFFF408		/* �ݡ���4�쥸���� */
#define	P5			0xFFFFF40A		/* �ݡ���5�쥸���� */
#define	P7L			0xFFFFF40E		/* �ݡ���7�쥸����L */
#define	P7H			0xFFFFF40F		/* �ݡ���7�쥸����H */
#define	P9			0xFFFFF412		/* �ݡ���9�쥸���� */
#define	P9L			0xFFFFF412		/* �ݡ���9�쥸����L */
#define	P9H			0xFFFFF413		/* �ݡ���9�쥸����H */
#define	PM0			0xFFFFF420		/* �ݡ���0�⡼�ɡ��쥸���� */
#define	PM1			0xFFFFF422		/* �ݡ���1�⡼�ɡ��쥸���� */
#define	PM3			0xFFFFF426		/* �ݡ���3�⡼�ɡ��쥸���� */
#define	PM3L		0xFFFFF426		/* �ݡ���3�⡼�ɡ��쥸����L */
#define	PM3H		0xFFFFF427		/* �ݡ���3�⡼�ɡ��쥸����H */
#define	PM4			0xFFFFF428		/* �ݡ���4�⡼�ɡ��쥸���� */
#define	PM5			0xFFFFF42A		/* �ݡ���5�⡼�ɡ��쥸���� */
#define	PM7L		0xFFFFF42E		/* �ݡ���7�⡼�ɡ��쥸����L */
#define	PM7H		0xFFFFF42F		/* �ݡ���7�⡼�ɡ��쥸����H */
#define	PM9			0xFFFFF432		/* �ݡ���9�⡼�ɡ��쥸���� */
#define	PM9L		0xFFFFF432		/* �ݡ���9�⡼�ɡ��쥸����L */
#define	PM9H		0xFFFFF433		/* �ݡ���9�⡼�ɡ��쥸����H */
#define	PMC0		0xFFFFF440		/* �ݡ���0�⡼�ɡ�����ȥ��롦�쥸���� */
#define	PMC3		0xFFFFF446		/* �ݡ���3�⡼�ɡ�����ȥ��롦�쥸���� */
#define	PMC3L		0xFFFFF446		/* �ݡ���3�⡼�ɡ�����ȥ��롦�쥸����L */
#define	PMC3H		0xFFFFF447		/* �ݡ���3�⡼�ɡ�����ȥ��롦�쥸����H */
#define	PMC4		0xFFFFF448		/* �ݡ���4�⡼�ɡ�����ȥ��롦�쥸���� */
#define	PMC5		0xFFFFF44A		/* �ݡ���5�⡼�ɡ�����ȥ��롦�쥸���� */
#define	PMC9		0xFFFFF452		/* �ݡ���9�⡼�ɡ�����ȥ��롦�쥸���� */
#define	PMC9L		0xFFFFF452		/* �ݡ���9�⡼�ɡ�����ȥ��롦�쥸����L */
#define	PMC9H		0xFFFFF453		/* �ݡ���9�⡼�ɡ�����ȥ��롦�쥸����H */
#define	PFC0		0xFFFFF460		/* �ݡ���0�ե��󥯥���󡦥���ȥ��롦�쥸���� */
#define	PFC3		0xFFFFF466		/* �ݡ���3�ե��󥯥���󡦥���ȥ��롦�쥸���� */
#define	PFC3L		0xFFFFF466		/* �ݡ���3�ե��󥯥���󡦥���ȥ��롦�쥸����L */
#define	PFC3H		0xFFFFF467		/* �ݡ���3�ե��󥯥���󡦥���ȥ��롦�쥸����H */
#define	PFC4		0xFFFFF468		/* �ݡ���4�ե��󥯥���󡦥���ȥ��롦�쥸���� */
#define	PFC5		0xFFFFF46A		/* �ݡ���5�ե��󥯥���󡦥���ȥ��롦�쥸���� */
#define	PFC9		0xFFFFF472		/* �ݡ���9�ե��󥯥���󡦥���ȥ��롦�쥸���� */
#define	PFC9L		0xFFFFF472		/* �ݡ���9�ե��󥯥���󡦥���ȥ��롦�쥸����L */
#define	PFC9H		0xFFFFF473		/* �ݡ���9�ե��󥯥���󡦥���ȥ��롦�쥸����H */
#define	DWC0		0xFFFFF484		/* �ǡ������������ȡ�����ȥ��롦�쥸����0 */
#define	AWC			0xFFFFF488		/* ���ɥ쥹���������ȡ�����ȥ��롦�쥸���� */
#define	BCC			0xFFFFF48A		/* �Х����������롦����ȥ��롦�쥸���� */
#define	TQ0CTL0		0xFFFFF540		/* TMQ0����쥸����0 */
#define	TQ0CTL1		0xFFFFF541		/* TMQ0����쥸����1 */
#define	TQ0IOC0		0xFFFFF542		/* TMQ0I/O����쥸����0 */
#define	TQ0IOC1		0xFFFFF543		/* TMQ0I/O����쥸����1 */
#define	TQ0IOC2		0xFFFFF544		/* TMQ0I/O����쥸����2 */
#define	TQ0OPT0		0xFFFFF545		/* TMQ0���ץ���󡦥쥸���� */
#define	TQ0CCR0		0xFFFFF546		/* TMQ0����ץ��㡿����ڥ����쥸����0 */
#define	TQ0CCR1		0xFFFFF548		/* TMQ0����ץ��㡿����ڥ����쥸����1 */
#define	TQ0CCR2		0xFFFFF54A		/* TMQ0����ץ��㡿����ڥ����쥸����2 */
#define	TQ0CCR3		0xFFFFF54C		/* TMQ0����ץ��㡿����ڥ����쥸����3 */
#define	TQ0CNT		0xFFFFF54E		/* TMQ0�����󥿡��꡼�ɡ��Хåե����쥸���� */
#define	TP0CTL0		0xFFFFF590		/* TMP0����쥸����0 */
#define	TP0CTL1		0xFFFFF591		/* TMP0����쥸����1 */
#define	TP0IOC0		0xFFFFF592		/* TMP0I/O����쥸����0 */
#define	TP0IOC1		0xFFFFF593		/* TMP0I/O����쥸����1 */
#define	TP0IOC2		0xFFFFF594		/* TMP0I/O����쥸����2 */
#define	TP0OPT0		0xFFFFF595		/* TMP0���ץ���󡦥쥸���� */
#define	TP0CCR0		0xFFFFF596		/* TMP0����ץ��㡿����ڥ����쥸����0 */
#define	TP0CCR1		0xFFFFF598		/* TMP0����ץ��㡿����ڥ����쥸����1 */
#define	TP0CNT		0xFFFFF59A		/* TMP0�����󥿡��꡼�ɡ��Хåե����쥸���� */
#define	TP1CTL0		0xFFFFF5A0		/* TMP1����쥸����0 */
#define	TP1CTL1		0xFFFFF5A1		/* TMP1����쥸����1 */
#define	TP1IOC0		0xFFFFF5A2		/* TMP1I/O����쥸����0 */
#define	TP1IOC1		0xFFFFF5A3		/* TMP1I/O����쥸����1 */
#define	TP1IOC2		0xFFFFF5A4		/* TMP1I/O����쥸����2 */
#define	TP1OPT0		0xFFFFF5A5		/* TMP1���ץ���󡦥쥸���� */
#define	TP1CCR0		0xFFFFF5A6		/* TMP1����ץ��㡿����ڥ����쥸����0 */
#define	TP1CCR1		0xFFFFF5A8		/* TMP1����ץ��㡿����ڥ����쥸����1 */
#define	TP1CNT		0xFFFFF5AA		/* TMP1�����󥿡��꡼�ɡ��Хåե����쥸���� */
#define	TP2CTL0		0xFFFFF5B0		/* TMP2����쥸����0 */
#define	TP2CTL1		0xFFFFF5B1		/* TMP2����쥸����1 */
#define	TP2IOC0		0xFFFFF5B2		/* TMP2I/O����쥸����0 */
#define	TP2IOC1		0xFFFFF5B3		/* TMP2I/O����쥸����1 */
#define	TP2IOC2		0xFFFFF5B4		/* TMP2I/O����쥸����2 */
#define	TP2OPT0		0xFFFFF5B5		/* TMP2���ץ���󡦥쥸���� */
#define	TP2CCR0		0xFFFFF5B6		/* TMP2����ץ��㡿����ڥ����쥸����0 */
#define	TP2CCR1		0xFFFFF5B8		/* TMP2����ץ��㡿����ڥ����쥸����1 */
#define	TP2CNT		0xFFFFF5BA		/* TMP2�����󥿡��꡼�ɡ��Хåե����쥸���� */
#define	TP3CTL0		0xFFFFF5C0		/* TMP3����쥸����0 */
#define	TP3CTL1		0xFFFFF5C1		/* TMP3����쥸����1 */
#define	TP3IOC0		0xFFFFF5C2		/* TMP3I/O����쥸����0 */
#define	TP3IOC1		0xFFFFF5C3		/* TMP3I/O����쥸����1 */
#define	TP3IOC2		0xFFFFF5C4		/* TMP3I/O����쥸����2 */
#define	TP3OPT0		0xFFFFF5C5		/* TMP3���ץ���󡦥쥸���� */
#define	TP3CCR0		0xFFFFF5C6		/* TMP3����ץ��㡿����ڥ����쥸����0 */
#define	TP3CCR1		0xFFFFF5C8		/* TMP3����ץ��㡿����ڥ����쥸����1 */
#define	TP3CNT		0xFFFFF5CA		/* TMP3�����󥿡��꡼�ɡ��Хåե����쥸���� */
#define	TP4CTL0		0xFFFFF5D0		/* TMP4����쥸����0 */
#define	TP4CTL1		0xFFFFF5D1		/* TMP4����쥸����1 */
#define	TP4IOC0		0xFFFFF5D2		/* TMP4I/O����쥸����0 */
#define	TP4IOC1		0xFFFFF5D3		/* TMP4I/O����쥸����1 */
#define	TP4IOC2		0xFFFFF5D4		/* TMP4I/O����쥸����2 */
#define	TP4OPT0		0xFFFFF5D5		/* TMP4���ץ���󡦥쥸���� */
#define	TP4CCR0		0xFFFFF5D6		/* TMP4����ץ��㡿����ڥ����쥸����0 */
#define	TP4CCR1		0xFFFFF5D8		/* TMP4����ץ��㡿����ڥ����쥸����1 */
#define	TP4CNT		0xFFFFF5DA		/* TMP4�����󥿡��꡼�ɡ��Хåե����쥸���� */
#define	TP5CTL0		0xFFFFF5E0		/* TMP5����쥸����0 */
#define	TP5CTL1		0xFFFFF5E1		/* TMP5����쥸����1 */
#define	TP5IOC0		0xFFFFF5E2		/* TMP5I/O����쥸����0 */
#define	TP5IOC1		0xFFFFF5E3		/* TMP5I/O����쥸����1 */
#define	TP5IOC2		0xFFFFF5E4		/* TMP5I/O����쥸����2 */
#define	TP5OPT0		0xFFFFF5E5		/* TMP5���ץ���󡦥쥸���� */
#define	TP5CCR0		0xFFFFF5E6		/* TMP5����ץ��㡿����ڥ����쥸����0 */
#define	TP5CCR1		0xFFFFF5E8		/* TMP5����ץ��㡿����ڥ����쥸����1 */
#define	TP5CNT		0xFFFFF5EA		/* TMP5�����󥿡��꡼�ɡ��Хåե����쥸���� */
#define	WTM			0xFFFFF680		/* ���ץ�����ư��⡼�ɡ��쥸���� */
#define	TM0CTL0		0xFFFFF690		/* TMM0����쥸����0 */
#define	TM0CMP0		0xFFFFF694		/* TMM0����ڥ����쥸����0 */
#define	OSTS		0xFFFFF6C0		/* ȯ�������������쥸���� */
#define	PLLS		0xFFFFF6C1		/* PLL��å����å׻��ֻ���쥸���� */
#define	WDTM2		0xFFFFF6D0		/* �����å��ɥå��������ޡ��⡼�ɡ��쥸����2 */
#define	WDTE		0xFFFFF6D1		/* �����å��ɥå��������ޡ����͡��֥롦�쥸���� */
#define	RTBL0		0xFFFFF6E0		/* �ꥢ�륿������ϥХåե����쥸����0�� */
#define	RTBH0		0xFFFFF6E2		/* �ꥢ�륿������ϥХåե����쥸����0H */
#define	RTPM0		0xFFFFF6E4		/* �ꥢ�륿������ϥݡ��ȡ��⡼�ɡ��쥸����0 */
#define	RTPC0		0xFFFFF6E5		/* �ꥢ�륿������ϥݡ��ȡ�����ȥ��롦�쥸����0 */
#define	PFCE3L		0xFFFFF706		/* �ݡ���3�ե��󥯥���󡦥���ȥ����ĥ�쥸����L */
#define	PFCE5		0xFFFFF70A		/* �ݡ���5�ե��󥯥���󡦥���ȥ����ĥ�쥸���� */
#define	PFCE9		0xFFFFF712		/* �ݡ���9�ե��󥯥���󡦥���ȥ����ĥ�쥸���� */
#define	PFCE9L		0xFFFFF712		/* �ݡ���9�ե��󥯥���󡦥���ȥ����ĥ�쥸����L */
#define	PFCE9H		0xFFFFF713		/* �ݡ���9�ե��󥯥���󡦥���ȥ����ĥ�쥸����H */
#define	SYS			0xFFFFF802		/* �����ƥࡦ���ơ��������쥸���� */
#define	RCM			0xFFFFF80C		/* ���OSC�⡼�ɡ��쥸���� */
#define	DTFR0		0xFFFFF810		/* DMA�ȥꥬ�װ��쥸����0 */
#define	DTFR1		0xFFFFF812		/* DMA�ȥꥬ�װ��쥸����1 */
#define	DTFR2		0xFFFFF814		/* DMA�ȥꥬ�װ��쥸����2 */
#define	DTFR3		0xFFFFF816		/* DMA�ȥꥬ�װ��쥸����3 */
#define	PSMR		0xFFFFF820		/* �ѥ�������֡��⡼�ɡ��쥸���� */
#define	CKC			0xFFFFF822		/* ����å�������ȥ��롦�쥸���� */
#define	LOCKR		0xFFFFF824		/* ��å����쥸���� */
#define	PCC			0xFFFFF828		/* �ץ��å�������å�������ȥ��롦�쥸���� */
#define	PLLCTL		0xFFFFF82C		/* PLL����ȥ��롦�쥸���� */
#define	CCLS		0xFFFFF82E		/* CPUư���å������ơ��������쥸���� */
#define	CORAD0		0xFFFFF840		/* ���쥯����󡦥��ɥ쥹���쥸����0 */
#define	CORAD0L		0xFFFFF840		/* ���쥯����󡦥��ɥ쥹���쥸����0L */
#define	CORAD0H		0xFFFFF842		/* ���쥯����󡦥��ɥ쥹���쥸����0H */
#define	CORAD1		0xFFFFF844		/* ���쥯����󡦥��ɥ쥹���쥸����1 */
#define	CORAD1L		0xFFFFF844		/* ���쥯����󡦥��ɥ쥹���쥸����1L */
#define	CORAD1H		0xFFFFF846		/* ���쥯����󡦥��ɥ쥹���쥸����1H */
#define	CORAD2		0xFFFFF848		/* ���쥯����󡦥��ɥ쥹���쥸����2 */
#define	CORAD2L		0xFFFFF848		/* ���쥯����󡦥��ɥ쥹���쥸����2L */
#define	CORAD2H		0xFFFFF84A		/* ���쥯����󡦥��ɥ쥹���쥸����2H */
#define	CORAD3		0xFFFFF84C		/* ���쥯����󡦥��ɥ쥹���쥸����3 */
#define	CORAD3L		0xFFFFF84C		/* ���쥯����󡦥��ɥ쥹���쥸����3L */
#define	CORAD3H		0xFFFFF84E		/* ���쥯����󡦥��ɥ쥹���쥸����3H */
#define	CLM			0xFFFFF870		/* ����å�����˥����⡼�ɡ��쥸���� */
#define	CORCN		0xFFFFF880		/* ���쥯����󡦥���ȥ��롦�쥸���� */
#define	RESF		0xFFFFF888		/* �ꥻ�å��װ��ե饰���쥸���� */
#define	LVIM		0xFFFFF890		/* ���Ű����Х쥸���� */
#define	LVIS		0xFFFFF891		/* ���Ű����Х�٥�����쥸���� */
#define	RAMS		0xFFFFF892		/* ��¢RAM�ǡ��������ơ��������쥸���� */
#define	PRSM0		0xFFFFF8B0		/* �ץꥹ�����顦�⡼�ɡ��쥸���� */
#define	PRSCM0		0xFFFFF8B1		/* �ץꥹ�����顦����ڥ����쥸���� */
#define	OCDM		0xFFFFF9FC		/* ������åס��ǥ��Х����⡼�ɡ��쥸���� */
#define	PEMU1		0xFFFFF9FE		/* ���ե��ߥ�졼����󡦥쥸����1 */
#define	UA0CTL0		0xFFFFFA00		/* UARTA0����쥸����0 */
#define	UA0CTL1		0xFFFFFA01		/* UARTA0����쥸����1 */
#define	UA0CTL2		0xFFFFFA02		/* UARTA0����쥸����2 */
#define	UA0OPT0		0xFFFFFA03		/* UARTA0���ץ��������쥸����0 */
#define	UA0STR		0xFFFFFA04		/* UARTA0���֥쥸���� */
#define	UA0RX		0xFFFFFA06		/* UARTA0�����ǡ������쥸���� */
#define	UA0TX		0xFFFFFA07		/* UARTA0�����ǡ������쥸���� */
#define	UA1CTL0		0xFFFFFA10		/* UARTA1����쥸����0 */
#define	UA1CTL1		0xFFFFFA11		/* UARTA1����쥸����1 */
#define	UA1CTL2		0xFFFFFA12		/* UARTA1����쥸����2 */
#define	UA1OPT0		0xFFFFFA13		/* UARTA1���ץ��������쥸����0 */
#define	UA1STR		0xFFFFFA14		/* UARTA1���֥쥸���� */
#define	UA1RX		0xFFFFFA16		/* UARTA1�����ǡ������쥸���� */
#define	UA1TX		0xFFFFFA17		/* UARTA1�����ǡ������쥸���� */
#define	UA2CTL0		0xFFFFFA20		/* UARTA2����쥸����0 */
#define	UA2CTL1		0xFFFFFA21		/* UARTA2����쥸����1 */
#define	UA2CTL2		0xFFFFFA22		/* UARTA2����쥸����2 */
#define	UA2OPT0		0xFFFFFA23		/* UARTA2���ץ��������쥸����0 */
#define	UA2STR		0xFFFFFA24		/* UARTA2���֥쥸���� */
#define	UA2RX		0xFFFFFA26		/* UARTA2�����ǡ������쥸���� */
#define	UA2TX		0xFFFFFA27		/* UARTA2�����ǡ������쥸���� */
#define	INTF0		0xFFFFFC00		/* ����������Ω�������ꥨ�å�����쥸����0 */
#define	INTF3		0xFFFFFC06		/* ����������Ω�������ꥨ�å�����쥸����3 */
#define	INTF9H		0xFFFFFC13		/* ����������Ω�������ꥨ�å�����쥸����9H */
#define	INTR0		0xFFFFFC20		/* ����������Ω���夬�ꥨ�å�����쥸����0 */
#define	INTR3		0xFFFFFC26		/* ����������Ω���夬�ꥨ�å�����쥸����3 */
#define	INTR9H		0xFFFFFC33		/* ����������Ω���夬�ꥨ�å�����쥸����9H */
#define	PF0			0xFFFFFC60		/* �ݡ���0�ե��󥯥��������쥸���� */
#define	PF3			0xFFFFFC66		/* �ݡ���3�ե��󥯥��������쥸���� */
#define	PF3L		0xFFFFFC66		/* �ݡ���3�ե��󥯥��������쥸����L */
#define	PF3H		0xFFFFFC67		/* �ݡ���3�ե��󥯥��������쥸����H */
#define	PF4			0xFFFFFC68		/* �ݡ���4�ե��󥯥��������쥸���� */
#define	PF5			0xFFFFFC6A		/* �ݡ���5�ե��󥯥��������쥸���� */
#define	PF9			0xFFFFFC72		/* �ݡ���9�ե��󥯥��������쥸���� */
#define	PF9L		0xFFFFFC72		/* �ݡ���9�ե��󥯥��������쥸����L */
#define	PF9H		0xFFFFFC73		/* �ݡ���9�ե��󥯥��������쥸����H */
#define	CB0CTL0		0xFFFFFD00		/* CSIB0����쥸����0 */
#define	CB0CTL1		0xFFFFFD01		/* CSIB0����쥸����1 */
#define	CB0CTL2		0xFFFFFD02		/* CSIB0����쥸����2 */
#define	CB0STR		0xFFFFFD03		/* CSIB0���֥쥸���� */
#define	CB0RX		0xFFFFFD04		/* CSIB0�����ǡ������쥸���� */
#define	CB0RXL		0xFFFFFD04		/* CSIB0�����ǡ������쥸����L */
#define	CB0TX		0xFFFFFD06		/* CSIB0�����ǡ������쥸���� */
#define	CB0TXL		0xFFFFFD06		/* CSIB0�����ǡ������쥸����L */
#define	CB1CTL0		0xFFFFFD10		/* CSIB1����쥸����0 */
#define	CB1CTL1		0xFFFFFD11		/* CSIB1����쥸����1 */
#define	CB1CTL2		0xFFFFFD12		/* CSIB1����쥸����2 */
#define	CB1STR		0xFFFFFD13		/* CSIB1���֥쥸���� */
#define	CB1RX		0xFFFFFD14		/* CSIB1�����ǡ������쥸���� */
#define	CB1RXL		0xFFFFFD14		/* CSIB1�����ǡ������쥸����L */
#define	CB1TX		0xFFFFFD16		/* CSIB1�����ǡ������쥸���� */
#define	CB1TXL		0xFFFFFD16		/* CSIB1�����ǡ������쥸����L */
#define	CB2CTL0		0xFFFFFD20		/* CSIB2����쥸����0 */
#define	CB2CTL1		0xFFFFFD21		/* CSIB2����쥸����1 */
#define	CB2CTL2		0xFFFFFD22		/* CSIB2����쥸����2 */
#define	CB2STR		0xFFFFFD23		/* CSIB2���֥쥸���� */
#define	CB2RX		0xFFFFFD24		/* CSIB2�����ǡ������쥸���� */
#define	CB2RXL		0xFFFFFD24		/* CSIB2�����ǡ������쥸����L */
#define	CB2TX		0xFFFFFD26		/* CSIB2�����ǡ������쥸���� */
#define	CB2TXL		0xFFFFFD26		/* CSIB2�����ǡ������쥸����L */
#define	CB3CTL0		0xFFFFFD30		/* CSIB3����쥸����0 */
#define	CB3CTL1		0xFFFFFD31		/* CSIB3����쥸����1 */
#define	CB3CTL2		0xFFFFFD32		/* CSIB3����쥸����2 */
#define	CB3STR		0xFFFFFD33		/* CSIB3���֥쥸���� */
#define	CB3RX		0xFFFFFD34		/* CSIB3�����ǡ������쥸���� */
#define	CB3RXL		0xFFFFFD34		/* CSIB3�����ǡ������쥸����L */
#define	CB3TX		0xFFFFFD36		/* CSIB3�����ǡ������쥸���� */
#define	CB3TXL		0xFFFFFD36		/* CSIB3�����ǡ������쥸����L */
#define	CB4CTL0		0xFFFFFD40		/* CSIB4����쥸����0 */
#define	CB4CTL1		0xFFFFFD41		/* CSIB4����쥸����1 */
#define	CB4CTL2		0xFFFFFD42		/* CSIB4����쥸����2 */
#define	CB4STR		0xFFFFFD43		/* CSIB4���֥쥸���� */
#define	CB4RX		0xFFFFFD44		/* CSIB4�����ǡ������쥸���� */
#define	CB4RXL		0xFFFFFD44		/* CSIB4�����ǡ������쥸����L */
#define	CB4TX		0xFFFFFD46		/* CSIB4�����ǡ������쥸���� */
#define	CB4TXL		0xFFFFFD46		/* CSIB4�����ǡ������쥸����L */
#define	IIC0		0xFFFFFD80		/* IIC���եȡ��쥸����0 */
#define	IICC0		0xFFFFFD82		/* IIC����ȥ��롦�쥸����0 */
#define	SVA0		0xFFFFFD83		/* ���졼�֡����ɥ쥹���쥸����0 */
#define	IICCL0		0xFFFFFD84		/* IIC����å�����쥸����0 */
#define	IICX0		0xFFFFFD85		/* IIC��ǽ��ĥ�쥸����0 */
#define	IICS0		0xFFFFFD86		/* IIC���֥쥸����0 */
#define	IICF0		0xFFFFFD8A		/* IIC�ե饰���쥸����0 */
#define	IIC1		0xFFFFFD90		/* IIC���եȡ��쥸����1 */
#define	IICC1		0xFFFFFD92		/* IIC����ȥ��롦�쥸����1 */
#define	SVA1		0xFFFFFD93		/* IIC���졼�֡����ɥ쥹���쥸����1 */
#define	IICCL1		0xFFFFFD94		/* IIC����å�����쥸����1 */
#define	IICX1		0xFFFFFD95		/* IIC��ǽ��ĥ�쥸����1 */
#define	IICS1		0xFFFFFD96		/* IIC���֥쥸����1 */
#define	IICF1		0xFFFFFD9A		/* IIC�ե饰���쥸����1 */
#define	IIC2		0xFFFFFDA0		/* IIC���եȡ��쥸����2 */
#define	IICC2		0xFFFFFDA2		/* IIC����ȥ��롦�쥸����2 */
#define	SVA2		0xFFFFFDA3		/* IIC���졼�֡����ɥ쥹���쥸����2 */
#define	IICCL2		0xFFFFFDA4		/* IIC����å�����쥸����2 */
#define	IICX2		0xFFFFFDA5		/* IIC��ǽ��ĥ�쥸����2 */
#define	IICS2		0xFFFFFDA6		/* IIC���֥쥸����2 */
#define	IICF2		0xFFFFFDAA		/* IIC�ե饰���쥸����2 */
#define	EXIMC		0xFFFFFFBE		/* �����Х������󥿥ե��������⡼�ɡ�����ȥ��롦�쥸���� */

#endif	/* _V850ES_SG2_H_ */
