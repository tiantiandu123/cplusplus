#include<iostream>
#include<vector>
using namespace std;
//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

//For example,
//If n = 4 and k = 2, a solution is :
//
//[
//	[2, 4],
//	[3, 4],
//	[2, 3],
//	[1, 2],
//	[1, 3],
//	[1, 4],
//]
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
			vector<vector<int>> ret;
			vector<int> cur;
			combine(cur, 1, n, k, ret);
			return ret;
		}
	void combine(vector<int>&cur, int index, int n, int k, vector<vector<int>>&ret)
	{
		if (cur.size() == k)
		{
			ret.push_back(cur);
		}
		if (index > n || cur.size() > k)
		{
			return;
		}
		for (int i =index; i <= n; i++)
		{
			cur.push_back(i);
			combine(cur, i+ 1, n, k, ret);
			cur.pop_back();
		}
	}
};
//int main()
//{
//	Solution s;
//	vector<vector<int>>ret = s.combine(4, 2);
//	vector<vector<int>>::iterator it;
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cout << ret[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//
//void getCombine(
//	int n,
//	int k,
//	int level,
//	vector<int> &solution,
//	vector<vector<int>> &result){
//	if (solution.size() == k){
//		result.push_back(solution);
//		return;
//	}
//	for (int i = level; i <= n; i++){
//		solution.push_back(i);
//		getCombine(n, k, i + 1, solution, result);
//		solution.pop_back();
//	}
//}
//vector<vector<int> > combine(int n, int k) {
//	vector<int> solution;
//	vector<vector<int>> result;
//	getCombine(n, k, 1, solution, result);
//	return result;
//}
//int main()
//{
//	vector<vector<int>>ret = combine(4, 2);
//	vector<vector<int>>::iterator it;
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cout << ret[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}

//求开方，如sqrt(3)=1,sqrt(10)=3
//class Solution {
//public:
//	int sqrt(int x) {
//		if (x == 0)
//		{
//			return 0;
//		}
//		int left = 1, right = x;
//		int mid = 0;
//
//		while (left <=right)
//		{
//			//cout << mid << endl;
//			if (mid == (left + right) / 2)
//			{
//				break;
//			}
//			mid = (left + right) / 2;
//			if (mid*mid == x)
//			{
//				return mid;
//			}
//			else if (mid*mid < x)
//			{
//				left = mid;
//			}
//			else
//			{
//				right = mid;
//			}
//		}
//		return mid;
//	}
//			/*long long left = 0, right = x;
//			long long mid = 0;
//			while (left <= right) {
//				mid = (left + right) / 2;
//				long long sq = mid * mid;
//				if (sq == x) return mid;
//				else if (sq < x) left = mid + 1;
//				else right = mid - 1;
//			}
//			return right;
//		}*/
//};
//int main()
//{
//	Solution s;
//	int ret = s.sqrt(10);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//For example,
//[1, 1, 2] have the following unique permutations :
//[1, 1, 2], [1, 2, 1], and[2, 1, 1].
//
//和上题的思路一致，这里要加一个去重复的条件判断。并且需要先对数组进行排序，只有前面重复的数字使用的时候才能用
void GeneratePermuteUni(vector<vector<int>> &result,vector<int> &solu,int level,vector<int> &visited,vector<int> &num){
	if (level == num.size()){
		result.push_back(solu);
		return;
	}
	for (int i = 0; i<num.size(); i++){
		if (visited[i] == 0){
			if (i>0 && num[i] == num[i - 1] && visited[i - 1] == 0)
				continue;
			visited[i] = 1;
			solu.push_back(num[i]);
			GeneratePermuteUni(result, solu, level + 1, visited, num);
			solu.pop_back();
			visited[i] = 0;
		}
	}
}
vector<vector<int> > permuteUnique(vector<int> &num) {
	vector<vector<int>> result;
	vector<int> solution;
	vector<int> visited(num.size(), 0);
	if (num.size() == 0) return result;
	GeneratePermuteUni(result, solution, 0, visited, num);
	return result;
}
int main()
{
	vector<int>r = { 1, 2, 3 };
	vector<vector<int>>ret = permuteUnique(r);
	vector<vector<int>>::iterator it;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}