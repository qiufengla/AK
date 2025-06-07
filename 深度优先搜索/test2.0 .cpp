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
const int MX=10000; 
int T,n,m,x,y,cnt=0,num,l;
string s1,s2;
int fx[9]={0,0,1,0,-1,1,-1,1,-1};
int fy[9]={0,1,0,-1,0,1,-1,-1,1};
char a[50][50];
int b[50][50];
int tx,ty;
void fun(int x,int y,int dep)
{
    b[x][y]=dep;
    for(int i=1;i<=4;i++)
    {
        tx=x+fx[i];
        ty=y+fy[i];
        if(a[tx][ty]=='.'&&b[tx][ty]>dep+1)
        {
            fun(tx,ty,dep+1);
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            b[i][j]=INT_MAX;
        }
    }
    fun(1,1,1);
    cout<<b[n][m];
    return 0;    
}
/**************************************************************
    Problem: 23861
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:2392 kb
****************************************************************/