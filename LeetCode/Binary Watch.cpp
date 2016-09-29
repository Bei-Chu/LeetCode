#include "stdafx.h"
#include "Solution.h"

vector<string> Solution::readBinaryWatch(int num)
{
	vector<vector<string>> hours(5);
	for (unsigned int hour = 0; hour < 12; ++hour)
	{
		int c = 0;
		int h = hour;
		while (h)
		{
			if (h & 1)
				++c;
			h >>= 1;
		}
		hours[c].push_back(to_string(hour));
	}

	vector<vector<string>> minutes(7);
	for (unsigned int minute = 0; minute < 60; ++minute)
	{
		int c = 0;
		int m = minute;
		while (m)
		{
			if (m & 1)
				++c;
			m >>= 1;
		}
		string str = to_string(minute);
		if (str.length() == 1)
			str = "0" + str;
		minutes[c].push_back(move(str));
	}

	vector<string> ret;
	for (size_t i = 0; i <= num; ++i)
	{
		if (i >= hours.size() || num - i >= minutes.size())
			continue;

		for (size_t j = 0; j < hours[i].size(); ++j)
			for (size_t k = 0; k < minutes[num - i].size(); ++k)
				ret.push_back(hours[i][j] + ":" + minutes[num - i][k]);
	}
	return ret;
}