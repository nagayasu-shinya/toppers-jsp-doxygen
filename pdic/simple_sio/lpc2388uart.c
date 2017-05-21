/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *   CQ-FRK-NXP-ARM UART�� �ʰ�SIO�ɥ饤��
 *
 *   ���Υե�����ϡ�TOPPERS/JSP 1.4.2�� pdic/simple_sio/st16c2550.c��
 *   ��͡��ष�������μ��̻Ҥ��ѹ�������ΤǤ��롣
 */
#include <s_services.h>
#include "lpc2388uart.h"

/*
 * 8250, 16450, 16550�ƥ쥸�����Υ��ɥ쥹�����ե��åȡ�UART_RHR������Ȥ��롣
 * �����ƥऴ�Ȥ˰ۤʤ�Τ�UART_BOUNDARY�ˤ�äƥ쥸���������ֶ�������ꤹ�롣
 * ���Ȥ��Ф��٤ƤΥ쥸������8�ӥåȶ��������֤���Ƥ���ʤ顢UART_BOUNDARY��1,
 * 16bit�����ʤ�2, 32�ӥåȶ����ʤ�4����ꤹ�롣
 * UART_BOUNDARY��sys_config.h��������롣
 */


#define UART_RBR   (0x00 * UART_BOUNDARY)   /*  �����Хåե��쥸����  */
#define UART_THR   (0x00 * UART_BOUNDARY)   /*  �����ǡ������ۡ���ɡ��쥸���� */
#define UART_DLL   (0x00 * UART_BOUNDARY)   /*  ʬ���쥸�������̥Х���       */
#define UART_IER   (0x01 * UART_BOUNDARY)   /*  ����ߥ��͡��֥�쥸����       */
#define UART_DLM   (0x01 * UART_BOUNDARY)   /*  ʬ���쥸������̥Х���       */
#define UART_IIR   (0x02 * UART_BOUNDARY)   /*  ����߼��̥쥸����  */
#define UART_FCR   (0x02 * UART_BOUNDARY)   /*  FIFO����쥸����  */
#define UART_LCR   (0x03 * UART_BOUNDARY)   /*  �饤������쥸���� */
#define UART_MCR   (0x04 * UART_BOUNDARY)   /*  ��ǥ�����쥸���� */
#define UART_LSR   (0x05 * UART_BOUNDARY)   /*  �饤�󡦥��ơ��������쥸���� */
#define UART_MSR   (0x06 * UART_BOUNDARY)   /*  ��ǥࡦ���ơ��������쥸���� */
#define UART_SCR   (0x07 * UART_BOUNDARY)   /*  ������å����ѥåɡ��쥸���� */
#define UART_GCTL  (0x09 * UART_BOUNDARY)	  /*  Blackfin�Τߡ������Х�����쥸���� */

/*
 * �쥸�����Υӥåȥޥ������ü쵡ǽ���ɲä��ʤ��¤ꡢ�񤭴����ʤ��Ƥ褤��
 */

#define ISR_TX            0x02       /* ����������ȯ�� */
#define IER_TX            0x02       /* ���������ߵ��� */
#define ISR_RX            0x01       /* ����������ȯ�� */
#define IER_RX            0x01       /* ���������ߵ��� */

#define LCR_DL_MODE       0x80       /* Divisor Enable */
#define LCR_NP_8_1        0x03       /* 8bit,1stop,Noparity,No break */
#define FCR_FIFO_DISABLE  0x00

#define LSR_RX_DATA_READY 0x01
#define LSR_TX_EMPTY      0x20

#define MCR_INT_ENABLE    0x08

#define GCTL_UCEN		  0x01		/* Blackfin�Τ� */


