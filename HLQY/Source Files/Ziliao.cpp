// Ziliao.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "Ziliao.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZiliao dialog


CZiliao::CZiliao(CWnd* pParent /*=NULL*/)
	: CDialog(CZiliao::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZiliao)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CZiliao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZiliao)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZiliao, CDialog)
	//{{AFX_MSG_MAP(CZiliao)
	ON_BN_CLICKED(IDC_BTN_BACK, OnBtnBack)
	ON_BN_CLICKED(IDC_BTN_BAOCUN, OnBtnBaocun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZiliao message handlers

void CZiliao::OnBtnBack() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	
}

void CZiliao::OnBtnBaocun() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	
}
