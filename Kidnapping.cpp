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

vector<int> qua[5];
vector<int> tu[205],cost[205];
int l,i,n,j,x,m,cnt,k;
bool vis[205];
int b[205];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>x;
			if(i==j||x==0) continue;
			tu[i].push_back(j);
			cost[i].push_back(x);
		}
	}
	cin>>m;
	for(i=1;i<=m;i++) cin>>b[i];
	cnt=0;
	qua[cnt].push_back(1);
	for(i=1;i<=m;i++)
	{
		qua[cnt ^ 1].clear();
		memset(vis,0,sizeof(vis));
		for(j=0;j<qua[cnt].size();j++)
		{
			x=qua[cnt][j];
			for(l=0;l<tu[x].size();l++)
			{
				k=tu[x][l];
				if(cost[x][l]==b[i]&&!vis[k])
				{
					vis[k]=1;
					qua[cnt ^ 1].push_back(k);
				}
			}
		}
		cnt ^=1;
	}
	sort(qua[cnt].begin(),qua[cnt].end());
	cout<<qua[cnt].size()<<endl;
	for(i=0;i<qua[cnt].size();i++)
	{
		if(i==qua[cnt].size()-1)
			cout<<qua[cnt][i]<<endl;
		else
			cout<<qua[cnt][i]<<" ";
	}
	return 0;
}
