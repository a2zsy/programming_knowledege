//寻找字符串数组中最长的公共前缀，横向与纵向的比较外，分治与二分查找争取于7.25 6点半之前实现

#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。*/

//第一种方法，通过代入数组中的第一个单词，挨个比较,属于水平比较，纵向就不写了，两种时间复杂度一致，只是最坏情况下有区别。
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";//如果容器vecto为空，则返回“”
		string res = strs[0];//选择第一个字符串作为对照标准
		for (int i = 1; i < strs.size(); i++)
		{
			for (int j = 0; j < res.length(); j++)
			{
				if (res[j] == strs[i][j])
					continue;
				else
				{
					res.erase(j);//找到第一个不符合的字符位置，从pos=j处开始删除直至结尾
					break;
				}
			}
		}
		return res;
	}
};

//分值算法：将一个规模为n的问题切割为k个子问题去解决
//分治算法，不要混淆c++和python循环的毛病
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
		{
			return "";
		}
		else if (strs.size() == 1)
		{
			return strs[0];
		}
		else
			return sub_longestCommonPrefox(strs, 0, strs.size() - 1);
	}
	string sub_longestCommonPrefox(vector<string>& strs, int l, int r) {

		if (l == r) { return strs[l]; }
		else
		{
			int mid = l + (r - l) / 2;
			string leftprefox = sub_longestCommonPrefox(strs, l, mid);
			string rightprefox = sub_longestCommonPrefox(strs, mid + 1, r);
			return check_longestCommonPrefox(leftprefox, rightprefox);
		}

	}
	string check_longestCommonPrefox(string left, string right) {
		int min_len = left.length() < right.length() ? left.length() : right.length();
		for (auto i = 0; i < min_len; i++)
		{
			if (left[i] != right[i])
			{
				return left.substr(0, i);
			}
		}
		return left.substr(0, min_len);


	}
};