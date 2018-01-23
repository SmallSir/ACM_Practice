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
const int MaxN = 5e4 + 5;
int n;
struct tree
{
	int left,right;
	int cnt;
	int sum;
}a[MaxN*4+5];
void pushup(int deep)
{
	a[deep].sum=a[deep*2].sum+a[deep*2+1].sum;
}
void build(int l,int r,int deep)
{
	if(l==r)
	{
		scanf("%d",&a[deep].cnt);
		a[deep].sum=a[deep].cnt;
		return;
	}
	int mid =(l+r)/2;
	build(l,mid,deep*2);
	build(mid+1,r,deep*2+1);
	pushup(deep);
}
void update(int x,int adds,int l,int r,int deep)
{
	if(l==r)
	{
		a[deep].cnt+=adds;
		a[deep].sum=a[deep].cnt;
		return;
	}
	int mid=(r+l)/2;
	if(x<=mid) update(x,adds,l,mid,deep*2);
	else update(x,adds,mid+1,r,deep*2+1);
	pushup(deep);
}
int query(int L,int R,int l,int r,int deep)
{
	if(L<=l&&r<=R)
	{
		return a[deep].sum;
	}
	int sum=0;
	int mid=(l+r)/2;
	if(L<=mid) sum+=query(L,R,l,mid,deep*2);
	if(R>mid) sum+=query(L,R,mid+1,r,deep*2+1);
	return sum;
}
int main()
{
	int x,y,T,k;
	char s[50];
	scanf("%d",&T);
	k=0;
	while(T--)
	{
		k++;
		printf("Case %d:\n",k); 
		scanf("%d",&n);
		build(1,n,1);
		while (scanf("%s",s))
		{
			if(s[0]=='E')
				break;
			scanf("%d%d",&x,&y);
			if(s[0]=='Q')
				printf("%d\n",query(x , y , 1 , n , 1));  
			else if(s[0]=='A')
				update(x,y,1,n,1);
			else
				update(x,-y,1,n,1);	
		}
	}
	return 0;
}
