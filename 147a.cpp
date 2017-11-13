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

int n,m,MAX;
vector<int> tu[5005];
int a[5005][5005];
void dfs(int x,int deep)
{
	MAX=max(MAX,deep);
	for(int i=0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		dfs(k,deep+1);
	}
}
int main()
{
	cin>>n>>m;
	int i,x,y;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(!a[y][x])
		{
			tu[y].push_back(x);
		}
	}
		MAX=0;
		dfs(n,0);
		cout<<MAX<<endl;
}
