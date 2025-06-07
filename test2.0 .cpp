/*
题目描述
一矩形阵列由数字0到9组成,数字1到9代表细胞,细胞的定义为沿细胞数字上下左右若还是细胞数字则为同一细胞,求给定矩形阵列的细胞个数。（1<=m,n<=100）?
输入
整数m,n(m行，n列)
接下来m行，每行有n个0~9之间的整数
输出
细胞的个数
样例输入 Copy
4  10
0234500067
1034560500
2045600671
0000000089
样例输出 Copy
4
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=1e2;
char a[MX+10][MX+10];
int fx[5]={0,1,-1,0,0};
int fy[5]={0,0,0,1,-1};
bool flag=false;
int tx,ty;
int t,n,p,b1,b2,e1,e2,cnt=0,sum=INT_MAX,m;
void fun(int x,int y)
{
     
    a[x][y]='0';
    for(int i=1;i<=4;i++)
    {
        tx=x+fx[i];
        ty=y+fy[i];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]!='0')
        {
            fun(tx,ty);
        }
    }
}
int main() 
{
     
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
             
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!='0')
            {
                cnt++;
                fun(i,j);
            } 
        }
    }
    cout<<cnt;
    return 0;
}
/**************************************************************
    Problem: 23860
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:3 ms
    Memory:2380 kb
****************************************************************/