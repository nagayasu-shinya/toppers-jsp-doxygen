/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: tinet_cpu_config.h,v 1.2 2007/01/05 02:10:17 honda Exp $
 */

#ifndef _TINET_CPU_CONFIG_H_
#define _TINET_CPU_CONFIG_H_

/*
 *  TCP/IP �˴ؤ������
 */

/* TCP �˴ؤ������ */

/*
 *  MAX_TCP_RCV_SEG: �����������ȥ������κ�����
 *
 *    ���: �ѹ����٤��ǤϤʤ���
 */

#define MAX_TCP_RCV_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))

/*
 *  MAX_TCP_SND_SEG: �����������ȥ������κ�����
 *
 *    ��꤫�� MSS ���ץ����ǥ������ȥ���������ꤵ��Ƥ⡢
 *    �����ͤǡ��������ȥ����������¤Ǥ��롣
 */

#ifdef SUPPORT_PPP

#define MAX_TCP_SND_SEG		(256 - ((IF_IP_TCP_HDR_SIZE + 3) >> 2 << 2))
/*#define MAX_TCP_SND_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))*/
/*#define MAX_TCP_SND_SEG		TCP_MSS*/

#endif	/* of #ifdef SUPPORT_PPP */

#ifdef SUPPORT_ETHER

/*#define MAX_TCP_SND_SEG		(1024 - ((IF_IP_TCP_HDR_SIZE + 3) >> 2 << 2))*/
#define MAX_TCP_SND_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
/*#define MAX_TCP_SND_SEG		TCP_MSS*/

#endif	/* of #ifdef SUPPORT_ETHER */

#ifdef SUPPORT_LOOP

#define MAX_TCP_SND_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))

#endif	/* of #ifdef SUPPORT_LOOP */

/*
 *  DEF_TCP_SND_SEG: �����������ȥ������ε�����
 *  DEF_TCP_RCV_SEG: �����������ȥ������ε�����
 */

#ifdef SUPPORT_PPP

#define DEF_TCP_SND_SEG		MAX_TCP_SND_SEG

#define DEF_TCP_RCV_SEG		(256 - ((IF_IP_TCP_HDR_SIZE + 3) >> 2 << 2))
/*#define DEF_TCP_RCV_SEG		MAX_TCP_RCV_SEG*/

#endif	/* of #ifdef SUPPORT_PPP */

#ifdef SUPPORT_ETHER

#define DEF_TCP_SND_SEG		MAX_TCP_SND_SEG

/*#define DEF_TCP_RCV_SEG		(1024 - ((IF_IP_TCP_HDR_SIZE + 3) >> 2 << 2))*/
#define DEF_TCP_RCV_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
/*#define DEF_TCP_RCV_SEG		TCP_MSS*/

#endif	/* of #ifdef SUPPORT_ETHER */

#ifdef SUPPORT_LOOP

#define DEF_TCP_SND_SEG		MAX_TCP_SND_SEG
#define DEF_TCP_RCV_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))

#endif	/* of #ifdef SUPPORT_LOOP */

/* 
 *  �������Ȥν��֤������ؤ���Ȥ��˿����˥ͥåȥ���Хåե�������Ƥơ�
 *  �ǡ����򥳥ԡ����륵�����Τ�������
 */
#define MAX_TCP_REALLOC_SIZE	1024	

#define TMO_TCP_GET_NET_BUF	1000	/* [ms]��net_buf ���������ॢ����		*/
#define TMO_TCP_OUTPUT		1000	/* [ms]��TCP ���ϥ����ॢ����			*/

#define TCP_CFG_OPT_MSS		/* ���ͥ�������߻��ˡ��������ȥ��������ץ�����Ĥ����������롣*/
#define TCP_CFG_DELAY_ACK	/* ACK ���٤餻��Ȥ��ϥ����Ȥ򳰤���			*/
#define TCP_CFG_ALWAYS_KEEP	/* ��˥����ץ��饤�֤�����ϥ����Ȥ򳰤���		*/

/*
 *  ���ϥ�����
 */

