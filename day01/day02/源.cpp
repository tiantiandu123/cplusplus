#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class Replacement{
public:
	string ReplaceSpace(string &iniString, int length)
	{
		if (length <= 0){
			return 0;
		}
		int count = 0;
		//ͳ���ַ����еĿո�ĸ���
		for (int i = 0; i < length; i++)
		{
			if (iniString[i] == ' ')
			{
				count++;
			}
		}
		//�µ��ַ����ĳ���
		int newLength = length + count * 2;
		if (newLength == length)
		{
			return 0;
		}
		int oldindex = length - 1;
		int newindex = newLength - 1;
		//���ַ����ĳ������ݵ��µĴ�С
		iniString.resize(newLength);
		while (oldindex >= 0 && newindex > oldindex)
		{
			if (iniString[oldindex] == ' ')
			{
				iniString[newindex--] = '0';
				iniString[newindex--] = '2';
				iniString[newindex--] = '%';
			}
			else
			{
				iniString[newindex--] = iniString[oldindex];
			}
			oldindex --;
			
		}
		return iniString;
	}
};
int main()
{
	string str = "Hello world ";
	int length = str.size();
	Replacement r;
	r.ReplaceSpace(str, length);
	cout << str << endl;
	system("pause");
	return 0;
}
