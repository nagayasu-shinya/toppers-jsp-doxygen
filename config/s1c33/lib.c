/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
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
#include	"smcvals.h"
#include	"stdio.h"
#include	"cpu_rename.h"

FILE	_iob[FOPEN_MAX + 1];		/* standard i/o stream */

FILE	*stdin; 			/* standard input */
FILE	*stdout;			/* standard output */
FILE	*stderr;			/* standard error */

int 	errno;				/* error number */

unsigned int  seed; 			/* seed of random value */

unsigned char *ucNxtAlcP;	/* next memory allocate address */
unsigned char *ucBefAlcP;	/* one previous allocated address */
unsigned char *end_alloc;	/* end memory allocate address */

#ifndef DBL_LNG_TYPE

#define DBL_LNG_TYPE

/*  the architecture of double floating point
 *
 *   0 1          11                  31 32                               63 bit
 *   -----------------------------------------------------------------------
 *  | |   exponent  |                    fraction                           |
 *   -----------------------------------------------------------------------
 *
 *  |               |                   |                                   |
 *  |     12bits          20 bits       |             32 bits               |
 *  |            lower word             |            higher word            |
 *
 *         bit    0         sign bit         (  1 bit  )
 *              1 - 11      exponent part    ( 11 bits )
 *             12 - 63      fraction part    ( 52 bits )
 *
 */

typedef union {
		struct {
#ifdef	BIG_ENDIAN
			unsigned long _LL;
			unsigned long _LH;
#else
			unsigned long _LH;
			unsigned long _LL;
#endif
		} st;
	} DBL_LNG;

#endif

DBL_LNG _HUGE;				/* HUGE VALUE */

unsigned char *_STACK_TOP;		/* address of stack top */
unsigned char *_STACK_BOTTOM;		/* address of stack bottom */

long gm_sec;

/*
 * initialize routine
 */

void init_lib()
{

  /* initialize allocate address */
  end_alloc = (unsigned char *)_STACK_TOP;
  ucNxtAlcP = (unsigned char *)(_BOUND((unsigned long)_STACK_BOTTOM));
  ucBefAlcP = (unsigned char *)NULL;

  errno = 0;				/* clear error number */

  seed = 1; 				/* initialize random seed */

  gm_sec = -1;				/* initialize time */

  _HUGE.st._LL = 0x7ff00000;		/* HUGE VALUE */
  _HUGE.st._LH = 0;

/*
 *  INITIALIZE STANDARD STREAMS
 */

  _iob[0]._flg = _UGETN;		/* initialize stdin stream */
  _iob[0]._buf = 0;
  _iob[0]._fd = 0;

  _iob[1]._flg = _UGETN;		/* initialize stdout stream */
  _iob[1]._buf = 0;
  _iob[1]._fd = 1;

  _iob[2]._flg = _UGETN;		/* initialize stderr stream */
  _iob[2]._buf = 0;
  _iob[2]._fd = 2;

  stdin = &_iob[0];
  stdout = &_iob[1];
  stderr = &_iob[2];

}

