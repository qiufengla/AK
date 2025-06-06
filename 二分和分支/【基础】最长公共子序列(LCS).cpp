/*
题目描述
给出1-n的两个排列P1和P2，求它们的最长公共子序列。

输入
第一行是一个数n；（n是5~1000之间的整数）
接下来两行，每行为n个数，为自然数1-n的一个排列（1-n的排列每行的数据都是1-n之间的数，但顺序可能不同，比如1-5的排列可以是：1 2 3 4 5，也可以是2 5 4 3 1）。
输出
一个整数，即最长公共子序列的长度。
样例输入 Copy
5 
3 2 1 4 5
1 2 3 4 5
样例输出 Copy
3
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=1000; 
long long int n,m,l;
int a[MX+10],b[MX+10],dp[MX+10][MX+10];
int d[500];
int flag=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
     
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][n];
    return 0;    
}
/**************************************************************
    Problem: 23854
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:16 ms
    Memory:6216 kb
****************************************************************/
