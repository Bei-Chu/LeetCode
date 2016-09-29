#include "stdafx.h"
#include "Solution.h"

string remove(string const& num, int k)
{
	if (num.length() == k)
		return "";

	if (k == 0)
		return num;

	int minIndex = 0;
	for (int i = 1; i <= k; ++i)
	{
		if (num[i] < num[minIndex])
			minIndex = i;
	}
	return num[minIndex] + remove(num.substr(minIndex + 1), k - minIndex);
}

string Solution::removeKdigits(string num, int k)
{
	num = remove(num, k);

	int i = 0;
	while (i < num.length() && num[i] == '0')
		++i;
	if (i == num.length())
		return string("0");
	return num.substr(i);
}
