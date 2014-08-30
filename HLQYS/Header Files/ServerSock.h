#pragma once
#include "afxsock.h"
//#include "ListenSock.h"
//#include "HLQYSDlg.h"

//前导声明CHLQYDlg类
class CHLQYSDlg;    

// ServerSock 命令目标

class ServerSock : public CSocket
{
public:
	ServerSock();
	virtual ~ServerSock();

//	class CHLQYSDlg;
	CHLQYSDlg * m_pDlg;

	void SetDialog(CHLQYSDlg * pDlg)
	{
		m_pDlg = pDlg;
	}

	int RecLogInfo(struct StrMsg * info);
//	void OnAccept(int nErrorCode);
/*
	void OnAccept(int nErrorCode)
	{
		CSocket::OnAccept(nErrorCode);
		if(m_pDlg)
			m_pDlg->AcceptConnect();
	}
*/

};

/*
void ServerSock::OnAccept(int nErrorCode)
{
		CSocket::OnAccept(nErrorCode);
		if(m_pDlg)
			m_pDlg->AcceptConnect();
}
*/