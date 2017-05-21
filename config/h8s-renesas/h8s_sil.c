/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *
 *  @(#) $Id: h8s_sil.c,v 1.2 2007/03/23 07:59:26 honda Exp $
 */

/*
 * �����ƥ।�󥿥ե������쥤����ɲ���ʬ��
 *����I/O�ݡ��ȤΥǡ������ǥ��쥯����󡦥쥸����DDR�ؤΥ�������
 *����H8S��DDR�Ͻ񤭹������ѤǤ��ꡢ���ΤޤޤǤϽ�˾�ΥӥåȤ�����
 *�����ѹ����뤳�Ȥ��Ǥ��ʤ�����bset,bclr̿��Ǥ�����Բġ�
 *�������Τ��ᡢ�ܼ����Ǥϡ������˥ƥ�ݥ����Ѱդ��ơ�DDR��
 *���������ͤ��ݻ�������ˡ��ΤäƤ��롣
 *����
 *�����ݡ��ȣ���DDR�Ϥʤ����ᡢ���֤ˤ��Ƥ��롣
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*  �����Υƥ�ݥ���ΰ�  */
static UB ddr_tmp[] = {
        P1DDR0, P2DDR0, P3DDR0, P5DDR0, 	/*  �ݡ��ȣ��Ϸ���  */
        P6DDR0, P7DDR0, P8DDR0, P9DDR0, 
        PADDR0, PBDDR0, PCDDR0, PDDDR0, PEDDR0, 
        PFDDR0, PGDDR0
};

/*  
 *���ƥݡ��ȤΥ��ɥ쥹  
 *���������ɥ쥹�β���16�ӥåȤ��ݻ����롣
 */
static const UH ddr_adr[] = {
        P1DDR, P2DDR, P3DDR, P5DDR,  		/*  �ݡ��ȣ��Ϸ���  */
        P6DDR, P7DDR, P8DDR, P9DDR, 
        PADDR, PBDDR, PCDDR, PDDDR, PEDDR,
        PFDDR, PGDDR
};


/*
 *      DDR���ɤ߽Ф�
 */
UB sil_reb_ddr(IO_PORT_ID port)
{
	assert(port <= TNUM_IO_PORT);
	return ddr_tmp[port];
}

/*
 *      DDR�ν񤭹���
 */
void sil_wrb_ddr(IO_PORT_ID port, UB data)
{
	assert(port <= TNUM_IO_PORT);
	ddr_tmp[port] = data;
	h8s_wrb_reg(ddr_adr[port], (VB)data);
}

/*
 *      DDR��AND�黻
 */
void sil_anb_ddr(IO_PORT_ID port, UB data)
{
	UB ddr = sil_reb_ddr(port);
        
	ddr &= data;
	sil_wrb_ddr(port, ddr);
}

/*
 *      DDR��OR�黻
 */
void sil_orb_ddr(IO_PORT_ID port, UB data)
{
	UB ddr = sil_reb_ddr(port);

	ddr |= data;
	sil_wrb_ddr(port, ddr);
}

