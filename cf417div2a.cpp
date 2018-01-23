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

int n,k;
int a[]={1,2,3,1,2,3,1,2,3,4};
int main()
{
	cin>>n;
	k=n%10;
	if(k==0)
	{
		cout<<a[9]<<endl;
	}
	else
	{
		cout<<a[k-1]<<endl;
	}
}
