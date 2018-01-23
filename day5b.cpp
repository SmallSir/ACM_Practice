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


long long int m,n,MOD,dp[5][505][505],cnt1,cnt2;
char str[505][505];
int a[505],i,j,t,k;
int main()
{
	 cin>>n>>m>>MOD;
	 for(i=1;i<=m;i++)
	 {
		for(j=1;j<=n;j++)
		{
			cin>>str[i][j];
			if(str[i][j]=='1')
			{
				a[j]++;
			}
		}
	 }
	 for(i=1;i<=n;i++)
	 {
	 	 if(a[i]==0)
			cnt2++;
		 else if(a[i]==1)
		 	cnt1++;
	 }
	 memset(dp,0,sizeof(dp));
	 dp[0][cnt2][cnt1]=1;
	 t=0;
	 for(i=m+1;i<=n;i++)
     {
     	t^=1;
		for(j=0;j<=n;j++)
		{
			k=(n-i)*2-2*j;
			if(k<0||k>n) continue;
			if(j+1<=n)
				dp[t][j][k]+=(dp[t^1][j+1][k]*(j+1)*k)%MOD;
			if(j+2<=n&&k-2>=0)
				dp[t][j][k]+=(dp[t^1][j+2][k-2]*(j+2)*(j+1)/2)%MOD;
			if(k+2<=n)
				dp[t][j][k]+=(dp[t^1][j][k+2]*(k+2)*(k+1)/2)%MOD;
			//cout<<j<<" "<<k<<" "<<dp[t][j][k]<<endl;
		}
	 }
	 cout<<dp[t][0][0]<<endl;
}
