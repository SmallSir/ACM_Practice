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
#include<queue>  
#include<map> 
#include<stack>
#define inf 9999999; 
using namespace std;


void test()
{
	for(i=2;i<=500;i++)
	{
		bool flag=false;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=true;
				break;
			}
		}
		if(!flag)
			a[i]=true;
	}
}
int main()
{
	cin>>T;
	memset(check,0,sizeof(check));
	test();
	while(T--)
	{
		cin>>x>>y;
		if(x>y)
			swap(x,y);
		if(check[x][y])
		{
			cout<<"Shiro"<<endl;
		}
		else
		{
			cout<<"Sora"<<endl;
		}
	}
}
