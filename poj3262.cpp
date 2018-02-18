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

struct point
{
	LL t,c;
}cow[100005];
int i,n;
LL sum,ans;
bool cmp(point x,point y)
{
	return x.t*y.c<x.c*y.t;
}
int main()
{
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
			cin>>cow[i].t>>cow[i].c;
		sort(cow+1,cow+1+n,cmp);
		sum=0;
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=sum*cow[i].c;
			sum+=cow[i].t*2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
