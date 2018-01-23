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


int tu[105][105][105];
int n,m;
void check(int x,int y,int l)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(tu[l][i][x]==1&&tu[l][i][y]==0)
		{
			tu[l][i][y]=1;
			tu[l][y][i]=1;
			check(i,y,l);
		}
		if(tu[l][i][y]==1&&tu[l][i][x]==0)
		{
			tu[l][i][x]=1;
			tu[l][x][i]=1;
			check(i,x,l);
		}
	}
}
int main()
{
	int x,y,l,T,sum,i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>l;
		tu[l][x][y]=1;
		tu[l][y][x]=1;
		check(x,y,l);
	}
	cin>>T;
	while(T--)
	{
		cin>>x>>y;
		sum=0;
		for(i=1;i<=m;i++)
		{
			if(tu[i][x][y]==1)
				sum++;
		}
		cout<<sum<<endl;
	}
}
