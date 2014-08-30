#if !defined(AFX_UP_H__1FB53619_06B8_454F_9F04_BD88FA5D054A__INCLUDED_)
#define AFX_UP_H__1FB53619_06B8_454F_9F04_BD88FA5D054A__INCLUDED_

  #if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Up.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUp dialog

class CUp : public CDialog
{
// Construction
public:
	CUp(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUp)
	enum { IDD = IDD_UP_DIALOG };
	CListCtrl	m_gridUp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUp)
	afx_msg void OnBtnDakai();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UP_H__1FB53619_06B8_454F_9F04_BD88FA5D054A__INCLUDED_)
