// HLQYDlg.h : header file
//

#if !defined(AFX_HLQYDLG_H__89402D1C_1E05_482C_B3E7_5372D433339A__INCLUDED_)
#define AFX_HLQYDLG_H__89402D1C_1E05_482C_B3E7_5372D433339A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SkinPPWTL.h"
#include "HLQYSock.h"
#include "afxwin.h"
#define BUFFER_SIZE 256

/////////////////////////////////////////////////////////////////////////////
// CHLQYDlg dialog

class CHLQYDlg : public CDialog
{
// Construction
public:
	CHLQYDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHLQYDlg)
	enum { IDD = IDD_HLQY_DIALOG };
//	CString	m_UID;
//	CString	m_PWD;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHLQYDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHLQYDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnZhuce();
	afx_msg void OnBtnDenglu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEUid();
	// 用户的密码
	CString m_PWD;
	// 用户账号
	CString m_UID;
	// 储存用户账号的变量
	CEdit m_eUID;
	afx_msg void OnEnChangeEPwd();
	// 储存用户密码的变量
	CEdit m_ePWD;

	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HLQYDLG_H__89402D1C_1E05_482C_B3E7_5372D433339A__INCLUDED_)

