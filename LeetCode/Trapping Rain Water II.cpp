#include "stdafx.h"
#include "Solution.h"

struct Cube
{
	Cube(int i, int j, int h) :i(i), j(j), h(h) {}
	int i, j, h;
};

bool Heigher(Cube const& cube1, Cube const& cube2)
{
	return cube1.h > cube2.h;
}

int Solution::trapRainWater(vector<vector<int>>& heightMap)
{
	if (heightMap.size() <= 2 || heightMap[0].size() <= 2)
		return 0;
	int nRow = heightMap.size(), nCol = heightMap[0].size();

	vector<vector<bool>> processed(nRow, vector<bool>(nCol, false));
	priority_queue<Cube, vector<Cube>, decltype(&Heigher)> heap(&Heigher);
	for (int i = 0; i < nRow; ++i)
	{
		heap.push(Cube(i, 0, heightMap[i][0]));
		processed[i][0] = true;
		heap.push(Cube(i, nCol - 1, heightMap[i][nCol - 1]));
		processed[i][nCol - 1] = true;
	}
	for (int i = 1; i < nCol - 1; ++i)
	{
		heap.push(Cube(0, i, heightMap[0][i]));
		processed[0][i] = true;
		heap.push(Cube(nRow - 1, i, heightMap[nRow - 1][i]));
		processed[nRow - 1][i] = true;
	}

	int ret = 0;
	auto ProcessIndex = [&heightMap, &heap, &processed, &ret](int h, int i, int j)
	{
		if (!processed[i][j])
		{
			processed[i][j] = true;
			ret += max(0, h - heightMap[i][j]);
			heap.push(Cube(i, j, max(h, heightMap[i][j])));
		}
	};

	while (!heap.empty())
	{
		auto cube = heap.top();
		heap.pop();

		if (cube.i > 0)
			ProcessIndex(cube.h, cube.i - 1, cube.j);
		if (cube.i < nRow - 1)
			ProcessIndex(cube.h, cube.i + 1, cube.j);
		if (cube.j > 0)
			ProcessIndex(cube.h, cube.i, cube.j - 1);
		if (cube.j < nCol - 1)
			ProcessIndex(cube.h, cube.i, cube.j + 1);
	}
	return ret;
}
