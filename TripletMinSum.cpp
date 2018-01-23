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


int fa[100005][30],dis[100005],n;
vector<int> tu[100005];
void dfs(int x,int father,int d)
{
	int i;
	fa[x][0]=father;
	for(int i=0;i<tu[x].size();i++)
	{
		if(tu[x][i]==father)
			continue;
		dis[tu[x][i]]=d+1;
		dfs(tu[x][i],x,d+1);
	}
}
int LCA(int x,int y)
{
	int i;
	if(dis[x]<dis[y])
		swap(x,y);
	int f=dis[x]-dis[y];
//	cout<<f<<endl;
	for(i=0;(1<<i)<=f;i++)
	{
		if((1<<i)&f)
			x=fa[x][i];
	}
	if(x!=y)
	{
		for(i=(int)log2(n);i>=0;i--)
		{
			if(fa[x][i]!=fa[y][i])
			{
				x=fa[x][i];
				y=fa[y][i];
			}
		}
		x=fa[x][0];
	}
	return x;
}
int lens(int x,int y)
{
	int i=LCA(x,y);
	return dis[x]+dis[y]-2*dis[i]; 
}
int main()
{
	int T,x,y,z,i,j;
	cin>>n>>T;
	for(i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	dis[1]=1;
	dfs(1,0,1);
	/*cout<<"----------------------"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"dis["<<i<<"]:"<<dis[i]<<endl;
		cout<<"fa["<<i<<"]:"<<fa[i]<<endl;
	}
	cout<<"----------------------"<<endl;*/
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	int h1,h2,h3,res;
	while(T--)
	{
		x=y=z=0;
		cin>>x>>y>>z;
		//int h1,h2,h3,res;
		h1=LCA(x,y);
		h2=LCA(x,z);
		h3=LCA(y,z);
	//	cout<<"h1 h2 h3:"<<h1<<" "<<h2<<" "<<h3<<endl;
		if(h1==h2)
			res=h3;
		else if(h1==h3)
			res=h2;
		else if(h2==h3)
			res=h1;
		int k=lens(x,res)+lens(y,res)+lens(z,res);
		cout<<res<<" "<<k<<endl;
	}
}
