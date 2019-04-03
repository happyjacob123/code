#include<iostream>
using namespace std;

//ͨ�����㣬�����Ӵ���next����
void get_next(string t, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i<t.size() - 1)
	{
		if (j == 0 || t[i] == t[j])			//t[i]��ʾ��׺�ĵ����ַ���t[j]��ʾǰ׺�ĵ����ַ�
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];					//���ַ�����ͬ����jֵ����
	}

}

//�����Ӵ�t������t�е�pos���ַ�֮���λ�ã��������ڣ���������0
//s[0]��t[0]Ӧ�ñ����ַ����ĳ��ȣ������������Ᵽ��һ���ַ�#

int Index_KMP(string s, string t, int pos = 1)	//Ĭ�ϴ������ĵ�һ��λ�ÿ�ʼ����
{
	int i = pos;								//i���ڱ�ʾ����s�ĵ�ǰλ��
	int j = 1;									//j���ڱ�ʾ�Ӵ�t�ĵ�ǰλ��
	int next[255];								//����һ��next����
	get_next(t, next);							//�Դ����������õ�next����
	while (i < s.size() && j < t.size())		//��iС��s�ĳ�����jС��t�ĳ��ȣ�ѭ������
	{
		if (j == 0 || s[i] == t[j])				//���ַ�����ȣ���j���ڿ�ʼλ������
		{
			i++;
			j++;
		}
		else									//jֵ�˻غ��ʵ�λ�ã�iֵ����
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