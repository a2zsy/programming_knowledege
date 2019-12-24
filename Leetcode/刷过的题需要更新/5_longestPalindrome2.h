#include<string>
#include<vector>
using namespace std;
//方法二，利用最大子串，即反转字符，比较是否相同，再去原数组当中寻找下标的方法，但时间复杂度仍然比较高
class Solution2 {
public:
	string longestPalindrome(string s) {
		if (s.length() == 1) return s;//大小为1的字符串必为回文串
		string rev = s;//rev存放s反转结果
		string res;//存放结果
		std::reverse(rev.begin(), rev.end());
		if (rev == s) return s;
		int len = 0;//存放回文子串的长度
		for (int i = 0; i < s.length(); i++)//查找s与rev的最长公共子串
		{
			string temp;//存放待验证子串
			for (int j = i; j < s.length(); j++)
			{
				temp += s[j];
				if (len >= temp.length())
					continue;
				else if (rev.find(temp) != -1)//在rev中找到temp
				{
					string q = temp;//q用来验证temp是否是回文子串
					std::reverse(q.begin(), q.end());
					if (q == temp)
					{
						len = temp.length();
						res = temp;
					}
				}
				else break;
			}
			temp = "";
		}
		return res;
	}
};

//建立一个二维的n*n的数组，利用动态规划（ 诸如f（n）=f(n-1)+f(n-2)的状态转移方程的思想，去解决问题）
class Solution3 {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len == 0 || len == 1)
		{
			return s;                    //如果s的字符长度是0或者1，返回本身
		}
		int start = 0;
		int max = 0;  //定义最长长度和起始位置
		vector<vector<int>> arr(len, vector<int>(len));
		int i = 0, j = 0;
		for (i = 0; i <= len - 1; i++)
		{
			arr[i][i] = 1;
			max = 1;
		}
		for (i = 0; i < len - 1; i++)
		{
			if (s[i] == s[i + 1])
			{
				start = i;
				arr[i][i + 1] = 1;
				max = 2;
			}
		}
		for (auto temp = 3; temp <= len; temp++)
		{
			for (i = 0; i <= len - temp; i++)
			{
				j = temp - 1 + i;
				if (s[i] == s[j] && arr[i + 1][j - 1] == 1)
				{
					arr[i][j] = 1;
					max = temp;
					start = i;

				}
			}

		}
		return s.substr(start, max);
	}
};


//从中心去扩展，此处应分奇数偶数，但仍然是n^2的算法，
class Solution4 {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//记录回文子串起始位置
		int end = 0;//记录回文子串终止位置
		int mlen = 0;//记录最大回文子串的长度
		for (int i = 0; i < len; i++)
		{
			int len1 = expendaroundcenter(s, i, i);//一个元素为中心
			int len2 = expendaroundcenter(s, i, i + 1);//两个元素为中心
			mlen =(len1>len2?len1:len2)>mlen?(len1 > len2 ? len1 : len2):mlen ;
			if (mlen > end - start + 1)
			{
				start = i - (mlen - 1) / 2;
				end = i + mlen / 2;
			}
		}
		return s.substr(start, mlen);
		//该函数的意思是获取从start开始长度为mlen长度的字符串
	}
private:
	int expendaroundcenter(string s, int left, int right)
		//计算以left和right为中心的回文串长度
	{
		int L = left;
		int R = right;
		while (L >= 0 && R < s.length() && s[R] == s[L])
		{
			L--;
			R++;
		}
		return R - L - 1;
	}
};
