#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>
//1.��������˳��ʹ����λ��ż��֮ǰ����������������֮������λ�ò��䣬ż����ż��֮������λ�ò���
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
//2.˳ʱ���ӡ��ά����
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
		{//�����ң�
			for (i = col1; i <= col2 - 1; i++)
			{
				array.push_back(matrix[row1][i]);
			}
			row1++;
			//���ϵ���
			for (i = row1; i <= row2 - 1; i++)
			{
				array.push_back(matrix[i][col2 - 1]);
			}
			col2--;
			//���ҵ���
			for (i = col2 - 1; i >= col1; i--)
			{
				array.push_back(matrix[row2 - 1][i]);
			}
			row2--;
			//���µ���
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