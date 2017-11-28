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

vector<int> tu[100005];
int n,m;
int check[100005],dis[100005],vis[100005];
int ans[100005], t;
int bfs1(int x)
{
	int i,k,u,flag;
	int MAX = 0;
	flag=x;
	vis[x]=1;
	queue<int> qua;
	qua.push(x);
	dis[x]=0;
	while(!qua.empty())
	{
		k=qua.front();
		qua.pop();
		for(i=0;i<tu[k].size();i++)
		{
			u=tu[k][i];
			if(vis[u])continue;
			vis[u] = 1;
			qua.push(u);
			dis[u]=dis[k]+1;
			if(MAX<dis[u])
			{
				flag=u;
				MAX=dis[u];
			}
		}
	}
	return flag;
}
int bfs2(int x)
{
	int i,k,u,flag;
	int MAX = 0;
	flag=x;
	check[x]=1;
	queue<int> qua;
	qua.push(x);
	dis[x]=0;
	while(!qua.empty())
	{
		k=qua.front();
		qua.pop();
		for(i=0;i<tu[k].size();i++)
		{
			u=tu[k][i];
			if(check[u])continue;
			check[u] = 1;
			qua.push(u);
			dis[u]=dis[k]+1;
			if(MAX<dis[u])
			{
				flag=u;
				MAX=dis[u];
			}
		}
	}
	return flag;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int i,x,y;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}	
	memset(vis,0,sizeof(vis));
	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			int u=bfs1(i);
			int v=bfs2(u);
			ans[++t] = dis[v];
		}
	}
	sort(ans + 1, ans + t + 1,cmp);
	cout<<max(ans[1],max((ans[1]+1)/2+(ans[2]+1)/2+1,(ans[2]+1)/2+(ans[3]+1)/2+2))<<endl;
}

