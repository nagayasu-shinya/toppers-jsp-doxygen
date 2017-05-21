/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2010 by Witz Corporation, JAPAN
 * 
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 * 
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 * 
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 * 
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 * 
 *    (a) The above copyright notice, this use conditions, and the
 *           disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 * 
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 * 
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�
 *  �����ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭�����
 *      ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ�����
 *      ��������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ����Ѽԥ�
 *      �˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ�����̵��
 *      �ڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ���
 *        �𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»��
 *      ����⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ��ޤ���
 *      �ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���ͳ�˴��
 *      �����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ���
 *  ��TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū���Ф�
 *  ��Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ�����������
 *  �ˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ����
 *  ��ʤ���
 * 
 *  @(#) $Id: sys_config.c,v 1.1 2006/04/10 08:19:25 honda Exp $
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���Zup-F16��ĥ�ܡ����ѡ�
 */


#include "jsp_kernel.h"
#include <sil.h>
#include <tmp91cy22.h>
#include "hw_serial.h"


/* �����ƥ��������ե饰 */
BOOL	log_io_busy;

/*
 *  �������åȥ����ƥ��¸ ������롼����
 */

void
sys_initialize()
{
	/*
	 *  �Хʡ�ɽ���ѥ��ꥢ��ݡ��Ȥν����
	 *
	 *  �����Хåե����ե饰��̵�����ݡ���󥰤ˤ�����������μ�����
	 *  �Ǥ��ʤ����ᡤ������λ������׵�ե饰��ݡ���󥰤����������
	 *  �Ѥ˥����ƥ��������ե饰���Ѥ��롥
	 */
	/* �����ƥ��������ե饰����� */
	log_io_busy = FALSE;

	/* ���ꥢ��I/O�ɥ饤�н����	*/
	/* �������	*/
	sil_wrb_mem((VP)(TADR_SFR_SC1MOD0), 0x00 );
	/* �ݡ�������(TXD1)�Ȥ��ƻ���	*/
	sil_wrb_mem((VP)(TADR_SFR_P9FC), 0x08 );
	sil_wrb_mem((VP)(TADR_SFR_P9CR), 0x08 );
	/* ư��⡼������	*/
	sil_wrb_mem((VP)(TADR_SFR_SC1MOD0), (VB)(TBIT_SIOSMU8 | TBIT_SIOSCBRG) );
							/* 8bitUART�⡼��,�ܡ��졼�ȥ����ͥ졼������	*/
	sil_reb_mem((VP)(TADR_SFR_SC1CR));	/* �ɽФ��ˤ�ꥨ�顼�ե饰���ꥢ	*/
	sil_wrb_mem((VP)(TADR_SFR_SC1CR), 0x00 );	/* �ѥ�ƥ�̵��	*/
	sil_wrb_mem((VP)(TADR_SFR_BR1CR), (VB)BRCR_19200);
							/* ��T2����,19200bps,������ǽ̤����	*/
	sil_wrb_mem((VP)(TADR_SFR_BR1ADD), BRADD_19200);
	sil_wrb_mem((VP)(TADR_SFR_SC1MOD1), TBIT_SIOI2S);

	/* ���ꥢ�������׵�ե饰���ꥢ	 */
	sil_wrb_mem((VP)(TADR_SFR_INTCLR), TBIT_TX1_CLR );	/* �����׵᥯�ꥢ	*/

	/* LED�����	*/
	sil_wrb_mem((VP)(TADR_SFR_PA), 0xff );
	sil_wrb_mem((VP)(TADR_SFR_PAFC), 0x00 );
	sil_wrb_mem((VP)(TADR_SFR_PACR), 0xff );

}

/*
 *  �������åȥ����ƥ�ν�λ�롼����
 */

void
sys_exit(void)
{
  while(1);
}

/*
 *  �����ƥ����ʸ�������ؿ�
 *
 *  �ܴؿ���CPU��å�����(����߶ػ�)�Ǽ¹Ԥ��뤳��
 */
void
sys_putc(char c)
{
	/* ���ԥ����ɤξ�����'\r'������	*/
	if(c == '\n'){
		if( log_io_busy == TRUE ){
			/* ����������ξ��ϳ�����׵�ե饰��ݡ����	*/
			while( (sil_reb_mem((VP)(TADR_SFR_INTES1)) & TBIT_INTC_H) == 0 );
			sil_wrb_mem((VP)TADR_SFR_INTCLR, (TBIT_TX1_CLR) );	/* �����׵᥯�ꥢ	*/
			sil_wrb_mem((VP)(TADR_SFR_SC1BUF), '\r');
		}
		else{
			/* �������֤ˤ���ʸ��������	*/
			log_io_busy = TRUE;
			sil_wrb_mem((VP)(TADR_SFR_SC1BUF), '\r');
		}
	}
	if( log_io_busy == TRUE ){
		/* ����������ξ��ϳ�����׵�ե饰��ݡ����	*/
		while( (sil_reb_mem((VP)(TADR_SFR_INTES1)) & TBIT_INTC_H) == 0 );
		sil_wrb_mem((VP)TADR_SFR_INTCLR, (TBIT_TX1_CLR) );	/* �����׵᥯�ꥢ	*/
		sil_wrb_mem((VP)(TADR_SFR_SC1BUF), c);
	}
	else{
		/* �������֤ˤ���ʸ��������	*/
		log_io_busy = TRUE;
		sil_wrb_mem((VP)(TADR_SFR_SC1BUF), c);
	}
}



