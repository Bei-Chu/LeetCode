#include "stdafx.h"
#include "Solution.h"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* ret = nullptr, *pre = nullptr;
	bool overflow = false;
	while (l1 || l2)
	{
		int n = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (overflow ? 1 : 0);
		if (n >= 10)
		{
			n -= 10;
			overflow = true;
		}
		else
			overflow = false;
		if (pre)
		{
			pre->next = new ListNode(n);
			pre = pre->next;
		}
		else
		{
			pre = new ListNode(n);
			ret = pre;
		}
		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}
	if (overflow)
		pre->next = new ListNode(1);
	return ret;
}
