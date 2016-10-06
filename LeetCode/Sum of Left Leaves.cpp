#include "stdafx.h"
#include "Solution.h"

void Sum(TreeNode* node, bool left, int& sum)
{
	if (!node)
		return;

	if (!node->left && !node->right && left)
		sum += node->val;

	Sum(node->left, true, sum);
	Sum(node->right, false, sum);
}

int Solution::sumOfLeftLeaves(TreeNode* root)
{
	int ret = 0;
	Sum(root, false, ret);
	return ret;
}
