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

int n,T;
double a[100005];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,double y)
{
	while(x<=n)
	{
		a[x]+=y;
		x+=lowbit(x);
	}
}
double query(int x)
{
	double ans=0;
	while(x>0)
	{
		ans+=a[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	int i,k;
	int x;
	double y;
	cin>>n>>T;
	for(i=1;i<=n;i++)
	{
		cin>>y;
		update(i,y);
		update(i+1,-y);
	}
	while(T--)
	{
		cin>>k;
		if(k==0)
		{
			cin>>x>>y;
			update(x,y);
			update(x+1,-y);
			update(1,-y/(n-1));
			update(x,y/(n-1));
			update(x+1,-y/(n-1));
		}
		else
		{
			cin>>x;
			printf("%0.10lf\n",query(x));
		}
	}
}
