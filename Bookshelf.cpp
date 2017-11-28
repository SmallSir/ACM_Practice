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


long long int m,a[20005];
int n,i;
long long int sum;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum=0;
	for(i=n;i>=1;i--)
	{
		sum+=a[i];
		if(sum>=m)
		{
			cout<<n-i+1<<endl;
			break;
		}
	}
}
