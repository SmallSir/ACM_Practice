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

bool vis[100005];
int sons[100005],father[100005],deep[100005],n;
vector<int> tu[100005];
void dfs(int son,int fa)
{
	int k;
	sons[son]=1;
	deep[son]=deep[fa]+1;
	father[son]=fa;
	for(int i=0;i<tu[son].size();i++)
	{
		k=tu[son][i];
		if(k==fa) continue;
		if(vis[k]==0)
		{
			vis[k]=1;
			dfs(k,son);
			sons[son]+=sons[k];
		}
	}
}

int main()
{
	int i,x,y,tot;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	memset(deep,0,sizeof(deep));
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	dfs(1,0);
	tot=deep[n]-deep[1]-1;
	tot/=2;
	x=n;
	while(tot--)
		x=father[x];
	if(sons[x]>=n-sons[x])
	{
		cout<<"Snuke"<<endl;
	}
	else
	{
		cout<<"Fennec"<<endl;
	}
}
