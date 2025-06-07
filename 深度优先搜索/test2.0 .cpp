/*
题目描述
从键盘读入一个整数n（n<=6），请输出1~n中所有整数的全排列，按照由小到大输出结果，每组的n个数之间用空格隔开。
全排列的含义：从n个不同元素中任取m（m≤n）个元素，按照一定的顺序排列起来，叫做从n个不同元素中取出m个元素的一个排列。当m=n时所有的排列情况叫全排列。
如当n=3时，全排列的结果为：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
输入
一个整数n（n >= 1 && n <= 6）
输出
1~n中所有数的全排列的结果，按照由小到大输出，每行n个数
样例输入 Copy
3
样例输出 Copy
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
#include <bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
const int MX=10000; 
int T,n,m,cnt=0,num,l,mx=0,mn=INT_MAX;
int a[MX+10],s2[MX+10];
int fx[5]={0,0,1,0,-1};
int fy[5]={0,1,0,-1,0};
int r[20][3];
bool f[10];
 
void print()
{
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}
 
void fun(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(f[i]==false)
        {
            a[k]=i;
            f[i]=true;
            if(k==n)
            {
                print ();
            }
            else
            {
                fun(k+1);
            }
            f[i]=false;
        }
         
    }
}
 
 
int main()
{
    cin>>n;
    fun(1);
     
    return 0;    
}
/**************************************************************
    Problem: 23868
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:2300 kb
****************************************************************/