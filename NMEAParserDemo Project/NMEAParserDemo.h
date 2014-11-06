// NMEAParserDemo.h : main header file for the NMEAPARSERDEMO application
//

#if !defined(AFX_NMEAPARSERDEMO_H__2B00E819_2F79_4DE8_AC39_C849DE5985A3__INCLUDED_)
#define AFX_NMEAPARSERDEMO_H__2B00E819_2F79_4DE8_AC39_C849DE5985A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNMEAParserDemoApp:
// See NMEAParserDemo.cpp for the implementation of this class
//

class CNMEAParserDemoApp : public CWinApp
{
public:
	CNMEAParserDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNMEAParserDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNMEAParserDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NMEAPARSERDEMO_H__2B00E819_2F79_4DE8_AC39_C849DE5985A3__INCLUDED_)
