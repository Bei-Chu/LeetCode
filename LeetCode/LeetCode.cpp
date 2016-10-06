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
	auto ret = s.palindromePairs(vector<string>({ "bbbbbabbabbbb", "baabbaa", "bbab", "bbbabbaaab", "abababbbbbab", "abb", "baaaabbb", "babbaaaba", "aab", "aaaab", "baabbbbabbaaaba", "baaab", "abbbab", "abaabbbabbabba", "aa", "aabbbaabba", "aaabbbbbaaabbbb", "bbaaaaba", "ababaaa", "aaaaa", "aaaaabbbbaaaba", "abbabbbaabbaabbb", "bbaba", "aaaaabbbabbbbaaaab", "abbbaa", "bbbabbaaa", "bbbaaabaabbbaaaaabaa", "aaaabbabb", "ababbababbbab", "aaaaababaababbbabaaa", "ba", "bbbbababbbabab", "baaaba", "aababbaaabbb", "aabbaaabbabaaababaab", "abbbb", "babaabaaababb", "bbbbabaaaab", "babbbbb", "babaaba", "aaba", "abababba", "a", "bb", "abaaab", "babbabaababbabaaba", "aaaaaababbbabaaabaa", "baabaaabb", "b", "bbaaaabbb", "abaaaaabaabbbaa", "ab", "bababaaaba", "aabababb", "ababaabbaababba", "bbb", "ababbaabababbbbbabb", "bbbbb", "abbbbaabaaaabb", "baba", "bbaabbabaaababaabbaa", "bbaabaabbabbaab", "bbbaabbab", "babbbbbaaaaabaa", "abbbbbbabbbabb", "abaa", "bbbbaababaab", "abaaababa", "aaaababaaababbaaba", "bbabbbabbbbbbaab", "abbabbabaabbabbbba", "abbbbbaabbbaaabaaaa", "bbaabababb", "aaabababaabbaaaaaaab", "ababbaabaaababb", "abbbbabaaabbaaabbab", "aababababbabaaa", "baabbaabbbaaaaaa", "bbbbbbbabbabbbbbb", "bbbabbabbabbabaabba", "babbbbabaaaabbabaab", "baabaabaabababaaabba", "bbaaaabbbbabbbaaaa", "aaaaabaabaa", "bbabaaabbbabaa", "baaabaaaaaab", "ababbbbbbbabaaaba", "abbbabaababbbbbaaa", "baaaaaabab", "aabbabba", "baaabbaabbbbaba", "aaaaabba", "babaaabbba", "bbbbab", "bbbbaabbaabab", "baa", "baababaa", "abbbbb", "babbaa", "abbbabbaa" }));
	vector<vector<int>> output = { {0, 48}, {1, 48}, {8, 1}, {2, 48}, {30, 2}, {2, 5}, {38, 4}, {5, 42}, {43, 5}, {5, 30}, {6, 9}, {43, 6}, {44, 7}, {30, 8}, {8, 14}, {48, 8}, {8, 95}, {95, 9}, {30, 9}, {48, 9}, {48, 12}, {14, 42}, {42, 14}, {15, 24}, {5, 15}, {18, 59}, {14, 18}, {19, 42}, {19, 14}, {14, 19}, {42, 19}, {22, 43}, {42, 24}, {30, 48}, {42, 30}, {30, 51}, {31, 55}, {32, 8}, {32, 11}, {42, 32}, {32, 44}, {35, 42}, {35, 30}, {37, 35}, {38, 51}, {38, 2}, {38, 93}, {39, 48}, {65, 39}, {40, 42}, {51, 40}, {40, 95}, {40, 65}, {41, 59}, {5, 41}, {43, 48}, {48, 43}, {44, 42}, {11, 44}, {95, 44}, {44, 32}, {45, 2}, {65, 45}, {48, 49}, {51, 42}, {48, 51}, {51, 30}, {67, 52}, {55, 48}, {43, 55}, {55, 43}, {48, 55}, {57, 48}, {57, 43}, {55, 57}, {57, 55}, {43, 57}, {48, 57}, {17, 58}, {59, 48}, {42, 59}, {98, 62}, {8, 65}, {65, 30}, {42, 65}, {65, 40}, {66, 55}, {96, 66}, {67, 40}, {67, 32}, {51, 67}, {78, 48}, {65, 86}, {30, 88}, {89, 42}, {5, 91}, {93, 55}, {30, 93}, {93, 35}, {95, 48}, {14, 95}, {95, 51}, {95, 8}, {96, 48}, {40, 96}, {97, 42}, {57, 97}, {97, 30}, {8, 98}, {98, 2} };
	vector<vector<int>> expected = { {0, 48}, {1, 48}, {8, 1}, {2, 48}, {30, 2}, {2, 5}, {38, 4}, {5, 42}, {43, 5}, {5, 30}, {6, 9}, {43, 6}, {44, 7}, {30, 8}, {8, 14}, {48, 8}, {8, 95}, {95, 9}, {30, 9}, {48, 9}, {48, 12}, {14, 42}, {42, 14}, {15, 24}, {5, 15}, {18, 59}, {14, 18}, {19, 42}, {19, 14}, {14, 19}, {42, 19}, {22, 43}, {42, 24}, {30, 48}, {42, 30}, {30, 51}, {31, 55}, {32, 8}, {32, 11}, {42, 32}, {32, 44}, {35, 42}, {35, 30}, {37, 35}, {38, 51}, {38, 2}, {38, 93}, {39, 48}, {65, 39}, {40, 42}, {51, 40}, {40, 95}, {40, 65}, {41, 59}, {5, 41}, {43, 48}, {48, 43}, {44, 42}, {11, 44}, {95, 44}, {44, 32}, {45, 2}, {65, 45}, {48, 49}, {51, 42}, {48, 51}, {51, 30}, {67, 52}, {55, 48}, {43, 55}, {55, 43}, {48, 55}, {57, 48}, {57, 43}, {55, 57}, {57, 55}, {43, 57}, {48, 57}, {17, 58}, {59, 48}, {42, 59}, {98, 62}, {8, 65}, {65, 30}, {42, 65}, {65, 40}, {66, 55}, {96, 66}, {67, 40}, {67, 32}, {51, 67}, {78, 48}, {65, 86}, {30, 88}, {89, 42}, {5, 91}, {93, 55}, {30, 93}, {93, 35}, {95, 48}, {14, 95}, {95, 51}, {95, 8}, {96, 48}, {40, 96}, {97, 42}, {57, 97}, {97, 30}, {8, 98}, {98, 2} };
	sort(output.begin(), output.end());
	sort(expected.begin(), expected.end());
	for (size_t i = 0; i < output.size(); ++i)
	{
		assert(output[i][0] == expected[i][0]);
		assert(output[i][1] == expected[i][1]);
	}
	return 0;
}
