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
 *   Optimize��EZARM7�p�̒�`
 *   sys_config.h����C���N���[�h�����
 */

#ifndef _EZARM7_H_
#define _EZARM7_H_

#include <lpc2214.h>

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�V�X�e����
 */
#define    TARGET_NAME    "Optimize EZARM7"


/*
 *  JSP�J�[�l�����쎞�̃������}�b�v�Ɗ֘A�����`
 *
 *  �V�X�e���������}�b�v
 *
 *  On-Chip Non-volatile Memory : 0x00000000 - 0x0001FFFF   (128KB)
 *  On-chip SRAM0               : 0x40000000 - 0x40003fff   ( 16KB)
 *
 *  JSP�ł̊��蓖��
 *  0x00000000 - 0x0001ffff �R�[�h�̈�(128Kbyte)
 *  0x40000000 -            �f�[�^�̈�( 64Kbyte)
 *             - 0x4003ffff �^�X�N�Ɨ����X�^�b�N
 */

#define   STACKTOP 0x40003ffc   /* ��^�X�N�R���e�L�X�g�p�̃X�^�b�N�̏����l */

/*
 *  UART�̃{�[���[�g
 */
#define UART_BPS      115200

/*
 *  �^�C�}�l�̓����\���ƃ~���b�P�ʂƂ̕ϊ�
 */
#define TIMER_CLOCK          1000


/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN  SIL_ENDIAN_LITTLE  /* ���g���G���f�B�A�� */

#endif /* _EZARM7_H_ */



 

