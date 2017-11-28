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

const int MAXN=1e4;
struct tree
{
	int flag,cnt;
}a[MAXN*4+5];
int n,I,H,m;
struct point 
{
	int x,y;
}b[10005];
void build(int l,int r,int deep)
{
	a[deep].flag=0;
	if(l==r)
	{
		a[deep].cnt=H;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,deep*2);
	build(mid+1,r,deep*2+1);
}
void pushdown(int deep)
{
	if(a[deep].flag)
	{
		a[deep*2].flag+=a[deep].flag;
		a[deep*2+1].flag+=a[deep].flag;
		a[deep].flag=0;
	}
}
void update(int L,int R,int l,int r,int deep)
{
	if(L>R)
		return;
	if(L<=l&&r<=R)
	{
		a[deep].flag--;
		return;
	}
	pushdown(deep);
	int mid=(l+r)/2;
	if(L<=mid) update(L,R,l,mid,deep*2);
	if(mid<R) update(L,R,mid+1,r,deep*2+1);
}
int query(int L,int R,int l,int r,int deep)
{
	if(L<=l&&r<=R)
		return a[deep].cnt+a[deep].flag;
	pushdown(deep);
	int sum=0;
	int mid=(l+r)/2;
	if(L<=mid) sum+=query(L,R,l,mid,deep*2);
	if(mid<R) sum+=query(L,R,mid+1,r,deep*2+1);
	return sum;
}
bool cmp(point x,point y)
{
	if(x.x==y.x)
		return x.y<y.y;
	else
		return x.x<y.x;
}
int main()
{
	int i,x,y;
	scanf("%d%d%d%d",&n,&I,&H,&m);
	build(1,n,1);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].x,&b[i].y);
		if(b[i].x>b[i].y)
			swap(b[i].x,b[i].y);
	}
	sort(b+1,b+1+m,cmp);
	for(i=1;i<=m;i++)
	{
		if(b[i].x==b[i-1].x&&b[i].y==b[i-1].y)
			continue;
		update(b[i].x+1,b[i].y-1,1,n,1);
	}
	for(i=1;i<=n;i++)
		printf("%d\n",query(i,i,1,n,1));
	return 0;
}
