#include<iostream>  
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<climits>   
#include<cmath>
#include<stack>
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;


vector<int> tu[205],s;
bool vis[205];
int check[205];
int a[205];
int n,m;
void pushs(int x,int y)
{
	tu[x].push_back(y);
	tu[y].push_back(x);
}
void dfs(int x)
{
	int i;
	vis[x]=1;
	for(i=0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		if(vis[k]==0)
			dfs(k);
	}
	s.push_back(x);
}
void rdfs(int x,int ss)
{
	int i;
	vis[x]=1;
	check[x]=ss;
	for(i=0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		if(vis[k]==0)
		{
			rdfs(k,ss);
		}
	}
}
int main()
{
	int k,i,x,y,l;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>l;
		if(l==1)
		{
			pushs(x,y);
			pushs(x+n,y+n);
		}
		else
		{
			pushs(x,y+n);
			pushs(x+n,y);
		}
	}
	memset(vis,0,sizeof(vis));
	for(i=1;i<=2*n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(i=s.size()-1;i>=0;i--)
	{
		k=s[i];
		if(!vis[k])
		{
			rdfs(k,cnt++);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(check[i]==check[i+n])
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	cnt=0;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	{
		if(check[i]<check[i+n])
		{
			a[++cnt]=i;
		}

	}
	cout<<cnt<<endl;
	for(i=1;i<=cnt;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
