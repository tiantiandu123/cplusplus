#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//class Solution {
//public:
//	bool operator()(const string&s1, const string&s2)
//	{
//		string first = s1 + s2;
//		string second = s2 + s1;
//		return first <= second;
//	}
//	string PrintMinNumber(vector<int> numbers) {
//		string s;
//		vector<string>arr;
//		int i = 0;
//		for (i = 0; i<numbers.size(); i++)
//		{
//			arr.push_back(InttoString(numbers[i]));
//		}
//		sort(arr.begin(), arr.end());
//		int j = 0;
//		for (j = 0; j<arr.size(); i++)
//		{
//			s = s + arr[i];
//		}
//		return s;
//	}
//	string InttoString(int n)
//	{
//		string a;
//		int i = 0;
//		while (n>0)
//		{
//			a[i] = n % 10 + '0';
//			n /= 10;
//			i++;
//		}
//		return a;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> v = { 3, 32, 321 };
//	cout<<s.PrintMinNumber(v)<<"";
//	system("pause");
//	return 0;
//}
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>>result;
		int begin = 1;
		int end = 2;
		int currentsum = begin+end;
		int len = sum / 2;
		if (sum < 3)
			return result;
		while (begin<end&&end<=len)
		{
			if (currentsum == sum)
			{
				vector<int>temp;
				int i = 0;
				for (i = begin; i<=end; i++)
				{
					temp.push_back(i);//
				}
				result.push_back(temp);//��temp �Ž�ȥ
				++end;			//end����++
				currentsum = currentsum + end;//currentsumҲ����end,������Ѱ�ҵ�ǰend֮���ֵ�Ƿ������������
			}
			else if (currentsum<sum)//��currentsum<sum�������end
			{
				++end;
				currentsum = currentsum + end;
			}
			else //��currentsum>sum,���ȥbegin
			{
				currentsum = currentsum - begin;
				begin++;
			}
		}
		return result;
	}
}; 
int main()
{
	Solution s;
	vector<vector<int>>m=s.FindContinuousSequence(100);
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			cout << m[i][j] << "   ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
