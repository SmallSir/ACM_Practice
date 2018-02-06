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

int dp[1005][35];
int a[2005],b[2005];
int v[2005],w[2005];
int n,V,k;
void check()
{
	int i,j,u,x,y,z;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		for(j=V;j>=w[i];j--)
		{
			//29-45行表示求第1到第k的最大值
			for(u=1;u<=k;u++)
			{
				a[u]=dp[j][u];
				b[u]=dp[j-w[i]][u]+v[i];	
			}
			a[k+1] = -1;
			b[k+1]=-1;
			x=y=z=1;
			while(x<=k&&(a[y]!=-1||b[z]!=-1))
			{
				if(a[y]>b[z])
					dp[j][x]=a[y++];
				else
					dp[j][x]=b[z++];
				if(dp[j][x]!=dp[j][x-1])
					x++;
			}
		}
	}
	cout<<dp[V][k]<<endl;
}
int main()
{
	int T,i;
	cin>>T;
	while(T--)
	{
		cin>>n>>V>>k;
		for(i=1;i<=n;i++)
			cin>>v[i];
		for(i=1;i<=n;i++)
			cin>>w[i];
		check();
	}
	return 0;
}
