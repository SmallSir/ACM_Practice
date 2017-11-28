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


struct clothes
{
	long long int k,x,y;
}a[100005];
bool cmp(clothes x,clothes y)
{
	return x.k>y.k;
}
int n,m,i;
long long int sum;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].k=min(a[i].x*2,a[i].y)-min(a[i].x,a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(ans==m)
			break;
		if(a[i].k!=0)
		{
			//cout<<a[i].x<<endl;
			a[i].x*=2;
			ans++;
		}
	}
	sum=0;
	for(i=1;i<=n;i++)
	{
		sum=(sum+min(a[i].x,a[i].y));
	}
	cout<<sum<<endl;
}
