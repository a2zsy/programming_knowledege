#include<string>
#include<vector>
using namespace std;
//����������������Ӵ�������ת�ַ����Ƚ��Ƿ���ͬ����ȥԭ���鵱��Ѱ���±�ķ�������ʱ�临�Ӷ���Ȼ�Ƚϸ�
class Solution2 {
public:
	string longestPalindrome(string s) {
		if (s.length() == 1) return s;//��СΪ1���ַ�����Ϊ���Ĵ�
		string rev = s;//rev���s��ת���
		string res;//��Ž��
		std::reverse(rev.begin(), rev.end());
		if (rev == s) return s;
		int len = 0;//��Ż����Ӵ��ĳ���
		for (int i = 0; i < s.length(); i++)//����s��rev��������Ӵ�
		{
			string temp;//��Ŵ���֤�Ӵ�
			for (int j = i; j < s.length(); j++)
			{
				temp += s[j];
				if (len >= temp.length())
					continue;
				else if (rev.find(temp) != -1)//��rev���ҵ�temp
				{
					string q = temp;//q������֤temp�Ƿ��ǻ����Ӵ�
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

//����һ����ά��n*n�����飬���ö�̬�滮�� ����f��n��=f(n-1)+f(n-2)��״̬ת�Ʒ��̵�˼�룬ȥ������⣩
class Solution3 {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len == 0 || len == 1)
		{
			return s;                    //���s���ַ�������0����1�����ر���
		}
		int start = 0;
		int max = 0;  //��������Ⱥ���ʼλ��
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


//������ȥ��չ���˴�Ӧ������ż��������Ȼ��n^2���㷨��
class Solution4 {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//��¼�����Ӵ���ʼλ��
		int end = 0;//��¼�����Ӵ���ֹλ��
		int mlen = 0;//��¼�������Ӵ��ĳ���
		for (int i = 0; i < len; i++)
		{
			int len1 = expendaroundcenter(s, i, i);//һ��Ԫ��Ϊ����
			int len2 = expendaroundcenter(s, i, i + 1);//����Ԫ��Ϊ����
			mlen =(len1>len2?len1:len2)>mlen?(len1 > len2 ? len1 : len2):mlen ;
			if (mlen > end - start + 1)
			{
				start = i - (mlen - 1) / 2;
				end = i + mlen / 2;
			}
		}
		return s.substr(start, mlen);
		//�ú�������˼�ǻ�ȡ��start��ʼ����Ϊmlen���ȵ��ַ���
	}
private:
	int expendaroundcenter(string s, int left, int right)
		//������left��rightΪ���ĵĻ��Ĵ�����
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
