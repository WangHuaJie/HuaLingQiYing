
// HLQYSDlg.h : 头文件
//

#pragma once
#include "ListenSock.h"
#include "ServerSock.h"
#include "afxwin.h"
#define BUFFER_SIZE 256

// CHLQYSDlg 对话框
class CHLQYSDlg : public CDialogEx
{
// 构造
public:
	CHLQYSDlg(CWnd* pParent = NULL);	// 标准构造函数
	
	ServerSock serversock;
	CPtrList socklist;

// 对话框数据
	enum { IDD = IDD_HLQYS_DIALOG };


	void AcceptConnect();
/*
{
	CString mes1 = (CString)"接收新客户请求！"; 
	CString mes2 = (CString)"Attention";

	ServerSock *pSock = new ServerSock();
	pSock->SetDialog(this);
	if(serversock.Accept(*pSock))
	{
		MessageBox(mes1);
		servershowinfo.SetWindowTextW(mes1);
		socklist.AddTail(pSock);	
	}
	else
	{
		delete pSock;
	}
}
*/

	void ReceiveData(CSocket &socket);
/*
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
*/

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1Start();
	// 启动按钮
	CButton B_Start;
	afx_msg void OnEnChangeEdit1ShowInfo();
	// 服务端的对话框中显示客户登录等信息
	CEdit servershowinfo;
	CString showinfostr;
};
