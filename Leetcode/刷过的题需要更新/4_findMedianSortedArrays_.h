//寻找中位数，学会去分辨边界条件，并且建立可调用的其他函数,并且尽量从简单的数组开始端开始编写条件，主要要注意到数组一和数组二到头的极限情况
#include<vector>
using namespace std;
/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

示例 1:nums1 = [1, 3]nums2 = [2]则中位数是 2.0
示例 2:nums1 = [1, 2]nums2 = [3, 4]则中位数是 (2 + 3)/2 = 2.5
*/

//方法一，暴力破解，m+n的时间复杂度
class Solution1 {
public:
	double GetOddMedian(vector<int>& nums1, vector<int>& nums2, int median_index) {
		int m = nums1.size();
		int n = nums2.size();
		int index = 1;
		int result = 0;
		int i = 0;
		int j = 0;
		while (i < m && j < n && index <= median_index) {
			if (nums1[i] < nums2[j]) {
				result = nums1[i];
				++i;
				++index;
			}
			else if (nums1[i] >= nums2[j]) {
				result = nums2[j];
				++j;
				++index;
			}
			else {
				break;
			}
		}
		if (i < m && j < n)  return result;
		else if (i == m) {
			while (index <= median_index) {
				result = nums2[j];
				++j;
				++index;
			}
			return result;
		}
		else {
			while (index <= median_index) {
				result = nums1[i];
				++i;
				++index;
			}
			return result;
		}
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		const int median_index = (nums1.size() + nums2.size()) / 2 + 1;
		if ((nums1.size() + nums2.size()) & 0x1) {
			return GetOddMedian(nums1, nums2, median_index);
		}
		else {
			return(GetOddMedian(nums1, nums2, median_index) + GetOddMedian(nums1, nums2, median_index - 1)) / 2.0;
		}
	}
}; 






//方法二：利用分割和两个数组中位数的特性，分情况讨论，（再利用二分查找的特性，比较难以理解其实）
#include <stdio.h>
#include <vector>
using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //保证数组1一定最短
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = m + n - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
	}
};


int main(int argc, char* argv[])
{
	vector<int> nums1 = { 2,3, 5 };
	vector<int> nums2 = { 1,4,7, 9 };

	Solution solution;
	double ret = solution.findMedianSortedArrays(nums1, nums2);
	return 0;
}

