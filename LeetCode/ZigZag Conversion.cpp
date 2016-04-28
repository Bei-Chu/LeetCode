#include "stdafx.h"
#include "Solution.h"

std::string Solution::convert(string s, int numRows)
{
	int len = s.length();
	if (numRows == 1 || numRows >= len)
		return s;
	string ret;
	for (int i = 0; i < numRows; ++i)
	{
		int j = i;
		if (i == 0 || i == numRows - 1)
		{
			while (j < len)
			{
				ret.push_back(s[j]);
				j += numRows + numRows - 2;
			}
		}
		else
		{
			while (j < len)
			{
				ret.push_back(s[j]);
				j += numRows - i + numRows - i - 2;
				if (j < len)
				{
					ret.push_back(s[j]);
					j += i + i;
				}
			}
		}
	}
	return ret;
}
