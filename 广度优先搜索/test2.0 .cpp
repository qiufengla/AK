/*
题目描述
马在中国象棋以日字形规则移动，给定n*m大小的棋盘，以及马的初始位置(x，y)和目标位置（s，t），要求不能重复经过棋盘上的同一个点，计算马至少走多少步可以到达目标位置，所有棋盘保证从初始位置到结束位置一定有路径可达。
输入
测试数据包含一行，为六个整数，分别为棋盘的大小以及初始位置坐标nmxyst。（1≤x，s≤n≤5，1≤y，t≤m≤5）
输出
包含一行，为一个整数，表示马能到达目标位置的最小步数。
样例输入 Copy
3 3 1 1 1 3
样例输出 Copy
2

*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=1000; 
char a[MX+10][MX+10];
int q[1000010][4];
int n,m,tx,ty,k=1,s1,s2,e1,e2,cnt;
int head=1,tail=1;
int fx[9]={0,-1,-2,-2,-1,1,2,2,1};
int fy[9]={0,-2,-1,1,2,2,1,-1,-2};
bool f[MX+10][MX+10];
  
  
int main()
{
    cin>>n>>m>>s1>>s2>>e1>>e2;
      
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=0;
        }
    }
    q[1][1]=s1;
    q[1][2]=s2;
    q[1][3]=0;
    while(head<=tail)
    {
        for(int i=1;i<=8;i++)
        {
            tx=q[head][1]+fx[i];
            ty=q[head][2]+fy[i];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==0)
            {
                tail++;
                q[tail][1]=tx;
                q[tail][2]=ty;
                q[tail][3]=q[head][3]+1;
                a[tx][ty]=1;
                if(tx==e1&&ty==e2)
                {
                    cout<<q[tail][3];
                    return 0;
                }
            }
        }
        head++;
    }
    cout<<-1<<'\n';
    return 0;    
}
/**************************************************************
    Problem: 23884
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:19840 kb
****************************************************************/