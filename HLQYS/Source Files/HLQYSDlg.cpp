
// HLQYSDlg.cpp : ʵ���ļ�
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

// CHLQYSDlg �Ի���




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


// CHLQYSDlg ��Ϣ�������

BOOL CHLQYSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHLQYSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHLQYSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHLQYSDlg::OnBnClickedButton1Start()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString IP = (CString)"127.0.0.1";
	UINT	Port = 8080;
//	CString mes1 = (CString)"�ѳɹ������˿ڣ�";
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
//		CString mes4 = (CString)"�����¿ͻ�����"; 
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
			CString mes5 = (CString)"���ܵ����ֽ���";
			revnumi.Format(_T("%d"),revnum);
			MessageBox(revnumi,mes5);
		}
		else
		{
			CString revnumi;
			CString mes6 = (CString)"������Ϣʧ��";
			revnumi.Format(_T("%d"),revnumi);
			int err = serversock.GetLastError();
			CString errstr;
			errstr.Format(_T("%d"),err);
			MessageBox(errstr,mes6);

		}
	
//		serversock.Receive(pwdbuffer,BUFFER_SIZE);

		CString IdBuffer = (CString)idbuffer;
		CString PwdBuffer = (CString)pwdbuffer;
	
		servershowinfo.ReplaceSel(IdBuffer +" �û��ѵ�¼  ���룺" + "\r");
		servershowinfo.ReplaceSel(PwdBuffer + "\r\n");
//		MessageBox(IdBuffer)
*/

		struct StrMsg info;
		serversock2.RecLogInfo(&info);
		CString idbuffer =(CString)info.m_strLogin.m_szUID;
		CString pwdbuffer = (CString)info.m_strLogin.m_szPWD;
		servershowinfo.ReplaceSel(idbuffer +" �û��ѵ�¼  ���룺" + "\r");
		servershowinfo.ReplaceSel(pwdbuffer + "\r\n");
		

		Sleep(1000);
	}

}



void CHLQYSDlg::OnEnChangeEdit1ShowInfo()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	


}

void CHLQYSDlg::AcceptConnect()
{
	CString mes1 = (CString)"�����¿ͻ�����"; 
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