//寻找最大不含重复字符的字符串，暴力破解，建立哈希表。实际上难度不高，主要是想明白滑动窗的概；
/*给定一个字符串，请你找出其中不含有重复字符的 最长子串的长度。

示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/



//暴力破解，但是可以通过设置起始的位置去降低时间的复杂度
class Solution1 {
public:
	int lengthOfLongestSubstring(string s) {
		int len = 0;    //存放结果
		int start = 0;    //存放起始查找结果
		string str = "";    //存放无重复字符子串
		int pos = 0;    //存放子串重复位置
		for (int i = 0; i < s.length(); i++) {
			if (str.find(s[i]) == -1) {    //未找到重复字符，放入str
				str = str + s[i];
			}
			else {    //找到重复子串
				len = len > str.length() ? len : str.length();    //更改最大字串长度
				start = s.find_first_of(s[i], start) + 1;   //从start位置查找，并更新start
				pos = str.find_first_of(s[i]);   //在子串中查找重复位置
				str = str.substr(pos + 1) + s[i];    //从重复字符处后一位置截取字符串，并生成新的无重复字串
			}
		}
		len = len > str.length() ? len : str.length();
		return len;
	}
};


//方法二：利用哈希表建立的滑动窗口,字符作为键，字符串的下标作为他的值，每次利用哈希表的find函数去找在已有的窗口里是否有出现过的字符，一旦出现，更新窗口，并在每一步去判断最大的字符长度的情况。
class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.length();
		map<char, int> Map_tmp;
		map<char, int>::iterator iter;
		int i = 0, ans = 0;
		for (int j = 0; j < n; j++) {
			if ((iter = Map_tmp.find(s[j])) != Map_tmp.end())
			{
				i = i > iter->second ? i : iter->second;
			}
			ans = ans > j-i+1 ? ans : j-i+1;
			Map_tmp[(s[j])] = j + 1;
		}
		return ans;
	}
};



//方法三：优化版的滑动窗口：建立动态容器存储，注意左加加和右加加的区别，左加加先加再赋值；
//比方法二少了一半的时间花费
class Solution3 {

public:
	int lengthOfLongestSubstring(string s) {
		int i = 0, j = 0, n = 0, ans = 0;
		set<char> cont;
		n = s.size();
		set<char>::iterator iter;

		while (i < n && j < n) {
			if ((iter = cont.find(s[j])) != cont.end()) {
				cont.erase(s[i++]);
			}
			else {

				cont.insert(s[j++]);
				ans = ans>j-i?ans:j-i ;  //滑动窗口的判断滑动
			}

		}
		return ans;
	}
};

