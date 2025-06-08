/*
题目描述
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK，则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
输入
输入的第一行是一个整数N（2 <= N <= 100），表示同学的总数。
第一行有n个整数，用空格分隔，第i个整数Ti（130 <= Ti <= 230）是第i位同学的身高（厘米）。

输出
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

样例输入 Copy
8
186 186 150 200 160 130 197 220
样例输出 Copy
4
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=100000; 
int a[MX+10];
int dp[MX+10],dp1[MX+10];
int vis[30],vistr[30];
int T,mx,n,x,sum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    //  
    }
    for(int i=n;i>=1;i--)
    {
        dp1[i]=1;
        for(int j=n;j>i;j--)
        {
            if(a[j]<a[i])
            {
                dp1[i]=max(dp1[j]+1,dp1[i]);
            } 
        } 
    //  cout<<dp1[i]<<' ';
    }
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,dp[i]+dp1[i]-1);
    }
    cout<<n-mx;
    return 0;    
}
/**************************************************************
    Problem: 23889
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:3392 kb
****************************************************************/
