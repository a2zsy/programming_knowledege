//注意时间复杂度，动态规划与中心扩展都可以降低时间复杂度
//马拉车算法的对于数组的预处理在每个数字之间加入一个#，再去求解最大子串，再去除以二的方法可以学习；马拉车需要数学上详尽的讨论，但是只需要n的时间复杂度，从数组手段进行遍历
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：
输入: "cbbd"
输出: "bb"
。*/



//一无是处，但是能做出来的暴力破解方法
class Solution {
public:
	string longestPalindrome(string s) {
		int i = 0, j = 0, w = 0;
		string str = "";
		string result = "";
		int index1 = 0, index2 = 0;
		int len = s.length();
		int maxlen = 1;
		int resindex1 = 0, resindex2 = 0;
		bool count = true;
		if (s.length() == 1 || s.length() == 2)
		{
			if (s.length() == 1)
			{
				return s;
			}
			else
			{
				if (s[0] == s[1])
				{
					return s;
				}
				else
				{
					result = result + s[0];
					return result;

				}

			}
		}
		else
		{
			for (i = 2; i <= len; i++)        //从长度为二的开始遍历
			{
				for (j = 0; j <= len - i; j++)
				{
					count = true;
					index1 = j;
					index2 = j + (i - 1);         //遍历字符的下标范围并赋值
					str = s.substr(index1, i);
					for (w = 0; w <= i - 1; w++)
					{
						if (str[w] != str[(i - 1 - w)])
						{
							count = false;
						}

					}
					if (count == true)
					{
						if (str.length() > maxlen)
						{
							resindex1 = index1;
							resindex2 = index2;
						}
						maxlen = str.length();
						result = s.substr(resindex1, maxlen);

					}
					str = "";

				}

			}
			if (maxlen != 1) { return result; }
			else {
				result = s.substr(0, 1);
				return result;
			}


		}

	}
};

int main() {
	string s1 = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
	Solution answer;
	cout << answer.longestPalindrome(s1) << endl;
	system("pause");



	return 0;
}


