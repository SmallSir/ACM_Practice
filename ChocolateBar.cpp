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

long long int MAX,MIN,i,n,m,x,y,z,ans1,ans2,ans3,ans4;
int main()
{
	cin>>n>>m;
	if(n%3==0||m%3==0)
	{
		cout<<0<<endl;
		return 0;
	}
	ans1=n;
	ans2=m;
	ans3=ans4=9999999;
	for(i=1;i<=n;i++)
	{
		x=i*m;
		if(m%2!=0)
		{
			y=(n-i)*(m/2+1);
			z=(n-i)*(m/2);
		}
		else
		{
			y=z=(n-i)*(m/2);
		}
		MAX=max(z,max(x,y));
		MIN=min(z,min(x,y));
		ans3=min(MAX-MIN,ans3);
	}
	for(i=1;i<=m;i++)
	{
		x=i*n;
		if(n%2!=0)
		{
			z=(m-i)*(n/2+1);
			y=(m-i)*(n/2);
		}
		else
		{
			y=z=(m-i)*(n/2);
		}
		MAX=max(x,max(y,z));
		MIN=min(x,min(y,z));
		ans4=min(MAX-MIN,ans4);
	}
	cout<<min(min(ans1,ans2),min(ans3,ans4))<<endl;	
}
