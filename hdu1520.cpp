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

vector<int> tu[6005];
int check[6005],happy[6005];
int dp[6005][5],n;
void dfs(int son,int fa)
{
	int i,k;
	check[son]=1;
	for(i=0;i<tu[son].size();i++)
	{
		k=tu[son][i];
		if(check[k]==1)
			continue;
		check[k]=1;
		dfs(k,son);
		dp[son][0]+=max(dp[k][0],dp[k][1]);
		dp[son][1]+=dp[k][0];
	}
	dp[son][1]+=happy[son];
}
int main()
{
	int i,x,y;
	while(cin>>n)
	{
		memset(check,0,sizeof(check));
		memset(dp,0,sizeof(dp));
		memset(tu,0,sizeof(tu));
		for(i=1;i<=n;i++)
			cin>>happy[i];
		for(;;)
		{
			cin>>x>>y;
			if(x==0&&y==0)
				break;
			tu[x].push_back(y);
			tu[y].push_back(x);
		}
		dfs(1,0);
		cout<<max(dp[1][0],dp[1][1])<<endl;
	}
	return 0;
}
