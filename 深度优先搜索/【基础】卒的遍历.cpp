/*
题目描述
在一张n*m的棋盘上（如6行7列）的最左上角（1,1）的位置有一个卒。该卒只能向下或者向右走，且卒采取的策略是先向下，下边走到头就向右，请问从（1,1）点走到（n,m）点可以怎样走，输出这些走法。



输入
两个整数n，m代表棋盘大小（3=<n<=8,3<=m<=8）
输出
卒的行走路线
样例输入 Copy
3 3
样例输出 Copy
1:1,1->2,1->3,1->3,2->3,3
2:1,1->2,1->2,2->3,2->3,3
3:1,1->2,1->2,2->2,3->3,3
4:1,1->1,2->2,2->3,2->3,3
5:1,1->1,2->2,2->2,3->3,3
6:1,1->1,2->1,3->2,3->3,3
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=10000; 
int T,n,m,cnt=0,num,l,mx=0,mn=INT_MAX;
int a[MX+10],s2[MX+10];
int fx[3]={0,1,0};
int fy[3]={0,0,1};
int r[20][3];
 
void print(int k)
{
    cnt++;
    cout<<cnt<<":";
    for(int i=1;i<k;i++)
    {
        cout<<r[i][1]<<","<<r[i][2]<<"->";
    }
    cout<<n<<","<<m<<'\n';
}
 
void fun(int x,int y,int k)
{
    r[k][1]=x;
    r[k][2]=y;
    if(x==n&&y==m)
    {
        print(k);
        return;
    }
    int tx,ty;
    for(int i=1;i<=2;i++)
    {
        tx=x+fx[i];
        ty=y+fy[i];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m)
        {
            fun(tx,ty,k+1);
        }
    }
}
 
 
int main()
{
    cin>>n>>m;
    fun(1,1,1);
      
    return 0;    
}
/**************************************************************
    Problem: 23863
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:2300 kb
****************************************************************/
