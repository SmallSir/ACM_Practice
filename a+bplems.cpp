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

long long int a,b,n,k;
int main()
{
	cin>>n>>a>>b;
	k=b-a;
	n-=2;
	k=(b-a)*n+1;
	//cout<<max(0,((b-a)*n+1))<<endl;
	//cout<<max(0,k)<<endl;
	if(k<0)
		cout<<0<<endl;
	else
		cout<<k<<endl;
}
