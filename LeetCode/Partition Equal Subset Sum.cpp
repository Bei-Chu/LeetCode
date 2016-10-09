#include "stdafx.h"
#include "Solution.h"

bool sumTo(vector<int>& nums, int begin, int end, int sum)
{
	if (sum < 0)
		return false;
	if (end == begin)
		return sum == 0;
	return sumTo(nums, begin, end - 1, sum - nums[end - 1]) || sumTo(nums, begin, end - 1, sum);
}

bool Solution::canPartition(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
		sum += nums[i];
	if (sum & 1)
		return false;
	sum /= 2;

	return sumTo(nums, 0, nums.size() - 1, sum - nums.back());
}
