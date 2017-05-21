/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: hw_serial.h,v 1.7 2007/03/23 07:58:33 honda Exp $
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

/*
 *  �������åȰ�¸���ꥢ��I/O�⥸�塼���H8�ѡ�
 *    ���ݡ��Ȥ� 1�ܤξ��� HWPORT1_ADDR�˻��ꤵ�줿�ݡ��Ȥ���Ѥ���
 *      2�ܤξ��ϡ�HWPORT1_ADDR��桼���ѡ�HWPORT2_ADDR�򥳥󥽡���
 *      ���ϤȤ��ƻ��Ѥ��롣
 *      HWPORTx_ADDR�� �������åȰ�¸�� sys_config.h��ǻ��ꤹ�롣
 *    ���������Υ⥸�塼��ˤ�äơ�XON/XOFF�ե����椬�Ԥ�
 *      ��Ƥ���Τǡ���������TxD��RxD��2�ܤǤ褤
 */

#include <s_services.h>
#include <h8_sil.h>

#ifndef _MACRO_ONLY

/*
 *  ���ꥢ��ݡ��Ȥν�����֥�å�
 */
typedef struct sio_port_initialization_block {
        UB      *base;          /* SCI �Υ١������ɥ쥹 */
        UW      baudrate;       /* �ܡ��쥤��           */
        IRC     irc;            /* ����ߥ�٥�������� */
        UB      smr_init;       /* SMR ��������         */
} SIOPINIB;

/*
 *  ���ꥢ��ݡ��Ȥ�����֥�å�
 */

