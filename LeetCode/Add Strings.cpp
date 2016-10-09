#include "stdafx.h"
#include "Solution.h"

string Solution::addStrings(string num1, string num2)
{
	string ret(max(num1.length(), num2.length()) + 1, '0');
	int i = num1.length() - 1, j = num2.length() - 1, k = ret.length() - 1;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			ret[k] += num1[i] - '0';
		if (j >= 0)
			ret[k] += num2[j] - '0';
		if (ret[k] > '9')
		{
			++ret[k - 1];
			ret[k] -= 10;
		}
		--i;
		--j;
		--k;
	}
	if (ret[0] == '0')
		ret.erase(ret.begin(), ret.begin() + 1);
	return ret;
}
