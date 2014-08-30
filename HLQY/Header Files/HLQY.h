// HLQY.h : main header file for the HLQY application
//

#if !defined(AFX_HLQY_H__F99B364D_E93D_4073_B82D_429D4101BCDC__INCLUDED_)
#define AFX_HLQY_H__F99B364D_E93D_4073_B82D_429D4101BCDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHLQYApp:
// See HLQY.cpp for the implementation of this class
//

class CHLQYApp : public CWinApp
{
public:
	CHLQYApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHLQYApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHLQYApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HLQY_H__F99B364D_E93D_4073_B82D_429D4101BCDC__INCLUDED_)
