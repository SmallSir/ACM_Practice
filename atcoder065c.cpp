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

int n,m,i;
long long int sum;
int main()
{
	cin>>n>>m;
	if(abs(n-m)>=2)
	{
		cout<<0<<endl;
		return 0;
	}
	sum=1;
	for(i=1;i<=n;i++)
	{
		sum=(sum*i)%1000000007;
	}
	for(i=1;i<=m;i++)
	{
		sum=(sum*i)%1000000007;;
			
	}
	if(n==m)
	{
		sum=(sum*2)%1000000007;;
	
	}
	cout<<sum<<endl;
}

