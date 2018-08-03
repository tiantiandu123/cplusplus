#include<iostream>
#include<vector>
#include<malloc.h>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x)
		: val(x), 
		left(NULL),
		right(NULL)
	{}
	
};
typedef struct
{
	TreeNode stack[1024];  /*用来存放栈中元素的一维数组*/
	int top;
}SeqStack;
class Solution {
public:
	void creatbitree(TreeNode*b)
	{
		char ch;
		ch = getchar();
		if (ch == '\n')
		{
			return;
		}
		if (ch == '#')
		{
			*b = NULL;
		}
		else
		{
			*b = (TreeNode*)malloc(sizeof(TreeNode));
			(*b)->data = ch;
			creatbitree(&((*b)->Lchild));
			creatbitree(&((*b)->Rchild));

		}
	}
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		queue<TreeNode*> q;
		if (root != NULL)
			q.push(root);
		while (!q.empty()) {
			int n = q.size();
			vector<int> v;
			for(int i=0;i<n;i++){
				TreeNode *node = q.front();
				q.pop();
				if (node->left != NULL)
					q.push(node->left);
				if (node->right != NULL)
					q.push(node->right);
				v.push_back(node->val);
			}
			if (result.size() % 2 != 0)
				reverse(v.begin(), v.end());
			result.push_back(v);
		}
		return result;
	}
};