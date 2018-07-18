class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if ((str == NULL) || (pattern == NULL))
		{
			return false;
		}
		return match1(str, pattern);
	}
	bool match1(char* str, char* pattern)
	{
		//1.若开始变为\0
		if ((*str == '\0') && (*pattern == '\0'))
		{
			return true;
		}
		//2.
		if ((*str != '\0') && (*pattern == '\0'))
		{
			return false;

		}
		if (*(pattern + 1) == '*')
		{
			if (*pattern == *str || (*pattern == '.'&&*str != '\0'))
			{
				return match1(str + 1, pattern + 2) || match1(str + 1, pattern) || match1(str, pattern + 2);
			}
			else
			{
				return match1(str, pattern + 2);
			}
		}
		if (*str == *pattern || ((*pattern == '.') && (*str != '\0')))
		{
			return match1(str + 1, pattern + 1);
		}
		return false;

	}
};