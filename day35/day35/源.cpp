#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
//����һ�������ַ������������ֿ��Ա�ʾ�����п��ܵ���ĸ��ϡ����������һ�����ֵ���ĸ��ӳ��(�����ڵ绰��ť��һ��)�����룺�����ַ�����23������� ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string>res;
		int len = res.size();
		map<char, string>mymap;
		string temp = "";
		mymap['2'] = "abc";
		mymap['3'] = "def";
		mymap['4'] = "ghi";
		mymap['5'] = "jkl";
		mymap['6'] = "mno";
		mymap['7'] = "pqrs";
		mymap['8'] = "tuv";
		mymap['9'] = "wxyz";
		result(res, mymap, digits, temp);
		return res;
	}
	void result(vector<string>&res, map<char, string>&mymap, string digits, string temp)
	{
		int size = temp.size();
		if (size == digits.size())
		{
			res.push_back(temp);
		}
		for (int i = 0; i< mymap[digits[size]].size(); i++)
		{
			temp += mymap[digits[size]][i];
			result(res, mymap, digits, temp);
			temp.pop_back();
		}
	}
};
int main()
{
	Solution s;
	vector<string>ret = s.letterCombinations("23");
	vector<string>::iterator it;

	for (it = ret.begin(); it != ret.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;

}
//����һ���������У�дһ����������������ȷ��ʽ��������ϡ�
//���磬����n = 3��һ������������ǣ�
//"((()))", "(()())", "(())()", "()(())", "()()()"
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		36
	}
};