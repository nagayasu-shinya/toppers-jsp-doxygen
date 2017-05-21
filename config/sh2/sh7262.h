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

#ifndef _SH7262_H_
#define _SH7262_H_

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
#define INT_DEI8        140         /* DMAC����ͥ�8 �ȥ�󥹥ե������ */
#define INT_HEI8        141         /* DMAC����ͥ�8 �ϡ��ե���� */
#define INT_DEI9        144         /* DMAC����ͥ�9 �ȥ�󥹥ե������ */
#define INT_HEI9        145         /* DMAC����ͥ�9 �ϡ��ե���� */
#define INT_DEI10       148         /* DMAC����ͥ�10 �ȥ�󥹥ե������ */
#define INT_HEI10       149         /* DMAC����ͥ�10 �ϡ��ե���� */
#define INT_DEI11       152         /* DMAC����ͥ�11 �ȥ�󥹥ե������ */
#define INT_HEI11       153         /* DMAC����ͥ�11 �ϡ��ե���� */
#define INT_DEI12       156         /* DMAC����ͥ�12 �ȥ�󥹥ե������ */
#define INT_HEI12       157         /* DMAC����ͥ�12 �ϡ��ե���� */
#define INT_DEI13       160         /* DMAC����ͥ�13 �ȥ�󥹥ե������ */
#define INT_HEI13       161         /* DMAC����ͥ�13 �ϡ��ե���� */
#define INT_DEI14       164         /* DMAC����ͥ�14 �ȥ�󥹥ե������ */
#define INT_HEI14       165         /* DMAC����ͥ�14 �ϡ��ե���� */
#define INT_DEI15       168         /* DMAC����ͥ�15 �ȥ�󥹥ե������ */
#define INT_HEI15       169         /* DMAC����ͥ�15 �ϡ��ե���� */
#define INT_USBI        170         /* USB����ȥ��� */
#define INT_VIVSYNCJ    171         /* �ӥǥ��ǥ����ץ쥤����ȥ���3 VSYNC������측�� */
#define INT_VBUFFER     172         /* �ӥǥ��ǥ����ץ쥤����ȥ���3 �Хåե����顼 */
#define INT_VIFIELDE    173         /* �ӥǥ��ǥ����ץ쥤����ȥ���3 �ե�����ɽ񤭹��ߴ�λ */
#define INT_VOLINE      174         /* �ӥǥ��ǥ����ץ쥤����ȥ���3 �饤������� */
#define INT_CMI0        175         /* CMT����ͥ�0 ����ڥ��ޥå� */
#define INT_CMI1        176         /* CMT����ͥ�1 ����ڥ��ޥå� */
#define INT_CMI         177         /* BSC ��ե�å��奿���ޥ���ڥ��ޥå� */
#define INT_ITI         178         /* WDT ���󥿡��Х륿���޳����� */
#define INT_TGI0A       179         /* MTU2 TGRA0 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI0B       180         /* MTU2 TGRB0 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI0C       181         /* MTU2 TGRC0 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI0D       182         /* MTU2 TGRD0 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI0V       183         /* MTU2 TCNT0 �����Хե� */
#define INT_TGI0E       184         /* MTU2 TGRE0 ����ڥ��ޥå� */
#define INT_TGI0F       185         /* MTU2 TGRF0 ����ڥ��ޥå� */
#define INT_TGI1A       186         /* MTU2 TGRA1 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI1B       187         /* MTU2 TGRB1 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI1V       188         /* MTU2 TCNT1 �����Хե� */
#define INT_TGI1U       189         /* MTU2 TCNT1 ������ե� */
#define INT_TGI2A       190         /* MTU2 TGRA2 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI2B       191         /* MTU2 TGRA2 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI2V       192         /* MTU2 TCNT2 �����Хե� */
#define INT_TGI2U       193         /* MTU2 TCNT2 ������ե� */
#define INT_TGI3A       194         /* MTU2 TGRA3 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI3B       195         /* MTU2 TGRB3 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI3C       196         /* MTU2 TGRC3 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI3D       197         /* MTU2 TGRD3 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI3V       198         /* MTU2 TCNT3 �����Хե� */
#define INT_TGI4A       199         /* MTU2 TGRA4 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI4B       200         /* MTU2 TGRB4 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI4C       201         /* MTU2 TGRC4 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI4D       202         /* MTU2 TGRD4 ����ץåȥ���ץ��㡿����ڥ��ޥå� */
#define INT_TGI4V       203         /* MTU2 TCNT4 �����Хե���������ե� */
#define INT_CMF1        204         /* PWM����ͥ�1 ����ڥ��ޥå��ե饰 */
#define INT_CMF2        205         /* PWM����ͥ�2 ����ڥ��ޥå��ե饰 */
#define INT_ADI         206         /* A/D�Ѵ��� �Ѵ���λ */
#define INT_SSIF0       207         /* SSI����ͥ�0 SSIF0 */
#define INT_SSIRXI0     208         /* SSI����ͥ�0 SSIRXI0 */
#define INT_SSITXI0     209         /* SSI����ͥ�0 SSITXI0 */
#define INT_SSII1       210         /* SSI����ͥ�1 SSII1 */
#define INT_SSIRTI1     211         /* SSI����ͥ�1 SSIRTI1 */
#define INT_SSII2       212         /* SSI����ͥ�2 SSII2 */
#define INT_SSIRTI2     213         /* SSI����ͥ�2 SSIRTI2 */
#define INT_SSII3       214         /* SSI����ͥ�3 SSII2 */
#define INT_SSIRTI3     215         /* SSI����ͥ�3 SSIRTI2 */
#define INT_SPDIFI      216         /* SPDIF���󥿡��ե����������� */
#define INT_IIC3STPI0   217         /* IIC3����ͥ�0 ��߾�︡�� */
#define INT_IIC3NAKI0   218         /* IIC3����ͥ�0 NACK ���� */
#define INT_IIC3RXI0    219         /* IIC3����ͥ�0 �����ǡ����ե� */
#define INT_IIC3TXI0    220         /* IIC3����ͥ�0 �����ǡ�������ץƥ� */
#define INT_IIC3TEI0    221         /* IIC3����ͥ�0 ������λ */
#define INT_IIC3STPI1   222         /* IIC3����ͥ�1 ��߾�︡�� */
#define INT_IIC3NAKI1   223         /* IIC3����ͥ�1 NACK ���� */
#define INT_IIC3RXI1    224         /* IIC3����ͥ�1 �����ǡ����ե� */
#define INT_IIC3TXI1    225         /* IIC3����ͥ�1 �����ǡ�������ץƥ� */
#define INT_IIC3TEI1    226         /* IIC3����ͥ�1 ������λ */
#define INT_IIC3STPI2   227         /* IIC3����ͥ�2 ��߾�︡�� */
#define INT_IIC3NAKI2   228         /* IIC3����ͥ�2 NACK ���� */
#define INT_IIC3RXI2    229         /* IIC3����ͥ�2 �����ǡ����ե� */
#define INT_IIC3TXI2    230         /* IIC3����ͥ�2 �����ǡ�������ץƥ� */
#define INT_IIC3TEI2    231         /* IIC3����ͥ�2 ������λ */
#define INT_BRI0        232         /* SCIF����ͥ�0 �֥졼������ */
#define INT_ERI0        233         /* SCIF����ͥ�0 �������顼 */
#define INT_RXI0        234         /* SCIF����ͥ�0 �����ǡ����ե� */
#define INT_TXI0        235         /* SCIF����ͥ�0 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI1        236         /* SCIF����ͥ�1 �֥졼������ */
#define INT_ERI1        237         /* SCIF����ͥ�1 �������顼 */
#define INT_RXI1        238         /* SCIF����ͥ�1 �����ǡ����ե� */
#define INT_TXI1        239         /* SCIF����ͥ�1 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI2        240         /* SCIF����ͥ�2 �֥졼������ */
#define INT_ERI2        241         /* SCIF����ͥ�2 �������顼 */
#define INT_RXI2        242         /* SCIF����ͥ�2 �����ǡ����ե� */
#define INT_TXI2        243         /* SCIF����ͥ�2 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI3        244         /* SCIF����ͥ�3 �֥졼������ */
#define INT_ERI3        245         /* SCIF����ͥ�3 �������顼 */
#define INT_RXI3        246         /* SCIF����ͥ�3 �����ǡ����ե� */
#define INT_TXI3        247         /* SCIF����ͥ�3 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI4        248         /* SCIF����ͥ�4 �֥졼������ */
#define INT_ERI4        249         /* SCIF����ͥ�4 �������顼 */
#define INT_RXI4        250         /* SCIF����ͥ�4 �����ǡ����ե� */
#define INT_TXI4        251         /* SCIF����ͥ�4 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI5        252         /* SCIF����ͥ�5 �֥졼������ */
#define INT_ERI5        253         /* SCIF����ͥ�5 �������顼 */
#define INT_RXI5        254         /* SCIF����ͥ�5 �����ǡ����ե� */
#define INT_TXI5        255         /* SCIF����ͥ�5 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI6        256         /* SCIF����ͥ�6 �֥졼������ */
#define INT_ERI6        257         /* SCIF����ͥ�6 �������顼 */
#define INT_RXI6        258         /* SCIF����ͥ�6 �����ǡ����ե� */
#define INT_TXI6        259         /* SCIF����ͥ�6 ����FIFO�ǡ�������ץƥ� */
#define INT_BRI7        260         /* SCIF����ͥ�7 �֥졼������ */
#define INT_ERI7        261         /* SCIF����ͥ�7 �������顼 */
#define INT_RXI7        262         /* SCIF����ͥ�7 �����ǡ����ե� */
#define INT_TXI7        263         /* SCIF����ͥ�7 ����FIFO�ǡ�������ץƥ� */
#define INT_SIOFI       264         /* SIOF������ */
#define INT_SPEI0       265         /* SPI����ͥ�0 ���顼 */
#define INT_SPRI0       266         /* SPI����ͥ�0 �����Хåե��ե� */
#define INT_SPTI0       267         /* SPI����ͥ�0 ��������ץƥ�*/
#define INT_SPEI1       268         /* SPI����ͥ�1 ���顼 */
#define INT_SPRI1       269         /* SPI����ͥ�1 �����Хåե��ե� */
#define INT_SPTI1       270         /* SPI����ͥ�1 ��������ץƥ�*/
#define INT_ERS0        271         /* RCAN����ͥ�0 ERS�װ������� */
#define INT_OVR0        272         /* RCAN����ͥ�0 OVR�װ������� */
#define INT_RM00        273         /* RCAN����ͥ�0 �ǡ����ե졼����� */
#define INT_RM10        274         /* RCAN����ͥ�0 ��⡼�ȥե졼����� */
#define INT_SLE0        275         /* RCAN����ͥ�0 ��å��������� */
#define INT_ERS1        276         /* RCAN����ͥ�1 ERS�װ������� */
#define INT_OVR1        277         /* RCAN����ͥ�1 OVR�װ������� */
#define INT_RM01        278         /* RCAN����ͥ�1 �ǡ����ե졼����� */
#define INT_RM11        279         /* RCAN����ͥ�1 ��⡼�ȥե졼����� */
#define INT_SLE1        280         /* RCAN����ͥ�1 ��å��������� */
#define INT_IEBI        281         /* IEBus����ȥ�������� */
#define INT_ISY         282         /* CD-ROM�ǥ����� Ʊ�������ɰ۾勵���ߥ� */
#define INT_IERR        283         /* CD-ROM�ǥ����� ECC���顼 */
#define INT_IARG        284         /* CD-ROM�ǥ����� ITARG���顼������ */
#define INT_ISEC        285         /* CD-ROM�ǥ����� �������ڤ��ؤ�� */
#define INT_IBUF        286         /* CD-ROM�ǥ����� �Хåե��ǡ���ž���������� */
#define INT_IREDAY      287         /* CD-ROM�ǥ����� �Хåե��ǡ���ž���׵� */
#define INT_FLSTEI      288         /* NAND�ե�å��女��ȥ��� STEI�װ�������� */
#define INT_FLTENDI     289         /* NAND�ե�å��女��ȥ��� ž����λ */
#define INT_FLTREQ0I    290         /* NAND�ե�å��女��ȥ��� FIFO0ž���׵� */
#define INT_FLTREQ1I    291         /* NAND�ե�å��女��ȥ��� FIFO0ž���׵� */
#define INT_SDHI3       292         /* SD�ۥ��ȥ��󥿡��ե����� SDHI3������ */
#define INT_SDHI0       293         /* SD�ۥ��ȥ��󥿡��ե����� SDHI0������ */
#define INT_SDHI1       294         /* SD�ۥ��ȥ��󥿡��ե����� SDHI1������ */
#define INT_ARM         296         /* RTC ���顼������� */
#define INT_PRD         297         /* RTC ���������� */
#define INT_CUP         298         /* RTC ��夲������ */
#define INT_OVF0        299         /* SRC����ͥ�0 ���ϥǡ���FIFO�����С��饤�� */
#define INT_UDF0        300         /* SRC����ͥ�0 ���ϥǡ���FIFO��������ե� */
#define INT_CEF0        301         /* SRC����ͥ�0 �Ѵ�������λ */
#define INT_ODFI0       302         /* SRC����ͥ�0 ���ϥǡ���FIFO�ե� */
#define INT_IDEI0       303         /* SRC����ͥ�0 ���ϥǡ���FIFO����ץƥ� */
#define INT_OVF1        304         /* SRC����ͥ�1 ���ϥǡ���FIFO�����С��饤�� */
#define INT_UDF1        305         /* SRC����ͥ�1 ���ϥǡ���FIFO��������ե� */
#define INT_CEF1        306         /* SRC����ͥ�1 �Ѵ�������λ */
#define INT_ODFI1       307         /* SRC����ͥ�1 ���ϥǡ���FIFO�ե� */
#define INT_IDEI1       308         /* SRC����ͥ�1 ���ϥǡ���FIFO����ץƥ� */
#define INT_DCUEI       310         /* �ǥ���ץ�å�����˥å� DCUEI������ */
#define INT_OFFI        311         /* �ǥ���ץ�å�����˥å� OFFI������ */
#define INT_IFEI        312         /* �ǥ���ץ�å�����˥å� IFEI������ */

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
#define ACSWR       ((VW *)0xFFFC180C)  /* AC�����ڤ��ؤ��쥸���� */
#define ACKEYR      ((VB *)0xFFFC1BFC)  /* AC�����ڤ��ؤ������쥸���� */

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
#define IPR18       ((VH *)0xFFFE0C18)  /* ������ͥ���٥�����쥸����18 */
#define IPR19       ((VH *)0xFFFE0C1A)  /* ������ͥ���٥�����쥸����19 */
#define IPR20       ((VH *)0xFFFE0C1C)  /* ������ͥ���٥�����쥸����20 */
#define IPR21       ((VH *)0xFFFE0C1E)  /* ������ͥ���٥�����쥸����21 */
#define IPR22       ((VH *)0xFFFE0C20)  /* ������ͥ���٥�����쥸����22 */

