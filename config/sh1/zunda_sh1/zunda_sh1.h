/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2003-2004 by CHUO ELECTRIC WORKS Co.,LTD. JAPAN
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
 */
/*
 *  (��)������������ITRON���SH1CPU�ܡ�����
 *  �ϡ��ɥ������񸻤����
 */

#ifndef _ZUNDA_SH1_H_
#define _ZUNDA_SH1_H_

/* �ӣãɥ���ͥ룰 */
#if 0 /* sh1sci2.c���������Ƥ��� */
#define SCI_SMR0	((VH *)0x5fffec0)	/* ���ꥢ�뎥�⡼�Ɏ��쥸���� */
#define SCI_BRR0	((VH *)0x5fffec1)	/* �ӥåȥ졼�Ȏ��쥸���� */
#define SCI_SCR0	((VH *)0x5fffec2)	/* ���ꥢ�뎥����ȥ��뎥�쥸���� */
#define SCI_TDR0	((VH *)0x5fffec3)	/* �ȥ�󥹥ߥåȎ��ǡ������쥸���� */
#define SCI_SSR0	((VH *)0x5fffec4)	/* ���ꥢ�뎥���ơ��������쥸���� */
#define SCI_RDR0	((VH *)0x5fffec5)	/* �쥷���֎��ǡ������쥸���� */

/* �ӣãɥ���ͥ룱 */
#define SCI_SMR1	((VH *)0x5fffec8)	/* ���ꥢ�뎥�⡼�Ɏ��쥸���� */
#define SCI_BRR1	((VH *)0x5fffec9)	/* �ӥåȥ졼�Ȏ��쥸���� */
#define SCI_SCR1	((VH *)0x5fffeca)	/* ���ꥢ�뎥����ȥ��뎥�쥸���� */
#define SCI_TDR1	((VH *)0x5fffecb)	/* �ȥ�󥹥ߥåȎ��ǡ������쥸���� */
#define SCI_SSR1	((VH *)0x5fffecc)	/* ���ꥢ�뎥���ơ��������쥸���� */
#define SCI_RDR1	((VH *)0x5fffecd)	/* �쥷���֎��ǡ������쥸���� */
#endif	/* sh1sci2.c */

#define PBCR1_TD1_RD1_MASK	~0xf0u		/*  TxD1,RxD1ü�������ѥޥ���	*/
#define PBCR1_TD1 		0x80u		/*  TxD1ü�������ѥޥ���  	*/
#define PBCR1_RD1 		0x20u		/*  RxD1ü�������ѥޥ���  	*/

/* ������ */
#define AD_DRAH		((VH *)0x5fffee0)	/* A/D �ǡ������쥸������ H�ʎˎގ���9��2��*/
#define AD_DRAL		((VH *)0x5fffee1)	/* A/D �ǡ������쥸������ L�ʎˎގ���1��0��*/
#define AD_DRBH		((VH *)0x5fffee2)	/* A/D �ǡ������쥸������ H�ʎˎގ���9��2��*/
#define AD_DRBL		((VH *)0x5fffee3)	/* A/D �ǡ������쥸������ L�ʎˎގ���1��0��*/
#define AD_DRCH		((VH *)0x5fffee4)	/* A/D �ǡ������쥸������ H�ʎˎގ���9��2��*/
#define AD_DRCL		((VH *)0x5fffee5)	/* A/D �ǡ������쥸������ L�ʎˎގ���1��0��*/
#define AD_DRDH		((VH *)0x5fffee6)	/* A/D �ǡ������쥸������ H�ʎˎގ���9��2��*/
#define AD_DRDL		((VH *)0x5fffee7)	/* A/D �ǡ������쥸������ L�ʎˎގ���1��0��*/
#define AD_CSR		((VH *)0x5fffee8)	/* A/D ����ȥ��롿���ơ��������쥸���� */
#define AD_CR		((VH *)0x5fffee9)	/* A/D ����ȥ��뎥�쥸���� 		 */
#define	ADF			0x80		/* ADF				*/
#define	ADST			0x20		/* A/D start			*/

