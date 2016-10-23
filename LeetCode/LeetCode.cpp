// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Solution.h"
#include <iostream>
#include <algorithm>
#include <cassert>

int pathSum(TreeNode* root, int sum, int const& oriSum)
{
    if (!root)
        return 0;
    return (root->val == sum ? 1 : 0) + pathSum(root->left, sum - root->val, oriSum) + pathSum(root->right, sum - root->val, oriSum)
        + pathSum(root->left, oriSum, oriSum) + pathSum(root->right, oriSum, oriSum);
}

int Solution::pathSum(TreeNode * root, int sum)
{
    return ::pathSum(root, sum, sum);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* cur = root;
    for (int i = 2; i < 6; ++i)
    {
        cur->right = new TreeNode(i);
        cur = cur->right;
    }
    Solution s;
    int n = 100, k = 10;
    auto all = s.lexicalOrder(n);
    auto right = all[k - 1];
    auto ret = s.findKthNumber(n, k);
    return 0;
}
