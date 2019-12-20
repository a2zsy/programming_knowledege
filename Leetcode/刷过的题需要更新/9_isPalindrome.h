//题目9：判断一个数是否是回文
#include<iostream>
#include<vector>
using namespace std;



/*判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
	输出 : true
	示例?2 :

	输入 : -121
	输出 : false
	解释 : 从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
	示例 3 :

	输入 : 10
	输出 : false
	解释 : 从右向左读, 为 01 。因此它不是一个回文数。*/


//自己的算法，利用容器的简单操作；其实可以简化为化简一个数组的一半，直接进行前后相比（主要是长度不太好判断这样的话）
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


//简单的纸片对折，无需多余容器实现
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