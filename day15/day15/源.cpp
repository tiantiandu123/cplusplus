#include<iostream>
using namespace std;
 //Definition for singly-linked list.
struct ListNode {
	int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

// Definition for binary tree
 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution
 {
 public:
	 TreeNode *sortedListToBST(ListNode *head) {
		 if (head == NULL)
		 {
			 return NULL;
		 }
		 if (head->next == NULL)
		 {
			 TreeNode*newnode = new TreeNode(head->val);
			 return newnode;
		 }
		 //找到中间的节点
		 ListNode*fast = head;
		 ListNode*slow = head;
		 ListNode*p = head;
		 while ((fast != NULL) && (fast->next != NULL))
		 {
			 p = slow;
			 fast = fast->next->next;
			 slow = slow->next;

		 }
		 fast = slow->next;
		 p->next = NULL;
		 TreeNode*pRoot = new TreeNode(slow->val);
		 if (head != slow)
			 pRoot->left = sortedListToBST(head);
		 pRoot->right = sortedListToBST(fast);

		 return pRoot;
	 }
 };



 // Definition for singly-linked list.
 struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 class Solution {
 public:
	 ListNode *rotateRight(ListNode *head, int k) {
		 ListNode*p1 = head;
		 ListNode*p2 = head;
		 if (head == NULL)
		 {
			 return NULL;
		 }
		 if ((head->next == NULL) || (k <= 0))
		 {
			 return head;
		 }
		 int count = 0;
		 ListNode*cur = head;
		 while (cur->next)
		 {
			 cur = cur->next;
			 count++;
		 }
		 k = k%count;
		 if (k == 0)
			 return head;
		 int len = 0;
		 while (len != (count - k - 1))
		 {
			 p1 = p1->next;
			 len++;
		 }
		 p2 = p1->next;
		 p1->next = NULL;
		 cur->next = head;
		 return p2;
	 }
 };