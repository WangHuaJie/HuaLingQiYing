#define MSG_TYPE_LOGIN		1
#define MSG_TYPE_LOGINRST	2
#define MSG_TYPE_REG		3
#define MSG_TYPE_REGRST		4
// 如上所述，我们需要把每一种消息类型，都定义为宏
// 这样做的好处，是可以提高代码的可读性，并简化代码修改时的工作量

// 登陆消息结构体
struct StrLogin
{
	char m_szUID[20];
	char m_szPWD[20];
};

// 登陆返回结果的结构体
struct StrLoginRst
{
	int	m_nLoginRst;
};

// 注册结构体
struct StrReg
{
	char m_szUID[20];
	char m_szPWD[20];
	char m_szCFMPWD[20];
};

// 注册返回的结果的结构体
struct StrRegRst
{
	int m_nRegRst;
};

// 消息收发的总结构体
//  所有事件及其响应对应的结构体
//  在这里都被以联合的方式保存

// m_nMsgType是消息类型，
//   当程序接收到消息时，会先用StrMsg保存总的消息内容
//   然后读取m_nMsgType,并进行判断，
//     根据消息类型的不同，用不同的子结构体去接收联合的内容
//     并转发给不同的消息处理分支进行处理
struct StrMsg
{
	int m_nMsgType;
	union
	{
		struct StrLogin			m_strLogin;
		struct StrLoginRst		m_strLoginRst;
		struct StrReg           m_strReg;
		struct StrRegRst        m_strRegRst;
	};
};