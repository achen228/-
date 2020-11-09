//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
	{}
};
 
class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (!l1)
			return l2;
		if (!l2)
			return l1;

		ListNode* head = nullptr;
		ListNode* tail = nullptr;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				if (tail == nullptr)
				{
					head = tail = l1;
				}
				else
				{
					tail->next = l1;
					tail = l1;
				}
				l1 = l1->next;
			}
			else
			{
				if (tail == nullptr)
				{
					head = tail = l2;
				}
				else
				{
					tail->next = l2;
					tail = l2;
				}
				l2 = l2->next;
			}
		}

		if (l1)
		{
			tail->next = l1;
		}
		else
		{
			tail->next = l2;
		}
		return  head;
	}
};
