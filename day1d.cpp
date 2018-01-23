#include<iostream>  
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<climits>   
#include<cmath> 
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;


int pos[200005],a[200005],p[200005];
int n,m;
struct point
{
	int l,r,k,sum;
}check[5000005],q[200005];
int lowbit(int x) {
	return x&(-x);
}
void adds(int x,int y)
{
	while(x<=n)
	{
		p[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=p[x];
		x-=lowbit(x);
	}
	return ans;
}
bool cmp(point x,point y)
{
	if(x.l==y.l)
		return x.r<y.r;
	return x.l<y.l;
}
bool cmp1(point x,point y)
{
	return x.k<y.k;
}
int main()
{
	int i,cnt,j,head,now;
	scanf("%d%d",&n,&m);
	//cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}
	cnt=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;i*j<=n;j++)
		{
			check[++cnt].l=min(pos[i],pos[i*j]);
			check[cnt].r=max(pos[i],pos[i*j]);
			adds(check[cnt].r,1);
		}
	}
	sort(check+1,check+1+cnt,cmp);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		//cin>>q[i].l>>q[i].r;
		q[i].k=i;
	}
	sort(q+1,q+1+m,cmp);
	head=now=1;
	for(i=1;i<=m;i++)
	{
		while(head<q[i].l) head++;
		while(check[now].l<head)
		{
			adds(check[now].r,-1);
			now++;
		}
		q[i].sum=query(q[i].r);
	}
	sort(q+1,q+1+m,cmp1);
	for(i=1;i<=m;i++)
	{	printf("%d\n",q[i].sum);
		//cout<<q[i].sum<<endl;
	}
}
