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

long long int a[2005],b[2005],source[2005],p[2005][2005],ans,sum;
int i,j,n,k,tot;
long long int pp[5000006];
bool flag;
int main()
{
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=k;i++) cin>>b[i];
	for(i=1;i<=n;i++) source[i]=source[i-1]+a[i];
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			p[i][j]=b[i]-source[j];
		}
	}
	sum=0;
	tot=0;
	for(i=1;i<=k;i++)
	{
		map<int,bool> f;
		for(j=1;j<=n;j++)
		{
			if(f[p[i][j]]==true)
				continue;
			pp[++tot]=p[i][j];
			f[p[i][j]]=true;
		}
	}
	if(k==1)
	{
		cout<<tot<<endl;
		return 0;
	}
	//cout<<tot<<endl;
	sort(pp+1,pp+1+tot);
	ans=0;
	for(i=2;i<=tot;i++)
	{
		if(pp[i]==pp[i-1])
		{
			//ans=1;
			for(;i<=tot;i++)
			{
				if(pp[i-1]!=pp[i])
				{
					ans++;
					if(ans>=k)
						sum++;
					ans=0;
					break;
				}
				ans++;
			}
		}
	}
	if(ans>=k)
		sum++;
	cout<<sum<<endl;
}