/*
 * TNUM_SIOP_UART, UART0_ADDRESS, UART0_DIVISOR ��sys_config.h��������롣
 *	TNUM_SIOP_UART : PDIC����������UART�θĿ�
 *  �ʲ���PDIC����������ǽ��UART�ξ���
 *  	UART0_ADDRESS : 		THR�Υ��ɥ쥹
 *  	UART0_DIVISOR : 		DLM, DLL�ν����(16bitɽ��)
 *      UART0_14550_FIFO : 		14550�ߴ���FIFO����ĤȤ��˥ޥ�����������
 *		UART0_BLACKFIN_UCEN : 	Blackfin���ѡ��ޥ�����������Ƚ���������ɤ�UART_GCTL��UCEN��1�ˤ��롣
 *	����ܰʹߤ�UART������ʤ�ʲ��Τ褦��³���롣
 *  	UART1_ADDRESS : 		THR�Υ��ɥ쥹
 *  	UART1_DIVISOR : 		DLM, DLL�ν����(16bitɽ��)
 *      UART1_14550_FIFO : 		14550�ߴ���FIFO����ĤȤ��˥ޥ�����������
 *		UART1_BLACKFIN_UCEN : 	Blackfin���ѡ��ޥ�����������Ƚ���������ɤ�UART_GCTL��UCEN��1�ˤ��롣
 *	...
 */


/******************************************************************************************
 * ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
#if TNUM_SIOP_UART == 0 
#error "If you don't use UART, please remove this file from your make file" 
#endif

#if TNUM_SIOP_UART > 3
#error "Only TNUM_SIOP_UART < 4 is supported" 
#endif /* TNUM_SIOP_UART >= 2 */    

/* �ǥ��Х����׻��ޥ��� */
#define DLM(divisor) (divisor/256)
#define DLL(divisor) (divisor%256)

const SIOPINIB siopinib_table[TNUM_SIOP_UART] = {
/*-----------------------------------------------------------------
 *			PDIC����������ǽ��UART�ν�����ѥ�᡼�� 
 */
    {UART0_ADDRESS,  DLM(UART0_DIVISOR), DLL(UART0_DIVISOR), 
#ifdef UART0_BLACKFIN_UCEN
		1	/* �ޥ���UART0_BLACKFIN_UCEN���������Ƥ����顢GCTL��UCEN��1�ˤ��ƥ���å���ư���� */
#else
		0
#endif
	}

/*-----------------------------------------------------------------
 *			PDIC����������2���ܤ�UART�ν�����ѥ�᡼�� 
 */

#if TNUM_SIOP_UART > 1
    ,{UART1_ADDRESS,    DLM(UART1_DIVISOR), DLL(UART1_DIVISOR),	
#ifdef UART1_BLACKFIN_UCEN
		1	/* �ޥ���UART1_BLACKFIN_UCEN���������Ƥ����顢GCTL��UCEN��1�ˤ��ƥ���å���ư���� */
#else
		0
#endif


	}
#endif /* if TNUM_SIOP_UART > 1*/

/*-----------------------------------------------------------------
 *			PDIC����������3���ܤ�UART�ν�����ѥ�᡼�� 
 */
#if TNUM_SIOP_UART > 2
    ,{UART2_ADDRESS,    DLM(UART2_DIVISOR), DLL(UART2_DIVISOR),
#ifdef UART2_BLACKFIN_UCEN
		1	/* �ޥ���UART2_BLACKFIN_UCEN���������Ƥ����顢GCTL��UCEN��1�ˤ��ƥ���å���ư���� */
#else
		0
#endif


	}
#endif /* if TNUM_SIOP_UART > 2*/

};

/*
 * ���ꥢ��I/O�ݡ��Ƚ�����֥�å������ޤǡ�
 ******************************************************************************************/



/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å��μ�Ф�
 */
#define INDEX_SIOPINIB(siopid)  ((UINT)((siopid) - 1))
#define get_siopinib(siopid)  (&(siopinib_table[INDEX_SIOPINIB(siopid)]))


/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
SIOPCB  siopcb_table[TNUM_SIOP_UART];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))

Inline void
uart_write(UW addr, UW offset, UB val)
{
#ifdef UART_IOP_ACCESS
    sil_wrb_iop((VP)(addr + offset),val);
#else
    sil_wrb_mem((VP)(addr + offset),val);	
#endif
}

Inline UB
uart_read(UW addr, UW offset)
{
#ifdef UART_IOP_ACCESS
    return(sil_reb_iop((VP)(addr + offset)));
#else
    return(sil_reb_mem((VP)(addr + offset)));
#endif
}


/*
 * ʸ�������������?
 */ 
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
    UH status;

    status = uart_read(siopcb->siopinib->reg_base, UART_LSR);
    
    return((status & LSR_RX_DATA_READY));
}

