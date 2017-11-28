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
//strattime:2017/11/10 21:00
//endtime:2017/10/9 21:07

int a[50005];
int n,m,L,ans,mid;
bool check(int x)
{
	int cnt=0;
	int k=0;
	int i;
	for(i=1;i<=n+1;i++)
	{
		if(a[i]-a[k]<x)
			cnt++;
		else
			k=i;
	}
	if(cnt>m)
		return true;
	else
		return false;
}
int main()
{
	cin>>L>>n>>m;
	int i,l,r;
	ans=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	a[n+1]=L;
	l=0,r=L;
	while(r-l>1)
	{
		mid = (l+r)/2;
		if(check(mid)) r=mid;
		else
			l = mid;
	}
	cout<<l<<endl;
	return 0;
}
