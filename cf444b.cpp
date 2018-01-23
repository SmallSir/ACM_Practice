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

int n;
int cube[10][20];
int vis[20],a[20],check[20];;
bool dfs(int x,int flag)
{
	int i,j;
	if(flag==x)
		return true;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=x;j++)
		{
			if(cube[i][a[j]]==1&&vis[j]==0&&check[i]==0)
			{
				vis[j]=1;
				check[i]=1;
				if(dfs(x,flag+1))
					return true;
				vis[j]=0;
				check[i]=0;
			}
		}
	}
	return false;
}
int main()
{
	int i,j,x,k,cnt;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=6;j++)
		{
			cin>>x;
			cube[i][x]=1;
		}
	}
	for(i=1;;i++)
	{
		k=i;
		cnt=0;
		memset(check,0,sizeof(check));
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		while(k>0)
		{
			a[++cnt]=k%10;
			k/=10;
		}
		if(!dfs(cnt,0))
			break;
	}
	cout<<i-1<<endl;
	return 0;
}