#define	TCP_OUT_TASK_STACK_SIZE	1024	/* TCP ���ϥ������Υ����å�������		*/
#define TCP_OUT_TASK_PRIORITY	5	/* TCP ���ϥ�������ͥ����			*/

/* UDP �˴ؤ������ */

					/* UDP �������塼������				*/
#define NUM_DTQ_UDP_RCVQ	(NUM_MPF_NET_BUF_IF_PDU-1)	/* �󥳡���Хå���	*/
#define NUM_DTQ_UDP_CB_RCVQ	(NUM_DTQ_UDP_RCVQ+1)		/* ������Хå���	*/

#define TMO_UDP_OUTPUT	10000		/* [ms]��UDP ���ϥ����ॢ����			*/

#define UDP_CFG_IN_CHECKSUM	/* UDP �����ϥ����å������Ԥ����ϥ����Ȥ򳰤���	*/
#define UDP_CFG_OUT_CHECKSUM	/* UDP �ν��ϥ����å������Ԥ����ϥ����Ȥ򳰤���	*/

/*
 *  �Υ�֥�å��󥰥������Ԥ������Ȥ߹��ॿ�����ȥǡ������塼
 */

#define NUM_DTQ_UDP_OUTPUT	1	/* UDP ���ϥǡ������塼������			*/
#define	UDP_OUT_TASK_STACK_SIZE	1024	/* UDP ���ϥ������Υ����å�������			*/
#define UDP_OUT_TASK_PRIORITY	5	/* UDP ���ϥ�������ͥ����				*/

/* ICMPv4/v6 �˴ؤ������ */

#define ICMP_REPLY_ERROR		/* ICMP ���顼��å�����������������ϥ����Ȥ򳰤���*/

#define TMO_ICMP_OUTPUT		1000	/* [ms]��ICMP ���ϥХåե����������ॢ����	*/

/* IPv4/IPv6 ������� */

#define TMO_IN_REDIRECT	(10*60*1000)	/* [ms]������ľ���롼�ƥ��󥰥���ȥ꥿���ॢ����	*/

/* IPv4 �˴ؤ������ */

/*#define IP4_CFG_FRAGMENT		 �ǡ���������ʬ�䡦�ƹ����Ԥ����ϥ����Ȥ򳰤���*/
#define NUM_IP4_FRAG_QUEUE	2	/* �ǡ��������ƹ������塼������			*/
#define TMO_IP4_FRAG_GET_NET_BUF	1000	/* [ms]��net_buf ���������ॢ����		*/

/* IPv6 �˴ؤ������ */

#ifdef SUPPORT_ETHER

#define IP6_CFG_AUTO_LINKLOCAL		/* ��󥯥����륢�ɥ쥹�μ�ư�����Ԥ����ϥ����Ȥ򳰤���*/

#endif	/* of #ifdef SUPPORT_ETHER */

#define NUM_IP6_DAD_COUNT	1	/* ��ʣ���ɥ쥹���Ф�����������������β����		*/
					/*  0 ����ꤹ��ȡ���ʣ���ɥ쥹���Ф�Ԥ�ʤ���	*/
#define NUM_ND6_CACHE_ENTRY	10	/* ���٥���å���Υ���ȥ��			*/

#ifdef SUPPORT_ETHER

/*
 *  �ǥ��ե���ȥ롼���ꥹ�ȤΥ���ȥ����
 *  0 ����ꤹ��ȥ롼�����Τ�������ʤ���
 */
#define NUM_ND6_DEF_RTR_ENTRY	2

/*
 *  ��ư���Υ롼���������ϲ����
 *  0 ����ꤹ��ȥ롼����������Ϥ��ʤ���
 */
#define NUM_ND6_RTR_SOL_RETRY	3	

#endif	/* of #ifdef SUPPORT_ETHER */

