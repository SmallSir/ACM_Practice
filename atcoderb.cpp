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


int k,n,i;

int sum;
int a[55];
int main()
{
	sum=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(i=n;i>n-k;i--)
	{
		sum+=a[i];
	}
	cout<<sum<<endl;
}
