#if !defined(AFX_MAIN_H__6B20D035_ACF7_4E99_A824_466C65680C22__INCLUDED_)
#define AFX_MAIN_H__6B20D035_ACF7_4E99_A824_466C65680C22__INCLUDED_

#include "Doing.h"	// Added by ClassView
#include "Uping.h"
#include "Up.h"
#include "Done.h"
	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Main.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMain dialog

class CMain : public CDialog
{
// Construction
public:
	CUp upp;
	CUping uping;
	CDone donee;
	CDoing doing;

	CMain(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMain)
	enum { IDD = IDD_MAIN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMain)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMain)
	afx_msg void OnBtnPerson();
	afx_msg void OnBtnCenter();
	afx_msg void OnBtnSousuo();
	afx_msg void OnBtnYixiazai();
	afx_msg void OnBtnXiazaizhong();
	afx_msg void OnBtnYishangchuan();
	afx_msg void OnBtnShangchuanzhong();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAIN_H__6B20D035_ACF7_4E99_A824_466C65680C22__INCLUDED_)
