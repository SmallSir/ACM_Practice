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
	LL cost;
	int pos,len,flag;
}a[400005];
LL l[300005];
LL cnt;
int i,n,x,len;
bool cmp(point x,point y)
{
	if(x.pos==y.pos)
		return x.flag<y.flag;
	return x.pos<y.pos;
}
int main()
{
	cin>>n>>x;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].pos>>a[i+n].pos>>a[i].cost;
		a[i+n].cost=a[i].cost;
		a[i].flag=0;
		a[i+n].flag=1;
		a[i].len=a[i+n].len=a[i+n].pos-a[i].pos+1;
	}
	cnt=2e9+10;
	sort(a+1,a+1+2*n,cmp);
	for(i=1;i<=2*n;i++)
	{
		if(a[i].flag==0)
		{
			len=x-a[i].len;
			if(len<=0) continue;
			if(l[len]==0) continue;
			cnt=min(cnt,l[len]+a[i].cost);
		}
		else
		{
			len=a[i].len;
			if(l[len]==0) l[len]=a[i].cost;
			else l[len]=min(l[len],a[i].cost);
		}
	}
	if(cnt==2e9+10)
		cout<<-1<<endl;
	else
		cout<<cnt<<endl;
}

