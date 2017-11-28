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


/*start:17/5/17 21:30*/
/*end:17/5/17   25:52     */

long long int x;
int T;
long long int a[100005],dp[3605][3605];
int i,j,n;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		bool flag=false;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		for(i = 1; i <= n; i++)
		{
			cin>>x;
			a[i] = x % 3600;
			if(a[i]==0)
				flag=true;
		}
		if(n > 3600||flag)
		{
			cout<<"YES"<<endl;
			continue;
		}
		for(i = 1;i <= n; i++)
		{
			dp[i][a[i]] = 1;
		}
		for(i = 1; i <= n; i++)
		{
			for(j = 0; j < 3600; j++)
			{
				if(dp[i-1][j] == 1)
				{
					dp[i][j] = 1;
					dp[i][(j + a[i]) % 3600] = 1;
				}
			}
		}
		if(dp[n][0] == 1)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
