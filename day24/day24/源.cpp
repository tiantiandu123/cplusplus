//求深度
#include<iostream>
using namespace std;
#include<stack>
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
		{
			return 0;
		}
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return left>right ? left + 1 : right + 1;
	}
};



//先序遍历的非递归
//Definition for binary tree
struct TreeNode {
     int val;
TreeNode *left;
    TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int>v;
		if (root == NULL)
		{
			return v;
		}
		stack<TreeNode*>s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode*top = s.top();
			v.push_back(top->val);
			s.pop();
			if (top->right)
			{
				s.push(top->right);
			}
			if (top->left)
			{
				s.push(top->left);
			}
		}
		return v;
	}
};