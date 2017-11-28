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
vector<int> tu[300005];
vector<int> cost[300005];
map<pair<int,int>,int> b;
int flagg,n,m;
struct hh
{
	int x,y;
	LL sum;
}a[100005];
LL k;
LL c[300005];
int check[300005];
void build(int x,int y,int cc,int number)
{
	tu[x].push_back(y);
	tu[y].push_back(x);
	cost[x].push_back(cc);
	cost[y].push_back(cc);
	if(x>y)
		swap(x,y);
	b[make_pair(x,y)]=number;
	c[number] = cc;
}
bool dfs(int x,int fa,int y,int flag)
{
	for(int i=0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		int cc=cost[x][i];
		if(k==fa)
			continue;
		if(k==y)
		{
			a[flag].sum+=cc;
			if(x<y)
				check[b[make_pair(k,y)]]++;
			else
				check[b[make_pair(y,k)]]++;
			return true;
		}
		if(dfs(k,x,y,flag))
		{
			a[flag].sum+=cc;
			if(x<k)
				check[b[make_pair(x,k)]]++;
			else
				check[b[make_pair(k,x)]]++;
			return true;
		}
	}
	return false;
}
bool dfs1(int x,int fa,int y,int flag)
{
	for(int i=0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		if(k==fa)
			continue;
		if(k==y)
			return true;
		if(dfs1(k,x,y,flag))
		{
			if(x<k)
			{
				if(b[make_pair(x,k)]==flag)
					flagg=1;
			}
			else
			{
				if(b[make_pair(k,x)]==flag)
					flagg=1;
			}
			return true;
		}
	}
	return false;
}
int main()
{
	cin>>n>>m;
	int x,y,cc,i,MAX;
	int cnt;
	MAX=0;
	for(i=1;i<n;i++)
	{
		cin>>x>>y>>cc;
		build(x,y,cc,i);
	}
	for(i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].sum=0;
		dfs(a[i].x,0,a[i].y,i);
	}
	cnt=0;
	for(i=1;i<n;i++)
	{
		if(MAX<check[i])
		{
			MAX=check[i];
			cnt=i;
		}
	}
	k=0;
	for(i=1;i<=m;i++)
	{
		flagg=0;
		dfs1(a[i].x,0,a[i].y,cnt);
		if(flagg)
			k=max(k,(a[i].sum-c[cnt]));
		else
			k=max(k,a[i].sum);
	}
	cout<<k<<endl;
	return 0;
}
