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

bool check[1005][1005],vis[1005];
vector<int> tu[1005];
int n,m,T;
void dfs(int son,int fa)
{
	int k;
	vis[son]=1;
	for(int i=0;i<tu[son].size();i++)
	{
		k=tu[son][i];
		if(vis[k]==1)
			continue;
		dfs(k,son);
	}
}
int main()
{
	cin>>T;
	while(T--)
	{
		int i,j,x,flag,y;
		cin>>n>>m;
		memset(tu,0,sizeof(tu));
		memset(check,0,sizeof(check));
		for(i=1;i<=m;i++)
		{
			cin>>x>>y;
			check[x][y]=1;
			tu[x].push_back(y);
		}
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			dfs(i,0);
			for(j=1;j<=n;j++)
			{
				if(j!=i&&vis[j]==1)
					check[i][j]=1;
			}
		}
		flag=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(check[i][j]==0&&check[j][i]==0)
				{
					flag=1;
					break;
				}
			}
		}
		if(!flag) cout<<"I love you my love and our love save us!"<<endl;
		else
			cout<<"Light my fire!"<<endl;
	
	}
	return 0;
}
