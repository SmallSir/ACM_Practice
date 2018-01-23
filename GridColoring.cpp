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

double a[100005],b[100005];
int n,p;
bool check(double x)
{
	int i;
	double cnt=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]*x>b[i])
		{
			cnt+=(double)(a[i]*x-b[i]);
		}
	}
	if(cnt>x*p*1.0)
		return false;
	else
		return true;
}
int main()
{
	int i;
	LL sum;
	double l,r,k;
	sum=0;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i],&b[i]);
		sum+=a[i];
	}
	if(sum<=p)
	{
		printf("-1\n");
		return 0;
	}
	l=0,r=1e12;
	while(l<r-1e-8)
    {
        k = (l+r)/2;
        if(check(k))
            l = k;
        else
            r = k;
    }
	printf("%0.8lf\n",r);
}
