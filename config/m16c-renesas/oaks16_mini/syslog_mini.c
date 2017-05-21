/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id: syslog_mini.c,v 1.3 2005/11/24 12:41:23 honda Exp $
 */

/*
 *  �����ƥ����ǽ��ά��
 */

#undef OMIT_SYSLOG
#include "jsp_kernel.h"
#include "time_event.h"
#include "serial.h"

/*
 *  ���Ϥ��٤�������ν����١ʥӥåȥޥåס�
 */
static UINT	syslog_logmask;		/* ��Ͽ�����Ϥ��٤������� */
static UINT	syslog_lowmask;		/* ���٥���Ϥ��٤������� */

/*
 *  �����ƥ����ǽ�ν����
 */
void syslog_initialize(void)
{
	syslog_logmask = LOG_UPTO(LOG_NOTICE);
	syslog_lowmask = LOG_UPTO(LOG_NOTICE);
}

/* 
 *  ������ν���
 */
SYSCALL ER
vwri_log(UINT prio, SYSLOG *p_log)
{
	BOOL	locked;

	p_log->logtim = systim_offset + current_time;
	if ((syslog_logmask & LOG_MASK(prio)) != 0) {
		/*
	 	*  ���٥���Ϥؤν�Ф�
	 	*/
		syslog_print(p_log, sys_putc);
		sys_putc('\n');
	}
	return(E_OK);
}

/* 
 *  ���Ϥ��٤�������ν����٤�����
 */
SYSCALL ER
vmsk_log(UINT logmask, UINT lowmask)
{
	syslog_logmask = logmask;
	syslog_lowmask = lowmask;
	return(E_OK);
}

/* 
 *  �����ƥ����ǽ�ν�λ����
 *
 *  ���Хåե��˵�Ͽ���줿����������٥���ϵ�ǽ���Ѥ��ƽ��Ϥ�
 *  �롥
 */
void
syslog_terminate(void){}

/*
 *  ���ͤ�ʸ������Ѵ�
 */
static void
convert(unsigned long val, int radix, const char *radchar, int width,
		int minus, int padzero, void (*putc)(char))
{
	char	buf[12];
	int	i, j;

	i = 0;
	do {
		buf[i++] = radchar[val % radix];
		val /= radix;
	} while (val != 0);

	width -= minus;
	if (minus > 0 && padzero > 0) {
		(*putc)('-');
	}
	for (j = i; j < width; j++) {
		(*putc)((char)(padzero > 0 ? '0' : ' '));
	}
	if (minus > 0 && padzero <= 0) {
		(*putc)('-');
	}
	while (i > 0) {
		(*putc)(buf[--i]);
	}
}

/*
 *  ������ե����ޥå��ѥ饤�֥��ؿ�
 */
static char const raddec[] = "0123456789";
static char const radhex[] = "0123456789abcdef";
static char const radHEX[] = "0123456789ABCDEF";

void
syslog_print(SYSLOG *p_syslog, void (*putc)(char))
{
	char const	*format;
	int	argno;
	int	c;
	int	width;
	int	padzero;
	long	val;
	char const	*str;

	format = (char const *)(p_syslog->loginfo[0]);
	argno = 1;

	while ((c = *format++) != '\0') {
		if (c != '%') {
			(*putc)((char) c);
			continue;
		}

		width = padzero = 0;
		if ((c = *format++) == '0') {
			padzero = 1;
			c = *format++;
		}
		while ('0' <= c && c <= '9') {
			width = width*10 + c - '0';
			c = *format++;
		}
		switch (c) {
		case 'd':
			val = (long)(p_syslog->loginfo[argno++]);
			if (val >= 0) {
				convert(val, 10, raddec, width,
						0, padzero, putc);
			}
			else {
				convert(-val, 10, raddec, width,
						1, padzero, putc);
			}
			break;
		case 'u':
			val = (long)(p_syslog->loginfo[argno++]);
			convert(val, 10, raddec, width, 0, padzero, putc);
			break;
		case 'x':
			val = (long)(p_syslog->loginfo[argno++]);
			convert(val, 16, radhex, width, 0, padzero, putc);
			break;
		case 'X':
			val = (long)(p_syslog->loginfo[argno++]);
			convert(val, 16, radHEX, width, 0, padzero, putc);
			break;
		case 'c':
			(*putc)((char)(int)(p_syslog->loginfo[argno++]));
			break;
		case 's':
			str = (char const *)(p_syslog->loginfo[argno++]);
			while ((c = *str++) != '\0') {
				(*putc)((char) c);
			}
			break;
		case '%':
			(*putc)('%');
			break;
		case '\0':
			format--;
			break;
		default:
			break;
		}
	}
}

