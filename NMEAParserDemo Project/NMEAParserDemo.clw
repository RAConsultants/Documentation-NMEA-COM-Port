; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNMEAParserDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "nmeaparserdemo.h"
LastPage=0

ClassCount=5
Class1=CNMEAParserDemoApp
Class2=CAboutDlg
Class3=CNMEAParserDemoDlg
Class4=CSio

ResourceCount=3
Resource1=IDD_NMEAPARSERDEMO_DIALOG
Resource2=IDD_ABOUTBOX
Class5=CCommSettingsDlg
Resource3=IDD_COMM_SETTINGS

[CLS:CNMEAParserDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=NMEAParserDemo.h
ImplementationFile=NMEAParserDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=NMEAParserDemoDlg.cpp
ImplementationFile=NMEAParserDemoDlg.cpp

[CLS:CNMEAParserDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=NMEAParserDemoDlg.h
ImplementationFile=NMEAParserDemoDlg.cpp
LastObject=IDC_SET_COMM
Filter=D
VirtualFilter=dWC

[CLS:CSio]
Type=0
BaseClass=CWnd
HeaderFile=Sio.h
ImplementationFile=Sio.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NMEAPARSERDEMO_DIALOG]
Type=1
Class=CNMEAParserDemoDlg
ControlCount=36
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LAT,static,1342308352
Control5=IDC_LON,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_NMEA_RX_COUNT,static,1342308352
Control8=IDC_RESET_DATA,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_ALT,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_GPS_QUAL,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_VDOP,static,1342308352
Control17=IDC_HDOP,static,1342308352
Control18=IDC_PDOP,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_SATS_USED_IN_SOL,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_GSV_PRN,static,1342308352
Control26=IDC_GSV_SNR,static,1342308352
Control27=IDC_GSV_AZ,static,1342308352
Control28=IDC_GSV_ELV,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_SATS_IN_VIEW,static,1342308352
Control31=IDC_SET_COMM,button,1342242816
Control32=IDC_STATIC,static,1342181383
Control33=IDC_STATIC,static,1342181383
Control34=IDC_STATIC,static,1342308352
Control35=IDC_GSA_FIX_MODE,static,1342308352
Control36=IDC_GSA_MODE,static,1342308353

[CLS:CCommSettingsDlg]
Type=0
HeaderFile=CommSettingsDlg.h
ImplementationFile=CommSettingsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CCommSettingsDlg
VirtualFilter=dWC

[DLG:IDD_COMM_SETTINGS]
Type=1
Class=CCommSettingsDlg
ControlCount=6
Control1=IDC_PORT,combobox,1344339970
Control2=IDC_BAUD,combobox,1344339970
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

