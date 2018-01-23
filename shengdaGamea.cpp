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

int a[105][105],b[105],n,m,i,j;
int main()
{
	while(cin>>n>>m)
	{
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]==1)
				{
					b[j]++;
				}
			}
		}
		for(i=1;i<m;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<b[i]<<endl;
	}
}

