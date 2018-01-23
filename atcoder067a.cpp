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

int a,b;
int main()
{
	cin>>a>>b;
	if((a+b)%3==0||a%3==0||b%3==0)
	{
		cout<<"Possible"<<endl;
	}
	else
	{
		cout<<"Impossible"<<endl;
	}
}
