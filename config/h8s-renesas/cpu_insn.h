/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/* �����ˤ����Ѥ��Ƥ��롢MAX_IPM �� cpu_config.h ����� */

#ifndef _MACRO_ONLY

/*
 *  ����쥸���������ؿ�
 */

#include <machine.h>	/*  �����Ϥ��Ȥ߹��ߴؿ�  */

/*
 *  ����ǥ���󥳡��ɥ쥸������CCR�ˤθ����ͤ��ɽФ�
 *����UB current_ccr(void);
 *����������unsigned char get_ccr(void);
 */
#define current_ccr	get_ccr

/*
 *  ����ǥ���󥳡��ɥ쥸������CCR�ˤθ����ͤ��ѹ�
 *�����Ȥ߹��ߴؿ���set_ccr()�򤽤Τޤ޻Ȥ���
 *����void set_ccr(unsigned char ccr);
 */

/*
 *  �������ƥ�ɥ쥸������EXR�ˤθ����ͤ��ɽФ�
 *����UB current_exr(void);
 *����������unsigned char get_exr(void);
 */
#define current_exr	get_exr

/*
 *  �������ƥ�ɥ쥸������EXR�ˤθ����ͤ��ѹ�
 *�����Ȥ߹��ߴؿ���set_exr()�򤽤Τޤ޻Ȥ���
 *����void set_exr(unsigned char exr);
 */

/*
 *  ����ߥޥ������饤�֥�� (����ߥ⡼�ɣ���)
 */

/*
 *  ����ߥޥ����θ����ͤ��ɽФ�
 *����IPM current_intmask(void);
 *����������unsigned char get_imask_exr(void);
 */
#define current_intmask		(IPM)get_imask_exr

/*
 *  ����ߥޥ���������
 *������������intmask���ϰϥ����å��Ͼ�ά���Ƥ��롣
 */
#define set_intmask(intmask)	set_imask_exr(intmask)

/* �Ѹ����
 *���������ͥ�������γ���� �� ����ߥ�٥뤬MAX_IPM �ʲ��γ����
 *���������ͥ�������γ���� �� �ץ饤����ƥ���٥�(MAX_IPM+1)
 *�������������������������������ʾ�γ���ߤ�NMI
 */

/*
 *  �����ͥ�������γ���ߤ�ػ�
 *��������EXR�쥸�����Υȥ졼���ӥå�T����¸�Ͼ�ά���Ƥ��롣
 */
#define disint()	set_intmask( (UB)MAX_IPM )

/*
 *  �����ͥ�������γ���ߤ����
 *��������EXR�쥸�����Υȥ졼���ӥå�T����¸�Ͼ�ά���Ƥ��롣
 *�����������ν����ϡ����¾塢�����ͥ��������̵ͭ����鷺��
 *�����������٤Ƥγ���ߤ���Ĥ��뤳�ȤˤʤäƤ��롣
 */
#define enaint()	set_intmask( (UB)0 )

/*
 *  ����ߥ�å����֤������Ѵؿ�
 */

/*
 *  �����ͥ��������ޤ�Ƥ��٤Ƥγ���ߤ�ػ� (NMI�����)
 *��������EXR�쥸�����Υȥ졼���ӥå�T����¸�Ͼ�ά���Ƥ��롣
 */
#define _disint_()	set_exr( EXR_I_MASK )


#endif /* _MACRO_ONLY */

#endif /* _CPU_INSN_H_ */
