#include "stdafx.h"
#include "Solution.h"

int Solution::reverse(int x)
{
	if (x == numeric_limits<int>::min())
		return 0;
	if (x < 0)
	{
		return -reverse(-x);
	}

	vector<int> digits;
	while (x > 0)
	{
		digits.push_back(x % 10);
		x /= 10;
	}

	int ret = 0;
	static int overflow = numeric_limits<int>::max() / 10;
	for (auto i = digits.begin(); i != digits.end(); ++i)
	{
		if (ret > overflow)
			return 0;
		ret = ret * 10 + *i;
	}
	return ret;
}
