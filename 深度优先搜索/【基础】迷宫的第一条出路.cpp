/*
题目描述
已知一N×N的迷宫，允许往上、下、左、右四个方向行走，现请你按照左、上、右、下顺序进行搜索，找出第一条从左上角到右下角的路径。
输入
输入数据有若干行，第一行有一个自然数N（N≤20），表示迷宫的大小，其后有N行数据，每行有N个0或1（数字之间没有空格，0表示可以通过，1表示不能通过），用以描述迷宫地图。入口在左上角（1，1）处，出口在右下角（N，N）处。所有迷宫保证存在从入口到出口的可行路径。
输出
输出数据仅一行，为按照要求的搜索顺序找到的从入口到出口的第一条路径（搜索顺序：左、上、右、下）。
样例输入 Copy
4
0001
0100
0010
0110
样例输出 Copy
(1,1)->(1,2)->(1,3)->(2,3)->(2,4)->(3,4)->(4,4)
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=10000; 
int T,n,m,x,y,cnt=0,num,l;
string s1,s2;
int fx[5]={0,0,-1,0,1};
int fy[5]={0,-1,0,1,0};
char a[50][50];
int r[410][3];
int tx,ty;
 
void print(int k)
{
    for(int i=1;i<=k;i++)
    {
        cout<<"("<<r[i][1]<<","<<r[i][2]<<")";
        if(i!=k)
        {
            cout<<"->";
        }
    }
    exit(0);
}
 
void fun(int x,int y,int k)
{
    r[k][1]=x;
    r[k][2]=y;
     
    a[x][y]='1';
 
    if(x==n&&y==n)
    {
        print(k);
    }   
    int tx,ty;
    for(int i=1;i<=4;i++)
    {
        tx=x+fx[i];
        ty=y+fy[i];
        //没走过且没有障碍 
        if(a[tx][ty]=='0')
        {
            fun(tx,ty,k+1); 
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    fun(1,1,1);
    return 0;    
}
/**************************************************************
    Problem: 23862
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:2388 kb
****************************************************************/
