//一开始的感想:寻找中位数，学会去分辨边界条件，并且建立可调用的其他函数,并且尽量从简单的数组开始端开始编写条件，主要要注意到数组一和数组二到头的极限情况
//二刷时的感想：使用迭代的方法，往往费时又费力（在此题中）
/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

示例 1:nums1 = [1, 3]nums2 = [2]则中位数是 2.0
示例 2:nums1 = [1, 2]nums2 = [3, 4]则中位数是 (2 + 3)/2 = 2.5
*/
//方法0(优雅的边界条件，拒绝累赘的边界和冗杂的书写)
/*（1）分为偶数和奇数两种情况，将寻找中位数转化为寻找第k个大的数
（2）数组A和数组B，对于寻找第k个大的数，两个数组分割后(设两个数组的分割线分别为i，j)，有A[i-1]<=B[j]和B[j-1]<=A[i],且i+j = k
且第k个大的数位于max（A[i-1],B[j-1]）
（3）0<=i<=n,且由0<=k-i(j)<=m;结合可得max(0,k-m)<=i<=min(n,k)
（4)那么直接对A开始进行二分查找，查找的点为m，B数组对应的边界为k-m，如果B[k-m-1]>A[m]，说明左边的偏多，left需要加1，右移(同时，b的边界值将会减少)；
否则，就已经满足了B[j-1]<=A[i]的条件，则就让右边界等于中间值，直到左右边界重合(因为每步是对m判断，不用担心超出情况之外)。
(5)最后对边界条件进行讨论（不要将每个边界完全孤立于主函数之外）
*/
//！！！！！！！(len)>>1..会对len进行判断，括号别乱写
class Solution0 {
public:
    double findKthOfArray(vector<int>&nums1,vector<int>&nums2,int k)
    {
        assert(k>=1&&(k <= nums1.size()+nums2.size()));
        int le = max(0,int(k-nums2.size())),ri = min(k,int(nums1.size()));
        while(le<ri)
        {
            int m = (ri-le)/2 +le;
            if(nums2[k-m-1]>nums1[m]) 
            {
                le=m+1;
            }    
            else {ri=m;}
        }
        int nums1LeftMax = (le==0?INT_MIN:nums1[le-1]);
        int nums2LefttMax = (le==k?INT_MIN: nums2[k-le-1]);
        return max(nums1LeftMax,nums2LefttMax); 

    }
    double findMedianSortedArrays(vector<int>&nums1,vector<int>&nums2)
    {
        int len = nums1.size()+nums2.size();
        if(len&1)
        {
            return findKthOfArray(nums1,nums2,(len>>1)+1);
        }
        else
        {
            return (findKthOfArray(nums1,nums2,(len>>1))+findKthOfArray(nums1,nums2,(len>>1)+1))/2.0;
        }
    }
};
//方法一，暴力破解，m+n的时间复杂度，傻瓜式而已，重新排序
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

