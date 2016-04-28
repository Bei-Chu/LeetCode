#include "stdafx.h"
#include "Solution.h"

bool Solution::canJump(vector<int>& nums)
{
	size_t farest = nums[0];
	for (size_t i = 0; i <= farest; ++i)
	{
		farest = max(farest, nums[i] + i);
		if (farest >= nums.size() - 1)
			return true;
	}
	return false;
}
