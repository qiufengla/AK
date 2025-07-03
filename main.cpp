#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,l,k,mx,cnt;
int main()
{
    cin>>s>>k;
    int l=s.size();
    for(int i=0;i<3;i++)
    {
        if(s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='u')
        {
//           cout<<s[i]<<' ';
            cnt++;
            mx=max(cnt,mx);
        }
    }
    // cout<<'\n';
    // cout<<mx<<'\n';
    for(int i=1;i<l-k+1;i++)
    {
        if(s[i-1]=='a'||s[i-1]=='o'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='u')
        {
            cnt--;
        }
        if(s[i+k-1]=='a'||s[i+k-1]=='o'||s[i+k-1]=='e'||s[i+k-1]=='i'||s[i+k-1]=='u')
        {
            cnt++;
        }
        mx=max(cnt,mx);
    }
    cout<<mx<<'\n';
    return 0;
}