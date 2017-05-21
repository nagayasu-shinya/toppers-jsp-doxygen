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
 *	�������åȥ����ƥ��¸�⥸�塼��
 *	(��)������������ITRON���SH1CPU�ܡ�����
 */
 
#include <s_services.h>
#include "kernel_id.h"

#include <sh1.h>
#include "sys_support.h"

/*
 *  TINET���ѻ�
 */
#ifdef	SUPPORT_INET4
#include <sh1_sil.h>
#include <tinet_sys_config.h>
/*
 *  NIC (RTL8019AS) �˴ؤ������
 *  TINET���ѻ�tinet_sys_config.h �ذ�ư���뤳��
 */
/*#define ED_BASE_ADDRESS	0x06000000	*/	/* NIC �Υ쥸�����١������ɥ쥹 */
/*#define INHNO_IF_ED		IRQ5		*/	/* IRQ5 */
/*#define ED_PRI		7		*/	/* ͥ����=7 */
/*#define ED_LEVEL0		0		*/	/* ����߶ػ�  */
/*#define ED_IPR		IPRB		*/	/* ͥ���٥쥸����̾ */
/*#define ED_IPR_SHIFT		8		*/	/* ͥ���٥쥸������ӥåȰ��� */
#endif	/* SUPPORT_INET4 */

/*
 *  ROMICE���Ѥ�NMI�ޤǤ�ROM�٥����ơ��֥��ΰ�
 */
#define ROMVECT_START	0			/* ROM�Υ٥����ơ��֥�ϣ����Ϥ��� 	*/
#define ROMVECT_SIZE	((NMI+1)*sizeof(FP))	/* ROM�Υ٥����ơ��֥륵���� 		*/

/*
 *  ���٥�Υ������åȥ����ƥ��¸�ν���� _hardware_init_hook
 *
 *  �������ȥ��åץ⥸�塼�����ǡ�����ν���������˸ƤӽФ���롥
 */
void
hardware_init_hook(void)
{
	/* WCR3:�������ȥ���ȥ���쥸������
	 * WPU=1    WAITü�ҥץ륢�å�
	 * A02LW=00 ���ꥢ0,2��1�ێݎ��ގ�������
	 * A6LW=00  ���ꥢ6  ��1�ێݎ��ގ�������
	 */
	sil_wrh_mem(BSC_WCR3, 0x8000); 
	
	/* BCR:�Х�����ȥ���쥸����
	 * DRANE=0   ���؎�1�ϳ����������
	 * IOE=0     ���؎�6�ϳ����������
	 * WARP=0    �Ɏ��ώَӎ��Ď�:���􎱎����������􎱎�������Ʊ���˹Ԥ�ʤ�
	 * RDDTY=0   RD����HI T1��50%
	 * BAS=0     WRH,WRL,A0����ͭ��
	 */
	sil_wrh_mem(BSC_BCR, 0x0000);
	
	/* WCR1:�������ȥ���ȥ���쥸������
	 * read cycle state��
	 * waitü�ҥ���ץ뤷�ʤ�
	 * RWx=0  ���ꥢ1,3,4,5,7 1���Î��ĸ���
	 * RWx=0  ���ꥢ0,2,6 1���Î���+�ێݎ��ގ������ġʷ�3���Î��ġ�
	 * WW1=1  ���ꥢ1����Ҏӎ� 2���Î���
	 */
	sil_wrh_mem(BSC_WCR1, 0x00ff);
	
	/* WCR2:�������ȥ���ȥ���쥸������
	 * DMA�ʤ��Τǽ���ͤΤޤ�
	 */
	sil_wrh_mem(BSC_WCR2, 0xffff); 
	
	/*
	 * �У����У½��ϥХåե������
	 */
	sil_wrh_mem(PA_DR, VAL_PA_DR);
	sil_wrh_mem(PB_DR, VAL_PB_DR); 

	/*
	 * �У������Ͻ������sys_support.h���ȡ�
	 */
	sil_wrh_mem(PFC_PACR1, VAL_PFC_PACR1);
	sil_wrh_mem(PFC_PACR2, VAL_PFC_PACR2);
                                        
	sil_wrh_mem(PFC_PAIOR, VAL_PFC_PAIOR);
                    
	sil_wrh_mem(PFC_PBCR1, VAL_PFC_PBCR1);
	sil_wrh_mem(PFC_PBCR2, VAL_PFC_PBCR2);
	sil_wrh_mem(PFC_PBIOR, VAL_PFC_PBIOR);

	sil_wrh_mem(PFC_CASCR, VAL_PFC_CASCR);

}

/*
 *  ���եȥ������Ķ����ä˥饤�֥��ˤ˰�¸����ɬ�פʽ�������� software_init_hook
 *
 *  �������ȥ��åץ⥸�塼�����ǡ������ͥ��ư�������˸ƤӽФ���롥
 */
#ifdef	PARTNER
void
software_init_hook(void)
{
	/*
	 *  ROMICE���ѻ���ROM�٥����ơ��֥��ž��
	 */
	extern FP vector_table[];
	memcpy(vector_table, ROMVECT_START, ROMVECT_SIZE);
}
#endif

/*
 *  NIC �ϡ��ɥ����������ߵ���
 *  TINET���ѻ�ɬ��
 */
#ifdef	SUPPORT_INET4
void
ed_ena_inter(void)
{
	SIL_PRE_LOC;
	SIL_LOC_INT();
	define_int_plevel(ED_IPR, ED_PRI, ED_IPR_SHIFT);// ͥ����=ED_PRI
	SIL_UNL_INT();
}

/*
 *  NIC �ϡ��ɥ����������߶ػ�
 *  TINET���ѻ�ɬ��
 */
void
ed_dis_inter(void)
{
	SIL_PRE_LOC;
	SIL_LOC_INT();
	define_int_plevel(ED_IPR, ED_LEVEL0, ED_IPR_SHIFT);// ͥ����=0
	SIL_UNL_INT();
}
#endif	/* SUPPORT_INET4 *//* end */

