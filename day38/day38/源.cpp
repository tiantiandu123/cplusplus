#include<iostream>
using namespace std;
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
//����f(n)��n��̨�����Ĵ�����

//f(1) = 1
//
//f(2) �����������÷�ʽ��һ��1�׻���2�ף���ع鵽������f(1), f(2) = f(2 - 1) + f(2 - 2)
//
//f(3) �����������÷�ʽ��1�ס�2�ס�3�ף���ô���ǵ�һ������1�׺���ʣ�£�f(3 - 1); ��һ������2�ף�ʣ��f(3 - 2)����һ��3�ף���ôʣ��f(3 - 3).��˽�����
//f(3) = f(3 - 1) + f(3 - 2) + f(3 - 3)
//
//f(n)ʱ������n�����ķ�ʽ��1�ס�2��...n�ף��ó����ۣ�
//
//f(n) = f(n - 1) + f(n - 2) + ... + f(n - (n - 1)) + f(n - n) = > f(0) + f(1) + f(2) + f(3) + ... + f(n - 1) == f(n) = 2 * f(n - 1)
int jumpFloorII(int number) {
	if (number == 0){
		return 0;

	}
	if (number == 1){
		return 1;
	}
	return  2 * jumpFloorII(number - 1);
}
int main()
{
	int ret = jumpFloorII(5);
	cout << ret << endl;
	system("pause");
	return 0;
}
//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for (int i = 0; i<32; i++)
		{
			if ((n >> i) & 1 == 1)
			{
				count++;
			}
		}
		return count;
	}
};