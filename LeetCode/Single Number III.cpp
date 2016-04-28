#include "stdafx.h"
#include "Solution.h"

vector<int> Solution::singleNumber(vector<int>& nums)
{
	int res = 0;
	for (size_t i = 0; i < nums.size(); ++i)
		res ^= nums[i];
	int marker = 0;
	while (!(res & 1))
	{
		res >>= 1;
		++marker;
	}
	marker = 1 << marker;

	int res1 = 0, res2 = 0;
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (nums[i] & marker)
			res1 ^= nums[i];
		else
			res2 ^= nums[i];
	}
	return vector < int > {res1, res2};
}
