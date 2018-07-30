#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
//给定一个数字字符串，返回数字可以表示的所有可能的字母组合。下面给出了一个数字到字母的映射(就像在电话按钮上一样)。输入：数字字符串“23”输出： ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
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
//给定一个括号序列，写一个函数用于生成正确形式的括号组合。
//例如，给定n = 3，一个解决方案集是：
//"((()))", "(()())", "(())()", "()(())", "()()()"
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		36
	}
};