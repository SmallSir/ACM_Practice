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

int n,m,T,i,j,ans,xx,x,yy,y,k;
int a[2005][2005],b[2005][2005],c[2005][2005];
char tu[2005][2005];
int main()
{
	cin>>n>>m>>T;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>tu[i][j];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	//cout<<1111111<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
			b[i][j]=b[i][j-1]+b[i-1][j]-b[i-1][j-1];
			c[j][i]=c[j][i-1]+c[j-1][i]-c[j-1][i-1];
			if(tu[i][j]=='1')
				a[i][j]++;
			if(tu[i][j-1]=='1'&&tu[i][j]=='1')
				b[i][j]++;
			if(tu[i-1][j]=='1'&&tu[i][j]=='1')
				c[j][i]++;

		//	cout<<"i: "<<i<<" j: "<<j<<" b[i][j]"<<b[i][j]<<endl;
		}
	}
	//cout<<b[n][m]<<endl;
	//cout<<111111111<<endl;
	while(T--)
	{
		cin>>x>>y>>xx>>yy;
		k=a[xx][yy]-a[x-1][yy]+a[x-1][y-1]-a[xx][y-1];
		//cout<<"k "<<k<<endl;
		ans=b[xx][yy]-b[xx][y]-b[x-1][yy]+b[x-1][y];
//		cout<<"ans "<<ans<<endl;
		ans+=c[yy][xx]-c[yy][x]-c[y-1][xx]+c[y-1][x];
		//cout<<"1 :"<<ans<<endl;
		cout<<k-ans<<endl;
	}
}
