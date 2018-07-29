#include<iostream>
using namespace std;
#include<assert.h>
#include<math.h>
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x)
:val(x),
next(NULL) 
{}
};
class Solution {
public:
	void initLinkList(ListNode**pplist)//初始化链表，二级指针改变一级指针的指向
	{
		assert(pplist);//断言pplist是否为NULL
		*pplist = NULL;
	}
	void PushBack(ListNode**pHead, int x)
	{
		assert(pHead);
	/*	ListNode*newnode =(ListNode*)malloc(sizeof(ListNode));*/
		ListNode*newnode = new ListNode(x);
	/*	if (newnode == NULL)
		{
			perror("malloc");
			exit(0);
		}*/
		newnode->val = x;
		newnode->next = NULL;
		ListNode* cur = *pHead;
		if (*pHead == NULL)
		{
			*pHead = newnode;
			return;
		}
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newnode;

	}
	ListNode*FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) 
	{
		int len1 = GetListLength(pHead1);
		int len2 = GetListLength(pHead2);
		int len = len1 - len2;
		ListNode*p1 = pHead1;
		ListNode*p2 = pHead2;
		if (len2>len1)
		{
			p1 = pHead2;
			p2 = pHead1;
			int len = len2 - len1;
		}
		for (int i = 0; i < len; i++)
		{
			p1 = p1->next;
		}
		while ((p1 != NULL) && (p2 != NULL))
		{
				if (p1->val== p2->val)
				{
					ListNode*firstNode = p1;
					return firstNode;
				}
				p1 = p1->next;
				p2 = p2->next;
		}
		

			/*ListNode*p1 = pHead1;
		ListNode*p2 = pHead2;
		while (p1 != p2)
		{
			p1 = (p1 == NULL?pHead2:p1->next);
			p2 = (p2 == NULL?pHead1:p2->next);
		}
		return p1;
*/
	}
	void display(ListNode*p)
	{
		assert(p);
		while (p)
		{
			printf("%d->", p->val);
			p = p->next;
		}
		printf("NULL");
		printf("\n");
	}
	int GetListLength(ListNode*pHead)
	{
		int count = 0;
		while (pHead != NULL)
		{
			pHead = pHead->next;
			count++;
		}
		return count;
	}
	ListNode *rotateRight(ListNode *head, int k)
	{
		ListNode*p1 = head;
		ListNode*p2 = head;
		ListNode*p3 = NULL;
		if (head == NULL)
		{
			return NULL;
		}
		if ((head->next == NULL) || (k<0))
		{
			return head;
		}
		int count = 0;
		while (head != NULL)
		{
			head = head->next;
			count++;
		}
		k = k%count;
		if (k == 0)
			return head;
		int len = 0;
		while (len != (count - k - 1))
		{
			head = p1;
			p1 = p1->next;
			len++;
		}

		p3 = p1->next;
		p1->next = NULL;
		p2 = p3;
		p3 = p3->next;
		head = p3;
		return p2;
	}
};
void test()
{
	Solution s;
	ListNode *p1;
	
	s.initLinkList(&p1);
	s.PushBack(&p1, 1);
	s.PushBack(&p1, 2);
	s.PushBack(&p1, 3);
	s.PushBack(&p1, 6);
	s.PushBack(&p1, 7);
	s.display(p1);
	ListNode *p2;
	s.initLinkList(&p2);
	s.PushBack(&p2, 4);
	s.PushBack(&p2, 5);
	s.PushBack(&p2, 6);
	s.PushBack(&p2, 7);

	//s.PushBack(&p2, 4);*/
	s.display(p2);
	ListNode*p3 = NULL;
	p3=s.FindFirstCommonNode(p1, p2);
	printf("%d\n", p3->val);
/*	ListNode*p4=*/s.rotateRight(p1, 2);
s.display(p1);
}
int main()
{
	test();
	system("pause");
	return 0;
}

//bool number(int numbers[], int len)
//{
//	if ((numbers == NULL) || (len <= 0))
//	{
//		return false;
//	}
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		if ((numbers[i]<0) ||(numbers[i]>len - 1))
//		{
//			return false;
//		}
//	}
//	for (i = 0; i < len; i++)
//	{
//		while (numbers[i] != i)
//		{
//			if (numbers[i] == numbers[numbers[i]])
//			{
//				//*buf = numbers[i];
//				return true;
//			}
//			int temp = numbers[i];
//			numbers[i] = numbers[temp];
//			numbers[temp] = temp;
//		}
//	}
//	return false;
//
//}
//int main()
//{
////	int numbers[] = {0};
//	//int*buf = NULL;
//	int*numbers = NULL;
//	cout << number(numbers, 7) << endl;
//	system("pause");
//	return 0;
//
//}