/*
 * ʸ���������Ǥ��뤫?
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
    UH status;

    status = uart_read(siopcb->siopinib->reg_base, UART_LSR);
    
    return (status & LSR_TX_EMPTY);
}

/*
 *  ��������ʸ���μ��Ф�
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
    return(uart_read(siopcb->siopinib->reg_base,UART_RBR));
}

/*
 *  ��������ʸ���ν񤭹���
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
    uart_write(siopcb->siopinib->reg_base, UART_THR, c);
}

/*
 *  ��������ߵ���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
    uart_write(siopcb->siopinib->reg_base, UART_IER,
                (uart_read(siopcb->siopinib->reg_base,UART_IER) | IER_TX));
}

/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
    uart_write(siopcb->siopinib->reg_base, UART_IER,
                (uart_read(siopcb->siopinib->reg_base, UART_IER) & ~IER_TX));
                
}

/*
 *  ��������ߵ���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
    uart_write(siopcb->siopinib->reg_base, UART_IER,
                (uart_read(siopcb->siopinib->reg_base,UART_IER) | IER_RX));
}

/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
    uart_write(siopcb->siopinib->reg_base, UART_IER,
                (uart_read(siopcb->siopinib->reg_base, UART_IER) & ~IER_RX));
                
}


/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
uart_initialize()
{
    SIOPCB  *siopcb;
    UINT    i;

    /*
     *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
     */
    for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP_UART; siopcb++, i++) {
        siopcb->siopinib = &(siopinib_table[i]);
        siopcb->openflag = FALSE;
        siopcb->sendflag = FALSE;
    }
}

    
/*
 *
 */
void
uart_init_siopinib(const SIOPINIB *siopinib)
{

	/*
	 *  Blackfin ADSP-BF531/2/3, BF534/6/7, BF561����¢UART�˸�ͭ�κ�ȡ�
	 *  Power Down�⡼�ɤβ����
	 */
	if ( siopinib->set_ucen )
		uart_write(siopinib->reg_base, UART_GCTL, 
			   (uart_read(siopinib->reg_base, UART_GCTL) | GCTL_UCEN ));
    /*
     *  ʬ���������
     */
    /* Divisor Enable */
    uart_write(siopinib->reg_base, UART_LCR,
                (uart_read(siopinib->reg_base, UART_LCR) | LCR_DL_MODE));
    uart_write(siopinib->reg_base, UART_DLL, siopinib->dll_val);
    uart_write(siopinib->reg_base, UART_DLM, siopinib->dlm_val);
    /* Divisor Disable */
    uart_write(siopinib->reg_base, UART_LCR,
                (uart_read(siopinib->reg_base, UART_LCR) & ~LCR_DL_MODE));

    /* �⡼������, �ѥ�ƥ�̵�� 8bit data, 1 stop bit */
    uart_write(siopinib->reg_base, UART_LCR, LCR_NP_8_1);

    /* ����߶ػ� */
    uart_write(siopinib->reg_base, UART_IER, 0x00);
}


/*
 *  �����ͥ뵯ư���ΥХʡ������Ѥν����
 */
void 
uart_init(void)
{
    int i;
	/*
	 * ���٤Ƥ�uart���������롣id ��1����TNUM_SIOP_UART�ޤǡ�
	 */
	for ( i=1; i<=TNUM_SIOP_UART; i++ )
	    uart_init_siopinib(get_siopinib(i));
}

/*
 * �����ץ󤷤Ƥ���ݡ��Ȥ����뤫
 */
BOOL
uart_openflag(void)
{
	int i;
	
	/*
	 * �����Ƥ���ݡ��Ȥ������0���֤����ʤ����0���֤���
	 */
	for ( i=0; i<TNUM_SIOP_UART; i++ )
		if (siopcb_table[0].openflag)
			return( 1 );
	return( 0 );
}


/*
 * ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;
    
    /*
     * �����
     */
    uart_init_siopinib(siopcb->siopinib);
    
    /* ��������ߵ��� */
    uart_write(siopcb->siopinib->reg_base, UART_IER, IER_RX);
    
    /* ��������򥤥͡��֥� */
    uart_write(siopcb->siopinib->reg_base, UART_MCR, MCR_INT_ENABLE);

    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
uart_cls_por(SIOPCB *siopcb)
{
    /* ����߶ػ� */
    uart_write(siopcb->siopinib->reg_base, UART_IER, 0x00);   
    siopcb->openflag = FALSE;
}


