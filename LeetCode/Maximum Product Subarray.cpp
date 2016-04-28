#include "stdafx.h"
#include "Solution.h"

int Solution::maxProduct(vector<int>& nums)
{
	int ret = nums[0];
	size_t i = 0;
	while (i < nums.size())
	{
		int leftMostNegative = 0, rightMostNegative = 0;
		int absProduct = 1, absProductToLeft = 1, absProductToRight = 1;
		int negativeCount = 0;
		int startIndex = i, endIndex = -1, leftMostIndex = -1, rightMostIndex = -1;
		while (i < nums.size() && nums[i] != 0)
		{
			int num = nums[i];
			absProduct *= abs(num);
			if (num < 0)
			{
				++negativeCount;
				if (leftMostNegative == 0)
				{
					leftMostNegative = num;
					absProductToLeft = absProduct;
					leftMostIndex = i;
				}
				else
				{
					rightMostNegative = num;
					absProductToRight = absProduct;
					rightMostIndex = i;
				}
			}
			++i;
		}
		endIndex = i - 1;
		if (endIndex >= startIndex)
		{
			if (!(negativeCount & 1))
			{
				ret = max(ret, absProduct);
			}
			else
			{
				if (leftMostIndex > startIndex)
					ret = max(ret, -absProductToLeft / leftMostNegative);
				if (leftMostIndex >= 0 && leftMostIndex < endIndex)
					ret = max(ret, absProduct / absProductToLeft);
				if (rightMostIndex >= 0 && rightMostIndex < endIndex)
					ret = max(ret, absProduct / absProductToRight);
				if (rightMostIndex > startIndex)
					ret = max(ret, -absProductToRight / rightMostNegative);
			}
		}
		if (i < nums.size() && ret < 0)
			ret = 0;
		++i;
	}
	return ret;
}
