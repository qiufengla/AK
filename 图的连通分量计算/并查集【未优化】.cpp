#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MX=2e5;
ll n,m,op,x,y;
int pre[MX+10];
int root(int x)
{
    if(pre[x]==x)
    {
        return x;
    }
    else
    {
        return root(pre[x]);
    }
}

void merge(int x,int y)
{
    x=root(x),y=root(y);
    if(x==y) return;
    pre[x]=y;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        pre[i]=i;
    }
    while(m--)
    {
        cin>>op>>x>>y;
        if(op==1)
        {
            merge(x,y);
        }
        else
        {
            if(root(x)==root(y))
            {
                cout<<"Y"<<'\n';
            }
            else
            {
                cout<<"N"<<'\n';
            }
        }
    }
    return 0;
}

