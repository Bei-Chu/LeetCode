#include "stdafx.h"
#include "Solution.h"

string Solution::toHex(int num)
{
	char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	unsigned int n;
	memcpy(&n, &num, sizeof(unsigned int));

	string ret;
	while (n)
	{
		ret.insert(ret.begin(), hex[n & 15]);
		n >>= 4;
	}
	if (ret.length() == 0)
		ret = "0";
	return ret;
}
