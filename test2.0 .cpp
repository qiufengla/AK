#include<bits/stdc++.h>
using namespace std;
const int MX=1e6;
int a[MX+10];
int T,n,m,i,cnt,sum;
string s,s1;
map<int,int>p;
int main()
{
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int left=1,right=n;
	while(left<=right)
	{
		sum=a[left]+a[right];
		if(left==right)
		{
			cnt++;
			break;
		}
		if(a[left]+a[right]<=m)
		{
			cnt++;
			left++;
			right--;
		}
		else
		{
			cnt++;
			right--;
		}
	}
	cout<<cnt<<'\n';
	return 0;
}