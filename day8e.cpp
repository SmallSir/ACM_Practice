#include<iostream>  
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<climits>   
#include<cmath>
#include<stack>
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;

long long int f[1005],a[1005];
int s,k,ans,cnt,sum;
int i,n;
int main()
{
	cin>>s>>k;
	f[1]=1;
	for(i=2;;i++)
	{
		cnt++;
		sum+=f[i-1];
		f[i]=sum;
		if(cnt>=k)
		{
			sum-=f[i-k];
		}
		if(f[i]>s)
		{
			n=i;
			break;
		}
	}
	memset(a,0,sizeof(a));
	ans=0;
	for(i=n;i>=1;i--)
	{
		if(f[i]<=s)
		{
			s-=f[i];
			a[++ans]=f[i];
			if(s==0)
			{
				break;
			}
		}
	}
	cout<<ans+1<<endl;
	cout<<"0 "; 
	for(i=1;i<=ans;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
