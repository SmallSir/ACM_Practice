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

queue<int> qua;
int a[100005],n,k,p,i,j,ans;
int main()
{
	cin>>n>>k>>p;
	for(i=1;i<=k;i++)
	{
		qua.push(i);
	}
	i=0;
	memset(a,0,sizeof(a));
	ans=0;
	while(!qua.empty())
	{
		i++;
		if(i%n==0)
		{
			a[++ans]=qua.front();
		}
		else
		{
			qua.front();
		}
		qua.pop();
		for(j=1;j<=p;j++)
		{
			int xx=qua.front();
			qua.pop();
			qua.push(xx);
		}
	}
	sort(a+1,a+1+ans);
	for(i=1;i<=ans;i++)
	{
		cout<<a[i]<<endl;
	}
}
