//union myun
//{
//	struct{
//		int x, y, z;
//	}u;
//	int k;
//}a;
//int main()
//{
//	a.u.x = 4;
//	a.u.y = 5;
//	a.u.z = 6;
//	a.k = 0;
//	printf("%d\n", a.u.x);
//	system("pause");
//	return 0;
//}
//struct Fun
//{
//	int : 2;
//	int b : 4;
//	int c : 5;
//	int d : 6;
//}fun;
//int main()
//{
//	int ret = sizeof(Fun);
//	cout << "ret = " << ret << "\n" << endl;
//	system("pause");
//	return 0;
//
//}
//union Fun
//{
//	int a[7];
//	char b[9];
//	double c;
//	short d[4];
//}fun;
//int main()
//{
//	int ret = sizeof(fun);
//	cout << "ret = " << ret << "\n" << endl;
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;
////2.��һ���ַ���ת��������
//int StrToInt(const char*str)
//{
//	int num = 0;
//	if (str != NULL)
//	{
//		const char*arr = str;
//		if (*arr == '+')
//		{
//			arr++;
//		}
//		else if (*arr == '-')
//		{
//			arr++;
//		}
//		while (*arr != '\0')
//		{
//			if (*arr >= '0'&& *arr <= '9')
//			{
//				num = num * 10 + (*arr - '0');
//				arr++;
//			}
//			else
//			{
//				num = 0;
//				break;
//			}
//		}
//	}
//	return num;
//}
//int main()
//{
//	const char arr[] = "+2147483";
//	cout << StrToInt(arr) << endl;
//	system("pause");
//	return 0;
//}
//2.����һ���ַ��������ַ����е�ĳһ��λ�ã����һ���㷨��������iλ�����ڵ���ಿ���ƶ����Ҳ࣬���Ҳಿ���ƶ������
class StringRotation {
public:
	string rotateString(string A, int n, int p) {
		return A.substr(p + 1) + A.substr(0, p + 1);
	}
};
int main()
{
	StringRotation s;
	string A = "ABCDEFGH";
	int n = 8;
	int p = 4;
	cout << s.rotateString(A, n, p) << endl;
	system("pause");
	return 0;
}