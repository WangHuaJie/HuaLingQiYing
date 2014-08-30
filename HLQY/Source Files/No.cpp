// No.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "No.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNo dialog


CNo::CNo(CWnd* pParent /*=NULL*/)
	: CDialog(CNo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNo, CDialog)
	//{{AFX_MSG_MAP(CNo)
	ON_BN_CLICKED(IDC_BTN_BACK, OnBtnBack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNo message handlers

void CNo::OnBtnBack() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	
}
