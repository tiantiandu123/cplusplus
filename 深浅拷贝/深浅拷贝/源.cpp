#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
using namespace std;
//class String
//{
//public:
//	String(const char*pStr = "")
//		:_pStr(new char[strlen(pStr+1)])
//	{
//		strcpy(_pStr, pStr);
//	}
//	~String()
//	{
//		if (_pStr)
//		{
//			delete[]_pStr;
//			_pStr = NULL;
//		}
//	}
//private:
//	char*_pStr;
//};
//void Test()
//{
//	String s1("hello world");
//	String s2(s1);
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

class String
{
public:
	String(const char*str = " ") //构造函数
	{
		if (NULL == str)
		{
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else
			_pStr = new char[strlen(str) + 1];
		strcpy(_pStr, str);
		cout << "String" << endl;
	}
	String(const String&s)
		:_pStr(new char[strlen(s._pStr)] + 1)
	{
		strcpy(_pStr, s._pStr);
	}
	String&operator=(const String &s)
	{
		if (this != &s)
		{
			char* tmp = new char[strlen(s._pStr) + 1];//pstr;  
			delete[] _pStr;
			strcpy(tmp, s._pStr);
			_pStr = tmp;
		}
		return *this;
	}
	~String()
	{
		if (_pStr)
		{
			delete[]_pStr;
			_pStr = NULL;
		}
	}
	bool operator<(const String&s)
	{
		if (strcmp(_pStr, s._pStr) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(const String&s)
	{
		if (strcmp(_pStr, s._pStr)>0)
		{
			return true;
		}
		return false;
	}
	char operator[](int index)//下标
	{
		if (index > 0 && (index < strlen(_pStr)))
			return _pStr[index];
	}
	friend ostream&operator<<(ostream&_cout,const String&s);
	friend istream&operator>>(istream&_cin, const String&s);
private:
	char* _pStr;
};
ostream&operator<<(ostream&_cout, const String&s)
{
	_cout << s._pStr;
	return _cout;
}
istream&operator>>(istream&_cin, const String&s)
{
	_cin >> s._pStr;
	return _cin;
}
void Test()
{
	String s1("hello world")/*,s3*/;
	//String s2(s1);
	//s3 = "jello";//类型转换，此处调用了构造函数创建了一个临时对象
	String s2 = "hello";
}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
int main()
{
	int *p = new int[10];
}