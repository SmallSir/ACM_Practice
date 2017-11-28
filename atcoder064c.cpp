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

int n,i,ans,x;
bool a[11];
int main()
{
	int sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x>=1&&x<=399)
			a[1]=true;
		else if(x>=400&&x<=799)
			a[2]=true;
		else if(x>=800&&x<=1199)
			a[3]=true;
		else if(x>=1200&&x<=1599)
			a[4]=true;
		else if(x>=1600&&x<=1999)
			a[5]=true;
		else if(x>=2000&&x<=2399)
			a[6]=true;
		else if(x>=2400&&x<=2799)
			a[7]=true;
		else if(x>=2800&&x<=3199)
			a[8]=true;
		else
		{
			a[9]=true;
			sum++;
		}
	}
	ans=0;
	for(i=1;i<=8;i++)
	{
		if(a[i]==true)
			ans++;
	}
	if(a[9]==true)
	{
		if(ans==0)
			cout<<1<<" "<<ans+sum<<endl;
		else
			cout<<ans<<" "<<ans+sum<<endl;
	}
	else 
		cout<<ans<<" "<<ans<<endl;
}
