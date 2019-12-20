#include<string>
using namespace std;
//一步一步判断，首先找到第一个非空字符，把其赋给子串，再对子串接下来的字符一个个遍历；

class Solution2 {
public:
	int myAtoi(string str) {
		if (str.empty())
			return 0;
		int len = str.size();
		int pos = str.find_first_not_of(" ");//寻找字符串开头不为空格的位置
		if (pos != -1)//若找到
			str = str.substr(pos, len - pos + 1);
		bool flag = false;//标志符号，false为正，true为负
		long long res = 0;//设置为long long型是防止转换过程溢出
		if ((str[0] <= '9' && str[0] >= 0) || str[0] == '+' || str[0] == '-')//合法字符范围
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
					if (res > INT_MAX)//判断溢出
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
		if (flag)//是负数取相反数
		{
			res = 0 - res;
		}
		return res;
	}
};

