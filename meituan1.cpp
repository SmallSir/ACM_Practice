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

int i,n,m;
struct point
{
	float cost,x;
}c[15];
int y;
float a[15],b[15],sum,cnt,MAX;
int main()
{
	sum = cnt = 0;
	scanf("%d %d",&n,&m);
	for(i = 1;i <= n;i++)
	{
		cin>>a[i]>>y;
		if(y == 1)
		{
			b[i] = a[i] * 0.8;
		}
		else
			b[i] = a[i] * 1.0;
		sum+=a[i];
		cnt+=b[i];
	}
	MAX  = (1 << 30) *1.0;
	for(i = 1;i <= m;i++)
	{
		cin>>c[i].x>>c[i].cost;
		if(sum >= c[i].x)
			MAX = min(MAX,sum - c[i].cost);
	}
	printf("%0.2lf\n",min(MAX,cnt));
	return 0;
}
