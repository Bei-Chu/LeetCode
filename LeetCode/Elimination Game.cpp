#include "stdafx.h"
#include "Solution.h"

int Solution::lastRemaining(int n)
{
	vector<bool> odd;

	bool forward = true;
	while (n > 1)
	{
		odd.push_back(!(forward || n % 2));
		n /= 2;
		forward = !forward;
	}

	for (auto it = odd.rbegin(); it != odd.rend(); ++it)
		if (*it)
			n = n * 2 - 1;
		else
			n *= 2;
	return n;
}
