// HLQYSock.cpp : 实现文件
//

#include "stdafx.h"
#include "HLQY.h"
#include "HLQYSock.h"
#include "MsgStruct.h"
#include "HLQYDlg.h"


// HLQYSock


HLQYSock::HLQYSock()
{
}

HLQYSock::~HLQYSock()
{
}


// HLQYSock 成员函数
//int HLQYSock::SendUserInfor(HLQYSock sock,CString uid,CString pwd)
int HLQYSock::SendUserInfor(CString uid,CString pwd)
{	
	StrMsg info;
	info.m_nMsgType = 1;
	strcpy(info.m_strLogin.m_szUID,uid);
	strcpy(info.m_strLogin.m_szPWD,pwd);
	if(this->Send(&info,sizeof(struct StrMsg)))
		return 1;
	else
		return -1;
}