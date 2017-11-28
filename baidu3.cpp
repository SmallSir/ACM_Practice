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

struct moster
{
	LL up,hp;
}a[100005];
struct point
{
	LL cost,hp;
}b[1005];
int n,m;
LL up,hp,hpp,ans;
LL dp[1005][15];
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i,j,k;
		memset(a,0,sizeof(a));
		up=hp=hpp=0;
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++)
		{
			scanf("%I64d%I64d",&a[i].up,&a[i].hp);
			up=max(up,a[i].up);
			hp=max(hp,a[i].hp);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%I64d%I64d",&b[i].cost,&b[i].hp);
			hpp=max(hpp,b[i].hp);
		}
		if(hp>=hpp)
		{
			printf("-1\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(i=0;i<=10;i++)
		{
			for(j=1;j<=up;j++)
			{
				dp[j][i]=1<<30;
				for(k=1;k<=m;k++)
				{
					LL tt=b[k].hp-i;
					if(tt<=0)
						continue;
					if(tt>=j)
					{
						dp[j][i]=min(dp[j][i],b[k].cost);
					}
					else
					{
						dp[j][i]=min(dp[j][i],dp[j-tt][i]+b[k].cost);
					}
				}
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
			ans+=dp[a[i].up][a[i].hp];
		printf("%I64d\n",ans);
	}
	return 0;
}
