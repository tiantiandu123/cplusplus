#include<iostream>
#include<vector>
using namespace std;
//int main()
//{
//	char s[] = "ABCD";
//	char*p;
//	for (p = s + 1; p < s + 4; p++)
//	{
//		printf("%s\n", p);
//	}
//	system("pause");
//	return 0;
//}
//int x(int n)
//{
//	int cnt = 0;
//	cnt++;
//	if (n < 3){
//		return 1;
//	}
//	else{
//		return x(n - 2) + x(n - 4) + 1;
//	}
//}
//int main()
//{
//	int ret = x(x(8));
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//定按升序排序的整数数组，找到给定目标值的开始和结束位置。 如果在数组中找不到目标，则返回[-1， - 1]。
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int>ret(2, -1);
		if (n == 0)
		{
			return ret;
		}
		int left = 0;
		int right = n - 1;
		while (left<right)
		{
			int mid = (left + right) >> 1;
			if (A[mid]<target)
			{
				left = mid + 1;
			}
			else{
				right = mid;
			}
		}
		if (A[left] != target)
		{
			return ret;
		}
		else{
			ret[0] = left;
		}
		int right = n - 1;
		while (left<right)
		{
			int mid = ((left + right) >> 1)+1;
			if (A[mid]>target)
			{
				right = mid - 1;
			}
			else{
				left = mid;
			}
		}
		if (A[right] == target)
		{
			ret[1] = right;
		}
		return ret;
	}
};

//给定一个排序数组和一个目标值，如果找到了目标，则返回索引。如果没有，返回如果按顺序插入索引的位置。您可以假定数组中没有重复项

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int left = 0;
		int right = n - 1;

		while (left<right)
		{
			int mid = (left + right) >> 1;
			if (A[mid]<target)
			{
				left = mid + 1;
			}
			else if (A[mid]>target)
			{
				right = mid - 1;
			}
			else
			{
				return mid;
			}
		}
		if (A[left] >= target)
		{
			return left;
		}
		else{
			return left + 1;
		}
	}
};