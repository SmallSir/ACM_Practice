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

LL a[200005];
LL c[200005];
int n;
struct point
{
	int index;
	LL k;
}b[200005];
bool cmp(LL x,LL y)
{
	return x>y;
}
bool cmp1(point x,point y)
{
	return x.k<y.k;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&b[i].k);
		b[i].index=i;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp1);
	for(i=1;i<=n;i++)
	{
		c[b[i].index]=a[i];
	}
	for(i=1;i<n;i++)
		printf("%lld ",c[i]);
	printf("%lld\n",c[i]);
}
