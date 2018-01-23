#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long LL;

double a[15][1005];
bool check[15];
int vis[15];
int n,m;
int t;
double dfs(int x,int y,int kk)
{
	int i,j;
	double ans;
	ans=0;
	if(kk==n+1)
	{
		for(i=x;i<=y;i++)
		{
			ans+=a[vis[i]][i];
		}
		//cout<<ans<<endl;
		return ans;
	}
	//cout<<"kk"<<kk<<endl;
	for(i=x;i<=y;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=kk;
			//cout<<"vis["<<i<<"]"<<vis[i]<<endl;
			ans=max(ans,dfs(x,y,kk+1));
			vis[i]=0;
		}
	}
//	cout<<"kk "<<kk<<endl;
	return ans;
}
double dfss(int x,int y,int xx)
{
	double ans=0;
	int i,j;
	if(xx==(y-x+1))
	{
		for(i=x;i<=y;i++)
		{
			ans+=a[vis[i]][i];
		}
		return ans;
	}
	for(i=1;i<=n;i++)
	{
		for(j=x;j<=y;j++)
		{	
			if(vis[j]==0&&check[i]==0)
			{
				vis[j]=i;
				check[i]=1;
				ans=max(ans,dfs(x,y,xx+1));
				check[i]=0;
				vis[j]=0;
			}
		}
	}
	return ans;
}

int main()
{
	int T,i,j,k;
	double ans,sum;
	cin>>T;
	t = 0;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		ans=sum=0;
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		if(m>=n)
		{
			for(k=1;k<=m/n;k++)
			{
				memset(vis,0,sizeof(vis));
				ans=0;
				for(int j = (k - 1) * n + 1; j <= k * n; j++)
				{
						if(vis[j]==0)
						{
							vis[j]=1;
							//cout<<"vis["<<j<<"] "<<vis[j]<<endl;
							ans=max(ans,dfs((k-1)*n+1,k*n,2));
							vis[j]=0;
						}
				}
				sum+=ans;
	//			cout<<"sum "<<sum<<endl;
			}
		}
		ans=0;
		//bool check[15];
		memset(check,0,sizeof(check));
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			//ans=0;
			for(int j = (m / n) * n + 1; j <= m; j++)
			{
				if(vis[j]==0)
				{
					vis[j]=i;
					check[i]=1;
					ans=max(ans,dfss((m/n)*n+1,m,1));
					vis[j]=0;
					check[i]=0;
				}
			}
		}
		//cout<<"ans: "<<ans<<endl;
		printf("Case #%d: %.5lf\n", ++t, sum + ans);
	//	cout<<sum+ans<<endl;
	}
}
