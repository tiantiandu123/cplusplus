#include<iostream>
using namespace std;
#include<vector>
#include<queue>
//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};
//class Solution {
//public:
//	vector<vector<int> > Print(TreeNode* pRoot) {
//		vector<vector<int>>ret;
//		if (pRoot == NULL)
//		{
//			return ret;
//		}
//		queue<TreeNode*>q;
//		q.push(pRoot);
//		while (!q.empty())
//		{
//			vector<int>v;
//			int size = q.size();
//			for (int i = 0; i<size; i++)
//			{
//				TreeNode*tmp = q.front();
//				v.push_back(tmp->val);
//				if (tmp->left)
//				{
//					q.push(tmp->left);
//				}
//				if (tmp->right)
//				{
//					q.push(tmp->right);
//				}
//				q.pop();
//			}
//			ret.push_back(v);
//		}
//		return ret;
//	}
//
//};
//int main()
//{
//	Solution s;
//
//}

int main()
{
	int a[3];
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	int *p, *q;
	p = a;
	q = &a[2];
	*q = a[2];
int ret = a[q - p];
	cout << ret << endl;
	cout << q << endl;
	system("pause");
	return 0;
}