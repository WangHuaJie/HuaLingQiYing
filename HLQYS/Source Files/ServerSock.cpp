// ServerSock.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HLQYS.h"
#include "ServerSock.h"
#include "MsgStruct.h"


// ServerSock

ServerSock::ServerSock()
{
}

ServerSock::~ServerSock()
{
}


// ServerSock ��Ա����

int ServerSock::RecLogInfo(struct StrMsg * info)
{

	CString mes1 = (CString)"can't receive the login informaion";
	CString mes2 = (CString)"receive the login information success";
	int num = this->Receive(info,sizeof(StrMsg));
	if(!num)
	{
		AfxMessageBox(mes1);
		return -1;
	}
	else
	{
		if(info->m_nMsgType == 1)
		{

//			show.ReplaceSel(info->m_strLogin.m_szUID +" �û��ѵ�¼  ���룺" + "\r");
//			show.ReplaceSel(info->m_strLogin.m_szPWD + "\r\n");
			AfxMessageBox(mes2);
			return 0;
		}
		else if(info->m_nMsgType == 2)
		{

		}
		else if(info->m_nMsgType == 3)
		{

		}


	}
}