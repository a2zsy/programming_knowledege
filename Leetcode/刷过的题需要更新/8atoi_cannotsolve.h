//atoi������δ��ͨ�������ƽ⣬��Ҫ���ǵ����̫�ࣻ
#include<iostream>
#include<string>
using namespace std;

/*������ʵ��һ��?atoi?������ʹ���ܽ��ַ���ת����������
���ȣ��ú����������Ҫ�������õĿ�ͷ�ո��ַ���ֱ��Ѱ�ҵ���һ���ǿո���ַ�Ϊֹ��
������Ѱ�ҵ��ĵ�һ���ǿ��ַ�Ϊ�����߸���ʱ���򽫸÷�����֮���澡���ܶ���������������������Ϊ�������������ţ������һ���ǿ��ַ������֣���ֱ�ӽ�����֮�������������ַ�����������γ�������
���ַ���������Ч����������֮��Ҳ���ܻ���ڶ�����ַ�����Щ�ַ����Ա����ԣ����Ƕ��ں�����Ӧ�����Ӱ�졣
ע�⣺������ַ����еĵ�һ���ǿո��ַ�����һ����Ч�����ַ����ַ���Ϊ�ջ��ַ����������հ��ַ�ʱ������ĺ�������Ҫ����ת����
���κ�����£����������ܽ�����Ч��ת��ʱ���뷵�� 0��
˵����
�������ǵĻ���ֻ�ܴ洢 32 λ��С���з�����������ô����ֵ��ΧΪ?[?231,? 231?? 1]�������ֵ���������Χ��qing���� ?INT_MAX (231?? 1) ��?INT_MIN (?231) ��
ʾ��?1:
����: "42"
���: 42
ʾ��?2:
����: "   -42"
���: -42
����: ��һ���ǿհ��ַ�Ϊ '-', ����һ�����š�
���Ǿ����ܽ���������������������ֵ�����������������õ� -42 ��
ʾ��?3:
����: "4193 with words"
���: 4193
����: ת����ֹ������ '3' ����Ϊ������һ���ַ���Ϊ���֡�
ʾ��?4:
����: "words and 987"
���: 0
����: ��һ���ǿ��ַ��� 'w', �����������ֻ��������š�����޷�ִ����Ч��ת����
ʾ��?5:
����: "-91283472332"
���: -2147483648
����: ���� "-91283472332" ���� 32 λ�з���������Χ�� 
?    ��˷��� INT_MIN (?231) ��
��*/


//�Լ���Ӳ�Ľⷨ���������������--�ո�ֻ���Ե�һ���ǿ��ַ���ǰ�Ŀո񣬺����ȥ���ˡ�
class Solution1 {
public:
	int myAtoi(string str) {
		int count = 0;
		int given = 0;
		string result = "";
		bool flag = false;     //�жϱ�־λ�Ƿ����
		for (auto i = 0; i <= str.length() - 1; i++)
		{
			if (flag == false && result.length() == 0 && (str[i] == '+' || str[i] == '-'))
			{
				flag = true;
				result.push_back(str[i]);
				continue;

			}
			if (str[i] >= '0' && str[i] <= '9')
			{

				result.push_back(str[i]);
				continue;
			}
			else
			{
				if (str[i] == ' ' || (flag == false && (str[i] == '+' || str[i] == '-')))
				{
					continue;
				}
				else {
					break;
				}
			}

		}
		if (result.length() == 0) { return 0; }
		if (flag == true)
		{
			given = getnumber(result, 1, result.length() - 1);
			if (result[0] == '-')
			{
				if (given == INT_MAX)
				{
					given = (-1) * (INT_MAX + 1);
				}
				else {
					given = (-1) * given;
				}
			}
			else {
				given = given;
			}
		}
		if (flag == false)
		{
			given = getnumber(result, 0, result.length() - 1);
		}

		return given;
	}
	int getnumber(string result, int start, int end)
	{
		int x = start;
		int res = 0;
		while (x <= end)
		{
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && result[x] > 55)) return INT_MAX;
			res = res * 10 + (result[x] - 48);
			x++;
		}
		return res;

	}
};