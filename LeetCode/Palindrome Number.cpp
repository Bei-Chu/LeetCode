#include "stdafx.h"
#include "Solution.h"

bool Solution::isPalindrome(int x)
{
	if (x < 0)
		return false;
	if (x == 0)
		return true;
	int digits = 0;
	int t = x;
	while (t > 0)
	{
		++digits;
		t = t / 10;
	}
	int order = 1;
	for (int i = 0; i < digits - 1; ++i)
		order *= 10;
	while (x > 0)
	{
		int lastdigit = x % 10;
		int firstdigit = x / order;
		if (lastdigit != firstdigit)
			return false;
		x = (x - firstdigit * order) / 10;
		order /= 100;
	}
	return true;
}
