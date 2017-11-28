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

int n,m,k,flag;
int a[100005],i,x,y;
int main()
{
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		a[i]=i;
	}
	flag=k;
	while(m--)
	{
		cin>>x;
		if(x==0)
		{
			cin>>y;
			if(flag<=y)
			{
			//	cout<<111111111111<<endl;
				flag=y-flag+1;
			}
		}
		else
		{
			cin>>y;
			if(n-flag+1<=y)
				flag=n-y+y-(flag-(n-y))+1;
		}
		//cout<<"flag: "<<flag<<endl;
	}
	cout<<flag<<endl;
}
