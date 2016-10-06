#include "stdafx.h"
#include "Solution.h"

int Solution::findNthDigit(int n)
{
	vector<long long> digitCount = { 0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889 };
	vector<long long> power = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
	size_t k = 1;
	for (; k < digitCount.size(); ++k)
	{
		if (digitCount[k] > n)
			break;
	}

	n -= digitCount[k - 1];
	int number = (n - 1) / k + power[k - 1];
	int digit = (n - 1) % k;
	return (number / power[k - digit - 1]) % 10;
}
