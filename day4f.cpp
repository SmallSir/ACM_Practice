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


int sum,i,j,ans,x,n,k;
//int a[1000000];
map<int,bool> t;
int main()
{
	cin>>n;
	sum=0;
	//memset(a,0,sizeof(a));
	for(i=2;i<=sqrt(n);i++)
	{
		for(j=2;;j++)
		{
			int k=pow(i,j);	
			if(pow(i,j)>n||t[k]==1)
				break;
			t[k]=1;
			sum++;
		}
	}
	ans=n-sum;
	cout<<ans<<endl;
	if(ans%2==0)
	{
		cout<<"Petya"<<endl;
	}
	else
	{
		cout<<"Vasya"<<endl;
	}
}
