#include "stdafx.h"
#include "Solution.h"

int Solution::integerReplacement(int n)
{
	int count = 0;
	while (n > 3)
	{
		int c = 0;
		while (n & 1)
		{
			++c;
			n >>= 1;
		}
		if (c == 0)
		{
			++count;
			n >>= 1;
		}
		else if (c == 1)
		{
			count += 3;
			n >>= 1;
		}
		else
		{
			count += (c + 1);
			n |= 1;
		}
	}
	return count + n - 1;
}
