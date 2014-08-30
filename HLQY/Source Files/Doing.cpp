// Doing.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "Doing.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDoing dialog


CDoing::CDoing(CWnd* pParent /*=NULL*/)
	: CDialog(CDoing::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDoing)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDoing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDoing)
	DDX_Control(pDX, IDC_LIST1, m_grid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDoing, CDialog)
	//{{AFX_MSG_MAP(CDoing)
	ON_BN_CLICKED(IDC_BTN_BACK, OnBtnBack)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDoing message handlers

BOOL CDoing::OnInitDialog() 
{
	CDialog::OnInitDialog();
	LONG lStyle = GetWindowLong(m_grid.m_hWnd, GWL_STYLE);
	lStyle |= LVS_EDITLABELS;	// |= ��λ���㣬�������ؼ����������
	SetWindowLong(m_grid, GWL_STYLE, lStyle);	// ���µ��������û�����ؼ�
	// ���棬������������ؼ��ĸ�������
	m_grid.SetExtendedStyle(LVS_EX_FLATSB 
		| LVS_EX_FULLROWSELECT 
		| LVS_EX_HEADERDRAGDROP 
		| LVS_EX_ONECLICKACTIVATE 
		| LVS_EX_GRIDLINES);

	m_grid.ShowWindow(SW_SHOW);
	m_grid.InsertColumn(0, "�ļ���", LVCFMT_LEFT,  100);
	m_grid.InsertColumn(1, "��С", LVCFMT_LEFT,  100);
	m_grid.InsertColumn(2, "��Դ", LVCFMT_LEFT,  60);


	CFont font;
    font.CreatePointFont(100,_T("����"),NULL);
    GetDlgItem(IDC_STATIC_DOWN)->SetFont(&font);
	


	
	return TRUE;  // return TRUE unless you set the focus to a control
	
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDoing::OnBtnBack() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	
}

void CDoing::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here
	int nCount=m_grid.GetItemCount();
	if(nCount<1)
	{
		AfxMessageBox("�Բ�������Ϊ�գ�����ɾ��");
		return;
	}
	nCount=m_grid.GetSelectedCount();
	if(nCount<1)
	{
		AfxMessageBox("û��ѡ�е��У�����ѡ��Ҫɾ������");
		return;
	}
	int nTemp=0;



	POSITION pos=m_grid.GetFirstSelectedItemPosition();
	while(pos)
	{
		int nIndex=m_grid.GetNextSelectedItem(pos);
		nIndex-=nTemp;
		nTemp++;
		m_grid.DeleteItem(nIndex);

	}
	
}

//OnCtlColor
/*BOOL CDoing::OnInitDialog(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
HBRUSH hbr = CDialog::OnInitDialog(pDC, pWnd, nCtlColor);

if(nCtlColor==CTLCOLOR_STATIC)   
  {  
  pDC->SetTextColor(RGB(0,0,0));
  pDC->SetBkColor(RGB(249,199,63));//���ֱ���ɫ
  HBRUSH b=CreateSolidBrush(RGB(249,199,63));//�ؼ�����ɫ   
  return b;
 }   
 return TRUE;
}*/

