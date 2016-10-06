#include "stdafx.h"
#include "Solution.h"

bool Solution::validUtf8(vector<int>& data)
{
	for (size_t i = 0; i < data.size(); ++i)
	{
		if (!((data[i] >> 7) & 0x1))
			continue;

		int nBytes = -1;
		if (!((data[i] >> 5) ^ 0x6))
			nBytes = 2;
		else if (!((data[i] >> 4) ^ 0xe))
			nBytes = 3;
		else if (!((data[i] >> 3) ^ 0x1e))
			nBytes = 4;
		if (nBytes < 0)
			return false;

		for (size_t j = i + 1; j < i + nBytes; ++j)
		{
			if (j >= data.size())
				return false;
			if ((data[j] >> 6) ^ 0x2)
				return false;
		}
		i = i + nBytes - 1;
	}
	return true;
}
