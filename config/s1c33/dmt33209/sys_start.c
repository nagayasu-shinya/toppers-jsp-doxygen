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
 *  �����ͥ��ѤΥ������ȥ��åץ⥸�塼��(S1C33��)
 */

#include "jsp_kernel.h"
#include "sys_config.h"
#include "cpu_config.h"

/*
 *  �����ؿ��λ���
 */
extern void init_lib(void);
extern void init_sys(void);

extern void INT_ENTRY(timer_handler)(void);
extern void INT_ENTRY(sio_in_handler)(void);
extern void INT_ENTRY(sio_out_handler)(void);

/*
 *  �ץ�ȥ��������
 */
void start(void);
static void undef_handler(void);
static void hardware_init_hook(void);
static void software_init_hook(void);

/*
 *  �٥������ơ��֥�
 */
VP tps_VectorTable[] = {		/* offset   number */
	(VP) start,			/* 00  Reset                    */
	(VP) undef_handler,		/* 01                           */
	(VP) undef_handler,		/* 02                           */
	(VP) undef_handler,		/* 03                           */
	(VP) undef_handler,		/* 04  Zero division            */
	(VP) undef_handler,		/* 05                           */
	(VP) undef_handler,		/* 06  Address error exception  */
	(VP) undef_handler,		/* 07  debug                    */
	(VP) undef_handler,		/* 08  NMI                      */
	(VP) undef_handler,		/* 09                           */
	(VP) undef_handler,		/* 10                           */
	(VP) undef_handler,		/* 11                           */
	(VP) undef_handler,		/* 12  Software exception 0     */
	(VP) undef_handler,		/* 13  Software exception 1     */
	(VP) undef_handler,		/* 14  Software exception 2     */
	(VP) undef_handler,		/* 15  Software exception 3     */
	(VP) undef_handler,		/* 16 (00)                      */
	(VP) undef_handler,		/* 17 (01)                      */
	(VP) undef_handler,		/* 18 (02)                      */
	(VP) undef_handler,		/* 19 (03)                      */
	(VP) undef_handler,		/* 20 (04)                      */
	(VP) undef_handler,		/* 21 (05)                      */
	(VP) undef_handler,		/* 22 (06)                      */
	(VP) undef_handler,		/* 23 (07)                      */
	(VP) undef_handler,		/* 24 (08)                      */
	(VP) undef_handler,		/* 25 (09)                      */
	(VP) undef_handler,		/* 26 (10)                      */
	(VP) undef_handler,		/* 27 (11)                      */
	(VP) undef_handler,		/* 28 (12)                      */
	(VP) undef_handler,		/* 29 (13)                      */
	(VP) undef_handler,		/* 30 (14)                      */
	(VP) undef_handler,		/* 31 (15)                      */
	(VP) undef_handler,		/* 32 (16)                      */
	(VP) undef_handler,		/* 33 (17)                      */
	(VP) INT_ENTRY(timer_handler),	/* 34 (18) 16 bit programable timer 1-b */
	(VP) undef_handler,		/* 35 (19)                      */
	(VP) undef_handler,		/* 36 (20)                      */
	(VP) undef_handler,		/* 37 (21)                      */
	(VP) undef_handler,		/* 38 (22)                      */
	(VP) undef_handler,		/* 39 (23)                      */
	(VP) undef_handler,		/* 40 (24)                      */
	(VP) undef_handler,		/* 41 (25)                      */
	(VP) undef_handler,		/* 42 (26)                      */
	(VP) undef_handler,		/* 43 (27)                      */
	(VP) undef_handler,		/* 44 (28)                      */
	(VP) undef_handler,		/* 45 (29)                      */
	(VP) undef_handler,		/* 46 (30)                      */
	(VP) undef_handler,		/* 47 (31)                      */
	(VP) undef_handler,		/* 48 (32)                      */
	(VP) undef_handler,		/* 49 (33)                      */
	(VP) undef_handler,		/* 50 (34)                      */
	(VP) undef_handler,		/* 51 (35)                      */
	(VP) undef_handler,		/* 52 (36)                      */
	(VP) undef_handler,		/* 53 (37)                      */
	(VP) undef_handler,		/* 54 (38)                      */
	(VP) undef_handler,		/* 55 (39)                      */
	(VP) undef_handler,		/* 56 (40) Serial interface Ch.0 (error) */
	(VP) INT_ENTRY(sio_in_handler),	/* 57 (41) Serial interface Ch.0 (rx) */
	(VP) INT_ENTRY(sio_out_handler),/* 58 (42) Serial interface Ch.0 (tx) */
	(VP) undef_handler,		/* 59 (43)                      */
	(VP) undef_handler,		/* 60 (44)                      */
	(VP) undef_handler,		/* 61 (45)                      */
	(VP) undef_handler,		/* 62 (46)                      */
	(VP) undef_handler,		/* 63 (47)                      */
	(VP) undef_handler,		/* 64 (48)                      */
	(VP) undef_handler,		/* 65 (49)                      */
	(VP) undef_handler,		/* 66 (50)                      */
	(VP) undef_handler,		/* 67 (51)                      */
	(VP) undef_handler,		/* 68 (52)                      */
	(VP) undef_handler,		/* 69 (53)                      */
	(VP) undef_handler,		/* 70 (54)                      */
	(VP) undef_handler,		/* 71 (55)                      */
};

