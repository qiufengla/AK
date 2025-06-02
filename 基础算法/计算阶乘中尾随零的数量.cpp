/*
题目描述
您的任务是计算阶乘 n！ 中尾随零的数量。
例如，20！=2432902008176640000 并且它有 4 个尾随 0。
输入
唯一的输入行有一个整数 n（1 ≤ n ≤ 109）.
输出
打印 n！ 中尾随零的数量。
样例输入 复制
20
样例输出 Copy
4
*/
#include<bits/stdc++.h>
using namespace std;
const int MX=1e5;
int T,n,m,cnt,c;
map<int,int>p;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin>>n;
	while(n>0)
	{
		n=n/5;
		cnt+=n;
	}
	cout<<cnt<<'\n';
	return 0;
}
/*
从 5 开始，每次将 n 除以 5，取整后累加到结果中，直到商为 0。
循环逻辑：通过不断将 n 除以 5，逐步计算[n/5],[n/25].... 等项。
该方法通过数学规律高效统计质因数 5 的个数，避免了直接计算阶乘（大数问题），是计算尾随零的最优解法。
*/
