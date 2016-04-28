#include "stdafx.h"
#include "Solution.h"

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target)
{
	size_t nRow = matrix.size();
	if (nRow == 0)
		return false;
	size_t nCol = matrix[0].size();
	if (nCol == 0)
		return false;
	int i = 0, j = nCol - 1;
	while (i < nRow && j >= 0)
	{
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] < target)
			++i;
		else
			--j;
	}
	return false;
}
