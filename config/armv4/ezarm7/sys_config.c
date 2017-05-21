/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *    �^�[�Q�b�g�V�X�e���ˑ����W���[���iEZARM7�p�j
 */

#include "jsp_kernel.h"
#include <lpc2214.h>



void
hardware_init_hook()
{
    extern int __ivector_end;
    int i;
    VB *sram;

    sram = (VB *)0x40000000;
    /*
     *  Remap vector to Static RAM.
     */
    for(i = 0; i < 0x40; i++) {
      sram[i] = *((VB *)i);
    }
    sil_wrw_mem((VP)(0xe01fc040), 2);
}

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
    int i;

    sil_wrw_mem((VP *)(0xfffff034), undef_interrupt);

    /*
     *  ARM�̃x�N�^�e�[�u���֊����݃n���h����o�^
     */
    arm_install_handler(IRQ_Number,IRQ_Handler);
  
    /*
     *  sys_putc ���\�ɂȂ�悤��UART��������
     */
    uart_init();
}


/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit(void)
{
    syslog(LOG_EMERG, "End Kernel.....!");
    while(1);
}




/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void
sys_putc(char c)
{
    if (c == '\n') {
        uart_putc('\r');
    }
  uart_putc(c);  
}


/*
 *  �����݃n���h���̐ݒ�
 *
 *  �����ݔԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
void
define_inh(INHNO inhno, FP inthdr)
{
    VW *base;
    assert(inhno < MAX_INT_NUM);

    base = (VW *)(0xfffff100);
    sil_wrw_mem((VP *)(&base[inhno]), inthdr);
    sil_wrw_mem((VP *)0xfffff010, 1 << inhno);

    base = (VW*)0xfffff200;
    sil_wrw_mem((VP *)&(base[inhno]), inhno | 0x20);
}


/*
 * �����ݗD��x��ݒ�D
 */
void
define_ipm(INHNO inhno, PRI pri)
{
    VW *base;

    assert(inhno < MAX_INT_NUM);
#if 0
    base = (VW*)0xfffff200;
    if (pri == 0) {
	sil_wrw_mem((VP *)&(base[inhno]), 0);
    } else {
	pri = 16 + pri;
	assert(0 <= pri && pri <= 15);
	sil_wrw_mem((VP *)&(base[inhno]), pri | 0x20);
    }
#endif
}


void
dis_int(INHNO inhno)
{
  sil_wrw_mem((VP *)0xfffff014, 1 << inhno);
}

void
ena_int(INHNO inhno)
{
  sil_wrw_mem((VP *)0xfffff010, 1 << inhno);
}



/*
 *  ����`�̊����݂��������ꍇ�̏���
 */
void
undef_interrupt(){
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
    while(1);
}
