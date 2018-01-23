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

struct DP
{
	int w;
	int a[4];
}dp[200];
int n,m,i,k,j;
int a[200],number[10],x;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>x;
		number[x]++;
	}
	memset(dp,0,sizeof(dp));
	dp[1].w=a[1];
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=4;j++)
		{
			if(i-j<1)
				continue;
			if(dp[i].w<dp[i-j].w&&dp[i-j].a[j]+1<=number[j])
			{
				for(k=1;k<=4;k++)
				{
					dp[i].a[k]=dp[i-j].a[k];
				}
				dp[i].a[j]++;
				dp[i].w=dp[i-j].w;
			}
		}
		dp[i].w+=a[i];
		cout<<dp[i].w<<" "<<i<<endl;
	}
	cout<<dp[n].w<<endl;
 return 0;
}
