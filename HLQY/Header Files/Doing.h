#if !defined(AFX_DOING_H__33192BF7_B83D_4E6D_82A4_73269D156504__INCLUDED_)
#define AFX_DOING_H__33192BF7_B83D_4E6D_82A4_73269D156504__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Doing.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDoing dialog

class CDoing : public CDialog
{
// Construction
public:
	CDoing(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDoing)
	enum { IDD = IDD_DOING_DIALOG };
	CListCtrl	m_grid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDoing)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDoing)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnBack();
	afx_msg void OnBtnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOING_H__33192BF7_B83D_4E6D_82A4_73269D156504__INCLUDED_)
