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

int dix[4] = {1,-1,0,0};
int diy[4] = {0,0,-1,1};
struct point
{
	int x,y;
};
int n,m;
int tu[1005][1005],check[1005][1005];;
void dfs(int x,int y)
{
	int i,xx,yy;
	queue<point> qua;
	point p,pp;
	p.x = x,p.y = y;
	check[x][y] = 1;
	qua.push(p);
	while(!qua.empty())
	{
		p = qua.front();
		qua.pop();
		for(i=0;i<4;i++)
		{
			xx = p.x + dix[i];
			yy = p.y + diy[i];
			if(xx<1||xx>n||yy<1||yy>m)
				continue;
			if(tu[xx][yy]==0&&check[xx][yy] == 0)
			{
				pp.x = xx;
				pp.y = yy;
				check[pp.x][pp.y] = 1;
				qua.push(pp);
			}
		}
	}
}
int sum_dfs(int x,int y)
{
	int i,xx,yy;
	int sum=1;
	point p,pp;
	queue<point> qua;
	p.x = x;
	p.y = y;
	qua.push(p);
	check[x][y] = 1;
	while(!qua.empty())
	{
		p = qua.front();
		qua.pop();
		for(i=0;i<4;i++)
		{
			xx = p.x + dix[i];
			yy = p.y + diy[i];
			if(xx<1||xx>n||yy<1||yy>m)
				continue;
			if(tu[xx][yy]==1&&check[xx][yy] == 0)
			{
				pp.x = xx;
				pp.y = yy;
				check[pp.x][pp.y] = 1;
				qua.push(pp);
				sum++;
			}
		}
	}
	return sum;
}
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>tu[i][j];
	memset(check,0,sizeof(check));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i==1||i==n||j==1||j==m)
			{
				if(tu[i][j] == 0&&check[i][j]==0)
				{
					dfs(i,j);
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(check[i][j] == 0)
				tu[i][j]=1;
		}
	}
	memset(check,0,sizeof(check));
	int sum = sum_dfs(n,1);
	cout<<sum<<endl;
	return 0;
}
