/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Additional routine
 *
 *  Copyright (C) 2003 by SEIKO EPSON Corp, JAPAN
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
 */

#include "cpu_rename.h"

unsigned char WRITE_BUF[65];

/* buffer for simulated stdin, WRITE_BUF[0] is size (1-0x40, 0 means no data)
   WRITE_BUF[1-64] is buffer area for data, max 64 bytes
   used in write () */

unsigned char READ_BUF[65];

/* buffer for simulated stdin, READ_BUF[0] is size (1-0x40, 0 means EOF)
   READ_BUF[1-64] is buffer area for data, max 64 bytes
   used in read() */

static unsigned char READ_EOF; /* if 1: READ_BUFFER become EOF, 0: not EOF */

/*
 *  void _exit
 *	_exit execute inifinity loop.
 */

void _exit()
{
LOOP:
	goto LOOP;
}

/*
 *  void _init_sys
 *	_init_sys initialize read() and write() bffer area
 */

void init_sys()
{
	READ_EOF = 0;		/* not EOF */
	READ_BUF[0] = 0;	/* BUFFER is empty */
}

/*
 *  read
 *	Read() get and return required bytes with using simulated input.
 *	If EOF return 0.
 *	READ_FLASH: is break point label for stdin
 *	READ_BUF is buffer area for stdin
 */

int read (int fhDummy, char *psReadBuf, int iReadBytes)
{
	int iBytes;		/* data size written to psReadBuf */
	int iSize;		/* data size in READ_BUF */
	char *psBuf;		/* top of read buffer */
	static int iNdxPos;	/* current positon in READ_BUF*/

/* start */

	iBytes = 0;		/* no read now */
	psBuf = psReadBuf;

/* This loop repeat for each byte to copy READ_BUF to psReadBuf */

	for (;;)
	    {

/* if iReadByte become 0, return */

		if (iReadBytes == 0)	/* if required size become 0, return */
			return(iBytes);

/* if EOF, return 0 */

		if (READ_EOF == 1)
			return(iBytes);

/* if there is data, copy 1 byte */

		iSize = READ_BUF[0];
		if (iSize > 0 )
		    {
		    	*psBuf = READ_BUF[iNdxPos];
		    	psBuf++;
		    	iReadBytes--;
		    	iNdxPos++;
		    	iSize--;
			iBytes++;
		    	READ_BUF[0] = (unsigned char)(iSize & 0xff);
		    }

/* if no data, read 0-64 bytes from simulated input */

		else
		    {
			asm(".global READ_FLASH");
			asm("READ_FLASH:");	/* label for simulated stdin */
			if (READ_BUF[0] == 0)
				READ_EOF = 1;	/* if size is 0, EOF */
		    	iNdxPos = 1;	/* reset index position */
		    }
	    } /* back to for (;;) */
}

/*
 *  write
 *	write datas with using simulated stdout
 *	WRITE_FLASH: is break point label for stdout
 *      WRITE_BUF is buffer area for stdout
 */

int write (int fhDummy, char *psWriBuf, int iWriBytes)
{
	int iBytes;	/* remain data bytes waiting WRITE_BUF */
	int iSize;	/* data size to write to WRITE_BUF */
	int iCount;	/* counter to copy data to WRITE_BUF */

	iBytes = iWriBytes;

	for (;;){				/* repeat each 255 bytes */

/* if remain 0, return original size */

	if (iBytes == 0)		/* remain size become 0, so return */
		return(iWriBytes);

/* if remain > 64, write size is 64 */

	if (iBytes > 64)
	{				/* over 64 */
		iSize = 64;				/* 64 bytes to WRITE_BUF */
		iBytes = iBytes - 64;	/* remain data */
	}
	else
	{						/* not over 64 */
		iSize = iBytes;		/* under 64 bytes to WRITE_BUF */
		iBytes = 0;			/* no remain data */
	}

/* copy psWriBuf to WRITE_BUF */

	WRITE_BUF[0] = (unsigned char)(iSize & 0xff);	/* set size */
	for (iCount = 1 ; iCount <= iSize ; iCount++)
	{
		WRITE_BUF[iCount] = *psWriBuf;		/* copy data */
		psWriBuf++;
	}
	asm(".global WRITE_FLASH");
	asm("WRITE_FLASH:");		/* label for simulated stdout */

    }	/* back to for (;;) */

	return(iSize);
}

