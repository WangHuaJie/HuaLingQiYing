#pragma once
#include "afxsock.h"

class CHLQYDlg;
// HLQYSock 命令目标

class HLQYSock : public CSocket
{
public:
	HLQYSock();
	virtual ~HLQYSock();

	CHLQYDlg * m_pDlg;

	void SetDialog(CHLQYDlg * pDlg)
	{
		m_pDlg = pDlg;
	}

	//发送用户信息函数
	int SendUserInfor(CString uid,CString pwd);
/*
	void OnReceive(int nErrorCode)
	{
		CSocket::OnReceive(nErrorCode);
		if(m_pDlg != NULL)
*/	
};


