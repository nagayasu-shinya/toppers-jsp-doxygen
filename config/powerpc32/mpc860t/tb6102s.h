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
 *  @(#) $Id: tb6102s.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *  ����Хå���MPC860T CPU�ܡ���TB6102S
 *  �Υϡ��ɥ������񸻤����
 */

#ifndef _TB6102S_H_
#define _TB6102S_H_


/*
 *  ����ߴ�Ϣ�����
 */

/*  ̤����γ���ߤ��Ф���IPM�Υǥե������  */
#define DEFAULT_IPM	0x00	/*  ���٤Ƥγ���ߤ�ػ�  */

/*  CPM����SIU�ؤγ�����׵��٥�  */
	/*  CICR.IRL0�������͡ʥӥå�16-18��2�ʿ���  */
#define CICR_IRL0	(CPM_INT_LEVEL << (31 - 18))

/*  SIU���鸫��CPM�γ�����ֹ�  */
#define INHNO_CPM		LEVEL_TO_INHNO(CPM_INT_LEVEL)

/*  SIU���鸫��CPM�γ���ߵ��ĥӥå�  */
#define ENABLE_CPM		LEVEL_TO_ENABLE_BIT(CPM_INT_LEVEL)

/*  CPM����ߤ�IPM  */
#define IPM_CPM			LEVEL_TO_IPM(CPM_INT_LEVEL)


/*
 *  �����޴�Ϣ������
 *
 */
/* �����ޤγ����ߥ�٥��SIU��������٥�� */
#define INTLVL_PIT	INTLVL_TIMER


/*
 *  GDB STUB�ƽФ��롼�����̤������
 */
#ifndef _MACRO_ONLY
#ifdef GDB_STUB

#define tb6102s_exit	stub_exit
#define tb6102s_putc	stub_putc

Inline void
stub_exit(void)
{
}

Inline void
stub_putc(char c)
{
}

/*
 *  GDB stub��Ȥ�ʤ�����ROM���ѡ�
 */
#else /* GDB_STUB */

extern void	smc_putc_pol(char c);	/*  mpc860_smc.c  */

/*
 *  SIL�Υ�������������ǽ��ͭ���ˤ������
 */
#ifdef SIL_DEBUG

#define SIL_BUFFER_SIZE	10000
char sil_buffer[SIL_BUFFER_SIZE];
int sil_pos;
BOOL sil_debug_on;

Inline void
tb6102s_exit()
{
	int i;

	sil_debug_on = FALSE;
	
	/*  ��󥰥Хåե�����Ť���˥ǡ�����ɽ������  */
	for(i=sil_pos; i<SIL_BUFFER_SIZE; i++) {
		smc_putc_pol(sil_buffer[i]);
	}
	for(i=0; i<sil_pos; i++) {
		smc_putc_pol(sil_buffer[i]);
	}
	while(1);
}

Inline void 
tb6102s_putc(char c)
{
	++sil_pos;
	sil_pos %= SIL_BUFFER_SIZE;
	sil_buffer[sil_pos] = c;
}

#else	/* SIL_DEBUG */

Inline void
tb6102s_exit()
{
	while(1);
}

Inline void 
tb6102s_putc(char c)
{
	smc_putc_pol(c);
}

#endif	/* SIL_DEBUG */

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _TB6102S_H_ */
/*  end of file  */
