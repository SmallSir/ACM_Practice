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


int n,m,i,k;
int a[205],b[205];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+1+m,cmp);
	k=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=b[k];
			k++;
		}
	}
	for(i=2;i<=n;i++)
	{
		if(a[i]<=a[i-1])
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}
