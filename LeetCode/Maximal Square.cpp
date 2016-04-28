#include "stdafx.h"
#include "Solution.h"

int Solution::maximalSquare(vector<vector<char>>& matrix)
{
	int nRow = matrix.size();
	if (nRow == 0)
		return 0;
	int nCol = matrix[0].size();
	vector<vector<int>> colCount(nRow, vector<int>(nCol, 0));
	for (int i = 0; i < nRow; ++i)
	{
		int cur = 0;
		for (int j = 0; j < nCol; ++j)
		{
			if (matrix[i][j] == '1')
			{
				++cur;
				colCount[i][j] = cur;
			}
			else
				cur = 0;
		}
	}

	int square = 0;
	for (int i = 0; i < nCol; ++i)
	{
		int j = 0;
		while (j < nRow)
		{
			if (colCount[j][i] <= square)
				++j;
			else
			{
				int count = 1;
				int k = j + 1;
				while (k < nRow && colCount[k][i] > square)
				{
					++count;
					++k;
				}
				if (count > square)
					++square;
				j = k;
			}
		}
	}
	return square * square;
}
