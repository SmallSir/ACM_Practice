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
//strattime:2017/10/9 21:00
//endtime:2017/10/9 21:07

void init()
{
	memset(tu,0,sizeof(tu));
	memset(cost,0,sizeof(cost));
	memset(son,0,sizeof(son));
	memset(a,0,sizeof(a));
}
void built(int t,int x,int y,int z)
{
	a[t].l=x;
	a[t].r=y;
	a[t].c=z;
}
buildtree(int x,int y,int z)
{
	tu[x].push_back(y);
	cost[x].push_back(z);
}
void dfs
int main()
{
	while(cin>>n>>q>>s)
	{
		init();
		for(i=1;i<n;i++)
		{
			cin>>x>>y>>z;
			built(i,x,y,z);
			buildtree(x,y,z);
			buildtree(y,x,z);
		}
		dfs(1,0,1);
		dfs(1,1);
	}
	return 0;
}
