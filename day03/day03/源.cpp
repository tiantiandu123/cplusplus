//1.���ַ������ҳ���һ��ֻ����һ�ε��ַ�
#include<iostream>
using namespace std;
#include<string>
char first(char*arr, int sz)
{
	const char*tmp = arr;//tmpָ��arr
	 char str[256] = { 0 };//����Ascii��0-255
	while (*tmp)
	{
		str[*tmp]++;
		tmp++;
	}
	tmp = arr;//�ֽ�tmpָ���ַ�����Ԫ�ص�ַ
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