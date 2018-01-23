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

struct point
{
	int x,y,z;
}a[50005];
int i,n,j,u,k,q,T,MAX;
int b[100];
int main()
{
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n>>q;
		MAX=0;
		for(i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				k=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+abs(a[i].z-a[j].y);
				b[k]++;
				MAX=max(MAX,k);
			}
		}
		for(i=1;i<=MAX;i++)
		{
			b[i]+=b[i-1];
		}
		while(q--)
		{
			cin>>u;
			if(u>MAX)
				cout<<0<<endl;
			else
				cout<<b[u]<<endl;
		}
	}
}
