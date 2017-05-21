/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 *  @(#) $Id: hw_serial.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *�������ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�MPC860T�ѡ�
 *��������MPC860T��¢���ꥢ�롦�ޥ͡������ȥ���ȥ���SMC1�����
 *
 *��������smc.{c,h}��hw_serial.h��ʬ��δ��
 *��������������smc.{c,h}�����ꥢ��ǥХ����˰�¸������ʬ�Τߵ���
 *��������������hw_serial.h�����ꥢ��ǥХ����ʳ��˵�����������
 *�������� ������������������hw_serial.h�˵��Ҥ���
 *��������������������������������ߥ���ȥ����¸�ʤ�
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#ifndef _MACRO_ONLY
#include <mpc860_smc.h>
#endif /* _MACRO_ONLY */

/*
 *  SIO�γ���ߥϥ�ɥ�Υ٥����ֹ�����������̡�
 */
#define INHNO_SERIAL	INTNO_SMC1

/*
 *��SIU���鸫��CPM����ߥ������γ���ߥ�٥�ϰ�ޤȤ�ˤʤꡢ
 *��CPM��Ǥγ���ߥ�٥�ϥϡ��ɥ������ˤ����ꤵ��롣
 *�����Τ��ᡢSMC1��ͭ��IPM���Ѱդ��Ƥ��ʤ���
 */

#ifndef _MACRO_ONLY

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
#define	sio_initialize	smc_initialize

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;

	/*
	 *  �ǥХ�����¸�Υ����ץ������
	 */
	siopcb = smc_opn_por(siopid, exinf);

    	/*
    	 *  CPM����ߥ���ȥ��������
    	 *  ��CPM����ߥ���ե�����졼����󡦥쥸����CICR��
    	 *  �������CPU�ν�����ǹԤäƤ���Ȥ���
    	 *  ���ʳ���ߥ���ȥ����¸����
    	 *  ��
    	 *  ��CPM��Ǥγ���߽�̤ϸ��ꤵ��Ƥ��롣
    	 *  ����SCC�������
    	 */
    	mpc860_orw_mem(CIMR, CIMR_SMC1);	/*  SMC1����ߤ����  */

	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
Inline void
sio_cls_por(SIOPCB *siopcb)
{
	/*
	 *  �ǥХ�����¸�Υ�����������
	 */
	smc_cls_por(siopcb);

	if (!smc_openflag()) {
		/*  ���٤ƤΥݡ��Ȥ�����������Ƥ����  */
		/*  ���ꥢ��ǥХ����ؤΥ���å��������  */
	}

    	/*
    	 *  CPM����ߥ���ȥ��������
    	 *  ���ʳ���ߥ���ȥ����¸����
    	 */
    	mpc860_andw_mem(CIMR, ~CIMR_SMC1);	/*  SMC1����ߤ�ػ�  */
}

/*
 *  SIO�γ���ߥϥ�ɥ�����������̡�
 */
#define	sio_handler	smc_isr

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
#define	sio_snd_chr	smc_snd_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
#define	sio_rcv_chr	smc_rcv_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
#define	sio_ena_cbr	smc_ena_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
#define	sio_dis_cbr	smc_dis_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 *  ����jsp/systask/serial.c�ˤ�����Τ��͡��ष�Ƥ���
 *  �����ʰ����������ȡ�
 */
#define	sio_ierdy_snd	smc_ierdy_snd

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 *  ����jsp/systask/serial.c�ˤ�����Τ��͡��ष�Ƥ���
 *  �����ʰ����������ȡ�
 */
#define	sio_ierdy_rcv	smc_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
/*  end of file  */
