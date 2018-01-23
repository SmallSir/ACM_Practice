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


long long int dp[5][100005],kk;
int a[100005];
int n,b,i,T,j,lu;
int main()
{
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n>>b;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=2;i<=n;i++)
		{
			dp[1][i]=min(dp[0][i-1],dp[1][i-1])+pow(2,(a[i]-a[i-1]))+b;
			dp[0][i]=dp[1][i];
			lu=a[i]-a[i-1];
			for(j=i-1;j>=1;j--)
			{
				kk=pow(2,a[i]-a[j])+b;
				dp[0][i]=min(dp[0][i],(dp[1][j]+kk));
				lu+=a[j]-a[j-1];
			}
		}
		cout<<min(dp[1][n],dp[0][n])<<endl;
	}
}
