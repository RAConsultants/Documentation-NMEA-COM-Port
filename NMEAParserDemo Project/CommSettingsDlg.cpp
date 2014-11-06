// CommSettingsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "nmeaparserdemo.h"
#include "CommSettingsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommSettingsDlg dialog


CCommSettingsDlg::CCommSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommSettingsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommSettingsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_nBaud = 4800;
	m_nPort = 1;
}


void CCommSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommSettingsDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommSettingsDlg, CDialog)
	//{{AFX_MSG_MAP(CCommSettingsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommSettingsDlg message handlers

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void CCommSettingsDlg::OnOK() 
{
	m_nBaud = GetDlgItemInt(IDC_BAUD);
	m_nPort = GetDlgItemInt(IDC_PORT);
	
	CDialog::OnOK();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
BOOL CCommSettingsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemInt(IDC_BAUD, m_nBaud);
	SetDlgItemInt(IDC_PORT, m_nPort);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
