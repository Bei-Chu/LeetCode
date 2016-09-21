#include "stdafx.h"
#include "Solution.h"

bool Solution::isSubsequence(string s, string t)
{
	size_t is = 0, it = 0;
	while (is < s.length() && it < t.length())
	{
		while (it < t.length() && t[it] != s[is])
			++it;
		++it;
		++is;
	}
	return is == s.length();
}
