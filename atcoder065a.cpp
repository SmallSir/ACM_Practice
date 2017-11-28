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

int a,b,c;
int main()
{
	cin>>a>>b>>c;
	if(c>b&&a+b>=c)
	{
		cout<<"safe"<<endl;
	}
	else if(c<=b)
	{
		cout<<"delicious"<<endl;
	}
	else
	{
		cout<<"dangerous"<<endl;
	}
}
