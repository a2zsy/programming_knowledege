//暴力破解和哈希表
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
//方法1：暴力破解，两遍遍历
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i, j;
		for (i = 0; i <= nums.size() - 1; i++)
		{
			for (j = i + 1; j <= nums.size() - 1; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					return { i,j };

				}
			}

		}
		return { i,j };
	}
};



//方法二：建立哈希表，数组的值作为哈希表的键，数组的下标作为哈希表的值，通过哈希表的内置count函数去一一寻找
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int>a;
		vector<int>b = { -1,-1 };
		for (auto i = 0; i <= nums.size() - 1; i++)
			a.insert(map<int, int>::value_type(nums[i], i));
		for (auto i = 0; i <= nums.size() - 1; i++)
		{
			if (a.count(target - nums[i]) > 0 && (a[target - nums[i]] != i))
			{
				b[0] = i;
				b[1] = a[target - nums[i]];
				return b;

			}
		}
		return b;
	}

};
