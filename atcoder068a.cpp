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
int n;
bool dfs(int son,int fa,int t)
{
	int i,k;
	for(i=0;i<tu[son].size();i++)
	{
		k=tu[son][i];
		if(k==n&&t<=2)
			return true;
		if(t>2)
			return false;
		if(dfs(k,son,t+1)==true)
			return true;
	}
}
int main()
{
	int x,y,i,m;
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	//memset(vis,0,sizeof(vis));
	//vis[1]=1;
	if(dfs(1,0,1)==false)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else
	{
		cout<<"POSSIBLE"<<endl;
	}
 return 0;
}
