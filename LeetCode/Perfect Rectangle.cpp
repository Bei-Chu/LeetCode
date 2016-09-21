#include "stdafx.h"
#include "Solution.h"

bool Solution::isRectangleCover(vector<vector<int>>& rectangles)
{
	unordered_set<string> corners;
	static auto ChangeFlag = [](unordered_set<string>& flags, int e1, int e2)
	{
		string key = to_string(e1) + to_string(e2);
		auto it = flags.find(key);
		if (it == flags.end())
			flags.insert(key);
		else
			flags.erase(it);
	};
	static auto Find = [](unordered_set<string> const& flags, int e1, int e2)
	{
		string key = to_string(e1) + to_string(e2);
		return flags.find(key) != flags.end();
	};

	int left = numeric_limits<int>::max(), bottom = left;
	int right = numeric_limits<int>::min(), top = right;
	int area = 0;
	for (size_t i = 0; i < rectangles.size(); ++i)
	{
		int iLeft = rectangles[i][0], iBottom = rectangles[i][1], iRight = rectangles[i][2], iTop = rectangles[i][3];
		left = min(left, iLeft);
		bottom = min(bottom, iBottom);
		right = max(right, iRight);
		top = max(top, iTop);
		area += (iRight - iLeft) * (iTop - iBottom);

		ChangeFlag(corners, iLeft, iBottom);
		ChangeFlag(corners, iLeft, iTop);
		ChangeFlag(corners, iRight, iBottom);
		ChangeFlag(corners, iRight, iTop);
	}

	if (corners.size() == 4 && Find(corners, left, bottom)
		&& Find(corners, left, top)
		&& Find(corners, right, bottom)
		&& Find(corners, right, top))
		return area == (right - left) * (top - bottom);
	return false;
}
