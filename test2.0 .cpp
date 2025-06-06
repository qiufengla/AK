/*
题目描述
有如下所示的数塔，要求从底层走到顶层，若每一步只能走到相邻的结点，则经过的结点的数字之和最大是多少？

输入
输入数据首先包括一个整数整数N(1 <= N <= 100)，表示数塔的高度，接下来用N行数字表示数塔，其中第i行有个i个整数，且所有的整数均在区间[0,99]内。
输出
从底层走到顶层经过的数字的最大和是多少？
样例输入 Copy
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
样例输出 Copy
30
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=100;
long long int a[MX+10][MX+10];
int main()
{
    ios::sync_with_stdio;
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
        }
    }
    cout<<a[1][1];
    return 0;
}
/**************************************************************
    Problem: 23801
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:2316 kb
****************************************************************/