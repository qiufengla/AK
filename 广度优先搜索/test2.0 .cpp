/*
题目描述
Leyni是一个地址调查员，有一天在他调查的地方突然出现个泉眼。由于当地的地势不均匀，有高有低，他觉得如果这个泉眼不断的向外溶出水来，这意味着这里在不久的将来将会一个小湖。水往低处流，凡是比泉眼地势低或者等于的地方都会被水淹没，地势高的地方水不会越过。而且又因为泉水比较弱，当所有地势低的地方被淹没后，水位将不会上涨，一直定在跟泉眼一样的水位上。
由于Leyni已经调查过当地很久了，所以他手中有这里地势的详细数据。所有的地图都是一个矩形，并按照坐标系分成了一个个小方格，Leyni知道每个方格的具体高度。我们假定当水留到地图边界时，不会留出地图外，现在他想通过这些数据分析出，将来这里将会出现一个多大面积的湖。
输入
有若干组数据，每组数据的第一行有四个整数n,m,p1,p2(0<=1000)，n和m表示当前地图的长和宽，p1和p2表示当前地图的泉眼位置，即第p1行第p2列，随后的n行中，每行有m个数据。表示这每一个对应坐标的高度。
输出
输出对应地图中会有多少个格子被水充满。
样例输入 Copy
3 5 2 3
3 4 1 5 1
2 3 3 4 7
4 1 4 1 1
样例输出 Copy
6
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=100; 
long long int n,m,s1,s2,x,y;
int a[MX+10][MX+10],dp[MX+10][MX+10];
bool f[MX+10][MX+10];
int q[10100][3];
int fx[5]={0,0,1,0,-1};
int fy[5]={0,1,0,-1,0};
int tx,ty,k=1;
int main()
{
    cin>>n>>m>>s1>>s2;
    int head=1,tail=1;
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
            if(i==s1&&j==s2)
            {
                x=i;
                y=j;
                q[head][1]=x;
                q[head][2]=y;
                f[x][y]=true;
                while(head<=tail)
                {
                    for(int k=1;k<=4;k++)
                    {
                        tx=q[head][1]+fx[k];
                        ty=q[head][2]+fy[k];
                        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]<=a[x][y]&&f[tx][ty]==false)
                        {
                            tail++;
                            q[tail][1]=tx;
                            q[tail][2]=ty;
                            f[tx][ty]=true;
                        }
                    }
                    head++;
                }
            }
        }
    }
    cout<<tail;
     
    return 0;    
}
/**************************************************************
    Problem: 23882
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:3 ms
    Memory:2448 kb
****************************************************************/