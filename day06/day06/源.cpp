#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>
//1.调整数组顺序使奇数位于偶数之前，并且奇数与奇数之间的相对位置不变，偶数与偶数之间的相对位置不变
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int i = 0;
		vector<int>arr;
		for (i = 0; i<array.size(); i++)
		{
			if ((array[i] % 2) != 0)
			{
				arr.push_back(array[i]);
			}
		}
		for (i = 0; i<array.size(); i++)
		{
			if ((array[i] % 2) == 0)
			{
				arr.push_back(array[i]);
			}
		}
		
	}
};
//2.顺时针打印二维数组
#include<assert.h>
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>array;
		int row1 = 0;
		int col1 = 0;
		int col2 = matrix[0].size();
		int row2 = matrix.size();
		assert(!matrix.empty());
		int i = 0;
		while ((row1<row2) && (col1<col2))
		{//从左到右：
			for (i = col1; i <= col2 - 1; i++)
			{
				array.push_back(matrix[row1][i]);
			}
			row1++;
			//从上到下
			for (i = row1; i <= row2 - 1; i++)
			{
				array.push_back(matrix[i][col2 - 1]);
			}
			col2--;
			//从右到左
			for (i = col2 - 1; i >= col1; i--)
			{
				array.push_back(matrix[row2 - 1][i]);
			}
			row2--;
			//从下到上
			for (i = row2 - 1; i >= row1; i--)
			{
				array.push_back(matrix[i][col1]);
			}
			col1++;
		}
		return array;
	}
	void show(vector<int>array)
	{
		int i = 0;
		for (i = 0; i<array.size(); i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	Solution s;
	vector<vector<int>>matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<int>result=s.printMatrix(matrix);
	s.show(result);
	system("pause");
	return 0;
}