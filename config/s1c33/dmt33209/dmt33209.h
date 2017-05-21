/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 *  �ϡ��ɥ������񸻤����
 *  definitions of hardware resource.
 */
#ifndef _DMT33209_H_
#define _DMT33209_H_

#include "s1c33.h"

#ifndef _MACRO_ONLY
extern int __START_bss[];			/* ��󥫥�����ץȤ���������	*/
extern int __END_bss[];				/* ����ܥ�			*/
extern int __START_data[];
extern int __END_data[];
extern int __START_vector[];
extern int __END_vector[];
extern int __START_data_lma[];
extern int __END_data_lma[];
extern int __START_vector_lma[];
extern int __END_vector_lma[];
#endif /* _MACRO_ONLY */

/*
 *	���ꥢ��Ƭ/��ü���ɥ쥹
 *  Top/tail address of each area.
 */
#define STACKTOP	((void *)0x00002000)

#define BSS_START	__START_bss		/* RAM�ΰ����Ƭ 		*/
#define BSS_END		__END_bss		/* RAM�ΰ�ν�ü		*/
#define DATA_START	__START_data		/* RAM��ν�����ѿ��ΰ���Ƭ	*/
#define IDATA_START	__START_data_lma	/* ROM��ν�����ѿ��ΰ���Ƭ	*/
#define IDATA_END	__END_data_lma		/* ROM��ν�����ѿ��ΰ轪ü	*/
#define VECTOR_START	__START_vector		/* RAM��Υ٥����ơ��֥��ΰ���Ƭ*/
#define IVECTOR_START	__START_vector_lma	/* ROM��Υ٥����ơ��֥��ΰ���Ƭ*/
#define IVECTOR_END	__END_vector_lma	/* ROM��Υ٥����ơ��֥��ΰ轪ü*/

#endif /*  _DMT33209_H_ */
