//利用荣其可以实现的基础操作题目，而且double类型过于取巧了，可以学一学答案上对于结果和边界值的大致估算

#include<vector>
using namespace std;

/*给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例 1 :
输入: 123
	输出 : 321
	示例 2 :
	输入 : -123
	输出 : -321
	示例 3 :

	输入 : 120
	输出 : 21
	*/


//自己的代码
class Solution1 {
public:
	int reverse(int x) {
		vector<int>  num;
		int num_store = 0;
		int flag = 0;
		double result_temp = 0;
		int result = 0;
		if (x >= 0) { flag = 1; }
		else { flag = -1; }          //正整数标志位为1，负整数标志位为-1
		if (x == -2147483648) { return 0; }
		x = abs(x);
		while ((x / 10) != 0 || (x % 10) != 0)             //当且仅当余数和商均为0时，才跳出循环
		{

			num_store = x % 10;
			num.push_back(num_store);
			x = x / 10;
		}
		int len = num.size();
		for (auto i = 0; i < len; i++)
		{
			result_temp += num[i] * (pow(10, len - i - 1));

		}
		result_temp = result_temp * flag;
		if (result_temp >= (-1) * (pow(2, 31)) && result_temp <= (pow(2, 31) - 1))
		{
			result = (int)result_temp;

			return result;
		}
		else
		{
			return 0;
		}
	}
};

//答案的代码，一定程度上自己比较缺乏整洁性和刻度性
class Solution2 {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};

