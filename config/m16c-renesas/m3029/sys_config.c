/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
 * 
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ��� 
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ����(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ�������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: sys_config.c,v 1.2 2006/08/03 04:14:02 honda Exp $
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���M3029�ѡ�
 */

#include "jsp_kernel.h"
#include <sil.h>
#include "m3029.h"

/*
 *  �������åȥ����ƥ��¸ ������롼����
 */

void
sys_initialize(void)
{
	VB * p;

	/* 
	 * ü�ҳ����������쥸�����ν����
	 * �������Ԥ��ޤǰ�����ü�Ҥ�ư��ʤ� 
	 */
	/* ��å���� */
	sil_wrb_mem((VP)(TADR_SFR_PRCR), TVAL_PACR_PRCR);
#ifdef PIN80 
	sil_wrb_mem((VP)(TADR_SFR_PACR), TVAL_80_PACR);
#else /* PIN64 */
	sil_wrb_mem((VP)(TADR_SFR_PACR), TVAL_64_PACR);
#endif
	/* ��å� */
	sil_wrb_mem((VP)(TADR_SFR_PRCR), 0x00);
		
	/* ����ȥ���#2�쥸�����ν���� */
	p = (VB*)TADR_SFR_UART0_BASE;
	sil_wrb_mem((VP)(p+TADR_SFR_UC2_OFFSET), 0x00);
	
#if CONSOLE_PORTID == 1
	p = (VB*)TADR_SFR_UART0_BASE;
#else	/* CONSOLE_PORTID == 2 */
	p = (VB*)TADR_SFR_UART1_BASE;
#endif	
	
	/* �������⡼�ɥ쥸�����ν���� */
	sil_wrb_mem((VP)(p+TADR_SFR_UMR_OFFSET), 0x05);	/* ��������ݥɥ쥸���� ��������å�,*/
													/* ��Ʊ����8�ӥåȡ��ѥ�ƥ��ʤ���	*/
													/* ���꡼�פʤ�						*/
	/* ��������쥸�����ν���� */
	sil_wrb_mem((VP)(p+TADR_SFR_UC0_OFFSET), 0x10);	/* ����������쥸����0 ����å�f1���� */
	/* ž��®�٥쥸�����ν���� (38400bps��32) */
	sil_wrb_mem((VP)(p+TADR_SFR_UBRG_OFFSET), 32);	/* ž��®�٥쥸����(19200bps)		*/
	/* ����������쥸�����ν���� */
	sil_wrb_mem((VP)(p+TADR_SFR_UC1_OFFSET), (TBIT_UiC1_TE | TBIT_UiC1_RE));
													/* ����������쥸������ ����������	*/

	/* �ݡ���0�ν���� */
	sil_wrb_mem((VP)TADR_SFR_P0, 0xff);				/* �ݡ���0�ǡ��������				*/
	sil_wrb_mem((VP)TADR_SFR_PD0, 0xff);			/* �ݡ���0��������					*/
}

/*
 *  �������åȥ����ƥ�ν�λ�롼����
 */

void
sys_exit(void)
{
  while (1)
  	;
}

void
sys_putc(char c)
{
	if(c == '\n'){
	    m3029_putc( '\r' );
	}
    m3029_putc( c );
}


