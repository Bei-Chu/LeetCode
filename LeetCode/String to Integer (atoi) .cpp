#include "stdafx.h"
#include "Solution.h"

int Solution::myAtoi(string str)
{
	size_t i = 0;
	int ret = 0;
	int sign = 1;
	int overflow = numeric_limits<int>::max() / 10;
	int lastdigit = numeric_limits<int>::max() % 10;
	while (i < str.length() && str[i] == ' ')
		++i;
	if (i == str.length())
		return 0;
	if (str[i] == '+')
		++i;
	else if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	bool bOverflow = false;
	bool bEuqalOverflow = false;
	while (i < str.length())
	{
		char c = str[i];
		if (c<'0' || c>'9')
			break;
		if (bOverflow)
			return sign == 1 ? numeric_limits<int>::max() : numeric_limits<int>::min();
		if (sign == 1 && bEuqalOverflow && c - '0' > lastdigit)
			return numeric_limits<int>::max();
		if (sign == -1 && bEuqalOverflow && c - '0' > lastdigit + 1)
			return numeric_limits<int>::min();
		ret = ret * 10 + c - '0';
		if (ret > overflow)
			bOverflow = true;
		else if (ret == overflow)
			bEuqalOverflow = true;
		++i;
	}
	return sign * ret;
}