/* ����ڥ��ޥå������� (CMT) */
#define CMSTR       ((VH *)0xFFFEC000)  /* ����ڥ��ޥå������ޥ������ȥ쥸���� */
#define CMCSR_0     ((VH *)0xFFFEC002)  /* ����ͥ�0 ����ڥ��ޥå������󥿥���ȥ���/���ơ������쥸���� */
#define CMCNT_0     ((VH *)0xFFFEC004)  /* ����ͥ�0 ����ڥ��ޥå������� */
#define CMCOR_0     ((VH *)0xFFFEC006)  /* ����ͥ�0 ����ڥ��ޥå����󥹥���ȥ쥸���� */
#define CMCSR_1     ((VH *)0xFFFEC008)  /* ����ͥ�1 ����ڥ��ޥå������󥿥���ȥ���/���ơ������쥸���� */
#define CMCNT_1     ((VH *)0xFFFEC00A)  /* ����ͥ�1 ����ڥ��ޥå������� */
#define CMCOR_1     ((VH *)0xFFFEC00C)  /* ����ͥ�1 ����ڥ��ޥå����󥹥���ȥ쥸���� */

/* �ԥ�ե��󥯥���󥳥�ȥ��� (PFC), I/O�ݡ��� */
#define PAIOR0      ((VH *)0xFFFE3812)  /* �ݡ���A IO�쥸����0 */
#define PADR1       ((VH *)0xFFFE3814)  /* �ݡ���A �ǡ����쥸����1 */
#define PADR0       ((VH *)0xFFFE3816)  /* �ݡ���A �ǡ����쥸����0 */
#define PAPR0       ((VH *)0xFFFE381A)  /* �ݡ���A �ݡ��ȥ쥸����0 */
#define PBCR5       ((VH *)0xFFFE3824)  /* �ݡ���B ����ȥ���쥸����5 */
#define PBCR4       ((VH *)0xFFFE3826)  /* �ݡ���B ����ȥ���쥸����4 */
#define PBCR3       ((VH *)0xFFFE3828)  /* �ݡ���B ����ȥ���쥸����3 */
#define PBCR2       ((VH *)0xFFFE382A)  /* �ݡ���B ����ȥ���쥸����2 */
#define PBCR1       ((VH *)0xFFFE382C)  /* �ݡ���B ����ȥ���쥸����1 */
#define PBCR0       ((VH *)0xFFFE382E)  /* �ݡ���B ����ȥ���쥸����0 */
#define PBIOR1      ((VH *)0xFFFE3830)  /* �ݡ���B IO�쥸����1 */
#define PBIOR0      ((VH *)0xFFFE3832)  /* �ݡ���B IO�쥸����0 */
#define PBDR1       ((VH *)0xFFFE3834)  /* �ݡ���B �ǡ����쥸����1 */
#define PBDR0       ((VH *)0xFFFE3836)  /* �ݡ���B �ǡ����쥸����0 */
#define PBPR1       ((VH *)0xFFFE3838)  /* �ݡ���B �ݡ��ȥ쥸����1 */
#define PBPR0       ((VH *)0xFFFE383A)  /* �ݡ���B �ݡ��ȥ쥸����1 */
#define PCCR2       ((VH *)0xFFFE384A)  /* �ݡ���C ����ȥ���쥸����2 */
#define PCCR1       ((VH *)0xFFFE384C)  /* �ݡ���C ����ȥ���쥸����1 */
#define PCCR0       ((VH *)0xFFFE384E)  /* �ݡ���C ����ȥ���쥸����0 */
#define PCIOR0      ((VH *)0xFFFE3852)  /* �ݡ���C IO�쥸����0 */
#define PCDR0       ((VH *)0xFFFE3856)  /* �ݡ���C �ǡ����쥸����0 */
#define PCPR0       ((VH *)0xFFFE385A)  /* �ݡ���C �ݡ��ȥ쥸����1 */
#define PDCR3       ((VH *)0xFFFE3868)  /* �ݡ���D ����ȥ���쥸����3 */
#define PDCR2       ((VH *)0xFFFE386A)  /* �ݡ���D ����ȥ���쥸����2 */
#define PDCR1       ((VH *)0xFFFE386C)  /* �ݡ���D ����ȥ���쥸����1 */
#define PDCR0       ((VH *)0xFFFE386E)  /* �ݡ���D ����ȥ���쥸����0 */
#define PDIOR0      ((VH *)0xFFFE3872)  /* �ݡ���D IO�쥸����0 */
#define PDDR0       ((VH *)0xFFFE3876)  /* �ݡ���D �ǡ����쥸����0 */
#define PDPR0       ((VH *)0xFFFE387A)  /* �ݡ���D �ݡ��ȥ쥸����1 */
#define PECR1       ((VH *)0xFFFE388C)  /* �ݡ���D ����ȥ���쥸����1 */
#define PECR0       ((VH *)0xFFFE388E)  /* �ݡ���D ����ȥ���쥸����0 */
#define PEIOR0      ((VH *)0xFFFE3892)  /* �ݡ���D IO�쥸����0 */
#define PEDR0       ((VH *)0xFFFE3896)  /* �ݡ���D �ǡ����쥸����0 */
#define PEPR0       ((VH *)0xFFFE389A)  /* �ݡ���D �ݡ��ȥ쥸����1 */
#define PFCR3       ((VH *)0xFFFE38A8)  /* �ݡ���F ����ȥ���쥸����3 */
#define PFCR2       ((VH *)0xFFFE38AA)  /* �ݡ���F ����ȥ���쥸����2 */
#define PFCR1       ((VH *)0xFFFE38AC)  /* �ݡ���F ����ȥ���쥸����1 */
#define PFCR0       ((VH *)0xFFFE38AE)  /* �ݡ���F ����ȥ���쥸����0 */
#define PFIOR0      ((VH *)0xFFFE38B2)  /* �ݡ���F IO�쥸����0 */
#define PFDR0       ((VH *)0xFFFE38B6)  /* �ݡ���F �ǡ����쥸����0 */
#define PFPR0       ((VH *)0xFFFE38BA)  /* �ݡ���F �ݡ��ȥ쥸����1 */
#define PGCR7       ((VH *)0xFFFE38C0)  /* �ݡ���G ����ȥ���쥸����5 */
#define PGCR6       ((VH *)0xFFFE38C2)  /* �ݡ���G ����ȥ���쥸����5 */
#define PGCR5       ((VH *)0xFFFE38C4)  /* �ݡ���G ����ȥ���쥸����5 */
#define PGCR4       ((VH *)0xFFFE38C6)  /* �ݡ���G ����ȥ���쥸����4 */
#define PGCR3       ((VH *)0xFFFE38C8)  /* �ݡ���G ����ȥ���쥸����3 */
#define PGCR2       ((VH *)0xFFFE38CA)  /* �ݡ���G ����ȥ���쥸����2 */
#define PGCR1       ((VH *)0xFFFE38CC)  /* �ݡ���G ����ȥ���쥸����1 */
#define PGCR0       ((VH *)0xFFFE38CE)  /* �ݡ���G ����ȥ���쥸����0 */
#define PGIOR1      ((VH *)0xFFFE38D0)  /* �ݡ���G IO�쥸����1 */
#define PGIOR0      ((VH *)0xFFFE38D2)  /* �ݡ���G IO�쥸����0 */
#define PGDR1       ((VH *)0xFFFE38D4)  /* �ݡ���G �ǡ����쥸����1 */
#define PGDR0       ((VH *)0xFFFE38D6)  /* �ݡ���G �ǡ����쥸����0 */
#define PGPR1       ((VH *)0xFFFE38D8)  /* �ݡ���G �ݡ��ȥ쥸����1 */
#define PGPR0       ((VH *)0xFFFE38DA)  /* �ݡ���G �ݡ��ȥ쥸����1 */
#define PHCR1       ((VH *)0xFFFE38EC)  /* �ݡ���H ����ȥ���쥸����1 */
#define PHCR0       ((VH *)0xFFFE38EE)  /* �ݡ���H ����ȥ���쥸����0 */
#define PHPR0       ((VH *)0xFFFE38FA)  /* �ݡ���H �ݡ��ȥ쥸����1 */
#define PJCR2       ((VH *)0xFFFE390A)  /* �ݡ���J ����ȥ���쥸����2 */
#define PJCR1       ((VH *)0xFFFE390C)  /* �ݡ���J ����ȥ���쥸����1 */
#define PJCR0       ((VH *)0xFFFE390E)  /* �ݡ���J ����ȥ���쥸����0 */
#define PJIOR0      ((VH *)0xFFFE3912)  /* �ݡ���J IO�쥸����0 */
#define PJDR0       ((VH *)0xFFFE3916)  /* �ݡ���J �ǡ����쥸����0 */
#define PJPR0       ((VH *)0xFFFE391A)  /* �ݡ���J �ݡ��ȥ쥸����1 */
#define PKCR2       ((VH *)0xFFFE392A)  /* �ݡ���K ����ȥ���쥸����2 */
#define PKCR1       ((VH *)0xFFFE392C)  /* �ݡ���K ����ȥ���쥸����1 */
#define PKCR0       ((VH *)0xFFFE392E)  /* �ݡ���K ����ȥ���쥸����0 */
#define PKIOR0      ((VH *)0xFFFE3932)  /* �ݡ���K IO�쥸����0 */
#define PKDR0       ((VH *)0xFFFE3936)  /* �ݡ���K �ǡ����쥸����0 */
#define PKPR0       ((VH *)0xFFFE393A)  /* �ݡ���K �ݡ��ȥ쥸����1 */

