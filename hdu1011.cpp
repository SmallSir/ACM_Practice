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

int n,m;
struct point
{
	int hope,bug;
}a[105];
int dp[105][105];
int check[105];
vector<int> tu[105];
void dfs(int son,int fa)
{
	int i,j,u,k;
	for(i=a[son].bug;i<=m;i++)
		dp[son][i]=a[son].hope;
	for(i=0;i<tu[son].size();i++)
	{
		k=tu[son][i];
		if(k == fa)
			continue;
		dfs(k,son);
		for(j=m;j>=a[son].bug;j--)
		{
			for(u=1;u<=j-a[son].bug;u++)
				dp[son][j]=max(dp[son][j],dp[son][j-u]+dp[k][u]);
		}

	}
}
int main()
{
	int i,x,y;
	while(cin>>n>>m)
	{
		memset(tu,0,sizeof(tu));
		memset(check,0,sizeof(check));
		memset(dp,0,sizeof(dp));
		if(n==-1&&m==-1)
			break;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].bug>>a[i].hope;
			a[i].bug = (a[i].bug + 19)/20;
		}
	
		for(i=1;i<n;i++)
		{
			cin>>x>>y;
			tu[x].push_back(y);
			tu[y].push_back(x);
		}
		if(m==0)
		{
			cout<<0<<endl;
			continue;
		}
		dfs(1,0);
		cout<<dp[1][m]<<endl;
	}
	return 0;
}
