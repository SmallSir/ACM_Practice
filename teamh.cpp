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

int T,j,n,m,i,cnt;
LL dp[10005],a[10005],b[10005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		memset(dp,0,sizeof(dp));
		for(i=0;i<=m;i++) scanf("%lld",&a[i]);
		cnt=1;
		dp[0]=1;
		for(i=1;i<=n;i++)
		{
			while(dp[cnt]==a[cnt]) cnt++;
			b[i]=cnt;
			for(j=m;j>=cnt;j--)
				dp[j]+=dp[j-cnt];
		}
		for(i=1;i<n;i++)
			printf("%lld ",b[i]);
		printf("%lld\n",b[i]);
	}
	return 0;
}
