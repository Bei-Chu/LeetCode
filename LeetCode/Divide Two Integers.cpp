#include "stdafx.h"
#include "Solution.h"

int Solution::divide(int dividend, int divisor)
{
	if (divisor == 0 || (dividend == numeric_limits<int>::min() && divisor == -1))
		return numeric_limits<int>::max();
	if (dividend == 0)
		return 0;
	long long dividend1 = dividend;
	long long divisor1 = divisor;
	int sign = 1;
	if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
		sign = -1;
	return sign * int(exp(log(abs(dividend1)) - log(abs(divisor1))));
}
