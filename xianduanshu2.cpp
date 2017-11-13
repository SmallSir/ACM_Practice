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
const int MAXN = 2e5+5;
struct tree
{
	int cnt;
}a[MAXN*4+5];
int n;
void updatemax(int deep)
{
	a[deep].cnt=max(a[deep*2].cnt,a[deep*2+1].cnt);
}
void build(int l,int r,int deep)
{
	if(l==r)
	{
		scanf("%d",&a[deep].cnt);
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,deep*2);
	build(mid+1,r,deep*2+1);
	updatemax(deep);
}
void update(int x,int flag,int l,int r,int deep)
{
	if(l==r)
	{
		a[deep].cnt=flag;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid)
		update(x,flag,l,mid,deep*2);
	else
		update(x,flag,mid+1,r,deep*2+1);
	updatemax(deep);
}
int query_max(int L,int R,int l,int r,int deep)
{
	if(L<=l&&r<=R)
	{
		return a[deep].cnt;
	}
	int mid=(l+r)/2;
	int res=0;
	if(L<=mid)
		res=max(res,query_max(L,R,l,mid,deep*2));
	if(R>mid)
		res=max(res,query_max(L,R,mid+1,r,deep*2+1));
	return res;
}
int main()
{
	int m,i,x,y;
	char s[2];
	while (~scanf("%d%d",&n,&m)) 	
	{
		build(1,n,1);
		for(i=1;i<=m;i++)
		{	
			scanf("%s%d%d",&s,&x,&y);  
			if(s[0]=='Q')
				printf("%d\n",query_max(x , y , 1 , n , 1));
			else
				update(x,y,1,n,1);
		}
	}
	return 0;
}
