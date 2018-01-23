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


struct milk
{
	int l,r,sum;
}a[1005];
bool cmp(milk x,milk y)
{
	if(x.l==y.l)
		return x.r<y.r;
	return x.l<y.l;
}
int i;
int dp[1005];
int n,m,r,j;
int main()
{
	cin>>n>>m>>r;
	for(i=1;i<=m;i++)
	{
		cin>>a[i].l>>a[i].r>>a[i].sum;
		a[i].r+=r;
	}
	sort(a+1,a+1+m,cmp);
	memset(dp,0,sizeof(dp));
	for(i=m;i>=1;i--)
	{
		dp[i]=a[i].sum;
		for(j=i+1;j<=m;j++)
		{
			if(a[j].l>=a[i].r)
				dp[i]=max(dp[i],dp[j]+a[i].sum);
		}
	}
	int maxx=0;
	for(i=1;i<=m;i++)
	{
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx<<endl;
}
