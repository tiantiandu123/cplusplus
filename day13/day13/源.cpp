#include <iostream>

using namespace std;
//������{2,3,1,0,2,5,3}Ϊ���������ҵ��ظ����ֵĲ��衣����ĵ� 0 �����֣��� 0 ��ʼ��������������±걣��һ�£��� 2���������±겻��ȣ����ǰ������±�Ϊ 2 ������ 1 ����������֮���������{1.3.2.0.2.5.3}����ʱ�� 0 �������� 1����Ȼ�������±겻��ȣ������������±�Ϊ 1 ������ 3 �������õ�����{3,1,2,0,2,5,3}.���������������� 0 ������ 3 �͵� 3 ������ 0���õ�����{0,1,2,3,2,5,3}����ʱ�� 0 �����ֵ���ֵΪ 0������ɨ����һ�����֡��ڽ������ļ��������У��±�Ϊ 1��2��3 ���������ֱַ�Ϊ 1��2��3 ���ǵ��±����ֵ���ֱ���ȣ���˲���Ҫ���κβ�����������ɨ�赽�±�Ϊ 4 ������ 2������������ֵ�������±겻��ȣ��ٱȽ������±�Ϊ 2 �����֡�ע�⵽��ʱ�������±�Ϊ 2 ������Ҳ�� 2��Ҳ�����������±�Ϊ 2 ���±�Ϊ 4 ������λ�ö������ˣ�����ҵ�һ���ظ������֡�
bool duplicate(int numbers[], int length, int* duplication){
	if (numbers == NULL || length <= 1){
		duplication = NULL;
		return false;
	}

	for (int i = 0; i<length; i++){
		while (numbers[i] != i){
			if (numbers[i] == numbers[numbers[i]]){
				*duplication = numbers[i];
				return true;
			}
			int tmp = numbers[i];
			numbers[i] = numbers[tmp];
			numbers[tmp] = tmp;
		}
	}

	return false;
}

int main()
{
	int A[] = { 2, 3, 1, 0, 2, 5, 3 };
	int len = sizeof(A) / sizeof(A[0]);

	int duplication;
	cout << duplicate(A, len, &duplication) << endl;
	cout << duplication << endl;
	system("pause");
	return 0;
}