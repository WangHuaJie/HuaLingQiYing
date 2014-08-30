// HLQYDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HLQY.h"
#include "HLQYDlg.h"
#include "Login.h"
#include "Main.h"
#include "MsgStruct.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HLQYSock m_SockClient;
/////////////////////////////////////////////////////////////////////////////
// CHLQYDlg dialog

CHLQYDlg::CHLQYDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHLQYDlg::IDD, pParent)
	, m_PWD(_T(""))
	, m_UID(_T(""))
{
	//{{AFX_DATA_INIT(CHLQYDlg)
	//  m_UID = _T("");
	//  m_PWD = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHLQYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHLQYDlg)
	//  DDX_Text(pDX, IDC_E_UID, m_UID);
	//  DDX_Text(pDX, IDC_E_PWD, m_PWD);
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_E_PWD, m_PWD);
	DDV_MaxChars(pDX, m_PWD, 225);
	DDX_Text(pDX, IDC_E_UID, m_UID);
	DDV_MaxChars(pDX, m_UID, 255);
	DDX_Control(pDX, IDC_E_UID, m_eUID);
	DDX_Control(pDX, IDC_E_PWD, m_ePWD);
}

BEGIN_MESSAGE_MAP(CHLQYDlg, CDialog)
	//{{AFX_MSG_MAP(CHLQYDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ZHUCE, OnBtnZhuce)
	ON_BN_CLICKED(IDC_BTN_DENGLU, OnBtnDenglu)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_E_UID, &CHLQYDlg::OnEnChangeEUid)
	ON_EN_CHANGE(IDC_E_PWD, &CHLQYDlg::OnEnChangeEPwd)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHLQYDlg message handlers

BOOL CHLQYDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	
	

	// TODO: Add extra initialization here
	int tmp;
	if((tmp = m_SockClient.Create()))
	{
//		MessageBox("socket create success!","Attention");
	}
	else
	{
		CString str ;
		str.Format("%d",tmp);

		MessageBox(str,"Error");
	}
	m_SockClient.SetDialog(this);



	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHLQYDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHLQYDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHLQYDlg::OnBtnZhuce() 
{
	// TODO: Add your control notification handler code here
	CLogin a;
	a.DoModal();
	m_PWD=a.m_Key2;
    m_UID=a.m_Name;
    UpdateData(FALSE);
	

	
}

void CHLQYDlg::OnBtnDenglu() 
{
	// TODO: Add your control notification handler code here
	

	CString IP = "127.0.0.1";
	UINT	Port = 8080;
//	CString str = CString(m_UID);
//	MessageBox(m_UID,"user");
//	MessageBox(m_PWD,"password");
	MessageBox("正在登陆，请稍后","Attention");
	if(m_SockClient.Connect(IP,Port))
	{
//		MessageBox("Connect to server success!","Attention!");
	
		this->ShowWindow(SW_HIDE);
		CMain  h;
		h.DoModal();
	
	}
	else
	{
		MessageBox("Connect to server failed!","Attention!");
		this->ShowWindow(SW_HIDE);
		CMain  h;
		h.DoModal();
	}

/*	//将客户信息发送给服务器
	if(!m_UID.IsEmpty() && !m_PWD.IsEmpty())
	{
		int snum1,snum2;
		CString mes1 = (CString)"user Id send success";
		CString mes2 = (CString)"user password send success";

		if(snum1 = m_SockClient.Send(m_UID,BUFFER_SIZE))
		{
//			CString mes3;
//			mes3.Format(_T("%d"),snum1);
//			MessageBox("发送字节数:"+mes3,mes1);
		}

//		if(snum2 = m_SockClient.Send(m_PWD.GetBuffer(m_PWD.GetLength()),m_PWD.GetLength()))
		if(snum2 = m_SockClient.Send(m_PWD.GetBuffer(m_PWD.GetLength()),BUFFER_SIZE))
		{
			MessageBox(mes2);
		}
	}
*/
	CString mes1 = (CString)"user information send success!";
	CString mes2 = (CString)"user information send failed!";
	if(!m_UID.IsEmpty() && !m_PWD.IsEmpty())
		if( m_SockClient.SendUserInfor(m_UID,m_PWD))
			MessageBox(mes1);
		else
			MessageBox(mes2);
	
}


void CHLQYDlg::OnEnChangeEUid()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	m_eUID.GetWindowText(m_UID);

	
}


void CHLQYDlg::OnEnChangeEPwd()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	m_ePWD.GetWindowText(m_PWD);
	
}

