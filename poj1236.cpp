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
//check[u]数组表示节点u搜索的次序编号时间戳。low[u]为u能追溯到的最早的时间戳
void tarjan(int x)
{
	check[x]=low[x]=++index;//初始化搜索到的节点x
	st.push(x);//将x点放在求强连通分量的栈中
	instack[x]=1;//x点是否在栈中
	for(int i = 0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		if(!check[k])
		{
			tarjan(k);
			low[x]=min(low[x],low[k]);//比较当前点x能够到达的最早时间戳，与他的子树中的点的最早时间戳比较
		}
		else
		{
			if(instack[k])//如果x为根的子树中有K在栈中
			{
				low[x]=min(low[x],check[k]);//比较k的时间戳大小
			}
		}
	}
	if(check[x]==low[x])//x点为根节点
	{
		sum++;
		int k=0;
		while(k!=x)//直到符合条件前，这些点都是强连通分量
		{
			k=st.top();
			st.pop();
			fllow[k]=sum;//将这些点分组进行标记
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
		if(!check[i])//存在多个图
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
