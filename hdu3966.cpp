#pragma comment(linker, "/STACK:1024000000,1024000000")
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
//strattime:2017/10/11 13:12
//endtime:2017/10/9 21:07

const int MAXN=50010;
int cnt,son[MAXN],deep[MAXN],father[MAXN],siz[MAXN],top[MAXN],pre[MAXN],tid[MAXN];
int n,m,q;
struct point
{
	int flag,cnt;
}tree[MAXN*4];
vector<int> tu[MAXN];
int a[MAXN];
void init()
{
	memset(son,0,sizeof(son));	
	memset(tu,0,sizeof(tu));
	cnt=0;
}
//树链剖分部分
void dfs1(int s,int fa,int de)//沿着树查找子节点以及子树中的重链
{
	int i,k;
	deep[s]=de;//deep[s]表示s这个点所在的层数为de
	father[s]=fa;//father[s]表示s这个点的父亲节点为fa
	siz[s]=1;//sizes[s]表示以s为根节点的子树一共有几个点
	for(i=0;i<tu[s].size();i++)
	{
		k=tu[s][i];
		if(k==fa)
			continue;
		dfs1(k,s,de+1);
		siz[s]+=siz[k];
		if(son[s]==0||siz[k]>siz[son[s]])
			son[s]=k;//son[s]表示与s在同一重链上的儿子(俗称重儿子)
	}
}
void dfs2(int x,int tp)//将树转化为线段树
{
	int i,k;
	top[x]=tp;//top[x]表示x所在重链上的头结点
	tid[x]=++cnt;//tid[x]表示x在线段树上的编号
	pre[cnt]=x;//pre[cnt]表示cnt这个标号代表的树上的点
	if(son[x])
		dfs2(son[x],tp);
	for(i=0;i<tu[x].size();i++)
	{
		k=tu[x][i];
		if(k!=son[x]&&k!=father[x])//轻边
			dfs2(k,k);
	}
}
//线段树部分

void build(int l,int r,int de)
{
	tree[de].flag=0;
	if(l==r)
	{
		tree[de].cnt=a[pre[l]];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,de*2);
	build(mid+1,r,de*2+1);
}
void putdown(int de,int k)
{
	if(tree[de].flag)
	{
		tree[de*2+1].flag+=tree[de].flag;
		tree[de*2].flag+=tree[de].flag;
		tree[de*2].cnt+=(k-k/2)*tree[de].flag;
		tree[de*2+1].cnt+=k/2*tree[de].flag;
		tree[de].flag=0;
	}
}
void update(int L,int R,int l,int r,int de,int k)
{
	if(L<=l&&r<=R)
	{
		tree[de].flag+=k;
		tree[de].cnt+=(r-l+1)*k;
		return ;
	}
	putdown(de,r-l+1);
	int mid=(l+r)/2;
	if(L<=mid)
		update(L,R,l,mid,de*2,k);
	if(mid<R)
		update(L,R,mid+1,r,de*2+1,k);
}
int query(int l,int r,int de,int pos)
{
	if(l==r)
		return tree[de].cnt;
	putdown(de,r-l+1);
	int mid=(l+r)/2;
	int sum=0;
	if(pos<=mid) sum=query(l,mid,de*2,pos);
	else sum=query(mid+1,r,de*2+1,pos);
	return sum;
}
void change(int x,int y,int k)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		update(tid[top[x]],tid[x],1,n,1,k);
		x=father[top[x]];
	}
	if(deep[x]>deep[y]) swap(x,y);
	update(tid[x],tid[y],1,n,1,k);
}
int main()
{
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
	while(scanf("%d%d%d", &n, &m, &q) != EOF)
	{
		char s;
		int i,x,y,z;
		init();
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			tu[x].push_back(y);
			tu[y].push_back(x);
		}
		dfs1(1,0,1);
		dfs2(1,1);
		build(1,n,1);
		while(q--)
		{
			scanf("%s",&s);
			if(s=='Q')
			{
				scanf("%d",&x);
				printf("%d\n",query(1,n,1,tid[x]));
			}
			else if(s=='D')
			{
				scanf("%d%d%d",&x,&y,&z);
				change(x,y,-z);
			}
			else
			{
				scanf("%d%d%d",&x,&y,&z);
				change(x,y,z);
			}
		}
	}
	return 0;
}
