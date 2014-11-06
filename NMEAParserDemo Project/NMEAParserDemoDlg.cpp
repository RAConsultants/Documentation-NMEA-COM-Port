// NMEAParserDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NMEAParserDemo.h"
#include "NMEAParserDemoDlg.h"
#include "CommSettingsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

enum TIMER_ID
{
	TIMER_ID_POLL_COMM = 1,
	TIMER_ID_UPDATE_TEXT,
};

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNMEAParserDemoDlg dialog

CNMEAParserDemoDlg::CNMEAParserDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNMEAParserDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNMEAParserDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNMEAParserDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNMEAParserDemoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNMEAParserDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CNMEAParserDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RESET_DATA, OnResetData)
	ON_BN_CLICKED(IDC_SET_COMM, OnSetComm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNMEAParserDemoDlg message handlers

BOOL CNMEAParserDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_Sio.InitComm(1, 4800, NOPARITY, 8, ONESTOPBIT, FALSE);

	SetTimer(TIMER_ID_POLL_COMM, 100, NULL);
	SetTimer(TIMER_ID_UPDATE_TEXT, 1000, NULL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNMEAParserDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNMEAParserDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNMEAParserDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void CNMEAParserDemoDlg::OnTimer(UINT nIDEvent) 
{
	switch(nIDEvent)
	{
		///////////////////////////////////////////////////////////////////////
		// Read data from serial port and send it to the parser
		case TIMER_ID_POLL_COMM :
			BYTE pBuff[256];
			DWORD dwBytesRead;
			dwBytesRead = m_Sio.Read(pBuff, 255);
			m_NMEAParser.ParseBuffer(pBuff, dwBytesRead);
		break;

		///////////////////////////////////////////////////////////////////////
		case TIMER_ID_UPDATE_TEXT :
			UpdateText();
		break;
	}
	
	CDialog::OnTimer(nIDEvent);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void CNMEAParserDemoDlg::UpdateText()
{
	CString str;	// used for formatting strings
	CString str2;

	//
	// Update NMEA sentence count
	//
	SetDlgItemInt(IDC_NMEA_RX_COUNT, m_NMEAParser.m_dwCommandCount);

	//
	// GGA Lat/Lon/Alt
	//
	str.Format("%f", m_NMEAParser.m_dGGALatitude);
	SetDlgItemText(IDC_LAT, str);
	str.Format("%f", m_NMEAParser.m_dGGALongitude);
	SetDlgItemText(IDC_LON, str);
	str.Format("%f", m_NMEAParser.m_dGGAAltitude);
	SetDlgItemText(IDC_ALT, str);
	str.Format("%f", m_NMEAParser.m_dRMCGroundSpeed);
	SetDlgItemText(IDC_SPEED, str);
	//m_dRMCGroundSpeed

	//
	// GGA GPS Quality
	//
	switch(m_NMEAParser.m_btGGAGPSQuality)
	{
		case 0 : str = _T("Fix not available"); break;
		case 1 : str = _T("GPS sps mode"); break;
		case 2 : str = _T("Differential GPS, SPS mode, fix valid"); break;
		case 3 : str = _T("GPS PPS mode, fix valid"); break;
		default : str = _T("Unknown"); break;
	}
	SetDlgItemText(IDC_GPS_QUAL, str);

	//
	// GSA Fix mode and Dops
	//
	switch(m_NMEAParser.m_btGSAMode)
	{
		case 'M' : str = _T("(Manual)"); break;
		case 'A' : str = _T("(Automatic)"); break;
		default : str = _T("(?)"); break;
	}
	SetDlgItemText(IDC_GSA_MODE,str);
	switch(m_NMEAParser.m_btGSAFixMode)
	{
		case 1 : str = _T("Fix not available"); break;
		case 2 : str = _T("2D Fix"); break;
		case 3 : str = _T("3D Fix"); break;
		default : str = _T("Unknown"); break;
	}
	SetDlgItemText(IDC_GSA_FIX_MODE, str);
	str.Format(_T("%.02f"), m_NMEAParser.m_dGSAVDOP);
	SetDlgItemText(IDC_VDOP, str);
	str.Format(_T("%.02f"), m_NMEAParser.m_dGSAHDOP);
	SetDlgItemText(IDC_HDOP, str);
	str.Format(_T("%.02f"), m_NMEAParser.m_dGSAPDOP);
	SetDlgItemText(IDC_PDOP, str);

	//
	// GSA satellites used in solution
	//
	str = _T("");
	for(int i = 0; i < 12; i++)
	{
		str2.Format("%02d ", m_NMEAParser.m_wGSASatsInSolution[i]);
		str += str2;
	}
	SetDlgItemText(IDC_SATS_USED_IN_SOL, str);

	//
	// GSV signal quality/azimuth/elevation
	//
	SetDlgItemInt(IDC_SATS_IN_VIEW, m_NMEAParser.m_wGSVTotalNumSatsInView);
	str = _T("");
	for(int i = 0; i < m_NMEAParser.m_wGSVTotalNumSatsInView; i++)
	{
		str2.Format(_T("%d\t"), m_NMEAParser.m_GSVSatInfo[i].m_wPRN);
		str += str2;
	}
	SetDlgItemText(IDC_GSV_PRN, str);
	str = _T("");
	for(int i = 0; i < m_NMEAParser.m_wGSVTotalNumSatsInView; i++)
	{
		str2.Format(_T("%d\t"), m_NMEAParser.m_GSVSatInfo[i].m_wSignalQuality);
		str += str2;
	}
	SetDlgItemText(IDC_GSV_SNR, str);
	str = _T("");
	for(int i = 0; i < m_NMEAParser.m_wGSVTotalNumSatsInView; i++)
	{
		str2.Format(_T("%d\t"), m_NMEAParser.m_GSVSatInfo[i].m_wAzimuth);
		str += str2;
	}
	SetDlgItemText(IDC_GSV_AZ, str);
	str = _T("");
	for(int i = 0; i < m_NMEAParser.m_wGSVTotalNumSatsInView; i++)
	{
		str2.Format(_T("%d\t"), m_NMEAParser.m_GSVSatInfo[i].m_wElevation);
		str += str2;
	}
	SetDlgItemText(IDC_GSV_ELV, str);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void CNMEAParserDemoDlg::OnResetData() 
{
	m_NMEAParser.Reset();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void CNMEAParserDemoDlg::OnSetComm() 
{
	CCommSettingsDlg dlg;
	
	dlg.m_nBaud = m_Sio.m_nBaud;
	dlg.m_nPort = m_Sio.m_nPort;

	if(dlg.DoModal() == IDOK)
	{
		m_Sio.Close();
		m_Sio.InitComm(dlg.m_nPort, dlg.m_nBaud, NOPARITY, 8, ONESTOPBIT, FALSE);
	}

}
