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
#include <ctime>
using namespace std;
typedef long long LL;

const LL inf=10000000000000;
vector<LL> cost[50005];
vector<int> tu[50005];
LL sum;
int n,m;
bool vis[50005];
LL a[50005],dis[50005];
void build(int x,int y,LL k)
{
	tu[x].push_back(y);
	cost[x].push_back(k);
}
void spfa(int x)
{
	int i,k,child;
	LL c;
	for(i=1;i<=n;i++)
	{
		dis[i]=inf;
		vis[i]=0;
	}
	vis[x]=1;
	dis[x]=0;
	queue<int> qua;
	qua.push(x);
	while(!qua.empty())
	{
		child=qua.front();
		qua.pop();
		for(i=0;i<tu[child].size();i++)
		{
			k=tu[child][i];
			c=cost[child][i];
			if(dis[k]>dis[child]+c)
			{
				dis[k]=dis[child]+c;
				if(!vis[k])
				{
					qua.push(k);
					vis[k]=1;
				}
			}
		}
		vis[child]=0;
	}
}
int main()
{
	int i,T,x,y;
	LL c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%I64d",&x,&y,&c);
			build(x,y,c);
			build(y,x,c);
		}
		spfa(1);
		sum=0;
		bool flag=0;
		for(i=1;i<=n;i++)
		{
			if(dis[i]==inf)
			{
				flag=1;
				break;
			}
			sum+=a[i]*dis[i];
		}
		if(!flag)
			printf("%I64d\n",sum);
		else
			printf("No Answer\n");
		memset(a,0,sizeof(a));
		memset(cost,0,sizeof(cost));
		memset(tu,0,sizeof(tu));
	}
	return 0;
}
