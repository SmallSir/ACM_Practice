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


int tu[1005][1005],vis[1005][1005];
int n,i,m,sum,x,y,j,k;
int dix[]={0,1,-1,0,0,-1,-1,1,1};
int diy[]={0,0,0,1,-1,1,-1,1,-1};
int main()
{
	memset(tu,0,sizeof(tu));
	cin>>n>>m;
	sum=-1;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		tu[x][y]=1;
		vis[x][y]=i;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(tu[i][j]==1)
			{
				bool flag=0;
				for(k=1;k<=8;k++)
				{
					if(tu[i+dix[k]][j+diy[k]]!=1)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					int cnt=vis[i][j];
					for(k=0;k<=8;k++)
						cnt=max(cnt,vis[i+dix[k]][j+diy[k]]);
					if(sum!=-1)
					{
						sum=min(sum,cnt);
					}
					else
						sum=cnt;
				}
			}
		}
	}
	cout<<sum<<endl;
}
