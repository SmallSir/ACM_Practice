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

int n,k,i,check[1005],a[1005][1005],j;
int main()
{
	scanf("%d %d",&n,&k);
	if((n-1)/2<k)
	{
		printf("-1\n");
		return 0;
	}
	else
		printf("%d\n",n*k);
	for(i=1;i<=n;i++)
		check[i]=k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j||a[j][i]==1)
				continue;
			printf("%d %d\n",i,j);
			a[i][j]=1;
			check[i]--;
			if(check[i]==0)
				break;
		}
	}
	return 0;
}
