// Done.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "Done.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDone dialog


CDone::CDone(CWnd* pParent /*=NULL*/)
	: CDialog(CDone::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDone)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDone::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDone)
	DDX_Control(pDX, IDC_LIST1, m_gridDone);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDone, CDialog)
	//{{AFX_MSG_MAP(CDone)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDone message handlers

BOOL CDone::OnInitDialog() 
{
	CDialog::OnInitDialog();
	LONG lStyle = GetWindowLong(m_gridDone.m_hWnd, GWL_STYLE);
	lStyle |= LVS_EDITLABELS;	// |= 是位运算，用来给控件添加新属性
	SetWindowLong(m_gridDone, GWL_STYLE, lStyle);	// 将新的属性设置回网格控件
	// 下面，还将设置网格控件的附加属性
	m_gridDone.SetExtendedStyle(LVS_EX_FLATSB 
		| LVS_EX_FULLROWSELECT 
		| LVS_EX_HEADERDRAGDROP 
		| LVS_EX_ONECLICKACTIVATE 
		| LVS_EX_GRIDLINES);

	m_gridDone.ShowWindow(SW_SHOW);
	m_gridDone.InsertColumn(0, "文件名", LVCFMT_LEFT,  100);
	m_gridDone.InsertColumn(1, "大小", LVCFMT_LEFT,  100);
	m_gridDone.InsertColumn(2, "下载时间", LVCFMT_LEFT,  60);
	m_gridDone.InsertColumn(3, "来源", LVCFMT_LEFT,  60);
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
