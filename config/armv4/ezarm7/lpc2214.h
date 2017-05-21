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

#ifndef _LPC2214_H_
#define _LPC2214_H_

#ifndef _MACRO_ONLY
#include <itron.h>
#include <sil.h>
#endif /* _MACRO_ONLY */

#include <armv4.h>

/*
 *  Device Registers
 */

/*
 * PXA250 RTC
 */
#define	RTC_RCNR	((VP)0x40900000)
#define	RTC_RTAR	((VP)0x40900004)
#define	RTC_RTSR	((VP)0x40900008)
#define	RTC_RTTR	((VP)0x4090000c)

/*
 * LPC2214 TIMER0/TIMER1
 */
#define TIMER_T0IR	((VP)0xe0004000)
#define TIMER_T0TCR	((VP)0xe0004004)
#define TIMER_T0TC	((VP)0xe0004008)
#define TIMER_T0PR	((VP)0xe000400c)
#define TIMER_T0PC	((VP)0xe0004010)
#define TIMER_T0MCR	((VP)0xe0004014)
#define TIMER_T0MR0	((VP)0xe0004018)
#define TIMER_T0MR1	((VP)0xe000401c)
#define TIMER_T0MR2	((VP)0xe0004020)
#define TIMER_T0MR3	((VP)0xe0004024)
#define TIMER_T0CCR	((VP)0xe0004028)
#define TIMER_T0CR0	((VP)0xe000402c)
#define TIMER_T0CR1	((VP)0xe0004030)
#define TIMER_T0CR2	((VP)0xe0004034)
#define TIMER_T0CR3	((VP)0xe0004038)
#define TIMER_T0EMR	((VP)0xe000403c)

#define TIMER_T1IR	((VP)0xe0008000)
#define TIMER_T1TCR	((VP)0xe0008004)
#define TIMER_T1TC	((VP)0xe0008008)
#define TIMER_T1PR	((VP)0xe000800c)
#define TIMER_T1PC	((VP)0xe0008010)
#define TIMER_T1MCR	((VP)0xe0008014)
#define TIMER_T1MR0	((VP)0xe0008018)
#define TIMER_T1MR1	((VP)0xe000801c)
#define TIMER_T1MR2	((VP)0xe0008020)
#define TIMER_T1MR3	((VP)0xe0008024)
#define TIMER_T1CCR	((VP)0xe0008028)
#define TIMER_T1CR0	((VP)0xe000802c)
#define TIMER_T1CR1	((VP)0xe0008030)
#define TIMER_T1CR2	((VP)0xe0008034)
#define TIMER_T1CR3	((VP)0xe0008038)
#define TIMER_T1EMR	((VP)0xe000803c)

#define MCR_INT_MR0 (1u)
#define MCR_RST_MR0 (2u)
#define MCR_STP_MR0 (4u)

/*
 * intrrupt control
 */
#define INTC_ICIP	0x40d00000
#define INTC_ICMR	0x40d00004
#define INTC_ICFP	0x40d0000c /* should not be used in the kenrel. */
#define INTC_ICPR	0x40d00010
#define INTC_ICLR	((VP)0x40d00008)
#define INTC_ICCR	((VP)0x40d00014)
#define INT_MASK_UA     (1<<22)
#define INT_MASK_T0     (1<<26)


/*
 *  SCI Registers
 */
#define	UART_BASE	(0xE0010000)
#define	UART_RBR	(VP)(UART_BASE+ 0)
#define	UART_THR	(VP)(UART_BASE+ 0)
#define	UART_IER	(VP)(UART_BASE+ 4)
#define	UART_IIR	(VP)(UART_BASE+ 8)
#define	UART_FCR	(VP)(UART_BASE+ 8)
#define	UART_LCR	(VP)(UART_BASE+ 0xc)
#define	UART_MCR	(VP)(UART_BASE+ 0x10)
#define	UART_LSR	(VP)(UART_BASE+ 0x14)
#define	UART_MSR	(VP)(UART_BASE+ 0x18)
#define	UART_SPR	(VP)(UART_BASE+ 0x1c)
#define	UART_DLL	(VP)(UART_BASE+ 0)
#define	UART_DLH	(VP)(UART_BASE+ 4)
/* #define	UART_ISR	(VP)(UART_BASE+ 0x20) -- LP2214 doesn't have ISR register. */

