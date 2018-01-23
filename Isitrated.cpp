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
using namespace std; 


/*start:17/5/18 21:40*/
/*end:17/5/18   2    */

struct people
{
	int i,l,r;
}p[1005];

bool cmp(people x,people y)
{
	return x.l>y.l;
}
int i,n,x,y;
int main()
{
	cin>>n;
	int flag=0;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(x!=y)
		{
			flag=-1;
		}
		p[i].l=x,p[i].r=y;
		p[i].i=i;
	}
	if(flag==-1)
	{
		cout<<"rated"<<endl;
		return 0;
	}
	sort(p+1,p+1+n,cmp);
	for(i=1;i<=n;i++)
	{
		if(p[i].i!=i)
		{
			cout<<"unrated"<<endl;
			return 0;
		}
	}
	cout<<"maybe"<<endl;
}
