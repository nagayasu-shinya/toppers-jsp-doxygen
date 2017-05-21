/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

#include <jsp_kernel.h>
#include <hw_serial.h>

/*
 *  �������åȥ����ƥ��¸ ������롼����
 */
void
sys_initialize()
{

#ifndef GDB_STUB

	/*
	 * �⥸�塼�륹�ȥåץ⡼�ɲ��
	 */
#if TNUM_SIOP < 2
	h8s_andh( (VP) MSTPCR, ~( BIT5 ) );
#else /* TNUM_SIOP < 2 */
	h8s_andh( (VP) MSTPCR, ~( BIT6 | BIT5 ) );
#endif /* TNUM_SIOP < 2 */

	/*
	 *  �Хʡ�ɽ���ѥ��ꥢ��ݡ��Ȥν����
	 */
	sio_init();

#endif /* GDB_STUB */

}

/*
 *  �������åȥ����ƥ�ν�λ�롼����
 */
void
sys_exit(void)
{
	while (1);
}


/*
 *  GDB STUB / ľ�ܸƽФ� ���󥽡���ƽФ��롼����
 */

/* er0 ��0, er1 �˽��Ϥ�����ʸ�������� trapa #1 ��¹Ԥ��� */
void
stub_putc(char c)
{
	/* er0 = c */
	Asm("push.l	er1");
	Asm("mov.l	er0, er1");
	Asm("sub.l	er0, er0");
	Asm("trapa	#1");
	Asm("pop.l	er1");
}

#ifdef GDB_STUB
#define h8s_putc(c)	stub_putc(c)		/* GDB�����֤Υ����ƥॳ������� */
#else  /* GDB_STUB */
#define	h8s_putc(c)	sio_snd_chr_pol(c)	/* ���ꥢ��ݡ��ȤؤΥݡ���󥰽��� */
#endif /* GDB_STUB */

/*   print_banner()  */
void
sys_putc(char c)
{
	if (c == '\n') {
		h8s_putc('\r');
	}
	h8s_putc(c);
}
