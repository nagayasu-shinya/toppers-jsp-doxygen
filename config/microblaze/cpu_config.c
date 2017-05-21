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
 *  @(#) $Id: cpu_config.c,v 1.4 2003/12/11 00:58:01 honda Exp $
 */

/*
 *  �ץ��å���¸�⥸�塼���Microblaze�ѡ�
 */
#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <microblaze.h>


/*
 * �����ߥϥ�ɥ�/�ӥåȥޥ����Υơ��֥�
 */
FP  int_handler_table[32];
UW  int_bit_table[32];

/*
 * CPU�㳰�ϥ�ɥ�ε����ơ��֥�
 * Not Support!
 */
/* FP	exc_table[(0x1E0 >> 5) + 1]; */


/*
 * �����ߤΥͥ��Ȳ���Υ������
 * �����ͥ뵯ư���ϥ�������Ω���Ȥߤʤ�����1�ǽ��������
 */
UW interrupt_count = 1;

/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize()
{
  int i;
    
  /*
   * int_handler_table[],int_plevel_table[]�ν����
   * ̤��Ͽ�γ����ȯ������cpu_interrup()���ƤӽФ����褦��
   * no_reg_interrup()����Ͽ����
   */
  for(i = 0; i < 32; i++){
    int_handler_table[i] = no_reg_interrupt;
    int_bit_table[i]  = 1 << i; /* �ӥåȥѥ���������� */
  }
  
  /*
   *  INTC��������
   */
  intc_start();
}



/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate()
{
}


/*
 * ��Ͽ����Ƥ��ʤ��㳰��ȯ������ȸƤӽФ����
 * Not Support! 
 */
/*
void
cpu_expevt(void)
{
}
*/

/*
 * ̤��Ͽ�γ���ߤ�ȯ���������˸ƤӽФ����
 * Not Yet!
 */
void
cpu_interrupt(void)
{
    syslog(LOG_EMERG, "Unregisted Interrupt Occur!");

    while(1);
}
