#include <iostream>
#include <cmath>
#include <algorithm>//ͷ�ļ�
using namespace std;//���ֿռ�
int a[100100],b[100100];//�����������飬�ֱ𴢴�ÿ��ѧУ�ķ����ߣ���ÿ��ͬѧ�Ĺ���
int main()//������
{
	int n,m;//����n,m
	cin>>n>>m;//����
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];//����
	}
	for(int i=1; i<=m; i++)
	{
		cin>>b[i];//��������
	}
	sort(a+1,a+n+1);//��ÿ��ѧУ�ķ����ߴ�С��������
	int ans=0;//��һ��ʼΪ0����ΪҪ�ۼӺ͡�
	for(int i=1; i<=m; i++)
	{
		int l=0,r=n+1;//������߽����ұ߽�
		while(l<r)
		{
			int mid=(l+r)/2;//ȡ���ҷ�Χ���м�ֵ
			if(a[mid]<=b[i])//���¼ȡ�����������еĵ�mid��Ԫ��С�ڻ������λͬѧ�ķ���
			{
				l=mid+1;//��߽��������
			}
			else
			{
				r=mid;//�ұ߽��������
			}
		}
		if(b[i]<=a[1])//������Ҫ���ж�һ�£���Ȼֻ�ܵ�70��
		{
			ans+=a[1]-b[i];
		}
		else
		{
			ans+=min(abs(a[l-1]-b[i]),abs(a[l]-b[i]));//������������ֵ����С
		}
	}
	cout<<ans;//���ans
	return 0;//��������
}
