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

int dx[5]={1,-1,0,0};
int dy[5]={0,0,1,-1};
struct point
{
	int x,y,flag;
}A,B;
int n,m;
char a[1005][1005];
int check[1005][1005];
int vis[1005][1005];
void bfs_f(int xx,int yy)
{
	int x,y,flag;
	memset(vis,0,sizeof(vis));
	check[xx][yy]=0;
	vis[xx][yy]=1;
	queue<point> qua;
	A.x=xx,A.y=yy,A.flag=0;
	qua.push(A);
	while(!qua.empty())
	{
		B=qua.front();
		qua.pop();	
		for(int i=0;i<4;i++)
		{
			x=B.x+dx[i];
			y=B.y+dy[i];
			flag=B.flag+1;
			if(flag>check[x][y]||x>n||x<1||y>m||y<1||a[x][y]=='F'||a[x][y]=='#'||vis[x][y])
				continue;
			check[x][y]=flag;
			vis[x][y]=1;
			A.x=x,A.y=y,A.flag=flag;
			qua.push(A);
		}
	}
}
int bfs_p(int xx,int yy)
{
	int x,y,flag;
	memset(vis,0,sizeof(vis));
	check[xx][yy]=0;
	vis[xx][yy]=1;
	queue<point> qua;
	A.x=xx,A.y=yy,A.flag=0;
	qua.push(A);
	while(!qua.empty())
	{
		B=qua.front();
		qua.pop();	
		for(int i=0;i<4;i++)
		{
			x=B.x+dx[i];
			y=B.y+dy[i];
			flag=B.flag+1;
			if(x<1||x>n||y>m||y<1)
				return flag;
			if(flag>=check[x][y]||a[x][y]=='#'||vis[x][y])
				continue;
			vis[x][y]=1;
			A.x=x,A.y=y,A.flag=flag;
			qua.push(A);
		}
	}
	return 0;
}
int main()
{
	int i,j,T,x,y;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				check[i][j]=1<<30;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='J')
					x=i,y=j;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]=='F')
				{
					bfs_f(i,j);
				}
			}
		}
		int cnt;
		cnt=bfs_p(x,y);
		if(cnt)
			cout<<cnt<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
		memset(a,0,sizeof(a));
	}
	return 0;
}
