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

const int MAXN=2e6;
int n,i,b[MAXN+5],a[MAXN+5],cnt[MAXN+5];
int tot,sum,l;
int main()
{
	while(~scanf("%d",&n)){
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		cnt[i+n]=cnt[i]=a[i]-b[i];
	}
	int MAX,ans;
	tot=1;
	sum=0;
	ans=0;
	MAX=-(1<<30);
	for(i=1;i<=2*n;i++)
	{
		ans+=a[i];
		sum+=cnt[i];
		if(ans>MAX)
		{
			MAX=ans;
			l=tot;
		}
		if(sum<0)
		{
			sum=0;
			ans=0;
			tot=i+1;
			if(tot>n+1)
				break;
		}	
	}
	printf("%d\n",l-1);
	}
	return 0;
}
