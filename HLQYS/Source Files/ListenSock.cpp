// ListenSock.cpp : 实现文件
//

#include "stdafx.h"
#include "HLQYS.h"
#include "ListenSock.h"

#include "afxsock.h"
class CHLQYSDlg;
CHLQYSDlg * m_pDlg;
// ListenSock

ListenSock::ListenSock()
{
}

ListenSock::~ListenSock()
{
}


// ListenSock 成员函数

void SetDialog(CHLQYSDlg * pDlg)
{
	m_pDlg = pDlg;
}

void ListenSock::OnReceive(int nErrorCode)
{
	if(m_pDlg)
	{
		m_pDlg->ReceiveData(*this);
	}

}