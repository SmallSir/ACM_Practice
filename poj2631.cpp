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

vector<int> tu[50005],lu[50005];
int check[50005],dis[50005],n,MAXN;
void build(int x,int y,int l)
{
	tu[x].push_back(y);
	lu[x].push_back(l);
}
int dfs(int x)
{
	int tot,k,l,index;
	memset(check,0,sizeof(check));
	memset(dis,0,sizeof(dis));
	tot=0;
	MAXN=0;
	queue<int> qua;
	qua.push(x);
	check[x]=1;
	while(!qua.empty())
	{
		k=qua.front();
		qua.pop();
		for(int i=0;i<tu[k].size();i++)
		{
			index=tu[k][i];
			l=lu[k][i];
			if(check[index])
				continue;
			check[index]=1;
			qua.push(index);
			dis[index]=dis[k]+l;
			if(dis[index]>MAXN)
			{
				MAXN=dis[index];
				tot=index;
			}
		}
	}
	return tot;
}
int main()
{
	int i,x,y,l;
	while(cin>>x>>y>>l)
	{
		build(x,y,l);
		build(y,x,l);
	}
	int t=dfs(1);
	int tot=dfs(t);
	cout<<dis[tot]<<endl;
 return 0;
}
