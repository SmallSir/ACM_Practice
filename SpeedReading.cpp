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


int n,m,ans,sum,s,t,r;
int main()
{
	cin>>n>>m;
	while(m--)
	{
		ans=0;
		sum=0;
		int i=0;
		cin>>s>>t>>r;
		for(;;)
		{
			ans+=s;
			i++;
			sum++;
			if(ans>=n)
				break;
			if(i%t==0)
			//{
				//cout<<111111111<<endl;
				sum+=r;
			//}
			//cout<<"sum: "<<sum<<endl;
		}
		cout<<sum<<endl;
	}
}
			
