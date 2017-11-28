#include<iostream>    
#include<cstdio>  
#include<stdio.h>  
#include<cstring>    
#include<cstdio>    
#include<climits>    
#include<cmath>   
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;

struct point
{
	int x,y;
}p,pp;
int ans,n,m,k;
int a[105][105];
bool vis[105][105];
int dix[]={1,0,-1,0};
int diy[]={0,1,0,-1};
int dfs(int x,int y)
{
	int i;
	int sum=0;
	queue<point> qua;
	p.x=x;
	p.y=y;
	qua.push(p);
	while(!qua.empty())
	{
		p=qua.front();
		qua.pop();
		for(i=0;i<4;i++)
		{
			pp.x=p.x+dix[i];
			pp.y=p.y+diy[i];
			if(pp.x>=1&&pp.x<=n&&pp.y<=m&&pp.y>=1
				&&a[pp.x][pp.y]==1&&!vis[pp.x][pp.y])
			{	
				sum++;
				qua.push(pp);
				vis[pp.x][pp.y]=true;
			}
		}
	}
	return sum;
}

int main()
{
	cin>>n>>m>>k;
	int i,j,x,y;
	while(k--)
	{
		cin>>x>>y;
		a[x][y]=true;
	}
	memset(vis,false,sizeof(vis));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==1&&!vis[i][j])
			{
				vis[i][j]=true;
				ans=max(ans,dfs(i,j)+1);
			}
		}
	}
	cout<<ans<<endl;
}
