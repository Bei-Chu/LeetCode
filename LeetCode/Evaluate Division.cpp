#include "stdafx.h"
#include "Solution.h"

vector<double> Solution::calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
{
	unordered_map<string, pair<double, string>> symbols;
	for (size_t i = 0; i < equations.size(); ++i)
	{
		string& d1 = equations[i].first;
		string& d2 = equations[i].second;

		auto it1 = symbols.find(d1);
		if (it1 != symbols.end())
		{
			auto it2 = symbols.find(d2);
			if (it2 != symbols.end())
			{
				string const& d1unit = it1->second.second;
				double d2ind1unit = it1->second.first / values[i];
				string d2unit = it2->second.second;
				double d2tod1mul = d2ind1unit / it2->second.first;
				for (auto it = symbols.begin(); it != symbols.end(); ++it)
				{
					if (it->second.second == d2unit)
						it->second = { it->second.first * d2tod1mul, d1unit };
				}
			}
			else
				symbols[d2] = { it1->second.first / values[i], it1->second.second };
		}

		auto it2 = symbols.find(d2);
		if (it2 != symbols.end())
		{
			symbols[d1] = { it2->second.first * values[i], it2->second.second };
			continue;
		}

		symbols[d1] = { values[i], d2 };
		symbols[d2] = { 1, d2 };
	}
	
	vector<double> ret(queries.size());
	for (size_t i = 0; i < queries.size(); ++i)
	{
		auto it1 = symbols.find(queries[i].first);
		auto it2 = symbols.find(queries[i].second);
		if (it1 != symbols.end() && it2 != symbols.end() && it1->second.second == it2->second.second)
			ret[i] = it1->second.first / it2->second.first;
		else
			ret[i] = -1;
	}
	return ret;
}
