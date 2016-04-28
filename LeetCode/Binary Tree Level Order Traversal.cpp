#include "stdafx.h"
#include "Solution.h"

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
	vector<vector<int>> ret;
	if (!root)
		return ret;
	vector<TreeNode*> curLevel;
	curLevel.push_back(root);
	while (!curLevel.empty())
	{
		vector<int> cur;
		vector<TreeNode*> next;
		for (size_t i = 0; i < curLevel.size(); ++i)
		{
			cur.push_back(curLevel[i]->val);
			if (curLevel[i]->left)
				next.push_back(curLevel[i]->left);
			if (curLevel[i]->right)
				next.push_back(curLevel[i]->right);
		}
		ret.push_back(cur);
		curLevel = move(next);
	}
	return ret;
}
