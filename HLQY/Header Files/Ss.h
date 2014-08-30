#if !defined(AFX_SS_H__0A7E89E9_5CD5_4034_A5C2_099743E8CA47__INCLUDED_)
#define AFX_SS_H__0A7E89E9_5CD5_4034_A5C2_099743E8CA47__INCLUDED_

 #if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ss.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSs dialog

class CSs : public CDialog
{
// Construction
public:
	CSs(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSs)
	enum { IDD = IDD_SS_DIALOG };
	CListCtrl	m_gridSs;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSs)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSs)
	afx_msg void OnBtnBack();
	afx_msg void OnBtnDown();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SS_H__0A7E89E9_5CD5_4034_A5C2_099743E8CA47__INCLUDED_)
