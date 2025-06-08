/*题目描述
小明是查字典高手，每次都能快速查找到自己不会的单词。这一天，小明在路上捡到了好几本字典，打开一看，发现这些字典中，字母的顺序和常规的不样。
他很好奇，如果有两个不同的字符串s和t，他想知道哪个字符串在当前这本字典中的字典序更小。
设字符串s 长度为n,字符串t长度为m,其中s= S0S1..Sn-1,t= t0t1....tm-1。
对于字典序的解释:当且仅当满足以下条件之一时，称字符串s的字典序比字符串t更小:找到最小的正整数<k(0 ≤k<min(n,m))，使得 Sk≠tk。若 Sk<tk，则序列 s的字典序小于 t。
若不存在这样的 k，则当 n<m 时序列 s 的字典序小于 t。
输入
第一行包含两个正整数 n，m ，分别代表字符串 s,t 的长度。
第二行有两个仅包含小写字母的字符串 s,t。
第三行输入一个正整数T ，代表有T 本字典。
接下来有T 行数据，第 i行数据包含一个长度为 26 的仅包含小写字母的字符串 Di，代表第 i 本字典中的字符字符顺序。
输出
第i行输出一个字母。
若s字典序小于t，则输出s;否则输出t。
数据保证不会出现字典序相同的情况。
样例输入 Copy
【样例1】
4 4
adeg
abah
2
abcdefghijklmnopqrstuvwxyz
zyxwvutsrqponmlkjihgfedcba
【样例2】
3 4
abc
abcd
2
abcdefghijklmnopqrstuvwxyz
zyxwvutsrqponmlkjihgfedcba
【样例3】
5 5
ypdmz
ypdms
3
dbvygoufzamnphlsjcxewtrikq
ntsdkjbuhefozpwyirmcqgxlav
jswtzbriyfpvqmkunglhxodeca
样例输出 Copy
【样例1】
t
s
【样例2】
s
s
【样例3】
s
t
t
提示
对于 30%的数据，字符串s,t的长度不超过 100。
对于 100%的数据，1≤T≤10 ，字符串 s,t 的长度不超过 105。
*/
#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,l1,l2,k1,k2,mx;
string s,t,s1;
int main()
{
    cin>>n>>m;
    cin>>s>>t;
    cin>>T;
    mx=max(n,m);
    for(int i=0;i<mx;i++)
    {
        if(s[i]!=t[i])
        {
            k=i;
            break;
        }
    }
    if(s[k]==' ')
    {
        cout<<"s"<<'\n';
        return 0;
    }
    else if(t[k]==' ')
    {
        cout<<"t"<<'\n';
        return 0;
    }
    while(T--)
    {
        getchar(); 
        cin>>s1;
        int l=s1.size();
        for(int i=0;i<l;i++)
        {
            if(s1[i]==s[k])
            {
                k1=i;
            }
            if(s1[i]==t[k])
            {
                k2=i;
            }
        }
        if(k1<k2)
        {
            cout<<"s"<<'\n';
        }
        else
        {
            cout<<"t"<<'\n';
        }
        s1.clear();
    }
    return 0;
}
/**************************************************************
    Problem: 24256
    User: 2024JK070430
    Language: C++
    Result: 正确
    Time:3 ms
    Memory:2600 kb
****************************************************************/
