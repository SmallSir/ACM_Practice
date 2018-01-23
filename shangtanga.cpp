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
	int x;
	int y;
}p,pp;
int dix[]={1,0,-1,0};
int diy[]={0,1,0,-1};
bool vis[105][105],a[105][105];
int n,m;
int dfs(int x,int y)
{
	int sum,i;
	queue<point>qua;
	p.x=x;
	p.y=y;
	qua.push(p);
	sum=0;
	while(!qua.empty())
	{
		p=qua.front();qua.pop();
		for(i=0;i<4;i++)
		{
			pp.x=p.x+dix[i];
			pp.y=p.y+diy[i];
			if(pp.x<=n&&pp.x>=1&&pp.y<=m&&pp.y>=1)
			{
				if(!vis[pp.x][pp.y]&&a[pp.x][pp.y]==false)
				{
					sum++;
					vis[pp.x][pp.y]=true;
					qua.push(pp);
				}
			}
		}
	}
	return sum;
}
int main()
{
	int T,i,x,y,j,ans;
	cin>>n>>m>>T;
	memset(a,0,sizeof(a));
//	memset(b,0,sizeof(b));
	while(T--)
	{
		cin>>x>>y;
		if(x==0)
		{
			for(i=1;i<=m;i++)
			{
				a[y][i]=true;
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				a[i][y]=true;
			}
		}
	}
	memset(vis,0,sizeof(vis));
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==false&&!vis[i][j])
			{
				//vis[i][j]=true;
				//cout<<dfs(i,j)<<endl;
				ans+=dfs(i,j)/2;
			}
		}
	}
	cout<<ans<<endl;	

}
