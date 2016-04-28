#include "stdafx.h"
#include "Solution.h"

int fib(int n)
{
	static vector<int> num{ 1, 1 };
	if (n < num.size())
		return num[n];
	int ret = fib(n - 1) + fib(n - 2);
	num.push_back(ret);
	return ret;
}

int Solution::numDecodings(string s)
{
	if (s.length() == 0)
		return 0;
	int ret = 1;
	size_t i = 0;
	while (i < s.length())
	{
		if (s[i] == '1' || s[i] == '2')
		{
			int count = 1;
			int j = i + 1;
			while (j < s.length())
			{
				if (s[j] == '1' || s[j] == '2')
				{
					++j;
					++count;
				}
				else if (s[j] == '0')
				{
					++j;
					--count;
					break;
				}
				else if (s[j - 1] == '2' && s[j] > '6')
				{
					++j;
					break;
				}
				else
				{
					++j;
					++count;
					break;
				}
			}
			ret *= fib(count);
			i = j;
		}
		else if (s[i] == '0' && (i == 0 || (s[i - 1] != '1' && s[i - 1] != '2')))
			return 0;
		else
			++i;
	}
	return ret;
}
