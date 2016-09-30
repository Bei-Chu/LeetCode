#include "stdafx.h"
#include "Solution.h"

vector<pair<int, int>> Solution::reconstructQueue(vector<pair<int, int>>& people)
{
	vector<pair<int, int>> ret;
	ret.reserve(people.size());

	vector<pair<pair<int, int>, size_t>> temp(people.size());
	for (size_t i = 0; i < people.size(); ++i)
	{
		temp[i].first = people[i];
		temp[i].second = i;
	}

	while (!temp.empty())
	{
		int minHeight = numeric_limits<int>::max();
		size_t minIndex = 0;
		for (size_t i = 0; i < temp.size(); ++i)
		{
			if (temp[i].first.second == 0 && temp[i].first.first < minHeight)
			{
				minHeight = temp[i].first.first;
				minIndex = i;
			}
		}

		ret.push_back(people[temp[minIndex].second]);
		temp.erase(temp.begin() + minIndex);
		for (size_t i = 0; i < temp.size(); ++i)
			if (temp[i].first.first <= minHeight)
				--temp[i].first.second;
	}
	return ret;
}
