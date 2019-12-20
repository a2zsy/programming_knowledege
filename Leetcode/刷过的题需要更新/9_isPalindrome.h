//��Ŀ9���ж�һ�����Ƿ��ǻ���
#include<iostream>
#include<vector>
using namespace std;



/*�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

ʾ�� 1:

����: 121
	��� : true
	ʾ��?2 :

	���� : -121
	��� : false
	���� : �������Ҷ�, Ϊ - 121 �� ���������, Ϊ 121 - �����������һ����������
	ʾ�� 3 :

	���� : 10
	��� : false
	���� : ���������, Ϊ 01 �����������һ����������*/


//�Լ����㷨�����������ļ򵥲�������ʵ���Լ�Ϊ����һ�������һ�룬ֱ�ӽ���ǰ����ȣ���Ҫ�ǳ��Ȳ�̫���ж������Ļ���
class Solution1 {
public:
	bool isPalindrome(int x) {
		if (x < 0) { return false; }
		vector<int> smallx1;
		int i = 0;
		while ((x / 10) != 0 || (x % 10) != 0)
		{
			smallx1.push_back(x % 10);
			x /= 10;
		}
		vector<int> smallx2(smallx1);
		std::reverse(smallx1.begin(), smallx1.end());
		while (i != smallx2.size())
		{
			if (smallx1[i] != smallx2[i])
			{
				return false;
			}
			i++;
		}
		return true;

	}
};


//�򵥵�ֽƬ���ۣ������������ʵ��
class Solution2 {
public:
	bool isPalindrome(int x) {
		if (x < 0)   return false;
		int len = 0;
		int copy = 0;
		for (int i = x; i; i /= 10)  ++len;
		for (int j = len / 2; j > 0; --j) {
			copy = copy * 10 + x % 10;
			x /= 10;
		}
		if (len % 2 == 1)    x /= 10;
		if (copy == x)   return true;
		return false;
	}
};