#include "stdafx.h"
#include "Solution.h"

bool Solution::canCross(vector<int>& stones)
{
	if (stones[1] != 1)
		return false;
	if (stones.size() == 2)
		return true;

	vector<vector<bool>> dp(stones.size(), vector<bool>(stones.size(), false));

	dp[1][1] = true;
	for (size_t i = 2; i < stones.size(); ++i)
	{
		for (size_t j = i - 1; j >= 1; --j)
		{
			int step = stones[i] - stones[j];
			if (step > j + 1)
				break;
			dp[step][i] = dp[step - 1][j] || dp[step][j] || dp[step + 1][j];
			if (i == stones.size() - 1 && dp[step][i])
				return true;
		}
	}

	return false;
}
