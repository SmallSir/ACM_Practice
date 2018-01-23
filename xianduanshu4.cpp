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

const int MAXN = 1e5 + 5;
struct tree
{
	LL flag,sum;
}a[MAXN * 4 + 5];
int n,m;
void pushup(int deep)
{
	a[deep].sum = a[deep * 2].sum + a[deep * 2 + 1].sum;
}
void build(int l ,int r,int deep)
{
	a[deep].flag = 0;
	if(l == r)
	{
		scanf("%lld",&a[deep].sum);
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid,deep * 2);
	build(mid+1,r,deep * 2 + 1);
	pushup(deep);
}
void pushdown(int deep,int longs)
{
	if(a[deep].flag)
	{
		a[deep * 2].flag += a[deep].flag;
		a[deep * 2 +1].flag += a[deep].flag;
		a[deep * 2].sum += a[deep].flag * (longs - longs / 2);
		a[deep * 2 + 1].sum += a[deep].flag * (longs / 2);
		a[deep].flag = 0;
	}
}
void update(int L , int R ,int k , int l , int  r, int deep)
{
	if( L <= l && r <= R)
	{
		a[deep].flag += k;
		a[deep].sum += (LL) k * (r - l + 1);
		return;
	}
	pushdown(deep,r-l+1);
	int mid = (l + r) / 2;
	if(L <= mid) update(L,R,k,l,mid,deep * 2);
	if(mid < R) update(L,R,k,mid+1,r,deep * 2 + 1);
	pushup(deep);
}
LL query(int L,int R,int l,int r,int deep)
{
	if( L <= l && r <= R)
		return a[deep].sum;
	pushdown(deep,r-l+1);
	LL sum=0;
	int mid = (l + r) / 2;
	if(L <= mid) sum += query(L,R,l,mid,deep * 2);
	if(mid < R)  sum += query(L,R,mid+1,r,deep * 2 + 1);
	return sum;
}
int main()
{
	char s[2];
	LL k;
	int x,y;
	scanf("%d%d",&n,&m);
	build(1 , n , 1);
	while(m--)
	{
		scanf("%s",&s);
		if(s[0] == 'Q')
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(x , y , 1 , n , 1));  
		}
		else
		{
			scanf("%d%d%d",&x,&y,&k);
			update(x,y,k,1,n,1);
		}
	}
	return 0;
}
