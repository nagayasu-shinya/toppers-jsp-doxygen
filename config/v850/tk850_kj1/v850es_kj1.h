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
 *  @(#) $Id: v850es_kj1.h,v 1.9 2007/03/23 08:20:08 honda Exp $
 */

#ifndef	_V850ES_KJ1_H_
#define	_V850ES_KJ1_H_
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
#define	IRAM_TOP	0x03FFB000		/* ��¢RAM����Ƭ���ɥ쥹 */
#define IRAM_SIZE	0x4000			/* ��¢RAM���礭�� 16Kbyte(uPD70F3318Y) */
/*
 * ��¢FlashROM
 */
#define	IROM_TOP	0x0000000		/* ��¢FlashROM����Ƭ���ɥ쥹 */
#define IROM_SIZE	0x40000			/* ��¢FlashROM���礭�� 256Kbyte(uPD70F3318Y) */

/* 
 * V850ES/KJ1��IO�쥸�������
 */
#define	PDL			0xFFFFF004		/* �ݡ���DL�쥸����(0x0000) */
#define	PDLL		0xFFFFF004		/* �ݡ���DL�쥸����L(0x00) */
#define	PDLH		0xFFFFF005		/* �ݡ���DL�쥸����(0x00) */
#define	PDH			0xFFFFF006		/* �ݡ���DH�쥸����(0x00) */
#define	PCS			0xFFFFF008		/* �ݡ���CS�쥸����(0x00) */
#define	PCT			0xFFFFF00A		/* �ݡ���CT�쥸����(0x00) */
#define	PCM			0xFFFFF00C		/* �ݡ���CM�쥸����(0x00) */
#define	PCD			0xFFFFF00E		/* �ݡ���CD�쥸����(0x00) */
#define	PMDL		0xFFFFF024		/* �ݡ���DL�⡼�ɡ��쥸����(0xFFFF) */
#define	PMDLL		0xFFFFF024		/* �ݡ���DL�⡼�ɡ��쥸����(0xFF) */
#define	PMDLH		0xFFFFF025		/* �ݡ���DL�⡼�ɡ��쥸����(0xFF) */
#define	PMDH		0xFFFFF026		/* �ݡ���DH�⡼�ɡ��쥸����(0xFF) */
#define	PMCS		0xFFFFF028		/* �ݡ���CS�⡼�ɡ��쥸����(0xFF) */
#define	PMCT		0xFFFFF02A		/* �ݡ���CT�⡼�ɡ��쥸����(0xFF) */
#define	PMCM		0xFFFFF02C		/* �ݡ���CM�⡼�ɡ��쥸����(0xFF) */
#define	PMCD		0xFFFFF02E		/* �ݡ���CD�⡼�ɡ��쥸����(0xFF) */
#define	PMCDL		0xFFFFF044		/* �ݡ���DL�⡼�ɡ�����ȥ��롦�쥸����(0x0000) */
#define	PMCDLL		0xFFFFF044		/* �ݡ���DL�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMCDLH		0xFFFFF045		/* �ݡ���DL�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMCDH		0xFFFFF046		/* �ݡ���DH�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMCCS		0xFFFFF048		/* �ݡ���CS�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMCCT		0xFFFFF04A		/* �ݡ���CT�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMCCM		0xFFFFF04C		/* �ݡ���CM�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	BSC			0xFFFFF066		/* �Х���������������ե�����졼����󡦥쥸����(0x5555) */
#define	VSWC		0xFFFFF06E		/* �����ƥࡦ�������ȡ�����ȥ��롦�쥸����(0x77) */
#define	IMR0		0xFFFFF100		/* �����ߥޥ����쥸����(0xFFFF) */
#define	IMR0L		0xFFFFF100		/* �����ߥޥ������쥸����0(0xFF) */
#define	IMR0H		0xFFFFF101		/* �����ߥޥ������쥸����0(0xFF) */
#define	IMR1		0xFFFFF102		/* �����ߥޥ������쥸����(0xFFFF) */
#define	IMR1L		0xFFFFF102		/* �����ߥޥ������쥸����1(0xFF) */
#define	IMR1H		0xFFFFF103		/* �����ߥޥ������쥸����1(0xFF) */
#define	IMR2		0xFFFFF104		/* �����ߥޥ������쥸����(0xFFFF) */
#define	IMR2L		0xFFFFF104		/* �����ߥޥ������쥸����2(0xFF) */
#define	IMR2H		0xFFFFF105		/* �����ߥޥ������쥸����2(0xFF) */
#define	IMR3		0xFFFFF106		/* �����ߥޥ������쥸����(0xFFFF) */
#define	IMR3L		0xFFFFF106		/* �����ߥޥ������쥸����3(0xFF) */
#define	WDT1IC		0xFFFFF110		/* ����������쥸����(0x47) */
#define	PIC0		0xFFFFF112		/* ����������쥸����(0x47) */
#define	PIC1		0xFFFFF114		/* ����������쥸����(0x47) */
#define	PIC2		0xFFFFF116		/* ����������쥸����(0x47) */
#define	PIC3		0xFFFFF118		/* ����������쥸����(0x47) */
#define	PIC4		0xFFFFF11A		/* ����������쥸����(0x47) */
#define	PIC5		0xFFFFF11C		/* ����������쥸����(0x47) */
#define	PIC6		0xFFFFF11E		/* ����������쥸����(0x47) */
#define	TM0IC00		0xFFFFF120		/* ����������쥸����(0x47) */
#define	TM0IC01		0xFFFFF122		/* ����������쥸����(0x47) */
#define	TM0IC10		0xFFFFF124		/* ����������쥸����(0x47) */
#define	TM0IC11		0xFFFFF126		/* ����������쥸����(0x47) */
#define	TM5IC0		0xFFFFF128		/* ����������쥸����(0x47) */
#define	TM5IC1		0xFFFFF12A		/* ����������쥸����(0x47) */
#define	CSI0IC0		0xFFFFF12C		/* ����������쥸����(0x47) */
#define	CSI0IC1		0xFFFFF12E		/* ����������쥸����(0x47) */
#define	SREIC0		0xFFFFF130		/* ����������쥸����(0x47) */
#define	SRIC0		0xFFFFF132		/* ����������쥸����(0x47) */
#define	STIC0		0xFFFFF134		/* ����������쥸����(0x47) */
#define	SREIC1		0xFFFFF136		/* ����������쥸����(0x47) */
#define	SRIC1		0xFFFFF138		/* ����������쥸����(0x47) */
#define	STIC1		0xFFFFF13A		/* ����������쥸����(0x47) */
#define	TMHIC0		0xFFFFF13C		/* ����������쥸����(0x47) */
#define	TMHIC1		0xFFFFF13E		/* ����������쥸����(0x47) */
#define	CSIAIC0		0xFFFFF140		/* ����������쥸����(0x47) */
#define	IICIC0		0xFFFFF142		/* ����������쥸����(0x47) */
#define	ADIC		0xFFFFF144		/* ����������쥸����(0x47) */
#define	KRIC		0xFFFFF146		/* ����������쥸����(0x47) */
#define	WTIIC		0xFFFFF148		/* ����������쥸����(0x47) */
#define	WTIC		0xFFFFF14A		/* ����������쥸����(0x47) */
#define	BRGIC		0xFFFFF14C		/* ����������쥸����(0x47) */
#define	TM0IC20		0xFFFFF14E		/* ����������쥸����(0x47) */
#define	TM0IC21		0xFFFFF150		/* ����������쥸����(0x47) */
#define	TM0IC30		0xFFFFF152		/* ����������쥸����(0x47) */
#define	TM0IC31		0xFFFFF154		/* ����������쥸����(0x47) */
#define	CSIAIC1		0xFFFFF156		/* ����������쥸����(0x47) */
#define	TM0IC40		0xFFFFF158		/* ����������쥸����(0x47) */
#define	TM0IC41		0xFFFFF15A		/* ����������쥸����(0x47) */
#define	TM0IC50		0xFFFFF15C		/* ����������쥸����(0x47) */
#define	TM0IC51		0xFFFFF15E		/* ����������쥸����(0x47) */
#define	CSI0IC2		0xFFFFF160		/* ����������쥸����(0x47) */
#define	SREIC2		0xFFFFF162		/* ����������쥸����(0x47) */
#define	SRIC2		0xFFFFF164		/* ����������쥸����(0x47) */
#define	STIC2		0xFFFFF166		/* ����������쥸����(0x47) */
#define	IICIC1		0xFFFFF168		/* ����������쥸����(0x47) */
#define	TP0OVIC		0xFFFFF174		/* ����������쥸����(0x47) */
#define	TP0CCIC0	0xFFFFF176		/* ����������쥸����(0x47) */
#define	TP0CCIC1	0xFFFFF178		/* ����������쥸����(0x47) */
#define	ISPR		0xFFFFF1FA		/* ���󥵡��ӥ����ץ饤����ƥ����쥸����(0x00) */
#define	PRCMD		0xFFFFF1FC		/* ���ޥ�ɡ��쥸����(����) */
#define	PSC			0xFFFFF1FE		/* �ѥ�������֡�����ȥ��롦�쥸����(0x00) */
#define	ADM			0xFFFFF200		/* A/D����С������⡼�ɡ��쥸����(0x00) */
#define	ADS			0xFFFFF201		/* ���ʥ����ϥ���ͥ����쥸����(0x00) */
#define	PFM			0xFFFFF202		/* �ѥ���ե�������ӥ⡼�ɡ��쥸����(0x00) */
#define	PFT			0xFFFFF203		/* �ѥ���ե�������Ӥ������ͥ쥸����(0x00) */
#define	ADCR		0xFFFFF204		/* A/D�Ѵ���̥쥸����(����) */
#define	ADCRH		0xFFFFF205		/* A/D�Ѵ���̥쥸����(����) */
#define	DACS0		0xFFFFF280		/* D/A�Ѵ�������쥸����(0x00) */
#define	DACS1		0xFFFFF282		/* D/A�Ѵ�������쥸����(0x00) */
#define	DAM			0xFFFFF284		/* D/A����С������⡼�ɡ��쥸����(0x00) */
#define	KRM			0xFFFFF300		/* �������꥿���󡦥⡼�ɡ��쥸����(0x00) */
#define	P0			0xFFFFF400		/* �ݡ���0�쥸����(0x00) */
#define	P1			0xFFFFF402		/* �ݡ���1�쥸����(0x00) */
#define	P3			0xFFFFF406		/* �ݡ���3�쥸����(0x0000) */
#define	P3L			0xFFFFF406		/* �ݡ���3�쥸����(0x00) */
#define	P3H			0xFFFFF407		/* �ݡ���3�쥸����(0x00) */
#define	P4			0xFFFFF408		/* �ݡ���4�쥸����(0x00) */
#define	P5			0xFFFFF40A		/* �ݡ���5�쥸����(0x00) */
#define	P6			0xFFFFF40C		/* �ݡ���6�쥸����(0x0000) */
#define	P6L			0xFFFFF40C		/* �ݡ���6�쥸����(0x00) */
#define	P6H			0xFFFFF40D		/* �ݡ���6�쥸����(0x00) */
#define	P7			0xFFFFF40E		/* �ݡ���7�쥸����(����) */
#define	P7L			0xFFFFF40E		/* �ݡ���7�쥸����(����) */
#define	P7H			0xFFFFF40F		/* �ݡ���7�쥸����(����) */
#define	P8			0xFFFFF410		/* �ݡ���8�쥸����(0x00) */
#define	P9			0xFFFFF412		/* �ݡ���9�쥸����(0x0000) */
#define	P9L			0xFFFFF412		/* �ݡ���9�쥸����(0x00) */
#define	P9H			0xFFFFF413		/* �ݡ���9�쥸����(0x00) */
#define	PM0			0xFFFFF420		/* �ݡ���0�⡼�ɡ��쥸����(0xFF) */
#define	PM1			0xFFFFF422		/* �ݡ���1�⡼�ɡ��쥸����(0xFF) */
#define	PM3			0xFFFFF426		/* �ݡ���3�⡼�ɡ��쥸����(0xFFFF) */
#define	PM3L		0xFFFFF426		/* �ݡ���3�⡼�ɡ��쥸����(0xFF) */
#define	PM3H		0xFFFFF427		/* �ݡ���3�⡼�ɡ��쥸����(0xFF) */
#define	PM4			0xFFFFF428		/* �ݡ���4�⡼�ɡ��쥸����(0xFF) */
#define	PM5			0xFFFFF42A		/* �ݡ���5�⡼�ɡ��쥸����(0xFF) */
#define	PM6			0xFFFFF42C		/* �ݡ���6�⡼�ɡ��쥸����(0xFFFF) */
#define	PM6L		0xFFFFF42C		/* �ݡ���6�⡼�ɡ��쥸����(0xFF) */
#define	PM6H		0xFFFFF42D		/* �ݡ���6�⡼�ɡ��쥸����(0xFF) */
#define	PM8			0xFFFFF430		/* �ݡ���8�⡼�ɡ��쥸����(0xFF) */
#define	PM9			0xFFFFF432		/* �ݡ���9�⡼�ɡ��쥸����(0xFFFF) */
#define	PM9L		0xFFFFF432		/* �ݡ���9�⡼�ɡ��쥸����(0xFF) */
#define	PM9H		0xFFFFF433		/* �ݡ���9�⡼�ɡ��쥸����(0xFF) */
#define	PMC0		0xFFFFF440		/* �ݡ���0�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMC3		0xFFFFF446		/* �ݡ���3�⡼�ɡ�����ȥ��롦�쥸����(0x0000) */
#define	PMC3L		0xFFFFF446		/* �ݡ���3�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMC3H		0xFFFFF447		/* �ݡ���3�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMC4		0xFFFFF448		/* �ݡ���4�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMC5		0xFFFFF44A		/* �ݡ���5�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMC6		0xFFFFF44C		/* �ݡ���6�⡼�ɡ�����ȥ��롦�쥸����(0x0000) */
#define	PMC6L		0xFFFFF44C		/* �ݡ���6�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMC6H		0xFFFFF44D		/* �ݡ���6�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMC8		0xFFFFF450		/* �ݡ���8�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMC9		0xFFFFF452		/* �ݡ���9�⡼�ɡ�����ȥ��롦�쥸����(0x0000) */
#define	PMC9L		0xFFFFF452		/* �ݡ���9�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PMC9H		0xFFFFF453		/* �ݡ���9�⡼�ɡ�����ȥ��롦�쥸����(0x00) */
#define	PFC3		0xFFFFF466		/* �ݡ���3�ե��󥯥���󡦥���ȥ��롦�쥸����(0x00) */
#define	PFC5		0xFFFFF46A		/* �ݡ���5�ե��󥯥���󡦥���ȥ��롦�쥸����(0x00) */
#define	PFC6H		0xFFFFF46D		/* �ݡ���6�ե��󥯥���󡦥���ȥ��롦�쥸����(0x00) */
#define	PFC8		0xFFFFF470		/* �ݡ���8�ե��󥯥���󡦥���ȥ��롦�쥸����(0x00) */
#define	PFC9		0xFFFFF472		/* �ݡ���9�ե��󥯥���󡦥���ȥ��롦�쥸����(0x0000) */
#define	PFC9L		0xFFFFF472		/* �ݡ���9�ե��󥯥���󡦥���ȥ��롦�쥸����(0x00) */
#define	PFC9H		0xFFFFF473		/* �ݡ���9�ե��󥯥���󡦥���ȥ��롦�쥸����(0x00) */
#define	DWC0		0xFFFFF484		/* �ǡ�����������������쥸����(0x7777) */
#define	AWC			0xFFFFF488		/* ���ɥ쥹��������������쥸����(0xFFFF) */
#define	BCC			0xFFFFF48A		/* �Х���������������쥸����(0xAAAA) */
#define	TMHMD0		0xFFFFF580		/* 8�ӥåȡ�������H�⡼�ɡ��쥸����(0x00) */
#define	TMCYC0		0xFFFFF581		/* 8�ӥåȡ�������H����ꥢ������ȥ��롦�쥸����(0x00) */
#define	CMP00		0xFFFFF582		/* 8�ӥåȡ�������H����ڥ����쥸����0(0x00) */
#define	CMP01		0xFFFFF583		/* 8�ӥåȡ�������H����ڥ����쥸����0(0x00) */
#define	TMHMD1		0xFFFFF590		/* 8�ӥåȡ�������H�⡼�ɡ��쥸����(0x00) */
#define	TMCYC1		0xFFFFF591		/* 8�ӥåȡ�������H����ꥢ������ȥ��롦�쥸����(0x00) */
#define	CMP10		0xFFFFF592		/* 8�ӥåȡ�������H����ڥ����쥸����1(0x00) */
#define	CMP11		0xFFFFF593		/* 8�ӥåȡ�������H����ڥ����쥸����1(0x00) */
#define	TP0CTL0		0xFFFFF5A0		/* TMP0����쥸����(0x00) */
#define	TP0CTL1		0xFFFFF5A1		/* TMP0����쥸����(0x00) */
#define	TP0IOC0		0xFFFFF5A2		/* TMP0I/O����쥸����(0x00) */
#define	TP0IOC1		0xFFFFF5A3		/* TMP0I/O����쥸����(0x00) */
#define	TP0IOC2		0xFFFFF5A4		/* TMP0I/O����쥸����(0x00) */
#define	TP0OPT0		0xFFFFF5A5		/* TMP0���ץ���󡦥쥸����(0x00) */
#define	TP0CCR0		0xFFFFF5A6		/* TMP0����ץ��㡿����ڥ����쥸����(0x0000) */
#define	TP0CCR1		0xFFFFF5A8		/* TMP0����ץ��㡿����ڥ����쥸����(0x0000) */
#define	TP0CNT		0xFFFFF5AA		/* TMP0�����󥿡��꡼�ɡ��Хåե����쥸����(0x0000) */
#define	TM5			0xFFFFF5C0		/* 16�ӥåȡ������ޡ�������(0x0000) */
#define	TM50		0xFFFFF5C0		/* 8�ӥåȡ������ޡ�������5(0x00) */
#define	TM51		0xFFFFF5C1		/* 8�ӥåȡ������ޡ�������5(0x00) */
#define	CR5			0xFFFFF5C2		/* 16�ӥåȡ������ޡ�����ڥ����쥸����(0x0000) */
#define	CR50		0xFFFFF5C2		/* 8�ӥåȡ������ޡ�����ڥ����쥸����5(0x00) */
#define	CR51		0xFFFFF5C3		/* 8�ӥåȡ������ޡ�����ڥ����쥸����5(0x00) */
#define	TCL5		0xFFFFF5C4		/* �����ޡ�����å�����쥸����(0x0000) */
#define	TCL50		0xFFFFF5C4		/* �����ޡ�����å�����쥸����5(0x00) */
#define	TCL51		0xFFFFF5C5		/* �����ޡ�����å�����쥸����5(0x00) */
#define	TMC5		0xFFFFF5C6		/* 16�ӥåȡ������ޡ��⡼�ɡ�����ȥ��롦�쥸����(0x0000) */
#define	TMC50		0xFFFFF5C6		/* 8�ӥåȡ������ޡ��⡼�ɡ�����ȥ��롦�쥸����5(0x00) */
#define	TMC51		0xFFFFF5C7		/* 8�ӥåȡ������ޡ��⡼�ɡ�����ȥ��롦�쥸����5(0x00) */
#define	TM00		0xFFFFF600		/* 16�ӥåȡ������ޡ�������0(0x0000) */
#define	CR000		0xFFFFF602		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����00(0x0000) */
#define	CR001		0xFFFFF604		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����00(0x0000) */
#define	TMC00		0xFFFFF606		/* 16�ӥåȡ������ޡ��⡼�ɡ�����ȥ��롦�쥸����0(0x00) */
#define	PRM00		0xFFFFF607		/* �ץꥹ�����顦�⡼�ɡ��쥸����0(0x00) */
#define	CRC00		0xFFFFF608		/* ����ץ��㡿����ڥ�������ȥ��롦�쥸����0(0x00) */
#define	TOC00		0xFFFFF609		/* 16�ӥåȡ������޽��ϥ���ȥ��롦�쥸����0(0x00) */
#define	TM01		0xFFFFF610		/* 16�ӥåȡ������ޡ�������0(0x0000) */
#define	CR010		0xFFFFF612		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����01(0x0000) */
#define	CR011		0xFFFFF614		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����01(0x0000) */
#define	TMC01		0xFFFFF616		/* 16�ӥåȡ������ޡ��⡼�ɡ�����ȥ��롦�쥸����0(0x00) */
#define	PRM01		0xFFFFF617		/* �ץꥹ�����顦�⡼�ɡ��쥸����0(0x00) */
#define	CRC01		0xFFFFF618		/* ����ץ��㡿����ڥ�������ȥ��롦�쥸����0(0x00) */
#define	TOC01		0xFFFFF619		/* 16�ӥåȡ������޽��ϥ���ȥ��롦�쥸����0(0x00) */
#define	TM02		0xFFFFF620		/* 16�ӥåȡ������ޡ�������0(0x0000) */
#define	CR020		0xFFFFF622		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����02(0x0000) */
#define	CR021		0xFFFFF624		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����02(0x0000) */
#define	TMC02		0xFFFFF626		/* 16�ӥåȡ������ޡ��⡼�ɡ�����ȥ��롦�쥸����0(0x00) */
#define	PRM02		0xFFFFF627		/* �ץꥹ�����顦�⡼�ɡ��쥸����0(0x00) */
#define	CRC02		0xFFFFF628		/* ����ץ��㡿����ڥ�������ȥ��롦�쥸����0(0x00) */
#define	TOC02		0xFFFFF629		/* 16�ӥåȡ������޽��ϥ���ȥ��롦�쥸����0(0x00) */
#define	TM03		0xFFFFF630		/* 16�ӥåȡ������ޡ�������0(0x0000) */
#define	CR030		0xFFFFF632		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����03(0x0000) */
#define	CR031		0xFFFFF634		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����03(0x0000) */
#define	TMC03		0xFFFFF636		/* 16�ӥåȡ������ޡ��⡼�ɡ�����ȥ��롦�쥸����0(0x00) */
#define	PRM03		0xFFFFF637		/* �ץꥹ�����顦�⡼�ɡ��쥸����0(0x00) */
#define	CRC03		0xFFFFF638		/* ����ץ��㡿����ڥ�������ȥ��롦�쥸����0(0x00) */
#define	TOC03		0xFFFFF639		/* 16�ӥåȡ������޽��ϥ���ȥ��롦�쥸����0(0x00) */
#define	TM04		0xFFFFF640		/* 16�ӥåȡ������ޡ�������0(0x0000) */
#define	CR040		0xFFFFF642		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����04(0x0000) */
#define	CR041		0xFFFFF644		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����04(0x0000) */
#define	TMC04		0xFFFFF646		/* 16�ӥåȡ������ޡ��⡼�ɡ�����ȥ��롦�쥸����0(0x00) */
#define	PRM04		0xFFFFF647		/* �ץꥹ�����顦�⡼�ɡ��쥸����0(0x00) */
#define	CRC04		0xFFFFF648		/* ����ץ��㡿����ڥ�������ȥ��롦�쥸����0(0x00) */
#define	TOC04		0xFFFFF649		/* 16�ӥåȡ������޽��ϥ���ȥ��롦�쥸����0(0x00) */
#define	TM05		0xFFFFF650		/* 16�ӥåȡ������ޡ�������0(0x0000) */
#define	CR050		0xFFFFF652		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����05(0x0000) */
#define	CR051		0xFFFFF654		/* 16�ӥåȡ������ޡ�����ץ��㡿����ڥ����쥸����05(0x0000) */
#define	TMC05		0xFFFFF656		/* 16�ӥåȡ������ޡ��⡼�ɡ�����ȥ��롦�쥸����0(0x00) */
#define	PRM05		0xFFFFF657		/* �ץꥹ�����顦�⡼�ɡ��쥸����0(0x00) */
#define	CRC05		0xFFFFF658		/* ����ץ��㡿����ڥ�������ȥ��롦�쥸����0(0x00) */
#define	TOC05		0xFFFFF659		/* 16�ӥåȡ������޽��ϥ���ȥ��롦�쥸����0(0x00) */
#define	WTM			0xFFFFF680		/* ���ץ�����ư��⡼�ɡ��쥸����(0x00) */
#define	OSTS		0xFFFFF6C0		/* ȯ�������������쥸����(0x01) */
#define	WDCS		0xFFFFF6C1		/* �����å��ɥå��������ޡ�����å�����쥸����(0x00) */
#define	WDTM1		0xFFFFF6C2		/* �����å��ɥå��������ޡ��⡼�ɡ��쥸����(0x00) */
#define	WDTM2		0xFFFFF6D0		/* �����å��ɥå��������ޡ��⡼�ɡ��쥸����(0x67) */
#define	WDTE		0xFFFFF6D1		/* �����å��ɥå��������ޡ����͡��֥롦�쥸����(0x9A) */
#define	RTBL0		0xFFFFF6E0		/* �ꥢ�륿������ϥХåե����쥸����L(0x00) */
#define	RTBH0		0xFFFFF6E2		/* �ꥢ�륿������ϥХåե����쥸����H(0x00) */
#define	RTPM0		0xFFFFF6E4		/* �ꥢ�륿������ϥݡ��ȡ��⡼�ɡ��쥸����(0x00) */
#define	RTPC0		0xFFFFF6E5		/* �ꥢ�륿������ϥݡ��ȡ�����ȥ��롦�쥸����(0x00) */
#define	RTBL1		0xFFFFF6F0		/* �ꥢ�륿������ϥХåե����쥸����L(0x00) */
#define	RTBH1		0xFFFFF6F2		/* �ꥢ�륿������ϥХåե����쥸����H(0x00) */
#define	RTPM1		0xFFFFF6F4		/* �ꥢ�륿������ϥݡ��ȡ��⡼�ɡ��쥸����(0x00) */
#define	RTPC1		0xFFFFF6F5		/* �ꥢ�륿������ϥݡ��ȡ�����ȥ��롦�쥸����(0x00) */
#define	PFCE3		0xFFFFF706		/* �ݡ���3�ե��󥯥���󡦥���ȥ����ĥ�쥸����(0x00) */
#define	SYS			0xFFFFF802		/* �����ƥࡦ���ơ��������쥸����(0x00) */
#define	PLLCTL		0xFFFFF806		/* PLL����ȥ��롦�쥸����(0x01) */
#define	PSMR		0xFFFFF820		/* �ѥ�������֡��⡼�ɡ��쥸����(0x00) */
#define	PCC			0xFFFFF828		/* �ץ��å�������å�������ȥ��롦�쥸����(0x03) */
#define	CORAD0		0xFFFFF840		/* ���쥯����󡦥��ɥ쥹���쥸����(0x00000000) */
#define	CORAD0L		0xFFFFF840		/* ���쥯����󡦥��ɥ쥹���쥸����0(0x0000) */
#define	CORAD0H		0xFFFFF842		/* ���쥯����󡦥��ɥ쥹���쥸����0(0x0000) */
#define	CORAD1		0xFFFFF844		/* ���쥯����󡦥��ɥ쥹���쥸����(0x00000000) */
#define	CORAD1L		0xFFFFF844		/* ���쥯����󡦥��ɥ쥹���쥸����1(0x0000) */
#define	CORAD1H		0xFFFFF846		/* ���쥯����󡦥��ɥ쥹���쥸����1(0x0000) */
#define	CORAD2		0xFFFFF848		/* ���쥯����󡦥��ɥ쥹���쥸����(0x00000000) */
#define	CORAD2L		0xFFFFF848		/* ���쥯����󡦥��ɥ쥹���쥸����2(0x0000) */
#define	CORAD2H		0xFFFFF84A		/* ���쥯����󡦥��ɥ쥹���쥸����2(0x0000) */
#define	CORAD3		0xFFFFF84C		/* ���쥯����󡦥��ɥ쥹���쥸����(0x00000000) */
#define	CORAD3L		0xFFFFF84C		/* ���쥯����󡦥��ɥ쥹���쥸����3(0x0000) */
#define	CORAD3H		0xFFFFF84E		/* ���쥯����󡦥��ɥ쥹���쥸����3(0x0000) */
#define	CORCN		0xFFFFF880		/* ���쥯����󡦥���ȥ��롦�쥸����(0x00) */
#define	PRSM		0xFFFFF8B0		/* ���󥿡��Х롦������BRG�⡼�ɡ��쥸����(0x00) */
#define	PRSCM		0xFFFFF8B1		/* ���󥿡��Х롦������BRG����ڥ����쥸����(0x00) */
#define	OCDM		0xFFFFF9FC		/* ������åס��ǥ��Х����⡼�ɡ��쥸����(0x01) */
#define	ASIM0		0xFFFFFA00		/* �����󥯥�ʥ������ꥢ�롦���󥿥ե��������⡼�ɡ��쥸����(0x01) */
#define	RXB0		0xFFFFFA02		/* �����Хåե����쥸����(0xFF) */
#define	ASIS0		0xFFFFFA03		/* �����󥯥�ʥ������ꥢ�롦���󥿥ե����������ơ��������쥸����(0x00) */
#define	TXB0		0xFFFFFA04		/* �����Хåե����쥸����(0xFF) */
#define	ASIF0		0xFFFFFA05		/* �����󥯥�ʥ������ꥢ�롦���󥿥ե������������ơ��������쥸����(0x00) */
#define	CKSR0		0xFFFFFA06		/* ����å�����쥸����(0x00) */
#define	BRGC0		0xFFFFFA07		/* �ܡ����졼�ȡ������ͥ졼��������ȥ��롦�쥸����(0xFF) */
#define	ASIM1		0xFFFFFA10		/* �����󥯥�ʥ������ꥢ�롦���󥿥ե��������⡼�ɡ��쥸����(0x01) */
#define	RXB1		0xFFFFFA12		/* �����Хåե����쥸����(0xFF) */
#define	ASIS1		0xFFFFFA13		/* �����󥯥�ʥ������ꥢ�롦���󥿥ե����������ơ��������쥸����(0x00) */
#define	TXB1		0xFFFFFA14		/* �����Хåե����쥸����(0xFF) */
#define	ASIF1		0xFFFFFA15		/* �����󥯥�ʥ������ꥢ�롦���󥿥ե������������ơ��������쥸����(0x00) */
#define	CKSR1		0xFFFFFA16		/* ����å�����쥸����(0x00) */
#define	BRGC1		0xFFFFFA17		/* �ܡ����졼�ȡ������ͥ졼��������ȥ��롦�쥸����(0xFF) */
#define	ASIM2		0xFFFFFA20		/* �����󥯥�ʥ������ꥢ�롦���󥿥ե��������⡼�ɡ��쥸����(0x01) */
#define	RXB2		0xFFFFFA22		/* �����Хåե����쥸����(0xFF) */
#define	ASIS2		0xFFFFFA23		/* �����󥯥�ʥ������ꥢ�롦���󥿥ե����������ơ��������쥸����(0x00) */
#define	TXB2		0xFFFFFA24		/* �����Хåե����쥸����(0xFF) */
#define	ASIF2		0xFFFFFA25		/* �����󥯥�ʥ������ꥢ�롦���󥿥ե������������ơ��������쥸����(0x00) */
#define	CKSR2		0xFFFFFA26		/* ����å�����쥸����(0x00) */
#define	BRGC2		0xFFFFFA27		/* �ܡ����졼�ȡ������ͥ졼��������ȥ��롦�쥸����(0xFF) */
#define	P0NFC		0xFFFFFB00		/* TIP00�Υ�����������쥸����(0x00) */
#define	P1NFC		0xFFFFFB04		/* TIP01�Υ�����������쥸����(0x00) */
#define	INTF0		0xFFFFFC00		/* ����������Ω�������ꥨ�å�����쥸����(0x00) */
#define	INTF9H		0xFFFFFC13		/* ����������Ω�������ꥨ�å�����쥸����9(0x00) */
#define	INTR0		0xFFFFFC20		/* ����������Ω���夬�ꥨ�å�����쥸����(0x00) */
#define	INTR9H		0xFFFFFC33		/* ����������Ω���夬�ꥨ�å�����쥸����9(0x00) */
#define	PU0			0xFFFFFC40		/* �ץ륢�å��񹳥��ץ���󡦥쥸����(0x00) */
#define	PU1			0xFFFFFC42		/* �ץ륢�å��񹳥��ץ���󡦥쥸����(0x00) */
#define	PU3			0xFFFFFC46		/* �ץ륢�å��񹳥��ץ���󡦥쥸����(0x00) */
#define	PU4			0xFFFFFC48		/* �ץ륢�å��񹳥��ץ���󡦥쥸����(0x00) */
#define	PU5			0xFFFFFC4A		/* �ץ륢�å��񹳥��ץ���󡦥쥸����(0x00) */
#define	PU6			0xFFFFFC4C		/* �ץ륢�å��񹳥��ץ���󡦥쥸����(0x0000) */
#define	PU6L		0xFFFFFC4C		/* �ץ륢�å��񹳥��ץ���󡦥쥸����6(0x00) */
#define	PU6H		0xFFFFFC4D		/* �ץ륢�å��񹳥��ץ���󡦥쥸����6(0x00) */
#define	PU8			0xFFFFFC50		/* �ץ륢�å��񹳥��ץ���󡦥쥸����(0x00) */
#define	PU9			0xFFFFFC52		/* �ץ륢�å��񹳥��ץ���󡦥쥸����(0x0000) */
#define	PU9L		0xFFFFFC52		/* �ץ륢�å��񹳥��ץ���󡦥쥸����9(0x00) */
#define	PU9H		0xFFFFFC53		/* �ץ륢�å��񹳥��ץ���󡦥쥸����9(0x00) */
#define	PF3H		0xFFFFFC67		/* �ݡ���3�ե��󥯥���󡦥쥸����(0x00) */
#define	PF4			0xFFFFFC68		/* �ݡ���4�ե��󥯥���󡦥쥸����(0x00) */
#define	PF5			0xFFFFFC6A		/* �ݡ���5�ե��󥯥���󡦥쥸����(0x00) */
#define	PF6			0xFFFFFC6C		/* �ݡ���6�ե��󥯥���󡦥쥸����(0x0000) */
#define	PF6L		0xFFFFFC6C		/* �ݡ���6�ե��󥯥���󡦥쥸����(0x00) */
#define	PF6H		0xFFFFFC6D		/* �ݡ���6�ե��󥯥���󡦥쥸����(0x00) */
#define	PF8			0xFFFFFC70		/* �ݡ���8�ե��󥯥���󡦥쥸����(0x00) */
#define	PF9H		0xFFFFFC73		/* �ݡ���9�ե��󥯥���󡦥쥸����(0x00) */
#define	CSIM00		0xFFFFFD00		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������⡼�ɡ��쥸����0(0x00) */
#define	CSIC0		0xFFFFFD01		/* ����å�Ʊ�������ꥢ�롦���󥿥ե�����������å�����쥸����(0x00) */
#define	SIRB0		0xFFFFFD02		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����(0x0000) */
#define	SIRB0L		0xFFFFFD02		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����0(0x00) */
#define	SOTB0		0xFFFFFD04		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����(0x0000) */
#define	SOTB0L		0xFFFFFD04		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����0(0x00) */
#define	SIRBE0		0xFFFFFD06		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������꡼�����Ѽ����Хåե����쥸����(0x0000) */
#define	SIRBE0L		0xFFFFFD06		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������꡼�����Ѽ����Хåե����쥸����0(0x00) */
#define	SOTBF0		0xFFFFFD08		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������������Хåե����쥸����(0x0000) */
#define	SOTBF0L		0xFFFFFD08		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������������Хåե����쥸����0(0x00) */
#define	SIO00		0xFFFFFD0A		/* ���ꥢ��I/O���եȡ��쥸����(0x00) */
#define	SIO00L		0xFFFFFD0A		/* ���ꥢ��I/O���եȡ��쥸����0(0x0000) */
#define	CSIM01		0xFFFFFD10		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������⡼�ɡ��쥸����0(0x00) */
#define	CSIC1		0xFFFFFD11		/* ����å�Ʊ�������ꥢ�롦���󥿥ե�����������å�����쥸����(0x00) */
#define	SIRB1		0xFFFFFD12		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����(0x0000) */
#define	SIRB1L		0xFFFFFD12		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����1(0x00) */
#define	SOTB1		0xFFFFFD14		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����(0x0000) */
#define	SOTB1L		0xFFFFFD14		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����1(0x00) */
#define	SIRBE1		0xFFFFFD16		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������꡼�����Ѽ����Хåե����쥸����(0x0000) */
#define	SIRBE1L		0xFFFFFD16		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������꡼�����Ѽ����Хåե����쥸����1(0x00) */
#define	SOTBF1		0xFFFFFD18		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������������Хåե����쥸����(0x0000) */
#define	SOTBF1L		0xFFFFFD18		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������������Хåե����쥸����1(0x00) */
#define	SIO01		0xFFFFFD1A		/* ���ꥢ��I/O���եȡ��쥸����(0x00) */
#define	SIO01L		0xFFFFFD1A		/* ���ꥢ��I/O���եȡ��쥸����1(0x0000) */
#define	CSIM02		0xFFFFFD20		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������⡼�ɡ��쥸����0(0x00) */
#define	CSIC2		0xFFFFFD21		/* ����å�Ʊ�������ꥢ�롦���󥿥ե�����������å�����쥸����(0x00) */
#define	SIRB2		0xFFFFFD22		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����(0x0000) */
#define	SIRB2L		0xFFFFFD22		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����2(0x00) */
#define	SOTB2		0xFFFFFD24		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����(0x0000) */
#define	SOTB2L		0xFFFFFD24		/* ����å�Ʊ�������ꥢ�롦���󥿥ե����������Хåե����쥸����2(0x00) */
#define	SIRBE2		0xFFFFFD26		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������꡼�����Ѽ����Хåե����쥸����(0x0000) */
#define	SIRBE2L		0xFFFFFD26		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������꡼�����Ѽ����Хåե����쥸����2(0x00) */
#define	SOTBF2		0xFFFFFD28		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������������Хåե����쥸����(0x0000) */
#define	SOTBF2L		0xFFFFFD28		/* ����å�Ʊ�������ꥢ�롦���󥿥ե��������������Хåե����쥸����2(0x00) */
#define	SIO02		0xFFFFFD2A		/* ���ꥢ��I/O���եȡ��쥸����(0x00) */
#define	SIO02L		0xFFFFFD2A		/* ���ꥢ��I/O���եȡ��쥸����2(0x0000) */
#define	CSIMA0		0xFFFFFD40		/* ���ꥢ��ư��⡼�ɻ���쥸����(0x00) */
#define	CSIS0		0xFFFFFD41		/* ���ꥢ�롦���ơ��������쥸����(0x00) */
#define	CSIT0		0xFFFFFD42		/* ���ꥢ�롦�ȥꥬ���쥸����(0x00) */
#define	BRGCA0		0xFFFFFD43		/* ʬ��������쥸����(0x03) */
#define	ADTP0		0xFFFFFD44		/* ��ư�ǡ���ž�����ɥ쥹���ݥ���Ȼ���쥸����(0x00) */
#define	ADTI0		0xFFFFFD45		/* ��ư�ǡ���ž���ֳֻ���쥸����(0x00) */
#define	SIOA0		0xFFFFFD46		/* ���ꥢ��I/O���եȡ��쥸����A(0x00) */
#define	ADTC0		0xFFFFFD47		/* ��ư�ǡ���ž�����ɥ쥹��������ȡ��쥸����(0x00) */
#define	CSIMA1		0xFFFFFD50		/* ���ꥢ��ư��⡼�ɻ���쥸����(0x00) */
#define	CSIS1		0xFFFFFD51		/* ���ꥢ�롦���ơ��������쥸����(0x00) */
#define	CSIT1		0xFFFFFD52		/* ���ꥢ�롦�ȥꥬ���쥸����(0x00) */
#define	BRGCA1		0xFFFFFD53		/* ʬ��������쥸����(0x03) */
#define	ADTP1		0xFFFFFD54		/* ��ư�ǡ���ž�����ɥ쥹���ݥ���Ȼ���쥸����(0x00) */
#define	ADTI1		0xFFFFFD55		/* ��ư�ǡ���ž���ֳֻ���쥸����(0x00) */
#define	SIOA1		0xFFFFFD56		/* ���ꥢ��I/O���եȡ��쥸����A(0x00) */
#define	ADTC1		0xFFFFFD57		/* ��ư�ǡ���ž�����ɥ쥹��������ȡ��쥸����(0x00) */
#define	IIC0		0xFFFFFD80		/* IIC���եȡ��쥸����(0x00) */
#define	IICC0		0xFFFFFD82		/* IIC����ȥ��롦�쥸����(0x00) */
#define	SVA0		0xFFFFFD83		/* ���졼�֡����ɥ쥹���쥸����(0x00) */
#define	IICCL0		0xFFFFFD84		/* IIC����å�����쥸����(0x00) */
#define	IICX0		0xFFFFFD85		/* IIC��ǽ��ĥ�쥸����(0x00) */
#define	IICS0		0xFFFFFD86		/* IIC���֥쥸����(0x00) */
#define	IICF0		0xFFFFFD8A		/* IIC�ե饰���쥸����(0x00) */
#define	IIC1		0xFFFFFD90		/* IIC���եȡ��쥸����(0x00) */
#define	IICC01		0xFFFFFD92		/* IIC����ȥ��롦�쥸����(0x00) */
#define	SVA01		0xFFFFFD93		/* ���졼�֡����ɥ쥹���쥸����(0x00) */
#define	IICCL01		0xFFFFFD94		/* IIC����å�����쥸����(0x00) */
#define	IICX1		0xFFFFFD95		/* IIC��ǽ��ĥ�쥸����(0x00) */
#define	IICS01		0xFFFFFD96		/* IIC���֥쥸����(0x00) */
#define	IICF1		0xFFFFFD9A		/* IIC�ե饰���쥸����(0x00) */
#define	CSIA0B0		0xFFFFFE00		/* CSIA0�Хåե�RAM0(����) */
#define	CSIA0B0L	0xFFFFFE00		/* CSIA0�Хåե�RAM0L(����) */
#define	CSIA0B0H	0xFFFFFE01		/* CSIA0�Хåե�RAM0H(����) */
#define	CSIA0B1		0xFFFFFE02		/* CSIA0�Хåե�RAM1(����) */
#define	CSIA0B1L	0xFFFFFE02		/* CSIA0�Хåե�RAM1L(����) */
#define	CSIA0B1H	0xFFFFFE03		/* CSIA0�Хåե�RAM1H(����) */
#define	CSIA0B2		0xFFFFFE04		/* CSIA0�Хåե�RAM2(����) */
#define	CSIA0B2L	0xFFFFFE04		/* CSIA0�Хåե�RAM2L(����) */
#define	CSIA0B2H	0xFFFFFE05		/* CSIA0�Хåե�RAM2H(����) */
#define	CSIA0B3		0xFFFFFE06		/* CSIA0�Хåե�RAM3(����) */
#define	CSIA0B3L	0xFFFFFE06		/* CSIA0�Хåե�RAM3L(����) */
#define	CSIA0B3H	0xFFFFFE07		/* CSIA0�Хåե�RAM3H(����) */
#define	CSIA0B4		0xFFFFFE08		/* CSIA0�Хåե�RAM4(����) */
#define	CSIA0B4L	0xFFFFFE08		/* CSIA0�Хåե�RAM4L(����) */
#define	CSIA0B4H	0xFFFFFE09		/* CSIA0�Хåե�RAM4H(����) */
#define	CSIA0B5		0xFFFFFE0A		/* CSIA0�Хåե�RAM5(����) */
#define	CSIA0B5L	0xFFFFFE0A		/* CSIA0�Хåե�RAM5L(����) */
#define	CSIA0B5H	0xFFFFFE0B		/* CSIA0�Хåե�RAM5H(����) */
#define	CSIA0B6		0xFFFFFE0C		/* CSIA0�Хåե�RAM6(����) */
#define	CSIA0B6L	0xFFFFFE0C		/* CSIA0�Хåե�RAM6L(����) */
#define	CSIA0B6H	0xFFFFFE0D		/* CSIA0�Хåե�RAM6H(����) */
#define	CSIA0B7		0xFFFFFE0E		/* CSIA0�Хåե�RAM7(����) */
#define	CSIA0B7L	0xFFFFFE0E		/* CSIA0�Хåե�RAM7L(����) */
#define	CSIA0B7H	0xFFFFFE0F		/* CSIA0�Хåե�RAM7H(����) */
#define	CSIA0B8		0xFFFFFE10		/* CSIA0�Хåե�RAM8(����) */
#define	CSIA0B8L	0xFFFFFE10		/* CSIA0�Хåե�RAM8L(����) */
#define	CSIA0B8H	0xFFFFFE11		/* CSIA0�Хåե�RAM8H(����) */
#define	CSIA0B9		0xFFFFFE12		/* CSIA0�Хåե�RAM9(����) */
#define	CSIA0B9L	0xFFFFFE12		/* CSIA0�Хåե�RAM9L(����) */
#define	CSIA0B9H	0xFFFFFE13		/* CSIA0�Хåե�RAM9H(����) */
#define	CSIA0BA		0xFFFFFE14		/* CSIA0�Хåե�RAMA(����) */
#define	CSIA0BAL	0xFFFFFE14		/* CSIA0�Хåե�RAMAL(����) */
#define	CSIA0BAH	0xFFFFFE15		/* CSIA0�Хåե�RAMAH(����) */
#define	CSIA0BB		0xFFFFFE16		/* CSIA0�Хåե�RAMB(����) */
#define	CSIA0BBL	0xFFFFFE16		/* CSIA0�Хåե�RAMBL(����) */
#define	CSIA0BBH	0xFFFFFE17		/* CSIA0�Хåե�RAMBH(����) */
#define	CSIA0BC		0xFFFFFE18		/* CSIA0�Хåե�RAMC(����) */
#define	CSIA0BCL	0xFFFFFE18		/* CSIA0�Хåե�RAMCL(����) */
#define	CSIA0BCH	0xFFFFFE19		/* CSIA0�Хåե�RAMCH(����) */
#define	CSIA0BD		0xFFFFFE1A		/* CSIA0�Хåե�RAMD(����) */
#define	CSIA0BDL	0xFFFFFE1A		/* CSIA0�Хåե�RAMDL(����) */
#define	CSIA0BDH	0xFFFFFE1B		/* CSIA0�Хåե�RAMDH(����) */
#define	CSIA0BE		0xFFFFFE1C		/* CSIA0�Хåե�RAME(����) */
#define	CSIA0BEL	0xFFFFFE1C		/* CSIA0�Хåե�RAMEL(����) */
#define	CSIA0BEH	0xFFFFFE1D		/* CSIA0�Хåե�RAMEH(����) */
#define	CSIA0BF		0xFFFFFE1E		/* CSIA0�Хåե�RAMF(����) */
#define	CSIA0BFL	0xFFFFFE1E		/* CSIA0�Хåե�RAMFL(����) */
#define	CSIA0BFH	0xFFFFFE1F		/* CSIA0�Хåե�RAMFH(����) */
#define	CSIA1B0		0xFFFFFE20		/* CSIA1�Хåե�RAM0(����) */
#define	CSIA1B0L	0xFFFFFE20		/* CSIA1�Хåե�RAM0L(����) */
#define	CSIA1B0H	0xFFFFFE21		/* CSIA1�Хåե�RAM0H(����) */
#define	CSIA1B1		0xFFFFFE22		/* CSIA1�Хåե�RAM1(����) */
#define	CSIA1B1L	0xFFFFFE22		/* CSIA1�Хåե�RAM1L(����) */
#define	CSIA1B1H	0xFFFFFE23		/* CSIA1�Хåե�RAM1H(����) */
#define	CSIA1B2		0xFFFFFE24		/* CSIA1�Хåե�RAM2(����) */
#define	CSIA1B2L	0xFFFFFE24		/* CSIA1�Хåե�RAM2L(����) */
#define	CSIA1B2H	0xFFFFFE25		/* CSIA1�Хåե�RAM2H(����) */
#define	CSIA1B3		0xFFFFFE26		/* CSIA1�Хåե�RAM3(����) */
#define	CSIA1B3L	0xFFFFFE26		/* CSIA1�Хåե�RAM3L(����) */
#define	CSIA1B3H	0xFFFFFE27		/* CSIA1�Хåե�RAM3H(����) */
#define	CSIA1B4		0xFFFFFE28		/* CSIA1�Хåե�RAM4(����) */
#define	CSIA1B4L	0xFFFFFE28		/* CSIA1�Хåե�RAM4L(����) */
#define	CSIA1B4H	0xFFFFFE29		/* CSIA1�Хåե�RAM4H(����) */
#define	CSIA1B5		0xFFFFFE2A		/* CSIA1�Хåե�RAM5(����) */
#define	CSIA1B5L	0xFFFFFE2A		/* CSIA1�Хåե�RAM5L(����) */
#define	CSIA1B5H	0xFFFFFE2B		/* CSIA1�Хåե�RAM5H(����) */
#define	CSIA1B6		0xFFFFFE2C		/* CSIA1�Хåե�RAM6(����) */
#define	CSIA1B6L	0xFFFFFE2C		/* CSIA1�Хåե�RAM6L(����) */
#define	CSIA1B6H	0xFFFFFE2D		/* CSIA1�Хåե�RAM6H(����) */
#define	CSIA1B7		0xFFFFFE2E		/* CSIA1�Хåե�RAM7(����) */
#define	CSIA1B7L	0xFFFFFE2E		/* CSIA1�Хåե�RAM7L(����) */
#define	CSIA1B7H	0xFFFFFE2F		/* CSIA1�Хåե�RAM7H(����) */
#define	CSIA1B8		0xFFFFFE30		/* CSIA1�Хåե�RAM8(����) */
#define	CSIA1B8L	0xFFFFFE30		/* CSIA1�Хåե�RAM8L(����) */
#define	CSIA1B8H	0xFFFFFE31		/* CSIA1�Хåե�RAM8H(����) */
#define	CSIA1B9		0xFFFFFE32		/* CSIA1�Хåե�RAM9(����) */
#define	CSIA1B9L	0xFFFFFE32		/* CSIA1�Хåե�RAM9L(����) */
#define	CSIA1B9H	0xFFFFFE33		/* CSIA1�Хåե�RAM9H(����) */
#define	CSIA1BA		0xFFFFFE34		/* CSIA1�Хåե�RAMA(����) */
#define	CSIA1BAL	0xFFFFFE34		/* CSIA1�Хåե�RAMAL(����) */
#define	CSIA1BAH	0xFFFFFE35		/* CSIA1�Хåե�RAMAH(����) */
#define	CSIA1BB		0xFFFFFE36		/* CSIA1�Хåե�RAMB(����) */
#define	CSIA1BBL	0xFFFFFE36		/* CSIA1�Хåե�RAMBL(����) */
#define	CSIA1BBH	0xFFFFFE37		/* CSIA1�Хåե�RAMBH(����) */
#define	CSIA1BC		0xFFFFFE38		/* CSIA1�Хåե�RAMC(����) */
#define	CSIA1BCL	0xFFFFFE38		/* CSIA1�Хåե�RAMCL(����) */
#define	CSIA1BCH	0xFFFFFE39		/* CSIA1�Хåե�RAMCH(����) */
#define	CSIA1BD		0xFFFFFE3A		/* CSIA1�Хåե�RAMD(����) */
#define	CSIA1BDL	0xFFFFFE3A		/* CSIA1�Хåե�RAMDL(����) */
#define	CSIA1BDH	0xFFFFFE3B		/* CSIA1�Хåե�RAMDH(����) */
#define	CSIA1BE		0xFFFFFE3C		/* CSIA1�Хåե�RAME(����) */
#define	CSIA1BEL	0xFFFFFE3C		/* CSIA1�Хåե�RAMEL(����) */
#define	CSIA1BEH	0xFFFFFE3D		/* CSIA1�Хåե�RAMEH(����) */
#define	CSIA1BF		0xFFFFFE3E		/* CSIA1�Хåե�RAMF(����) */
#define	CSIA1BFL	0xFFFFFE3E		/* CSIA1�Хåե�RAMFL(����) */
#define	CSIA1BFH	0xFFFFFE3F		/* CSIA1�Хåե�RAMFH(����) */
#define	EXIMC		0xFFFFFFBE		/* �����Х������󥿥ե��������⡼�ɡ�����ȥ��롦�쥸����(0x00) */

#endif	/* _V850ES_KJ1_H_ */
