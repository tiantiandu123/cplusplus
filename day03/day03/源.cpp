//1.在字符串中找出第一个只出现一次的字符
#include<iostream>
using namespace std;
#include<string>
char first(char*arr, int sz)
{
	const char*tmp = arr;//tmp指向arr
	 char str[256] = { 0 };//设置Ascii码0-255
	while (*tmp)
	{
		str[*tmp]++;
		tmp++;
	}
	tmp = arr;//又将tmp指向字符串首元素地址
	while (*tmp)
	{
		if (str[*tmp] == 1)
		{
			return *tmp;
		}
		tmp++;
	}
	return -1;
}
int main()
{
	char p[] = "asdfasdfo";
	int sz = strlen(p);
	printf("%c\n", first(p, sz));
	system("pause");
	return 0;
}