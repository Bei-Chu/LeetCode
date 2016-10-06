#include "stdafx.h"
#include "Solution.h"

namespace
{
	int digitToNumber(vector<unsigned short> const& digits, int curDigit)
	{
		int ret = 0;
		for (int i = 0; i <= curDigit; ++i)
			ret = ret * 10 + digits[i];
		return ret;
	}
}

vector<int> Solution::lexicalOrder(int n)
{
	if (n == 0)
		return vector<int>();

	vector<int> ret;
	ret.reserve(n);
	ret.push_back(1);

	int curNumber = 1;
	while (true)
	{
		if (curNumber <= n / 10)
		{
			curNumber *= 10;
			ret.push_back(curNumber);
			continue;
		}

		if (curNumber < n && curNumber % 10 != 9)
		{
			++curNumber;
			ret.push_back(curNumber);
			continue;
		}

		do
		{
			curNumber /= 10;
		} while (curNumber % 10 == 9);
		if (curNumber == 0)
			break;

		++curNumber;
		ret.push_back(curNumber);
	}

	return ret;
}
