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
const int INF =1e8+5;


int n,m;
int a[205][205];
int dis[205];
bool bfs()
{
	int k,i;;
	memset(dis,-1,sizeof(dis));
	dis[1]=1;
	queue<int> qua;
	qua.push(1);
	while(!qua.empty())
	{
		k=qua.front();
		qua.pop();
		for(i=1;i<=n;i++)
		{
			if(a[k][i]>0&&dis[i]==-1)
			{
				dis[i]=dis[k]+1;
				qua.push(i);
			}
		}
	}
	if(dis[n]>0)
		return true;
	else
		return false;
}
int dfs(int x,int water)
{
	if(x==n||water==0)
		return water;
	int flow=0;
	for(int i=1;i<=n;i++)
	{
		if(a[x][i]>0&&dis[i]==dis[x]+1&&(flow=dfs(i,min(a[x][i],water))))
		{
			a[x][i]-=flow;
			a[i][x]+=flow;
			return flow;
		}
	}
	return 0;
}
int main()
{
	int flow,i,x,y,c;
	while(cin>>m>>n)
	{
		memset(a,0,sizeof(a));
		for(i=1;i<=m;i++)
		{
			cin>>x>>y>>c;
			a[x][y]+=c;
			a[y][x]+=0;
		}
		flow=0;
		while(bfs())
		{
			flow+=dfs(1,INF);
		}
		cout<<flow<<endl;
	}
	return 0;
}
