#include<iostream>
using namespace std;
#include<vector>
 struct ListNode {
   int val;
       struct ListNode *next;
       ListNode(int x) :
             val(x), next(NULL)
	   {  
	   }
 };
 class Solution {
 public:
	 vector<int> printListFromTailToHead(ListNode*head)
	 {
		 vector<int>result;
		 print(head, result);
		 return result;
	 }

	 void print(ListNode*head, vector<int>&result)
	 {

		 if (head != NULL)
		 {
			 if (head->next != NULL)
			 {
				 print(head->next, result);
			 }
			 result.push_back(head->val);
		 }
	 }
 };

struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		int x = 0;
		cloneList(pHead, x);
		pointRandom(pHead);
		RandomListNode*ret = devidedList(pHead);
		return ret;
	}
	//1.复制链表
	void cloneList(RandomListNode* pHead, int x)
	{
		RandomListNode* cur = pHead;
		while (cur != NULL)
		{
			RandomListNode*pclone = new RandomListNode(x);
			pclone->next = cur->next;
			pclone->label = cur->label;
			pclone->random = NULL;
			//下面进行往下走
			cur->next = pclone;
			cur = pclone->next;
		}
	}
	void pointRandom(RandomListNode*pHead)//指向
	{
		RandomListNode* cur = pHead;
		while (cur != NULL)
		{
			RandomListNode*pclone = cur->next;
			if (cur->random != NULL)
			{
				pclone->random = cur->random->next;
			}
			cur = pclone->next;
		}
	}
	RandomListNode*devidedList(RandomListNode*pHead)//分离
	{
		RandomListNode* cur = pHead;
		RandomListNode*pclone = NULL;
		RandomListNode*head = NULL;
		if (cur != NULL)
		{
			head = pclone = cur->next;
			cur->next = pclone->next;
			cur = cur->next;
		}
		while (cur)
		{
			pclone->next = cur->next;
			pclone = pclone->next;
			cur->next = pclone->next;
			cur = cur->next;
		}
		return head;
	}
};