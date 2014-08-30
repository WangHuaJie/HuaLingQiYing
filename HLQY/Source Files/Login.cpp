// Login.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "Login.h"
#include  "No.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog


CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogin)
	m_Name = _T("");
	m_Key1 = _T("");
	m_Key2 = _T("");
	//}}AFX_DATA_INIT
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Text(pDX, IDC_E_UID, m_Name);
	DDX_Text(pDX, IDC_E_PWD1, m_Key1);
	DDX_Text(pDX, IDC_E_PWD2, m_Key2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
	ON_BN_CLICKED(IDC_BTN_ZHUCE, OnBtnZhuce)
	ON_BN_CLICKED(IDC_BTN_BACK, OnBtnBack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers


void CLogin::OnBtnBack() 
{
	CDialog::OnOK();	
}

void CLogin::OnBtnZhuce() 
{	
	CNo  p;
	UpdateData(TRUE);
	if(m_Key1==m_Key2){
      
	  CDialog::OnOK();
	}
	else

	p.DoModal();

}