/* ��������ϥ⡼�� */
#define STBCR1      ((VB *)0xFFFE0014)  /* ������Х�����ȥ���쥸����1 */
#define STBCR2      ((VB *)0xFFFE0018)  /* ������Х�����ȥ���쥸����2 */
#define STBCR3      ((VB *)0xFFFE0408)  /* ������Х�����ȥ���쥸����3 */
#define STBCR4      ((VB *)0xFFFE040C)  /* ������Х�����ȥ���쥸����4 */
#define STBCR5      ((VB *)0xFFFE0410)  /* ������Х�����ȥ���쥸����5 */
#define STBCR6      ((VB *)0xFFFE0414)  /* ������Х�����ȥ���쥸����6 */
#define STBCR7      ((VB *)0xFFFE0418)  /* ������Х�����ȥ���쥸����7 */
#define STBCR8      ((VB *)0xFFFE041C)  /* ������Х�����ȥ���쥸����8 */
#define SWRSTCR     ((VB *)0xFFFE0430)  /* ���եȥ������ꥻ�åȥ���ȥ���쥸����8 */
#define SYSCR1      ((VB *)0xFFFE0400)  /* �����ƥॳ��ȥ���쥸����1 */
#define SYSCR2      ((VB *)0xFFFE0404)  /* �����ƥॳ��ȥ���쥸����2 */
#define SYSCR3      ((VB *)0xFFFE0420)  /* �����ƥॳ��ȥ���쥸����3 */
#define SYSCR4      ((VB *)0xFFFE0424)  /* �����ƥॳ��ȥ���쥸����4 */
#define SYSCR5      ((VB *)0xFFFE0428)  /* �����ƥॳ��ȥ���쥸����5 */
#define RRAMKP      ((VB *)0xFFFE6800)  /* �ݻ�����¢RAM �ݻ����ꥢ����쥸���� */
#define DSCTR       ((VB *)0xFFFE6802)  /* �ǥ����ץ�����Х�����ȥ���쥸���� */
#define DSSSR       ((VH *)0xFFFE6804)  /* �ǥ����ץ�����Х�����װ����쥯�ȥ쥸���� */
#define DSESR       ((VH *)0xFFFE6806)  /* �ǥ����ץ�����Х�������å����쥯�ȥ쥸���� */
#define DSFR        ((VH *)0xFFFE6808)  /* �ǥ����ץ�����Х�����װ��ե饰�쥸���� */
#define XTALCTR     ((VB *)0xFFFE6810)  /* XTAL�徽ȯ���沈���󥳥�ȥ���쥸���� */

