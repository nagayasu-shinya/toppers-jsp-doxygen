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
 *  @(#) $Id: sh1sci.c,v 1.12 2005/11/14 08:00:44 honda Exp $
 */

/*
 *   SH1��¢���ꥢ�륳�ߥ�˥�������󥤥󥿥ե�����SCI�� �ʰץɥ饤��
 *��������
 *��������SCI0�ΤߤΥ��ݡ��Ȥ�����2ch�ؤγ�ĥ���ϻĤ��Ƥ��롣
 *
 *��������sh1sci.{c,h}��hw_serial.h��ʬ��δ��
 *��������������sh1sci.{c,h}�����ꥢ��ǥХ����˰�¸������ʬ�Τߵ���
 *��������������hw_serial.h������ߥ���ȥ����¸
 *������������
 *������������������å����ȿ���¸�ˤĤ���
 *�������������������ǥХ�����¸�Υѥ�᡼����sh1sci.c����Ѱդ��롣
 *�������������������縵�Υ���å����ȿ��ϥ���ѥ��륪�ץ����Ȥ���Ϳ����
 */

#include <s_services.h>
#include <sh1sci.h>

/*
 *  ����ȥ���쥸�����Υ��ɥ쥹 �ʤ��٤�1�Х��ȥ�������
 */
	/*  ����ͥ�0  */
#define SCI_SMR0 (VB *)0x5fffec0	/*  ���ꥢ��⡼�ɥ쥸���� */
#define SCI_BRR0 (VB *)0x5fffec1	/*  �ӥåȥ졼�ȥ쥸����  */
#define SCI_SCR0 (VB *)0x5fffec2	/*  ���ꥢ�륳��ȥ���쥸���� */
#define SCI_TDR0 (VB *)0x5fffec3	/*  �ȥ�󥹥ߥåȥǡ����쥸���� */
#define SCI_SSR0 (VB *)0x5fffec4	/*  ���ꥢ�륹�ơ������쥸���� */
#define SCI_RDR0 (VB *)0x5fffec5	/*  �쥷���֥ǡ����쥸���� */

	/*  ����ͥ�1  */
#define SCI_SMR1 (VB *)0x5fffec8	/*  ���ꥢ��⡼�ɥ쥸���� */
#define SCI_BRR1 (VB *)0x5fffec9	/*  �ӥåȥ졼�ȥ쥸����  */
#define SCI_SCR1 (VB *)0x5fffeca	/*  ���ꥢ�륳��ȥ���쥸���� */
#define SCI_TDR1 (VB *)0x5fffecb	/*  �ȥ�󥹥ߥåȥǡ����쥸���� */
#define SCI_SSR1 (VB *)0x5fffecc	/*  ���ꥢ�륹�ơ������쥸���� */
#define SCI_RDR1 (VB *)0x5fffecd	/*  �쥷���֥ǡ����쥸���� */


/*
 *  ����ȥ���쥸������������
 */
/*  ���ꥢ�륹�ơ������쥸����SSR�γƥӥå�  */
#define SSR_TDRE	0x80u	/* �ȥ�󥹥ߥåȥǡ����쥸��������ץƥ� */
#define SSR_RDRF	0x40u	/* �쥷���֥ǡ����쥸�����ե� 		*/
#define SSR_ORER	0x20u	/* �����С���󥨥顼 			*/
#define SSR_FER		0x10u	/* �ե졼�ߥ󥰥��顼 			*/
#define SSR_PER		0x08u	/* �ѥ�ƥ����顼 			*/
#define SSR_TEND	0x04u	/* �ȥ�󥹥ߥåȥ���� 		*/
#define SSR_MPB		0x02u	/* �ޥ���ץ��å��ӥå� 		*/
#define SSR_MPBT	0x01u	/* �ޥ���ץ��å��ӥåȥȥ�󥹥ե� 	*/

/*  ���ꥢ�륳��ȥ���쥸����SCR�γƥӥå�  */
#define SCR_TIE		0x80u	/* �ȥ�󥹥ߥåȥ��󥿥�ץȥ��͡��֥� */
#define SCR_RIE		0x40u	/* �쥷���֥��󥿥�ץȥ��͡��֥� 	*/
#define SCR_TE		0x20u	/* �ȥ�󥹥ߥåȥ��͡��֥� 		*/
#define SCR_RE		0x10u	/* �쥷���֥��͡��֥� 			*/
#define SCR_MPIE	0x08u	/* �ޥ���ץ��å����󥿥�ץȥ��͡��֥� */
				/* �ȥ�󥹥ߥåȥ���ɥ��󥿥�ץ�	*/
#define SCR_TEIE	0x04u	/* ���͡��֥� 				*/
#define SCR_CKE_MASK	0x03u	/* ����å������������ѥޥ���		*/
#define SCR_CKE		0x00u	/* ����å����͡��֥�			*/
				/*   Ĵ��Ʊ�����ΤȤ�  			*/
				/*   	��������å�����  		*/
				/*   	���Ϥʤ�  			*/

/*  ���ꥢ��⡼�ɥ�����SMR�γƥӥå�  */
				/* ���ߥ�˥��������⡼�� 	*/
#define SMR_CA_CLOCK	0x80u	/* 	����å�Ʊ���� 		*/
#define SMR_CA_ASYNC	0x00u	/* 	Ĵ��Ʊ���� 		*/
	/*  Ĵ��Ʊ�����̿���Asynchronous Communication method	*/
				/* ����饯����󥰥� 		*/
#define SMR_CHR8	0x00u	/* 	8�ӥå� 		*/
#define SMR_CHR7	0x40u	/* 	7�ӥå� 		*/
				/* �ѥ�ƥ����͡��֥� 		*/
#define SMR_PE		0x20u	/* 	�ѥ�ƥ����� 		*/
#define SMR_PE_NON	0x00u	/* 	�ѥ�ƥ��ʤ� 		*/
#define SMR_OE_ODD	0x10u	/* �ѥ�ƥ��⡼�ɡʴ���ѥ�ƥ���*/
#define SMR_STOP2	0x08u	/* ���ȥåץӥåȥ�󥰥���2 	*/
#define SMR_STOP1	0x00u	/* ���ȥåץӥåȥ�󥰥���1 	*/
#define SMR_MP		0x04u	/* �ޥ���ץ��å��⡼�� 	*/

/*
 *  ����å����ȿ���¸
 *  	���ԥޥ�������ԥ塼��KZ-SH1-01�Υ���å����ȿ���20MHz
 *  	CQ���� RISCɾ�����å� SH-1�Υ���å����ȿ���19.6608MHz
 *  	���׾���SH1/CPUB�Υ���å����ȿ���16MHz
 */

/*
 *  ʬ����ȥӥåȥ졼�Ȥ�����
 */
#if CONFIG_BAUD == 9600
/*
 *
 *  ����å�	��20MHz�ξ��
 *  �ӥåȥ졼�ȡ�9600bps
 *
 *  ��n=0(ʬ�����ʤ��ΤǤ��Τޤ�)
 *  ��N=64�Ǹ�0.16%
 *  ��äơ�
 *  �����ꥢ��⡼�ɥ쥸����SMR�Υ���å����쥯�ȥӥå�CKS=00
 *  ���ӥåȥ졼�ȥ쥸����BRR=64
 */
#ifdef CONFIG_20MHZ
#define SMR_CKS 	0x0u	/*  ʬ����  		*/
#define SCI_BRR 	64u	/*  �ӥåȥ졼��  	*/
#endif

/*
 *  ����å�	��19.6608MHz
 *  �ӥåȥ졼�ȡ�9600bps
 *
 *  ��n=0(ʬ�����ʤ��ΤǤ��Τޤ�)
 *  ��N=63�Ǹ�0%
 *  ��äơ�
 *  �����ꥢ��⡼�ɥ쥸����SMR�Υ���å����쥯�ȥӥå�CKS=00
 *  ���ӥåȥ졼�ȥ쥸����BRR=63
 */
#ifdef CONFIG_19MHZ
#define SMR_CKS 	0x0u	/*  ʬ����  		*/
#define SCI_BRR 	63u	/*  �ӥåȥ졼��  	*/
#endif

/*
 *  ����å�	��16MHz
 *  �ӥåȥ졼�ȡ�9600bps
 *
 *  ��n=0(ʬ�����ʤ��ΤǤ��Τޤ�)
 *  ��N=51�Ǹ�0.16%
 *  ��äơ�
 *  �����ꥢ��⡼�ɥ쥸����SMR�Υ���å����쥯�ȥӥå�CKS=00
 *  ���ӥåȥ졼�ȥ쥸����BRR=51
 */
#ifdef CONFIG_16MHZ
#define SMR_CKS 	0x0u	/*  ʬ����  		*/
#define SCI_BRR 	51u	/*  �ӥåȥ졼��  	*/
#endif

/*
 *  �ܡ��졼������塢����å������ꤹ��ޤǤ��Ԥ�����
 *  ���ʺǽ��1�ӥå�ʬ�ˡ�
 *  BPS=9600bps�ξ��
 *  ��t = 1 / BPS = 104,167 = 105,000[nsec]
 */
#define SH1SCI_DELAY 	105000


#elif CONFIG_BAUD == 19200


/*
 *
 *  ����å�	��20MHz�ξ��
 *  �ӥåȥ졼�ȡ�19200bps
 *
 *  ��n=0(ʬ�����ʤ��ΤǤ��Τޤ�)
 *  ��N=32�Ǹ� -1.36%
 *  ��äơ�
 *  �����ꥢ��⡼�ɥ쥸����SMR�Υ���å����쥯�ȥӥå�CKS=00
 *  ���ӥåȥ졼�ȥ쥸����BRR=32
 */
#ifdef CONFIG_20MHZ
#define SMR_CKS 	0x0u	/*  ʬ����  		*/
#define SCI_BRR 	32u	/*  �ӥåȥ졼��  	*/
#endif

/*
 *  ����å�	��19.6608MHz
 *  �ӥåȥ졼�ȡ�19200bps
 *
 *  ��n=0(ʬ�����ʤ��ΤǤ��Τޤ�)
 *  ��N=31�Ǹ�0%
 *  ��äơ�
 *  �����ꥢ��⡼�ɥ쥸����SMR�Υ���å����쥯�ȥӥå�CKS=00
 *  ���ӥåȥ졼�ȥ쥸����BRR=31
 */
#ifdef CONFIG_19MHZ
#define SMR_CKS 	0x0u	/*  ʬ����  		*/
#define SCI_BRR 	31u	/*  �ӥåȥ졼��  	*/
#endif

/*
 *  ����å�	��16MHz
 *  �ӥåȥ졼�ȡ�19200bps
 *
 *  ��n=0(ʬ�����ʤ��ΤǤ��Τޤ�)
 *  ��N=25�Ǹ�0.16%
 *  ��äơ�
 *  �����ꥢ��⡼�ɥ쥸����SMR�Υ���å����쥯�ȥӥå�CKS=00
 *  ���ӥåȥ졼�ȥ쥸����BRR=25
 */
#ifdef CONFIG_16MHZ
#define SMR_CKS 	0x0u	/*  ʬ����  		*/
#define SCI_BRR 	25u	/*  �ӥåȥ졼��  	*/
#endif

/*
 *  �ܡ��졼������塢����å������ꤹ��ޤǤ��Ԥ�����
 *  ���ʺǽ��1�ӥå�ʬ�ˡ�
 *  BPS=19200bps�ξ��
 *  ��t = 1 / BPS = 52,083 = 53,000[nsec]
 */
#define SH1SCI_DELAY 	53000


#elif CONFIG_BAUD == 38400


/*
 *
 *  ����å�	��20MHz�ξ��
 *  �ӥåȥ졼�ȡ�38400bps
 *
 *  ��n=0(ʬ�����ʤ��ΤǤ��Τޤ�)
 *  ��N=15�Ǹ�1.73%
 *  ��äơ�
 *  �����ꥢ��⡼�ɥ쥸����SMR�Υ���å����쥯�ȥӥå�CKS=00
 *  ���ӥåȥ졼�ȥ쥸����BRR=15
 */
#ifdef CONFIG_20MHZ
#define SMR_CKS 	0x0u	/*  ʬ����  		*/
#define SCI_BRR 	15u	/*  �ӥåȥ졼��  	*/
#endif

/*
 *  ����å�	��19.6608MHz
 *  �ӥåȥ졼�ȡ�38400bps
 *
 *  ��n=0(ʬ�����ʤ��ΤǤ��Τޤ�)
 *  ��N=15�Ǹ�0%
 *  ��äơ�
 *  �����ꥢ��⡼�ɥ쥸����SMR�Υ���å����쥯�ȥӥå�CKS=00
 *  ���ӥåȥ졼�ȥ쥸����BRR=15
 */
#ifdef CONFIG_19MHZ
#define SMR_CKS 	0x0u	/*  ʬ����  		*/
#define SCI_BRR 	15u	/*  �ӥåȥ졼��  	*/
#endif

/*
 *  ����å�	��16MHz
 *  �ӥåȥ졼�ȡ�38400bps
 *
 *  ��n=0(ʬ�����ʤ��ΤǤ��Τޤ�)
 *  ��N=12�Ǹ�0.16%
 *  ��äơ�
 *  �����ꥢ��⡼�ɥ쥸����SMR�Υ���å����쥯�ȥӥå�CKS=00
 *  ���ӥåȥ졼�ȥ쥸����BRR=16
 */
#ifdef CONFIG_16MHZ
#define SMR_CKS 	0x0u	/*  ʬ����  		*/
#define SCI_BRR 	16u	/*  �ӥåȥ졼��  	*/
#endif

/*
 *  �ܡ��졼������塢����å������ꤹ��ޤǤ��Ԥ�����
 *  ���ʺǽ��1�ӥå�ʬ�ˡ�
 *  BPS=38400bps�ξ��
 *  ��t = 1 / BPS = 26,042 = 27,000[nsec]
 */
#define SH1SCI_DELAY 	27000

#else	/*  CONFIG_BAUD  */

#error unsupported baud rate.

#endif 	/*  CONFIG_BAUD  */


/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 *  ��2ch���ݡ��Ȥ˳�ĥ������Ͻ�����ѤΥǡ�����ޤ��
 */
struct sio_port_control_block {
	VP_INT		exinf;		/* ��ĥ���� */
	BOOL		openflag;	/* �����ץ�Ѥߥե饰 */
};

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 *  ����ID = 1 ��SCI0���б������Ƥ��롥
 */
static SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
				/*  �ݡ���ID����ǥХ����ֹ�����ޥ���  */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ʸ��������Ǥ��뤫��
 */
Inline BOOL
sh1sci_getready(SIOPCB *siopcb)
{
	VB ssr0 = sil_reb_mem(SCI_SSR0);
	return(ssr0 & SSR_RDRF);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
sh1sci_putready(SIOPCB *siopcb)
{
	VB ssr0 = sil_reb_mem(SCI_SSR0);
	return(ssr0 & SSR_TDRE);
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
sh1sci_getchar(SIOPCB *siopcb)
{
	char data;

	data = sil_reb_mem(SCI_RDR0);
	
	/*  �쥷���֥ǡ����쥸�����ե롦�ե饰�Υ��ꥢ  */
	sh1_anb_reg(SCI_SSR0, (VB)~SSR_RDRF);
	return data;
}

/*
 *  ��������ʸ���ν����
 */
Inline void
sh1sci_putchar(SIOPCB *siopcb, char c)
{
#ifdef GDB_STUB
	gdb_stub_putc( c );
#else
	sil_wrb_mem(SCI_TDR0 ,c);
	
	/*  �ȥ�󥹥ߥåȥǡ����쥸��������ץƥ����ե饰�Υ��ꥢ*/
	sh1_anb_reg(SCI_SSR0, (VB)~SSR_TDRE);
#endif
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
sh1sci_initialize(void)
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->openflag = FALSE;
	}
}

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
BOOL
sh1sci_openflag(void)
{
#if TNUM_SIOP < 2
	return(siopcb_table[0].openflag);
#else /* TNUM_SIOP < 2 */
	return(siopcb_table[0].openflag || siopcb_table[1].openflag);
#endif /* TNUM_SIOP < 2 */
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sh1sci_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb = get_siopcb(siopid);

#ifndef GDB_STUB
	VB scr0, smr0;
	VH pbcr1;

	sh1_anb_reg(SCI_SCR0, (VB)~(SCR_TE | SCR_RE));	/*  ���������  */

	/*  �ԥ󥢥�����
	 *     ���ꥢ��ǥХ������Τλ���ǤϤʤ��Τ�
	 *     ����Ϥ��Υե�����˵��Ҥ���ΤϤդ��路���ʤ�����
	 *     hw_serial.c���Ѱդ���Τ��ѻ��ʤΤǻ���Ū�ˤ���������Ƥ��롣
	 */
	pbcr1 = sil_reh_mem((VP)PBCR1);
						/* PB8:RxD0 PB9:TxD0  */
	pbcr1 = (pbcr1 & PBCR1_TD0_RD0_MASK) |
			PBCR1_TD0 | PBCR1_RD0;
	sil_wrh_mem((VP)PBCR1, pbcr1);
						/*  �������ե����ޥå�  */
	smr0 = 	SMR_CA_ASYNC |	/*  Ĵ��Ʊ����  		*/
		SMR_CHR8 |	/*  ����饯����󥰥���8�ӥå� */
		SMR_PE_NON |	/*  �ѥ�ƥ��ʤ�  		*/
		SMR_STOP1 |	/*  ���ȥåץӥåȥ�󥰥���1 	*/
		SMR_CKS;	/*  ����å����쥯�ȡ�ʬ�����  */
	sil_wrb_mem(SCI_SMR0, smr0);
	
	sil_wrb_mem(SCI_BRR0, SCI_BRR);	/*  �ܡ��졼������  	*/

					/*  ����߶ػߤȥ���å������������� */
	scr0 = (VB)(~(SCR_TIE | SCR_RIE | SCR_TE | SCR_RE |
			  SCR_MPIE | SCR_TEIE | SCR_CKE_MASK) | SCR_CKE);
	sil_wrb_mem(SCI_SCR0, scr0);
	
	/*
	 * �ܡ��졼�Ȥ�����塢1�������ʬ�Ԥ��ʤ���Фʤ�ʤ���
	 */
	sil_dly_nse(SH1SCI_DELAY);

					/* ���顼�ե饰�򥯥ꥢ	*/
	sh1_anb_reg(SCI_SSR0, (VB)~(SSR_ORER | SSR_FER | SSR_PER));
					/* ���������ߵ���   	*/
					/* ����������  		*/
	sh1_orb_reg(SCI_SCR0, (SCR_RIE | SCR_TE | SCR_RE));
			/*  ��������ߤε��Ĥ���������ؿ��ǹԤ�  */

#endif	/*  GDB_STUB  */

	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sh1sci_cls_por(SIOPCB *siopcb)
{
				/*  ��������ߡ�����߶ػ� 	*/
	sh1_anb_reg(SCI_SCR0, (VB)~(SCR_TIE | SCR_RIE | SCR_TE | SCR_RE));
	siopcb->openflag = FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
sh1sci_snd_chr(SIOPCB *siopcb, char c)
{
	if (sh1sci_putready(siopcb)) {
		sh1sci_putchar(siopcb, c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
sh1sci_rcv_chr(SIOPCB *siopcb)
{
	if (sh1sci_getready(siopcb)) {
		return((INT)(UB)sh1sci_getchar(siopcb));
		/*  (UB)�ǥ��㥹�Ȥ���Τϥ����ĥ�ˤ��뤿��  */
	}
	return(-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
sh1sci_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:	/* �����������׵����� */
		sh1_orb_reg(SCI_SCR0, SCR_TIE);
		break;
	case SIO_ERDY_RCV:	/* �����������׵����� */
		sh1_orb_reg(SCI_SCR0, SCR_RIE);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
sh1sci_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:	/* �����������׵��ػ� */
		sh1_anb_reg(SCI_SCR0, (VB)~SCR_TIE);
		break;
	case SIO_ERDY_RCV:	/* �����������׵��ػ� */
		sh1_anb_reg(SCI_SCR0, (VB)~SCR_RIE);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф�����������߽���
 */
Inline void
sh1sci_isr_siop_out(SIOPCB *siopcb)
{
	VB scr0 = sil_reb_mem(SCI_SCR0);
	
	if ((scr0 & SCR_TIE) != 0 && sh1sci_putready(siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sh1sci_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф����������߽���
 */
Inline void
sh1sci_isr_siop_in(SIOPCB *siopcb)
{
	VB scr0 = sil_reb_mem(SCI_SCR0);

	if ((scr0 & SCR_RIE) != 0 && sh1sci_getready(siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		sh1sci_ierdy_rcv(siopcb->exinf);
	}
}

/*
 *  SIO��������ߥ����ӥ��롼����
 *  
 *  ��SH1��¢��SCI�Ǥϳ�����ֹ椬�������̡�����ͥ��̤�ʬ����Ƥ���Τǡ�
 *  ��SCI0����������߰ʳ��Ǥ��Υ롼���󤬸ƤФ�뤳�ȤϤʤ�
 *  
 */
void
sh1sci_isr_out(void)
{
	if (siopcb_table[0].openflag) {
		sh1sci_isr_siop_out(get_siopcb(1));
	}
}

/*
 *  SIO��������ߥ����ӥ��롼����
 *  
 *  ��SH1��¢��SCI�Ǥϳ�����ֹ椬�������̡�����ͥ��̤�ʬ����Ƥ���Τǡ�
 *  ��SCI0�μ�������߰ʳ��Ǥ��Υ롼���󤬸ƤФ�뤳�ȤϤʤ�
 *  
 */
void
sh1sci_isr_in(void)
{
	if (siopcb_table[0].openflag) {
		sh1sci_isr_siop_in(get_siopcb(1));
	}
}

/*
 *  SIO�������顼����ߥ����ӥ��롼����
 *  
 *  ��SH1��¢��SCI�Ǥϳ�����ֹ椬����ͥ��̤�ʬ����Ƥ���Τǡ�
 *  ��SCI0�μ������顼����߰ʳ��Ǥ��Υ롼���󤬸ƤФ�뤳�ȤϤʤ�
 *  ��
 *  �����顼�������Τϥ��顼�ե饰�Υ��ꥢ�ΤߤˤȤɤ�Ƥ��롣
 *  �������������С���󥨥顼
 *  ���������ե졼�ߥ󥰥��顼
 *  ���������ѥ�ƥ����顼
 */
void
sh1sci_isr_error(void)
{
	VB ssr0;
	
	if (siopcb_table[0].openflag) {
		ssr0 = sil_reb_mem(SCI_SSR0);	/*  1���ɤ߽Ф���  */
		ssr0 &= ~(SSR_RDRF | SSR_ORER | SSR_FER | SSR_PER);
		sil_wrb_mem(SCI_SSR0, ssr0);	/*  ���顼�ե饰���ꥢ  */
	}
}

/*
 * �ݡ���󥰤ˤ��ʸ��������
 */
void
sh1sci_putc_pol(char c)
{
	while(!sh1sci_putready(&siopcb_table[0]));
	sh1sci_putchar(&siopcb_table[0], c);
}
