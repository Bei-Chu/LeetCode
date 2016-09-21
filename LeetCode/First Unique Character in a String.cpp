#include "stdafx.h"
#include "Solution.h"

int Solution::firstUniqChar(string s)
{
	vector<char> allChar;
	vector<size_t> allIndex;
	int count['z' + 1] = { 0 };
	
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (count[s[i]] == 0)
		{
			allChar.push_back(s[i]);
			allIndex.push_back(i);
		}
		++count[s[i]];
	}

	for (size_t i = 0; i < allChar.size(); ++i)
		if (count[allChar[i]] == 1)
			return allIndex[i];
	return -1;
}