#if 0 /* sh1itu.h���������Ƥ��� */
/* �ɣԣն��� */
#define ITU_TSTR	((VH *)0x5ffff00)	/* �����ގ��������Ȏ��쥸���� */
#define ITU_TSNC	((VH *)0x5ffff01)	/* �����ގ����󥯥펥�쥸���� */
#define ITU_TMDR	((VH *)0x5ffff02)	/* �����ގ��⡼�Ɏ��쥸���� 	*/
#define ITU_TFCR	((VH *)0x5ffff03)	/* �����ގ��ե��󥯥���󎥥���ȥ��뎥�쥸���� */
#define ITU_TOER	((VH *)0x5ffff31)	/* �����ގ������ȥץåȎ��ޥ������͡��֥뎥�쥸���� */

/* �ɣԣե���ͥ룰 */
#define ITU_TCR0	((VH *)0x5ffff04)	/* �����ގ�����ȥ��뎥�쥸����0 		*/
#define ITU_TIOR0	((VH *)0x5ffff05)	/* �����ޣɡ��ϥ���ȥ��뎥�쥸����0 	*/
#define ITU_TIER0	((VH *)0x5ffff06)	/* �����ގ����󥿥�ץȎ����͡��֥뎥�쥸����0 */
#define ITU_TSR0	((VH *)0x5ffff07)	/* �����ގ����ơ��������쥸����0 */
#define ITU_TCNT0	((VH *)0x5ffff08)	/* �����ގ�������0 */
#define ITU_GRA0	((VH *)0x5ffff0a)	/* �����ͥ�뎥�쥸������0 */
#define ITU_GRB0	((VH *)0x5ffff0c)	/* �����ͥ�뎥�쥸������0 */
#endif /* sh1itu.h */

/* �ɣԣե���ͥ룱 */
#define ITU_TCR1	((VH *)0x5ffff0e)	/* �����ގ�����ȥ��뎥�쥸����1 */
#define ITU_TIOR1	((VH *)0x5ffff0f)	/* �����ޣɡ��ϥ���ȥ��뎥�쥸����1 */
#define ITU_TIER1	((VH *)0x5ffff10)	/* �����ގ����󥿥�ץȎ����͡��֥뎥�쥸����1 */
#define ITU_TSR1	((VH *)0x5ffff11)	/* �����ގ����ơ��������쥸����1 */
#define ITU_TCNT1	((VH *)0x5ffff12)	/* �����ގ�������1 */
#define ITU_GRA1	((VH *)0x5ffff14)	/* �����ͥ�뎥�쥸������1 */
#define ITU_GRB1	((VH *)0x5ffff16)	/* �����ͥ�뎥�쥸������1 */

/* �ɣԣե���ͥ룲 */
#define ITU_TCR2	((VH *)0x5ffff18)	/* �����ގ�����ȥ��뎥�쥸����2  */
#define ITU_TIOR2	((VH *)0x5ffff19)	/* �����ޣɡ��ϥ���ȥ��뎥�쥸����2  */
#define ITU_TIER2	((VH *)0x5ffff1a)	/* �����ގ����󥿥�ץȎ����͡��֥뎥�쥸����2  */
#define ITU_TSR2	((VH *)0x5ffff1b)	/* �����ގ����ơ��������쥸����2  */
#define ITU_TCNT2	((VH *)0x5ffff1c)	/* �����ގ�������2  */
#define ITU_GRA2	((VH *)0x5ffff1e)	/* �����ͥ�뎥�쥸������2 */
#define ITU_GRB2	((VH *)0x5ffff20)	/* �����ͥ�뎥�쥸������2 */

/* �ɣԣե���ͥ룳 */
#define ITU_TCR3	((VH *)0x5ffff22)	/* �����ގ�����ȥ��뎥�쥸����3 */
#define ITU_TIOR3	((VH *)0x5ffff23)	/* �����ޣɡ��ϥ���ȥ��뎥�쥸����3 */
#define ITU_TIER3	((VH *)0x5ffff24)	/* �����ގ����󥿥�ץȎ����͡��֥뎥�쥸����3 */
#define ITU_TSR3	((VH *)0x5ffff25)	/* �����ގ����ơ��������쥸����3 */
#define ITU_TCNT3	((VH *)0x5ffff26)	/* �����ގ�������3 */
#define ITU_GRA3	((VH *)0x5ffff28)	/* �����ͥ�뎥�쥸������3 */
#define ITU_GRB3	((VH *)0x5ffff2a)	/* �����ͥ�뎥�쥸������3 */
#define ITU_BRA3	((VH *)0x5ffff2c)	/* �Хåե����쥸������3 */
#define ITU_BRB3	((VH *)0x5ffff2e)	/* �Хåե����쥸������3 */

