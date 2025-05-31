/*
题目描述
有 n 个孩子想去摩天轮，你的任务是为每个孩子找到一个吊舱。
每个吊舱中可以有一个或两个孩子，此外，吊舱中的总重量不得超过 x。你知道每个孩子的体重。
儿童所需的最低缆车数量是多少？
输入
第一行输入包含两个整数 n（1≤ n≤ 2 * 105） 和 x（1≤ x≤ 109）：子项的数量和允许的最大重量。
下一行包含 n 个整数 p1，p2,...,pn（1≤ pi≤ x）：每个子项的权重。
输出
打印一个整数：吊舱的最小数量。
样例输入 复制
4 10
7 2 3 9
样例输出 Copy
3

*/



/*
方法思路
排序体重：首先将所有孩子的体重从小到大排序，这样可以方便后续的双指针操作。

双指针配对：使用两个指针，一个指向最轻的孩子（左指针），另一个指向最重的孩子（右指针）。

贪心配对：

如果最轻和最重的孩子体重之和不超过限制，则将他们配对放入一个吊舱，同时移动左右指针。

如果体重之和超过限制，则最重的孩子单独使用一个吊舱，只移动右指针。

计数吊舱：每次配对或单独放置都会增加吊舱计数，直到所有孩子都被安排。

*/
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
