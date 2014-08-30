#pragma once
#include "HLQYSDlg.h"
#include "afxsock.h"

class CHLQYSDlg;

// ListenSock ÃüÁîÄ¿±ê

class ListenSock : public CSocket
{
public:
	ListenSock();
	virtual ~ListenSock();

//	CHLQYSDlg * m_pDlg;

	void SetDialog(CHLQYSDlg * pDlg);
/*	{
		m_pDlg = pDlg;
	}
*/
	void OnReceive(int nErrorCode);
};

/*
void ListenSock::OnReceive(int nErrorCode)
{
	if(m_pDlg)
	{
		m_pDlg->ReceiveData(*this);
	}

}
*/