#include<string>
using namespace std;
//һ��һ���жϣ������ҵ���һ���ǿ��ַ������丳���Ӵ����ٶ��Ӵ����������ַ�һ����������

class Solution2 {
public:
	int myAtoi(string str) {
		if (str.empty())
			return 0;
		int len = str.size();
		int pos = str.find_first_not_of(" ");//Ѱ���ַ�����ͷ��Ϊ�ո��λ��
		if (pos != -1)//���ҵ�
			str = str.substr(pos, len - pos + 1);
		bool flag = false;//��־���ţ�falseΪ����trueΪ��
		long long res = 0;//����Ϊlong long���Ƿ�ֹת���������
		if ((str[0] <= '9' && str[0] >= 0) || str[0] == '+' || str[0] == '-')//�Ϸ��ַ���Χ
		{
			int i = 0;
			if (str[0] == '+')
			{
				i = 1;
			}
			else if (str[0] == '-')
			{
				flag = true;
				i = 1;
			}
			for (; i < str.size(); i++)
			{
				if (str[i] <= '9' && str[i] >= '0')
				{
					res = res * 10 + (str[i] - '0');
					if (res > INT_MAX)//�ж����
					{
						if (flag)
							return INT_MIN;
						else return INT_MAX;
					}
				}
				else break;
			}
		}
		else return 0;
		if (flag)//�Ǹ���ȡ�෴��
		{
			res = 0 - res;
		}
		return res;
	}
};

