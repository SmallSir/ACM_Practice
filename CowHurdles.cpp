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
using namespace std;
const long long inf = 9999999;


vector<long long int> cost[305];
vector<int> tu[305];
int n,m,T;
long long int a[305][305],b[305][305];
bool flag[305];
long long int dis[305],c;
void check(int x)
{
	int k,xx;
	queue<int> qua;
	qua.push(x);
	while(!qua.empty())
	{
		k=qua.front();
		qua.pop();
		for(int i=0;i<tu[k].size();i++)
		{
			xx=tu[k][i];
			if(cost[k][i]+dis[k]<dis[xx])
			{
				dis[xx]=cost[x][i]+dis[k];
				b[x][xx]=max(b[x][xx],cost[x][i]);
				if(!flag[xx])
				{
					flag[xx]=true;
					qua.push(xx);
				}
			}
		}
	}
	return;
}
int main()
{
	cin>>n>>m>>T;
	int i,x,y,j;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		tu[x].push_back(y);
		cost[x].push_back(c);
	}
	//cout<<1111<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				a[i][j]=0;
			else
				a[i][j]=inf;
		}
	}
	//cout<<11111<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dis[j]=inf;
		}
		dis[i]=0;
		//cout<<inf<<endl;
		//cout<<dis[2]<<endl;
		memset(flag,0,sizeof(flag));
		//cout<<111<<endl;
		check(i);
		for(j=1;j<=n;j++)
		{
			//cout<<dis[j]<<endl;
			a[i][j]=dis[j];
		}
	}
//	cout<<1111<<endl;
	while(T--)
	{
		cin>>x>>y;
		if(a[x][y]==inf)
			cout<<-1<<endl;
		else
			cout<<b[x][y]<<endl;
	}
	return 0;
}
