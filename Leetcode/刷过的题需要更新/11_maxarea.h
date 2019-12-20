//算出一个数组中的容器所能盛的最大的水容量，暴力破解或者双指针
/*给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

输入: [1,8,6,2,5,4,8,3,7]
输出: 49  */
//暴力破解，极度容易超时
class Solution1 {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		for (int i = 0; i < height.size(); i++)
		{
			for (int j = i + 1; j < height.size(); j++)
			{
				int temp1 = min(height[i], height[j]);
				int temp2 = temp1 * (j - i);
				res = max(res, temp2);
			}
		}
		return res;
	}
};


//因为数组之间间距的均匀性，所以可采用双指针，慢慢比较
class Solution2{
public:
	int maxArea(vector<int>& height) {
		int i = 0;
		int j = height.size() - 1;        //双指针，因为每个垂直线间距相同，所以指针移动起来很舒服
		int max = 0, temp = 0;
		while (i != j)
		{
			temp = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
			if (height[i] >= height[j]) { j--; }
			else { i++; }
			max = max > temp ? max : temp;

		}
		return max;
	}
};


