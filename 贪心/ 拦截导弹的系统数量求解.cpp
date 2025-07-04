/*
题目描述
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。
假设某天雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。 
输入n个导弹依次飞来的高度（给出的高度数据是不大于30000的正整数），计算如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。 
比如：有8颗导弹，飞来的高度分别为
389  207  175  300  299  170  158  165      
那么需要2个系统来拦截，他们能够拦截的导弹最优解分别是：
系统1：拦截 389  207 175 170 158
系统2：拦截 300  299 165
输入
两行，第一行表示飞来导弹的数量n（n<=1000）
第二行表示n颗依次飞来的导弹高度
输出
要拦截所有导弹最小配备的系统数k
样例输入 Copy
8
389  207  175  300  299  170  158  165    
样例输出 Copy
2
*/
#include<bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
int n,w,x,y=100,s=1;
const int MX=1e3;
int a[MX+10],b[1000100];
/*
1.若没有系统可以进行拦截，则需要新开一套系统去拦截，可以引入一个cnt=0判断引入了几套系统 
2.若前面的系统可以拦截，则用靠前的系统进行相对应的拦截，同时更新他的高度；
3.则前面系统可以拦截的导弹高度一定比后面可拦截导弹系统的高度低一些
*/
int main(){
    int n,m,s=0,cnt=0,k=0,j;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        int p=-1;
        for(j=1;j<=k;j++)
        {
            if(a[j]>=m)
            {
                p=1;
                break;
            }
        }
        if(p==-1)
        {
            k++;
            a[k]=m;
        }
        else
        {
            a[j]=m;
        }
    }
    cout<<k;
     
    return 0;
}
/**************************************************************
    Problem: 23837
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:6132 kb
****************************************************************/
