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

long long int ans;
int i,n,r,l;
string str;
int main()
{
	cin>>str;
	n=str.length();
	l=-1;
	for(i=0;i<n;i++)
	{
		if(str[i]=='U'&&l==-1)
		{
			l=i;
		}
		if(str[i]=='D')
		{
			r=i;
		}
	}
	ans=0;
	for(i=0;i<n;i++)
	{
		if(str[i]=='U')
		{
			ans+=n-1-i;
			if(i<r)
				ans+=i*2;
			//cout<<ans<<endl;
		}
		else
		{
			ans+=i;
			if(i>l)
			{
				ans+=(n-i-1)*2;
			}
		}
	}
	cout<<ans<<endl;
}
