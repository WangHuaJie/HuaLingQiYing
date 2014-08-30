#if !defined(AFX_ZILIAO_H__9B98C99A_DBD6_4295_AB48_D46F99FFD2C0__INCLUDED_)
#define AFX_ZILIAO_H__9B98C99A_DBD6_4295_AB48_D46F99FFD2C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ziliao.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZiliao dialog

class CZiliao : public CDialog
{
// Construction
public:
	CZiliao(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CZiliao)
	enum { IDD = IDD_ZILIAO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZiliao)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZiliao)
	afx_msg void OnBtnBack();
	afx_msg void OnBtnBaocun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZILIAO_H__9B98C99A_DBD6_4295_AB48_D46F99FFD2C0__INCLUDED_)
