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

long long int a,b,i,sum;
int main()
{
	cin>>a>>b;
	if(a>b)
		swap(a,b);
	sum=1;
	for(i=1;i<=a;i++)
		sum*=i;
	cout<<sum<<endl;
}
