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

vector<int> tu[400005];
int n,m,cnt;
int a[400005],b[400005],c[400005];
void dfs(int x)
{
	int i,k;
	for(i=0;i<tu[x].size();i++)
	{
		k=tu[x][i];
		if(a[x]==0&&c[x]%2!=0&&a[k]==1)
		{
			b[++cnt]=k;
			c[k]++;
			b[++cnt]=x;
			c[x]++;
		}
		if(a[k]==0)
		{
			if(c[k]%2!=0||c[k]==0)
			{
				b[++cnt]=k;
				c[k]++;
				dfs(k);
			}
		}
		else
		{
			if(c[k]%2==0)
			{
				b[++cnt]=k;
				c[k]++;
				dfs(k);
			}
		}
	}
}
int main()
{
	int x,y,i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	bool flag=0;
	for(i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==1)
			flag=1;
	}
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cnt=0;
	b[++cnt]=1;
	c[1]=1;
	if(m==0)
	{
		if(flag==0)
			cout<<0<<endl;
		else
			cout<<-1<<endl;
		return 0;
	}
	flag=0;
	dfs(1);
	for(i=1;i<=n;i++)
	{
		if(a[i]%2==0&&c[i]%2!=0||a[i]%2!=0&&c[i]%2==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1||cnt>4*n)
		cout<<-1<<endl;
	else
	{
		cout<<cnt<<endl;
		for(i=1;i<=cnt;i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}
}
