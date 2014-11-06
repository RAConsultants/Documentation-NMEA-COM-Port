// NMEAParserDemoDlg.h : header file
//

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Sio.h"
#include "NMEAParser.h"

/////////////////////////////////////////////////////////////////////////////
// CNMEAParserDemoDlg dialog

class CNMEAParserDemoDlg : public CDialog
{
	CSio m_Sio;					// Serial port class
	CNMEAParser	m_NMEAParser;	// The parser

// Construction
public:
	void UpdateText();
	CNMEAParserDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNMEAParserDemoDlg)
	enum { IDD = IDD_NMEAPARSERDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNMEAParserDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNMEAParserDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnResetData();
	afx_msg void OnSetComm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

