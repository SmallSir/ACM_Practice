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

int n,T,i,j,v;
int value[1005],height[1005],dp[1005];
int main()
{
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n>>v;
		for(i=1;i<=n;i++)
			cin>>value[i];
		for(i=1;i<=n;i++)
			cin>>height[i];
		for(i=1;i<=n;i++)
		{
			for(j=v;j>=height[i];j--)
			{
				dp[j]=max(dp[j],dp[j-height[i]]+value[i]);
			}
		}
		cout<<dp[v]<<endl;
	}
	return 0;
}
