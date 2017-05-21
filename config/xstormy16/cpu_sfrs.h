/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2003      by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2010 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�
 *  �����ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭�����
 *      ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ�����
 *      ��������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ����Ѽԥ�
 *      �˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ�����̵��
 *      �ڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ���
 *        �𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»��
 *      ����⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ��ޤ���
 *      �ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���ͳ�˴��
 *      �����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ���
 *  ��TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū���Ф�
 *  ��Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ�����������
 *  �ˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ����
 *  ��ʤ���
 */

/*
 *  Xstormy16����SFR�����
 */
#ifndef _CPU_SFRS_H_
#define _CPU_SFRS_H_
                                /*
                                 *  �����ߤ��㳰������
                                 */
#define __IL1L 0x7F02
#define __IL1H 0x7F03
#define __IL2L 0x7F04
#define __IL2H 0x7F05
#define __EXCPL 0x7f08
#define __EXCPH 0x7f09
                                /*
                                 *  �����ƥ९��å�������
                                 */
#define __OCR0 0x7F0A
#define __OCR1 0x7F0B
                                /*
                                 *  ��å��ɥå������ޡ�
                                 */
#define __WDTCR 0x7F0C
                                /*
                                 *  �١��������ޡ�
                                 */
#define __BTCR 0x7F0E
                                /*
                                 *  �����ޡ�0/1
                                 */
#define __T0LR 0x7F10
#define __T0HR 0x7F11
#define __T0CNT 0x7F12
#define __T0PR 0x7F13
#define __T1LR 0x7F14
#define __T1HR 0x7F15
#define __T1CNT 0x7F16
#define __T1PR 0x7F17
                                /*
                                 *  UART
                                 */
#define __U0CR 0x7f38
#define __U1CR 0x7f78
#define __UxCR_RUN 0x80
#define __UxCR_ORERR 0x40
#define __UxCR_BAUDRATE 0x20
#define __UxCR_PARITY 0x10
#define __UxCR_TXEMPTY 0x08
#define __UxCR_TXIE 0x04
#define __UxCR_RXREADY 0x02
#define __UxCR_RXIE 0x01
#define __UxTX_STOPBIT 0x0000

#endif /* _CPU_SFRS_H_ */
