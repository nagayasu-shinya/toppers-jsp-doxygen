VERSION 5.00
Object = "{194B359F-594E-4EE4-A804-84723D1CF1C4}#1.0#0"; "ATLDevice.dll"
Begin VB.Form Form1 
   BorderStyle     =   3  '�����������
   Caption         =   "Form1"
   ClientHeight    =   1140
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   3045
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1140
   ScaleWidth      =   3045
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows �δ�����
   Begin ATLDEVICELibCtl.DeviceControl DeviceControl1 
      Height          =   375
      Left            =   2400
      OleObjectBlob   =   "Form1.frx":0000
      TabIndex        =   1
      Top             =   0
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.Label Label1 
      Alignment       =   2  '���·��
      Caption         =   "Label1"
      Height          =   255
      Index           =   4
      Left            =   1920
      TabIndex        =   5
      Top             =   360
      Width           =   975
   End
   Begin VB.Label Label1 
      Alignment       =   2  '���·��
      Caption         =   "Label1"
      Height          =   255
      Index           =   3
      Left            =   1560
      TabIndex        =   4
      Top             =   720
      Width           =   975
   End
   Begin VB.Label Label1 
      Alignment       =   2  '���·��
      Caption         =   "Label1"
      Height          =   255
      Index           =   2
      Left            =   480
      TabIndex        =   3
      Top             =   720
      Width           =   975
   End
   Begin VB.Label Label1 
      Alignment       =   2  '���·��
      Caption         =   "Label1"
      Height          =   255
      Index           =   1
      Left            =   0
      TabIndex        =   2
      Top             =   360
      Width           =   975
   End
   Begin VB.Label Label1 
      Alignment       =   2  '���·��
      Caption         =   "Label1"
      Height          =   255
      Index           =   0
      Left            =   960
      TabIndex        =   0
      Top             =   0
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

'
'  TOPPERS/JSP Kernel
'      Toyohashi Open Platform for Embedded Real-Time Systems/
'      Just Standard Profile Kernel
' 
'  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
'                              Toyohashi Univ. of Technology, JAPAN
' 
'  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation 
'  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
'  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
'  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
'  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
'  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
'      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
'      ����������˴ޤޤ�Ƥ��뤳�ȡ�
'  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
'      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
'      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
'      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
'  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
'      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
'      �ȡ�
'    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
'        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
'    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
'        ��𤹤뤳�ȡ�
'  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
'      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
' 
'  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
'  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
'  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
'  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
'
'  @(#) $Id: form1.frm,v 1.5 2004/09/09 03:40:51 honda Exp $
'

Private Sub SetLabelString(index As Integer, letter As String, color As ColorConstants)
    Label1(index) = letter
    Label1(index).ForeColor = color
End Sub

Private Sub DeviceControl1_OnKernelExit()
    Dim i As Integer
    
    For i = 0 To 4
        SetLabelString i, "��λ", vbBlue
    Next i
    
End Sub

Private Sub DeviceControl1_OnKernelStart()
    Dim i As Integer
    
    For i = 0 To 4
        SetLabelString i, "�����Ԥ�", vbBlack
    Next i
End Sub

Private Sub DeviceControl1_OnWrite(ByVal address As Long, ByVal sz As Long)
    Dim i As Integer
    Dim work As Long
    work = DeviceControl1.Value
    i = work And &HF
        
    Select Case (work And &HF0)
    Case &H10
        SetLabelString i, "�����Ԥ�", vbBlack
    Case &H20
        SetLabelString i, "����", vbRed
    Case &H40
        SetLabelString i, "�ٷ�", vbBlack
    End Select

End Sub

Private Sub Form_Load()
    Dim i As Integer
    
    For i = 0 To 4
        SetLabelString i, "��λ", vbBlue
    Next i
    
    DeviceControl1.Connect
    DeviceControl1.Map 100, 4
End Sub

Private Sub Form_Unload(Cancel As Integer)
    DeviceControl1.Close
End Sub
