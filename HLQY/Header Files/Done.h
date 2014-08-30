#if !defined(AFX_DONE_H__6D68E78F_6B18_42A6_961A_A7348C546878__INCLUDED_)
#define AFX_DONE_H__6D68E78F_6B18_42A6_961A_A7348C546878__INCLUDED_

  #if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Done.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDone dialog

class CDone : public CDialog
{
// Construction
public:
	CDone(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDone)
	enum { IDD = IDD_DONE_DIALOG };
	CListCtrl	m_gridDone;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDone)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDone)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DONE_H__6D68E78F_6B18_42A6_961A_A7348C546878__INCLUDED_)
