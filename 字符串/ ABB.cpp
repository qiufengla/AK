/*
题目描述
给出一个长度为n的字符串，字符串中只包含小写字母a,b,c,...,z。
定义一个ABB式的子串为：三个连续的字符，第一个字符和第二个字符不同，第二个字符和第
三个字符相同。如，"acc","nee"。
AiBiBi与AjBjBj不同，当且仅当Ai≠Aj或Bi≠Bj，如：
"bcc"与"add"是两个不同的串；
"acc" 与"bcc"是两个不同的串；
"aee"与"acc"是两个不同的串。
请你统计给出的字符串中包含有多少个不同的 ABB 式的子串。
输入
输入共两行。
第一行输入一个数字n，表示字符串的长度.
第二行输入一个长度为n的字符串。
输出
输出一个数字，表示有多少个不同的 ABB 式的子串。
样例输入 Copy
【样例1】
11
abbccccdadd
【样例2】
3
aaa
【样例3】
6
abbabb
样例输出 Copy
【样例1】
3
【样例2】
0
【样例3】
1
提示
样例1解释：给出的字符串中包含的ABB式的子串是：abb,bcc,add。


对于 20% 的数据，字符串中没有相同的ABB式子串；
对于 100% 的数据， 3 ≤ n ≤ 20000。
*/
#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,total,x,y,cnt;
string s,t,s1;
bool a[30][30]={false};
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<=n-3;i++)
    {
        if(s[i]!=s[i+1]&&s[i+1]==s[i+2])
        {
            x=s[i]-'a';
            y=s[i+1]-'a';
            if(a[x][y]==false)
            {
                a[x][y]=true;
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
    return 0;
}
/**************************************************************
    Problem: 24259
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:2364 kb
****************************************************************/
