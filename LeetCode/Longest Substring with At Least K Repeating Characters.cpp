#include "stdafx.h"
#include "Solution.h"

namespace
{
	void longestSubString_r(string const& s, int start, int end, int k, int& ret)
	{
		if (end - start < k || end - start < ret)
			return;

		vector<int> count('z' + 1);
		for (int i = start; i < end; ++i)
			++count[s[i]];

		int split = start - 1;
		for (int i = start; i < end; ++i)
		{
			if (count[s[i]] < k)
			{
				longestSubString_r(s, split + 1, i, k, ret);
				split = i;
			}
		}
		if (split == start - 1)
			ret = end - start;
		else
			longestSubString_r(s, split + 1, end, k, ret);
	}
}

int Solution::longestSubstring(string s, int k)
{
	int ret = 0;
	longestSubString_r(s, 0, s.length(), k, ret);
	return ret;
}