#define	GPIO_GPLR_x	(VP)(0x40e00000)
#define	GPIO_GPLR_y	(VP)(0x40e00004)
#define	GPIO_GPLR_z	(VP)(0x40e00008)
#define	GPIO_GPDR_x	(VP)(0x40e0000c)
#define	GPIO_GPDR_y	(VP)(0x40e00010)
#define	GPIO_GPDR_z	(VP)(0x40e00014)
#define	GPIO_GPSR_x	(VP)(0x40e00018)
#define	GPIO_GPSR_y	(VP)(0x40e0001c)
#define	GPIO_GPSR_z	(VP)(0x40e00020)
#define	GPIO_GPCR_x	(VP)(0x40e00024)
#define	GPIO_GPCR_y	(VP)(0x40e00028)
#define	GPIO_GPCR_z	(VP)(0x40e0002c)
#define	GPIO_GRER_x	(VP)(0x40e00030)
#define	GPIO_GRER_y	(VP)(0x40e00034)
#define	GPIO_GRER_z	(VP)(0x40e00038)
#define	GPIO_GFER_x	(VP)(0x40e0003c)
#define	GPIO_GFER_y	(VP)(0x40e00040)
#define	GPIO_GFER_z	(VP)(0x40e00044)
#define	GPIO_GEDR_x	(VP)(0x40e00048)
#define	GPIO_GEDR_y	(VP)(0x40e0004c)
#define	GPIO_GEDR_z	(VP)(0x40e00050)
#define	GPIO_GAFR0_x	(VP)(0x40e00054)
#define	GPIO_GAFR1_x	(VP)(0x40e00058)
#define	GPIO_GAFR0_y	(VP)(0x40e0005c)
#define	GPIO_GAFR1_y	(VP)(0x40e00060)
#define	GPIO_GAFR0_z	(VP)(0x40e00064)
#define	GPIO_GAFR1_z	(VP)(0x40e00068)

#define CQ_PXA250_CONFIG	(VP)(0x0a000000)

/*
 *  SCI Registers
 */
#define CAL_BPS(bps,clk) ((clk)/(16*(bps)))

#define UART_FCR_TC        0x01
#define UART_FCR_RC        0x02

#define UART_INT_R        0x01
#define UART_INT_T        0x02 
#define UART_INT_TI       0x04
#define UART_INT_M        0x08

#ifndef _MACRO_ONLY
/*
 * ����UART�p �Ȉ�SIO�h���C�o
 */


/*
 * �J�[�l���N�����p�̏�����(sys_putc���g�p���邽��)
 */
extern void uart_init(void);

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
typedef struct sio_port_control_block   SIOPCB;

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND    1u      /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u      /* ��M�ʒm�R�[���o�b�N */


/*
 *  �I���`�b�v��UART����̃|�[�����O�o��
 */
extern void uart_putc(char c);



/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void uart_initialize(void);


/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL uart_openflag(void);


/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB   *uart_opn_por(ID siopid, VP_INT exinf);


/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void uart_cls_por(SIOPCB *siopcb);


/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL uart_snd_chr(SIOPCB *siopcb, char c);


/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT  uart_rcv_chr(SIOPCB *siopcb);


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);


/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void uart_isr(void);


/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void uart_ierdy_snd(VP_INT exinf);


/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void uart_ierdy_rcv(VP_INT exinf);


#endif /* _MACRO_ONLY */


#endif  /*  _LPC2214_H_ */
