// Up.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "Up.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUp dialog


CUp::CUp(CWnd* pParent /*=NULL*/)
	: CDialog(CUp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUp)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUp)
	DDX_Control(pDX, IDC_LIST1, m_gridUp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUp, CDialog)
	//{{AFX_MSG_MAP(CUp)
	ON_BN_CLICKED(IDC_BTN_DAKAI, OnBtnDakai)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUp message handlers

void CUp::OnBtnDakai() 
{
	// TODO: Add your control notification handler code here
	
}

BOOL CUp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	LONG lStyle = GetWindowLong(m_gridUp.m_hWnd, GWL_STYLE);
	lStyle |= LVS_EDITLABELS;	// |= 是位运算，用来给控件添加新属性
	SetWindowLong(m_gridUp, GWL_STYLE, lStyle);	// 将新的属性设置回网格控件
	// 下面，还将设置网格控件的附加属性
	m_gridUp.SetExtendedStyle(LVS_EX_FLATSB 
		| LVS_EX_FULLROWSELECT 
		| LVS_EX_HEADERDRAGDROP 
		| LVS_EX_ONECLICKACTIVATE 
		| LVS_EX_GRIDLINES);

	m_gridUp.ShowWindow(SW_SHOW);
	m_gridUp.InsertColumn(0, "文件名", LVCFMT_LEFT,  100);
	m_gridUp.InsertColumn(1, "大小", LVCFMT_LEFT,  100);
	m_gridUp.InsertColumn(2, "上传时间", LVCFMT_LEFT,  60);
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
