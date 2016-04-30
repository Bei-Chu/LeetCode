#include "stdafx.h"
#include "Solution.h"

ListNode * Solution::partition(ListNode * head, int x)
{
	ListNode* less = nullptr, *greater = nullptr, *lessHead = nullptr, *greaterHead = nullptr;
	while (head)
	{
		ListNode* next = head->next;
		if (head->val < x)
		{
			if (less)
				less->next = head;
			else
				lessHead = head;
			less = head;
		}
		else
		{
			if (greater)
				greater->next = head;
			else
				greaterHead = head;
			greater = head;
		}
		head->next = nullptr;
		head = next;
	}
	if (less)
		less->next = greaterHead;
	if (lessHead)
		return lessHead;
	return greaterHead;
}
