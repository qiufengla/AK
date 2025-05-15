#include<bits/stdc++.h>
using namespace std;

const int MX=1e6;
string s,t1,t2; 
int n,m,cnt,num,sum,x,k; 
int jh,j,yh,y,num1,num2;
int a[MX+10],b[MX+10],c[MX+10];
map<string,long long int>p;
int main()
{
	while(cin>>s)
	{
		k++;
		if(k==2)
		{
			t1=s;
		}
		if(k==14)
		{
			t2=s;
		}
	}
	if(k>=14)
	{
		cout<<t1<<" and "<<t2<<" are inviting you to dinner..."<<'\n';
	}
	if(k>=2&&k<14)
	{
		cout<<t1<<" is the only one for you..."<<'\n';
	}
	if(k<2)
	{
		cout<<"Momo... No one is for you ..."<<'\n';
	}
    return 0;
}
