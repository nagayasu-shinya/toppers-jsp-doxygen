/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 *  �������åȥ����ƥ��¸�⥸�塼��(DMT33209)
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �����ͥ����������̾�Υ�͡���
 */

#include "sys_rename.h"

/*
 *  ��������¬���ѥ����ӥ�������򥵥ݡ��Ȥ��ʤ�
 */
#define OMIT_VGET_TIM

/*
 *  ��ư��å������Υ������å�̾
 */
#define TARGET_NAME	"EPSON S1C33 Standard Macro"

/*
 *  ���ݡ��Ȥ��륷�ꥢ��ǥ��Х����ο��Ϻ��� 1
 */
#define TNUM_PORT		1
#define LOGTASK_PORTID		1

/*
 *  ���ꥢ������ߤ�����/���Ϥǰۤʤ뤫�ɤ��������
 */
#define SEPARATE_SIO_INT

#include "s1c33.h"
#include "dmt33209.h"

#ifndef _MACRO_ONLY

/*
 *  �������åȥ����ƥ��¸�ν����
 */
extern void sys_initialize(void);

/*
 *  �������åȥ����ƥ�ν�λ
 *
 *  �����ƥ��λ������˻Ȥ���
 */
extern void sys_exit(void);

/*
 *  �������åȥ����ƥ��ʸ������
 *
 *  �����ƥ�����٥��ʸ�����ϥ롼����
 *
 */
extern void sys_putc(char c);

/*
 *  ���������쥸�����Υ��ե��åȰ��ּ���
 */
/*
 *  �����ߥץ饤����ƥ��쥸���������������
 */
Inline ER
get_Offset(INTNO intno)
{
	INT		iOffset;
	switch(intno)
	{
		case S1C33_INHNO_PINT0:			/* Key, Port0-3 group */
		case S1C33_INHNO_PINT1:
		case S1C33_INHNO_PINT2:
		case S1C33_INHNO_PINT3:
		case S1C33_INHNO_KINT0:
		case S1C33_INHNO_KINT1:
			iOffset = 0;
			break;

		case S1C33_INHNO_HSDMA0:		/* DMA group */
		case S1C33_INHNO_HSDMA1:
		case S1C33_INHNO_HSDMA2:
		case S1C33_INHNO_HSDMA3:
		case S1C33_INHNO_IDMA:
			iOffset = 1;
			break;

		case S1C33_INHNO_P16TIMER0B:		/* 16bit timer0/1 group */
		case S1C33_INHNO_P16TIMER0A:
		case S1C33_INHNO_P16TIMER1B:
		case S1C33_INHNO_P16TIMER1A:
			iOffset = 2;
			break;

		case S1C33_INHNO_P16TIMER2B:		/* 16bit timer2/3 group */
		case S1C33_INHNO_P16TIMER2A:
		case S1C33_INHNO_P16TIMER3B:
		case S1C33_INHNO_P16TIMER3A:
			iOffset = 3;
			break;

		case S1C33_INHNO_P16TIMER4B:		/* 16bit timer4/5 group */
		case S1C33_INHNO_P16TIMER4A:
		case S1C33_INHNO_P16TIMER5B:
		case S1C33_INHNO_P16TIMER5A:
			iOffset = 4;
			break;

		case S1C33_INHNO_P8TIMER0:		/* 8bit timer group */
		case S1C33_INHNO_P8TIMER1:
		case S1C33_INHNO_P8TIMER2:
		case S1C33_INHNO_P8TIMER3:
			iOffset = 5;
			break;

		case S1C33_INHNO_SERIAL0ERR:		/* Serial I/O group */
		case S1C33_INHNO_SERIAL0RX:
		case S1C33_INHNO_SERIAL0TX:
		case S1C33_INHNO_SERIAL1ERR:
		case S1C33_INHNO_SERIAL1RX:
		case S1C33_INHNO_SERIAL1TX:
			iOffset = 6;
			break;

		case S1C33_INHNO_AD:			/* A/DConv, clocktimer, */
		case S1C33_INHNO_CLKTIMER:		/* Port 4-7 group	*/
		case S1C33_INHNO_PINT4:
		case S1C33_INHNO_PINT5:
		case S1C33_INHNO_PINT6:
		case S1C33_INHNO_PINT7:
			iOffset = 7;
			break;

		default:
			iOffset = E_PAR;
	}

	return (iOffset);
}

/*
 *  ����������ӥåȰ����������
 */
Inline ER
get_BitFlag(INTNO intno)
{
	INT	iBitFlag;

	switch(intno)
	{
		case S1C33_INHNO_PINT0:			/* D0 group*/
		case S1C33_INHNO_HSDMA0:
		case S1C33_INHNO_P8TIMER0:
		case S1C33_INHNO_SERIAL0ERR:
		case S1C33_INHNO_AD:
			iBitFlag = 0x01;
			break;

		case S1C33_INHNO_PINT1:			/* D1 group*/
		case S1C33_INHNO_HSDMA1:
		case S1C33_INHNO_P8TIMER1:
		case S1C33_INHNO_SERIAL0RX:
		case S1C33_INHNO_CLKTIMER:
			iBitFlag = 0x02;
			break;

		case S1C33_INHNO_PINT2:			/* D2 group*/
		case S1C33_INHNO_HSDMA2:
		case S1C33_INHNO_P16TIMER0B:
		case S1C33_INHNO_P16TIMER2B:
		case S1C33_INHNO_P16TIMER4B:
		case S1C33_INHNO_P8TIMER2:
		case S1C33_INHNO_SERIAL0TX:
		case S1C33_INHNO_PINT4:
			iBitFlag = 0x04;
			break;

		case S1C33_INHNO_PINT3:			/* D3 group*/
		case S1C33_INHNO_HSDMA3:
		case S1C33_INHNO_P16TIMER0A:
		case S1C33_INHNO_P16TIMER2A:
		case S1C33_INHNO_P16TIMER4A:
		case S1C33_INHNO_P8TIMER3:
		case S1C33_INHNO_SERIAL1ERR:
		case S1C33_INHNO_PINT5:
			iBitFlag = 0x08;
			break;

		case S1C33_INHNO_KINT0:			/* D4 group*/
		case S1C33_INHNO_IDMA:
		case S1C33_INHNO_SERIAL1RX:
		case S1C33_INHNO_PINT6:
			iBitFlag = 0x10;
			break;

		case S1C33_INHNO_KINT1:			/* D5 group*/
		case S1C33_INHNO_SERIAL1TX:
		case S1C33_INHNO_PINT7:
			iBitFlag = 0x20;
			break;

		case S1C33_INHNO_P16TIMER1B:		/* D6 group*/
		case S1C33_INHNO_P16TIMER3B:
		case S1C33_INHNO_P16TIMER5B:
			iBitFlag = 0x40;
			break;

		case S1C33_INHNO_P16TIMER1A:		/* D7 group*/
		case S1C33_INHNO_P16TIMER3A:
		case S1C33_INHNO_P16TIMER5A:
			iBitFlag = 0x80;
			break;

		default:
			iBitFlag = E_PAR;
	}

	return (iBitFlag);
}

#endif /* _MACRO_ONLY */
#endif /* _SYS_CONFIG_H_ */
