#include "stdafx.h"
#include "Solution.h"

int Solution::wordsTyping(vector<string>& sentence, int rows, int cols)
{
	vector<int> length(sentence.size());
	length[0] = sentence[0].length();
	for (int i = 1; i < sentence.size(); ++i)
		length[i] = length[i - 1] + sentence[i].length() + 1;

	if (cols < 2 * length.back() + 1)
	{
		int ret = 0;
		int row = 0, col = 0, i = 0;
		while (row < rows)
		{
			int nextCol = col + sentence[i].length();
			if (nextCol > cols)
			{
				++row;
				col = 0;
				continue;
			}
			col = nextCol + 1;
			++i;
			if (i == sentence.size())
			{
				++ret;
				i = 0;
			}
		}
		return ret;
	}
	else
	{
		int ret = 0, offset = 0;
		for (int row = 0; row < rows; ++row)
		{
			if (offset > 0)
				++ret;
			int wholeCount = (cols + 1 - offset) / (length.back() + 1);
			ret += wholeCount;
			int left = cols - offset - wholeCount * (length.back() + 1);
			int nextLineStart = 0;
			while (length[nextLineStart] <= left)
				++nextLineStart;
			if (nextLineStart == 0)
				offset = 0;
			else
				offset = length.back() - length[nextLineStart - 1];
		}
		return ret;
	}
}
