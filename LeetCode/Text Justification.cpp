#include "stdafx.h"
#include "Solution.h"

vector<string> Solution::fullJustify(vector<string>& words, int maxWidth)
{
	size_t i = 0;
	vector<string> ret;
	while (i < words.size())
	{
		size_t j = i;
		int wordTotalLength = 0;
		int lineTotalLength = -1;
		for (; j<words.size() && lineTotalLength <= maxWidth; ++j)
		{
			lineTotalLength += words[j].length() + 1;
			wordTotalLength += words[j].length();
		}
		if (lineTotalLength > maxWidth)
		{
			wordTotalLength -= words[j - 1].length();
			--j;
		}
		if (j == words.size())
		{
			string s;
			while (i < j)
			{
				s.append(words[i]);
				++i;
				if (i != j)
					s.append(" ");
			}
			s.append(maxWidth - s.length(), ' ');
			ret.push_back(s);
			break;
		}
		int numSlots = j - i - 1;
		if (numSlots == 0)
		{
			ret.push_back(words[i].append(maxWidth - wordTotalLength, ' '));
		}
		else
		{
			int numSpaces = maxWidth - wordTotalLength;
			int averageSpace = numSpaces / numSlots;
			int extraSpace = numSpaces % numSlots;
			string s;
			s.append(words[i]);
			for (int iSlot = 0; iSlot < numSlots; ++iSlot)
			{
				s.append(averageSpace + (extraSpace > 0 ? 1 : 0), ' ');
				--extraSpace;
				s.append(words[i + iSlot + 1]);
			}
			ret.push_back(s);
		}
		i = j;
	}
	return ret;
}
