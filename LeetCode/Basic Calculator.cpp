#include "stdafx.h"
#include "Solution.h"

struct Token
{
	enum Type { Invalid, Num, Operation };
	Type type{ Invalid };
	int num{ -1 };
	char operation{ ' ' };
};

Token ReadToken(string const& s, size_t& i)
{
	while (i < s.length() && s[i] == ' ')
		++i;
	Token ret;
	if (i >= s.length())
		return ret;
	if (s[i] >= '0' && s[i] <= '9')
	{
		ret.type = Token::Num;
		size_t j = i + 1;
		while (j < s.length() && s[j] >= '0' && s[j] <= '9')
			++j;
		ret.num = atoi(s.substr(i, j - i).c_str());
		i = j;
	}
	else
	{
		ret.type = Token::Operation;
		ret.operation = s[i];
		++i;
	}
	return ret;
}

int Solution::calculate(string s)
{
	size_t i = 0;
	vector<int> operand{ 0 };
	vector<char> operation;
	while (true)
	{
		Token token = ReadToken(s, i);
		if (token.type == Token::Invalid)
			return operand.back();
		if (token.type == Token::Num)
		{
			if (!operation.empty())
			{
				char c = operation.back();
				if (c == '+' || c == '-')
				{
					operation.pop_back();
					int num = operand.back();
					operand.pop_back();
					if (c == '+')
						operand.push_back(num + token.num);
					else
						operand.push_back(num - token.num);
				}
				else
					operand.push_back(token.num);
			}
			else
			{
				operand.push_back(token.num);
			}
		}
		else
		{
			if (token.operation == ')')
			{
				operation.pop_back();
				if (!operation.empty())
				{
					char c = operation.back();
					if (c == '+' || c == '-')
					{
						operation.pop_back();
						int num2 = operand.back();
						operand.pop_back();
						int num1 = operand.back();
						operand.pop_back();
						if (c == '+')
							operand.push_back(num1 + num2);
						else
							operand.push_back(num1 - num2);
					}
				}
			}
			else
			{
				operation.push_back(token.operation);
			}
		}
	}
}
