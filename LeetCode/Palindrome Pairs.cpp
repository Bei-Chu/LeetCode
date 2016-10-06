#include "stdafx.h"
#include "Solution.h"

vector<vector<int>> Solution::palindromePairs(vector<string>& words)
{
	vector<vector<int>> ret;
	unordered_map<string, bool> cache;

	static auto MakeKey = [](int i, bool b, int j)
	{
		return to_string(i) + (b ? "1" : "0") + to_string(j);
	};

	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = 0; j < words.size(); ++j)
		{
			if (i == j)
				continue;

			bool bLeft = words[i].length() > words[j].length();
			int diff = bLeft ? words[i].length() - words[j].length() : words[j].length() - words[i].length();
			bool cached = false;
			if (bLeft)
			{
				auto it = cache.find(MakeKey(i, true, diff));
				cached = it != cache.end();
				if (it != cache.end() && !it->second)
					continue;
			}
			else
			{
				auto it = cache.find(MakeKey(j, false, diff));
				cached = it != cache.end();
				if (it != cache.end() && !it->second)
					continue;
			}

			if (!cached)
			{
				if (bLeft)
				{
					bool toCache = true;
					int k = words[j].length(), l = words[i].length() - 1;
					while (l > k)
					{
						if (words[i][l] != words[i][k])
						{
							toCache = false;
							break;
						}
						++k; --l;
					}
					cache[MakeKey(i, true, diff)] = toCache;
					if (!toCache)
						continue;
				}
				else
				{
					bool toCache = true;
					int k = 0, l = words[j].length() - 1 - words[i].length();
					while (l > k)
					{
						if (words[j][k] != words[j][l])
						{
							toCache = false;
							break;
						}
						++k; --l;
					}
					cache[MakeKey(j, false, diff)] = toCache;
					if (!toCache)
						continue;
				}
			}

			bool palindrome = true;
			if (bLeft)
			{
				int k = 0, l = words[j].length() - 1;
				while (l >= 0)
				{
					if (words[i][k] != words[j][l])
					{
						palindrome = false;
						break;
					}
					++k; --l;
				}
			}
			else
			{
				int k = 0, l = words[j].length() - 1;
				while (k < words[i].length())
				{
					if (words[i][k] != words[j][l])
					{
						palindrome = false;
						break;
					}
					++k; --l;
				}
			}

			if (palindrome)
				ret.push_back({ i, j });
		}
	}
	return ret;
}
