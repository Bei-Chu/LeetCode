#include "stdafx.h"
#include "Solution.h"

bool CheckValid(vector<int>& queens, int nrow, int place)
{
	for (int i = 0; i < nrow; ++i)
	{
		if (queens[i] == place)
			return false;
		if (abs(queens[i] - place) == nrow - i)
			return false;
	}
	return true;
}

vector<string> GenerateSolution(vector<int>& queens)
{
	string dots(queens.size(), '.');
	vector<string> ret;
	for (size_t i = 0; i < queens.size(); ++i)
	{
		dots[queens[i]] = 'Q';
		ret.push_back(dots);
		dots[queens[i]] = '.';
	}
	return ret;
}

void dfs(vector<int>& queens, int nrow, int place, vector<vector<string>>& ret)
{
	queens[nrow] = place;
	++nrow;
	if (nrow >= queens.size())
	{
		ret.push_back(GenerateSolution(queens));
		return;
	}

	for (int i = 0; i < queens.size(); ++i)
	{
		if (CheckValid(queens, nrow, i))
			dfs(queens, nrow, i, ret);
	}
}

vector<vector<string>> Solution::solveNQueens(int n)
{
	vector<int> queens(n, -1);
	vector<vector<bool>> board(n, vector<bool>(n, true));
	vector<vector<string>> ret;
	for (int i = 0; i < n; ++i)
		dfs(queens, 0, i, ret);
	return ret;
}
