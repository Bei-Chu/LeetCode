#include "stdafx.h"
#include "Solution.h"

int Solution::titleToNumber(string s)
{
	int ret = 0;
	int cur = 1;
	for (auto i = s.rbegin(); i != s.rend(); ++i)
	{
		ret += (*i - 'A' + 1) * cur;
		cur *= 26;
	}
	return ret;
}
