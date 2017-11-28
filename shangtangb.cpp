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
	long long int x,y;
}p[100005],pp;
bool cmp(point x,point y)
{
	if(x.x==y.x)
		return x.y<y.y;
	return x.x<y.x;
}
long long int k,xx,x,y,yy,ans;
int T,n,i;
int main()
{
	cin>>T;
	n=T;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>xx>>yy;
		pp.x=xx-x;
		pp.y=yy-y;
		p[i]=pp;
	}
	sort(p+1,p+1+n,cmp);
	int l,r;
	r=l=1;
	for(i=2;i<=n;i++)
	{
		if(p[i].x==p[i-1].x&&p[i].y==p[i-1].y)
			r++;
		else
		{
			//ans+=1;
			if(r-l+1>n/2)
			{
				cout<<p[i-1].x<<" "<<p[i-1].y<<endl;return 0;
			}
			l=r=i;
		}
	}
	if(r-l+1>n/2)
		cout<<p[n].x<<" "<<p[n].y<<endl;	
}
