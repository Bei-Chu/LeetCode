#include "stdafx.h"
#include "Solution.h"

int Solution::lengthOfLongestSubstring(string s)
{
	if (s.length() == 0)
		return 0;
	auto dp = new int[s.length()];
	int hash[256];
	for (int i = 0; i < 256; ++i)
		hash[i] = -1;
	dp[0] = 0;
	hash[s[0]] = 0;
	int ret = 1;
	for (size_t i = 1; i < s.length(); ++i)
	{
		if (hash[s[i]] < 0)
		{
			hash[s[i]] = i;
			dp[i] = dp[i - 1];
		}
		else
		{
			dp[i] = hash[s[i]] + 1;
			for (int j = dp[i - 1]; j <= hash[s[i]]; ++j)
				hash[s[j]] = -1;
			hash[s[i]] = i;
		}
		int len = i - dp[i] + 1;
		if (len > ret)
			ret = len;
	}
	return ret;
}
