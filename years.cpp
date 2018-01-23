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
using namespace std;

long long int T,s,p,y,j,x;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s>>p>>y>>j;
		if((12+j-p-y)/3!=0)
			x=(12+j-p-y)/3+1;
		else
			x=(12+j-p-y)/3;
		cout<<y+x<<" "<<p+x<<" "<<x<<endl;
	}
}
