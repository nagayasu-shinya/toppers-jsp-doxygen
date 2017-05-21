' TOPPERS/JSP Kernel
'     Toyohashi Open Platform for Embedded Real-Time Systems/
'     Just Standard Profile Kernel
'
' Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
'                             Toyohashi Univ. of Technology, JAPAN
'
' �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation 
' �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
' �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
' ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
' ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
' (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
'     ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
'     ����������˴ޤޤ�Ƥ��뤳�ȡ�
' (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
'     �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
'     �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
'     ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
' (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
'     �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
'     �ȡ�
'   (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
'       �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
'   (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
'       ��𤹤뤳�ȡ�
' (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
'     ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
'
' �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
' ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
' �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
' ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
'
' @(#) $Id: make.vbs,v 1.8 2003/12/26 03:50:06 honda Exp $
'

dim model
dim msdev
dim rootdir

rootdir = left(Wscript.ScriptFullName, len(Wscript.scriptfullname) - len(wscript.scriptname))

if msgbox("TOPPERS/JSP Windows �ǥХ����ޥ͡����� ����� ATL�ǥХ�������ȥ�����������ޤ��������򳫻Ϥ��Ƥ������Ǥ���?", vbYesno) = vbyes then

	if msgbox("��꡼���ӥ�ɤ��ޤ���? (�֤������פ����֤ȥǥХå���ǽ�ʼ¹ԥե�������������ޤ�)",vbyesno) = vbyes then
		model = " - Win32 Unicode Release MinDependency"
	else
		model = " - Win32 Debug"
	end if

		'Visual C++ �ε�ư
	set msdev = CreateObject("MSDEV.APPLICATION")
	msdev.visible = true

		'�ǥХ����ޥ͡����������
	msdev.documents.open rootdir + "devicemanager\devicemanager.dsw"
	set msdev.activeproject = msdev.projects("devicemanager")
	set msdev.activeconfiguration = msdev.activeproject.configurations("devicemanager" + model)
	msdev.build

		'�ǥХ�������ȥ��������
	msdev.documents.open rootdir + "devicecontrol\device.dsw"
	set msdev.activeproject = msdev.projects("device")
	set msdev.activeconfiguration = msdev.activeproject.configurations("device" + model)
	msdev.build

		'cmdwatch������
	msdev.documents.open rootdir + "cmdwatch\cmdwatch.dsw"
	set msdev.activeproject = msdev.projects("cmdwatch")
	set msdev.activeconfiguration = msdev.activeproject.configurations("cmdwatch" + model)
	msdev.build

		'�����å��㥳��ȥ��������
	msdev.documents.open rootdir + "watcher\watcher.dsw"
	set msdev.activeproject = msdev.projects("watcher")
	set msdev.activeconfiguration = msdev.activeproject.configurations("watcher" + model)
	msdev.build


msdev.quit
set msdev = nothing

msgbox "���Ƥν�������λ���ޤ���"
end if
