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
//strattime:2017/10/18 11:04
//endtime:2017/10/18 12:00

const int MAXN = 5e5+10;
vector<int> tu[MAXN];
struct node
{
	int val,flag;
}tree[MAXN*4];
int in[MAXN],out[MAXN],fa[MAXN];
int flag,n,q,cnt;
void dfs(int son,int father)
{
	int i,k;
	in[son]=++cnt;
	for(i=0;i<tu[son].size();i++)
	{
		k=tu[son][i];
		if(k==father)
			continue;
		fa[k]=son;
		dfs(k,son);
	}
	out[son]=cnt;
}
void build(int l,int r,int deep)
{
	tree[deep].flag=0,tree[deep].val=0;
	int mid=(l+r)/2;
	if(l==r)
		return;
	build(l,mid,deep*2);
	build(mid+1,r,deep*2+1);
}
void putup(int deep)
{
	if(tree[deep*2].val==1&&tree[deep*2+1].val==1)
		tree[deep].val=1;
	else
		tree[deep].val=0;
}
void putdown(int deep)
{
	if(tree[deep].flag)
	{
		tree[deep*2].flag=tree[deep*2+1].flag=tree[deep].flag;
		tree[deep*2].val=tree[deep*2+1].val=tree[deep].flag;
		tree[deep].flag=0;
	}
}
void update(int L,int R,int l,int r,int deep,int k)
{
	if(L==0)
		return;
	if(L<=l&&r<=R)
	{
		if(tree[deep].val==0)
			flag=1;
		tree[deep].val=k;
		if(k==1) tree[deep].flag=1;
		return;
	}
	putdown(deep);
	int mid=(l+r)/2;
	if(L<=mid) update(L,R,l,mid,deep*2,k);
	if(mid<R) update(L,R,mid+1,r,deep*2+1,k);
	putup(deep);
}
void query(int L,int R,int l,int r,int deep)
{
	if(L<=l&&r<=R)
	{
		if(tree[deep].val==0)
			flag=1;
		return;
	}
	putdown(deep);
	int mid=(l+r)/2;
	if(L<=mid) query(L,R,l,mid,deep*2);
	if(mid<R) query(L,R,mid+1,r,deep*2+1);
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	cnt=0;
	dfs(1,0);
	build(1,cnt,1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(x==1)
		{
			flag=0;
			update(in[y],out[y],1,n,1,1);
			if(flag)
			{
				update(in[fa[y]],in[fa[y]],1,n,1,0);
			}
		}
		else if(x==2)
		{
			update(in[y],in[y],1,n,1,0);
		}
		else
		{
			flag=0;
			query(in[y],out[y],1,n,1);
			if(flag)
				printf("0\n");
			else
				printf("1\n");
		}
	}
}
