#include<bits/stdc++.h>
using namespace std;
const int MX=1e6;
const int NX=1e6;
long long int a[MX+10],b[MX+10],v[NX+10][NX+10];
int f,g;
long long int k,n,m,cnt=1,x,y,z,M,xx,yy,num1,num2,k1,k2,q;
int main()
{
	cin>>M;         //表示的是其对打的总轮数
    cin>>n>>m;      //代表的是两个人出拳的周期；
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    v[0][2]=1,v[0][3]=1,v[1][3]=1,v[2][4]=1,v[3][4]=1;
    v[2][0]=1,v[3][0]=1,v[3][1]=1,v[4][2]=1,v[4][3]=1;
    for(int k=1;k<=M;k++)
    {
        xx=k%n;
        if(xx==0)
        {
            xx=n;
        }
        x=a[xx];

        yy=k%m;
        if(yy==0)
        {
            yy=m;
        }
        y=b[yy];

        num1+=v[x][y];
        num2+=v[x][y];
    }
    cout<<num1<<' '<<num2;
    return 0;
}
