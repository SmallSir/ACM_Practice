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
	int c,index;
}f[300005];
int a[300005];
int check[800005];
int n,k,i,cnt;
LL sum;
bool cmp(point x,point y)
{
	return x.c>y.c;
}
int find(int x)
{
	if(check[x]==x)
		return x;
	check[x]=find(check[x]);
	return check[x];
}
int main()
{
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>f[i].c;
		f[i].index=i;
	}
	sort(f+1,f+1+n,cmp);
	for(i=k+1;i<=k+n;i++) check[i]=i;
	sum = 0;
	for(i=1;i<=n;i++)
	{
		cnt = max(f[i].index,k+1);
		a[f[i].index]=find(cnt);
		sum += (LL)(a[f[i].index]-f[i].index)*f[i].c;
		check[a[f[i].index]]=find(a[f[i].index]+1);
	}
	cout<<sum<<endl;
	for(i=1;i<n;i++) cout<<a[i]<<" ";
	cout<<a[i]<<endl;
	return 0;
}
