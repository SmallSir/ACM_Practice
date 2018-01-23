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


int i,j,n,m;
char a[105][105];
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=1;i<=m+2;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"#";
		for(j=1;j<=m;j++)
		{
			cout<<a[i][j];
		}
		cout<<"#"<<endl;
	}
	for(i=1;i<=m+2;i++)
	{
		cout<<"#";
	}
	cout<<endl;
}
