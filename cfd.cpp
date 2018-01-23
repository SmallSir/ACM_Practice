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

long long int a[2005],b[2005],p[2005],l,r,pos;
int n,k;
bool check(int x)
{
	long long int ans=2e9+10;
	long long int lu;
	int i;
	for(i=1;i<=n;i++)
	{
		lu=abs(a[i]-b[p[i]])+abs(b[p[i]]-pos);
		ans=min(ans,lu);
	}
	if(lu<=x) return 1;
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
	sort(b+1,b+1+n);
	for(i=1;i<=n;i++)
	{
		MIN=2e9+10;
		for(j=1;j<=k;j++)
		{
			if(b[j]<=pos&&a[i]<=b[j]||b[j]>=a[i]&&b[j]<=pos)
			{
				p[i]=j;
				break;
			}
			else
			{
				if(abs(a[i]-b[j])<MIN)
				{
					MIN=abs(a[i]-b[j]);
					p[i]=j;
				}
			}
		}
	}
	l=0,r=2000000005;
	while(l<=r)
	{
		k=(l+r)/2;
		if(check(k))
		{
			ans = k , r = k - 1;
		}
		else
		{
			l = k + 1;
		}
	}
	cout<<ans<<endl;
}
