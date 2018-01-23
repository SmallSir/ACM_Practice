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

struct people
{
	LL weight,beautiful;
}a[5005];
LL dp[1005];
vector<int> tu[1005];
int check[1005];
int n,m,w;
int find(int x)
{
	if(check[x]==x)
		return x;
	check[x]=find(check[x]);
	return check[x];
}
void join(int x,int y)
{
	int t1=find(x);
	int t2=find(y);
	if(t1!=t2)
		check[t1]=t2;
}
int main()
{
	int i,j,k,x,y;
	cin>>n>>m>>w;
	for(i=1;i<=n;i++)
	{
		check[i]=i;
		cin>>a[i].weight;
	}
	for(i=1;i<=n;i++)
		cin>>a[i].beautiful;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		join(x,y);
	}
	for(i=1;i<=n;i++)
			tu[find(check[i])].push_back(i);
	
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		if(check[i]!=i)
			continue;
		for(j=w;j>=0;j--)
		{
			LL cntw=0,cntb=0;
			for(k=0;k<tu[i].size();k++)
			{
				cntw+=a[tu[i][k]].weight;
				cntb+=a[tu[i][k]].beautiful;
				if(j>=a[tu[i][k]].weight)
				{
					dp[j]=max(dp[j],dp[j-a[tu[i][k]].weight]+a[tu[i][k]].beautiful);
				}
			}
			if(j>=cntw)
				dp[j]=max(dp[j],dp[j-cntw]+cntb);
		}
	}
	LL MAX=0;
	for(i=1;i<=w;i++)
		MAX=max(MAX,dp[i]);
	cout<<MAX<<endl;
	return 0;
}
