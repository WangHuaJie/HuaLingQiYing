#if !defined(AFX_PERSON_H__B56DA105_AE95_4785_929F_C41C038E32A5__INCLUDED_)
#define AFX_PERSON_H__B56DA105_AE95_4785_929F_C41C038E32A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Person.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPerson dialog

class CPerson : public CDialog
{
// Construction
public:
	CPerson(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPerson)
	enum { IDD = IDD_PERSON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPerson)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPerson)
	afx_msg void OnBtnXiugai();
	afx_msg void OnBtnBack();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSON_H__B56DA105_AE95_4785_929F_C41C038E32A5__INCLUDED_)
