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

int x,y;
int main()
{
	int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
	cin>>x>>y;
	if(a[x-1]==a[y-1])
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}
