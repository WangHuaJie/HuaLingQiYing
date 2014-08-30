// Uping.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "Uping.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUping dialog


CUping::CUping(CWnd* pParent /*=NULL*/)
	: CDialog(CUping::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUping)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUping::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUping)
	DDX_Control(pDX, IDC_LIST1, m_gridUping);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUping, CDialog)
	//{{AFX_MSG_MAP(CUping)
	ON_BN_CLICKED(IDC_BTN_NEW, OnBtnNew)
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, OnBtnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUping message handlers

void CUping::OnBtnNew() 
{
	// TODO: Add your control notification handler code here
	
}

void CUping::OnBtnStart() 
{
	// TODO: Add your control notification handler code here
	
}

void CUping::OnBtnStop() 
{
	// TODO: Add your control notification handler code here
	
}

BOOL CUping::OnInitDialog() 
{
	CDialog::OnInitDialog();
	LONG lStyle = GetWindowLong(m_gridUping.m_hWnd, GWL_STYLE);
	lStyle |= LVS_EDITLABELS;	// |= ��λ���㣬�������ؼ����������
	SetWindowLong(m_gridUping, GWL_STYLE, lStyle);	// ���µ��������û�����ؼ�
	// ���棬������������ؼ��ĸ�������
	m_gridUping.SetExtendedStyle(LVS_EX_FLATSB 
		| LVS_EX_FULLROWSELECT 
		| LVS_EX_HEADERDRAGDROP 
		| LVS_EX_ONECLICKACTIVATE 
		| LVS_EX_GRIDLINES);

	m_gridUping.ShowWindow(SW_SHOW);
	m_gridUping.InsertColumn(0, "�ļ���", LVCFMT_LEFT,  100);
	m_gridUping.InsertColumn(1, "��С", LVCFMT_LEFT,  100);
	m_gridUping.InsertColumn(2, "ʣ��ʱ��", LVCFMT_LEFT,  60);
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
