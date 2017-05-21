/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005- by Monami software, LP.
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id$
 */

/*
 *    LPC2214 �����@�\�p�h���C�o
 */
#include <s_services.h>
#include <lpc2214.h>

/*
 * ����UART�p �Ȉ�SIO�h���C�o
 */

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_initialization_block {

} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N
 */
struct sio_port_control_block {
    const SIOPINIB  *siopinib; /* �V���A��I/O�|�[�g�������u���b�N */
    VP_INT          exinf;     /* �g����� */
    BOOL    openflag;          /* �I�[�v���ς݃t���O */
    BOOL    sendflag;          /* ���M�����݃C�l�[�u���t���O */
    BOOL    getready;          /* ��������M������� */
    BOOL    putready;          /* �����𑗐M�ł����� */
};

/*
 * �V���A��I/O�|�[�g�������u���b�N
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {{}};

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
SIOPCB  siopcb_table[TNUM_SIOP];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))


/*
 * ��������M������?
 */ 
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
    return (sil_rew_mem(UART_LSR) & 0x01) != 0;
}

/*
 * �����𑗐M�ł��邩?
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
    return (sil_rew_mem(UART_LSR) & 0x20) != 0;
}

/*
 *  ��M���������̎��o��
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
    return (UB)sil_rew_mem(UART_RBR);  
}

/*
 *  ���M���镶���̏�������
 */
void
uart_putchar(SIOPCB *siopcb, UB c)
{
    sil_wrw_mem(UART_THR, (VW)c);
}

/*
 *  ���M�����݋���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
    VW wbits;
    wbits = sil_rew_mem(UART_IER);
    wbits |= UART_INT_T;
    sil_wrw_mem(UART_IER,wbits);
}

/*
 *  ���M�����݋֎~
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
    VW wbits;
    wbits = sil_rew_mem(UART_IER);
    wbits &= ~UART_INT_T;
    sil_wrw_mem(UART_IER,wbits);
}

/*
 *  ��M�����݋���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
    VW wbits;
    wbits = sil_rew_mem(UART_IER);
    wbits |= UART_INT_R;
    sil_wrw_mem(UART_IER,wbits);
}

/*
 *  ��M�����݋֎~
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
    VW wbits;
    wbits = sil_rew_mem(UART_IER);
    wbits &= ~UART_INT_R;
    sil_wrw_mem(UART_IER,wbits);
}



/*
 * �J�[�l���N�����̃��O�o�͗p�̏�����
 */
void
uart_init(void){
    UW wbits;
    UH devisor;

#if 0
    /*
     *  GP34�`41 �� FFUART �Ƃ��ė��p
     */
    wbits = sil_rew_mem(GPIO_GAFR0_y);
    wbits = (wbits & 0xfff0000f) | 0x000a9550;
    sil_wrw_mem(GPIO_GAFR0_y, wbits);

    /*
     *  TXD, RTS/RTS ���o�͂ɂ���
     */
    wbits = sil_rew_mem(GPIO_GPDR_y);
    wbits = (wbits & 0xfffffc7f) | 0x00000380;
    sil_wrw_mem(GPIO_GPDR_y, wbits);
    
    /*
     * RS232C �h���C�o�n�[�h�E�F�A�̃C�l�[�u��
     */
    wbits = sil_rew_mem(CQ_PXA250_CONFIG);
    wbits |= 0x200;
    sil_wrw_mem(CQ_PXA250_CONFIG, wbits);
#endif

    /*
     *  UART_BPS ��14�ȉ��̂Ƃ��A
     *  ���Z���ʂ��I�[�o�t���[����B
     *  ���ۂɂ���Ȑ��l�ɂ��邱�Ƃ�
     *  ���肦�Ȃ����O�̂��߁B
     */
#if (UART_BPS < 15)
#error UART_BPS is too small or undefined.
#endif

    devisor = 921600 / UART_BPS;

    sil_wrw_mem(UART_LCR, 0x80);
    sil_wrw_mem(UART_DLL, devisor & 0xff);
    sil_wrw_mem(UART_DLH, (devisor >> 8) & 0xff);
    sil_wrw_mem(UART_LCR, 0x3);
    sil_wrw_mem(UART_FCR, 0x1);
    sil_wrw_mem(UART_MCR, 0x3);
    sil_wrw_mem(UART_IER, 0x40);
}


/*
 *  �I���`�b�v��UART����̃|�[�����O�o��
 */
void
uart_putc(char c)
{
    UW buf_level;
    
    while((sil_rew_mem(UART_LSR) & 0x20) == 0) {
	/* spin lock */
    }
    
    sil_wrw_mem(UART_THR,(VW)c);
}

/*
 *  SIO�h���C�o�̏��������[�`��
 *  1�|�[�g�����Ȃ����߁C���܂�Ӗ��͂Ȃ�
 */
void
uart_initialize()
{
    SIOPCB  *siopcb;
    UINT    i;

    /*
     *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
     */
    for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
        siopcb->siopinib = &(siopinib_table[i]);
        siopcb->openflag = FALSE;
        siopcb->sendflag = FALSE;
    }
}

/*
 * �I�[�v�����Ă���|�[�g�����邩
 */
BOOL
uart_openflag(void)
{
    return(siopcb_table[0].openflag);
}


/*
 * �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

    uart_init();
    
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    /* clear FIFO  TxThr = 0 RxThr = 1*/
    sil_wrw_mem(UART_FCR,(VW)(UART_FCR_TC | UART_FCR_RC));
  
    /* set interrupt */
    sil_wrw_mem(UART_IER, 0x42);

    return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
uart_cls_por(SIOPCB *siopcb)
{
    siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
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
 *  �V���A��I/O�|�[�g����̕�����M
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
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
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
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
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
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
uart_isr_siop(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        /*
         *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
         */
        uart_ierdy_rcv(siopcb->exinf);
    }
    if (uart_putready(siopcb)) {
        /*
         *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
         */
        uart_ierdy_snd(siopcb->exinf);
    }
}


/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
uart_isr()
{
	sil_wrw_mem((VP *)0xe002800c, 0x40000000);

    uart_isr_siop(&(siopcb_table[0]));
}

