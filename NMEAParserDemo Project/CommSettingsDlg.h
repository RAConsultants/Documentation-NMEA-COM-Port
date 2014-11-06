#if !defined(AFX_COMMSETTINGSDLG_H__FD62EA94_13BB_4F81_818D_943B5BD4B125__INCLUDED_)
#define AFX_COMMSETTINGSDLG_H__FD62EA94_13BB_4F81_818D_943B5BD4B125__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CommSettingsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommSettingsDlg dialog

class CCommSettingsDlg : public CDialog
{
public:
	int m_nBaud;
	int m_nPort;

// Construction
public:
	CCommSettingsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCommSettingsDlg)
	enum { IDD = IDD_COMM_SETTINGS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommSettingsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCommSettingsDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMSETTINGSDLG_H__FD62EA94_13BB_4F81_818D_943B5BD4B125__INCLUDED_)
