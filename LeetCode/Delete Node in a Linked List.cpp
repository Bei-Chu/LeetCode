#include "stdafx.h"
#include "Solution.h"

void Solution::deleteNode(ListNode* node)
{
	node->val = node->next->val;
	ListNode* nextnext = node->next->next;
	delete node->next;
	node->next = nextnext;
}
