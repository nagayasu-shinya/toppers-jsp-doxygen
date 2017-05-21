/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2010 by Cronus Computer Works, JAPAN
 *
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ���
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ���ξ��Τ����줫�����������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ�������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 *
 *  @(#) $Id
 */

#ifndef _SH7263_H_
#define _SH7263_H_

#include <sil.h>

/*
 *  ����ߥ٥����ֹ�
 */
#define INT_IRQ0        64          /* IRQ0 (����������) */
#define INT_IRQ1        65          /* IRQ1 (����������) */
#define INT_IRQ2        66          /* IRQ2 (����������) */
#define INT_IRQ3        67          /* IRQ3 (����������) */
#define INT_IRQ4        68          /* IRQ4 (����������) */
#define INT_IRQ5        69          /* IRQ5 (����������) */
#define INT_IRQ6        70          /* IRQ6 (����������) */
#define INT_IRQ7        71          /* IRQ7 (����������) */
#define INT_PINT0       80          /* PINT0 (����������) */
#define INT_PINT1       81          /* PINT1 (����������) */
#define INT_PINT2       82          /* PINT2 (����������) */
#define INT_PINT3       83          /* PINT3 (����������) */
#define INT_PINT4       84          /* PINT4 (����������) */
#define INT_PINT5       85          /* PINT5 (����������) */
#define INT_PINT6       86          /* PINT6 (����������) */
#define INT_PINT7       87          /* PINT7 (����������) */
#define INT_DEI0        108         /* DMAC����ͥ�0 �ȥ�󥹥ե������ */
#define INT_HEI0        109         /* DMAC����ͥ�0 �ϡ��ե���� */
#define INT_DEI1        112         /* DMAC����ͥ�1 �ȥ�󥹥ե������ */
#define INT_HEI1        113         /* DMAC����ͥ�1 �ϡ��ե���� */
#define INT_DEI2        116         /* DMAC����ͥ�2 �ȥ�󥹥ե������ */
#define INT_HEI2        117         /* DMAC����ͥ�2 �ϡ��ե���� */
#define INT_DEI3        120         /* DMAC����ͥ�3 �ȥ�󥹥ե������ */
#define INT_HEI3        121         /* DMAC����ͥ�3 �ϡ��ե���� */
#define INT_DEI4        124         /* DMAC����ͥ�4 �ȥ�󥹥ե������ */
#define INT_HEI4        125         /* DMAC����ͥ�4 �ϡ��ե���� */
#define INT_DEI5        128         /* DMAC����ͥ�5 �ȥ�󥹥ե������ */
#define INT_HEI5        129         /* DMAC����ͥ�5 �ϡ��ե���� */
#define INT_DEI6        132         /* DMAC����ͥ�6 �ȥ�󥹥ե������ */
#define INT_HEI6        133         /* DMAC����ͥ�6 �ϡ��ե���� */
#define INT_DEI7        136         /* DMAC����ͥ�7 �ȥ�󥹥ե������ */
#define INT_HEI7        137         /* DMAC����ͥ�7 �ϡ��ե���� */
#define INT_USBI        140         /* USB����ȥ��� */
#define INT_LCDCI       141         /* LCD����ȥ��� */
#define INT_CMI0        142         /* CMT����ͥ�0 ����ڥ��ޥå� */
#define INT_CMI1        143         /* CMT����ͥ�1 ����ڥ��ޥå� */
#define INT_CMI         144         /* BSC ��ե�å��奿���ޥ���ڥ��ޥå� */
#define INT_ITI         145         /* WDT ���󥿡��Х륿���޳����� */
#define INT_TGI0A       146         /* MTU2 TGRA0 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI0B       147         /* MTU2 TGRB0 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI0C       148         /* MTU2 TGRC0 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI0D       149         /* MTU2 TGRD0 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI0V       150         /* MTU2 TCNT0 �����Хե� */
#define INT_TGI0E       151         /* MTU2 TGRE0 ����ڥ��ޥå� */
#define INT_TGI0F       152         /* MTU2 TGRF0 ����ڥ��ޥå� */
#define INT_TGI1A       153         /* MTU2 TGRA1 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI1B       154         /* MTU2 TGRB1 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI1V       155         /* MTU2 TCNT1 �����Хե� */
#define INT_TGI1U       156         /* MTU2 TCNT1 ������ե� */
#define INT_TGI2A       157         /* MTU2 TGRA2 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI2B       158         /* MTU2 TGRA2 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI2V       159         /* MTU2 TCNT2 �����Хե� */
#define INT_TGI2U       160         /* MTU2 TCNT2 ������ե� */
#define INT_TGI3A       161         /* MTU2 TGRA3 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI3B       162         /* MTU2 TGRB3 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI3C       163         /* MTU2 TGRC3 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI3D       164         /* MTU2 TGRD3 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI3V       165         /* MTU2 TCNT3 �����Хե� */
#define INT_TGI4A       166         /* MTU2 TGRA4 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI4B       167         /* MTU2 TGRB4 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI4C       168         /* MTU2 TGRC4 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI4D       169         /* MTU2 TGRD4 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI4V       170         /* MTU2 TCNT4 �����Хե���������ե� */
#define INT_ADI         171         /* A/D�Ѵ��� �Ѵ���λ */
#define INT_IIC3STPI0   172         /* IIC3����ͥ�0 ��߾�︡�� */
#define INT_IIC3NAKI0   173         /* IIC3����ͥ�0 NACK ���� */
#define INT_IIC3RXI0    174         /* IIC3����ͥ�0 �����ǡ����ե� */
#define INT_IIC3TXI0    175         /* IIC3����ͥ�0 �����ǡ�������ץƥ� */
#define INT_IIC3TEI0    176         /* IIC3����ͥ�0 ������λ */
#define INT_IIC3STPI1   177         /* IIC3����ͥ�1 ��߾�︡�� */
#define INT_IIC3NAKI1   178         /* IIC3����ͥ�1 NACK ���� */
#define INT_IIC3RXI1    179         /* IIC3����ͥ�1 �����ǡ����ե� */
#define INT_IIC3TXI1    180         /* IIC3����ͥ�1 �����ǡ�������ץƥ� */
#define INT_IIC3TEI1    181         /* IIC3����ͥ�1 ������λ */
#define INT_IIC3STPI2   182         /* IIC3����ͥ�2 ��߾�︡�� */
#define INT_IIC3NAKI2   183         /* IIC3����ͥ�2 NACK ���� */
#define INT_IIC3RXI2    184         /* IIC3����ͥ�2 �����ǡ����ե� */
#define INT_IIC3TXI2    185         /* IIC3����ͥ�2 �����ǡ�������ץƥ� */
#define INT_IIC3TEI2    186         /* IIC3����ͥ�2 ������λ */
#define INT_IIC3STPI3   187         /* IIC3����ͥ�3 ��߾�︡�� */
#define INT_IIC3NAKI3   188         /* IIC3����ͥ�3 NACK ���� */
#define INT_IIC3RXI3    189         /* IIC3����ͥ�3 �����ǡ����ե� */
#define INT_IIC3TXI3    190         /* IIC3����ͥ�3 �����ǡ�������ץƥ� */
#define INT_IIC3TEI3    191         /* IIC3����ͥ�3 ������λ */
#define INT_BRI0        192         /* SCIF����ͥ�0 �֥졼������ */
#define INT_ERI0        193         /* SCIF����ͥ�0 �������顼 */
#define INT_RXI0        194         /* SCIF����ͥ�0 �����ǡ����ե� */
#define INT_TXI0        195         /* SCIF����ͥ�0 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI1        196         /* SCIF����ͥ�1 �֥졼������ */
#define INT_ERI1        197         /* SCIF����ͥ�1 �������顼 */
#define INT_RXI1        198         /* SCIF����ͥ�1 �����ǡ����ե� */
#define INT_TXI1        199         /* SCIF����ͥ�1 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI2        200         /* SCIF����ͥ�2 �֥졼������ */
#define INT_ERI2        201         /* SCIF����ͥ�2 �������顼 */
#define INT_RXI2        202         /* SCIF����ͥ�2 �����ǡ����ե� */
#define INT_TXI2        203         /* SCIF����ͥ�2 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI3        204         /* SCIF����ͥ�3 �֥졼������ */
#define INT_ERI3        205         /* SCIF����ͥ�3 �������顼 */
#define INT_RXI3        206         /* SCIF����ͥ�3 �����ǡ����ե� */
#define INT_TXI3        207         /* SCIF����ͥ�3 ����FIFO�ǡ�������ץƥ� */
#define INT_SSERI0      208         /* SSU����ͥ�0 ���顼 */
#define INT_SSRXI0      209         /* SSU����ͥ�0 �����ǡ����ե� */
#define INT_SSTXI0      210         /* SSU����ͥ�0 �����ǡ�������ץƥ�/������λ */
#define INT_SSERI1      211         /* SSU����ͥ�1 ���顼 */
#define INT_SSRXI1      212         /* SSU����ͥ�1 �����ǡ����ե� */
#define INT_SSTXI1      213         /* SSU����ͥ�1 �����ǡ�������ץƥ�/������λ */
#define INT_SSI0        214         /* SSI����ͥ�0 ������ */
#define INT_SSI1        215         /* SSI����ͥ�1 ������ */
#define INT_SSI2        216         /* SSI����ͥ�2 ������ */
#define INT_SSI3        217         /* SSI����ͥ�3 ������ */
#define INT_ISY         218         /* CD-ROM�ǥ����� Ʊ�������ɰ۾勵���ߥ� */
#define INT_IERR        219         /* CD-ROM�ǥ����� ECC���顼 */
#define INT_IARG        220         /* CD-ROM�ǥ����� ITARG������ */
#define INT_ISEC        221         /* CD-ROM�ǥ����� �������ڤ��ؤ�� */
#define INT_IBUF        222         /* CD-ROM�ǥ����� �Хåե��ǡ���ž���������� */
#define INT_IREDAY      223         /* CD-ROM�ǥ����� �Хåե��ǡ���ž���׵� */
#define INT_FLSTEI      224         /* NAND�ե�å��女��ȥ��� STEI�װ�������� */
#define INT_FLTENDI     225         /* NAND�ե�å��女��ȥ��� ž����λ */
#define INT_FLTREQ0I    226         /* NAND�ե�å��女��ȥ��� FIFO0ž���׵� */
#define INT_FLTREQ1I    227         /* NAND�ե�å��女��ȥ��� FIFO0ž���׵� */
#define INT_SDHI3       228         /* SD�ۥ��ȥ��󥿡��ե����� SDHI3������ */
#define INT_SDHI0       229         /* SD�ۥ��ȥ��󥿡��ե����� SDHI0������ */
#define INT_SDHI1       230         /* SD�ۥ��ȥ��󥿡��ե����� SDHI1������ */
#define INT_ARM         231         /* RTC ���顼������� */
#define INT_PRD         232         /* RTC ���������� */
#define INT_CUP         233         /* RTC ��夲������ */
#define INT_ERS0        234         /* RCAN����ͥ�0 ERS�װ������� */
#define INT_OVR0        235         /* RCAN����ͥ�0 OVR�װ������� */
#define INT_RM00        236         /* RCAN����ͥ�0 �ǡ����ե졼����� */
#define INT_RM10        237         /* RCAN����ͥ�0 ��⡼�ȥե졼����� */
#define INT_SLE0        238         /* RCAN����ͥ�0 ��å��������� */
#define INT_ERS1        239         /* RCAN����ͥ�1 ERS�װ������� */
#define INT_OVR1        240         /* RCAN����ͥ�1 OVR�װ������� */
#define INT_RM01        241         /* RCAN����ͥ�1 �ǡ����ե졼����� */
#define INT_RM11        242         /* RCAN����ͥ�1 ��⡼�ȥե졼����� */
#define INT_SLE1        243         /* RCAN����ͥ�1 ��å��������� */
#define INT_OVF         244         /* SRC ���ϥǡ���FIFO�����С��饤�� */
#define INT_ODFI        245         /* SRC ���ϥǡ���FIFO�ե� */
#define INT_IDEI        246         /* SRC ���ϥǡ���FIFO����ץƥ� */
#define INT_IEBI        247         /* IEBus����ȥ��� ������ */

#ifndef _MACRO_ONLY

/*
 *  ��¢�⥸�塼��Υ쥸����
 */
/* ����å��� */
#define CCR1        ((VW *)0xFFFC1000)  /* ����å�������쥸����1 */
#define CCR2        ((VW *)0xFFFC1004)  /* ����å�������쥸����2 */

/* ����å�ȯ���� (CPG) */
#define FRQCR       ((VH *)0xFFFE0010)  /* ���ȿ�����쥸���� */

/* �Х����ơ��ȥ���ȥ��� (BSC) */
#define CMNCR       ((VW *)0xFFFC0000)  /* ���̥���ȥ���쥸���� */
#define CS0BCR      ((VW *)0xFFFC0004)  /* ���ꥢ0 �Х�����ȥ���쥸���� */
#define CS1BCR      ((VW *)0xFFFC0008)  /* ���ꥢ1 �Х�����ȥ���쥸���� */
#define CS2BCR      ((VW *)0xFFFC000C)  /* ���ꥢ2 �Х�����ȥ���쥸���� */
#define CS3BCR      ((VW *)0xFFFC0010)  /* ���ꥢ3 �Х�����ȥ���쥸���� */
#define CS4BCR      ((VW *)0xFFFC0014)  /* ���ꥢ4 �Х�����ȥ���쥸���� */
#define CS5BCR      ((VW *)0xFFFC0018)  /* ���ꥢ5 �Х�����ȥ���쥸���� */
#define CS6BCR      ((VW *)0xFFFC001C)  /* ���ꥢ6 �Х�����ȥ���쥸���� */
#define CS7BCR      ((VW *)0xFFFC0020)  /* ���ꥢ7 �Х�����ȥ���쥸���� */
#define CS0WCR      ((VW *)0xFFFC0028)  /* ���ꥢ0 �������ȥ���ȥ���쥸���� */
#define CS1WCR      ((VW *)0xFFFC002C)  /* ���ꥢ1 �������ȥ���ȥ���쥸���� */
#define CS2WCR      ((VW *)0xFFFC0030)  /* ���ꥢ2 �������ȥ���ȥ���쥸���� */
#define CS3WCR      ((VW *)0xFFFC0034)  /* ���ꥢ3 �������ȥ���ȥ���쥸���� */
#define CS4WCR      ((VW *)0xFFFC0038)  /* ���ꥢ4 �������ȥ���ȥ���쥸���� */
#define CS5WCR      ((VW *)0xFFFC003C)  /* ���ꥢ5 �������ȥ���ȥ���쥸���� */
#define CS6WCR      ((VW *)0xFFFC0040)  /* ���ꥢ6 �������ȥ���ȥ���쥸���� */
#define CS7WCR      ((VW *)0xFFFC0044)  /* ���ꥢ7 �������ȥ���ȥ���쥸���� */
#define SDCR        ((VW *)0xFFFC004C)  /* SDRAM����ȥ���쥸���� */
#define RTCSR       ((VW *)0xFFFC0050)  /* ��ե�å��奿���ޥ���ȥ���/���ơ������쥸���� */
#define RTCNT       ((VW *)0xFFFC0054)  /* ��ե�å��奿���ޥ����� */
#define RTCOR       ((VW *)0xFFFC0058)  /* ��ե�å��奿���ॳ�󥹥���ȥ쥸���� */

/* �����ߥ���ȥ��� (INTC) */
#define ICR0        ((VH *)0xFFFE0800)  /* �����ߥ���ȥ���쥸����0 */
#define ICR1        ((VH *)0xFFFE0802)  /* �����ߥ���ȥ���쥸����1 */
#define ICR2        ((VH *)0xFFFE0804)  /* �����ߥ���ȥ���쥸����2 */
#define IRQRR       ((VH *)0xFFFE0806)  /* IRQ �������׵�쥸���� */
#define PINTER      ((VH *)0xFFFE0808)  /* PINT �����ߥ��͡��֥�쥸���� */
#define PIRR        ((VH *)0xFFFE080A)  /* PINT �������׵�쥸���� */
#define IBCR        ((VH *)0xFFFE080C)  /* �Х󥯥���ȥ���쥸���� */
#define IBNR        ((VH *)0xFFFE080E)  /* �Х��ֹ�쥸���� */
#define IPR01       ((VH *)0xFFFE0818)  /* ������ͥ���٥�����쥸����01 */
#define IPR02       ((VH *)0xFFFE081A)  /* ������ͥ���٥�����쥸����02 */
#define IPR05       ((VH *)0xFFFE0820)  /* ������ͥ���٥�����쥸����05 */
#define IPR06       ((VH *)0xFFFE0C00)  /* ������ͥ���٥�����쥸����06 */
#define IPR07       ((VH *)0xFFFE0C02)  /* ������ͥ���٥�����쥸����07 */
#define IPR08       ((VH *)0xFFFE0C04)  /* ������ͥ���٥�����쥸����08 */
#define IPR09       ((VH *)0xFFFE0C06)  /* ������ͥ���٥�����쥸����09 */
#define IPR10       ((VH *)0xFFFE0C08)  /* ������ͥ���٥�����쥸����10 */
#define IPR11       ((VH *)0xFFFE0C0A)  /* ������ͥ���٥�����쥸����11 */
#define IPR12       ((VH *)0xFFFE0C0C)  /* ������ͥ���٥�����쥸����12 */
#define IPR13       ((VH *)0xFFFE0C0E)  /* ������ͥ���٥�����쥸����13 */
#define IPR14       ((VH *)0xFFFE0C10)  /* ������ͥ���٥�����쥸����14 */
#define IPR16       ((VH *)0xFFFE0C12)  /* ������ͥ���٥�����쥸����15 */
#define IPR15       ((VH *)0xFFFE0C14)  /* ������ͥ���٥�����쥸����16 */
#define IPR17       ((VH *)0xFFFE0C16)  /* ������ͥ���٥�����쥸����17 */

/* ����ڥ��ޥå������� (CMT) */
#define CMSTR       ((VH *)0xFFFEC000)  /* ����ڥ��ޥå������ޥ������ȥ쥸���� */
#define CMCSR_0     ((VH *)0xFFFEC002)  /* ����ͥ�0 ����ڥ��ޥå������󥿥���ȥ���/���ơ������쥸���� */
#define CMCNT_0     ((VH *)0xFFFEC004)  /* ����ͥ�0 ����ڥ��ޥå������� */
#define CMCOR_0     ((VH *)0xFFFEC006)  /* ����ͥ�0 ����ڥ��ޥå����󥹥���ȥ쥸���� */
#define CMCSR_1     ((VH *)0xFFFEC008)  /* ����ͥ�1 ����ڥ��ޥå������󥿥���ȥ���/���ơ������쥸���� */
#define CMCNT_1     ((VH *)0xFFFEC00A)  /* ����ͥ�1 ����ڥ��ޥå������� */
#define CMCOR_1     ((VH *)0xFFFEC00C)  /* ����ͥ�1 ����ڥ��ޥå����󥹥���ȥ쥸���� */

/* �ԥ�ե��󥯥���󥳥�ȥ��� (PFC), I/O�ݡ��� */
#define PADRL       ((VH *)0xFFFE3802)  /* �ݡ���A �ǡ����쥸����L */
#define PBCRL       ((VH *)0xFFFE3882)  /* �ݡ���B �ǡ����쥸����L */
#define PBIORL      ((VH *)0xFFFE3886)  /* �ݡ���B IO�쥸����L */
#define PBCRL4      ((VH *)0xFFFE3890)  /* �ݡ���B ����ȥ���쥸����L4 */
#define PBCRL3      ((VH *)0xFFFE3892)  /* �ݡ���B ����ȥ���쥸����L3 */
#define PBCRL2      ((VH *)0xFFFE3894)  /* �ݡ���B ����ȥ���쥸����L2 */
#define PBCRL1      ((VH *)0xFFFE3896)  /* �ݡ���B ����ȥ���쥸����L1 */
#define PBPRL       ((VH *)0xFFFE389E)  /* �ݡ���B �ݡ��ȥ쥸����L */
#define IFCR        ((VH *)0xFFFE38A2)  /* IRQOUT��ǽ����ȥ���쥸���� */
#define PCCRL       ((VH *)0xFFFE3902)  /* �ݡ���C �ǡ����쥸����L */
#define PCIORL      ((VH *)0xFFFE3906)  /* �ݡ���C IO�쥸����L */
#define PCCRL4      ((VH *)0xFFFE3910)  /* �ݡ���C ����ȥ���쥸����L4 */
#define PCCRL3      ((VH *)0xFFFE3912)  /* �ݡ���C ����ȥ���쥸����L3 */
#define PCCRL2      ((VH *)0xFFFE3914)  /* �ݡ���C ����ȥ���쥸����L2 */
#define PCCRL1      ((VH *)0xFFFE3916)  /* �ݡ���C ����ȥ���쥸����L1 */
#define PCPRL       ((VH *)0xFFFE391E)  /* �ݡ���C �ݡ��ȥ쥸����L */
#define PDCRL       ((VH *)0xFFFE3982)  /* �ݡ���D �ǡ����쥸����L */
#define PDIORL      ((VH *)0xFFFE3986)  /* �ݡ���D IO�쥸����L */
#define PDCRL4      ((VH *)0xFFFE3990)  /* �ݡ���D ����ȥ���쥸����L4 */
#define PDCRL3      ((VH *)0xFFFE3992)  /* �ݡ���D ����ȥ���쥸����L3 */
#define PDCRL2      ((VH *)0xFFFE3994)  /* �ݡ���D ����ȥ���쥸����L2 */
#define PDCRL1      ((VH *)0xFFFE3996)  /* �ݡ���D ����ȥ���쥸����L1 */
#define PDPRL       ((VH *)0xFFFE399E)  /* �ݡ���D �ݡ��ȥ쥸����L */
#define PECRL       ((VH *)0xFFFE3A02)  /* �ݡ���E �ǡ����쥸����L */
#define PEIORL      ((VH *)0xFFFE3A06)  /* �ݡ���E IO�쥸����L */
#define PECRL4      ((VH *)0xFFFE3A10)  /* �ݡ���E ����ȥ���쥸����L4 */
#define PECRL3      ((VH *)0xFFFE3A12)  /* �ݡ���E ����ȥ���쥸����L3 */
#define PECRL2      ((VH *)0xFFFE3A14)  /* �ݡ���E ����ȥ���쥸����L2 */
#define PECRL1      ((VH *)0xFFFE3A16)  /* �ݡ���E ����ȥ���쥸����L1 */
#define PEPRL       ((VH *)0xFFFE3A1E)  /* �ݡ���E �ݡ��ȥ쥸����L */
#define PFCRH       ((VH *)0xFFFE3A80)  /* �ݡ���E �ǡ����쥸����H */
#define PFCRL       ((VH *)0xFFFE3A82)  /* �ݡ���E �ǡ����쥸����L */
#define PFIORH      ((VH *)0xFFFE3A84)  /* �ݡ���F IO�쥸����H */
#define PFIORL      ((VH *)0xFFFE3A86)  /* �ݡ���F IO�쥸����L */
#define PFCRH4      ((VH *)0xFFFE3A88)  /* �ݡ���F ����ȥ���쥸����H4 */
#define PFCRH3      ((VH *)0xFFFE3A8A)  /* �ݡ���F ����ȥ���쥸����H3 */
#define PFCRH2      ((VH *)0xFFFE3A8C)  /* �ݡ���F ����ȥ���쥸����H2 */
#define PFCRH1      ((VH *)0xFFFE3A8E)  /* �ݡ���F ����ȥ���쥸����H1 */
#define PFCRL4      ((VH *)0xFFFE3A90)  /* �ݡ���F ����ȥ���쥸����L4 */
#define PFCRL3      ((VH *)0xFFFE3A92)  /* �ݡ���F ����ȥ���쥸����L3 */
#define PFCRL2      ((VH *)0xFFFE3A94)  /* �ݡ���F ����ȥ���쥸����L2 */
#define PFCRL1      ((VH *)0xFFFE3A96)  /* �ݡ���F ����ȥ���쥸����L1 */
#define PFPRH       ((VH *)0xFFFE3A9C)  /* �ݡ���E �ݡ��ȥ쥸����H */
#define PFPRL       ((VH *)0xFFFE3A9E)  /* �ݡ���E �ݡ��ȥ쥸����L */
#define SCSR        ((VH *)0xFFFE3AA2)  /* SSI����å�����쥸���� */

/* ��������ϥ⡼�� */
#define STBCR       ((VB *)0xFFFE0014)  /* ������Х�����ȥ���쥸���� */
#define STBCR2      ((VB *)0xFFFE0018)  /* ������Х�����ȥ���쥸����2 */
#define STBCR3      ((VB *)0xFFFE0408)  /* ������Х�����ȥ���쥸����3 */
#define STBCR4      ((VB *)0xFFFE040C)  /* ������Х�����ȥ���쥸����4 */
#define STBCR5      ((VB *)0xFFFE0410)  /* ������Х�����ȥ���쥸����5 */
#define STBCR6      ((VB *)0xFFFE0414)  /* ������Х�����ȥ���쥸����6 */
#define SYSCR1      ((VB *)0xFFFE0402)  /* �����ƥॳ��ȥ���쥸����1 */
#define SYSCR2      ((VB *)0xFFFE0404)  /* �����ƥॳ��ȥ���쥸����2 */
#define SYSCR3      ((VB *)0xFFFE0418)  /* �����ƥॳ��ȥ���쥸����3 */
#define DSCTR       ((VB *)0xFFFE2800)  /* �ǥ����ץ�����Х�����ȥ���쥸���� */
#define DSCTR2      ((VB *)0xFFFE2802)  /* �ǥ����ץ�����Х�����ȥ���쥸����2 */
#define DSSSR       ((VH *)0xFFFE2804)  /* �ǥ����ץ�����Х�����װ����쥯�ȥ쥸���� */
#define DSFR        ((VH *)0xFFFE2808)  /* �ǥ����ץ�����Х�������å����쥯�ȥ쥸���� */
#define DSRTR       ((VB *)0xFFFE280C)  /* �ݻ�����¢RAM�ȥ�ߥ󥰥쥸���� */

/* FIFO�դ����ꥢ�륳�ߥ�˥�������󥤥󥿡��ե����� (SCIF) */

#define SCIF0_BASE  ((UW)0xFFFE8000)    /* ����ͥ�0 �쥸�����١������ɥ쥹 */
#define SCIF1_BASE  ((UW)0xFFFE8800)    /* ����ͥ�1 �쥸�����١������ɥ쥹 */
#define SCIF2_BASE  ((UW)0xFFFE9000)    /* ����ͥ�2 �쥸�����١������ɥ쥹 */
#define SCIF3_BASE  ((UW)0xFFFE9800)    /* ����ͥ�3 �쥸�����١������ɥ쥹 */

/*
 * �����ߥ���ȥ���ν����
 */
Inline void sh2_init_intcontorller(void)
{
	/* �Х��ֹ�쥸���������� */
	sil_wrh_mem(IBNR, 0x0000);		/* BE=00, BOVE=0                         */
									/*  ���٤Ƥγ����ߤǥХ󥯻��Ѷػ�     */
									/*  �쥸�����Х󥯥����С��ե��㳰�ػ� */
	/* ������ͥ���٥�����쥸���������� */
	sil_wrh_mem (IPR01, 0x0000);
	sil_wrh_mem (IPR02, 0x0000);
	sil_wrh_mem (IPR05, 0x0000);
	sil_wrh_mem (IPR06, 0x0000);
	sil_wrh_mem (IPR07, 0x0000);
	sil_wrh_mem (IPR08, 0x0000);
	sil_wrh_mem (IPR09, 0x0000);
	sil_wrh_mem (IPR10, 0x0000);
	sil_wrh_mem (IPR11, 0x0000);
	sil_wrh_mem (IPR12, 0x0000);
	sil_wrh_mem (IPR13, 0x0000);
	sil_wrh_mem (IPR14, 0x0000);
	sil_wrh_mem (IPR15, 0x0000);
	sil_wrh_mem (IPR16, 0x0000);
	sil_wrh_mem (IPR17, 0x0000);
}

#endif /* _MACRO_ONLY */

#endif /* _SH7263_H_ */