typedef struct sio_port_control_block {
        const SIOPINIB  *inib;          /* ������֥�å�       */
        VP_INT          exinf;          /* ��ĥ����             */
        BOOL            openflag;       /* �����ץ�Ѥߥե饰   */
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ��������֥�å��ؤ��Ѵ�
 */
#define INDEX_SIO(sioid)        ((UINT)(sioid) - 1u)

Inline SIOPCB*
get_siopcb(ID sioid)
{
	UINT index = INDEX_SIO(sioid);
	
	assert(index < TNUM_PORT);
	
    return(&(siopcb_table[index]));
}

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_ERDY_SND            1u              /* ������ǽ������Хå�                 */
#define SIO_ERDY_RCV            2u              /* �������Υ�����Хå�                 */

/*
 *  SCI �ؿ��λ���
 */
extern void     SCI_initialize (ID sioid);      /* SCI �ν����                         */
extern void     SCI_cls_por(UB *base);          /* SCI �Υ�����                       */
extern void     SCI_in_handler(ID sioid);       /* SCI ���ϳ����ߥϥ�ɥ�             */
extern void     SCI_out_handler(ID sioid);      /* SCI ���ϳ����ߥϥ�ɥ�             */
extern void     SCI_err_handler(ID sioid);      /* SCI ���ϥ��顼�����ߥϥ�ɥ�       */
extern void     SCI_ierdy_snd(VP_INT exinf);    /* ���ꥢ�� I/O �����������ǽ������Хå� */
extern void     SCI_ierdy_rcv(VP_INT exinf);    /* ���ꥢ�� I/O ����μ������Υ�����Хå� */

/*
 *  SCI ��٥�δؿ�
 */

/*
 *  SCI �Υ����ץ�
 */
Inline SIOPCB *
SCI_opn_por (ID sioid)
{
        SCI_initialize(sioid);
        return get_siopcb(sioid);
}

/*
 *  SCI_putchar -- ��������ʸ���ν񤭹���
 */
Inline void
SCI_putchar(const SIOPCB *p, UB c)
{
        UB *base_addr = p->inib->base;

        sil_wrb_mem((VP)(base_addr + H8TDR), (VB)c);
        bitclr(base_addr + H8SSR, (UB)H8SSR_TDRE_BIT);
}


/*
 *  ���٥���Ϥ��Ѥ��륷�ꥢ��ݡ��Ȥ�
 *  ���椹��쥸����������Ƭ���ɥ쥹
 */
#if SCI_LOW_PORTID == SCI_PORTID1
#define SCI_LOW_BASE			SCI_PORT1_BASE
#else /* SCI_LOW_PORTID == SCI_PORTID1 */
#define SCI_LOW_BASE			SCI_PORT2_BASE
#endif

/*
 *  SCI_putchar_pol -- �ݡ���������ˤ�����٥����
 */
Inline void
SCI_putchar_pol(UB c)
{
        UB *base = (UB*)SCI_LOW_BASE;
        UB *addr = base + H8SSR;
        UB tdre = 0;

        /* TDRE�����åȤ����ޤ��Ԥ� */
        while (tdre == 0) {
			/*  ����ѥ���ηٹ���������뤿�ᡢ���㥹�Ȥ��Ƥ���  */
			tdre = (UB)((UB)sil_reb_mem((VP)addr) & H8SSR_TDRE);
		}
        sil_wrb_mem((VP)(base + H8TDR), (VB)c);
        bitclr(addr, (UB)H8SSR_TDRE_BIT);
}

/*
 *  SCI_getchar -- ��������ʸ�����ɤ߽Ф�
 */
Inline INT
SCI_getchar(const SIOPCB *p)
{
        UB      *base_addr = p->inib->base;
        INT     ch = (UB)sil_reb_mem((VP)(base_addr + H8RDR));
                /* UB �Υ��㥹�Ȥϡ�����ĥ���ɻߤ��뤿�� */

        bitclr(base_addr + H8SSR, (UB)H8SSR_RDRF_BIT);
        return ch;
}

/*
 *  SCI_putready -- ������ǽ��
 */
Inline BOOL
SCI_putready(const SIOPCB *pcb)
{
        BOOL ret = TRUE;
        UB ssr = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
        
        ssr &= (UB)H8SSR_TDRE;
        if (ssr == 0) {
			ret = FALSE;
		}
        return(ret);
}

/*
 *  SCI_getready -- ������ǽ��
 */
Inline BOOL
SCI_getready(const SIOPCB *pcb)
{
        BOOL ret = TRUE;
        UB ssr = sil_reb_mem((VP)(pcb->inib->base + H8SSR));

        ssr &= (UB)H8SSR_RDRF;
        if (ssr == 0) {
			ret = FALSE;
		}
        return(ret);
}

/*
 *  ��������������ؿ�
 */
Inline void
SCI_enable_send(const SIOPCB *p)
{
        UB *addr = p->inib->base + H8SCR;
        bitset(addr, (UB)H8SCR_TIE_BIT);
}

Inline void
SCI_disable_send(const SIOPCB *p)
{
        UB *addr = p->inib->base + H8SCR;
        bitclr(addr, (UB)H8SCR_TIE_BIT);
}

/*
 *  ��������������ؿ�
 */
Inline void
SCI_enable_recv(const SIOPCB *p)
{
        UB *addr = p->inib->base + H8SCR;
        bitset(addr, (UB)H8SCR_RIE_BIT);
}

Inline void
SCI_disable_recv(const SIOPCB *p)
{
        UB *addr = p->inib->base + H8SCR;
        bitclr(addr, (UB)H8SCR_RIE_BIT);
}

/*
 *  SIO �ؿ��λ���
 */
                                /* SCI �ν����                         */
extern void     sio_initialize(void);
                                /* ���ꥢ�� I/O ����Υ�����Хå�����  */
extern void     sio_ena_cbr(SIOPCB *pcb, UINT cbrtn);
                                /* ���ꥢ�� I/O ����Υ�����Хå��ػ�  */
extern void     sio_dis_cbr(SIOPCB *pcb, UINT cbrtn);

/*
 *  �ؿ����ߥ�졼�����ޥ���
 */
                        /* ���ꥢ�� I/O �����������ǽ������Хå�      */
#define sio_ierdy_snd(e)        SCI_ierdy_snd(e)
                        /* ���ꥢ�� I/O ����μ������Υ�����Хå�      */
#define sio_ierdy_rcv(e)        SCI_ierdy_rcv(e)

/*
 *  SIO ��٥�δؿ�
 */

extern void sio_in_handler (void);
extern void sio_out_handler (void);

#ifdef H8_CFG_SCI_ERR_HANDLER
extern void sio_err_handler (void);
#endif  /* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#if TNUM_PORT >= 2u
extern void sio_in2_handler (void);
extern void sio_out2_handler (void);

#ifdef H8_CFG_SCI_ERR_HANDLER
extern void sio_err2_handler (void);
#endif  /* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#endif  /* of #if TNUM_PORT >= 2u */

/*
 *  sio_opn_por -- �ݡ��ȤΥ����ץ�
 */
Inline SIOPCB *
sio_opn_por(ID sioid, VP_INT exinf)
{
        SIOPCB  *pcb = SCI_opn_por(sioid);

        pcb->exinf    = exinf;
        pcb->openflag = TRUE;
        return pcb;
}

/*
 *  sio_cls_por -- �ݡ��ȤΥ�����
 */
Inline void
sio_cls_por(SIOPCB *pcb)
{
        SCI_cls_por(pcb->inib->base);
        pcb->openflag = FALSE;
}

/*
 *  sio_snd_chr -- ʸ������
 */
Inline BOOL
sio_snd_chr(const SIOPCB *pcb, char chr)
{
        BOOL ret = FALSE;
        if (SCI_putready(pcb) == TRUE) {
                SCI_putchar(pcb, (UB)chr);
                ret = TRUE;
        }
        return ret;
}

/*
 *  sio_rcv_chr -- ʸ������
 */
Inline INT
sio_rcv_chr(const SIOPCB *pcb)
{
        INT ret = 0;
        if (SCI_getready(pcb) == TRUE) {
                ret = SCI_getchar(pcb);
        } else {
                ret = -1;
        }
        return(ret);
}

#endif  /* of #ifndef _MACRO_ONLY */

#endif /* _HW_SERIAL_H_ */
