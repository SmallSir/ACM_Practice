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

vector<int> tu[505];
int T,n,m,flag;
int vis[505];
void dfs(int x,int y)
{
	int i,k;
	for(i=0;i<tu[x].size();i++)
	{
		k=tu[x][i];
		if(k==y) continue;
		dfs(k,x);
		if(vis[k]==0&&vis[x]==0)
		{
			vis[k]=1;
			vis[x]=1;
		}
		else
		{
			m--;
		}
	}
}
int main()
{
	int k,i,x;

	cin>>T;
	while(T--)
	{
		memset(tu,0,sizeof(tu));
		cin>>n>>m;
		for(i=2;i<=n;i++)
		{
			cin>>x;
			tu[x].push_back(i);
			tu[i].push_back(x);
		}
		flag=0;
		memset(vis,0,sizeof(vis));
		dfs(1,0);
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				flag=1;
				break;
			}
		}
		if(m<0)
			flag=1;
		if(flag)
		{
			cout<<"Alice"<<endl;
		}
		else
		{
			cout<<"Bob"<<endl;
		}
	}
	return 0;
}
