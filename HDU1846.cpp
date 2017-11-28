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


int n,m,T;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		if(n%(m+1)==0)
		{
			cout<<"second"<<endl;
		}
		else
		{
			cout<<"first"<<endl;
		}
	}
}
