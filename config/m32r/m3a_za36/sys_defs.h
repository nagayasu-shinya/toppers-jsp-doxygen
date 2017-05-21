/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: sys_defs.h,v 1.2 2007/05/28 02:03:55 honda Exp $
 */

/*
 *  �������åȥ����ƥ�˰�¸���������m3a_za36/10MHz��
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

#define m3a_za36

/*
 *  ����ޥåץɥ쥸����
 */

/* ����ߴ�Ϣ�Υ쥸���� */
#define ICUISTS		0xeff004
#define ICUIREQ0	0xeff008
#define ICUIREQ1	0xeff00c
#define ICUSBICR	0xeff018
#define ICUIMASK	0xeff01c

#define __ICUCR(x)	ICUCR_##x
#define _ICUCR(x)	__ICUCR(x)
#define ICUCR_INT	0xeff200
#define ICUCR_MFT	0xeff23c
#define ICUCR_SIO	0xeff2bc
#define ICUCR(x,y)	(_ICUCR(x) + (0x4*y))

/* �����޴�Ϣ�쥸���� */
#define MFTCR			0xefc000
#define MFTRPR			0xefc004
#define MFTMOD(x)		(0xefc100 + ((x) * 0x100))
#define MFTBOS(x)		(0xefc104 + ((x) * 0x100))
#define MFTCUT(x)		(0xefc108 + ((x) * 0x100))
#define MFTRLD(x)		(0xefc10c + ((x) * 0x100))
#define MFTMCMPRLD(x)	(0xefc110 + ((x) * 0x100))

/* ���ꥢ���Ϣ�쥸���� */
#define SIOCR(x)	(0xefd000 + ((x) * 0x100))
#define SIOMOD0(x)	(0xefd004 + ((x) * 0x100))
#define SIOMOD1(x)	(0xefd008 + ((x) * 0x100))
#define SIOSTS(x)	(0xefd00c + ((x) * 0x100))
#define SIOTRCR(x)	(0xefd010 + ((x) * 0x100))
#define SIOBAUR(x)	(0xefd014 + ((x) * 0x100))
#define SIORBAUR(x)	(0xefd018 + ((x) * 0x100))
#define SIOTXB(x)	(0xefd01c + ((x) * 0x100))
#define SIORXB(x)	(0xefd020 + ((x) * 0x100))

/* �ץ���ޥ֥�I/O�ݡ��ȴ�Ϣ�쥸���� */
#define PIEN		0xef1000
#define PDATA(x)	(0xef1020+(x))
#define PDIR(x)		(0xef1040+(x))
#define PMOD(x)		(0xef1060+((x)*2))
#define PODCR(x)	(0xef1080+((x)*2))

/* �����Х�����ȥ��� */
#define BSELCR(x)	(0xef5000 + ((x)*4))

/* SDRAM����ȥ��� */
#define SDRF0		0xef6000
#define SDRF1		0xef6004
#define SDIR0		0xef6008
#define SDIR1		0xef600c
#define SDBR		(0xef6010)
#define SDADR(x)	(0xef6020 + ((x)*32))
#define SDER(x)		(0xef6024 + ((x)*32))
#define SDTR(x)		(0xef6028 + ((x)*32))
#define SDMOD(x)	(0xef602c + ((x)*32))

/* CPUư��⡼�ɴ�Ϣ�Υ쥸���� */
#define CPUCLKCR	0xef4000
#define CLKMOD		0xef4004
#define PLLCR		0xef4008

#ifndef _MACRO_ONLY

/*
 *  INTNO���ȳ���ߤζػ�/����
 */
typedef	unsigned char INTNO;		/* ������ֹ� */

/*
 *  �������åȥ����ƥ��¸�Υ����ӥ�������
 */
typedef	unsigned long SYSUTIM;	/* ��ǽɾ���ѥ����ƥ���� */

Inline void kernel_abort(void)
{
    extern void _kernel_sys_exit(void);
    _kernel_sys_exit();
}

extern ER	vxget_tim(SYSUTIM *pk_sysutim);

#endif /* _MACRO_ONLY */

/*
 *  ������ƥ��å������
 */
#define	TIC_NUME	1		/* ������ƥ��å��μ�����ʬ�� */
#define	TIC_DENO	1		/* ������ƥ��å��μ�����ʬ�� */

#endif /* _SYS_DEFS_H_ */
