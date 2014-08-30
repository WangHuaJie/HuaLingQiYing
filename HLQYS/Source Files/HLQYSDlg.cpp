
// HLQYSDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HLQYS.h"
#include "HLQYSDlg.h"
#include "afxdialogex.h"
#include "ListenSock.h"
#include "ServerSock.h"
#include "MsgStruct.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//ListenSock listensock;
ServerSock serversock;
//CSocket serversock2;
//CPtrList socklist;

// CHLQYSDlg 对话框




CHLQYSDlg::CHLQYSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHLQYSDlg::IDD, pParent)
	, showinfostr(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHLQYSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1_Start, B_Start);
	DDX_Control(pDX, IDC_EDIT1_Show_Info, servershowinfo);
	DDX_Text(pDX, IDC_EDIT1_Show_Info, showinfostr);
}

BEGIN_MESSAGE_MAP(CHLQYSDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1_Start, &CHLQYSDlg::OnBnClickedButton1Start)
	ON_EN_CHANGE(IDC_EDIT1_Show_Info, &CHLQYSDlg::OnEnChangeEdit1ShowInfo)
END_MESSAGE_MAP()


// CHLQYSDlg 消息处理程序

BOOL CHLQYSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHLQYSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHLQYSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHLQYSDlg::OnBnClickedButton1Start()
{
	// TODO: 在此添加控件通知处理程序代码

	CString IP = (CString)"127.0.0.1";
	UINT	Port = 8080;
//	CString mes1 = (CString)"已成功监听端口！";
	CString mes2 = (CString)"Attention";
	CString mes3 = (CString)"Listen failed!";
	
//	MessageBox(IP);
	serversock.SetDialog(this);
	serversock.Create(Port,SOCK_STREAM,IP);
	BOOL lsn = serversock.Listen();
	if(lsn)
	{
		B_Start.EnableWindow(FALSE);
//		MessageBox(mes1,mes2);
	}
	else
	{
		MessageBox(mes3,mes2);
	}
	
	while(1)
	{
//		CString mes4 = (CString)"接收新客户请求！"; 
//		ServerSock *serversock2 = new ServerSock();
		ServerSock serversock2;
		serversock2.SetDialog(this);
		if(serversock.Accept(serversock2))
		{
//			MessageBox(mes1);
//			servershowinfo.SetWindowText(mes1);
//			servershowinfo.ReplaceSel(mes4+"\r\n");
//			servershowinfo.ReplaceSel(mes4);
//			socklist.AddTail(serversock2);	
		}
		else
		{
			serversock2.Close();
		}
/*
		char idbuffer[BUFFER_SIZE];
		char pwdbuffer[BUFFER_SIZE];

		int revnumi = serversock2.Receive(idbuffer,BUFFER_SIZE);
		int revnump = serversock2.Receive(pwdbuffer,BUFFER_SIZE);
		int revnum = revnumi + revnump;
//		int revnumi = serversock.Receive(idbuffer,4);
		if((revnumi != -1) & (revnump != -1))
		{
			CString revnumi;
			CString mes5 = (CString)"接受到的字节数";
			revnumi.Format(_T("%d"),revnum);
			MessageBox(revnumi,mes5);
		}
		else
		{
			CString revnumi;
			CString mes6 = (CString)"接收信息失败";
			revnumi.Format(_T("%d"),revnumi);
			int err = serversock.GetLastError();
			CString errstr;
			errstr.Format(_T("%d"),err);
			MessageBox(errstr,mes6);

		}
	
//		serversock.Receive(pwdbuffer,BUFFER_SIZE);

		CString IdBuffer = (CString)idbuffer;
		CString PwdBuffer = (CString)pwdbuffer;
	
		servershowinfo.ReplaceSel(IdBuffer +" 用户已登录  密码：" + "\r");
		servershowinfo.ReplaceSel(PwdBuffer + "\r\n");
//		MessageBox(IdBuffer)
*/

		struct StrMsg info;
		serversock2.RecLogInfo(&info);
		CString idbuffer =(CString)info.m_strLogin.m_szUID;
		CString pwdbuffer = (CString)info.m_strLogin.m_szPWD;
		servershowinfo.ReplaceSel(idbuffer +" 用户已登录  密码：" + "\r");
		servershowinfo.ReplaceSel(pwdbuffer + "\r\n");
		

		Sleep(1000);
	}

}



void CHLQYSDlg::OnEnChangeEdit1ShowInfo()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	


}

void CHLQYSDlg::AcceptConnect()
{
	CString mes1 = (CString)"接收新客户请求！"; 
	CString mes2 = (CString)"Attention";

	ServerSock *pSock = new ServerSock();
	pSock->SetDialog(this);
	if(serversock.Accept(*pSock))
	{
		MessageBox(mes1);
		servershowinfo.SetWindowText(mes1);
		socklist.AddTail(pSock);	
	}
	else
	{
		delete pSock;
	}
}

void CHLQYSDlg::ReceiveData(CSocket &socket)
{
	char pBuffer[BUFFER_SIZE];
	int nReceiveNum = socket.Receive(pBuffer,BUFFER_SIZE);
	if(nReceiveNum != -1)
	{
		pBuffer[nReceiveNum] = 0;
		POSITION pos = socklist.GetHeadPosition();
		while(pos != NULL)
		{
			ListenSock * pSocket = (ListenSock *)socklist.GetNext(pos);
			if(pSocket != NULL)
			{
				pSocket->Send(pBuffer,nReceiveNum);
			}
		}
	}
}