/* �ɣԣե���ͥ룴 */
#define ITU_TCR4	((VH *)0x5ffff32)	/* �����ގ�����ȥ��뎥�쥸����4 */
#define ITU_TIOR4	((VH *)0x5ffff33)	/* �����ޣɡ��ϥ���ȥ��뎥�쥸����4 */
#define ITU_TIER4	((VH *)0x5ffff34)	/* �����ގ����󥿥�ץȎ����͡��֥뎥�쥸����4 */
#define ITU_TSR4	((VH *)0x5ffff35)	/* �����ގ����ơ��������쥸����4 */
#define ITU_TCNT4	((VH *)0x5ffff36)	/* �����ގ�������4 */
#define ITU_GRA4	((VH *)0x5ffff38)	/* �����ͥ�뎥�쥸������4 */
#define ITU_GRB4	((VH *)0x5ffff3a)	/* �����ͥ�뎥�쥸������4 */
#define ITU_BRA4	((VH *)0x5ffff3c)	/* �Хåե����쥸������4 */
#define ITU_BRB4	((VH *)0x5ffff3e)	/* �Хåե����쥸������4 */

/* �ɣԣ� */
#if 0 /* sh1itu.h���������Ƥ��� */
#ifndef	TSR_IMFA
#define TSR_IMFA	0x0001			/* GRA���ݎ͎ߎ��ώ���/���ݎ̎ߎ��Ď����̎ߎ����̎׎���A */
#endif
#endif /* sh1itu.h */

#ifndef	TSR_IMFB
#define TSR_IMFB	0x0002			/* GRB���ݎ͎ߎ��ώ���/���ݎ̎ߎ��Ď����̎ߎ����̎׎���B */
#endif
#define TSR_OVF	 	0x0004				/* �����ʎގ��̎ێ��̎׎��� */

/* �ģͣ��ö��� */
#define DMAC_DMAOR	((VH *)0x5ffff48)		/* DMA ���ڥ졼����󎥥쥸���� */

/* �ģͣ��å���ͥ룰 */
#define DMAC_SAR0	((VH *)0x5ffff40)	/* DMA �����������ɥ쥹���쥸����0 */
#define DMAC_DAR0	((VH *)0x5ffff44)	/* DMA �ǥ��ƥ��͡�����󎥥��ɥ쥹���쥸����0 */
#define DMAC_TCR0	((VH *)0x5ffff4a)	/* DMA �ȥ�󥹥ե���������Ȏ��쥸����0 */
#define DMAC_CHCR0	((VH *)0x5ffff4e)		/* DMA ����ͥ뎥����ȥ��뎥�쥸����0 */

/* �ģͣ��å���ͥ룱 */
#define DMAC_SAR1	((VH *)0x5ffff50)	/* DMA �����������ɥ쥹���쥸����1 */
#define DMAC_DAR1	((VH *)0x5ffff54)	/* DMA �ǥ��ƥ��͡�����󎥥��ɥ쥹���쥸����1 */
#define DMAC_TCR1	((VH *)0x5ffff5a)	/* DMA �ȥ�󥹥ե���������Ȏ��쥸����1 */
#define DMAC_CHCR1	((VH *)0x5ffff5e)		/* DMA ����ͥ뎥����ȥ��뎥�쥸����1 */
/* �ģͣ��å���ͥ룲 */

#define DMAC_SAR2	((VH *)0x5ffff60)	/* DMA �����������ɥ쥹���쥸����2 */
#define DMAC_DAR2	((VH *)0x5ffff64)	/* DMA �ǥ��ƥ��͡�����󎥥��ɥ쥹���쥸����2 */
#define DMAC_TCR2	((VH *)0x5ffff6a)	/* DMA �ȥ�󥹥ե���������Ȏ��쥸����2 */
#define DMAC_CHCR2	((VH *)0x5ffff6e)		/* DMA ����ͥ뎥����ȥ��뎥�쥸����2 */

