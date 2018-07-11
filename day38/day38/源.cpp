#include<iostream>
using namespace std;
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//假设f(n)是n个台阶跳的次数。

//f(1) = 1
//
//f(2) 会有两个跳得方式，一次1阶或者2阶，这回归到了问题f(1), f(2) = f(2 - 1) + f(2 - 2)
//
//f(3) 会有三种跳得方式，1阶、2阶、3阶，那么就是第一次跳出1阶后面剩下：f(3 - 1); 第一次跳出2阶，剩下f(3 - 2)；第一次3阶，那么剩下f(3 - 3).因此结论是
//f(3) = f(3 - 1) + f(3 - 2) + f(3 - 3)
//
//f(n)时，会有n中跳的方式，1阶、2阶...n阶，得出结论：
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
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
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