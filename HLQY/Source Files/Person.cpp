// Person.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "Person.h"
#include "Ziliao.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPerson dialog


CPerson::CPerson(CWnd* pParent /*=NULL*/)
	: CDialog(CPerson::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPerson)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPerson::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPerson)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPerson, CDialog)
	//{{AFX_MSG_MAP(CPerson)
	ON_BN_CLICKED(IDC_BTN_XIUGAI, OnBtnXiugai)
	ON_BN_CLICKED(IDC_BTN_BACK, OnBtnBack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPerson message handlers

void CPerson::OnBtnXiugai() 
{
	// TODO: Add your control notification handler code here
	CZiliao  yy;
	yy.DoModal();
	
}

void CPerson::OnBtnBack() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	
}
