// Main.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "Main.h"
#include  "Person.h"
#include  "Ss.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMain dialog


CMain::CMain(CWnd* pParent /*=NULL*/)
	: CDialog(CMain::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMain)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMain)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMain, CDialog)
	//{{AFX_MSG_MAP(CMain)
//	ON_BN_CLICKED(IDC_BTN_PERSON, OnBtnPerson)
	ON_BN_CLICKED(IDC_BTN_CENTER, OnBtnCenter)
	ON_BN_CLICKED(IDC_BTN_SOUSUO, OnBtnSousuo)
	ON_BN_CLICKED(IDC_BTN_YIXIAZAI, OnBtnYixiazai)
	ON_BN_CLICKED(IDC_BTN_XIAZAIZHONG, OnBtnXiazaizhong)
	ON_BN_CLICKED(IDC_BTN_YISHANGCHUAN, OnBtnYishangchuan)
	ON_BN_CLICKED(IDC_BTN_SHANGCHUANZHONG, OnBtnShangchuanzhong)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMain message handlers


void CMain::OnBtnCenter() 
{
	// TODO: Add your control notification handler code here
	CPerson a;
	a.DoModal();
	
}

void CMain::OnBtnSousuo() 
{
	// TODO: Add your control notification handler code here
	CSs y;
	y.DoModal();
	
}


void CMain::OnBtnYixiazai() 
{
	// TODO: Add your control notification handler code here
	doing.ShowWindow(SW_HIDE);
	uping.ShowWindow(SW_HIDE);
	donee.ShowWindow(SW_SHOW);
	upp.ShowWindow(SW_HIDE);
	
}

void CMain::OnBtnXiazaizhong() 
{
	// TODO: Add your control notification handler code here
	doing.ShowWindow(SW_SHOW);
	uping.ShowWindow(SW_HIDE);	
	donee.ShowWindow(SW_HIDE);
	upp.ShowWindow(SW_HIDE);
	
}

void CMain::OnBtnYishangchuan() 
{
	// TODO: Add your control notification handler code here
	uping.ShowWindow(SW_SHOW);
    doing.ShowWindow(SW_HIDE);
	donee.ShowWindow(SW_HIDE);
	upp.ShowWindow(SW_HIDE);
	
}

void CMain::OnBtnShangchuanzhong() 
{
	// TODO: Add your control notification handler code here
	uping.ShowWindow(SW_HIDE);
    doing.ShowWindow(SW_HIDE);	
	donee.ShowWindow(SW_HIDE);
	upp.ShowWindow(SW_SHOW);
	
}

BOOL CMain::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CWnd* pTabPage = GetDlgItem(IDC_STATIC);

	// 设定标签页的父窗体，第一个参数是标签页的窗体ID
	doing.Create(IDD_DOING_DIALOG, pTabPage);
	// 设置标签页的显示与隐藏
	doing.ShowWindow(SW_HIDE);

    donee.Create(IDD_DONE_DIALOG, pTabPage);
    donee.ShowWindow(SW_HIDE);
    upp.Create(IDD_UP_DIALOG, pTabPage);
	upp.ShowWindow(SW_HIDE);
    
	uping.Create(IDD_UPING_DIALOG, pTabPage);
	uping.ShowWindow(SW_HIDE);
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
