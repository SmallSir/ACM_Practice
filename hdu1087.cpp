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

int n,i,j;
LL dp[1005],a[1005],sum;
int main()
{
	for(;;)
	{
		cin>>n;
		if(n==0)
			return 0 ;
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			dp[i]=a[i];
		}
		sum=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				if(dp[i]>dp[j])
				{
					dp[i]=max(dp[i],dp[j]+a[i]);
				}
			}
			sum=max(sum,dp[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