/* FIFO�դ����ꥢ�륳�ߥ�˥�������󥤥󥿡��ե����� (SCIF) */

#define SCIF0_BASE  ((UW)0xFFFE8000)    /* ����ͥ�0 �쥸�����١������ɥ쥹 */
#define SCIF1_BASE  ((UW)0xFFFE8800)    /* ����ͥ�1 �쥸�����١������ɥ쥹 */
#define SCIF2_BASE  ((UW)0xFFFE9000)    /* ����ͥ�2 �쥸�����١������ɥ쥹 */
#define SCIF3_BASE  ((UW)0xFFFE9800)    /* ����ͥ�3 �쥸�����١������ɥ쥹 */
#define SCIF4_BASE  ((UW)0xFFFEA000)    /* ����ͥ�4 �쥸�����١������ɥ쥹 */
#define SCIF5_BASE  ((UW)0xFFFEA800)    /* ����ͥ�5 �쥸�����١������ɥ쥹 */
#define SCIF6_BASE  ((UW)0xFFFEB000)    /* ����ͥ�6 �쥸�����١������ɥ쥹 */
#define SCIF7_BASE  ((UW)0xFFFEB800)    /* ����ͥ�7 �쥸�����١������ɥ쥹 */

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
	sil_wrh_mem (IPR18, 0x0000);
	sil_wrh_mem (IPR19, 0x0000);
	sil_wrh_mem (IPR20, 0x0000);
	sil_wrh_mem (IPR21, 0x0000);
	sil_wrh_mem (IPR22, 0x0000);
}

#endif /* _MACRO_ONLY */

#endif /* _SH7262_H_ */
