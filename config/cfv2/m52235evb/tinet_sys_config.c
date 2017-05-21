/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2001-2006 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
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
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: $
 */

/*
 *  JSP-1.4.2 �ʹߤ��ѹ����줿����ߥϥ�ɥ�ؤ��б�
 */

#include <s_services.h>
#include <t_services.h>
#include "kernel_id.h"

#include <tinet_defs.h>
#include <tinet_config.h>

/*
 *  fec_inter_init -- �������åȰ�¸���γ���ߤν����
 */

int
memcmp(const void* s1, const void* s2, int n) {
  char* a1 = (char*)s1;
  char* a2 = (char*)s2;
  
  while (n--)
    if (*a1++ != *a2++)
      return *(a1 - 1) - *(a2 - 1);
  return 0;
}


void*
memset(char *s, int c, int n) 
{
  char* p = s;
  while (n--) {
    *p++=c;
  }
  return s;
}


void*
memcpy(void* dest, void* src, int n) {
  char *p1 = dest;
  const char *p2 = src;
  int i;

  for (i = 0; i < n; i++) {
    *(p1++) = *(p2++);
  }

  return dest;
}

void *
memmove (void *d, void *s, int n)
{
    char *dst = d;
    char *src = s;
    void *ret = dst;

    if (src < dst) {
	src += n;
	dst += n;
	while (n--)
	    *--dst = *--src;
    }
    else if (dst < src)
	while (n--)
	    *dst++ = *src++;
    return ret;
}

#if TKERNEL_PRVER >= 0x1042u	/* JSP-1.4.2 �ʹ� */

/*
 * fec_dis_inter -- ����ߤ�ػߤ��롣
 */
IPM
fec_dis_inter(void)
{
  IPM	ipm;
  
  syscall(get_ipm(&ipm));
  syscall(chg_ipm(if_fec_handler_intmask));
  return ipm;
}

/*
 *  fec_bus_init -- �������åȰ�¸���ΥХ��ν����
 */

void
fec_bus_init (void)
{
}

/*
 *  fec_inter_init -- �������åȰ�¸���γ���ߤν����
 */

void
fec_inter_init (void)
{
  int i;
  /* NIC �γ����ߤ���Ĥ��롣*/
  for (i = TBIT_FEC_XINF; i <= TBIT_FEC_BABR; i++) {
    sil_wrb_mem (MCF_INTC_ICR(MCF_INTC0, i), ((FEC_INT_LEVEL) << 3) | (FEC_INT_PRI));
    if (i < 32)
      sil_wrw_mem (MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRL(MCF_INTC0)) & (~(1 << i)));
    else
      sil_wrw_mem (MCF_INTC_IMRH(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRH(MCF_INTC0)) & (~(1 << (i-32))));
  }
}

#endif	/* of #if TKERNEL_PRVER >= 0x1042u */
