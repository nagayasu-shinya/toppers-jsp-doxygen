
        �� TOPPERS/JSP�����ͥ� �桼�����ޥ˥奢�� ��
                    ��m16c:TM��ȯ�Ķ���

        ��Release 1.4.4 �б����ǽ�����: 28-Dec-2010��

------------------------------------------------------------------------
 TOPPERS/JSP Kernel
     Toyohashi Open Platform for Embedded Real-Time Systems/
     Just Standard Profile Kernel

 Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
                             Toyohashi Univ. of Technology, JAPAN
 Copyright (C) 2003-2004 by Platform Development Center
                                         RIOCH COMPANY,LTD. JAPAN
 Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
               Graduate School of Information Science, Nagoya Univ., JAPAN
 Copyright (C) 2010 by Naoki Saito
            Nagoya Municipal Industrial Research Institute, JAPAN

 �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation 
 �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
 �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
 ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
     ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
     ����������˴ޤޤ�Ƥ��뤳�ȡ�
 (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
     �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
     �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
     ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
     �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
     �ȡ�
   (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
       �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
   (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
       ��𤹤뤳�ȡ�
 (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
     ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�

 �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
------------------------------------------------------------------------

���Υɥ�����ȤǤϡ�M16C�ѤΥ�ͥ������쥯�ȥ�˥����Ҥγ�ȯ�ġ����
���Ѥ��ơ�TOPPERS/JSP�����ͥ���ۤ��뤿���ɬ�פʥե�����ˤĤ��Ʋ��⤹�롥

1. �ǥ��쥯�ȥ�ι���

jsp
  +--config
  |     +---m16c-renesas
  |            +---oaks16
  |            +---oaks16_mini
  |            +---m3029
  +--tools
  |     +-----M16C-RENESAS
  +--utils
        +-----m16c-renesas


2.�ǥ��쥯�ȥ�ȥե����������

(1) config/m16c-renesas
	M16C ��¸���Υե����뤬�֤����ǥ��쥯�ȥꡥ
(2) utils/m16c-renesas
	�ӥ�ɤκݤ˻Ȥ��롤�ʲ��Υġ��뤬�֤����ǥ��쥯�ȥꡥ
		������ߤ� CPU �㳰�Υ٥�����ư��������ġ���(m16cvec.exe)
		��TCB �Υ��ե��å��ͤ򥢥���֥饽���������ꤹ��ġ���(m16coffset.exe)
		(�ʲ��ϡ�make ���Ѥ��ƥӥ�ɤ�����Τ߻Ȥ���)
		���������ΰ�¸�ط����������� perl ������ץ�(makedep.m16c)
(3) tools/M16C-RENESAS
	���糫ȯ�Ķ� TM ���Ѥ��� TOPPERS/JSP �����ͥ���ۤ��뤿���
	�ե����뤬�֤����ǥ��쥯�ȥꡥ


2.1 config/m16c-renesas

a. Makefile.config
    make ���ޥ�ɤ��Ѥ���M16C�� TOPPERS/JSP ���ۤ������ make �ե�����
b. oaks16/Makefile.config 
    make ���ޥ�ɤ��Ѥ��� M16C-OAKS16�� TOPPERS/JSP ���ۤ������ make �ե�����
c. oaks16_mini/Makefile.config 
    make ���ޥ�ɤ��Ѥ��� M16C-OAKS16 MINI�� TOPPERS/JSP ���ۤ������ make �ե�����
d. ����¾ ---- M16C��¸���Υ�����


2.2 utils/m16c-renesas

a. makedep.m16c
    make���Ѥ��Ƴ�ȯ���硢�������ΰ�¸�ط�����������PERL������ץ�
b: m16coffset.c
    m16coffset ���ޥ��C���쵭��
c: m16cvec.c
    m16cvec ���ޥ��C���쵭��
d: Makefile
    MinGW ��GCC���Ѥ��� m16coffset, m16cvec ���ޥ�ɤ�ӥ�ɤ���ݤ�
    �Ѥ���ե�����

2.3 tools/M16C-RENESAS

a.Jsp14sample1.tmi,Jsp14sample1.tmk 
   TM���Ѥ��� OAKS16�Ѥ� TOPPERS/JSP ���ۤ��뤿��Υץ������ȥե�����
b.Jsp14sample1m.tmi,Jsp14samplem1.tmk
   TM���Ѥ��� OAKS16 MINI�Ѥ� TOPPERS/JSP ���ۤ��뤿��Υץ������ȥե�����
c.Jsp14sample1_m3029.tmi,Jsp14samplem1_m3029.tmk 
   TM���Ѥ��� M3029�Ѥ� TOPPERS/JSP ���ۤ��뤿��Υץ������ȥե�����
d.Jsp14sample1.id 
   �������� MOT �ե������OAKS16 �ܡ��ɤΥե�å���ROM�ν񤭹�����˻��Ѥ���ID�ե�����
e.Jsp14sample1m.id 
   �������� MOT �ե������OAKS16 MINI�ܡ��ɤΥե�å���ROM�ν񤭹�����˻��Ѥ���ID�ե�����
f.Jsp14sample1_m3029.id 
   �������� MOT �ե������ M3029 �Υե�å���ROM�ν񤭹�����˻��Ѥ���ID�ե�����
g.sample1.cfg 
   OAKS16, M3029�� �� TOPPERS/JSP ���ۤ��뤿��Υ���ե�����졼�����ե�����
h.sample1m.cfg 
   OAKS16 MINI�Ѥ� TOPPERS/JSP ���ۤ��뤿��Υ���ե�����ե�����


2.4  sample

a.Makefile.m16c-oaks16 
   make���ޥ�ɤ��Ѥ���OAKS16�Ѥ�TOPPERS/JSP���ۤ��뤿���make�ե�����


3��m16cvec, m16coffset ���ޥ�ɤι�����ˡ

m16cvec �ڤ� m16coffset ���ޥ�ɤι��ۤ� MinGW ���Ѥ��ƥ���ѥ����Ԥ���
����ѥ��뤹��ݡ�utils/m16c-renesas �ǥ��쥯�ȥ�ذ�ư����
ñ�� make ���ޥ�ɤ�¹Ԥ���Ф褤��
ư���ǧ���� GCC �ΥС������� 4.5.0 �Ǥ��롥
