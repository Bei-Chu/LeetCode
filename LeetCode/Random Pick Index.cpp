#include "stdafx.h"
#include "Solution.h"

class RandomPickIndex
{
public:
	RandomPickIndex(vector<int> nums)
	{
		num = move(nums);
		srand(0);
	}

	int pick(int target)
	{
		while (true)
		{
			int index = rand() % num.size();
			if (num[index] == target)
				return index;
		}
	}

	vector<int> num;
};
