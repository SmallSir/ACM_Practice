#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

const int MOD=1e8;
int n,m,x,y,i,j,u,k,sum;
int dp[105][105][15][15];
int main()
{
	cin>>n>>m>>x>>y;
	dp[0][0][0][0]=1;
	for(i=0;i<=x;i++)
	{
		for(j=0;j<=m;j++)
		{
			for(k=0;k<=x;k++)
			{
				for(u=0;u<=y;u++)
				{
					if(k!=0&&u!=0)
						continue;
					if(i!=0)
						dp[i][j][k][u]=(dp[i][j][k][u]+dp[i-1][j][k-1][u])%MOD;
					if(j!=0)
						dp[i][j][k][u]=(dp[i][j][k][u]+dp[i][j-1][k][u-1])%MOD;
					cout<<i<<" "<<j<<" "<<k<<" "<<u<<" "<<dp[i][j][k][u]<<endl;
				}
			}
		}
	}
	sum=0;
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
			sum=(sum+dp[n][m][i][j])%MOD;
		}
	}
	cout<<sum<<endl;
	return 0;
}
