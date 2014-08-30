
// HLQYSDlg.h : ͷ�ļ�
//

#pragma once
#include "ListenSock.h"
#include "ServerSock.h"
#include "afxwin.h"
#define BUFFER_SIZE 256

// CHLQYSDlg �Ի���
class CHLQYSDlg : public CDialogEx
{
// ����
public:
	CHLQYSDlg(CWnd* pParent = NULL);	// ��׼���캯��
	
	ServerSock serversock;
	CPtrList socklist;

// �Ի�������
	enum { IDD = IDD_HLQYS_DIALOG };


	void AcceptConnect();
/*
{
	CString mes1 = (CString)"�����¿ͻ�����"; 
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
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1Start();
	// ������ť
	CButton B_Start;
	afx_msg void OnEnChangeEdit1ShowInfo();
	// ����˵ĶԻ�������ʾ�ͻ���¼����Ϣ
	CEdit servershowinfo;
	CString showinfostr;
};
