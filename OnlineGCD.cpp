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

int n,T,x,i;
long long int a[100005],y,k;
long long int gcd(long long int x,long long int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	cin>>n>>T;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(T--)
	{
		cin>>x>>y;
		a[x]/=y;
		k=gcd(a[1],a[2]);
		for(i=3;i<=n;i++)
		{
			k=gcd(k,a[i]);
		}
		cout<<k<<endl;
	}
}
