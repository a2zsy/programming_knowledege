//求三数之和，利用三指针，很舒服的解法、
/*给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
。*/


class Solution1 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		if (nums.size() < 3 || nums.front() > 0 || nums.back() < 0)
		{
			return result;
		}
		for (auto i = 0; i <= nums.size() - 3; i++)
		{
			int temp = nums[i];
			if (temp > 0) break;
			if (i > 0 && temp == nums[i - 1]) { continue; }
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r) {				
				if (nums[l] + nums[r] == -temp)				
				{
					if (l == i + 1 || r == nums.size() - 1)					//刚进入循环一定要有个判断左右指针的情况，进入相等的循环条件后左右指针都是通过与前一个或者后一个数相比，要避免地址溢出的情况
					{
						result.push_back(vector<int>{nums[i], nums[l], nums[r]});
						l++;
						r--;
					}
					else if (nums[l] == nums[l - 1])
						l++;
					else if (nums[r] == nums[r + 1])
						r--;
					else
					{
						result.push_back(vector<int>{nums[i], nums[l], nums[r]});
						l++;
						r--;

					}
				}
				else if (nums[l] + nums[r] < -temp)
				{
					l++;
				}
				else { r--; }
			}
		}

		return result;

	}
};



