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

vector<int> Solution::findAnagrams(string s, string p)
{
    vector<int> ret;
    if (s.length() < p.length())
        return ret;

    vector<int> pattern('z' + 1, 0);
    vector<int> match('z' + 1, 0);
    for (int i = 0; i < p.length(); ++i)
    {
        ++pattern[p[i]];
        ++match[s[i]];
    }

    unordered_set<char> diff;
    for (char c = 'a'; c <= 'z'; ++c)
        if (pattern[c] != match[c])
            diff.insert(c);

    if (diff.empty())
        ret.push_back(0);

    for (int i = 1; i + p.length() <= s.length(); ++i)
    {
        char c1 = s[i - 1];
        char c2 = s[i + p.length() - 1];
        --match[c1];
        ++match[c2];
        if (match[c1] != pattern[c1])
            diff.insert(c1);
        else
            diff.erase(c1);
        if (match[c2] != pattern[c2])
            diff.insert(c2);
        else
            diff.erase(c2);
        if (diff.empty())
            ret.push_back(i);
    }

    return ret;
}

string parse(string const& exp, int i)
{
    if (exp[i] == 'T')
    {
        if (i + 1 < exp.length() && exp[i + 1] == '?')
            return parse(exp, i + 2);
        else
            return "T";
    }
    else if (exp[i] == 'F')
    {
        if (i + 1 < exp.length() && exp[i + 1] == '?')
        {
            int queCount = 0;
            int j = i + 1;
            while (j < exp.length())
            {
                if (exp[j] == '?')
                    ++queCount;
                else if (exp[j] == ':')
                {
                    --queCount;
                    if (queCount == 0)
                        break;
                }
                ++j;
            }
            return parse(exp, j + 1);
        }
        else
            return "F";
    }
    return string(1, exp[i]);
}

string Solution::parseTernary(string expression)
{
    return parse(expression, 0);
}

int Solution::findKthNumber(int n, int k)
{
    vector<int> power = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
    vector<int> count = { 0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111 };

    int nn = n;
    vector<int> digits;
    while (n > 0)
    {
        digits.insert(digits.begin(), n % 10);
        n /= 10;
    }
    vector<int> nvec;


    vector<int> nCount(10, 0);
    for (int i = 1; i < digits[0]; ++i)
        nCount[i] = count[digits.size()];
    for (int i = digits[0] + 1; i < 10; ++i)
        nCount[i] = count[digits.size() - 1];
    nCount[digits[0]] = count[digits.size() - 1] + nn % power[digits.size() - 1] + 1;

    vector<int> kdigits;
    int d = 1;
    while (k > nCount[d])
    {
        k -= nCount[d];
        ++d;
    }
    kdigits.insert(kdigits.begin(), d);
    --k;
    if (k == 0)
        return kdigits.back();
    bool equal = kdigits[0] == digits[0];

    auto all = lexicalOrder(nn);
    while (k > 0)
    {
        if ((digits.size() - kdigits.size() == 1) || (kdigits[0] > digits[0] && digits.size() - kdigits.size() == 2))
        {
            kdigits.push_back(k - 1);
            break;
        }
    }

    int ret = 0;
    for (int i = 0; i < kdigits.size(); ++i)
        ret = ret * 10 + kdigits[i];
    return ret;
}
