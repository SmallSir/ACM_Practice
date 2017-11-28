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

long long a[2005],b[2005],p[2005],l,r,pos;
int n,k,kk;
bool check(long long x)
{
	int now=1;
	int i;
	for(i=1;i<=k;i++)
	{
		if(abs(b[i]-a[now])+abs(b[i]-pos)<=x)
		{	
			now++;
		}
	}
	//cout<<x<<endl;
	if(now > n) return 1;
	else
		return 0;
}
int main()
{
	int i,j;
	long long int MIN,ans;;
	cin>>n>>k>>pos;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=k;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+k);	
	l=-1,r=2000000005;
	while(l<r - 1)
	{
		kk=(l+r)/2;
		if(check(kk))
		{
			r=kk;
		}
		else
		{
			l = kk;
		}
	}
	cout<<r<<endl;
}