/* �ģͣ��å���ͥ룳 */
#define DMAC_SAR3	((VH *)0x5ffff70)	/* DMA �����������ɥ쥹���쥸����3 */
#define DMAC_DAR3	((VH *)0x5ffff74)	/* DMA �ǥ��ƥ��͡�����󎥥��ɥ쥹���쥸����3 */
#define DMAC_TCR3	((VH *)0x5ffff7a)	/* DMA �ȥ�󥹥ե���������Ȏ��쥸����3 */
#define DMAC_CHCR3	((VH *)0x5ffff7e)		/* DMA ����ͥ뎥����ȥ��뎥�쥸����3 */

/* ����ߥ���ȥ��� */
#define INTC_IPRA	((VH *)0x5ffff84)	/* �����ͥ���٥�����쥸������ */
#define INTC_IPRB	((VH *)0x5ffff86)	/* �����ͥ���٥�����쥸������ */
#define INTC_IPRC	((VH *)0x5ffff88)	/* �����ͥ���٥�����쥸������ */
#define INTC_IPRD	((VH *)0x5ffff8a)	/* �����ͥ���٥�����쥸������ */
#define INTC_IPRE	((VH *)0x5ffff8c)	/* �����ͥ���٥�����쥸������ */
#define INTC_ICR	((VH *)0x5ffff8e)	/* ����ߥ���ȥ���쥸���� */

/* �桼���֥졼��������ȥ��� */
#define UBC_BARH	((VH *)0x5ffff90)	/* �֥졼�������ɥ쥹���쥸������ */
#define UBC_BARL	((VH *)0x5ffff92)	/* �֥졼�������ɥ쥹���쥸������ */
#define UBC_BAMRH	((VH *)0x5ffff94)	/* �֥졼�������ɥ쥹���ޥ������쥸������ */
#define UBC_BAMRL	((VH *)0x5ffff96)	/* �֥졼�������ɥ쥹���ޥ������쥸������ */
#define UBC_BBR		((VH *)0x5ffff98)	/* �֥졼�����Х��������뎥�쥸���� */

/* �Х�������ȥ��� */
#define BSC_BCR		((VH *)0x5ffffa0)	/* �Х�������ȥ��뎥�쥸���� */
#define BSC_WCR1	((VH *)0x5ffffa2)	/* �������Ȏ����ơ�������쥸����1 */
#define BSC_WCR2	((VH *)0x5ffffa4)	/* �������Ȏ����ơ�������쥸����2 */
#define BSC_WCR3	((VH *)0x5ffffa6)	/* �������Ȏ����ơ�������쥸����3 */
#define BSC_DCR		((VH *)0x5ffffa8)	/* DRAM ���ꥢ������ȥ��뎥�쥸���� */
#define BSC_PCR		((VH *)0x5ffffaa)	/* DRAM �ѥ�ƥ�������ȥ��뎥�쥸���� */
#define BSC_RCR		((VH *)0x5ffffac)	/* ��ե쎯���厥����ȥ��뎥�쥸���� */
#define BSC_RTCSR	((VH *)0x5ffffae)	/* ��ե쎯�����������ގ�����ȥ펰��/���Ǝ��������쥸���� */
#define BSC_RTCNT	((VH *)0x5ffffb0)	/* ��ե쎯���厥�����ގ������� */
#define BSC_RTCOR	((VH *)0x5ffffb2)	/* ��ե쎯���厥�����ॳ�󥹥���Ȏ��쥸���� */

/* �ףģ� */
#define WDT_TCSR	((VH *)0x5ffffb8)	/* �����ގ�����ȥ��롿���ơ��������쥸���� */
#define WDT_TCNT	((VH *)0x5ffffb8)	/* �����ގ������󥿡ʎ׎��ġ�*/
#define WDT_TCNT_R	((VH *)0x5ffffb9)	/* �����ގ������󥿡ʎ؎��Ďޡ�*/
#define WDT_RSTCSR	((VH *)0x5ffffba)	/* �ꥻ���Ȏ�����ȥ펰��/���Ǝ��������쥸�����ʎ׎��ġ�*/
#define WDT_RSTCSR_R	((VH *)0x5ffffbb)		/* �ꥻ���Ȏ�����ȥ펰��/���Ǝ��������쥸�����ʎ؎��Ďޡ�*/

/* ��������� */
#define SYS_SBYCR	((VH *)0x5ffffbc)	/* ������Х�������ȥ��뎥�쥸���� */

