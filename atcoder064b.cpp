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

int a[105],i,n;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	cout<<a[n]-a[1]<<endl;
}
