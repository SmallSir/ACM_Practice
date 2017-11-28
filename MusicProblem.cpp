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
using namespace std; 


/*start:17/5/17 20:30*/
/*end:17/5/17   25:52     */

int n,m,i;
long long int x;
int a[1000005];
int dp[1005][1005];
int main()
{
	cin>>n>>m;
	bool flag=false;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=x%m;
		if(a[i]==0)
			flag=true;
	}
	if(flag||n>m)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		dp[i][a[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dp[i-1][j]==1)
			{
				dp[i][j]=1;
				dp[i][(j+a[i])%m]=1;
			}
		}
	}
	if(dp[n][0]==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}
