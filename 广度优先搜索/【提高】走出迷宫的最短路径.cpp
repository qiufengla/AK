/*
题目描述
有n*m的迷宫，该迷宫有一个入口，一个出口。编写一程序打印一条从迷宫入口到出口的最短路径，黑色方块的单元表示走不通（用1表示），白色方块的内容表示走的通（用0表示）
只能往上下左右四个方向走，如果有最短路径，保证最短路径一定是唯一的，如果没有路径可以到达，则输出“no way”。
输入
第一行输入2个整数n和m(n和m都是10~150之间的整数)，代表迷宫的行数和列数
接下来n行，每行有m个整数，1代表不可走的点，0代表可走的点
接下来一行，有2个整数s1和s2代表入口的坐标
接下来一行，有2个整数e1和e2代表出口的坐标
输出
输出从入口到出口的最短路径，如果没有路径可达输出“no way”
样例输入 Copy
8 5      
1 1 1 1 1  
0 0 0 0 1
1 1 1 0 1
1 0 0 0 1
1 0 0 1 1
1 0 0 0 1
1 1 1 0 1
1 0 0 0 1
2 1  
8 4
样例输出 Copy
(2,1)->(2,2)->(2,3)->(2,4)->(3,4)->(4,4)->(4,3)->(5,3)->(6,3)->(6,4)->(7,4)->(8,4)

*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=150; 
int a[MX+10][MX+10];
int q[2500][4];
int n,m,tx,ty,k=1,s1,s2,e1,e2;
int head=1,tail=1;
int fx[5]={0,0,1,0,-1};
int fy[5]={0,1,0,-1,0};
bool f[MX+10][MX+10];
 
void print(int k)
{
    if(q[k][3]!=0)
    {
        print(q[k][3]);
    }
    cout<<"("<<q[k][1]<<","<<q[k][2]<<")";
    if(k!=tail)
    {
        cout<<"->";
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
    cin>>s1>>s2>>e1>>e2;
    q[1][1]=s1;
    q[1][2]=s2;
    q[1][3]=0;
    while(head<=tail)
    {
        for(int i=1;i<=4;i++)
        {
            tx=q[head][1]+fx[i];
            ty=q[head][2]+fy[i];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==0)
            {
                a[tx][ty]=1;
                tail++;
                q[tail][1]=tx;
                q[tail][2]=ty;
                q[tail][3]=head;
                if(tx==e1&&ty==e2)
                {
                    print(tail);
                    return 0;
                }
            }
        }
        head++;
    }
    cout<<"no way"<<'\n';
    return 0;    
}
/**************************************************************
    Problem: 23885
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:3 ms
    Memory:2384 kb
****************************************************************/
