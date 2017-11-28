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
	int i,x;
}p[10005];
bool cmp(point x,point y)
{
	return x.x<y.x;
}
bool cmp1(point x,point y)
{
	return x.i<y.i;
}
int l,r,m,n,i,k;
int main()
{
	int xx;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>p[i].x;
		p[i].i=i;
	}
	int ans;
	while(m--)
	{
		cin>>l>>r>>xx;
		k=p[xx].x;
		ans=0;
		for(i=l;i<=r;i++)
		{
			if(p[i].x<k)
				ans++;
		}
		//cout<<l+ans<<endl;
		if(l+ans==xx)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

}
