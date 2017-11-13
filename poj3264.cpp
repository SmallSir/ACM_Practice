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

const int MAXN=5e4;
struct point
{
	int c,MAX,MIN;
}tree[MAXN*4+5];
void putdown(int deep)
{
	tree[deep].MAX=max(tree[deep*2].MAX,tree[deep*2+1].MAX);
	tree[deep].MIN=min(tree[deep*2].MIN,tree[deep*2+1].MIN);
}
void build(int l,int r,int deep)
{
	if(l==r)
	{
		cin>>tree[deep].c;
		tree[deep].MAX=tree[deep].MIN=tree[deep].c;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,deep*2);
	build(mid+1,r,deep*2+1);
	putdown(deep);
}
int query_max(int L,int R,int l,int r,int deep)
{
	if(L<=l&&r<=R)
		return tree[deep].MAX;
	int mid=(l+r)/2;
	int ans=0;
	if(L<=mid)
		ans=max(ans,query_max(L,R,l,mid,deep*2));
	if(mid<R)
		ans=max(ans,query_max(L,R,mid+1,r,deep*2+1));
	return ans;
}
int query_min(int L,int R,int l,int r,int deep)
{
	if(L<=l&&r<=R)
		return tree[deep].MIN;
	int mid=(l+r)/2;
	int ans=1<<20;
	if(L<=mid)
		ans=min(ans,query_min(L,R,l,mid,deep*2));
	if(mid<R)
		ans=min(ans,query_min(L,R,mid+1,r,deep*2+1));
	return ans;
}

int main()
{
	int n,q,x,y;
	cin>>n>>q;
	build(1,n,1);
	while(q--)
	{
		cin>>x>>y;
		cout<<query_max(x,y,1,n,1)-query_min(x,y,1,n,1)<<endl;
	}
 return 0;
}
