// Ss.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "Ss.h"
#include "Doing.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSs dialog


CSs::CSs(CWnd* pParent /*=NULL*/)
	: CDialog(CSs::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSs)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSs)
	DDX_Control(pDX, IDC_LIST1, m_gridSs);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSs, CDialog)
	//{{AFX_MSG_MAP(CSs)
	ON_BN_CLICKED(IDC_BTN_BACK, OnBtnBack)
	ON_BN_CLICKED(IDC_BTN_DOWN, OnBtnDown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSs message handlers

void CSs::OnBtnBack() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

void CSs::OnBtnDown() 
{
	// TODO: Add your control notification handler code here
	CDoing a;
	a.DoModal();
	
}

BOOL CSs::OnInitDialog() 
{
	CDialog::OnInitDialog();
	LONG lStyle = GetWindowLong(m_gridSs.m_hWnd, GWL_STYLE);
	lStyle |= LVS_EDITLABELS;	// |= 是位运算，用来给控件添加新属性
	SetWindowLong(m_gridSs, GWL_STYLE, lStyle);	// 将新的属性设置回网格控件
	// 下面，还将设置网格控件的附加属性
	m_gridSs.SetExtendedStyle(LVS_EX_FLATSB 
		| LVS_EX_FULLROWSELECT 
		| LVS_EX_HEADERDRAGDROP 
		| LVS_EX_ONECLICKACTIVATE 
		| LVS_EX_GRIDLINES);

	m_gridSs.ShowWindow(SW_SHOW);
	m_gridSs.InsertColumn(0, "文件名", LVCFMT_LEFT,  100);
	m_gridSs.InsertColumn(1, "大小", LVCFMT_LEFT,  100);
	m_gridSs.InsertColumn(2, "来源", LVCFMT_LEFT,  60);
//	m_gridSs.InsertColumn(3, "", LVCFMT_LEFT,  60);
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
