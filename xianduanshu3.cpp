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

const int MAXN=1e5+5;

struct tree
{
	int flag;
	int sum;
}a[MAXN*4+5];
int n,m,T;
void pushup(int deep)
{
	a[deep].sum=a[deep*2].sum+a[deep*2+1].sum;
}
void pushdown(int deep,int longs)
{
	if(a[deep].flag)
	{
		a[deep*2].flag=a[deep].flag,a[deep*2+1].flag=a[deep].flag;
		a[deep*2].sum=(longs-longs/2)*a[deep].flag;
		a[deep*2+1].sum=longs/2*a[deep].flag;
		a[deep].flag=0;
	}
}
void build(int l,int r,int deep)
{
	a[deep].flag=0;
	if(l==r)
	{
		a[deep].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,deep*2);
	build(mid+1,r,deep*2+1);
	pushup(deep);
}
void update(int L,int R,int k,int l,int r,int deep)
{
	int mid=(l+r)/2;
	if(L<=l&&r<=R)
	{
		a[deep].flag=k;
		a[deep].sum=(r-l+1)*k;
		return;
	}
	pushdown(deep,r-l+1);
	if(L<=mid) update(L,R,k,l,mid,deep*2);
	if(mid<R) update(L,R,k,mid+1,r,deep*2+1);
	pushup(deep);
}
int query(int L,int R,int l,int r,int deep)
{
	if(L<=l&&r<=R)
	{
		return a[deep].sum;
	}
	pushdown(deep,r-l+1);
	int mid=(l+r)/2;
	int sum=0;
	if(L<=mid) sum+=query(L,R,l,mid,deep*2);
	if(mid<R) sum+=query(L,R,l,mid,deep*2+1);
	return sum;
}
int main()
{
	int k=0;
	int i,x,y,sum;
	scanf("%d",&T);
	while(T--)
	{
		k++;
		scanf("%d",&n);
		scanf("%d",&m);
		build(1,n,1);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&sum);
			update(x,y,sum,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",k , query(1,n,1,n,1));	
	}
	return 0;
}
