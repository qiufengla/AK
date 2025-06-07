/*
题目描述
设有N 个正整数（1 <= N <= 50），其中每一个均是大于等于1、小于等于300的数。
从这N个数中任取出若干个数（不能取相邻的数），要求得到一种取法，使得到的和为最大。
例如：当N=5时，有5个数分别为：13，18，28，45，21
此时，有许多种取法，如： 13，28，21 和为62
13, 45 和为58
18，45 和为63
……….

和为63应该是满足要求的一种取法
输入
第一行是一个整数N
第二行有N个符合条件的整数。
输出
一个整数，即最大和
样例输入 Copy
5
13 18 28 45 21
样例输出 Copy
63

*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=100000; 
int a[MX+10];
int dp[MX+10];
int vis[30],vistr[30];
int T,mx,n,x,sum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[1]=a[1];
    dp[2]=max(a[1],a[2]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    }
    cout<<dp[n];
    return 0;    
}
/**************************************************************
    Problem: 23888
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:3004 kb
****************************************************************/
