#include "stdafx.h"
#include "Solution.h"

int GreatestCommonDivisor(int m, int n)
{
	while (n != 0)
	{
		int res = m % n;
		m = n;
		n = res;
	}
	return m;
}

void Solution::rotate(vector<int>& nums, int k)
{
	int n = nums.size();
	int cycle = GreatestCommonDivisor(n, k);
	for (int i = 0; i < cycle; ++i)
	{
		int curPos = (i + k) % n;
		int curNum = nums[i];
		while (curPos != i)
		{
			int temp = nums[curPos];
			nums[curPos] = curNum;
			curNum = temp;
			curPos = (curPos + k) % n;
		}
		nums[i] = curNum;
	}
}
