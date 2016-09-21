#pragma once

#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#include <list>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution
{
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(string s);
	string convert(string s, int numRows);
	int reverse(int x);
	int myAtoi(string str);
	bool isPalindrome(int x);
	bool isMatch(string s, string p);
	bool searchMatrix(vector<vector<int>>& matrix, int target);
	int divide(int dividend, int divisor);
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
	bool canJump(vector<int>& nums);
	int maximalSquare(vector<vector<char>>& matrix);
	int numDecodings(string s);
	int titleToNumber(string s);
	int maxProduct(vector<int>& nums);
	vector<vector<int>> levelOrder(TreeNode* root);
	int calculate(string s);
	vector<int> singleNumber(vector<int>& nums);
	void rotate(vector<int>& nums, int k);
	vector<vector<string>> solveNQueens(int n);
	void deleteNode(ListNode* node);
	ListNode* partition(ListNode* head, int x);
	vector<int> lexicalOrder(int n);
	int firstUniqChar(string s);
	int lastRemaining(int n);
	bool isRectangleCover(vector<vector<int>>& rectangles);
	bool isSubsequence(string s, string t);
};
