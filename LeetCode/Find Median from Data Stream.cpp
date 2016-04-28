#include "stdafx.h"
#include "Solution.h"

class MedianFinder {
public:

	// Adds a number into the data structure.
	void addNum(int num) 
	{
		int i = binarySearch(num);
		nums.insert(nums.begin() + i, num);
	}

	// Returns the median of current data stream
	double findMedian() 
	{
		return (nums[nums.size() / 2] + nums[(nums.size() - 1) / 2]) / 2.;
	}

protected:
	vector<int> nums;

	int binarySearch(int num)
	{
		if (nums.size() == 0)
			return 0;
		int lower = 0, upper = nums.size() - 1;
		while (upper > lower)
		{
			int mid = (upper + lower) / 2;
			if (nums[mid] > num)
				upper = max(lower, mid - 1);
			else if (nums[mid] < num)
				lower = min(upper, mid + 1);
			else
				return mid;
		}
		if (nums[upper] < num)
			return upper + 1;
		else
			return upper;
	}
	int linearSearch(int num)
	{
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] >= num)
				return i;
		return nums.size();
	}
};