#define TMO_ND6_NS_OUTPUT	1000	/* [ms]�������������ϥ����ॢ����		*/
#define TMO_ND6_NA_OUTPUT	1000	/* [ms]���������ν��ϥ����ॢ����		*/
#define TMO_ND6_RS_OUTPUT	1000	/* [ms]���롼���������ϥ����ॢ����		*/
#define TMO_ND6_RTR_SOL_DELAY	1000	/* [ms]���롼�����������ٱ�			*/
#define TMO_ND6_RTR_SOL_INTERVAL	\
				3000	/* [ms]���롼���������ϴֳ�			*/

/*
 *  �ǡ�������� (�ͥåȥ�����󥿥ե�����) �˴ؤ������
 */

/*
 *  PPP �˴ؤ������
 */

#define NUM_DTQ_PPP_OUTPUT	2	/* PPP ���ϥǡ������塼��������2 �ʾ�	*/

#define	PPP_INPUT_STACK_SIZE	1024	/* PPP �������Υ����å�������		*/
#define	PPP_OUTPUT_STACK_SIZE	1024	/* PPP ���ϥ������Υ����å�������		*/

#define PPP_INPUT_PRIORITY	5	/* PPP ��������ͥ����			*/
#define PPP_OUTPUT_PRIORITY	5	/* PPP ��������ͥ����			*/

#define TMO_PPP_GET_NET_BUF	1000	/* [ms]�������� net_buf ���������ॢ����	*/

/*
 *  PPP����ǥ�˴ؤ������
 */

#define MODEM_CFG_DIAL		"ATD"	/* �������륳�ޥ��ʸ����			*/
#define MODEM_CFG_RETRY_CNT	3	/* ���������ȥ饤���			*/
#define MODEM_CFG_RETRY_WAIT	10000	/* ���������ȥ饤�ޤǤ��Ԥ����� [ms]	*/

/*
 *  PPP��HDLC �˴ؤ������
 */

#define DEF_LOCAL_ACCM		0x000a0000	/* ��ʬ�� ACCM��XON �� XOFF �Τ��Ѵ�	*/
#define DEF_REMOTE_ACCM		0xffffffff	/* ���� ACCM������ͤ������Ѵ�		*/

/*
 *  PPP��LCP �˴ؤ������
 */

#define LCP_CFG_MRU		0x0001	/* MRU					*/
#define LCP_CFG_ACCM		0x0002	/* ACCM					*/
#define LCP_CFG_MAGIC		0x0004	/* �ޥ��å��ֹ�				*/
#define LCP_CFG_PCOMP		0x0008	/* �ץ�ȥ��������̵�ǽ			*/
#define LCP_CFG_ACCOMP		0x0010	/* ���ɥ쥹������������			*/
#define LCP_CFG_PAP		0x0020	/* PAP					*/
/*#define LCP_CFG_CHAP		0x0040	   CHAP �ϼ���ͽ��			*/

#ifdef LCP_CFG_MAGIC

#define LCP_ECHO_INTERVAL	(20*NET_TIMER_HZ)	/* ���󥿡��Х����		*/
#define LCP_ECHO_FAILS		9			/* ��������			*/

#endif	/* of #ifdef LCP_CFG_MAGIC */

/*
 *  PPP��PAP �˴ؤ������
 */

#define DEF_PAP_TIMEOUT		(3*NET_TIMER_HZ)
#define DEF_PAP_REQTIME		(30*NET_TIMER_HZ)	/* �����ॢ���Ƚ�����Ԥ��Ȥ��ϥ����Ȥ򳰤���*/
#define MAX_PAP_REXMT		10			/* ǧ���׵�κ���������	*/

/*
 *  ARP �˴ؤ������
 */

#define NUM_ARP_ENTRY		10			/* ARP ����å��奨��ȥ��	*/
#define ARP_CACHE_KEEP		(20*60*NET_TIMER_HZ)	/* ARP ����å���Υ����ॢ����	*/
#define TMO_ARP_GET_NET_BUF	1000	/* [ms]�����ɥ쥹����׵��� net_buf ���������ॢ����*/
#define TMO_ARP_OUTPUT		1000	/* [ms]�����ɥ쥹����׵���ϥ����ॢ����	*/