/* �ݡ��ȣ����� */
#define PA_DR		((VH *)0x5ffffc0)	/* �ݡ��ȣ� �ǡ������쥸���� */
#define PB_DR		((VH *)0x5ffffc2)	/* �ݡ��ȣ� �ǡ������쥸���� */
#define PC_DR		((VH *)0x5ffffd0)	/* �ݡ��ȣ� �ǡ������쥸���� */

#define PB_RTS0		(1<<2)  		/* RTS0 ����ü�ҡ�PB2��*/
#define PB_CTS0		(1<<3)  		/* CTS0 ����ü�ҡ�PB3��*/
#define PB_TXE1		(1<<5)  		/* TXE1 ����ü�ҡ�PB5��*/
#define PB_RXD0		(1<<8)  		/* RxD0 ����ü�ҡ�PB8��*/
#define PB_TXD0		(1<<9)  		/* TxD0 ����ü�ҡ�PB9��*/
#define PB_RXD1		(1<<10) 		/* RxD1 ����ü�ҡ�PB10��*/
#define PB_TXD1		(1<<11)			/* TxD1 ����ü�ҡ�PB11��*/

/* �ԥ󎥥ե��󥯥���󎥥���ȥ��� */
#define PFC_PAIOR	((VH *)0x5ffffc4)	/* �ݡ��ȣ� �ɣϥ쥸���� */
#define PFC_PBIOR	((VH *)0x5ffffc6)	/* �ݡ��ȣ� �ɣϥ쥸���� */
#define PFC_PACR1	((VH *)0x5ffffc8)	/* �ݡ��ȣ� ����ȥ��뎥�쥸����1 */
#define PFC_PACR2	((VH *)0x5ffffca)	/* �ݡ��ȣ� ����ȥ��뎥�쥸����2 */
#define PFC_PBCR1	((VH *)0x5ffffcc)	/* �ݡ��ȣ� ����ȥ��뎥�쥸����1 */
#define PFC_PBCR2	((VH *)0x5ffffce)	/* �ݡ��ȣ� ����ȥ��뎥�쥸����2 */
#define PFC_CASCR	((VH *)0x5ffffee)	/* ����ॢ�ɥ쥹�����ȥ펰�֎��ԥ󎥥���Ďێ��َ��쥸���� */

/* �ԣУ� */
#define TPC_TPMR	((VH *)0x5fffff0)	/* TPC ���ϥ⡼�Ɏ��쥸���� */
#define TPC_TPCR	((VH *)0x5fffff1)	/* TPC ���ϥ���ȥ��뎥�쥸���� */
#define TPC_NDERB	((VH *)0x5fffff2)	/* �ͥ����Ȏ��ǡ��������͡��֥뎥�쥸������ */
#define TPC_NDERA	((VH *)0x5fffff3)	/* �ͥ����Ȏ��ǡ��������͡��֥뎥�쥸������ */
#define TPC_NDRB	((VH *)0x5fffff4)	/* �ͥ����Ȏ��ǡ������쥸������ */
#define TPC_NDRA	((VH *)0x5fffff5)	/* �ͥ����Ȏ��ǡ������쥸������ */
#define TPC_NDRB_2	((VH *)0x5fffff6)	/* �ͥ����Ȏ��ǡ������쥸�����¡ʽ��ώĎ؎��ްۤʤ����*/
#define TPC_NDRA_2	((VH *)0x5fffff7)	/* �ͥ����Ȏ��ǡ������쥸�������ʽ��ώĎ؎��ްۤʤ����*/

