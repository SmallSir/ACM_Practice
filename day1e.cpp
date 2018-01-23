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

double b[65][60],w,r[65],k,tt;
int n,i,m,x,j,check;
int main()
{
	//cin>>n>>w>>m;
	scanf("%d,%d,%d",&n,&w,&m);
	cout<<n<<" "<<m<<endl;
	//for(i=1;i<=m;i++)
	//	a[i]=(0.6lf)(n*w/m);
	for(i=1;i<=n;i++)
		r[i]=w;
	x=1;
	k=n*w/m;
	tt=k;
	for(i=1;i<=n;i++)
	{
		while(r[i]!=0)
		{
			if(tt<=r[i])
			{
				b[x][i]=tt;
				r[i]-=tt;
				x++;
				tt=k;
				cout<<1<<" i "<<i<<" x "<<endl;
			}
			else
			{
				b[x][i]=r[i];
				tt-=r[i];
				r[i]=0;
				if(tt==0)
				{
					x++;
					tt=k;
				}
			}
		}
	}
	check=0;
	bool flag=false;
	for(i=1;i<=n;i++)
	{
		check=0;
		for(j=1;j<=m;j++)
		{
			if(b[j][i]!=0)
				check++;
		}
		if(check>2)
		{
			flag=true;
			break;
		}
	}
	if(flag)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		//cout<<n<<" "<<m<<endl;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(b[i][j]!=0)
				{
					printf("%d %0.6lf ",j,b[i][j]);
				}
			}
			cout<<endl;
		}
	}
}
