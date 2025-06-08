/*
题目描述
有一个背包能装的重量maxw(正整数，0≤maxw≤20000)，同时有n件物品(0≤n≤100)，每件物品有一个重量wi(正整数)和一个价值pi(正整数)。要求从这n件物品中任取若干件装入背包内，使背包的物品价值最大。
输入
第1行：背包最大载重maxw，物品总数n
第2行到第n+1行：每个物品的重量和价值
输出
一个数字即背包内物品最大价值

样例输入 Copy
10 3
4 5
3 4
6 9
样例输出 Copy
14
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=100; 
long long int T,mx,m,n,x,sum=1,num=0,c,l=1;
long long int cnt=0,cnt1=0,k=1;
int a[MX+10],w[MX+10],v[MX+10],dp[MX+10][20100];
int main()
{
    cin>>c>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(w[i]<=j)
            {
                dp[i][j]=max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j]; 
            }
        }
    }
    cout<<dp[n][c];
    return 0;    
}
/**************************************************************
    Problem: 23890
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:6 ms
    Memory:10860 kb
****************************************************************/