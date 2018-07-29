/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if ((pHead1 == NULL) && (pHead2 == NULL))
		{
			return NULL;
		}
		if ((pHead2 == NULL) || (pHead1 == pHead2))
		{
			return pHead1;
		}
		if (pHead1 == NULL)
		{
			return pHead2;
		}
		ListNode*cur1 = NULL;
		ListNode*cur2 = NULL;
		if ((pHead1->val)<(pHead2->val))
		{
			cur1 = pHead1;
			cur2 = cur1;
			pHead1 = pHead1->next;
		}
		else{
			cur1 = pHead2;
			cur2 = cur1;
			pHead2 = pHead2->next;
		}
		while ((pHead1 != NULL) && (pHead2 != NULL))
		{
			if ((pHead1->val)<(pHead2->val))
			{
				cur2->next = pHead1;
				pHead1 = pHead1->next;
			}
			else{
				cur2->next = pHead2;
				pHead2 = pHead2->next;
			}
			cur2 = cur2->next;
		}
		if (pHead1 != NULL)
		{
			cur2->next = pHead1;
		}
		if (pHead2 != NULL)
		{
			cur2->next = pHead2;
		}
		return cur1;

	}
};


//2.
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode*newnode = NULL;
		ListNode*cur = pHead;
		ListNode*pre = pHead;
		if (pHead == NULL)
		{
			return NULL;
		}
		if (pHead->next == NULL)
		{
			return pHead;
		}
		while (cur != NULL)
		{
			pre = cur;
			cur = cur->next;
			pre->next = newnode;
			newnode = pre;
		}
		pHead = newnode;
		return pHead;
	}
};