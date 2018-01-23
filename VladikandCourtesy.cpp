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

long long int a,b,i;
int main()
{
	cin>>a>>b;
	i=1;
	for(;;)
	{
		if(i%2!=0)
			a-=i;
		else
			b-=i;
		i++;
		if(b<0)
		{
			cout<<"Valera"<<endl;
			return 0;
		}
		if(a<0)
		{
			cout<<"Vladik"<<endl;
			return 0;
		}
	}
}

