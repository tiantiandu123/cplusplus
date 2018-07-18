#include<iostream>
#include<assert.h>
using namespace std;
void reverse(char*left, char*right)
{
	assert(left);
	assert(right);
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void str_reverse(char*str, int sz)
{
	assert(str);
	reverse(str, str + sz - 2);
	while (*str)
	{
		char*start = str;
		while (((*str) != ' ') && ((*str) != '\0'))
		{
			str++;
		}
		reverse(start, str - 1);
		if ((*str) != '\0')
		{
			str++;
		}
	}
}
int main()
{
	char arr[] = "I like beijing.";
	int sz = sizeof(arr) / sizeof(arr[0]);
	str_reverse(arr, sz);
	cout << arr << endl;
	system("pause");
	return 0;
}