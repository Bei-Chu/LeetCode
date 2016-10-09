#include "stdafx.h"
#include "Solution.h"

vector<pair<int, int>> Solution::pacificAtlantic(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	if (m == 0)
		return vector<pair<int, int>>();
	int n = matrix[0].size();
	if (n == 0)
		return vector<pair<int, int>>();

	auto LowerOrEqual = [&matrix](pair<int, int> const& idx1, pair<int, int> const& idx2)
	{
		return matrix[idx1.first][idx1.second] <= matrix[idx2.first][idx2.second];
	};
	vector<pair<int, int>> stack;
	auto Grow = [&matrix, &LowerOrEqual, &stack](vector<vector<bool>>& status, pair<int, int> idx, pair<int, int> idx1)
	{
		if (!status[idx1.first][idx1.second] && LowerOrEqual(idx, idx1))
		{
			status[idx1.first][idx1.second] = true;
			stack.push_back(idx1);
		}
	};

	vector<vector<bool>> pacific(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
	{
		pacific[i][0] = true;
		stack.push_back({ i,0 });
	}
	for (int i = 0; i < n; ++i)
	{
		pacific[0][i] = true;
		stack.push_back({ 0,i });
	}
	while (!stack.empty())
	{
		auto idx = stack.back();
		stack.pop_back();
		if (idx.first > 0)
			Grow(pacific, idx, { idx.first - 1, idx.second });
		if (idx.first < m - 1)
			Grow(pacific, idx, { idx.first + 1, idx.second });
		if (idx.second > 0)
			Grow(pacific, idx, { idx.first, idx.second - 1 });
		if (idx.second < n - 1)
			Grow(pacific, idx, { idx.first, idx.second + 1 });
	}

	stack.clear();
	vector<vector<bool>> atlantic(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
	{
		atlantic[i][n - 1] = true;
		stack.push_back({ i,n - 1 });
	}
	for (int i = 0; i < n; ++i)
	{
		atlantic[m - 1][i] = true;
		stack.push_back({ m - 1,i });
	}
	while (!stack.empty())
	{
		auto idx = stack.back();
		stack.pop_back();
		if (idx.first > 0)
			Grow(atlantic, idx, { idx.first - 1, idx.second });
		if (idx.first < m - 1)
			Grow(atlantic, idx, { idx.first + 1, idx.second });
		if (idx.second > 0)
			Grow(atlantic, idx, { idx.first, idx.second - 1 });
		if (idx.second < n - 1)
			Grow(atlantic, idx, { idx.first, idx.second + 1 });
	}

	vector<pair<int, int>> ret;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (pacific[i][j] && atlantic[i][j])
				ret.push_back({ i,j });
	return ret;
}
