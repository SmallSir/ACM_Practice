#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include<stack>
#include <ctime>
using namespace std;
typedef long long LL;

int check[105],low[105];
vector<int> tu[105];
int index,instack[105],ans[105],a[105],fllow[105],sum;
stack<int> st;
int inn[105],outt[105];
//check[u]�����ʾ�ڵ�u�����Ĵ�����ʱ�����low[u]Ϊu��׷�ݵ��������ʱ���
void tarjan(int x)
{
	check[x]=low[x]=++index;//��ʼ���������Ľڵ�x
	st.push(x);//��x�������ǿ��ͨ������ջ��
	instack[x]=1;//x���Ƿ���ջ��
	for(int i = 0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		if(!check[k])
		{
			tarjan(k);
			low[x]=min(low[x],low[k]);//�Ƚϵ�ǰ��x�ܹ����������ʱ����������������еĵ������ʱ����Ƚ�
		}
		else
		{
			if(instack[k])//���xΪ������������K��ջ��
			{
				low[x]=min(low[x],check[k]);//�Ƚ�k��ʱ�����С
			}
		}
	}
	if(check[x]==low[x])//x��Ϊ���ڵ�
	{
		sum++;
		int k=0;
		while(k!=x)//ֱ����������ǰ����Щ�㶼��ǿ��ͨ����
		{
			k=st.top();
			st.pop();
			fllow[k]=sum;//����Щ�������б��
			instack[k]=0;
			ans[sum]=x;
		}
	}
}
int main()
{
	int i,n,x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(;;)
		{
			cin>>x;
			if(x==0)
				break;
			tu[i].push_back(x);
			a[x]++;//
		}
	}
	int cnt=0;
	index=0;
	for(i=1;i<=n;i++)
		if(!check[i])//���ڶ��ͼ
			tarjan(i);
	int t1,t2;
	t1=t2=0;
	int j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<tu[i].size();j++)
		{
			int k=tu[i][j];
			if(fllow[k]!=fllow[i])//
			{
				inn[fllow[k]]++;
				outt[fllow[i]]++;
			}
		}
	}
	for(i=1;i<=sum;i++)
	{
		if(inn[i]==0)
		{
			t1++;
		}
		if(outt[i]==0)
		{
			t2++;
		}
	}
	if(sum==1)
	{
		cout<<1<<endl;
		cout<<0<<endl;
		return 0;
	}
	cout<<t1<<endl;
	cout<<max(t1,t2)<<endl;
	return 0;
}
