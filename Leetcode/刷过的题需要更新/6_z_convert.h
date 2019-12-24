//z型字符串转换，主要是数学上建立好逻辑关系，但是编写的代码较为繁琐，可以看看答案正确的操作方式，另有：+=的二目运算符所占用的时间资源更低
#include<string>
using namespace std;
/*将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
示例 1:
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:
*/


class Solution1 {
public:
	string convert(string s, int numRows) {
		int index = 0;
		int row = numRows;
		string res = "";
		int len = s.length();
		int col = 0;
		if (len <= row || numRows == 1) { return s; }
		for (int i = 0; i <= row - 1; i++)
		{
			index = getindex(i, col, row);
			while (index <= len - 1)
			{
				index = getindex(i, col, row);
				if (index >= len)
				{
					break;
				}
				res += s[index];
				if (i == 0 || i == row - 1) { col = col + 2; }
				else { col++; }
			}
			col = 0;
		}
		return res;

	}

	int getindex(int row, int col, int numRows)
	{
		int col1 = col;
		int index = 0;
		int num = numRows;
		if (col1 % 2 == 0)
		{
			index = row + (num - 1) * (col1);
		}
		else
		{
			index = (num - 1) * (col1 + 1) - row;
		}
		return index;
	}
};

/*
//答案的标准操作方式
class Solution {
public:
	string convert(string s, int numRows) {

		if (numRows == 1) return s;

		string ret;
		int n = s.size();
		int cycleLen = 2 * numRows - 2;

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j + i < n; j += cycleLen) {
				ret += s[j + i];
				if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
					ret += s[j + cycleLen - i];
			}
		}
		return ret;
	}
};

*/
