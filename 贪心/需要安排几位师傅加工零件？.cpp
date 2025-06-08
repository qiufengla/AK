/*题目描述
某工厂有n个零件加工的师傅，每位师傅每天能够加工出不同数量的零件。现有m个零件要求一天加工完，请问该工厂最少需要派几个师傅来完成这次零件加工任务，如果安排所有的师傅都参与加工也不能在一天内完成任务，请输出“NO”。（4.2.71）
输入
第一行有两个整数，用空格隔开；第一个整数代表要加工的总零件个数m（m<=10^6），第二个整数代表工厂的零件加工师傅的数量n（n<=100）。
第二行有n个整数，分别代表每个师傅每天能够加工出来的零件数量（每个师傅每天加工的零件数量<=10^4）。
输出
工厂在1天时间内加工所有零件需要的师傅数量或者输出NO。
样例输入 Copy
10 5
1 3 2 4 2
样例输出 Copy
4
*/
#include<bits/stdc++.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
int n,w,x,y=100,s=1;
const int MX=1e3;
int a[MX+10],b[1000100];
int main(){
    int n,m,s=0,cnt=0;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    } 
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        s+=a[i];
        cnt++;
        if(s>=m)
        {
            cout<<cnt<<'\n';
            break;
        }
    }
    if(s<m)
    {
        cout<<"NO"<<'\n';
    }
    return 0;
}
/**************************************************************
    Problem: 23835
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:6132 kb
****************************************************************/
