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

struct point
{
	int x,y;
}a[10005],aa;
int x, y,n,m,T,i,xx,yy;

int main() 
{
	cin >> n >> m ;
	cin >> x >> y ;
	cin >> T ;
	memset(a,0,sizeof(a));
	for ( i = 1 ; i <= T ; i++)
	{
		cin>>a[i].x>>a[i].y;
		aa.x+=a[i].x;
		aa.y+=a[i].y;
	}
	if(aa.x<0)
	{
		xx=x/abs(aa.x);
	}
	else if(aa.x>0)
	{
		xx=(n-x)/aa.x;
	}
	if(aa.y<0)
	{
		yy=y/abs(aa.y);
	}
	else if(aa.y>0)
	{
		yy=(m-y)/aa.y;
	}
	if(xx==yy)
	{
		cout<<T*xx<<endl;
		return 0;
	}
	cout<<xx<<" "<<yy<<endl;
	if(xx<yy&&xx!=0||yy==0)
	{
		//cout<<1111<<endl;
		x+=xx*aa.x;
		y+=xx*aa.y;
		if(x<1||x>n)
		{
			cout<<xx*T-1<<endl;
			return 0;
		}
		for(i=1;i<=T;i++)
		{
			x+=a[i].x;
			y+=a[i].y;
			if(x<1||x>n)
			{
				cout<<xx*T+i-1<<endl;
				break;
			}
		}
	}
	else
	{
		x+=yy*aa.x;
		y+=yy*aa.y;
		if(y<1||y>m)
		{
			cout<<yy*T-1<<endl;
			return 0;
		}
		for(i=1;i<=T;i++)
		{
			x+=a[i].x;
			y+=a[i].y;
			if(y<1||y>m)
			{
				cout<<yy*T+i-1<<endl;
				break;
			}
		}
	}
}
