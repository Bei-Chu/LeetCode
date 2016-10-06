#include "stdafx.h"
#include "Solution.h"

int Solution::maxRotateFunction(vector<int>& A)
{
	if (A.size() == 0)
		return 0;

	vector<long long> f(A.size(), 0);
	long long sum = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		sum += A[i];
		f[0] += i * A[i];
	}

	long long ret = f[0];
	for (int i = 1; i < A.size(); ++i)
	{
		f[i] = f[i - 1] + A[i - 1] * A.size() - sum;
		ret = max(ret, f[i]);
	}
	return ret;
}
