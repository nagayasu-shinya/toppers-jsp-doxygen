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
 *  ���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�Xstormy16�ѡ�
 */

#include <kernel.h>
#include <s_services.h>
#include <hw_serial.h>
#include <cpu_sfrs.h>

/*
 *  ��Ʊ�������Ǥ�TxReady�Υ����ॢ����
 */
#define TXREADY_TIMEOUT 400

/*
 *  SIOPCB*�����å��Τ���Υޥ��å���
 */
#define MAGIC_SIOPCB 0xabcd

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
static SIOPCB siopcb_table[TNUM_PORT] = {
    { MAGIC_SIOPCB, __U0CR, 0x1400 },
    { MAGIC_SIOPCB, __U1CR, 0x4800 },
} ;

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void sio_initialize(void)
{
    /* nothing to do here */
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *sio_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB* siopcb ;
    UH uhBase ;
                                /*
                                 *  �����ץ�����ݡ��Ȥ��Υ����å�
                                 */
    if ( siopid < 1 || siopid > TNUM_PORT ) return NULL ;
    siopcb = &siopcb_table[siopid-1] ;
    if ( siopcb->bNotExist ) return NULL ;
                                /*
                                 *  ���˥����ץ�Ѥߤξ��
                                 */
    if ( siopcb->bOpened ) {
        siopcb->vpiExinf = exinf ;
        return siopcb ;
    }
                                /*
                                 *  SIO�ν������¸�ߤΥ����å�
                                 */
    uhBase = siopcb->uhBase ;
    __SFR(uhBase) = __UxCR_RUN|__UxCR_TXEMPTY ;
    if ( ( __SFR(uhBase) &
        ( __UxCR_RUN|__UxCR_BAUDRATE|__UxCR_PARITY|__UxCR_TXIE|
        __UxCR_RXIE) ) != __UxCR_RUN ) {
        siopcb->bNotExist = TRUE ;
        return NULL ;
    }
                                /*
                                 *  �����ơ��֥�ν����
                                 */
    siopcb->vpiExinf = exinf ;
    siopcb->bOpened = TRUE ;
    siopcb->bTxIe = FALSE ;
    siopcb->bRxIe = FALSE ;
    siopcb->bLastIsCr = FALSE ;
                                /*
                                 *  �����ߥϥ�ɥ����Ͽ�ȵ���
                                 */
    define_inh( INHNO_SIO, sio_handler ) ;
    __UNLOCK_EXCP() ;
    __SFRW(__EXCPL) |= siopcb->uhExcpMask ;
    __LOCK_EXCP() ;
    return siopcb ;
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void sio_cls_por(SIOPCB *siopcb)
{
                                /*
                                 *  �����������ݡ��Ȥ��Υ����å�
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return ;
                                /*
                                 *  �����ơ��֥���ѹ�
                                 */
    siopcb->bOpened = FALSE ;
                                /*
                                 *  �����ߤζػ�
                                 */
    __UNLOCK_EXCP() ;
    __SFRW(__EXCPL) &= ~siopcb->uhExcpMask ;
    __LOCK_EXCP() ;
                                /*
                                 *  SIO�����
                                 */
    __SFR(siopcb->uhBase) = 0 ;
}

/*
 *  SIO�γ���ߥϥ�ɥ�
 */
void sio_handler(void)
{
                                /*
                                 *  ���ƤΥݡ��ȤˤĤ��ƥ����å�
                                 */
    ID portid ;
    for ( portid = 0 ; portid < TNUM_PORT ; portid++ ) {
        SIOPCB *siopcb = &siopcb_table[portid] ;
        UH uhBase = siopcb->uhBase ;
                                /*
                                 *  ������λ�����ߤ�
                                 */
        if ( ( __SFR(uhBase) & ( __UxCR_TXIE | __UxCR_TXEMPTY ) ) ==
            ( __UxCR_TXIE | __UxCR_TXEMPTY ) ) {
            sio_ierdy_snd( siopcb->vpiExinf ) ;
        }
                                /*
                                 *  ���������ߤ�
                                 */
        if ( ( __SFR(uhBase) & ( __UxCR_RXIE | __UxCR_RXREADY ) ) ==
            ( __UxCR_RXIE | __UxCR_RXREADY ) ) {
            sio_ierdy_rcv( siopcb->vpiExinf ) ;
        }
    }
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL sio_snd_chr(SIOPCB *siopcb, char c)
{
    UH uhBase ;
                                /*
                                 *  ͭ���ʥݡ��Ȥ��ɤ����Υ����å�
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return FALSE ;
    uhBase = siopcb->uhBase ;
                                /*
                                 *  ������ǽ���ɤ����Υ����å�
                                 */
    if ( ! ( __SFR(uhBase) & __UxCR_TXEMPTY ) ) return FALSE ;
                                /*
                                 *  �����ǡ����ν񤭹���
                                 */
    __SFRW(uhBase+4) = __UxTX_STOPBIT | c ;
    return TRUE ;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT sio_rcv_chr(SIOPCB *siopcb)
{
    UH uhBase ;
                                /*
                                 *  ͭ���ʥݡ��Ȥ��ɤ����Υ����å�
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return -1 ;
    uhBase = siopcb->uhBase ;
                                /*
                                 *  �����ǡ���̵ͭ�Υ����å�
                                 */
    if ( ! ( __SFR(uhBase) & __UxCR_RXREADY ) ) return -1 ;
                                /*
                                 *  �����ǡ����μ��Ф�
                                 */
    return __SFRW(uhBase+2) & 0xff ;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void sio_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    UH uhBase ;
                                /*
                                 *  ͭ���ʥݡ��Ȥ��ɤ����Υ����å�
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return ;
    uhBase = siopcb->uhBase ;
                                /*
                                 *  ���������ߤε���
                                 */
    if ( cbrtn == SIO_ERDY_SND ) {
        __SFR(uhBase) |= __UxCR_TXIE ;
        siopcb->bTxIe = TRUE ;
    }
                                /*
                                 *  ���������ߤε���
                                 */
    if ( cbrtn == SIO_ERDY_RCV ) {
        __SFR(uhBase) |= __UxCR_RXIE ;
        siopcb->bRxIe = TRUE ;
    }
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void sio_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    UH uhBase ;
                                /*
                                 *  ͭ���ʥݡ��Ȥ��ɤ����Υ����å�
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return ;
    uhBase = siopcb->uhBase ;
                                /*
                                 *  ���������ߤζػ�
                                 */
    if ( cbrtn == SIO_ERDY_SND ) {
        __SFR(uhBase) &= ~__UxCR_TXIE ;
        siopcb->bTxIe = FALSE ;
    }
                                /*
                                 *  ���������ߤζػ�
                                 */
    if ( cbrtn == SIO_ERDY_RCV ) {
        __SFR(uhBase) &= ~__UxCR_RXIE ;
        siopcb->bRxIe = FALSE ;
    }
}

/*
 *  �ǥե���Ȥ�������ǽ������Хå�
 */
void sio_ierdy_snd(VP_INT exinf) __attribute__((__weak__)) ;
void sio_ierdy_snd(VP_INT exinf)
{
}

/*
 *  �ǥե���Ȥμ������Υ�����Хå�
 */
void sio_ierdy_rcv(VP_INT exinf) __attribute__((__weak__)) ;
void sio_ierdy_rcv(VP_INT exinf)
{
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ���Ʊ��ʸ������
 */
void sio_asnd_chr( INT c )
{
    SIOPCB* siopcb ;
    UH uhBase ;
    int i ;
                                /*
                                 *  CPU��å����֤ˤ���
                                 */
    BOOL bLocked ;
    if ( sns_loc() ) bLocked = TRUE ;
    else {
        bLocked = FALSE ;
        if ( sns_ctx() ) iloc_cpu() ;
        else loc_cpu() ;
    }
                                /*
                                 *  ��Ʊ���ѥݡ��Ȥ򳫤�
                                 */
    if ( ( siopcb = sio_opn_por( LOGTASK_PORTID,
        siopcb_table[LOGTASK_PORTID-1].vpiExinf ) ) != NULL ) {
        uhBase = siopcb->uhBase ;
                                /*
                                 *  LF�ʤ�ޤ�CR������
                                 */
        if ( c == '\n' ) {
            for ( i = 0 ; i < TXREADY_TIMEOUT ; i++ ) {
                if ( __SFR(uhBase) & __UxCR_TXEMPTY ) break ;
            }
            if ( i < TXREADY_TIMEOUT ) {
                __SFRW(uhBase+4) = __UxTX_STOPBIT | '\r' ;
            }
        }
                                /*
                                 *  �ǡ�������
                                 */
        for ( i = 0 ; i < TXREADY_TIMEOUT ; i++ ) {
            if ( __SFR(uhBase) & __UxCR_TXEMPTY ) break ;
        }
        if ( i < TXREADY_TIMEOUT ) {
            __SFRW(uhBase+4) = __UxTX_STOPBIT | c ;
        }
    }
                                /*
                                 *  CPU��å��򸵤��᤹
                                 */
    if ( !bLocked ) {
        if ( sns_ctx() ) iunl_cpu() ;
        else unl_cpu() ;
    }
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ������Ʊ��ʸ������
 */
INT sio_arcv_chr( void )
{
    SIOPCB* siopcb ;
    UH uhBase ;
    INT c = -1 ;
                                /*
                                 *  ����������ƥ����Ȥ���Τ߻��Ѳ�
                                 */
    if ( sns_ctx() || sns_loc() || sns_dsp() ) return -1 ;
                                /*
                                 *  CPU��å����֤ˤ���
                                 */
    loc_cpu() ;
                                /*
                                 *  ��Ʊ���ѥݡ��Ȥ򳫤�
                                 */
    if ( ( siopcb = sio_opn_por( LOGTASK_PORTID,
        siopcb_table[LOGTASK_PORTID-1].vpiExinf ) ) != NULL ) {
        uhBase = siopcb->uhBase ;
                                /*
                                 *  �����Ԥ�
                                 */
        while(1) {
            if ( __SFR(uhBase) & __UxCR_RXREADY ) {
                c = __SFRW(uhBase+2) & 0xff ;
                if ( c == '\r' ) {
                    c = '\n' ;
                    siopcb->bLastIsCr = TRUE ;
                }
                else {
                    if ( c == '\n' && siopcb->bLastIsCr ) c = -1 ;
                    siopcb->bLastIsCr = FALSE ;
                }
            }
            if ( c != -1 ) break ;
            unl_cpu() ;
            dly_tsk( 50 ) ;
            loc_cpu() ;
        }
    }
                                /*
                                 *  CPU��å�����
                                 */
    unl_cpu() ;
    return c ;
}

