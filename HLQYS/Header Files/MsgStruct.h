#define MSG_TYPE_LOGIN		1
#define MSG_TYPE_LOGINRST	2
#define MSG_TYPE_REG		3
#define MSG_TYPE_REGRST		4
// ����������������Ҫ��ÿһ����Ϣ���ͣ�������Ϊ��
// �������ĺô����ǿ�����ߴ���Ŀɶ��ԣ����򻯴����޸�ʱ�Ĺ�����

// ��½��Ϣ�ṹ��
struct StrLogin
{
	char m_szUID[20];
	char m_szPWD[20];
};

// ��½���ؽ���Ľṹ��
struct StrLoginRst
{
	int	m_nLoginRst;
};

// ע��ṹ��
struct StrReg
{
	char m_szUID[20];
	char m_szPWD[20];
	char m_szCFMPWD[20];
};

// ע�᷵�صĽ���Ľṹ��
struct StrRegRst
{
	int m_nRegRst;
};

// ��Ϣ�շ����ܽṹ��
//  �����¼�������Ӧ��Ӧ�Ľṹ��
//  �����ﶼ�������ϵķ�ʽ����

// m_nMsgType����Ϣ���ͣ�
//   ��������յ���Ϣʱ��������StrMsg�����ܵ���Ϣ����
//   Ȼ���ȡm_nMsgType,�������жϣ�
//     ������Ϣ���͵Ĳ�ͬ���ò�ͬ���ӽṹ��ȥ�������ϵ�����
//     ��ת������ͬ����Ϣ�����֧���д���
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