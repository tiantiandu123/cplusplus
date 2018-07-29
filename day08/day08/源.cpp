//#include<iostream>
//using namespace std;
//
//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) :
//val(x), next(NULL) {
//}
//};
//class Solution {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		ListNode*fast = pListHead;
//		ListNode*slow = pListHead;
//		if ((pListHead == NULL) || (k <= 0))
//		{
//			return NULL;
//		}
//		while (--k)
//		{
//			if(fast->next!=	NULL)
//			{
//				fast = fast->next;
//		     }
//		else
//		{
//			return NULL;
//		}
//		}
//		while (fast->next != NULL)
//		{
//			fast = fast->next;
//			slow = slow->next;
//		}
//			return slow;
//	}
//};
#include<iostream>
using namespace std;
#include <cstdio>
int maxsum(int*arr, int n)
{
	if (arr == NULL || n <= 0)
	{
		return 0;
	}
	int sum = 0;
	int maxsum = arr[0];
	for (int i = 0; i<n; i++)
	{
		if (sum>0)
		{
			sum = sum + arr[i];
		}
		else
		{
			sum = arr[i];
		}
		if (sum>maxsum)
		{
			maxsum = sum;
		}
	}
	return maxsum;
}
int main()
{
	int n = 0;
	cin >> n;
	int a = 0;
	int arr[] = { 0 };
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int b = maxsum(arr, n);
	cout << b << endl;
	return 0;
}

