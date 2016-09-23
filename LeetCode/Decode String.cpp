#include "stdafx.h"
#include "Solution.h"

string Solution::decodeString(string s)
{
	vector<int> repStack(1, 1);
	vector<string> patternStack(1);
	patternStack.back().reserve(s.length());

	size_t i = 0;
	while (i < s.length())
	{
		if (s[i] == '[')
		{
			patternStack.push_back("");
			++i;
			continue;
		}

		if (s[i] == ']')
		{
			string p = move(patternStack.back());
			patternStack.pop_back();
			int c = repStack.back();
			repStack.pop_back();
			for (int j = 0; j < c; ++j)
				patternStack.back() += p;
			++i;
			continue;
		}

		if (s[i] >= '0' && s[i] <= '9')
		{
			size_t j = i;
			int c = s[i] - '0';
			for (j = i + 1; s[j] != '['; ++j)
				c = c * 10 + s[j] - '0';
			repStack.push_back(c);
			i = j;
			continue;
		}

		patternStack.back().push_back(s[i]);
		++i;
	}
	return move(patternStack.back());
}
