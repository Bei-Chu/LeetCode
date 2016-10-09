// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Solution.h"
#include <iostream>
#include <algorithm>
#include <cassert>

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	auto ret = s.wordsTyping(vector<string>({ "try","to","be","better" }), 10000, 9001);
	return 0;
}
