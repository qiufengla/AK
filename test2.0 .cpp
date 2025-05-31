/*
题目描述
实现一个算法来压缩一个字符串。压缩的要求如下：

需要判断压缩能不能节省空间，仅在压缩后字符串比原字符串长度更短时进行压缩。

压缩的格式是将连续相同字符替换为字符 + 数字形式，例如 "AAABCCDDDD" 变为 "A3BC2D4"。

输入描述
输入一行字符串，长度不超过 500.

输出描述
输出一行。若输入的字符串可压缩，则输出压缩后的字符串，否则输出 NO。

输入输出样例
示例
输入

AAABCCDDDD
copy
输出

A3BC2D4
copy
运行限制
最大运行时间：1s
最大运行内存: 256M
总通过次数: 13388  |  总提交次数: 15978  |  通过率: 83.8%

难度: 简单   标签: 新手


*/


#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>//头文件
using namespace std;
const int MX=100000;
string s,t;
int cnt,n,len;
map<char,int>p;
map<char,int>q;
int main()
{
	cin>>s;
	int l=s.size();
	cnt=1;
	for(int i=1;i<l;i++)
	{
		if(s[i]==s[i-1])
		{
			cnt++;
		}
		else
		{
			//cout<<s[i-1];
			len++;
			if(cnt!=1)
			{
			//	cout<<cnt;
				len++;
			}
			cnt=1;
		}
	}
	len++;
	if(len!=1)
	{
		len++;
	}
	if(len>=l)
	{
		cout<<"NO"<<'\n'; 
	}
	else
	{
		cnt=1;
		for(int i=1;i<l;i++)
		{
			if(s[i]==s[i-1])
			{
				cnt++;
			}
			else
			{
				cout<<s[i-1];
				len++;
				if(cnt!=1)
				{
					cout<<cnt;
					len++;
				}
				cnt=1;
			}
		}
		cout<<s[l-1]<<cnt;
	}
	
	return 0;
} 