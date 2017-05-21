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
 *  �ץ��å���¸�⥸�塼���Xstormy16�ѡ�
 */

#include "jsp_kernel.h"
#include <s_services.h>
#include <hw_timer.h>
#include <hw_serial.h>
#include <cpu_sfrs.h>

/*
 *  ������ƥ��å��μ���
 */
UINT _kernel_tic_nume = 1u ;

/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize(void)
{
                                /*
                                 *  �㳰�ε���
                                 */
    __UNLOCK_EXCP() ;               /* unlock writing EXCPL/EXCPH */
    __SFR_BITSET( __EXCPL, 0 ) ;    /* enable invalid instruction exception */
    __SFR_BITSET( __EXCPL, 2 ) ;    /* enable odd/word access exception */
    __SFR_BITSET( __EXCPL, 4 ) ;    /* enable outrange access exception */
    __LOCK_EXCP() ;                 /* lock writing EXCPL/EXCPH */
                                /*
                                 *  �����ͥ륿���ޡ��ε�ư
                                 */
    hw_timer_initialize() ;
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate(void)
{
                                /*
                                 *  �����ͥ륿���ޡ������
                                 */
    hw_timer_terminate() ;
                                /*
                                 *  �㳰�ζػ�
                                 */
    __UNLOCK_EXCP() ;               /* unlock writing EXCPL/EXCPH */
    __SFR_BITCLR( __EXCPL, 0 ) ;    /* disable invalid instruction exception */
    __SFR_BITCLR( __EXCPL, 2 ) ;    /* disable odd/word access exception */
    __SFR_BITCLR( __EXCPL, 4 ) ;    /* disable outrange access exception */
    __LOCK_EXCP() ;                 /* lock writing EXCPL/EXCPH */
}

/*
 *  �����ߥϥ�ɥ����Ͽ
 */
void _kernel_define_inh(INHNO inhno, FP inthdr)
{
    extern FP _kernel_ih_table[TNUM_INTERRUPT] ;
    if ( inhno < TNUM_INTERRUPT ) {
        _kernel_ih_table[inhno] = inthdr ;
    }
}

/*
 *  �㳰�ϥ�ɥ����Ͽ
 */
void _kernel_define_exc(EXCNO excno, FP exchdr)
{
    extern FP _kernel_eh_table[TNUM_EXCEPTION] ;
    if ( excno < TNUM_EXCEPTION ) {
        _kernel_eh_table[excno] = exchdr ;
    }
}

/*
 *  �������åȥ����ƥ��ʸ������
 */
void sys_putc(char c)
{
    sio_asnd_chr( (INT)c ) ;
}

/*
 *  ���������Ԥ�
 */
void sil_dly_nse( UINT dlytim )
{
    UINT n ;
    for ( n = 3 ; n < dlytim ; n++ ) __asm__ volatile ( "nop" ) ;
}