/* ����ߥ٥����ֹ� */
#define INT_NMI		11		/* NMI */
#define INT_UB		12		/* �桼���֥졼�� */
#define INT_IRQ0	64		/* ����ü�� IRQ0 */
#define INT_IRQ1	65		/* ����ü�� IRQ1 */
#define INT_IRQ2	66		/* ����ü�� IRQ2 */
#define INT_IRQ3	67		/* ����ü�� IRQ3 */
#define INT_IRQ4	68		/* ����ü�� IRQ4 */
#define INT_IRQ5	69		/* ����ü�� IRQ5 */
#define INT_IRQ6	70		/* ����ü�� IRQ6 */
#define INT_IRQ7	71		/* ����ü�� IRQ7 */
#define INT_DEI0	72		/* DMAC ����ͥ�0 */
#define INT_DEI1	74		/* DMAC ����ͥ�1 */
#define INT_DEI2	76		/* DMAC ����ͥ�2 */
#define INT_DEI3	78		/* DMAC ����ͥ�3 */
#define INT_IMIA0	80		/* ITU �����ͥ�0 ����ڥ��ގ���/����׎��ĥ����ץ���A0 */
#define INT_IMIB0	81		/* ITU �����ͥ�0 ����ڥ��ގ���/����׎��ĥ����ץ���B0 */
#define INT_OVI0	82		/* ITU �����ͥ�0 �����Хե�0 */
#define INT_IMIA1	84		/* ITU �����ͥ�1 ����ڥ��ގ���/����׎��ĥ����ץ���A1 */
#define INT_IMIB1	85		/* ITU �����ͥ�1 ����ڥ��ގ���/����׎��ĥ����ץ���B1 */
#define INT_OVI1	86		/* ITU �����ͥ�1 �����Хե�1 */
#define INT_IMIA2	88		/* ITU �����ͥ�2 ����ڥ��ގ���/����׎��ĥ����ץ���A2 */
#define INT_IMIB2	89		/* ITU �����ͥ�2 ����ڥ��ގ���/����׎��ĥ����ץ���B2 */
#define INT_OVI2	90		/* ITU �����ͥ�2 �����Хե�2 */
#define INT_IMIA3	92		/* ITU �����ͥ�3 ����ڥ��ގ���/����׎��ĥ����ץ���A3 */
#define INT_IMIB3	93		/* ITU �����ͥ�3 ����ڥ��ގ���/����׎��ĥ����ץ���B3 */
#define INT_OVI3	94		/* ITU �����ͥ�3 �����Хե�3 */
#define INT_IMIA4	96		/* ITU �����ͥ�4 ����ڥ��ގ���/����׎��ĥ����ץ���A4 */
#define INT_IMIB4	97		/* ITU �����ͥ�4 ����ڥ��ގ���/����׎��ĥ����ץ���B4 */
#define INT_OVI4	98		/* ITU �����ͥ�4 �����Хե�4 */
#define INT_ERI0	100		/* SCI ����ͥ�0 �������顼 */
#define INT_RXI0	101	 	/* SCI ����ͥ�0 ������λ */
#define INT_TXI0	102		/* SCI ����ͥ�0 �����ǡ���������ץƥ� */
#define INT_TEI0	103		/* SCI ����ͥ�0 ������λ */
#define INT_ERI1	104		/* SCI ����ͥ�1 �������顼 */
#define INT_RXI1	105		/* SCI ����ͥ�1 ������λ */
#define INT_TXI1	106		/* SCI ����ͥ�1 �����ǡ���������ץƥ� */
#define INT_TEI1	107		/* SCI ����ͥ�1 ������λ */
#define INT_PEI		108		/* �ѥ�ƥ� */
#define INT_ADI		109		/* A/D ����� */
#define INT_ITI		112		/* �����å��ɥå��������ޡʥ��󥿡��Х뎥�����ޡ�*/
#define INT_CMI		113		/* ��ե�å��女����ȥ��鎥����ڥ��ޥå� */

/*
 *  GDB STUB�ƽФ��롼����
 */
#ifndef _MACRO_ONLY
#ifdef GDB_STUB

#define zunda_sh1_exit	gdb_stub_exit
#define zunda_sh1_putc	gdb_stub_putc

Inline void
gdb_stub_exit(void)
{
	Asm("trapa #0xff"::);		/*  ̤����  */
}

/*
 *  gdb stub�ˤ�����
 */
Inline int
gdb_stub_putc(int c)
{
	Asm("mov   #0x00,r0
	     mov   %0,r4
	     trapa #0x21"
               : /* no output */
               : "r"(c)
               : "r0","r4");
	return(c);
}

/*
 *  ROM���ξ��
 */
#else /* GDB_STUB */

Inline void
zunda_sh1_exit(void)
{
	while(1);
}

extern void	sh1sci_putc_pol(char c);	/*  sh1sci2.c  */

Inline void 
zunda_sh1_putc(char c)
{
	sh1sci_putc_pol(c);
}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _ZUNDA_SH1_H_ */
