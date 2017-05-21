/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2001-2006 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
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
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: $
 */

#ifndef _TINET_SYS_CONFIG_H_
#define _TINET_SYS_CONFIG_H_

/*
 *  �ǡ�������� (�ͥåȥ�����󥿥ե�����) �˴ؤ������
 */

/*
 *  NIC (NE2000 �ߴ�) �˴ؤ������
 */

#define NUM_IF_FEC_TXBUF		2	/* �����Хåե���			*/
#define NUM_IF_FEC_RXBUF		1	/* �����Хåե���			*/


#define TMO_IF_FEC_GET_NET_BUF	1	/* [ms]�������� net_buf ���������ॢ����	*/
					/* [s]�� ���������ॢ����			*/
#define TMO_IF_FEC_XMIT		(2*IF_TIMER_HZ)

/*#define IF_ED_CFG_ACCEPT_ALL		 �ޥ�����㥹�ȡ����顼�ե졼����������Ȥ��ϥ����Ȥ򳰤���*/

/*
 *  �������ͥåȽ��ϻ��ˡ�NIC �� net_buf ����������˻��ꤹ�롣
 *
 *  ���: �ʲ��λ���ϡ�������Ǥ��ꡢif_ed �Ǥϡ�
 *        �������ʤ��Τǡ��ʲ��Υ����Ȥ򳰤��ƤϤʤ�ʤ���
 */

/*#define ETHER_NIC_CFG_RELEASE_NET_BUF*/

/*
 *  FEC �˴ؤ������
 */
#define FEC_BASE_ADDRESS	(IPSBAR + 0x001000)	/* FEC�Υ쥸�����١������ɥ쥹 */
#define PHY_BASE_ADDRESS	(IPSBAR + 0x1E0000)	/* EPHY�Υ쥸�����١������ɥ쥹 */
#define FEC_PHY0                (0x00)

#define INHNO_FEC_XINF     87
#define INHNO_FEC_XINB     88
#define INHNO_FEC_UN       89
#define INHNO_FEC_RL       90
#define INHNO_FEC_RINF     91
#define INHNO_FEC_RINB     92
#define INHNO_FEC_MII      93
#define INHNO_FEC_LC       94
#define INHNO_FEC_HBERR    95
#define INHNO_FEC_GRA      96
#define INHNO_FEC_EBERR    97
#define INHNO_FEC_BABT     98
#define INHNO_FEC_BABR     99
#define INHNO_EPHY         100

#define TBIT_FEC_XINF     23
#define TBIT_FEC_XINB     24
#define TBIT_FEC_UN       25
#define TBIT_FEC_RL       26
#define TBIT_FEC_RINF     27
#define TBIT_FEC_RINB     28
#define TBIT_FEC_MII      29
#define TBIT_FEC_LC       30
#define TBIT_FEC_HBERR    31
#define TBIT_FEC_GRA      32
#define TBIT_FEC_EBERR    33
#define TBIT_FEC_BABT     34
#define TBIT_FEC_BABR     35
#define TBIT_EPHY         36

/*
 *  JSP-1.4.2 �ʹߤǤϡ�����ߥϥ�ɥ����Ͽ��ˡ���ѹ����졢
 *  ����ߥץ饤����ƥ�����٥�����ꤹ��ɬ�פ����롣
 */
#define FEC_INT_LEVEL			5
#define FEC_INT_PRI			7

/*  
 * ����ߥϥ�ɥ�¹���γ���ߥޥ�������
 * ����¾�γ���ߤ�ޥ������뤿�������  
 * ������ʬ��Ʊ����٥�γ�����׵��֥�å����뤿�ᡢ
 * �����嵭�γ�����׵��٥��꣱�Ĺ⤤��٥�����ꤹ�롣
 */
#define if_fec_handler_intmask		(FEC_INT_LEVEL+1)

#ifndef _MACRO_ONLY

#if TKERNEL_PRVER < 0x1042u	/* JSP-1.4.2 ���� */

/*
 *  JSP-1.4.2 �����Ǥϡ�IPM �򥨥顼��ȯ�����ʤ��褦��������롣
 */

typedef UINT	IPM;

#else	/* of #if TKERNEL_PRVER < 0x1042u */

#define fec_ena_inter(ipm)	chg_ipm(ipm)

#endif	/* of #if TKERNEL_PRVER < 0x1042u */

/*
 *  �ؿ�
 */

#if TKERNEL_PRVER < 0x1042u	/* JSP-1.4.2 ���� */

extern void fec_ena_inter (IPM ipm);

#endif	/* of #if TKERNEL_PRVER < 0x1042u */

extern IPM fec_dis_inter (void);
extern void fec_bus_init (void);
extern void fec_inter_init (void);

#endif	/* of #ifndef _MACRO_ONLY */

#endif /* _TINET_SYS_CONFIG_H_ */