/*
 *  DHCP �˴ؤ������
 *
 *    �����: TINET �ϡ�DHCP ��������Ƥ��ʤ������ѥץ����ǡ�
 *            DHCP ��å�������������뤿�������Ǥ��롣
 *            �ޤ������ߤ� IPv4 �Τ�ͭ���Ǥ��롣
 */

/*#define DHCP_CFG					 DHCP �����������ϥ����Ȥ򳰤���*/

/*
 *  Ethernet �˴ؤ������
 */

#define NUM_DTQ_ETHER_OUTPUT	2	/* Ethernet ���ϥǡ������塼������	*/

#define	ETHER_INPUT_STACK_SIZE	1024	/* Ethernet ���ϥ������Υ����å�������	*/
#define	ETHER_OUTPUT_STACK_SIZE	1024	/* Ethernet ���ϥ������Υ����å�������	*/

#define ETHER_INPUT_PRIORITY	5	/* Ethernet ���ϥ�������ͥ����		*/
#define ETHER_OUTPUT_PRIORITY	5	/* Ethernet ���ϥ�������ͥ����		*/

/*#define ETHER_CFG_ACCEPT_ALL		 �ޥ�����㥹�ȡ����顼�ե졼����������Ȥ��ϥ����Ȥ򳰤���	*/
/*#define ETHER_CFG_UNEXP_WARNING	 �󥵥ݡ��ȥե졼��ηٹ��ɽ������Ȥ��ϥ����Ȥ򳰤���		*/
/*#define ETHER_CFG_802_WARNING		 IEEE 802.3 �ե졼��ηٹ��ɽ������Ȥ��ϥ����Ȥ򳰤���		*/
/*#define ETHER_CFG_MCAST_WARNING	 �ޥ�����㥹�Ȥηٹ��ɽ������Ȥ��ϥ����Ȥ򳰤���		*/

/*
 *  �롼�ץХå����󥿥ե������˴ؤ������
 */

#define LOMTU			1500	/* �롼�ץХå��� MTU			*/

#define NUM_DTQ_LOOP_INPUT	0	/* �롼�ץХå����ϥǡ������塼������	*/
#define NUM_DTQ_LOOP_OUTPUT	0	/* �롼�ץХå����ϥǡ������塼������	*/

#define	LOOP_INPUT_STACK_SIZE	1024	/* �롼�ץХå����ϥ������Υ����å�������	*/
#define	LOOP_OUTPUT_STACK_SIZE	1024	/* �롼�ץХå����ϥ������Υ����å�������	*/

#define LOOP_INPUT_PRIORITY	5	/* �롼�ץХå����ϥ�������ͥ����		*/
#define LOOP_OUTPUT_PRIORITY	5	/* �롼�ץХå����ϥ�������ͥ����		*/

/*
 *  �ͥåȥ���˴ؤ������
 */

/* �ͥåȥ�������ޥ����� */

#define	NET_TIMER_STACK_SIZE	1024	/* �ͥåȥ�������ޥ������Υ����å������� */
#define NET_TIMER_PRIORITY	5	/* �ͥåȥ�������ޥ�������ͥ���� */

#define NUM_NET_CALLOUT		10	/* �����ॢ���ȸƽФ�����10 �ʾ�	*/

/* net_buf �� */

#ifdef SUPPORT_PPP

/*
 *  PPP �Ǥϡ������Ѥ� net_buf �� PDU (1502) ����������
 *  ������Ƥʤ���Фʤ�ʤ��Τ� PDU ��������¿��˳��ݤ��롣
 *  128 �������� net_buf �ϡ�TCP ���������Ѥ�¿��˳��ݤ��롣
 */

#define NUM_MPF_NET_BUF_128	2	/* net_buf ����128��2 �ʾ�	*/
#define NUM_MPF_NET_BUF_256	4	/* net_buf ����256		*/
#define NUM_MPF_NET_BUF_512	1	/* net_buf ����512		*/
#define NUM_MPF_NET_BUF_1024	1	/* net_buf ����1024		*/
#define NUM_MPF_NET_BUF_IF_PDU	1	/* net_buf ����PDU		*/

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)

