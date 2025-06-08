/*
题目描述
学校在最近几天有n（n<=100）个活动，这些活动都需要使用学校的大礼堂，在同一时间，礼堂只能被一个活动使。由于有些活动时间上有冲突，学校办公室人员只好让一些活动放弃使用礼堂而使用其他教室。
现在给出n个活动使用礼堂的起始时间begini和结束时间endi(begini < endi)，请你帮助办公室人员安排一些活动来使用礼堂，要求安排的活动尽量多。请问最多可以安排多少活动？
请注意，开始时间和结束时间均指的是某个小时的0分0秒，如：3 5，指的是3:00~5:00，因此3 5和5 9这两个时间段不算冲突的时间段。

输入
第一行一个整数n(n<=100)

接下来的n行，每行两个整数，第一个begini，第二个是endi(begini< endi  <=32767)


输出
输出最多能安排的活动数
样例输入 Copy
11
3 5
1 4
12 14
8 12
0 6
8 11
6 10
5 7
3 8
5 9
2 13
样例输出 Copy
4
*/
#include<bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
int n,w,x,y=100,s=1;
const int MX=2e5;
long long int b[MX+10];
 
struct p
{
    int start;
    int end;
}a[MX+10];
 
bool cmp(p a,p b)
{
    return a.end<b.end;
     
}
int main(){
    int n,cnt=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].start>>a[i].end;
    }
    sort(a+1,a+n+1,cmp);//已设置完毕 
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i].end<=a[j].start)
            {
                cnt++;
                i=j;
            }
        } 
    }
    cout<<cnt;
    return 0;
}
/**************************************************************
    Problem: 23838
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:5348 kb
****************************************************************/