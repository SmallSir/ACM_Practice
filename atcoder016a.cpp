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



string str;
int n,i,MAX,j;
int a[35],b[35][105],c[35],k,sum;
int main()
{
	memset(b,0,sizeof(b));
	memset(a,0,sizeof(a));
	cin>>str;
	n=str.length();
	for(i=0;i<n;i++)
	{
		k=str[i]-'a'+1;
		a[k]++;
		b[k][a[k]]=i;
		//cout<<a[k]<<" "<<k<<" "<<b[a[k]]<<endl;
	}
	MAX=0;
	sum=500;
	memset(c,0,sizeof(c));
	for(i=1;i<=26;i++)
	{
		MAX=max(MAX,a[i]);
	}
	if(MAX==1)
	{
		cout<<n/2<<endl;
		return 0;
	}
	for(i=1;i<=26;i++)
	{
		if(a[i]!=MAX)
			continue;
		for(j=1;j<=a[i];j++)
		{
			//cout<<i<<" "<<b[i][j]<<" "<<b[i][j-1]<<endl;
			c[i]=max(c[i],b[i][j]-b[i][j-1]);
			//cout<<c[i]<<endl;
		}
		c[i]=max(c[i],n-b[i][a[i]]);
		//cout<<i<<":"<<c[i]<<endl;
	}
	for(i=1;i<=26;i++)
	{
		if(c[i]!=0)
		{
		//	cout<<i<<" ";
		//	cout<<c[i]<<endl;
			sum=min(sum,c[i]);
		}
	}
	//cout<<endl;
	//cout<<sum<<endl;
	cout<<sum-1<<endl;
	//cout<<n-sum<<endl;
}
