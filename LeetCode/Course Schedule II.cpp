#include "stdafx.h"
#include "Solution.h"

vector<int> Solution::findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
	if (numCourses == 0)
		return vector<int>();
	vector<int> indegree(numCourses, 0);
	vector<vector<int>> outedges(numCourses);
	for (size_t i = 0; i < prerequisites.size(); ++i)
	{
		++indegree[prerequisites[i].first];
		outedges[prerequisites[i].second].push_back(prerequisites[i].first);
	}
	vector<int> in0;
	for (int i = 0; i < numCourses; ++i)
		if (indegree[i] == 0)
			in0.push_back(i);
	vector<int> ret;
	while (!in0.empty())
	{
		int course = in0.back();
		in0.pop_back();
		ret.push_back(course);
		for (size_t i = 0; i < outedges[course].size(); ++i)
		{
			int outcourse = outedges[course][i];
			--indegree[outcourse];
			if (indegree[outcourse] == 0)
				in0.push_back(outcourse);
		}
	}
	if (ret.size() != numCourses)
		return vector<int>();
	return ret;
}
