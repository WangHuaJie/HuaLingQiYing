#pragma once
#include "afxsock.h"

class CHLQYDlg;
// HLQYSock ����Ŀ��

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

	//�����û���Ϣ����
	int SendUserInfor(CString uid,CString pwd);
/*
	void OnReceive(int nErrorCode)
	{
		CSocket::OnReceive(nErrorCode);
		if(m_pDlg != NULL)
*/	
};


