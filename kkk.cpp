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

//b数组的要求当前点为根买书最少价格，a数组表示当前点卖书的最大收益
vector<int> tu[100005],cost[100005];
int a[100005],b[100005],book[100005];
int ans,n;
void build(int x,int y,int c)
{
	tu[x].push_back(y);
	cost[x].push_back(c);
}
void dfs(int son,int fa)
{
	int i;
	a[son]=book[son];
	b[son]=book[son];
	for(i=0;i<tu[son].size();i++)
	{
		int k=tu[son][i];
		int c=cost[son][i];
		if(k==fa) continue;
		dfs(k,son);
		a[son]=max(a[son],a[k]-c);
		b[son]=min(b[son],b[k]+c);
	}
	ans=max(ans,a[son]-b[son]);
}
int main()
{
	int i,T,x,y,c;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++) scanf("%d",&book[i]);
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&c);
			build(x,y,c);
			build(y,x,c);
		}
		ans=-(1<<30);
		dfs(1,0);
		cout<<ans<<endl;
		memset(cost,0,sizeof(cost));
		memset(tu,0,sizeof(tu));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	return 0;
}

