#if !defined(AFX_UPING_H__3DA9D07E_9FC3_4251_83C5_91AC95DD89D0__INCLUDED_)
#define AFX_UPING_H__3DA9D07E_9FC3_4251_83C5_91AC95DD89D0__INCLUDED_

  #if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Uping.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUping dialog

class CUping : public CDialog
{
// Construction
public:
	CUping(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUping)
	enum { IDD = IDD_UPING_DIALOG };
	CListCtrl	m_gridUping;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUping)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUping)
	afx_msg void OnBtnNew();
	afx_msg void OnBtnStart();
	afx_msg void OnBtnStop();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPING_H__3DA9D07E_9FC3_4251_83C5_91AC95DD89D0__INCLUDED_)
