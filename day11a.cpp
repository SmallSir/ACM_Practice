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

int dp[2005][2005];
int a[2005],i,n,j,cnt,m;
string str,s;
int main()
{
	cin>>str;
	cin>>s;
	n=str.length();
	m=s.length();
	for(i=0;i<n;i++)
	{
		a[i]=-1;
		cnt=0;
		for(j=i;j<n;j++)
		{
			if(str[j]==s[cnt])
			{
				cnt++;
			}
			if(cnt==m)
			{
				a[i]=j-i+1;
				break;
			}
		}
	}
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			dp[i+1][j+1]=max(dp[i][j],dp[i+1][j+1]);
			if(~a[i])
			{
				dp[i+a[i]][j+a[i]-m]=max(dp[i][j]+1,dp[i+a[i]][j+a[i]-m]);
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		cout<<dp[n][i]<<" ";
	}
	cout<<endl;
}
