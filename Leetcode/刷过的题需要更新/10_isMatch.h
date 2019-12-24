//正则化匹配，题目比较难，但是化为递归或动态规划后，就不那么难了
/*给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明 :

s 可能为空，且只包含从 a - z 的小写字母。
p 可能为空，且只包含从 a - z 的小写字母，以及字符 .和 * 。
示例 1 :
	输入 :s = "aa" p = "a"	输出 : false
	解释 : "a" 无法匹配 "aa" 整个字符串。
	示例 2 :
	输入 :	s = "aa"	p = "a*"
	输出 : true
	解释 : 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
	示例 3 :输入:s = "ab" p = ".*"
	输出 : true
	解释 : ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
	示例 4 :
	输入 :s = "aab"	p = "c*a*b"
	输出 : true
	解释 : 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
	示例 5 :
	输入 :	s = "mississippi"	p = "mis*is*p*."
	输出 : false
*/
//递归解法

class Solution1 {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) { return s.empty(); }
		bool first_match = (!s.empty()) && (p[0] == s[0] || p[0] == '.');
		if (p.length() >= 2 && p[1] == '*')
		{
			return(isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
		}
		else
		{
			return first_match && isMatch(s.substr(1), p.substr(1));
		}

	}
};

//动态规划 巧妙一点的方法
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (j > 1 && p[j - 1] == '*') {
					if (i > 0) dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
					dp[i][j] = dp[i][j] || dp[i][j - 2];
				}
				else if (i > 0) {
					dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
			}
		}
		return dp[m][n];
	}
};

