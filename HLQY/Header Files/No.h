#if !defined(AFX_NO_H__A999EC64_8DCD_46F0_8F7B_82C77BAA6FEA__INCLUDED_)
#define AFX_NO_H__A999EC64_8DCD_46F0_8F7B_82C77BAA6FEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// No.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNo dialog

class CNo : public CDialog
{
// Construction
public:
	CNo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNo)
	enum { IDD = IDD_NO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNo)
	afx_msg void OnBtnBack();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NO_H__A999EC64_8DCD_46F0_8F7B_82C77BAA6FEA__INCLUDED_)
