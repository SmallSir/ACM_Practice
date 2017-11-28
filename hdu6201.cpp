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

bool check[205];
vector<int> tu[205],cost[205];
int n,m,r,ans;
int vis[205];
void build(int x,int y,int c)
{
	tu[x].push_back(y);
	cost[x].push_back(c);
}
void dfs(int son)
{
	for(i=1;i<=n;i++)
	{
		dis[i]=(1<<30);
		a[i]=0;
	}
}
int main()
{
	int x,y,c,i;
	ans = (1 << 30);
	scanf("%d%d%d",&n,&m,&r);
	for( i = 1 ; i <= r ; i ++)
	{
		scanf("%d",&x);
		check[x] = true;
	}
	for( i = 1 ; i <= m ; i ++)
	{
		scanf("%d%d%d",&x,&y,&c);
		build(x , y , c);
		build(y , x , c);
	}
	for( i = 1 ; i <= n;i ++)
	{
		memset(vis,0,sizeof(vis));
		spfs(i);
	}
	printf("%d\n",ans);
}
