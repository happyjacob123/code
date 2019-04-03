#include<iostream>
using namespace std;

//通过计算，返回子串的next数组
void get_next(string t, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i<t.size() - 1)
	{
		if (j == 0 || t[i] == t[j])			//t[i]表示后缀的单个字符，t[j]表示前缀的单个字符
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];					//若字符不相同，则j值回溯
	}

}

//返回子串t在主串t中第pos个字符之后的位置；若不存在，函数返回0
//s[0]和t[0]应该保存字符串的长度，这里我们随意保存一个字符#

int Index_KMP(string s, string t, int pos = 1)	//默认从主串的第一个位置开始查找
{
	int i = pos;								//i用于表示主串s的当前位置
	int j = 1;									//j用于表示子串t的当前位置
	int next[255];								//定义一个next数组
	get_next(t, next);							//对串做分析，得到next数组
	while (i < s.size() && j < t.size())		//若i小于s的长度且j小于t的长度，循环继续
	{
		if (j == 0 || s[i] == t[j])				//两字符串相等，或j处于开始位，继续
		{
			i++;
			j++;
		}
		else									//j值退回合适的位置，i值不变
			j = next[j];
	}
	if (j >= t.size())
		return i - t.size() + 1;
	else
		return 0;
}

int main()
{
	string s = "#goodgoogle";
	string t = "#google";
	cout << Index_KMP(s, t) << endl;
	return 0;
}