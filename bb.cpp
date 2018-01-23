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

vector<int> tu[200005];
int a[200005],b[200005];
int n,m;
bool dfs(int x,int fa,int y,int deep)
{
	int i;
	for(i=0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		if(k==fa)
			continue;
		if(k==y)
		{
			if(deep+1==a[k])
				b[k]++;
			return true;
		}
		if(dfs(k,x,y,deep+1))
		{
			if(deep+1==a[k])
			{
				b[k]++;
			}
			return true;
		}
	}
	return false;
}
int main()
{
	int x,y,i;
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		if(a[x]==0)
			b[x]++;
		dfs(x,0,y,0);
	}
	for(i=1;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<b[i]<<endl;
}
