/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by Advanced Data Controls, Corp
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
 *  @(#) $Id: hw_sysio.h,v 1.5 2003/12/24 07:24:40 honda Exp $
 */

#ifndef _HW_SYSIO_H_
#define _HW_SYSIO_H_


#include "integrator.h"

/*
 *  ���ꥢ��I/O�ݡ��Ȥν����
 */
Inline void
hw_sysio_initialize()
{
    /*disable interrupt*/
    sil_wrw_mem((VP)UART0_CR,~UCR_UARTEN);
    /*baud rate 38400*/
    sil_wrw_mem((VP)UART0_LCRM,ULCRM_38400);
    sil_wrw_mem((VP)UART0_LCRL,ULCRL_38400);
    /*8bits, 1Stop bit, no parity*/
    sil_wrw_mem((VP)UART0_LCRH,ULCRH_WLEN_8BIT);
    /*Clear all registers*/
    sil_wrw_mem((VP)UART0_ICR,0xff);
    /*enable interrupt*/
    sil_wrw_mem((VP)UART0_CR,UCR_UARTEN | UCR_RIE);
}


/*
 *  ���ꥢ��I/O�ݡ��Ȥν�λ
 */
Inline void
hw_sysio_terminate()
{
    /*disable interrupt*/
    sil_wrw_mem((VP)UART0_CR,~UCR_UARTEN);
}


/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
hw_sysio_putready()
{
    return((sil_rew_mem((VP)UART0_FR) & UFR_BUSY)==0);
}


/*
 *  ��������ʸ���ν񤭹���
 */
Inline void
hw_sysio_putchar(UB c)
{
    while(!hw_sysio_putready())
        ;
    sil_wrw_mem((VP)UART0_DR,c);
}

#endif /* _HW_SYSIO_H_ */