/*
 *  ���ꥢ��I/O�ݡ��ȤؤΥݡ���󥰤Ǥν���
 */
void
uart_pol_putc(char c, ID siopid)
{
    const SIOPINIB *siopinib;
    
    siopinib = get_siopinib(siopid);
    
    while((uart_read(siopinib->reg_base, UART_LSR) & LSR_TX_EMPTY)
          != LSR_TX_EMPTY)
        ;
    uart_write(siopinib->reg_base, UART_THR, c);
}


/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char c)
{
    if (uart_putready(siopcb)){
        uart_putchar(siopcb, c);
        return(TRUE);
    }
    return(FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
uart_rcv_chr(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        return((INT)(UB) uart_getchar(siopcb));
    }
    return(-1);
}





/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{

    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_enable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_enable_rcv(siopcb);
            break;
    }
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_disable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_disable_rcv(siopcb);
            break;
    }
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф������߽���
 */
static void
uart_rx_isr_siop(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        /*
         *  �������Υ�����Хå��롼�����ƤӽФ���
         */
        uart_ierdy_rcv(siopcb->exinf);
    }
}

static void
uart_tx_isr_siop(SIOPCB *siopcb)
{
    if (uart_putready(siopcb)) {
        /*
         *  ������ǽ������Хå��롼�����ƤӽФ���
         */
        uart_ierdy_snd(siopcb->exinf);
    }
}

/*
 *  SIO�γ���ߥ����ӥ��롼����
 *	ADSP-BF533����¢UART���������̡��γ�����׵��Ф����ᡢ
 *  ISR��ʬ���Ƥ��롣�ޤ���ADSP-BF537�Τ褦����İʾ��
 *  UART����ľ����θ���ơ�uart0�Τ褦�˥ݡ����ֹ��
 *  ̾���˥ϡ��ɥ����ɤ��Ƥ��롣
 *  �����������Υݡ����ֹ�Ȥϡ�SIO�Υݡ����ֹ�Ǥ��äơ�
 *  �ϡ��ɥ�������UART�ֹ��Ʊ�����Ȥϸ¤�ʤ���
 */

/*
 ***** UART0
 */
void
uart0_rx_isr()
{
		/* ���̤μ���������Ƥ� */
    uart_rx_isr_siop(&(siopcb_table[0]));
}

void
uart0_tx_isr()
{
		/* ���̤�����������Ƥ� */
    uart_tx_isr_siop(&(siopcb_table[0]));
}

/*
 ***** UART1
 */
void
uart1_rx_isr()
{
		/* ���̤μ���������Ƥ� */
    uart_rx_isr_siop(&(siopcb_table[1]));
}

void
uart1_tx_isr()
{
		/* ���̤�����������Ƥ� */
    uart_tx_isr_siop(&(siopcb_table[1]));
}

/*
 ***** UART2
 */
void
uart2_rx_isr()
{
		/* ���̤μ���������Ƥ� */
    uart_rx_isr_siop(&(siopcb_table[2]));
}

void
uart2_tx_isr()
{
		/* ���̤�����������Ƥ� */
    uart_tx_isr_siop(&(siopcb_table[2]));
}





/*
 * UART�������ǳ���ߤ�ͭ������ʤ�����Τۤ�������Ū�ˤϡ�
 * ��Υ롼����ǤϤʤ�����������ߥ����ӥ��롼����Ȥ��ƻȤ���
 */
void
uart0_isr()
{
		/* ���̤μ���������Ƥ� */
    uart_rx_isr_siop(&(siopcb_table[0]));
		/* ���̤�����������Ƥ� */
    uart_tx_isr_siop(&(siopcb_table[0]));
}

void
uart1_isr()
{
		/* ���̤μ���������Ƥ� */
    uart_rx_isr_siop(&(siopcb_table[1]));
		/* ���̤�����������Ƥ� */
    uart_tx_isr_siop(&(siopcb_table[1]));
}

void
uart2_isr()
{
		/* ���̤μ���������Ƥ� */
    uart_rx_isr_siop(&(siopcb_table[2]));
		/* ���̤�����������Ƥ� */
    uart_tx_isr_siop(&(siopcb_table[2]));
}