#ifndef NUM_MPF_NET_BUF_4096
#define NUM_MPF_NET_BUF_4096	2	/* net_buf ����4096		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_4096 */

#endif	/* of #if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT) */

#endif	/* of #ifdef SUPPORT_PPP */

#ifdef SUPPORT_ETHER

/*
 *  �������ͥåȤǤϡ������Ѥ� net_buf �ϡ�NIC �ΥХåե��ˤ���
 *  �ե졼��Ĺ�򸫤Ƴ�����Ƥ�Ф褤��
 *  TCP �κ��祻�����ȥ������� 1024 �����ƥåȤ� net_buf ��Ĵ��������ϡ�
 *  ���Υ������� net_buf ��¿��˳��ݤ��롣
 *  128 �������� net_buf �⡢TCP �����楻�������Ѥ�¿��˳��ݤ��롣
 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	4	/* net_buf ����128��2 �ʾ�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	2	/* net_buf ����256		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	2	/* net_buf ����512		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	2	/* net_buf ����1024		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	4	/* net_buf ����PDU		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)

#ifndef NUM_MPF_NET_BUF_4096
#define NUM_MPF_NET_BUF_4096	2	/* net_buf ����4096		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_4096 */

#endif	/* of #if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT) */

#endif	/* of #ifdef SUPPORT_ETHER */

#ifdef SUPPORT_LOOP

#define NUM_MPF_NET_BUF_128	2	/* net_buf ����128��2 �ʾ�	*/
#define NUM_MPF_NET_BUF_256	2	/* net_buf ����256		*/
#define NUM_MPF_NET_BUF_512	2	/* net_buf ����512		*/
#define NUM_MPF_NET_BUF_1024	2	/* net_buf ����1024		*/
#define NUM_MPF_NET_BUF_IF_PDU	2	/* net_buf ����PDU		*/

#endif	/* of #ifdef SUPPORT_PPP */

/*
 *  �ͥåȥ�����׾���η�¬
 *
 *  �ͥåȥ�����׾���η�¬��Ԥ����ϡ�tinet/include/net/net.h
 *  ���������Ƥ���ץ�ȥ��뼱�̥ե饰����ꤹ�롣
 */

#if 1

#ifdef SUPPORT_INET4

#define NET_COUNT_ENABLE	(0			\
				| PROTO_FLG_PPP_HDLC	\
				| PROTO_FLG_PPP_PAP	\
				| PROTO_FLG_PPP_LCP	\
				| PROTO_FLG_PPP_IPCP	\
				| PROTO_FLG_PPP		\
				| PROTO_FLG_LOOP	\
				| PROTO_FLG_ETHER_NIC	\
				| PROTO_FLG_ETHER	\
				| PROTO_FLG_ARP		\
				| PROTO_FLG_IP4		\
				| PROTO_FLG_ICMP4	\
				| PROTO_FLG_UDP		\
				| PROTO_FLG_TCP		\
				| PROTO_FLG_NET_BUF	\
				)

#endif	/* of #ifdef SUPPORT_INET4 */

#ifdef SUPPORT_INET6

#define NET_COUNT_ENABLE	(0			\
				| PROTO_FLG_PPP_HDLC	\
				| PROTO_FLG_PPP_PAP	\
				| PROTO_FLG_PPP_LCP	\
				| PROTO_FLG_PPP_IPCP	\
				| PROTO_FLG_PPP		\
				| PROTO_FLG_LOOP	\
				| PROTO_FLG_ETHER_NIC	\
				| PROTO_FLG_ETHER	\
				| PROTO_FLG_IP6		\
				| PROTO_FLG_ICMP6	\
				| PROTO_FLG_ND6		\
				| PROTO_FLG_UDP		\
				| PROTO_FLG_TCP		\
				| PROTO_FLG_NET_BUF	\
				)

#endif	/* of #ifdef SUPPORT_INET6 */

#else	/* of #if 0 */

#define NET_COUNT_ENABLE	(0			\
				)

#endif	/* of #if 0 */

#endif /* _TINET_CPU_CONFIG_H_ */
