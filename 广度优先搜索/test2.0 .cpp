/*
题目描述
一个迷宫由R行C列格子组成，有的格子里有障碍物，不能走；有的格子是空地，可以走。
给定一个迷宫，求从左上角走到右下角最少需要走多少步(数据保证一定能走到)。只能在水平方向或垂直方向走，不能斜着走。
输入
第一行是两个整数，R和C，代表迷宫的行数和列数。（ 1<= R，C <= 40)
接下来是R行，每行C个字符，代表整个迷宫。空地格子用'.'表示，有障碍物的格子用'#'表示。迷宫左上角和右下角都是'.'。
输出
输出从左上角走到右下角至少要经过多少步（即至少要经过多少个空地格子）。计算步数要包括起点和终点。
样例输入 Copy
5 5
..###
#....
#.#.#
#.#.#
#.#..
样例输出 Copy
9
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=100; 
long long int n,m,s1,s2,e1,e2,x,y,cnt,head,tail;
char a[MX+10][MX+10],dp[MX+10][MX+10];
bool f[MX+10][MX+10];
int q[10100][4];
int fx[5]={0,0,1,0,-1};
int fy[5]={0,1,0,-1,0};
int tx,ty,k=1;
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
    head=1,tail=1;
    q[head][1]=1;
    q[head][2]=1;
    q[head][3]=k;
    f[1][1]=true;
    k++;
    while(head<=tail)
    {
        for(int i=1;i<=4;i++)
        {
            tx=q[head][1]+fx[i];
            ty=q[head][2]+fy[i];
            if(a[tx][ty]=='.'&&f[tx][ty]==false)
            {
                f[tx][ty]=true;
                a[tx][ty]='#';
                tail++;
                q[tail][1]=tx;
                q[tail][2]=ty;
                q[tail][3]=q[head][3]+1;
                if(tx==n&&ty==m)
                {
                    cout<<q[tail][3];
                    return 0;
                }
            }
        }
        head++;
    }
     
    return 0;    
}
/**************************************************************
    Problem: 23861
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:2416 kb
****************************************************************/