/*
 *  �֡��ȥ롼����
 *  Boot routine
 */
void start(void)
{
	/*
	 *  �ǥե���ȥǡ������ꥢ���ɥ쥹�����ꤹ��
	 */
	Asm("xld.w %r15, __dp");

	/*
	 *  �󥿥�������ƥ��ȤΥ����å���STACKTOP�˽��������
	 */
	set_sp(STACKTOP);

	/*
	 * PSR���������������ߤ�ػߤ���
	 */
	set_psr(0x00000000);


	/*
	 *  hardware_init_hook ��ƤӽФ���(0�Ǥʤ����)
	 *
	 *  �ϡ��ɥ�������¸��ɬ�פʽ����������������ϡ�
	 *  hardware_init_hook �Ȥ����ؿ����Ѱդ���Ф褤��
	 *  ����Ū�ˤ�ROM���κݡ�RAM����Ѳ�ǽ�ˤ��뤿���
	 *  �Х�����ȥ���ν��������Ԥ���
	 *  sys_config.c ��� hardware_init_hook ��������Ƥ��롥
	 */
	if (hardware_init_hook != (VP) 0) {
		hardware_init_hook();
	}

	/*
	 *  data�������������������ROM���б��ˡ�
	 */
	memcpy(VECTOR_START, IVECTOR_START, (UW)IVECTOR_END - (UW)IVECTOR_START);
	memcpy(DATA_START, IDATA_START, (UW)IDATA_END - (UW)IDATA_START);

	/*
	 *  bss����������0���ꥢ���롣
	 */
	 memset(BSS_START, 0x00, BSS_END - BSS_START);

	/*
	 *  software_init_hook ��ƤӽФ���0 �Ǥʤ�����
	 *
	 *  ���եȥ������Ķ����ä˥饤�֥��ˤ˰�¸����ɬ�פʽ������
	 *  ����������ϡ�software_init_hook �Ȥ����ؿ����Ѱդ����
	 *  �褤��
	 */
	if (software_init_hook != (VP) 0) {
		software_init_hook();
	}

	/*
	 *  �����ͥ��ư����
	 */
	Asm("xjp kernel_start");

	do {
		Asm("halt");
	} while (TRUE);
}

/*
 *  ���ߡ��롼����
 */
static void undef_handler(void)
{
	while(1){
		;
	}
}

/*
 *  �����ƥ��¸�ν��������
 */
static	void	hardware_init_hook(void)
{
	(*(s1c33Bcu_t *) S1C33_BCU_BASE).bTtbrProt = (IOREG)0x59;
	(*(s1c33Bcu_t *) S1C33_BCU_BASE).ulTtbr = (LIOREG)tps_VectorTable;

	return;
}


/*
 *  ���եȥ�������¸�ν��������
 */
static	void	software_init_hook(void)
{
	init_lib();
	init_sys();
}
