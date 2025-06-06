/*
题目描述
给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。
输入
第一行包含整数N。
第二行包含N个整数，表示完整序列。
1≤N≤100000，−109≤数列中的数≤109
输出
输出一个整数，表示最大长度。
样例输入 Copy
6
1 3 2 8 5 6
样例输出 Copy
4
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=100000; 
long long int n,m,l,r,mid,T,x,y,t=0,k=1,sum=0,num,cnt;
int a[MX+10],dp[MX+10];
int d[500];
int flag=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[1]=a[1];
    int len=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>dp[len])
        {
            len++;
            dp[len]=a[i];
        }
        else
        {
            l=1;
            r=len;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(a[i]<=dp[mid]) r=mid-1;
                else l=mid+1;
            }
            dp[l]=a[i];
        }
    }
    cout<<len;
    return 0;    
}
/**************************************************************
    Problem: 23853
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:30 ms
    Memory:3004 kb
****************************************************************/