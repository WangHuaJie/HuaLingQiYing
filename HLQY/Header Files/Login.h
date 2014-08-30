#if !defined(AFX_LOGIN_H__E3C6DAF0_8EA6_4870_9522_1BC1D382DB3B__INCLUDED_)
#define AFX_LOGIN_H__E3C6DAF0_8EA6_4870_9522_1BC1D382DB3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog

class CLogin : public CDialog
{
// Construction
public:
	CLogin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogin)
	enum { IDD = IDD_LOGIN_DIALOG };
	CString	m_Name;
	CString	m_Key1;
	CString	m_Key2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogin)
	afx_msg void OnBtnZhuce();
	afx_msg void OnBtnBack();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__E3C6DAF0_8EA6_4870_9522_1BC1D382DB3B__INCLUDED_)
